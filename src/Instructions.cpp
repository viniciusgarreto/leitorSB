#include "../headers/Instructions.h"

#include <stdlib.h>
#include <string.h>

Instruction** Instruction::instruc = nullptr;
bool Instruction::isBuilt = false;
int Instruction::EnumCheck = 200;


// constructor
Instruction::Instruction(string name, int opcode, int argnum, int opnum) {
    this->name = name;
    this->opcode = opcode;
    this->argnum = argnum;
    this->opnum = opnum;
    this->instruct_pc = argnum + 1;
}

// destructor
Instruction::~Instruction() {
}

// get instruction by opcode
Instruction& Instruction::getInstruction(int opcode) {
    if (!Instruction::isBuilt) Instruction::setInstructions();
    return *Instruction::instruc[opcode];
}

void Instruction::setInstructions() {
    Instruction::isBuilt = true;
    
    Instruction::instruc = (Instruction**)malloc(Instruction::EnumCheck * sizeof(Instruction*));

    instruc[nop] = new Instruction(string("nop"),  nop,  0 , 0);
    instruc[aconst_null] = new Instruction(string("aconst_null"), aconst_null, 0, 0);
    instruc[iconst_m1] = new Instruction(string("iconst_m1"), iconst_m1, 0, 0);
    instruc[iconst_0] = new Instruction(string("iconst_0"), iconst_0, 0, 0);
    instruc[iconst_1] = new Instruction(string("iconst_1"), iconst_1, 0, 0);
    instruc[iconst_2] = new Instruction(string("iconst_2"), iconst_2, 0, 0);
    instruc[iconst_3] = new Instruction(string("iconst_3"), iconst_3, 0, 0);
    instruc[iconst_4] = new Instruction(string("iconst_4"), iconst_4, 0, 0);
    instruc[iconst_5] = new Instruction(string("iconst_5"), iconst_5, 0, 0);
    instruc[lconst_0] = new Instruction(string("lconst_0"), lconst_0, 0, 0);
    instruc[lconst_1] = new Instruction(string("lconst_1"), lconst_1, 0, 0);
    instruc[fconst_0] = new Instruction(string("fconst_0"), fconst_0, 0, 0);
    instruc[fconst_1] = new Instruction(string("fconst_1"), fconst_1, 0, 0);
    instruc[fconst_2] = new Instruction(string("fconst_2"), fconst_2, 0, 0);
    instruc[dconst_0] = new Instruction(string("dconst_0"), dconst_0, 0, 0);
    instruc[dconst_1] = new Instruction(string("dconst_1"), dconst_1, 0, 0);
    instruc[bipush] = new Instruction(string("bipush"), bipush, 1, 0);
    instruc[sipush] = new Instruction(string("sipush"), sipush, 2, 0);
    instruc[ldc] = new Instruction(string("ldc"), ldc, 1, 0);
    instruc[ldc_w] = new Instruction(string("ldc_w"), ldc_w, 2, 0);
    instruc[ldc2_w] = new Instruction(string("ldc2_w"), ldc2_w, 2, 0);
    instruc[iload] = new Instruction(string("iload"), iload, 1, 0);
    instruc[lload] = new Instruction(string("lload"), lload, 1, 0);
    instruc[fload] = new Instruction(string("fload"), fload, 1, 0);
    instruc[dload] = new Instruction(string("dload"), dload, 1, 0);
    instruc[aload] = new Instruction(string("aload"), aload, 1, 0);
    instruc[iload_0] = new Instruction(string("iload_0"), iload_0, 0, 0);
    instruc[iload_1] = new Instruction(string("iload_1"), iload_1, 0, 0);
    instruc[iload_2] = new Instruction(string("iload_2"), iload_2, 0, 0);
    instruc[iload_3] = new Instruction(string("iload_3"), iload_3, 0, 0);
    instruc[lload_0] = new Instruction(string("lload_0"), lload_0, 0, 0);
    instruc[lload_1] = new Instruction(string("lload_1"), lload_1, 0, 0);
    instruc[lload_2] = new Instruction(string("lload_2"), lload_2, 0, 0);
    instruc[lload_3] = new Instruction(string("lload_3"), lload_3, 0, 0);
    instruc[fload_0] = new Instruction(string("fload_0"), fload_0, 0, 0);
    instruc[fload_1] = new Instruction(string("fload_1"), fload_1, 0, 0);
    instruc[fload_2] = new Instruction(string("fload_2"), fload_2, 0, 0);
    instruc[fload_3] = new Instruction(string("fload_3"), fload_3, 0, 0);
    instruc[dload_0] = new Instruction(string("dload_0"), dload_0, 0, 0);
    instruc[dload_1] = new Instruction(string("dload_1"), dload_1, 0, 0);
    instruc[dload_2] = new Instruction(string("dload_2"), dload_2, 0, 0);
    instruc[dload_3] = new Instruction(string("dload_3"), dload_3, 0, 0);
    instruc[aload_0] = new Instruction(string("aload_0"), aload_0, 0, 0);
    instruc[aload_1] = new Instruction(string("aload_1"), aload_1, 0, 0);
    instruc[aload_2] = new Instruction(string("aload_2"), aload_2, 0, 0);
    instruc[aload_3] = new Instruction(string("aload_3"), aload_3, 0, 0);
    instruc[iaload] = new Instruction(string("iaload"), iaload, 0, 2);
    instruc[laload] = new Instruction(string("laload"), laload, 0, 2);
    instruc[faload] = new Instruction(string("faload"), faload, 0, 2);
    instruc[daload] = new Instruction(string("daload"), daload, 0, 2);
    instruc[aaload] = new Instruction(string("aaload"), aaload, 0, 2);
    instruc[baload] = new Instruction(string("baload"), baload, 0, 2);
    instruc[caload] = new Instruction(string("caload"), caload, 0, 2);
    instruc[saload] = new Instruction(string("saload"), saload, 0, 2);
    instruc[istore] = new Instruction(string("istore"), istore, 1, 1);
    instruc[lstore] = new Instruction(string("lstore"), lstore, 1, 1);
    instruc[fstore] = new Instruction(string("fstore"), fstore, 1, 1);
    instruc[dstore] = new Instruction(string("dstore"), dstore, 1, 1);
    instruc[astore] = new Instruction(string("astore"), astore, 1, 1);
    instruc[istore_0] = new Instruction(string("istore_0"), istore_0, 0, 1);
    instruc[istore_1] = new Instruction(string("istore_1"), istore_1, 0, 1);
    instruc[istore_2] = new Instruction(string("istore_2"), istore_2, 0, 1);
    instruc[istore_3] = new Instruction(string("istore_3"), istore_3, 0, 1);
    instruc[lstore_0] = new Instruction(string("lstore_0"), lstore_0, 0, 1);
    instruc[lstore_1] = new Instruction(string("lstore_1"), lstore_1, 0, 1);
    instruc[lstore_2] = new Instruction(string("lstore_2"), lstore_2, 0, 1);
    instruc[lstore_3] = new Instruction(string("lstore_3"), lstore_3, 0, 1);
    instruc[fstore_0] = new Instruction(string("fstore_0"), fstore_0, 0, 1);
    instruc[fstore_1] = new Instruction(string("fstore_1"), fstore_1, 0, 1);
    instruc[fstore_2] = new Instruction(string("fstore_2"), fstore_2, 0, 1);
    instruc[fstore_3] = new Instruction(string("fstore_3"), fstore_3, 0, 1);
    instruc[dstore_0] = new Instruction(string("dstore_0"), dstore_0, 0, 1);
    instruc[dstore_1] = new Instruction(string("dstore_1"), dstore_1, 0, 1);
    instruc[dstore_2] = new Instruction(string("dstore_2"), dstore_2, 0, 1);
    instruc[dstore_3] = new Instruction(string("dstore_3"), dstore_3, 0, 1);
    instruc[astore_0] = new Instruction(string("astore_0"), astore_0, 0, 1);
    instruc[astore_1] = new Instruction(string("astore_1"), astore_1, 0, 1);
    instruc[astore_2] = new Instruction(string("astore_2"), astore_2, 0, 1);
    instruc[astore_3] = new Instruction(string("astore_3"), astore_3, 0, 1);
    instruc[iastore] = new Instruction(string("iastore"), iastore, 0, 3);
    instruc[lastore] = new Instruction(string("lastore"), lastore, 0, 3);
    instruc[fastore] = new Instruction(string("fastore"), fastore, 0, 3);
    instruc[dastore] = new Instruction(string("dastore"), dastore, 0, 3);
    instruc[aastore] = new Instruction(string("aastore"), aastore, 0, 3);
    instruc[bastore] = new Instruction(string("bastore"), bastore, 0, 3);
    instruc[castore] = new Instruction(string("castore"), castore, 0, 3);
    instruc[sastore] = new Instruction(string("sastore"), sastore, 0, 3);
    instruc[pop] = new Instruction(string("pop"), pop, 0, 1);
    instruc[pop2] = new Instruction(string("pop2"), pop2, 0, 1);
    instruc[dup] = new Instruction(string("dup"), dup, 0, 1);
    instruc[dup_x1] = new Instruction(string("dup_x1"), dup_x1, 0, 2);
    instruc[dup_x2] = new Instruction(string("dup_x2"), dup_x2, 0, 3);
    instruc[dup2] = new Instruction(string("dup2"), dup2, 0, 2);
    instruc[dup2_x1] = new Instruction(string("dup2_x1"), dup2_x1, 0, 3);
    instruc[dup2_x2] = new Instruction(string("dup2_x2"), dup2_x2, 0, 4);
    instruc[swapSwap] = new Instruction(string("swap"), swapSwap, 0, 2);
    instruc[iadd] = new Instruction(string("iadd"), iadd, 0, 2);
    instruc[ladd] = new Instruction(string("ladd"), ladd, 0, 2);
    instruc[fadd] = new Instruction(string("fadd"), fadd, 0, 2);
    instruc[dadd] = new Instruction(string("dadd"), dadd, 0, 2);
    instruc[isub] = new Instruction(string("isub"), isub, 0, 2);
    instruc[lsub] = new Instruction(string("lsub"), lsub, 0, 2);
    instruc[fsub] = new Instruction(string("fsub"), fsub, 0, 2);
    instruc[dsub] = new Instruction(string("dsub"), dsub, 0, 2);
    instruc[imul] = new Instruction(string("imul"), imul, 0, 2);
    instruc[fmul] = new Instruction(string("fmul"), fmul, 0, 2);
    instruc[dmul] = new Instruction(string("dmul"), dmul, 0, 2);
    instruc[idiv] = new Instruction(string("idiv"), idiv, 0, 2);
    instruc[inst_ldiv] = new Instruction(string("inst_ldiv"), inst_ldiv, 0, 2);
    instruc[fdiv] = new Instruction(string("fdiv"), fdiv, 0, 2);
    instruc[ddiv] = new Instruction(string("ddiv"), ddiv, 0, 2);
    instruc[irem] = new Instruction(string("irem"), irem, 0, 2);
    instruc[lrem] = new Instruction(string("lrem"), lrem, 0, 2);
    instruc[frem] = new Instruction(string("frem"), frem, 0, 2);
    instruc[inst_drem] = new Instruction(string("inst_drem"), inst_drem, 0, 2);
    instruc[ineg] = new Instruction(string("ineg"), ineg, 0, 1);
    instruc[lneg] = new Instruction(string("lneg"), lneg, 0, 1);
    instruc[fneg] = new Instruction(string("fneg"), fneg, 0, 1);
    instruc[dneg] = new Instruction(string("dneg"), dneg, 0, 1);
    instruc[ishl] = new Instruction(string("ishl"), ishl, 0, 2);
    instruc[lshl] = new Instruction(string("lshl"), lshl, 0, 2);
    instruc[ishr] = new Instruction(string("ishr"), ishr, 0, 2);
    instruc[lshr] = new Instruction(string("lshr"), lshr, 0, 2);
    instruc[iushr] = new Instruction(string("iushr"), iushr, 0, 2);
    instruc[lushr] = new Instruction(string("lushr"), lushr, 0, 2);
    instruc[iand] = new Instruction(string("iand"), iand, 0, 2);
    instruc[ior] = new Instruction(string("ior"), ior, 0, 2);
    instruc[lor] = new Instruction(string("lor"), lor, 0, 2);
    instruc[ixor] = new Instruction(string("ixor"), ixor, 0, 2);
    instruc[lxor] = new Instruction(string("lxor"), lxor, 0, 2);
    instruc[iinc] = new Instruction(string("iinc"), iinc, 2, 0);
    instruc[i2l] = new Instruction(string("i2l"), i2l, 0, 1);
    instruc[i2f] = new Instruction(string("i2f"), i2f, 0, 1);
    instruc[i2d] = new Instruction(string("i2d"), i2d, 0, 1);
    instruc[l2i] = new Instruction(string("l2i"), l2i, 0, 1);
    instruc[l2f] = new Instruction(string("l2f"), l2f, 0, 1);
    instruc[l2d] = new Instruction(string("l2d"), l2d, 0, 1);
    instruc[f2i] = new Instruction(string("f2i"), f2i, 0, 1);
    instruc[f2l] = new Instruction(string("f2l"), f2l, 0, 1);
    instruc[f2d] = new Instruction(string("f2d"), f2d, 0, 1);
    instruc[d2i] = new Instruction(string("d2i"), d2i, 0, 1);
    instruc[d2l] = new Instruction(string("d2l"), d2l, 0, 1);
    instruc[d2f] = new Instruction(string("d2f"), d2f, 0, 1);
    instruc[i2b] = new Instruction(string("i2b"), i2b, 0, 1);
    instruc[i2c] = new Instruction(string("i2c"), i2c, 0, 1);
    instruc[i2s] = new Instruction(string("i2s"), i2s, 0, 1);
    instruc[lcmp] = new Instruction(string("lcmp"), lcmp, 0, 2);
    instruc[fcmpl] = new Instruction(string("fcmpl"), fcmpl, 0, 2);
    instruc[fcmpg] = new Instruction(string("fcmpg"), fcmpg, 0, 2);
    instruc[dcmpl] = new Instruction(string("dcmpl"), dcmpl, 0, 2);
    instruc[dcmpg] = new Instruction(string("dcmpg"), dcmpg, 0, 2);
    instruc[ifeq] = new Instruction(string("ifeq"), ifeq, 2, 1);
    instruc[ifne] = new Instruction(string("ifne"), ifne, 2, 1);
    instruc[iflt] = new Instruction(string("iflt"), iflt, 2, 1);
    instruc[ifge] = new Instruction(string("ifge"), ifge, 2, 1);
    instruc[ifgt] = new Instruction(string("ifgt"), ifgt, 2, 1);
    instruc[ifle] = new Instruction(string("ifle"), ifle, 2, 1);
    instruc[if_icmpeq] = new Instruction(string("if_icmpeq"), if_icmpeq, 2, 2);
    instruc[if_icmpne] = new Instruction(string("if_icmpne"), if_icmpne, 2, 2);
    instruc[if_icmplt] = new Instruction(string("if_icmplt"), if_icmplt, 2, 2);
    instruc[if_icmpge] = new Instruction(string("if_icmpge"), if_icmpge, 2, 2);
    instruc[if_icmpgt] = new Instruction(string("if_icmpgt"), if_icmpgt, 2, 2);
    instruc[if_icmple] = new Instruction(string("if_icmple"), if_icmple, 2, 2);
    instruc[if_acmpeq] = new Instruction(string("if_acmpeq"), if_acmpeq, 2, 2);
    instruc[if_acmpne] = new Instruction(string("if_acmpne"), if_acmpne, 2, 2);
    instruc[inst_goto] = new Instruction(string("inst_goto"), inst_goto, 2, 0);
    instruc[jsr] = new Instruction(string("jsr"), jsr, 2, 0);
    instruc[ret] = new Instruction(string("ret"), ret, 1, 0);
    instruc[tableswitch] = new Instruction(string("tableswitch"), tableswitch, 0, 1);
    instruc[lookupswitch] = new Instruction(string("lookupswitch"), lookupswitch, 1, 1);
    instruc[ireturn] = new Instruction(string("ireturn"), ireturn, 0, 1);
    instruc[lreturn] = new Instruction(string("lreturn"), lreturn, 0, 1);
    instruc[freturn] = new Instruction(string("freturn"), freturn, 0, 1);
    instruc[dreturn] = new Instruction(string("dreturn"), dreturn, 0, 1);
    instruc[areturn] = new Instruction(string("areturn"), areturn, 0, 1);
    instruc[inst_return] = new Instruction(string("inst_return"), inst_return, 0, 1);
    instruc[getstatic] = new Instruction(string("getstatic"), getstatic, 2, 0);
    instruc[putstatic] = new Instruction(string("putstatic"), putstatic, 2, 0);
    instruc[getfield] = new Instruction(string("getfield"), getfield, 2, 1);
    instruc[putfield] = new Instruction(string("putfield"), putfield, 2, 2);
    instruc[invokevirtual] = new Instruction(string("invokevirtual"), invokevirtual, 2, -1);
    instruc[invokespecial] = new Instruction(string("invokespecial"), invokespecial, 2, -1);
    instruc[invokestatic] = new Instruction(string("invokestatic"), invokestatic, 2, -1);
    instruc[invokeinterface] = new Instruction(string("invokeinterface"), invokeinterface, 4, -1);
    instruc[inst_new] = new Instruction(string("inst_new"), inst_new, 2, 0);
    instruc[newarray] = new Instruction(string("newarray"), newarray, 1, 1);
    instruc[anewarray] = new Instruction(string("anewarray"), anewarray, 2, 1);
    instruc[arraylength] = new Instruction(string("arraylength"), arraylength, 0, 1);
    instruc[athrow] = new Instruction(string("athrow"), athrow, 0, 1);
    instruc[checkcast] = new Instruction(string("checkcast"), checkcast, 2, 1);
    instruc[instanceof] = new Instruction(string("instanceof"), instanceof, 2, 1);
    instruc[monitorenter] = new Instruction(string("monitorenter"), monitorenter, 0, 1);
    instruc[wide] = new Instruction(string("wide"), wide, 0, 0);
    instruc[multianewarray] = new Instruction(string("multianewarray"), multianewarray, 3, -1);
    instruc[ifnull] = new Instruction(string("ifnull"), ifnull, 2, 1);
    instruc[ifnonnull] = new Instruction(string("ifnonnull"), ifnonnull, 2, 1);
    instruc[goto_w] = new Instruction(string("goto_w"), goto_w, 4, 0);
    instruc[jsr_w] = new Instruction(string("jrs_w"),jsr_w,4,0);
}

ostream& operator<<(ostream& out, const Instruction& cf) {
    return cf.print(out);
}

ostream& Instruction::print(ostream& output) const {
    output << endl;
    output << "------------- INSTRUCTIONS -------------" << endl;
    output << endl;

    for (int i = 0; i <= 200; i++) {
        output << "Name: " << instruc[i]->name << endl;
        output << "Opcode: " << instruc[i]->opcode << endl;
        output << "Argum: " << instruc[i]->argnum << endl;
        output << "Opnum: " << instruc[i]->opnum << endl;
        output << "Instruct_pc: " << instruc[i]->instruct_pc << endl;
    }

    return output;
}
