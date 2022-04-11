#include "../headers/Instructions.h"

#include <stdlib.h>
#include <string.h>




void Instruction::setInstructions() {
  /* Instruction* instruc =
      (Instruction*)malloc(this->EnumCheck * sizeof(struct Instruction)); */

  this->instruc = (Instruction*)malloc(this->EnumCheck * sizeof(struct Instruction)); 

  // strcpy(instruc[0].name, "nop");
  // instruc[0].opcode = nop;
  // instruc[0].argnum = 0;
  // instruc[0].opnum = 0;

  // strcpy(instruc[1].name, "aconst_null");
  // instruc[1].opcode = aconst_null;
  // instruc[1].argnum = 0;
  // instruc[1].opnum = 0;

  for (int i = 0; i <= EnumCheck; i++) {
      switch (i) {
          case nop:
              strcpy(instruc[i].name, "nop");
              instruc[i].opcode = nop;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case aconst_null:
              strcpy(instruc[i].name, "aconst_null");
              instruc[i].opcode = aconst_null;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_m1:
              strcpy(instruc[i].name, "iconst_m1");
              instruc[i].opcode = iconst_m1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_0:
              strcpy(instruc[i].name, "iconst_0");
              instruc[i].opcode = iconst_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_1:
              strcpy(instruc[i].name, "iconst_1");
              instruc[i].opcode = iconst_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_2:
              strcpy(instruc[i].name, "iconst_2");
              instruc[i].opcode = iconst_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_3:
              strcpy(instruc[i].name, "iconst_3");
              instruc[i].opcode = iconst_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_4:
              strcpy(instruc[i].name, "iconst_4");
              instruc[i].opcode = iconst_4;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iconst_5:
              strcpy(instruc[i].name, "iconst_5");
              instruc[i].opcode = iconst_5;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lconst_0:
              strcpy(instruc[i].name, "lconst_0");
              instruc[i].opcode = lconst_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lconst_1:
              strcpy(instruc[i].name, "lconst_1");
              instruc[i].opcode = lconst_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fconst_0:
              strcpy(instruc[i].name, "fconst_0");
              instruc[i].opcode = fconst_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fconst_1:
              strcpy(instruc[i].name, "fconst_1");
              instruc[i].opcode = fconst_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fconst_2:
              strcpy(instruc[i].name, "fconst_2");
              instruc[i].opcode = fconst_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dconst_0:
              strcpy(instruc[i].name, "dconst_0");
              instruc[i].opcode = dconst_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dconst_1:
              strcpy(instruc[i].name, "dconst_1");
              instruc[i].opcode = dconst_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case bipush:
              strcpy(instruc[i].name, "bipush");
              instruc[i].opcode = bipush;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case sipush:
              strcpy(instruc[i].name, "sipush");
              instruc[i].opcode = sipush;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case ldc:
              strcpy(instruc[i].name, "ldc");
              instruc[i].opcode = ldc;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case ldc_w:
              strcpy(instruc[i].name, "ldc_w");
              instruc[i].opcode = ldc_w;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case ldc2_w:
              strcpy(instruc[i].name, "ldc2_w");
              instruc[i].opcode = ldc2_w;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case iload:
              strcpy(instruc[i].name, "iload");
              instruc[i].opcode = iload;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case lload:
              strcpy(instruc[i].name, "lload");
              instruc[i].opcode = lload;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case fload:
              strcpy(instruc[i].name, "fload");
              instruc[i].opcode = fload;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case dload:
              strcpy(instruc[i].name, "dload");
              instruc[i].opcode = dload;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case aload:
              strcpy(instruc[i].name, "aload");
              instruc[i].opcode = aload;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case iload_0:
              strcpy(instruc[i].name, "iload_0");
              instruc[i].opcode = iload_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iload_1:
              strcpy(instruc[i].name, "iload_1");
              instruc[i].opcode = iload_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iload_2:
              strcpy(instruc[i].name, "iload_2");
              instruc[i].opcode = iload_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iload_3:
              strcpy(instruc[i].name, "iload_3");
              instruc[i].opcode = iload_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lload_0:
              strcpy(instruc[i].name, "lload_0");
              instruc[i].opcode = lload_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lload_1:
              strcpy(instruc[i].name, "lload_1");
              instruc[i].opcode = lload_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lload_2:
              strcpy(instruc[i].name, "lload_2");
              instruc[i].opcode = lload_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case lload_3:
              strcpy(instruc[i].name, "lload_3");
              instruc[i].opcode = lload_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fload_0:
              strcpy(instruc[i].name, "fload_0");
              instruc[i].opcode = fload_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fload_1:
              strcpy(instruc[i].name, "fload_1");
              instruc[i].opcode = fload_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fload_2:
              strcpy(instruc[i].name, "fload_2");
              instruc[i].opcode = fload_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case fload_3:
              strcpy(instruc[i].name, "fload_3");
              instruc[i].opcode = fload_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dload_0:
              strcpy(instruc[i].name, "dload_0");
              instruc[i].opcode = dload_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dload_1:
              strcpy(instruc[i].name, "dload_1");
              instruc[i].opcode = dload_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dload_2:
              strcpy(instruc[i].name, "dload_2");
              instruc[i].opcode = dload_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case dload_3:
              strcpy(instruc[i].name, "dload_3");
              instruc[i].opcode = dload_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case aload_0:
              strcpy(instruc[i].name, "aload_0");
              instruc[i].opcode = aload_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case aload_1:
              strcpy(instruc[i].name, "aload_1");
              instruc[i].opcode = aload_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case aload_2:
              strcpy(instruc[i].name, "aload_2");
              instruc[i].opcode = aload_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case aload_3:
              strcpy(instruc[i].name, "aload_3");
              instruc[i].opcode = aload_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case iaload:
              strcpy(instruc[i].name, "iaload");
              instruc[i].opcode = iaload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case laload:
              strcpy(instruc[i].name, "laload");
              instruc[i].opcode = laload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case faload:
              strcpy(instruc[i].name, "faload");
              instruc[i].opcode = faload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case daload:
              strcpy(instruc[i].name, "daload");
              instruc[i].opcode = daload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case aaload:
              strcpy(instruc[i].name, "aaload");
              instruc[i].opcode = aaload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case baload:
              strcpy(instruc[i].name, "baload");
              instruc[i].opcode = baload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case caload:
              strcpy(instruc[i].name, "caload");
              instruc[i].opcode = caload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case saload:
              strcpy(instruc[i].name, "saload");
              instruc[i].opcode = saload;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case istore:
              strcpy(instruc[i].name, "istore");
              instruc[i].opcode = istore;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case lstore:
              strcpy(instruc[i].name, "lstore");
              instruc[i].opcode = lstore;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case fstore:
              strcpy(instruc[i].name, "fstore");
              instruc[i].opcode = fstore;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case dstore:
              strcpy(instruc[i].name, "dstore");
              instruc[i].opcode = dstore;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case astore:
              strcpy(instruc[i].name, "astore");
              instruc[i].opcode = astore;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case istore_0:
              strcpy(instruc[i].name, "istore_0");
              instruc[i].opcode = istore_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case istore_1:
              strcpy(instruc[i].name, "istore_1");
              instruc[i].opcode = istore_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case istore_2:
              strcpy(instruc[i].name, "istore_2");
              instruc[i].opcode = istore_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case istore_3:
              strcpy(instruc[i].name, "istore_3");
              instruc[i].opcode = istore_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lstore_0:
              strcpy(instruc[i].name, "lstore_0");
              instruc[i].opcode = lstore_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lstore_1:
              strcpy(instruc[i].name, "lstore_1");
              instruc[i].opcode = lstore_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lstore_2:
              strcpy(instruc[i].name, "lstore_2");
              instruc[i].opcode = lstore_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lstore_3:
              strcpy(instruc[i].name, "lstore_3");
              instruc[i].opcode = lstore_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case fstore_0:
              strcpy(instruc[i].name, "fstore_0");
              instruc[i].opcode = fstore_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case fstore_1:
              strcpy(instruc[i].name, "fstore_1");
              instruc[i].opcode = fstore_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case fstore_2:
              strcpy(instruc[i].name, "fstore_2");
              instruc[i].opcode = fstore_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case fstore_3:
              strcpy(instruc[i].name, "fstore_3");
              instruc[i].opcode = fstore_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dstore_0:
              strcpy(instruc[i].name, "dstore_0");
              instruc[i].opcode = dstore_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dstore_1:
              strcpy(instruc[i].name, "dstore_1");
              instruc[i].opcode = dstore_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dstore_2:
              strcpy(instruc[i].name, "dstore_2");
              instruc[i].opcode = dstore_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dstore_3:
              strcpy(instruc[i].name, "dstore_3");
              instruc[i].opcode = dstore_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case astore_0:
              strcpy(instruc[i].name, "astore_0");
              instruc[i].opcode = astore_0;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case astore_1:
              strcpy(instruc[i].name, "astore_1");
              instruc[i].opcode = astore_1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case astore_2:
              strcpy(instruc[i].name, "astore_2");
              instruc[i].opcode = astore_2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case astore_3:
              strcpy(instruc[i].name, "astore_3");
              instruc[i].opcode = astore_3;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case iastore:
              strcpy(instruc[i].name, "iastore");
              instruc[i].opcode = iastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case lastore:
              strcpy(instruc[i].name, "lastore");
              instruc[i].opcode = lastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case fastore:
              strcpy(instruc[i].name, "fastore");
              instruc[i].opcode = fastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case dastore:
              strcpy(instruc[i].name, "dastore");
              instruc[i].opcode = dastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case aastore:
              strcpy(instruc[i].name, "aastore");
              instruc[i].opcode = aastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case bastore:
              strcpy(instruc[i].name, "bastore");
              instruc[i].opcode = bastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case castore:
              strcpy(instruc[i].name, "castore");
              instruc[i].opcode = castore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case sastore:
              strcpy(instruc[i].name, "sastore");
              instruc[i].opcode = sastore;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case pop:
              strcpy(instruc[i].name, "pop");
              instruc[i].opcode = pop;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case pop2:
              strcpy(instruc[i].name, "pop2");
              instruc[i].opcode = pop2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dup:
              strcpy(instruc[i].name, "dup");
              instruc[i].opcode = dup;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dup_x1:
              strcpy(instruc[i].name, "dup_x1");
              instruc[i].opcode = dup_x1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dup_x2:
              strcpy(instruc[i].name, "dup_x2");
              instruc[i].opcode = dup_x2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case dup2:
              strcpy(instruc[i].name, "dup2");
              instruc[i].opcode = dup2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dup2_x1:
              strcpy(instruc[i].name, "dup2_x1");
              instruc[i].opcode = dup2_x1;
              instruc[i].argnum = 0;
              instruc[i].opnum = 3;
              break;

          case dup2_x2:
              strcpy(instruc[i].name, "dup2_x2");
              instruc[i].opcode = dup2_x2;
              instruc[i].argnum = 0;
              instruc[i].opnum = 4;
              break;

          case swapSwap:
              strcpy(instruc[i].name, "swap");
              instruc[i].opcode = swapSwap;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case iadd:
              strcpy(instruc[i].name, "iadd");
              instruc[i].opcode = iadd;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ladd:
              strcpy(instruc[i].name, "ladd");
              instruc[i].opcode = ladd;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fadd:
              strcpy(instruc[i].name, "fadd");
              instruc[i].opcode = fadd;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dadd:
              strcpy(instruc[i].name, "dadd");
              instruc[i].opcode = dadd;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case isub:
              strcpy(instruc[i].name, "isub");
              instruc[i].opcode = isub;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lsub:
              strcpy(instruc[i].name, "lsub");
              instruc[i].opcode = lsub;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fsub:
              strcpy(instruc[i].name, "fsub");
              instruc[i].opcode = fsub;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dsub:
              strcpy(instruc[i].name, "dsub");
              instruc[i].opcode = dsub;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case imul:
              strcpy(instruc[i].name, "imul");
              instruc[i].opcode = imul;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fmul:
              strcpy(instruc[i].name, "fmul");
              instruc[i].opcode = fmul;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dmul:
              strcpy(instruc[i].name, "dmul");
              instruc[i].opcode = dmul;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case idiv:
              strcpy(instruc[i].name, "idiv");
              instruc[i].opcode = idiv;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case inst_ldiv:
              strcpy(instruc[i].name, "inst_ldiv");
              instruc[i].opcode = inst_ldiv;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fdiv:
              strcpy(instruc[i].name, "fdiv");
              instruc[i].opcode = fdiv;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ddiv:
              strcpy(instruc[i].name, "ddiv");
              instruc[i].opcode = ddiv;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case irem:
              strcpy(instruc[i].name, "irem");
              instruc[i].opcode = irem;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lrem:
              strcpy(instruc[i].name, "lrem");
              instruc[i].opcode = lrem;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case frem:
              strcpy(instruc[i].name, "frem");
              instruc[i].opcode = frem;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case inst_drem:
              strcpy(instruc[i].name, "inst_drem");
              instruc[i].opcode = inst_drem;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ineg:
              strcpy(instruc[i].name, "ineg");
              instruc[i].opcode = ineg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lneg:
              strcpy(instruc[i].name, "lneg");
              instruc[i].opcode = lneg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case fneg:
              strcpy(instruc[i].name, "fneg");
              instruc[i].opcode = fneg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dneg:
              strcpy(instruc[i].name, "dneg");
              instruc[i].opcode = dneg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case ishl:
              strcpy(instruc[i].name, "ishl");
              instruc[i].opcode = ishl;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lshl:
              strcpy(instruc[i].name, "lshl");
              instruc[i].opcode = lshl;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ishr:
              strcpy(instruc[i].name, "ishr");
              instruc[i].opcode = ishr;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lshr:
              strcpy(instruc[i].name, "lshr");
              instruc[i].opcode = lshr;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case iushr:
              strcpy(instruc[i].name, "iushr");
              instruc[i].opcode = iushr;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lushr:
              strcpy(instruc[i].name, "lushr");
              instruc[i].opcode = lushr;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case iand:
              strcpy(instruc[i].name, "iand");
              instruc[i].opcode = iand;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ior:
              strcpy(instruc[i].name, "ior");
              instruc[i].opcode = ior;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lor:
              strcpy(instruc[i].name, "lor");
              instruc[i].opcode = lor;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ixor:
              strcpy(instruc[i].name, "ixor");
              instruc[i].opcode = ixor;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case lxor:
              strcpy(instruc[i].name, "lxor");
              instruc[i].opcode = lxor;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case iinc:
              strcpy(instruc[i].name, "iinc");
              instruc[i].opcode = iinc;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case i2l:
              strcpy(instruc[i].name, "i2l");
              instruc[i].opcode = i2l;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case i2f:
              strcpy(instruc[i].name, "i2f");
              instruc[i].opcode = i2f;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case i2d:
              strcpy(instruc[i].name, "i2d");
              instruc[i].opcode = i2d;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case l2i:
              strcpy(instruc[i].name, "l2i");
              instruc[i].opcode = l2i;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case l2f:
              strcpy(instruc[i].name, "l2f");
              instruc[i].opcode = l2f;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case l2d:
              strcpy(instruc[i].name, "l2d");
              instruc[i].opcode = l2d;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case f2i:
              strcpy(instruc[i].name, "f2i");
              instruc[i].opcode = f2i;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case f2l:
              strcpy(instruc[i].name, "f2l");
              instruc[i].opcode = f2l;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case f2d:
              strcpy(instruc[i].name, "f2d");
              instruc[i].opcode = f2d;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case d2i:
              strcpy(instruc[i].name, "d2i");
              instruc[i].opcode = d2i;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case d2l:
              strcpy(instruc[i].name, "d2l");
              instruc[i].opcode = d2l;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case d2f:
              strcpy(instruc[i].name, "d2f");
              instruc[i].opcode = d2f;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case i2b:
              strcpy(instruc[i].name, "i2b");
              instruc[i].opcode = i2b;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case i2c:
              strcpy(instruc[i].name, "i2c");
              instruc[i].opcode = i2c;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case i2s:
              strcpy(instruc[i].name, "i2s");
              instruc[i].opcode = i2s;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lcmp:
              strcpy(instruc[i].name, "lcmp");
              instruc[i].opcode = lcmp;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fcmpl:
              strcpy(instruc[i].name, "fcmpl");
              instruc[i].opcode = fcmpl;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case fcmpg:
              strcpy(instruc[i].name, "fcmpg");
              instruc[i].opcode = fcmpg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dcmpl:
              strcpy(instruc[i].name, "dcmpl");
              instruc[i].opcode = dcmpl;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case dcmpg:
              strcpy(instruc[i].name, "dcmpg");
              instruc[i].opcode = dcmpg;
              instruc[i].argnum = 0;
              instruc[i].opnum = 2;
              break;

          case ifeq:
              strcpy(instruc[i].name, "ifeq");
              instruc[i].opcode = ifeq;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case ifne:
              strcpy(instruc[i].name, "ifne");
              instruc[i].opcode = ifne;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case iflt:
              strcpy(instruc[i].name, "iflt");
              instruc[i].opcode = iflt;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case ifge:
              strcpy(instruc[i].name, "ifge");
              instruc[i].opcode = ifge;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case ifgt:
              strcpy(instruc[i].name, "ifgt");
              instruc[i].opcode = ifgt;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case ifle:
              strcpy(instruc[i].name, "ifle");
              instruc[i].opcode = ifle;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case if_icmpeq:
              strcpy(instruc[i].name, "if_icmpeq");
              instruc[i].opcode = if_icmpeq;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_icmpne:
              strcpy(instruc[i].name, "if_icmpne");
              instruc[i].opcode = if_icmpne;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_icmplt:
              strcpy(instruc[i].name, "if_icmplt");
              instruc[i].opcode = if_icmplt;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_icmpge:
              strcpy(instruc[i].name, "if_icmpge");
              instruc[i].opcode = if_icmpge;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_icmpgt:
              strcpy(instruc[i].name, "if_icmpgt");
              instruc[i].opcode = if_icmpgt;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_icmple:
              strcpy(instruc[i].name, "if_icmple");
              instruc[i].opcode = if_icmple;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_acmpeq:
              strcpy(instruc[i].name, "if_acmpeq");
              instruc[i].opcode = if_acmpeq;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case if_acmpne:
              strcpy(instruc[i].name, "if_acmpne");
              instruc[i].opcode = if_acmpne;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case inst_goto:
              strcpy(instruc[i].name, "inst_goto");
              instruc[i].opcode = inst_goto;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case jsr:
              strcpy(instruc[i].name, "jsr");
              instruc[i].opcode = jsr;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case ret:
              strcpy(instruc[i].name, "ret");
              instruc[i].opcode = ret;
              instruc[i].argnum = 1;
              instruc[i].opnum = 0;
              break;

          case tableswitch:
              strcpy(instruc[i].name, "tableswitch");
              instruc[i].opcode = tableswitch;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lookupswitch:
              strcpy(instruc[i].name, "lookupswitch");
              instruc[i].opcode = lookupswitch;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case ireturn:
              strcpy(instruc[i].name, "ireturn");
              instruc[i].opcode = ireturn;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case lreturn:
              strcpy(instruc[i].name, "lreturn");
              instruc[i].opcode = lreturn;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case freturn:
              strcpy(instruc[i].name, "freturn");
              instruc[i].opcode = freturn;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case dreturn:
              strcpy(instruc[i].name, "dreturn");
              instruc[i].opcode = dreturn;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case areturn:
              strcpy(instruc[i].name, "areturn");
              instruc[i].opcode = areturn;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case inst_return:
              strcpy(instruc[i].name, "inst_return");
              instruc[i].opcode = inst_return;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case getstatic:
              strcpy(instruc[i].name, "getstatic");
              instruc[i].opcode = getstatic;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case putstatic:
              strcpy(instruc[i].name, "putstatic");
              instruc[i].opcode = putstatic;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case getfield:
              strcpy(instruc[i].name, "getfield");
              instruc[i].opcode = getfield;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case putfield:
              strcpy(instruc[i].name, "putfield");
              instruc[i].opcode = putfield;
              instruc[i].argnum = 2;
              instruc[i].opnum = 2;
              break;

          case invokevirtual:
              strcpy(instruc[i].name, "invokevirtual");
              instruc[i].opcode = invokevirtual;
              instruc[i].argnum = 2;
              instruc[i].opnum = -1;
              break;

          case invokespecial:
              strcpy(instruc[i].name, "invokespecial");
              instruc[i].opcode = invokespecial;
              instruc[i].argnum = 2;
              instruc[i].opnum = -1;
              break;

          case invokestatic:
              strcpy(instruc[i].name, "invokestatic");
              instruc[i].opcode = invokestatic;
              instruc[i].argnum = 2;
              instruc[i].opnum = -1;
              break;

          case invokeinterface:
              strcpy(instruc[i].name, "invokeinterface");
              instruc[i].opcode = invokeinterface;
              instruc[i].argnum = 4;
              instruc[i].opnum = -1;
              break;

          case inst_new:
              strcpy(instruc[i].name, "inst_new");
              instruc[i].opcode = inst_new;
              instruc[i].argnum = 2;
              instruc[i].opnum = 0;
              break;

          case newarray:
              strcpy(instruc[i].name, "newarray");
              instruc[i].opcode = newarray;
              instruc[i].argnum = 1;
              instruc[i].opnum = 1;
              break;

          case anewarray:
              strcpy(instruc[i].name, "anewarray");
              instruc[i].opcode = anewarray;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case arraylength:
              strcpy(instruc[i].name, "arraylength");
              instruc[i].opcode = arraylength;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case athrow:
              strcpy(instruc[i].name, "athrow");
              instruc[i].opcode = athrow;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case checkcast:
              strcpy(instruc[i].name, "checkcast");
              instruc[i].opcode = checkcast;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case instanceof:
              strcpy(instruc[i].name, "instanceof");
              instruc[i].opcode = instanceof ;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case monitorenter:
              strcpy(instruc[i].name, "monitorenter");
              instruc[i].opcode = monitorenter;
              instruc[i].argnum = 0;
              instruc[i].opnum = 1;
              break;

          case wide:
              strcpy(instruc[i].name, "wide");
              instruc[i].opcode = wide;
              instruc[i].argnum = 0;
              instruc[i].opnum = 0;
              break;

          case multianewarray:
              strcpy(instruc[i].name, "multianewarray");
              instruc[i].opcode = multianewarray;
              instruc[i].argnum = 3;
              instruc[i].opnum = -1;
              break;

          case ifnull:
              strcpy(instruc[i].name, "ifnull");
              instruc[i].opcode = ifnull;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case ifnonnull:
              strcpy(instruc[i].name, "ifnonnull");
              instruc[i].opcode = ifnonnull;
              instruc[i].argnum = 2;
              instruc[i].opnum = 1;
              break;

          case goto_w:
              strcpy(instruc[i].name, "goto_w");
              instruc[i].opcode = goto_w;
              instruc[i].argnum = 4;
              instruc[i].opnum = 0;
              break;

          case jsr_w:
              strcpy(instruc[i].name, "jrs_w");
              instruc[i].opcode = jsr_w;
              instruc[i].argnum = 4;
              instruc[i].opnum = 0;
              break;

          default:
              strcpy(instruc[i].name, "undefined");
              instruc[i].opcode = 255;
              instruc[i].argnum = -1;
              instruc[i].opnum = -1;
              break;
      }
      instruc[i].instruct_pc = instruc[i].argnum + 1;
  }
}

ostream& operator<<(ostream& out, const Instruction& cf) {
    return cf.print(out);
}

ostream& Instruction::print(ostream& output) const {
    output << endl;
    output << "------------- INSTRUCTIONS -------------" << endl;
    output << endl;

    for (int i = 0; i <= 200; i++) {
        output << "Name: " << instruc[i].name << endl;
        output << "Opcode: " << instruc[i].opcode << endl;
        output << "Argum: " << instruc[i].argnum << endl;
        output << "Opnum: " << instruc[i].opnum << endl;
        output << "Instruct_pc: " << instruc[i].instruct_pc << endl;
    }

    return output;
}