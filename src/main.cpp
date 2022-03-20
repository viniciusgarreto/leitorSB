#include "../headers/classFile.h"
#include "../headers/reader.h"
#include "../headers/printer.h"

#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  //Declara file
  ClassFile *class_file;

  //Copia file do argumento para file do código
  // strcpy("nomeArquivo", argv[1]);

  class_file = lerArquivo(string("nomeArquivo"));

  imprimirArquivo(class_file);

  return 0;
}
