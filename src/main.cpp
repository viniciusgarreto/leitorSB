#include "../headers/JVM.h"
#include "../headers/ClassFile.h"
#include "../headers/printer.h"
#include "../headers/Instructions.h"
#include ",,/headers/Attribute.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cout << "Use this program as \"" << argv[0] << " fileName.java\"" << endl;
    return 1;
  }

  // get command argument
  string filename(argv[1]);

  // initialize JVM
  auto jvm = new JVM();
  //FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength
  auto teste = new CodeAttribute();

  teste->interpret();
  // read file
  jvm->ReadClassFile(filename);

  // execute JVM
  jvm->execute();

  JVM::removeInstance();
  return 0;
}
