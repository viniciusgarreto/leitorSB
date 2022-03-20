#include "../headers/Classes.h"

Classes::Classes(FILE* fp) {
	this->inner_class_info = u2READ(fp);
	this->outer_class_info = u2READ(fp);
	this->inner_name = u2READ(fp);
	this->inner_class_access_flags = u2READ(fp);
}
