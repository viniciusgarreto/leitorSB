#include <vector>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "../headers/definitions.h"
#include "../headers/OpQueue.h"

std::vector<OpQueue> InserirInicio_operandos(std::vector<OpQueue> lis, i4 op, void *ref, u1 opType){
  OpQueue atual;
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

std::vector<OpQueue> InserirFim_operandos(std::vector<OpQueue> lis, i4 op, void *ref, u1 opType){
  OpQueue atual;
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

std::vector<OpQueue> RemoverInicio_operandos(std::vector<OpQueue> lis){
  lis.erase(lis.begin());
  return lis;
}

std::vector<OpQueue> RemoverFim_operandos(std::vector<OpQueue> lis){
  lis.erase(lis.end());
  return lis;
}

void ImprimirOpQueue(std::vector<OpQueue> lis){
  for(int i = 0; i < lis.size(); i++){
    if(lis[i].operand_type <= 8){
      printf("Operando: 0x%08x\n\n", lis[i].operand_type);
    } else {
      switch(lis[i].operand_type){
				case RETURN_ADDRESS_OP:
					printf("Operando: %s\n\n",(char*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_BOOLEAN_OP:
					printf("[Z@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_CHAR_OP:
					printf("Operando: %s\n\n",(char*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_FLOAT_OP:
					printf("[F@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_DOUBLE_OP:
					printf("[D@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_BYTE_OP:
					printf("[B@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_SHORT_OP:
					printf("[S@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_INT_OP:
					printf("[I@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_ARRAY_LONG_OP:
					printf("[J@%p\n",(u4*) lis[i].operand_ref);
				  break;
				case REFERENCE_STRING_OP:
					printf("String: %s\n", (char *) lis[i].operand_ref);
				  break;
				case REFERENCE_OP:
					printf("Operando: 0x%p\n\n", (u4*) lis[i].operand_ref);
				  break;
			}
    }
  }
}

void LiberarOpQueue(std::vector<OpQueue> lis);

std::vector<OpQueue> BuscarElemento_operandos(std::vector<OpQueue> lis, i4 op, u1 opType);

OpQueue BuscarPosicao_operandos(std::vector<OpQueue> lis, int posicao){
  return lis[posicao];
};

std::vector<OpQueue> InserirPosicao_operandos(std::vector<OpQueue> lis, i4 op, u1 opType, int posicao){
  OpQueue atual;
  atual.operand = op;
  atual.operand_ref = NULL; 
  atual.operand_type = opType;

  lis.insert(lis.begin()+posicao, atual);
}

std::vector<OpQueue> RemoverPosicao_operandos(std::vector<OpQueue> lis, int posicao){
  lis.erase(lis.begin()+posicao);
}