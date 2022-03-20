#include "../headers/classFile.h"
#include "../headers/reader.h"
#include "../headers/printer.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  //Declara file
  ClassFile *class_file;

  if (argc != 2) {
    cout << "Use this program as \"" << argv[0] << " fileName.java\"" << endl;
    return 1;
  }

  // get command argument
  string filename(argv[1]);

  // read file
  class_file = lerArquivo(filename);

  // imprimirArquivo(class_file);

  return 0;
}
