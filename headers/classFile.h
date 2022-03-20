#ifndef classFile_h
#define classFile_h

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"

typedef struct attribute_info
{
  u2 attribute_name_index;
  u4 attribute_length;
  void *info;
} attribute_info;

typedef struct field_info
{
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info **attributes;
} field_Info;

typedef struct cp_info
{
  u1 tag;
  u1 info[];
} cp_info;

typedef struct method_info {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info attributes[];
} method_Info;

typedef struct ClassFile
{
  u4 magic;
  u2 minor_version;
  u2 major_version;
  ConstantPool* constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  Interfaces* interfaces;
  u2 fields_count;
  field_info *field_Info;
  u2 methods_count;
  method_info *method_Info;
  u2 attributes_count;
  attribute_info *attributes;
} ClassFile;

#endif
