#include "../headers/reader.h"

#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"
#include "../headers/definitions.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;

ClassFile *lerArquivo(string nomeArquivo) {
    auto cf = new ClassFile();
    FILE *fp = fopen(nomeArquivo.c_str(), "rb");

    if (!fp)
    { // se nao encontrou arquivo ou nao conseguiu abrir, encerra o programa
        printf("Erro na abertura do arquivo .class, o programa sera encerrado...\n");
        exit(0);
    }

    // file general info
    cf->magic = u4READ(fp);
    cf->minor_version = u2READ(fp);
    cf->major_version = u2READ(fp);

    // constant pool
    cf->constant_pool_count = u2READ(fp);
    cf->constant_pool = new ConstantPool(fp, cf->constant_pool_count);

    // stuff
    cf->access_flags = u2READ(fp);
    cf->this_class = u2READ(fp);
    cf->super_class = u2READ(fp);

    // interfaces
    cf->interfaces_count = u2READ(fp);
    cf->interfaces = new Interfaces(fp, cf->interfaces_count);

    // fields
    cf->fields_count = u2READ(fp);
    // cf->fields = new Fields(fp, cf->fields_count);

    // methods
    cf->methods_count = u2READ(fp);
    // cf->methods = new Methods(fp, cf->methods_count);

    // attributes
    cf->attributes_count = u2READ(fp);
    // cf->attributes = new attributes(fp, cf->attributes_count);
    
    fclose(fp);
}
