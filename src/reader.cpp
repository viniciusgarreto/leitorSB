#include "../headers/reader.h"
#include <stdio.h>
#include <stdlib.h>

/*Macro para leitura de um tipo u1 do arquivo .class*/
#define u1READ(arq) getc(arq)
/*Macro para leitura de um tipo u2 do arquivo .class*/
#define u2READ(arq) (getc(arq) << 8) | getc(arq)
/*Macro para leitura de um tipo u4 do arquivo .class*/
#define u4READ(arq) (getc(arq) << 24) | (getc(arq) << 16 | getc(arq) << 8 | getc(arq))

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

    cf->constant_pool_count = u2Read(fp);

    printf("Magic: %08x\n", cf->magic);
    
    fclose(fp);
}
