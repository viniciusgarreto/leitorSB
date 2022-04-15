#include <vector>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "../headers/definitions.h"
#include "../headers/OpStack.h"


std::vector<OpStack> InserirInicio_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType){
  OpStack atual;
  if(opType <= 8){
    atual.operand = op;
    atual.operand_ref = NULL; 
  } else {
    atual.operand = -INT_MAX;
    atual.operand_ref = ref;
  }
  atual.operand_type = opType;

  lis.insert(lis.begin(), atual);
  
  return lis;
}

std::vector<OpStack> InserirFim_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType){
  OpStack atual;
  if(opType <= 8){
    atual.operand = op;
    atual.operand_ref = NULL; 
  } else {
    atual.operand = -INT_MAX;
    atual.operand_ref = ref;
  }
  atual.operand_type = opType;
  
  lis.insert(lis.end(), atual);
  
  return lis;
}

std::vector<OpStack> RemoverInicio_operandos(std::vector<OpStack> lis){
  lis.erase(lis.begin());
  return lis;
}

std::vector<OpStack> RemoverFim_operandos(std::vector<OpStack> lis){
  lis.erase(lis.end());
  return lis;
}

void ImprimirOpStack(std::vector<OpStack> opList){
  for(auto op : opList){
    if(op.operand_type <= 8){
      printf("Operando: 0x%08x\n\n", op.operand_type);
    } else {
      switch(op.operand_type){
				case RETURN_ADDRESS_OP:
					printf("Operando: %s\n\n",(char*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_BOOLEAN_OP:
					printf("[Z@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_CHAR_OP:
					printf("Operando: %s\n\n",(char*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_FLOAT_OP:
					printf("[F@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_DOUBLE_OP:
					printf("[D@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_BYTE_OP:
					printf("[B@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_SHORT_OP:
					printf("[S@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_INT_OP:
					printf("[I@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_ARRAY_LONG_OP:
					printf("[J@%p\n",(u4*) op.operand_ref);
				  break;
				case REFERENCE_STRING_OP:
					printf("String: %s\n", (char *) op.operand_ref);
				  break;
				case REFERENCE_OP:
					printf("Operando: 0x%p\n\n", (u4*) op.operand_ref);
				  break;
			}
    }
  }
}

void LiberarOpStack(std::vector<OpStack> lis);

std::vector<OpStack> BuscarElemento_operandos(std::vector<OpStack> lis, i4 op, u1 opType);

OpStack BuscarPosicao_operandos(std::vector<OpStack> lis, int posicao){
  return lis[posicao];
};

std::vector<OpStack> InserirPosicao_operandos(std::vector<OpStack> lis, i4 op, u1 opType, int posicao){
  OpStack atual;
  atual.operand = op;
  atual.operand_ref = NULL; 
  atual.operand_type = opType;

  lis.insert(lis.begin()+posicao, atual);
  return lis;
}

std::vector<OpStack> RemoverPosicao_operandos(std::vector<OpStack> lis, int posicao){
  lis.erase(lis.begin()+posicao);
  return lis;
}
