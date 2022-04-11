#ifndef object.h
#define object.h

#include "definitions.h"
#include "ClassFile.h"

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