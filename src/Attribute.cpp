#include <iostream>

#include "../headers/Attribute.h"
#include "../headers/definitions.h"

using namespace std;

Attribute* Attribute::readAttribute(FILE* fp, ConstantPool& cp) {
	u2 attbName = u2READ(fp);
	u4 attbLength = u4READ(fp);
	// cout << "[ATTRIBUTE] Reading attb for name " << (unsigned) attbName << " and len " << (unsigned) attbLength << endl;

	// case attbLength 0
	if (attbLength == 0)
		return new Attribute(attbName, attbLength);
	
	string string_name = cp.getValueUTF8String(attbName);
	
	if (string_name == string(SOURCE_FILE_ATTRIBUTE))
		return new SourceFileAttribute(fp, attbName, attbLength);

	if (string_name == string(CODE_ATTRIBUTE))
		return new CodeAttribute(fp, cp, attbName, attbLength);

	if (string_name == string(LINE_NUMBER_ATTRIBUTE))
		return new LineNumberTableAttribute(fp, attbName, attbLength);

	if (string_name == string(STACK_MAP_ATTRIBUTE))
		return new StackMapAttribute(fp, attbName, attbLength);

	if (string_name == string(INNER_CLASS_ATTRIBUTE))
		return new InnerClassesAttribute(fp, attbName, attbLength);

	if (string_name == string(SIGNATURE_ATTRIBUTE))
		return new SignatureAttribute(fp, attbName, attbLength);

	if (string_name == string(CONSTANT_ATTRIBUTE))
		return new ConstantValueAttribute(fp, attbName, attbLength);

	if (string_name == string(EXCEPTIONS_ATTRIBUTE))
		return new ExceptionsAttribute(fp, attbName, attbLength);

	return nullptr;
}

// constructor
Attribute::Attribute(u2 attbName, u4 attbLength) {
  this->attribute_name = attbName;
  this->attribute_length = attbLength;
}
// destructor
Attribute::~Attribute() {}

string Attribute::getName(ConstantPool& cp) {
	return cp.getValueUTF8String(this->attribute_name);
}

// constructor
SourceFileAttribute::SourceFileAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
  this->source_file = u2READ(fp);
	// cout << "[SOURCE] source_file: " << this->source_file << endl;
}
// destructor
SourceFileAttribute::~SourceFileAttribute() {}

// constructor
CodeAttribute::CodeAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->max_stack = u2READ(fp);
	this->max_locals = u2READ(fp);
	this->code_length = u4READ(fp);

  this->code = (u1*) malloc(this->code_length * sizeof(u1));
  for (size_t i = 0; i < (size_t) this->code_length; i++){
    this->code[i] = u1READ(fp);
	}

	this->exception_info_length = u2READ(fp);
	if (this->exception_info_length > 0) {
		cout << "TODO: implement CodeAttribute::CodeAttribute" << endl;
		cout << "[UNINPLEMENTED ERROR] read and instantiate exception attribute" << endl;
		exit(1);
		// this->ex_info = lerExceptionTable(fp, this->exception_info_length);
	}

	this->attributes_count = u2READ(fp);
	if (this->attributes_count > 0) {
		for (int i = 0; i < this->attributes_count; i++) {
			// cout << "[CODE ATTB] reading sub-attribute of code attb #" << i+1 << endl;
			this->AddAttribute(Attribute::readAttribute(fp, cp));
		}
	}
}
// destructor
CodeAttribute::~CodeAttribute() {
	free(this->code);
}
void CodeAttribute::AddAttribute(Attribute* interface) {
  this->attributes.push_back(interface);
}
void CodeAttribute::interpret(JVM& jvm, Method& method) {
	cout << "TODO: implement CodeAttribute::interpret" << endl;
}

// constructor
LineNumberTableAttribute::LineNumberTableAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->line_number_table_length = u2READ(fp);
	// cout << "[LINE ATTB] reading line number table attribute." << endl
	// 	<< "[LINE ATTB]\tline_number_table_length: " << this->line_number_table_length
	// << endl;
	
	if (this->line_number_table_length > 0) {
		for (int posicao = 0; posicao < this->line_number_table_length; posicao++) {
			// cout << "[LINE ATTB] reading line " << posicao+1 << " of " << this->line_number_table_length << endl;
			this->AddLineNumberTable(new LineNumberTable(fp));
		}
	}
}
void LineNumberTableAttribute::AddLineNumberTable(LineNumberTable* table) {
  this->line_number_table.push_back(table);
}
// destructor
LineNumberTableAttribute::~LineNumberTableAttribute() {
// delete all classes from vector
  for (const auto table : this->line_number_table)
    delete table;
  this->line_number_table.clear();
}

// constructor
StackMapAttribute::StackMapAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->num_entries = u2READ(fp);
	this->entries = (StackMapFrame**) malloc(sizeof(StackMapFrame*) * (unsigned) this->num_entries);

	if (this->num_entries > 0) {
		for (int i = 0; i < this->num_entries; i++) {
			this->entries[i] = StackMapFrame::readStackMapFrame(fp);
		}
	}
}
// destructor
StackMapAttribute::~StackMapAttribute() {
	for (int i = 0; i < this->num_entries; i++) {
		delete this->entries[i];
	}
	delete this->entries;
}

// constructor
InnerClassesAttribute::InnerClassesAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->num_classes = u2READ(fp);
	if (this->num_classes > 0) {
		for (int posicao = 0; posicao < this->num_classes; posicao++) {
			this->AddClasses(new Classes(fp));
		}
	}
}

