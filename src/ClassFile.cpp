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

  output << endl;
  output << "------------- EXIBIDOR -------------" << endl;
  output << endl;

  output
    << "Magic Number: 0x" << hex << this->magic << dec << endl
    << "Minor Version: " << this->minor_version   << endl
    << "Major Version: " << this->major_version   << " [1." << this->major_version-44 << "]" << endl
    << "Access Flags: " << this->access_flags    << endl;
  if (this->access_flags & ACC_PUBLIC)       output << "\t- ACC_PUBLIC"       << endl;
  if (this->access_flags & ACC_PRIVATE)      output << "\t- ACC_PRIVATE"      << endl;
  if (this->access_flags & ACC_PROTECTED)    output << "\t- ACC_PROTECTED"    << endl;
  if (this->access_flags & ACC_STATIC)       output << "\t- ACC_STATIC"       << endl;
  if (this->access_flags & ACC_FINAL)        output << "\t- ACC_FINAL"        << endl;
  if (this->access_flags & ACC_SYNCHRONIZED) output << "\t- ACC_SYNCHRONIZED" << endl;
  if (this->access_flags & ACC_BRIDGE)       output << "\t- ACC_BRIDGE"       << endl;
  if (this->access_flags & ACC_VARARGS)      output << "\t- ACC_VARARGS"      << endl;
  if (this->access_flags & ACC_NATIVE)       output << "\t- ACC_NATIVE"       << endl;
  if (this->access_flags & ACC_ABSTRACT)     output << "\t- ACC_ABSTRACT"     << endl;
  if (this->access_flags & ACC_STRICT)       output << "\t- ACC_STRICT"       << endl;
  if (this->access_flags & ACC_SYNTHETIC)    output << "\t- ACC_SYNTHETIC"    << endl;
  
  output
    << "This Class: <" << this->constant_pool->getValueUTF8String(this->this_class)  << ">" << endl
    << "Super Class: <" << this->constant_pool->getValueUTF8String(this->super_class) << ">" << endl
  ;

  output << endl << "######### Constant Pool: " << endl << *this->constant_pool << endl;

  output << endl << "######### Interfaces: " << endl;
  this->interfaces->print(*this->constant_pool, output) << endl;

  output << endl << "######### Fields: " << endl;
  this->fields->print(*this->constant_pool, output) << endl;
  
  output << endl << "######### Methods: " << endl;
  this->methods->print(*this->constant_pool, output) << endl;

  output << endl << "######### Attributes: " << endl;
  this->attributes->print(*this->constant_pool, output) << endl;

  return output;
}

ClassFile* ClassFile::lerArquivo(string nomeArquivo) {
    FILE *fp = fopen(nomeArquivo.c_str(), "rb");

    if (!fp) {
      // se nao encontrou arquivo ou nao conseguiu abrir, encerra o programa
      cout << "Erro na abertura do arquivo .class, o programa sera encerrado...\n";
      exit(0);
    }

    auto cf = new ClassFile(fp);

    fclose(fp);

    return cf;
}

string ClassFile::getName() {
  return this->constant_pool->getValueUTF8String(this->this_class);
}

ConstantPool& ClassFile::getConstantPool() {
  return *this->constant_pool;
}

Method* ClassFile::getMain() {
  return this->methods->getMain(*this->constant_pool);
}

Method* ClassFile::getCLinit() {
  return this->methods->getCLinit(*this->constant_pool);
}
