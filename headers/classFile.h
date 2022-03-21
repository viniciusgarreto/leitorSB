#ifndef classFile_h
#define classFile_h

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"
#include "../headers/Fields.h"
#include "../headers/Methods.h"
#include "../headers/Attributes.h"

typedef struct ClassFile {
  u4 magic;
  u2 minor_version;
  u2 major_version;
  ConstantPool* constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  Interfaces* interfaces;
  Fields* fields;
  Methods* methods;
  Attributes* attributes;
} ClassFile;

#endif
