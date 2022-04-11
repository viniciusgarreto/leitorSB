#ifndef classFile_h
#define classFile_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"
#include "../headers/Fields.h"
#include "../headers/Methods.h"
#include "../headers/Attributes.h"

using namespace std;

class ClassFile {
  public:
    ClassFile(FILE* fp);
    ~ClassFile();

    // read .class file
    static ClassFile* lerArquivo(string nomeArquivo);

    string getName();
    ConstantPool& getConstantPool();
    Method* getMain();
    Method* getCLinit();

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const ClassFile& cf);

  private:
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
};

#endif
