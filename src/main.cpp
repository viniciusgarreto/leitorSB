#include "../headers/classFile.h"
#include "../headers/printer.h"
#include "../headers/Instructions.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

  // if (argc != 2) {
  //   cout << "Use this program as \"" << argv[0] << " fileName.java\"" << endl;
  //   return 1;
  // }

  // // get command argument
  // string filename(argv[1]);

  // // read file
  // auto class_file = ClassFile::lerArquivo(filename);

  // // print classfile
  // ofstream myfile("./example.txt");
  // imprimirArquivo(class_file, myfile);
  // myfile.close();

  Instruction instruc;
  instruc.setInstructions();

  instruc.print();

  // para mandar pro terminal é só deixar o segundo parâmetro vazio ou mandar o cout explicitamente
  // imprimirArquivo(class_file, cout);

  return 0;
}
