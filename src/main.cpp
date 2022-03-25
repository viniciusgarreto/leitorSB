#include "../headers/classFile.h"
#include "../headers/printer.h"

#include <iostream>
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

  // read file
  auto class_file = ClassFile::lerArquivo(filename);

  // print file
  imprimirArquivo(class_file);

  return 0;
}
