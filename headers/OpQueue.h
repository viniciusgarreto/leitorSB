#ifndef opQueue_h
#define opQueue_h

#include "./definitions.h"
#include <vector>

class OpQueue {
  public:
    i4 operand;  //< Caso o operando seja um valor, eh armazenado nesta variavel
    void *operand_ref;  //< Caso o operando seja uma referencia, eh armazenada nesta variavel
    u1 operand_type;    //< Tipo do operando armazenado na estrutura. A lista de opcoes esta definida na enumeracao \c tipos_operandos
  
  private:
    std::vector<OpQueue> InserirInicio_operandos(std::vector<OpQueue> lis, i4 op, void *ref, u1 opType);
    std::vector<OpQueue> InserirFim_operandos(std::vector<OpQueue> lis, i4 op, void *ref, u1 opType);
    std::vector<OpQueue> RemoverInicio_operandos(std::vector<OpQueue> lis);
    std::vector<OpQueue> RemoverFim_operandos(std::vector<OpQueue> lis);
  
    void ImprimirOpQueue(std::vector<OpQueue> lis);
    void LiberarOpQueue(std::vector<OpQueue> lis);

    std::vector<OpQueue> BuscarElemento_operandos(std::vector<OpQueue> lis, i4 op, u1 opType);
    OpQueue BuscarPosicao_operandos(std::vector<OpQueue> lis, int posicao);
    std::vector<OpQueue> InserirPosicao_operandos(std::vector<OpQueue> lis, i4 op, u1 opType, int posicao);
    std::vector<OpQueue> RemoverPosicao_operandos(std::vector<OpQueue> lis, int posicao);
};

enum tipos_operandos {
    BOOLEAN_OP = 1,
    BYTE_OP,
    CHAR_OP,
    SHORT_OP,
    INTEGER_OP,
    FLOAT_OP,
    LONG_OP,
    DOUBLE_OP,
    RETURN_ADDRESS_OP,
    REFERENCE_OP,
    REFERENCE_ARRAY_BOOLEAN_OP,
    REFERENCE_ARRAY_CHAR_OP,
    REFERENCE_ARRAY_FLOAT_OP,
    REFERENCE_ARRAY_DOUBLE_OP,
    REFERENCE_ARRAY_BYTE_OP,
    REFERENCE_ARRAY_SHORT_OP,
    REFERENCE_ARRAY_INT_OP,
    REFERENCE_ARRAY_LONG_OP,
    REFERENCE_STRING_OP,
};

#endif