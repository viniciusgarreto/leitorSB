#include <iostream>

#include "../headers/Attribute.h"
#include "../headers/definitions.h"

using namespace std;

Attribute* Attribute::readAttribute(FILE* fp, ConstantPool& cp) {
	u2 attbName = u2READ(fp);
	u4 attbLength = u4READ(fp);

	// cout << "reading attb for name " << (unsigned) attbName << " and len " << (unsigned) attbLength << endl;
	
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
}
// destructor
SourceFileAttribute::~SourceFileAttribute() {}

// constructor
CodeAttribute::CodeAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	this->max_stack = u2READ(fp);
	this->max_locals = u2READ(fp);
	this->code_length = u4READ(fp);

  this->code = (u1*) malloc(this->code_length * sizeof(u1));
  for (auto i = 0; i < this->code_length; i++){
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
	cout << "TODO: implement LineNumberTableAttribute" << endl;
	this->line_number = u2READ(fp);
	
	if (this->line_number == 0) return;
	

	// this-> = (Line_number_info*) malloc(this->line_number_length*sizeof(struct line_number_info));
	// for (Line_number_info *linfo = this->info; linfo < this->info+this->line_number_length; linfo++) {
	// 	linfo->start_pc = u2READ(fp);
	// 	linfo->line_number = u2READ(fp);
	// }
}
// destructor
LineNumberTableAttribute::~LineNumberTableAttribute() {}

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
	// Stack_map_frame *StackMapFrame = (Stack_map_frame*) malloc(sizeof(struct stack_map_frame));
	// StackMapFrame->frame_type = u1READ(fp);
	// if (StackMapFrame->frame_type >= 0 && StackMapFrame->frame_type <= 63) {
	// } else if (StackMapFrame->frame_type >= 64 && StackMapFrame->frame_type <= 127) {
	// 	StackMapFrame->map_frame_type.same_locals_1_stack_item_frame.stack = (Verification_type_info**)malloc(sizeof(Verification_type_info*));
	// 	*(StackMapFrame->map_frame_type.same_locals_1_stack_item_frame.stack) = lerVerificationTypeInfo(fp);
	// } else if (StackMapFrame->frame_type == 247) {
	// 	StackMapFrame->map_frame_type.same_locals_1_stack_item_frame_extended.offset_delta = u2READ(fp);
	// 	StackMapFrame->map_frame_type.same_locals_1_stack_item_frame_extended.stack = (Verification_type_info**)malloc(sizeof(Verification_type_info*));
	// 	*(StackMapFrame->map_frame_type.same_locals_1_stack_item_frame_extended.stack) = lerVerificationTypeInfo(fp);
	// } else if (StackMapFrame->frame_type >= 248 && StackMapFrame->frame_type <= 250) {
	// 	StackMapFrame->map_frame_type.chop_frame.offset_delta = u2READ(fp);
	// } else if (StackMapFrame->frame_type == 251) {
	// 	StackMapFrame->map_frame_type.same_frame_extended.offset_delta = u2READ(fp);
	// } else if (StackMapFrame->frame_type >= 252 && StackMapFrame->frame_type <= 254) {
	// 	StackMapFrame->map_frame_type.append_frame.offset_delta = u2READ(fp);
	// 	u2 sizeMalloc = (StackMapFrame->frame_type-251);
	// 	StackMapFrame->map_frame_type.append_frame.locals = (Verification_type_info**)malloc(sizeMalloc*sizeof(Verification_type_info*));
	// 	for (int posicao = 0; posicao < sizeMalloc; posicao++) {
	// 		*(StackMapFrame->map_frame_type.append_frame.locals+posicao) = lerVerificationTypeInfo(fp);
	// 	}
	// } else if (StackMapFrame->frame_type == 255) {
	// 	StackMapFrame->map_frame_type.full_frame.offset_delta = u2READ(fp);
	// 	StackMapFrame->map_frame_type.full_frame.num_locals = u2READ(fp);
	// 	if (StackMapFrame->map_frame_type.full_frame.num_locals > 0) {
	// 		StackMapFrame->map_frame_type.full_frame.locals = (Verification_type_info**) malloc(StackMapFrame->map_frame_type.full_frame.num_locals*sizeof(Verification_type_info*));
	// 		for (int posicao = 0; posicao < StackMapFrame->map_frame_type.full_frame.num_locals; posicao++) {
	// 			*(StackMapFrame->map_frame_type.full_frame.locals+posicao) = lerVerificationTypeInfo(fp);
	// 			if ((*(StackMapFrame->map_frame_type.full_frame.locals+posicao))->tag == 7) {
	// 			}
	// 		}
	// 	}
	// 	StackMapFrame->map_frame_type.full_frame.num_stack_items = u2READ(fp);
	// 	if (StackMapFrame->map_frame_type.full_frame.num_stack_items > 0) {
	// 		StackMapFrame->map_frame_type.full_frame.stack = (Verification_type_info**) malloc(StackMapFrame->map_frame_type.full_frame.num_stack_items*sizeof(Verification_type_info*));
	// 		for (int posicao = 0; posicao < StackMapFrame->map_frame_type.full_frame.num_stack_items; posicao++) {
	// 			*(StackMapFrame->map_frame_type.full_frame.stack+posicao) = lerVerificationTypeInfo(fp);
	// 		}
	// 	}
	// }
	// return StackMapFrame;
}

// constructor
InnerClassesAttribute::InnerClassesAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength): Attribute(attbName, attbLength) {
	// cout << "TODO: implement InnerClassesAttribute" << endl;
	this->num_classes = u2READ(fp);
	if (this->num_classes > 0) {
		// this->classes_array = (Classes**) malloc(this->num_classes*sizeof(Classes*));
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
	cout << "TODO: implement ExceptionsAttribute" << endl;
	// Exception_attribute *exceptions = (Exception_attribute*) malloc(sizeof(struct exception_attribute));
	// exceptions->num_exceptions = u2READ(fp);
	// exceptions->exception_info = NULL;
	// if (exceptions->num_exceptions > 0) {
	// 	exceptions->exception_info = (u2*) malloc(exceptions->num_exceptions*sizeof(u2));
	// 	for (u2 *excpAux = exceptions->exception_info; excpAux < exceptions->exception_info + exceptions->num_exceptions; excpAux++) {
	// 		*excpAux = u2READ(fp);
	// 	}
	// }
	// return exceptions;
}

// destructor
ExceptionsAttribute::~ExceptionsAttribute() {}
