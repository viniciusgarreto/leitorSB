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
	
	if (string_name.compare(string("SourceFile")) == 0)
		return new SourceFileAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("Code")) == 0)
		return new CodeAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("LineNumberTable")) == 0)
		return new LineNumberTableAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("StackMapTable")) == 0)
		return new StackMapAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("InnerClasses")) == 0)
		return new InnerClassesAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("Signature")) == 0)
		return new SignatureAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("ConstantValue")) == 0)
		return new ConstantValueAttribute(fp, cp, attbName, attbLength);

	if (string_name.compare(string("Exceptions")) == 0)
		return new ExceptionsAttribute(fp, cp, attbName, attbLength);
}

// constructor
Attribute::Attribute(u2 attbName, u4 attbLength) {
  this->attribute_name = attbName;
  this->attribute_length = attbLength;
}
// destructor
Attribute::~Attribute() {}

// constructor
SourceFileAttribute::SourceFileAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
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
		cout << "[UNINPLEMENTED ERROR] read and instantiate exception attribute";
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
void CodeAttribute::AddAttribute(Attribute* interface) {
  this->attributes.push_back(interface);
}
// destructor
CodeAttribute::~CodeAttribute() {
	free(this->code);
}

// constructor
LineNumberTableAttribute::LineNumberTableAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
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
StackMapAttribute::StackMapAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	cout << "TODO: implement StackMapAttribute" << endl;
	this->num_entries = u2READ(fp);
	if (this->num_entries > 0) {
		// this->entries = (Stack_map_frame**) malloc(this->num_entries*sizeof(Stack_map_frame*));
		for (int i = 0; i < this->num_entries; i++) {
			// *(this->entries + i) = lerStackMapFrame(fp);
		}
	}
}
// destructor
StackMapAttribute::~StackMapAttribute() {}

void StackMapAttribute::readStackMapFrame(FILE* fp) {
	// TODO: implement
}

// constructor
InnerClassesAttribute::InnerClassesAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
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
SignatureAttribute::SignatureAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->signature = u2READ(fp);
}
// destructor
SignatureAttribute::~SignatureAttribute() {}

// constructor
ConstantValueAttribute::ConstantValueAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->constantValue = u2READ(fp);
}
// destructor
ConstantValueAttribute::~ConstantValueAttribute() {}

// constructor
ExceptionsAttribute::ExceptionsAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->num_exceptions = u2READ(fp);
	this->exceptions = nullptr;
	if (this->num_exceptions > 0) {
		this->exceptions = (u2*) malloc(this->num_exceptions*sizeof(u2));
		for (u2* aux = this->exceptions; aux < this->exceptions + this->num_exceptions; aux++) {
			*aux = u2READ(fp);
		}
	}
}
// destructor
ExceptionsAttribute::~ExceptionsAttribute() {
	free(this->exceptions);
}

ostream& Attribute::print(ConstantPool& cp, unsigned int indent, ostream& output) const {	
	string string_name = cp.getValueUTF8String(this->attribute_name);

	if (string_name.compare(string("SourceFile")) == 0)
		((SourceFileAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("Code")) == 0)
		((CodeAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("LineNumberTable")) == 0)
		((LineNumberTableAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("StackMapTable")) == 0)
		((StackMapAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("InnerClasses")) == 0)
		((InnerClassesAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("Signature")) == 0)
		((SignatureAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("ConstantValue")) == 0)
		((ConstantValueAttribute*) this)->print(cp, indent, output);

	if (string_name.compare(string("Exceptions")) == 0)
		((ExceptionsAttribute*) this)->print(cp, indent, output);

	return output;
}

ostream& SourceFileAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
  out << "source_file: " << (unsigned)  this->source_file << endl;

	return out;
}

ostream& CodeAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
	out << "Code Attribute: " << endl;
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned) this->attribute_length << endl;
	indentBy(indent);
	out << "max_locals: " << (unsigned) this->max_locals << endl;
	indentBy(indent);
	out << "max_stack: " << (unsigned) this->max_stack << endl;

	indentBy(indent);
	out << "code_length: " << (unsigned) this->code_length << endl;
	indentBy(indent);
	out << "code: " << endl; 
	for (size_t i = 0; i < this->code_length; i++) {
		indentBy(indent+1);
		out << i+1 << ") " << (unsigned) this->code[i] << endl;
	}
	
	indentBy(indent);
	out << "exception_length: " << (unsigned) this->exception_info_length << endl;
	indentBy(indent);
	out << "exceptions: " << endl; 
	for (size_t i = 0; i < this->exception_info_length; i++) {
		this->ex_info[i].print(cp, indent+1, out);
	}

	indentBy(indent);
	out << "attributes: " << endl;
	for (auto atb : this->attributes) {
		atb->print(cp, indent + 1, out);
	}

	return out;
}

ostream& LineNumberTableAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
  out << "line_number_table_length: " << (unsigned)  this->line_number_table_length << endl;
	for (auto table : this->line_number_table) {
		table->print(cp, indent + 1);
	}

	return out;
}

ostream& StackMapAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;

	indentBy(indent);
  out << "attributes_num: " << (unsigned)  this->num_entries << endl;
	
	indentBy(indent);
  out << "Attributes: " << endl;
	for (auto atb : this->attributes)
		atb->print(cp, indent + 1, out);

	return out;
}

ostream& InnerClassesAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	out << "Inner Classes Attributes: " << endl;
	indentBy(indent);
	out << "num_class: " << (unsigned) this->num_classes << endl;
	for (auto c : this->classes) {
		c->print(cp, indent + 1);
	}

	return out;
}

ostream& SignatureAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	out << "Signature Attribute: " << endl;
	indentBy(indent);
	out << "signature: " << (unsigned) this->signature << endl;

	return out;
}

ostream& ConstantValueAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	out << "Constant Value Attribute: " << endl;
	indentBy(indent);
	out << "constant_value: " << (unsigned) this->constantValue << endl;

	return out;
}

ostream& ExceptionsAttribute::print(ConstantPool& cp, unsigned int indent, ostream& out) const {
	indentBy(indent);
  out << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  out << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	out << "Exceptions Attribute: " << endl;
	indentBy(indent);
	out << "num_exceptions: " << (unsigned) this->num_exceptions << endl;
	indentBy(indent);
	out << "exceptions: " << endl;
	for (size_t i = 0; i < (size_t) this->num_exceptions; i++) {
		indentBy(indent+1);
		out << i+1 << ") " << (unsigned) this->exceptions[i] << endl;
	}

	return out;
}
