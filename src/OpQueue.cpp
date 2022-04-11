#include "../headers/OpQueue.h"
#include <stdlib.h>
#include <string.h>


OpQueue *CriarOpQueue(){
  return NULL;
}

OpQueue *InserirInicio_operandos(){
  OpQueue *newQueue = (OpQueue*) malloc(sizeof(OpQueue));
}
OpQueue *InserirFim_operandos();
OpQueue *RemoverInicio_operandos(OpQueue *lis);
OpQueue *RemoverFim_operandos(OpQueue *lis);
void ImprimirOpQueue(OpQueue *lis);
void LiberarOpQueue(OpQueue *lis);

OpQueue *RemoverElemento_operandos(OpQueue *lis, i4 operando, u1 tipo_operando);

OpQueue *BuscarElemento_operandos(OpQueue *lis, i4 operando, u1 tipo_operando);

OpQueue *BuscarPosicao_operandos(OpQueue *lis, int posicao);

OpQueue *InserirPosicao_operandos(OpQueue *lis, i4 operando, u1 tipo_operando, int posicao);

OpQueue *RemoverPosicao_operandos(OpQueue *lis, int posicao);
