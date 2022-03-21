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

void Attribute::printAttribute(ConstantPool& cp, unsigned int indent) {	
	string string_name = cp.getValueUTF8String(this->attribute_name);

	if (string_name.compare(string("SourceFile")) == 0)
		((SourceFileAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("Code")) == 0)
		((CodeAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("LineNumberTable")) == 0)
		((LineNumberTableAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("StackMapTable")) == 0)
		((StackMapAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("InnerClasses")) == 0)
		((InnerClassesAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("Signature")) == 0)
		((SignatureAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("ConstantValue")) == 0)
		((ConstantValueAttribute*) this)->printAttribute(cp, indent);

	if (string_name.compare(string("Exceptions")) == 0)
		((ExceptionsAttribute*) this)->printAttribute(cp, indent);
}

void SourceFileAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
  cout << "source_file: " << (unsigned)  this->source_file << endl;

}

void CodeAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
	cout << "Code Attribute: " << endl;
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned) this->attribute_length << endl;
	indentBy(indent);
	cout << "max_locals: " << (unsigned) this->max_locals << endl;
	indentBy(indent);
	cout << "max_stack: " << (unsigned) this->max_stack << endl;

	indentBy(indent);
	cout << "code_length: " << (unsigned) this->code_length << endl;
	indentBy(indent);
	cout << "code: " << endl; 
	for (size_t i = 0; i < this->code_length; i++) {
		indentBy(indent+1);
		cout << i+1 << ") " << (unsigned) this->code[i] << endl;
	}
	
	indentBy(indent);
	cout << "exception_length: " << (unsigned) this->exception_info_length << endl;
	indentBy(indent);
	cout << "exceptions: " << endl; 
	for (size_t i = 0; i < this->exception_info_length; i++) {
		this->ex_info[i].printAttribute(cp, indent+1);
	}

	indentBy(indent);
	cout << "attributes: " << endl;
	for (auto atb : this->attributes) {
		atb->printAttribute(cp, indent + 1);
	}
}

void LineNumberTableAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
  cout << "line_number_table_length: " << (unsigned)  this->line_number_table_length << endl;
	for (auto table : this->line_number_table) {
		table->print(cp, indent + 1);
	}
  
}

void StackMapAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;

	indentBy(indent);
  cout << "attributes_num: " << (unsigned)  this->num_entries << endl;
	
	indentBy(indent);
  cout << "Attributes: " << endl;
	for (auto atb : this->attributes)
		atb->printAttribute(cp, indent + 1);
}

void InnerClassesAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	cout << "Inner Classes Attributes: " << endl;
	indentBy(indent);
	cout << "num_class: " << (unsigned) this->num_classes << endl;
	for (auto c : this->classes) {
		c->print(cp, indent + 1);
	}
}

void SignatureAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	cout << "Signature Attribute: " << endl;
	indentBy(indent);
	cout << "signature: " << (unsigned) this->signature << endl;
	
}

void ConstantValueAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	cout << "Constant Value Attribute: " << endl;
	indentBy(indent);
	cout << "constant_value: " << (unsigned) this->constantValue << endl;
}

void ExceptionsAttribute::printAttribute(ConstantPool& cp, unsigned int indent = 0) {
	indentBy(indent);
  cout << "attribute_name: " << (unsigned) this->attribute_name << endl;
	indentBy(indent);
  cout << "attribute_length: " << (unsigned)  this->attribute_length << endl;
	indentBy(indent);
	cout << "Exceptions Attribute: " << endl;
	indentBy(indent);
	cout << "num_exceptions: " << (unsigned) this->num_exceptions << endl;
	indentBy(indent);
	cout << "exceptions: " << endl;
	for (size_t i = 0; i < (size_t) this->num_exceptions; i++) {
		indentBy(indent+1);
		cout << i+1 << ") " << (unsigned) this->exceptions[i] << endl;
	}
}
