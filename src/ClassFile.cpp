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


ostream& operator<<(ostream& out, const ClassFile& cf) {
  return cf.print(out);
}
ostream& ClassFile::print(ostream& output) const {

  cout << endl;
  cout << "------------- EXIBIDOR -------------" << endl;
  cout << endl;

  printf("Magic Number: %08x\n", this->magic);
  printf("Minor Version: %04x\n", this->minor_version);
  printf("Major Version: %04x\n", this->major_version);
  printf("Constant Pool: \n");
  this->constant_pool->printConstantPool();
  printf("Access Flags: %04x\n", this->access_flags);
  printf("This Class: %04x\n", this->this_class);
  printf("Super Class: %04x\n", this->super_class);
  cout << this->interfaces->ToString(*this->constant_pool) << endl;
  
  //--fields
  cout << endl;
  this->fields->printFields(*this->constant_pool);
  this->methods->printMethods(*this->constant_pool);
  this->attributes->printAttributes(*this->constant_pool);

  return cout;
}
