#include "../headers/Instructions.h"

#include <stdlib.h>
#include <string.h>




void Instruction::setInstructions() {
  /* Instruction* instruc =
      (Instruction*)malloc(this->EnumCheck * sizeof(struct Instruction)); */

  this->instruc = (Instruction*)malloc(this->EnumCheck * sizeof(struct Instruction)); 

  // instruc[0].name = string("nop");
  // instruc[0].opcode = nop;
  // instruc[0].argnum = 0;
  // instruc[0].opnum = 0;

  // instruc[1].name = string("aconst_null");
  // instruc[1].opcode = aconst_null;
  // instruc[1].argnum = 0;
  // instruc[1].opnum = 0;

//   for (int i = 0; i <= EnumCheck; i++) {
//       switch (i) {
          
        instruc[nop].name = string("nop");
        instruc[nop].opcode = nop;
        instruc[nop].argnum = 0;
        instruc[nop].opnum = 0;

        instruc[aconst_null].name = string("aconst_null");
        instruc[aconst_null].opcode = aconst_null;
        instruc[aconst_null].argnum = 0;
        instruc[aconst_null].opnum = 0;

        instruc[iconst_m1].name = string("iconst_m1");
        instruc[iconst_m1].opcode = iconst_m1;
        instruc[iconst_m1].argnum = 0;
        instruc[iconst_m1].opnum = 0;

        instruc[iconst_0].name = string("iconst_0");
        instruc[iconst_0].opcode = iconst_0;
        instruc[iconst_0].argnum = 0;
        instruc[iconst_0].opnum = 0;

        instruc[iconst_1].name = string("iconst_1");
        instruc[iconst_1].opcode = iconst_1;
        instruc[iconst_1].argnum = 0;
        instruc[iconst_1].opnum = 0;

        instruc[iconst_2].name = string("iconst_2");
        instruc[iconst_2].opcode = iconst_2;
        instruc[iconst_2].argnum = 0;
        instruc[iconst_2].opnum = 0;

        instruc[iconst_3].name = string("iconst_3");
        instruc[iconst_3].opcode = iconst_3;
        instruc[iconst_3].argnum = 0;
        instruc[iconst_3].opnum = 0;

        instruc[iconst_4].name = string("iconst_4");
        instruc[iconst_4].opcode = iconst_4;
        instruc[iconst_4].argnum = 0;
        instruc[iconst_4].opnum = 0;

        instruc[iconst_5].name = string("iconst_5");
        instruc[iconst_5].opcode = iconst_5;
        instruc[iconst_5].argnum = 0;
        instruc[iconst_5].opnum = 0;

        instruc[lconst_0].name = string("lconst_0");
        instruc[lconst_0].opcode = lconst_0;
        instruc[lconst_0].argnum = 0;
        instruc[lconst_0].opnum = 0;

        instruc[lconst_1].name = string("lconst_1");
        instruc[lconst_1].opcode = lconst_1;
        instruc[lconst_1].argnum = 0;
        instruc[lconst_1].opnum = 0;

        instruc[fconst_0].name = string("fconst_0");
        instruc[fconst_0].opcode = fconst_0;
        instruc[fconst_0].argnum = 0;
        instruc[fconst_0].opnum = 0;

        instruc[fconst_1].name = string("fconst_1");
        instruc[fconst_1].opcode = fconst_1;
        instruc[fconst_1].argnum = 0;
        instruc[fconst_1].opnum = 0;

        instruc[fconst_2].name = string("fconst_2");
        instruc[fconst_2].opcode = fconst_2;
        instruc[fconst_2].argnum = 0;
        instruc[fconst_2].opnum = 0;

        instruc[dconst_0].name = string("dconst_0");
        instruc[dconst_0].opcode = dconst_0;
        instruc[dconst_0].argnum = 0;
        instruc[dconst_0].opnum = 0;

        instruc[dconst_1].name = string("dconst_1");
        instruc[dconst_1].opcode = dconst_1;
        instruc[dconst_1].argnum = 0;
        instruc[dconst_1].opnum = 0;

        instruc[bipush].name = string("bipush");
        instruc[bipush].opcode = bipush;
        instruc[bipush].argnum = 1;
        instruc[bipush].opnum = 0;

        instruc[sipush].name = string("sipush");
        instruc[sipush].opcode = sipush;
        instruc[sipush].argnum = 2;
        instruc[sipush].opnum = 0;

        instruc[ldc].name = string("ldc");
        instruc[ldc].opcode = ldc;
        instruc[ldc].argnum = 1;
        instruc[ldc].opnum = 0;

        instruc[ldc_w].name = string("ldc_w");
        instruc[ldc_w].opcode = ldc_w;
        instruc[ldc_w].argnum = 2;
        instruc[ldc_w].opnum = 0;

        instruc[ldc2_w].name = string("ldc2_w");
        instruc[ldc2_w].opcode = ldc2_w;
        instruc[ldc2_w].argnum = 2;
        instruc[ldc2_w].opnum = 0;

        instruc[iload].name = string("iload");
        instruc[iload].opcode = iload;
        instruc[iload].argnum = 1;
        instruc[iload].opnum = 0;

        instruc[lload].name = string("lload");
        instruc[lload].opcode = lload;
        instruc[lload].argnum = 1;
        instruc[lload].opnum = 0;

        instruc[fload].name = string("fload");
        instruc[fload].opcode = fload;
        instruc[fload].argnum = 1;
        instruc[fload].opnum = 0;

        instruc[dload].name = string("dload");
        instruc[dload].opcode = dload;
        instruc[dload].argnum = 1;
        instruc[dload].opnum = 0;

        instruc[aload].name = string("aload");
        instruc[aload].opcode = aload;
        instruc[aload].argnum = 1;
        instruc[aload].opnum = 0;

        instruc[iload_0].name = string("iload_0");
        instruc[iload_0].opcode = iload_0;
        instruc[iload_0].argnum = 0;
        instruc[iload_0].opnum = 0;

        instruc[iload_1].name = string("iload_1");
        instruc[iload_1].opcode = iload_1;
        instruc[iload_1].argnum = 0;
        instruc[iload_1].opnum = 0;

        instruc[iload_2].name = string("iload_2");
        instruc[iload_2].opcode = iload_2;
        instruc[iload_2].argnum = 0;
        instruc[iload_2].opnum = 0;

        instruc[iload_3].name = string("iload_3");
        instruc[iload_3].opcode = iload_3;
        instruc[iload_3].argnum = 0;
        instruc[iload_3].opnum = 0;

        instruc[lload_0].name = string("lload_0");
        instruc[lload_0].opcode = lload_0;
        instruc[lload_0].argnum = 0;
        instruc[lload_0].opnum = 0;

        instruc[lload_1].name = string("lload_1");
        instruc[lload_1].opcode = lload_1;
        instruc[lload_1].argnum = 0;
        instruc[lload_1].opnum = 0;

        instruc[lload_2].name = string("lload_2");
        instruc[lload_2].opcode = lload_2;
        instruc[lload_2].argnum = 0;
        instruc[lload_2].opnum = 0;

        instruc[lload_3].name = string("lload_3");
        instruc[lload_3].opcode = lload_3;
        instruc[lload_3].argnum = 0;
        instruc[lload_3].opnum = 0;

        instruc[fload_0].name = string("fload_0");
        instruc[fload_0].opcode = fload_0;
        instruc[fload_0].argnum = 0;
        instruc[fload_0].opnum = 0;

        instruc[fload_1].name = string("fload_1");
        instruc[fload_1].opcode = fload_1;
        instruc[fload_1].argnum = 0;
        instruc[fload_1].opnum = 0;

        instruc[fload_2].name = string("fload_2");
        instruc[fload_2].opcode = fload_2;
        instruc[fload_2].argnum = 0;
        instruc[fload_2].opnum = 0;

        instruc[fload_3].name = string("fload_3");
        instruc[fload_3].opcode = fload_3;
        instruc[fload_3].argnum = 0;
        instruc[fload_3].opnum = 0;

        instruc[dload_0].name = string("dload_0");
        instruc[dload_0].opcode = dload_0;
        instruc[dload_0].argnum = 0;
        instruc[dload_0].opnum = 0;

        instruc[dload_1].name = string("dload_1");
        instruc[dload_1].opcode = dload_1;
        instruc[dload_1].argnum = 0;
        instruc[dload_1].opnum = 0;

        instruc[dload_2].name = string("dload_2");
        instruc[dload_2].opcode = dload_2;
        instruc[dload_2].argnum = 0;
        instruc[dload_2].opnum = 0;

        instruc[dload_3].name = string("dload_3");
        instruc[dload_3].opcode = dload_3;
        instruc[dload_3].argnum = 0;
        instruc[dload_3].opnum = 0;

        instruc[aload_0].name = string("aload_0");
        instruc[aload_0].opcode = aload_0;
        instruc[aload_0].argnum = 0;
        instruc[aload_0].opnum = 0;

        instruc[aload_1].name = string("aload_1");
        instruc[aload_1].opcode = aload_1;
        instruc[aload_1].argnum = 0;
        instruc[aload_1].opnum = 0;

        instruc[aload_2].name = string("aload_2");
        instruc[aload_2].opcode = aload_2;
        instruc[aload_2].argnum = 0;
        instruc[aload_2].opnum = 0;

        instruc[aload_3].name = string("aload_3");
        instruc[aload_3].opcode = aload_3;
        instruc[aload_3].argnum = 0;
        instruc[aload_3].opnum = 0;

        instruc[iaload].name = string("iaload");
        instruc[iaload].opcode = iaload;
        instruc[iaload].argnum = 0;
        instruc[iaload].opnum = 2;

        instruc[laload].name = string("laload");
        instruc[laload].opcode = laload;
        instruc[laload].argnum = 0;
        instruc[laload].opnum = 2;

        instruc[faload].name = string("faload");
        instruc[faload].opcode = faload;
        instruc[faload].argnum = 0;
        instruc[faload].opnum = 2;

        instruc[daload].name = string("daload");
        instruc[daload].opcode = daload;
        instruc[daload].argnum = 0;
        instruc[daload].opnum = 2;

        instruc[aaload].name = string("aaload");
        instruc[aaload].opcode = aaload;
        instruc[aaload].argnum = 0;
        instruc[aaload].opnum = 2;

        instruc[baload].name = string("baload");
        instruc[baload].opcode = baload;
        instruc[baload].argnum = 0;
        instruc[baload].opnum = 2;

        instruc[caload].name = string("caload");
        instruc[caload].opcode = caload;
        instruc[caload].argnum = 0;
        instruc[caload].opnum = 2;

        instruc[saload].name = string("saload");
        instruc[saload].opcode = saload;
        instruc[saload].argnum = 0;
        instruc[saload].opnum = 2;

        instruc[istore].name = string("istore");
        instruc[istore].opcode = istore;
        instruc[istore].argnum = 1;
        instruc[istore].opnum = 1;

        instruc[lstore].name = string("lstore");
        instruc[lstore].opcode = lstore;
        instruc[lstore].argnum = 1;
        instruc[lstore].opnum = 1;

        instruc[fstore].name = string("fstore");
        instruc[fstore].opcode = fstore;
        instruc[fstore].argnum = 1;
        instruc[fstore].opnum = 1;

        instruc[dstore].name = string("dstore");
        instruc[dstore].opcode = dstore;
        instruc[dstore].argnum = 1;
        instruc[dstore].opnum = 1;

        instruc[astore].name = string("astore");
        instruc[astore].opcode = astore;
        instruc[astore].argnum = 1;
        instruc[astore].opnum = 1;

        instruc[istore_0].name = string("istore_0");
        instruc[istore_0].opcode = istore_0;
        instruc[istore_0].argnum = 0;
        instruc[istore_0].opnum = 1;

        instruc[istore_1].name = string("istore_1");
        instruc[istore_1].opcode = istore_1;
        instruc[istore_1].argnum = 0;
        instruc[istore_1].opnum = 1;

        instruc[istore_2].name = string("istore_2");
        instruc[istore_2].opcode = istore_2;
        instruc[istore_2].argnum = 0;
        instruc[istore_2].opnum = 1;

        instruc[istore_3].name = string("istore_3");
        instruc[istore_3].opcode = istore_3;
        instruc[istore_3].argnum = 0;
        instruc[istore_3].opnum = 1;

        instruc[lstore_0].name = string("lstore_0");
        instruc[lstore_0].opcode = lstore_0;
        instruc[lstore_0].argnum = 0;
        instruc[lstore_0].opnum = 1;

        instruc[lstore_1].name = string("lstore_1");
        instruc[lstore_1].opcode = lstore_1;
        instruc[lstore_1].argnum = 0;
        instruc[lstore_1].opnum = 1;

        instruc[lstore_2].name = string("lstore_2");
        instruc[lstore_2].opcode = lstore_2;
        instruc[lstore_2].argnum = 0;
        instruc[lstore_2].opnum = 1;

        instruc[lstore_3].name = string("lstore_3");
        instruc[lstore_3].opcode = lstore_3;
        instruc[lstore_3].argnum = 0;
        instruc[lstore_3].opnum = 1;

        instruc[fstore_0].name = string("fstore_0");
        instruc[fstore_0].opcode = fstore_0;
        instruc[fstore_0].argnum = 0;
        instruc[fstore_0].opnum = 1;

        instruc[fstore_1].name = string("fstore_1");
        instruc[fstore_1].opcode = fstore_1;
        instruc[fstore_1].argnum = 0;
        instruc[fstore_1].opnum = 1;

        instruc[fstore_2].name = string("fstore_2");
        instruc[fstore_2].opcode = fstore_2;
        instruc[fstore_2].argnum = 0;
        instruc[fstore_2].opnum = 1;

        instruc[fstore_3].name = string("fstore_3");
        instruc[fstore_3].opcode = fstore_3;
        instruc[fstore_3].argnum = 0;
        instruc[fstore_3].opnum = 1;

        instruc[dstore_0].name = string("dstore_0");
        instruc[dstore_0].opcode = dstore_0;
        instruc[dstore_0].argnum = 0;
        instruc[dstore_0].opnum = 1;

        instruc[dstore_1].name = string("dstore_1");
        instruc[dstore_1].opcode = dstore_1;
        instruc[dstore_1].argnum = 0;
        instruc[dstore_1].opnum = 1;

        instruc[dstore_2].name = string("dstore_2");
        instruc[dstore_2].opcode = dstore_2;
        instruc[dstore_2].argnum = 0;
        instruc[dstore_2].opnum = 1;

        instruc[dstore_3].name = string("dstore_3");
        instruc[dstore_3].opcode = dstore_3;
        instruc[dstore_3].argnum = 0;
        instruc[dstore_3].opnum = 1;

        instruc[astore_0].name = string("astore_0");
        instruc[astore_0].opcode = astore_0;
        instruc[astore_0].argnum = 0;
        instruc[astore_0].opnum = 1;

        instruc[astore_1].name = string("astore_1");
        instruc[astore_1].opcode = astore_1;
        instruc[astore_1].argnum = 0;
        instruc[astore_1].opnum = 1;

        instruc[astore_2].name = string("astore_2");
        instruc[astore_2].opcode = astore_2;
        instruc[astore_2].argnum = 0;
        instruc[astore_2].opnum = 1;

        instruc[astore_3].name = string("astore_3");
        instruc[astore_3].opcode = astore_3;
        instruc[astore_3].argnum = 0;
        instruc[astore_3].opnum = 1;

        instruc[iastore].name = string("iastore");
        instruc[iastore].opcode = iastore;
        instruc[iastore].argnum = 0;
        instruc[iastore].opnum = 3;

        instruc[lastore].name = string("lastore");
        instruc[lastore].opcode = lastore;
        instruc[lastore].argnum = 0;
        instruc[lastore].opnum = 3;

        instruc[fastore].name = string("fastore");
        instruc[fastore].opcode = fastore;
        instruc[fastore].argnum = 0;
        instruc[fastore].opnum = 3;

        instruc[dastore].name = string("dastore");
        instruc[dastore].opcode = dastore;
        instruc[dastore].argnum = 0;
        instruc[dastore].opnum = 3;

        instruc[aastore].name = string("aastore");
        instruc[aastore].opcode = aastore;
        instruc[aastore].argnum = 0;
        instruc[aastore].opnum = 3;

        instruc[bastore].name = string("bastore");
        instruc[bastore].opcode = bastore;
        instruc[bastore].argnum = 0;
        instruc[bastore].opnum = 3;

        instruc[castore].name = string("castore");
        instruc[castore].opcode = castore;
        instruc[castore].argnum = 0;
        instruc[castore].opnum = 3;

        instruc[sastore].name = string("sastore");
        instruc[sastore].opcode = sastore;
        instruc[sastore].argnum = 0;
        instruc[sastore].opnum = 3;

        instruc[pop].name = string("pop");
        instruc[pop].opcode = pop;
        instruc[pop].argnum = 0;
        instruc[pop].opnum = 1;

        instruc[pop2].name = string("pop2");
        instruc[pop2].opcode = pop2;
        instruc[pop2].argnum = 0;
        instruc[pop2].opnum = 1;

        instruc[dup].name = string("dup");
        instruc[dup].opcode = dup;
        instruc[dup].argnum = 0;
        instruc[dup].opnum = 1;

        instruc[dup_x1].name = string("dup_x1");
        instruc[dup_x1].opcode = dup_x1;
        instruc[dup_x1].argnum = 0;
        instruc[dup_x1].opnum = 2;

        instruc[dup_x2].name = string("dup_x2");
        instruc[dup_x2].opcode = dup_x2;
        instruc[dup_x2].argnum = 0;
        instruc[dup_x2].opnum = 3;

        instruc[dup2].name = string("dup2");
        instruc[dup2].opcode = dup2;
        instruc[dup2].argnum = 0;
        instruc[dup2].opnum = 2;

        instruc[dup2_x1].name = string("dup2_x1");
        instruc[dup2_x1].opcode = dup2_x1;
        instruc[dup2_x1].argnum = 0;
        instruc[dup2_x1].opnum = 3;

        instruc[dup2_x2].name = string("dup2_x2");
        instruc[dup2_x2].opcode = dup2_x2;
        instruc[dup2_x2].argnum = 0;
        instruc[dup2_x2].opnum = 4;

        instruc[swapSwap].name = string("swap");
        instruc[swapSwap].opcode = swapSwap;
        instruc[swapSwap].argnum = 0;
        instruc[swapSwap].opnum = 2;

        instruc[iadd].name = string("iadd");
        instruc[iadd].opcode = iadd;
        instruc[iadd].argnum = 0;
        instruc[iadd].opnum = 2;

        instruc[ladd].name = string("ladd");
        instruc[ladd].opcode = ladd;
        instruc[ladd].argnum = 0;
        instruc[ladd].opnum = 2;

        instruc[fadd].name = string("fadd");
        instruc[fadd].opcode = fadd;
        instruc[fadd].argnum = 0;
        instruc[fadd].opnum = 2;

        instruc[dadd].name = string("dadd");
        instruc[dadd].opcode = dadd;
        instruc[dadd].argnum = 0;
        instruc[dadd].opnum = 2;

        instruc[isub].name = string("isub");
        instruc[isub].opcode = isub;
        instruc[isub].argnum = 0;
        instruc[isub].opnum = 2;

        instruc[lsub].name = string("lsub");
        instruc[lsub].opcode = lsub;
        instruc[lsub].argnum = 0;
        instruc[lsub].opnum = 2;

        instruc[fsub].name = string("fsub");
        instruc[fsub].opcode = fsub;
        instruc[fsub].argnum = 0;
        instruc[fsub].opnum = 2;

        instruc[dsub].name = string("dsub");
        instruc[dsub].opcode = dsub;
        instruc[dsub].argnum = 0;
        instruc[dsub].opnum = 2;

        instruc[imul].name = string("imul");
        instruc[imul].opcode = imul;
        instruc[imul].argnum = 0;
        instruc[imul].opnum = 2;

        instruc[fmul].name = string("fmul");
        instruc[fmul].opcode = fmul;
        instruc[fmul].argnum = 0;
        instruc[fmul].opnum = 2;

        instruc[dmul].name = string("dmul");
        instruc[dmul].opcode = dmul;
        instruc[dmul].argnum = 0;
        instruc[dmul].opnum = 2;

        instruc[idiv].name = string("idiv");
        instruc[idiv].opcode = idiv;
        instruc[idiv].argnum = 0;
        instruc[idiv].opnum = 2;

        instruc[inst_ldiv].name = string("inst_ldiv");
        instruc[inst_ldiv].opcode = inst_ldiv;
        instruc[inst_ldiv].argnum = 0;
        instruc[inst_ldiv].opnum = 2;

        instruc[fdiv].name = string("fdiv");
        instruc[fdiv].opcode = fdiv;
        instruc[fdiv].argnum = 0;
        instruc[fdiv].opnum = 2;

        instruc[ddiv].name = string("ddiv");
        instruc[ddiv].opcode = ddiv;
        instruc[ddiv].argnum = 0;
        instruc[ddiv].opnum = 2;

        instruc[irem].name = string("irem");
        instruc[irem].opcode = irem;
        instruc[irem].argnum = 0;
        instruc[irem].opnum = 2;

        instruc[lrem].name = string("lrem");
        instruc[lrem].opcode = lrem;
        instruc[lrem].argnum = 0;
        instruc[lrem].opnum = 2;

        instruc[frem].name = string("frem");
        instruc[frem].opcode = frem;
        instruc[frem].argnum = 0;
        instruc[frem].opnum = 2;

        instruc[inst_drem].name = string("inst_drem");
        instruc[inst_drem].opcode = inst_drem;
        instruc[inst_drem].argnum = 0;
        instruc[inst_drem].opnum = 2;

        instruc[ineg].name = string("ineg");
        instruc[ineg].opcode = ineg;
        instruc[ineg].argnum = 0;
        instruc[ineg].opnum = 1;

        instruc[lneg].name = string("lneg");
        instruc[lneg].opcode = lneg;
        instruc[lneg].argnum = 0;
        instruc[lneg].opnum = 1;

        instruc[fneg].name = string("fneg");
        instruc[fneg].opcode = fneg;
        instruc[fneg].argnum = 0;
        instruc[fneg].opnum = 1;

        instruc[dneg].name = string("dneg");
        instruc[dneg].opcode = dneg;
        instruc[dneg].argnum = 0;
        instruc[dneg].opnum = 1;

        instruc[ishl].name = string("ishl");
        instruc[ishl].opcode = ishl;
        instruc[ishl].argnum = 0;
        instruc[ishl].opnum = 2;

        instruc[lshl].name = string("lshl");
        instruc[lshl].opcode = lshl;
        instruc[lshl].argnum = 0;
        instruc[lshl].opnum = 2;

        instruc[ishr].name = string("ishr");
        instruc[ishr].opcode = ishr;
        instruc[ishr].argnum = 0;
        instruc[ishr].opnum = 2;

        instruc[lshr].name = string("lshr");
        instruc[lshr].opcode = lshr;
        instruc[lshr].argnum = 0;
        instruc[lshr].opnum = 2;

        instruc[iushr].name = string("iushr");
        instruc[iushr].opcode = iushr;
        instruc[iushr].argnum = 0;
        instruc[iushr].opnum = 2;

        instruc[lushr].name = string("lushr");
        instruc[lushr].opcode = lushr;
        instruc[lushr].argnum = 0;
        instruc[lushr].opnum = 2;

        instruc[iand].name = string("iand");
        instruc[iand].opcode = iand;
        instruc[iand].argnum = 0;
        instruc[iand].opnum = 2;

        instruc[ior].name = string("ior");
        instruc[ior].opcode = ior;
        instruc[ior].argnum = 0;
        instruc[ior].opnum = 2;

        instruc[lor].name = string("lor");
        instruc[lor].opcode = lor;
        instruc[lor].argnum = 0;
        instruc[lor].opnum = 2;

        instruc[ixor].name = string("ixor");
        instruc[ixor].opcode = ixor;
        instruc[ixor].argnum = 0;
        instruc[ixor].opnum = 2;

        instruc[lxor].name = string("lxor");
        instruc[lxor].opcode = lxor;
        instruc[lxor].argnum = 0;
        instruc[lxor].opnum = 2;

        instruc[iinc].name = string("iinc");
        instruc[iinc].opcode = iinc;
        instruc[iinc].argnum = 2;
        instruc[iinc].opnum = 0;

        instruc[i2l].name = string("i2l");
        instruc[i2l].opcode = i2l;
        instruc[i2l].argnum = 0;
        instruc[i2l].opnum = 1;

        instruc[i2f].name = string("i2f");
        instruc[i2f].opcode = i2f;
        instruc[i2f].argnum = 0;
        instruc[i2f].opnum = 1;

        instruc[i2d].name = string("i2d");
        instruc[i2d].opcode = i2d;
        instruc[i2d].argnum = 0;
        instruc[i2d].opnum = 1;

        instruc[l2i].name = string("l2i");
        instruc[l2i].opcode = l2i;
        instruc[l2i].argnum = 0;
        instruc[l2i].opnum = 1;

        instruc[l2f].name = string("l2f");
        instruc[l2f].opcode = l2f;
        instruc[l2f].argnum = 0;
        instruc[l2f].opnum = 1;

        instruc[l2d].name = string("l2d");
        instruc[l2d].opcode = l2d;
        instruc[l2d].argnum = 0;
        instruc[l2d].opnum = 1;

        instruc[f2i].name = string("f2i");
        instruc[f2i].opcode = f2i;
        instruc[f2i].argnum = 0;
        instruc[f2i].opnum = 1;

        instruc[f2l].name = string("f2l");
        instruc[f2l].opcode = f2l;
        instruc[f2l].argnum = 0;
        instruc[f2l].opnum = 1;

        instruc[f2d].name = string("f2d");
        instruc[f2d].opcode = f2d;
        instruc[f2d].argnum = 0;
        instruc[f2d].opnum = 1;

        instruc[d2i].name = string("d2i");
        instruc[d2i].opcode = d2i;
        instruc[d2i].argnum = 0;
        instruc[d2i].opnum = 1;

        instruc[d2l].name = string("d2l");
        instruc[d2l].opcode = d2l;
        instruc[d2l].argnum = 0;
        instruc[d2l].opnum = 1;

        instruc[d2f].name = string("d2f");
        instruc[d2f].opcode = d2f;
        instruc[d2f].argnum = 0;
        instruc[d2f].opnum = 1;

        instruc[i2b].name = string("i2b");
        instruc[i2b].opcode = i2b;
        instruc[i2b].argnum = 0;
        instruc[i2b].opnum = 1;

        instruc[i2c].name = string("i2c");
        instruc[i2c].opcode = i2c;
        instruc[i2c].argnum = 0;
        instruc[i2c].opnum = 1;

        instruc[i2s].name = string("i2s");
        instruc[i2s].opcode = i2s;
        instruc[i2s].argnum = 0;
        instruc[i2s].opnum = 1;

        instruc[lcmp].name = string("lcmp");
        instruc[lcmp].opcode = lcmp;
        instruc[lcmp].argnum = 0;
        instruc[lcmp].opnum = 2;

        instruc[fcmpl].name = string("fcmpl");
        instruc[fcmpl].opcode = fcmpl;
        instruc[fcmpl].argnum = 0;
        instruc[fcmpl].opnum = 2;

        instruc[fcmpg].name = string("fcmpg");
        instruc[fcmpg].opcode = fcmpg;
        instruc[fcmpg].argnum = 0;
        instruc[fcmpg].opnum = 2;

        instruc[dcmpl].name = string("dcmpl");
        instruc[dcmpl].opcode = dcmpl;
        instruc[dcmpl].argnum = 0;
        instruc[dcmpl].opnum = 2;

        instruc[dcmpg].name = string("dcmpg");
        instruc[dcmpg].opcode = dcmpg;
        instruc[dcmpg].argnum = 0;
        instruc[dcmpg].opnum = 2;

        instruc[ifeq].name = string("ifeq");
        instruc[ifeq].opcode = ifeq;
        instruc[ifeq].argnum = 2;
        instruc[ifeq].opnum = 1;

        instruc[ifne].name = string("ifne");
        instruc[ifne].opcode = ifne;
        instruc[ifne].argnum = 2;
        instruc[ifne].opnum = 1;

        instruc[iflt].name = string("iflt");
        instruc[iflt].opcode = iflt;
        instruc[iflt].argnum = 2;
        instruc[iflt].opnum = 1;

        instruc[ifge].name = string("ifge");
        instruc[ifge].opcode = ifge;
        instruc[ifge].argnum = 2;
        instruc[ifge].opnum = 1;

        instruc[ifgt].name = string("ifgt");
        instruc[ifgt].opcode = ifgt;
        instruc[ifgt].argnum = 2;
        instruc[ifgt].opnum = 1;

        instruc[ifle].name = string("ifle");
        instruc[ifle].opcode = ifle;
        instruc[ifle].argnum = 2;
        instruc[ifle].opnum = 1;

        instruc[if_icmpeq].name = string("if_icmpeq");
        instruc[if_icmpeq].opcode = if_icmpeq;
        instruc[if_icmpeq].argnum = 2;
        instruc[if_icmpeq].opnum = 2;

        instruc[if_icmpne].name = string("if_icmpne");
        instruc[if_icmpne].opcode = if_icmpne;
        instruc[if_icmpne].argnum = 2;
        instruc[if_icmpne].opnum = 2;

        instruc[if_icmplt].name = string("if_icmplt");
        instruc[if_icmplt].opcode = if_icmplt;
        instruc[if_icmplt].argnum = 2;
        instruc[if_icmplt].opnum = 2;

        instruc[if_icmpge].name = string("if_icmpge");
        instruc[if_icmpge].opcode = if_icmpge;
        instruc[if_icmpge].argnum = 2;
        instruc[if_icmpge].opnum = 2;

        instruc[if_icmpgt].name = string("if_icmpgt");
        instruc[if_icmpgt].opcode = if_icmpgt;
        instruc[if_icmpgt].argnum = 2;
        instruc[if_icmpgt].opnum = 2;

        instruc[if_icmple].name = string("if_icmple");
        instruc[if_icmple].opcode = if_icmple;
        instruc[if_icmple].argnum = 2;
        instruc[if_icmple].opnum = 2;

        instruc[if_acmpeq].name = string("if_acmpeq");
        instruc[if_acmpeq].opcode = if_acmpeq;
        instruc[if_acmpeq].argnum = 2;
        instruc[if_acmpeq].opnum = 2;

        instruc[if_acmpne].name = string("if_acmpne");
        instruc[if_acmpne].opcode = if_acmpne;
        instruc[if_acmpne].argnum = 2;
        instruc[if_acmpne].opnum = 2;

        instruc[inst_goto].name = string("inst_goto");
        instruc[inst_goto].opcode = inst_goto;
        instruc[inst_goto].argnum = 2;
        instruc[inst_goto].opnum = 0;

        instruc[jsr].name = string("jsr");
        instruc[jsr].opcode = jsr;
        instruc[jsr].argnum = 2;
        instruc[jsr].opnum = 0;

        instruc[ret].name = string("ret");
        instruc[ret].opcode = ret;
        instruc[ret].argnum = 1;
        instruc[ret].opnum = 0;

        instruc[tableswitch].name = string("tableswitch");
        instruc[tableswitch].opcode = tableswitch;
        instruc[tableswitch].argnum = 0;
        instruc[tableswitch].opnum = 1;

        instruc[lookupswitch].name = string("lookupswitch");
        instruc[lookupswitch].opcode = lookupswitch;
        instruc[lookupswitch].argnum = 1;
        instruc[lookupswitch].opnum = 1;

        instruc[ireturn].name = string("ireturn");
        instruc[ireturn].opcode = ireturn;
        instruc[ireturn].argnum = 0;
        instruc[ireturn].opnum = 1;

        instruc[lreturn].name = string("lreturn");
        instruc[lreturn].opcode = lreturn;
        instruc[lreturn].argnum = 0;
        instruc[lreturn].opnum = 1;

        instruc[freturn].name = string("freturn");
        instruc[freturn].opcode = freturn;
        instruc[freturn].argnum = 0;
        instruc[freturn].opnum = 1;

        instruc[dreturn].name = string("dreturn");
        instruc[dreturn].opcode = dreturn;
        instruc[dreturn].argnum = 0;
        instruc[dreturn].opnum = 1;

        instruc[areturn].name = string("areturn");
        instruc[areturn].opcode = areturn;
        instruc[areturn].argnum = 0;
        instruc[areturn].opnum = 1;

        instruc[inst_return].name = string("inst_return");
        instruc[inst_return].opcode = inst_return;
        instruc[inst_return].argnum = 0;
        instruc[inst_return].opnum = 1;

        instruc[getstatic].name = string("getstatic");
        instruc[getstatic].opcode = getstatic;
        instruc[getstatic].argnum = 2;
        instruc[getstatic].opnum = 0;

        instruc[putstatic].name = string("putstatic");
        instruc[putstatic].opcode = putstatic;
        instruc[putstatic].argnum = 2;
        instruc[putstatic].opnum = 0;

        instruc[getfield].name = string("getfield");
        instruc[getfield].opcode = getfield;
        instruc[getfield].argnum = 2;
        instruc[getfield].opnum = 1;

        instruc[putfield].name = string("putfield");
        instruc[putfield].opcode = putfield;
        instruc[putfield].argnum = 2;
        instruc[putfield].opnum = 2;

        instruc[invokevirtual].name = string("invokevirtual");
        instruc[invokevirtual].opcode = invokevirtual;
        instruc[invokevirtual].argnum = 2;
        instruc[invokevirtual].opnum = -1;

        instruc[invokespecial].name = string("invokespecial");
        instruc[invokespecial].opcode = invokespecial;
        instruc[invokespecial].argnum = 2;
        instruc[invokespecial].opnum = -1;

        instruc[invokestatic].name = string("invokestatic");
        instruc[invokestatic].opcode = invokestatic;
        instruc[invokestatic].argnum = 2;
        instruc[invokestatic].opnum = -1;

        instruc[invokeinterface].name = string("invokeinterface");
        instruc[invokeinterface].opcode = invokeinterface;
        instruc[invokeinterface].argnum = 4;
        instruc[invokeinterface].opnum = -1;

        instruc[inst_new].name = string("inst_new");
        instruc[inst_new].opcode = inst_new;
        instruc[inst_new].argnum = 2;
        instruc[inst_new].opnum = 0;

        instruc[newarray].name = string("newarray");
        instruc[newarray].opcode = newarray;
        instruc[newarray].argnum = 1;
        instruc[newarray].opnum = 1;

        instruc[anewarray].name = string("anewarray");
        instruc[anewarray].opcode = anewarray;
        instruc[anewarray].argnum = 2;
        instruc[anewarray].opnum = 1;

        instruc[arraylength].name = string("arraylength");
        instruc[arraylength].opcode = arraylength;
        instruc[arraylength].argnum = 0;
        instruc[arraylength].opnum = 1;

        instruc[athrow].name = string("athrow");
        instruc[athrow].opcode = athrow;
        instruc[athrow].argnum = 0;
        instruc[athrow].opnum = 1;

        instruc[checkcast].name = string("checkcast");
        instruc[checkcast].opcode = checkcast;
        instruc[checkcast].argnum = 2;
        instruc[checkcast].opnum = 1;

        instruc[instanceof].name = string("instanceof");
        instruc[instanceof].opcode = instanceof ;
        instruc[instanceof].argnum = 2;
        instruc[instanceof].opnum = 1;

        instruc[monitorenter].name = string("monitorenter");
        instruc[monitorenter].opcode = monitorenter;
        instruc[monitorenter].argnum = 0;
        instruc[monitorenter].opnum = 1;

        instruc[wide].name = string("wide");
        instruc[wide].opcode = wide;
        instruc[wide].argnum = 0;
        instruc[wide].opnum = 0;

        instruc[multianewarray].name = string("multianewarray");
        instruc[multianewarray].opcode = multianewarray;
        instruc[multianewarray].argnum = 3;
        instruc[multianewarray].opnum = -1;

        instruc[ifnull].name = string("ifnull");
        instruc[ifnull].opcode = ifnull;
        instruc[ifnull].argnum = 2;
        instruc[ifnull].opnum = 1;

        instruc[ifnonnull].name = string("ifnonnull");
        instruc[ifnonnull].opcode = ifnonnull;
        instruc[ifnonnull].argnum = 2;
        instruc[ifnonnull].opnum = 1;

        instruc[goto_w].name = string("goto_w");
        instruc[goto_w].opcode = goto_w;
        instruc[goto_w].argnum = 4;
        instruc[goto_w].opnum = 0;

        instruc[jsr_w].name = string("jrs_w");
        instruc[jsr_w].opcode = jsr_w;
        instruc[jsr_w].argnum = 4;
        instruc[jsr_w].opnum = 0;
default:
              instruc[i].name = string("undefined");
              instruc[i].opcode = 255;
              instruc[i].argnum = -1;
              instruc[i].opnum = -1;
              break;
    //   }
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
