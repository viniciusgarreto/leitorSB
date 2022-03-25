#include "../headers/ClassFile.h"

ClassFile::ClassFile(FILE* fp) {
  // file general info
  this->magic = u4READ(fp);
  this->minor_version = u2READ(fp);
  this->major_version = u2READ(fp);

  // constant pool
  this->constant_pool = new ConstantPool(fp);

  // stuff
  this->access_flags = u2READ(fp);
  this->this_class = u2READ(fp);
  this->super_class = u2READ(fp);

  // interfaces
  // this->interfaces_count = u2READ(fp);
  this->interfaces = new Interfaces(fp);

  // fields
  this->fields = new Fields(fp, *this->constant_pool);
  // this->fields->printFields();

  // methods
  this->methods = new Methods(fp, *this->constant_pool);

  // attributes
  this->attributes = new Attributes(fp, *this->constant_pool);
    
}

ClassFile::~ClassFile() {
  delete this->constant_pool;
  delete this->interfaces;
  delete this->fields;
  delete this->methods;
  delete this->attributes;
}
