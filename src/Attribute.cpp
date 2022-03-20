#include <iostream>

#include "../headers/Attribute.h"
#include "../headers/definitions.h"

using namespace std;

// constructor
Attribute::Attribute(FILE* fp, ConstantPool& cp) {
  this->attribute_name = u2READ(fp);
  this->attribute_length = u4READ(fp);

  this->readInfo(fp, cp);
}
// destructor
Attribute::~Attribute() {}

void Attribute::readInfo(FILE* fp, ConstantPool& cp) {
	if (this->attribute_length > 0) {
			string string_name = cp.getValueUTF8String(this->attribute_name);
			// cout << "making attribute." << "index in cp is : " <<this->attribute_name << ", and value is |" << string_name << "|." << endl;

			// if (strcmp(string_name, "SourceFile") == 0){
			// 	source_file_attribute *SourceFile = NULL;//(code_attribute*) malloc(i->attributes_count*sizeof(code_attribute));
			// 	SourceFile = lerSourceFile(fp);
			// 	this->info = NULL;//malloc(i->attributes_count*sizeof(code_attribute));
			// 	this->info = (source_file_attribute*) SourceFile;
			// }
      // else if (strcmp(string_name,"Code") == 0) {
			// 	printf("Entrou code\n");
			// 	code_attribute *code_attr = NULL;
			// 	code_attr = lerCode(fp ,cp);
			// 	this->info = (code_attribute*) code_attr;
			// }
      // else if (strcmp(string_name,"LineNumberTable") == 0) {
			// 	line_number_table *lnt = NULL;
			// 	printf("Entrou lnt\n");
			// 	lnt = lerLineNumberTable(fp, cp);
			// 	this->info = (line_number_table*)lnt;
			// }
      // else if (strcmp(string_name,"StackMapTable") == 0) {
			// 	printf("Entrou stack map table\n");
			// 	stack_map_attribute *stackMapTable = NULL;
			// 	stackMapTable = lerStackMapTable(fp);
			// 	printf("Saiu de smt\n");
			// 	this->info = (stack_map_attribute*)stackMapTable;
			// }
      // else if (strcmp(string_name, "InnerClasses") == 0) {
			// 	printf("Entrou em inner class\n");
			// 	inner_classes_attribute *innerClasses = NULL;
			// 	innerClasses = lerInnerClasses(fp, cp);
			// 	this->info = (inner_classes_attribute*)innerClasses;
			// }
      // else if (strcmp(string_name,"Signature") == 0) {
			// 	printf("Entrou em signature\n");
			// 	signature_attribute *signatureR = NULL;
			// 	signatureR = lerSignature(fp);
			// 	this->info = (signature_attribute*)signatureR;
			// }
      // else if (strcmp(string_name,"ConstantValue") == 0) {
			// 	constant_value_attribute *constantV = NULL;
			// 	constantV = lerConstantValue(fp);
			// 	this->info = (constant_value_attribute*)constantV;
			// }
      // else if (strcmp(string_name,"Exceptions") == 0) {
			// 	exception_attribute *exceptions = NULL;
			// 	exceptions = lerExceptionsAttribute(fp);
			// 	this->info = (exception_attribute*) exceptions;
			// }
	}
}
