#ifndef opStack_h
#define opStack_h

#include "./definitions.h"
#include <vector>

class OpStack {
  public:
    i4 operand;  //< Caso o operando seja um valor, eh armazenado nesta variavel
    void *operand_ref;  //< Caso o operando seja uma referencia, eh armazenada nesta variavel
    u1 operand_type;    //< Tipo do operando armazenado na estrutura. A lista de opcoes esta definida na enumeracao \c tipos_operandos
  
  private:
    std::vector<OpStack> InserirInicio_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType);
    std::vector<OpStack> InserirFim_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType);
    std::vector<OpStack> RemoverInicio_operandos(std::vector<OpStack> lis);
    std::vector<OpStack> RemoverFim_operandos(std::vector<OpStack> lis);
  
    void ImprimirOpStack(std::vector<OpStack> lis);
    void LiberarOpStack(std::vector<OpStack> lis);

    std::vector<OpStack> BuscarElemento_operandos(std::vector<OpStack> lis, i4 op, u1 opType);
    OpStack BuscarPosicao_operandos(std::vector<OpStack> lis, int posicao);
    std::vector<OpStack> InserirPosicao_operandos(std::vector<OpStack> lis, i4 op, u1 opType, int posicao);
    std::vector<OpStack> RemoverPosicao_operandos(std::vector<OpStack> lis, int posicao);
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