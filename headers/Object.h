#ifndef object_h
#define object_h

#include "../headers/definitions.h"
#include "../headers/ClassFile.h"

class ClassFile;

class Object {
private:
	ClassFile * obj;
	u1 sizeData;
	u4 * data;
public:
  Object(/* args */);
  ~Object();
};

#endif
