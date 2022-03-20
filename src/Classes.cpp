#include "../headers/Classes.h"

#include <iostream>

using namespace std;

Classes::Classes(FILE* fp) {
	this->inner_class_info = u2READ(fp);
	this->outer_class_info = u2READ(fp);
	this->inner_name = u2READ(fp);
	this->inner_class_access_flags = u2READ(fp);

	
  cout << "[CLASSES] creating class with" << endl
    << "[CLASSES]\tthis->inner_class_info: " << (unsigned) this->inner_class_info << endl
    << "[CLASSES]\tthis->outer_class_info: " << (unsigned) this->outer_class_info << endl
    << "[CLASSES]\tthis->inner_name: " << (unsigned) this->inner_name << endl
    << "[CLASSES]\tthis->inner_class_access_flags: " << (unsigned) this->inner_class_access_flags << endl
	<< endl;
}
