#ifndef definitions_h
#define definitions_h

/*
Definitions.h: arquivo destinado a definições de macros usadas no projeto.
*/

#include <stdint.h>
#include <iostream>

//tipos de dados utilizados
typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

typedef int8_t i1;   
typedef int16_t i2;  
typedef int32_t i4;  
typedef int64_t i8;  

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


/** Macro para leitura de um tipo u1 do arquivo .class*/
#define u1READ(arq) getc(arq)
/** Macro para leitura de um tipo u2 do arquivo .class*/
#define u2READ(arq) (getc(arq) << 8) | getc(arq)
/** Macro para leitura de um tipo u4 do arquivo .class*/
#define u4READ(arq) (getc(arq) << 24) | (getc(arq) << 16 | getc(arq) << 8 | getc(arq))

std::ostream& indentBy(unsigned int n, std::ostream& out = std::cout);

/// opcode de instrucoes 
#define nop 0x00
#define aconst_null 0x01
#define iconst_m1 0x02
#define iconst_0 0x03
#define iconst_2 0x05
#define iconst_1 0x04
#define iconst_3 0x06
#define iconst_4 0x07
#define iconst_5 0x08
#define lconst_0 0x09
#define lconst_1 0x0a
#define fconst_0 0x0b
#define fconst_1 0x0c
#define fconst_2 0x0d
#define dconst_0 0x0e
#define dconst_1 0x0f
#define bipush 0x10
#define sipush 0x11
#define ldc 0x12
#define ldc_w 0x13
#define ldc2_w 0x14
#define iload 0x15
#define lload 0x16
#define fload 0x17
#define dload 0x18
#define aload 0x19
#define iload_0 0x1a
#define iload_1 0x1b
#define iload_2 0x1c
#define iload_3 0x1d
#define lload_0 0x1e
#define lload_1 0x1f
#define lload_2 0x20
#define lload_3 0x21
#define fload_0 0x22
#define fload_1 0x23
#define fload_2 0x24
#define fload_3 0x25
#define dload_0 0x26
#define dload_1 0x27
#define dload_2 0x28
#define dload_3 0x29
#define aload_0 0x2a
#define aload_1 0x2b
#define aload_2 0x2c
#define aload_3 0x2d
#define iaload 0x2e
#define laload 0x2f
#define faload 0x30
#define daload 0x31
#define aaload 0x32
#define baload 0x33
#define caload 0x34
#define saload 0x35
#define istore 0x36
#define lstore 0x37
#define fstore 0x38
#define dstore 0x39
#define astore 0x3a
#define istore_0 0x3b
#define istore_1 0x3c
#define istore_2 0x3d
#define istore_3 0x3e
#define lstore_0 0x3f
#define lstore_1 0x40
#define lstore_2 0x41
#define lstore_3 0x42
#define fstore_0 0x43
#define fstore_1 0x44
#define fstore_2 0x45
#define fstore_3 0x46
#define dstore_0 0x47
#define dstore_1 0x48
#define dstore_2 0x49
#define dstore_3 0x4a
#define astore_0 0x4b
#define astore_1 0x4c
#define astore_2 0x4d
#define astore_3 0x4e
#define iastore 0x4f
#define lastore 0x50
#define fastore 0x51
#define dastore 0x52
#define aastore 0x53
#define bastore 0x54
#define castore 0x55
#define sastore 0x56
#define pop 0x57
#define pop2 0x58
#define dup 0x59
#define dup_x1 0x5a
#define dup_x2 0x5b
#define dup2 0x5c
#define dup2_x1 0x5d
#define dup2_x2 0x5e
#define swapSwap 0x5f
#define iadd 0x60
#define ladd 0x61
#define fadd 0x62
#define dadd 0x63
#define isub 0x64
#define lsub 0x65
#define fsub 0x66
#define dsub 0x67
#define imul 0x68
#define lmul 0x69
#define fmul 0x6a
#define dmul 0x6b
#define idiv 0x6c
#define inst_ldiv 0x6d
#define fdiv 0x6e
#define ddiv 0x6f
#define irem 0x70
#define lrem 0x71
#define frem 0x72
#define inst_drem 0x73
#define ineg 0x74
#define lneg 0x75
#define fneg 0x76
#define dneg 0x77
#define ishl 0x78
#define lshl 0x79
#define ishr 0x7a
#define lshr 0x7b
#define iushr 0x7c
#define lushr 0x7d
#define iand 0x7e
#define land 0x7f
#define ior 0x80
#define lor 0x81
#define ixor 0x82
#define lxor 0x83
#define iinc 0x84
#define i2l 0x85
#define i2f 0x86
#define i2d 0x87
#define l2i 0x88
#define l2f 0x89
#define l2d 0x8a
#define f2i 0x8b
#define f2l 0x8c
#define f2d 0x8d
#define d2i 0x8e
#define d2l 0x8f
#define d2f 0x90
#define i2b 0x91
#define i2c 0x92
#define i2s 0x93
#define lcmp 0x94
#define fcmpl 0x95
#define fcmpg 0x96
#define dcmpl 0x97
#define dcmpg 0x98
#define ifeq 0x99
#define ifne 0x9a
#define iflt 0x9b
#define ifge 0x9c
#define ifgt 0x9d
#define ifle 0x9e
#define if_icmpeq 0x9f
#define if_icmpne 0xa0
#define if_icmplt 0xa1
#define if_icmpge 0xa2
#define if_icmpgt 0xa3
#define if_icmple 0xa4
#define if_acmpeq 0xa5
#define if_acmpne 0xa6
#define inst_goto 0xa7
#define jsr 0xa8
#define ret 0xa9
#define tableswitch 0xaa
#define lookupswitch 0xab
#define ireturn 0xac
#define lreturn 0xad
#define freturn 0xae
#define dreturn 0xaf
#define areturn 0xb0
#define inst_return 0xb1
#define getstatic 0xb2
#define putstatic 0xb3
#define getfield 0xb4
#define putfield 0xb5
#define invokevirtual 0xb6
#define invokespecial 0xb7
#define invokestatic 0xb8
#define invokeinterface 0xb9
#define inst_new 0xbb
#define newarray 0xbc
#define anewarray 0xbd
#define arraylength 0xbe
#define athrow 0xbf
#define checkcast 0xc0
#define instanceof 0xc1
#define monitorenter 0xc2
#define monitorexit 0xc3
#define wide 0xc4
#define multianewarray 0xc5
#define ifnull 0xc6
#define ifnonnull 0xc7
#define goto_w 0xc8
#define jsr_w 0xc9

/** Definição de algumas macros relativas aos nomes e descritores de métodos main, init e clinit */
#define MAIN_NOME "main"
#define DESCRIPTOR_MAIN "([Ljava/lang/String;)V"
#define PUBLIC_STATIC 0x0009
#define CLINIT_NOME "<clinit>"
#define DESCRIPTOR_CLINIT "()V"
#define STATICCLINIT 0x0008
#define INIT_NOME "<init>"
#define DESCRIPTOR_INIT "()V"

#define SOURCE_FILE_ATTRIBUTE "SourceFile"
#define CODE_ATTRIBUTE "Code"
#define LINE_NUMBER_ATTRIBUTE "LineNumberTable"
#define STACK_MAP_ATTRIBUTE "StackMapTable"
#define INNER_CLASS_ATTRIBUTE "InnerClasses"
#define SIGNATURE_ATTRIBUTE "Signature"
#define CONSTANT_ATTRIBUTE "ConstantValue"
#define EXCEPTIONS_ATTRIBUTE "Exceptions"

#endif