// destructor
InnerClassesAttribute::~InnerClassesAttribute() {
  // delete all classes from vector
  for (const auto c : this->classes)
    delete c;
  this->classes.clear();
}
void InnerClassesAttribute::AddClasses(Classes* c) {
  this->classes.push_back(c);
}
// constructor
SignatureAttribute::SignatureAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->signature = u2READ(fp);
}
// destructor
SignatureAttribute::~SignatureAttribute() {}

// constructor
ConstantValueAttribute::ConstantValueAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->constantValue = u2READ(fp);
}
// destructor
ConstantValueAttribute::~ConstantValueAttribute() {}

// constructor
ExceptionsAttribute::ExceptionsAttribute(FILE* fp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->num_exceptions = u2READ(fp);
	for (int i = 0; i < this->num_exceptions; i++){
		this->exception_index_table.push_back(u2READ(fp));
	}
	
}
// destructor
ExceptionsAttribute::~ExceptionsAttribute() {
	this->exception_index_table.clear();
}

ostream& Attribute::print(ConstantPool& cp, unsigned int i, ostream& output) const {	
	string string_name = cp.getValueUTF8String(this->attribute_name);

	if (string_name == string(SOURCE_FILE_ATTRIBUTE))
		return ((SourceFileAttribute*) this)->print(i, output);

	if (string_name == string(CODE_ATTRIBUTE))
		return ((CodeAttribute*) this)->print(cp, i, output);

	if (string_name == string(LINE_NUMBER_ATTRIBUTE))
		return ((LineNumberTableAttribute*) this)->print(i, output);

	if (string_name == string(STACK_MAP_ATTRIBUTE))
		return ((StackMapAttribute*) this)->print(i, output);

	if (string_name == string(INNER_CLASS_ATTRIBUTE))
		return ((InnerClassesAttribute*) this)->print(i, output);

	if (string_name == string(SIGNATURE_ATTRIBUTE))
		return ((SignatureAttribute*) this)->print(i, output);

	if (string_name == string(CONSTANT_ATTRIBUTE))
		return ((ConstantValueAttribute*) this)->print(i, output);

	if (string_name == string(EXCEPTIONS_ATTRIBUTE))
		return ((ExceptionsAttribute*) this)->print(cp, i, output);

	return output;
}

ostream& SourceFileAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "source_file: " << (unsigned)  this->source_file << endl;

	return out;
}

ostream& CodeAttribute::print(ConstantPool& cp, unsigned int tab, ostream& out) const {
	indentBy(tab, out) << "Code Attribute: " << endl;
	indentBy(tab, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(tab, out) << "attribute_length: " << (unsigned) this->attribute_length << endl;
	indentBy(tab, out) << "max_locals: " << (unsigned) this->max_locals << endl;
	indentBy(tab, out) << "max_stack: " << (unsigned) this->max_stack << endl;

	indentBy(tab, out) << "code_length: " << (unsigned) this->code_length << endl;
	indentBy(tab, out) << "code: " << endl; 
	for (size_t i = 0; i < this->code_length; i++) {
		indentBy(tab+1, out) << i+1 << ") " << (unsigned) this->code[i] << endl;
	}
	
	indentBy(tab, out) << "exception_length: " << (unsigned) this->exception_info_length << endl;
	indentBy(tab, out) << "exceptions: " << endl; 
	for (size_t i = 0; i < this->exception_info_length; i++) {
		this->ex_info[i].print(cp, i+1, out);
	}

	indentBy(tab, out) << "attributes: " << endl;
	for (auto atb : this->attributes) {
		atb->print(cp, tab + 1, out);
	}

	return out;
}

ostream& LineNumberTableAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "line_number_table_length: " << (unsigned)  this->line_number_table_length << endl;
	for (auto table : this->line_number_table) {
		table->print(i + 1, out);
	}

	return out;
}

ostream& StackMapAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "attributes_num: " << (unsigned)  this->num_entries << endl;
	indentBy(i, out) << "Attributes: " << endl;

	for (int i = 0; i < this->num_entries; i++)
		// this->entries[i]->print(cp, i + 1, out);
		this->entries[i]->print(i + 1, out);

	return out;
}

ostream& InnerClassesAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "Inner Classes Attributes: " << endl;
	indentBy(i, out) << "num_class: " << (unsigned) this->num_classes << endl;
	for (auto c : this->classes)
		c->print(i + 1);

	return out;
}

ostream& SignatureAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "Signature Attribute: " << endl;
	indentBy(i, out) << "signature: " << (unsigned) this->signature << endl;

	return out;
}

ostream& ConstantValueAttribute::print(unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(i, out) << "Constant Value Attribute: " << endl;
	indentBy(i, out) << "constant_value: " << (unsigned) this->constantValue << endl;

	return out;
}

ostream& ExceptionsAttribute::print(ConstantPool& cp, unsigned int i, ostream& out) const {
	indentBy(i, out) << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(i, out) << "attribute_length: " << (unsigned) this->attribute_length << endl;
	indentBy(i, out) << "Exceptions Attribute: " << endl;
	indentBy(i, out) << "num_exceptions: " << (unsigned) this->num_exceptions << endl;
	indentBy(i, out) << "exceptions: " << endl;
	for (int n = 0; n < this->num_exceptions; n++){
		indentBy(i + 1, out) << "Exception Table: " << i << endl;
		indentBy(i + 1, out) << *cp.getCpInfo(this->exception_index_table[n]) << endl;
	}
	
	return out;
}
