#ifndef methods_h
#define methods_h

class Methods;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Method.h"

class Methods {
  public:
    Methods(FILE* fp, ConstantPool& cp);
    ~Methods();

    Method* getMain(ConstantPool& cp);
    Method* getCLinit(ConstantPool& cp);

    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    void ReadMethodsFromFile(FILE* fp, ConstantPool& cp);
    void AddMethod(Method* method);

    std::vector<Method*> methods;
    u2 methods_count;
};

#endif
