#include <stdio.h>
#include <iostream>
#include "../headers/classFile.h"
using namespace std;

void imprimirArquivo(ClassFile *cf, ostream& output) {
  cf->print(output);
}
