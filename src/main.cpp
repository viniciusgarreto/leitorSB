#include "../headers/classFile.h"
#include "../headers/reader.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  //Declara file
  ClassFile *class_file;

  //Copia file do argumento para file do código
  strcpy(nomeArquivo, argv[1]);

  class_file = (ClassFile *) malloc(sizeof(struct ClassFile));

  class_file = lerArquivo(class_file, nomeArquivo);
}
