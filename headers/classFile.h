#ifndef CLASSFILE_INIT
#define CLASSFILE_INIT

#include <stdint.h>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

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
} field_info;

typedef struct method_info
{
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info **attributes;
} method_info;

typedef struct cp_info
{
  u1 tag;
  u1 info[];
} cp_info;

enum constant_pool_tags_values
{
  CONSTANT_Class = 7,
  CONSTANT_Fieldref = 9,
  CONSTANT_Methodref = 10,
  CONSTANT_InterfaceMethodref = 11,
  CONSTANT_String = 8,
  CONSTANT_Integer = 3,
  CONSTANT_Float = 4,
  CONSTANT_Long = 5,
  CONSTANT_Double = 6,
  CONSTANT_NameAndType = 12,
  CONSTANT_Utf8 = 1,
  CONSTANT_MethodHandle = 15,
  CONSTANT_MethodType = 16,
  CONSTANT_InvokeDynamic = 18,
};

typedef struct ClassFile
{
  u4 magic;
  u2 minor_version;
  u2 major_version;
  u2 constant_pool_count;
  cp_info *constant_pool;
  u2 access_flags;
  u2 this_class;
  u2 super_class;
  u2 interfaces_count;
  u2 *interfaces;
  u2 fields_count;
  field_info *fields;
  u2 methods_count;
  method_info *methods;
  u2 attributes_count;
  attribute_info **attributes;
} ClassFile;

#endif