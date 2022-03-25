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

  output << endl;
  output << "------------- EXIBIDOR -------------" << endl;
  output << endl;

  output << "Magic Number: "  << this->magic      << endl
    << "Minor Version: " << this->minor_version   << endl
    << "Major Version: " << this->major_version   << endl
    << "Constant Pool: " << *this->constant_pool  << endl
    << "Access Flags: "  << this->access_flags    << endl
    << "This Class: "    << this->this_class      << endl
    << "Super Class: "   << this->super_class     << endl
    // << this->interfaces->ToString(*this->constant_pool) << endl
  ;
  
  //--fields
  output << endl;
  // this->fields->printFields(*this->constant_pool);
  // this->methods->printMethods(*this->constant_pool);
  // this->attributes->printAttributes(*this->constant_pool);

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
