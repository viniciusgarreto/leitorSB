#ifndef methods_h
#define methods_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Method.h"

class Methods {
  public:
    Methods(FILE* fp, ConstantPool& cp);
    ~Methods();
    void printMethods(ConstantPool& cp);
  private:
    void ReadMethodsFromFile(FILE* fp, ConstantPool& cp);
    void AddMethod(Method* method);

    std::vector<Method*> methods;
    u2 methods_count;
};

#endif
