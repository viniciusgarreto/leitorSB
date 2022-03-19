#ifndef definitions_h
#define definitions_h

#include <stdint.h>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;


#define CONSTANT_Utf8 1
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_Class 7
#define CONSTANT_String 8
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_NameAndType 12
#define CONSTANT_MethodHandle 15
#define CONSTANT_MethodType 16
#define CONSTANT_InvokeDynamic 18

#define ACC_PUBLIC 0x0001 
#define ACC_PRIVATE 0x0002 
#define ACC_PROTECTED 0x0004 
#define ACC_STATIC 0x0008 
#define ACC_FINAL 0x0010 
#define ACC_SYNCHRONIZED 0x0020 
#define ACC_BRIDGE 0x0040 
#define ACC_VARARGS 0x0080 
#define ACC_NATIVE 0x0100 
#define ACC_ABSTRACT 0x0400 
#define ACC_STRICT 0x0800 
#define ACC_SYNTHETIC 0x1000 


/*Macro para leitura de um tipo u1 do arquivo .class*/
#define u1READ(arq) getc(arq)
/*Macro para leitura de um tipo u2 do arquivo .class*/
#define u2READ(arq) (getc(arq) << 8) | getc(arq)
/*Macro para leitura de um tipo u4 do arquivo .class*/
#define u4READ(arq) (getc(arq) << 24) | (getc(arq) << 16 | getc(arq) << 8 | getc(arq))

#endif
