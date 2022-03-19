#include "../headers/reader.h"
#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"
#include "../headers/definitions.h"
#include <stdio.h>
#include <stdlib.h>

ClassFile *lerArquivo(ClassFile *cf, char *nomeArquivo)
{
    FILE *fp = fopen(nomeArquivo, "rb");

    if (!fp)
    { // se nao encontrou arquivo ou nao conseguiu abrir, encerra o programa
        printf("Erro na abertura do arquivo .class, o programa sera encerrado...\n");
        exit(0);
    }
    cf->magic = u4READ(fp);
    cf->minor_version = u2READ(fp);
    cf->major_version = u2READ(fp);
    cf->constant_pool_count = u2READ(fp);
    cf->constant_pool = new ConstantPool(fp, cf->constant_pool_count);
    cf->access_flags = u2READ(fp);
    cf->this_class = u2READ(fp);
    cf->super_class = u2READ(fp);
    cf->interfaces_count = u2READ(fp);
    cf->interfaces = new Interfaces(fp, cf->interfaces_count);
    cf->fields_count = u2READ(fp);
    // cf->fields = new Fields(fp, cf->fields_count);


    
    fclose(fp);
}
