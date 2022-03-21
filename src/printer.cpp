#include <stdio.h>
#include <iostream>
#include "../headers/classFile.h"
using namespace std;

void imprimirArquivo(ClassFile *cf) {
  cout << endl;
  cout << "------------- EXIBIDOR -------------" << endl;
  cout << endl;

  printf("Magic Number: %08x\n", cf->magic);
  printf("Minor Version: %04x\n", cf->minor_version);
  printf("Major Version: %04x\n", cf->major_version);
  printf("Constant Pool: \n");
  cf->constant_pool->printConstantPool();
  printf("Access Flags: %04x\n", cf->access_flags);
  printf("This Class: %04x\n", cf->this_class);
  printf("Super Class: %04x\n", cf->super_class);
  cout << cf->interfaces->ToString(*cf->constant_pool) << endl;
  
  //--fields
  cout << endl;
  cf->fields->printFields(*cf->constant_pool);
  cf->methods->printMethods(*cf->constant_pool);
  cf->attributes->printAttributes(*cf->constant_pool);
}
