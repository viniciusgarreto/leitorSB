#include <stdio.h>
#include <iostream>
#include "../headers/ClassFile.h"
using namespace std;

void imprimirArquivo(ClassFile *cf, ostream& output) {
  cf->print(output);
}
