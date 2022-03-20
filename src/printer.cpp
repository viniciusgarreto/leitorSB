#include <stdio.h>
#include <iostream>
#include "../headers/classFile.h"
using namespace std;

void imprimirArquivo(ClassFile *cf) {
  // printf("Magic: %08x\n", cf->magic);
  // printf("Minor Version: %04x\n", cf->minor_version);
  // printf("Major Version: %04x\n", cf->major_version);
  // // printf("Constant Pool Count: %04x\n", cf->constant_pool_count);
  // printf("Constant Pool: \n");

  // cf->constant_pool->printConstantPool();
  // printf("Access Flags: %04x\n", cf->access_flags);
  // printf("This Class: %04x\n", cf->this_class);
  // printf("Super Class: %04x\n", cf->super_class);

  // cout << *cf->interfaces;
  // cout << cf->interfaces->ToString(*cf->constant_pool) << endl;

  // printf("Interfaces Count: %04x\n", cf->interfaces_count);
  // printf("Fields Count: %04x\n", cf->fields_count);
  
  //--fields
  cout << endl;
  cf->fields->printFields();
  //TO DO:
  // printf("Methods Count: %04x\n",cf->methods_count);
  // printf("Atributes Count: %02x\n",cf->attributes_count);

//   imprimeConstantPool(cf);
//   imprimeFields(cf);
//   imprimeMetodos(cf);
//   imprimeAtributosClasse(cf);
}
