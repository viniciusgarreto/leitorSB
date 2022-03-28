#include "./definitions.h"

class OpQueue {
  public:
    i4 operand;  //< Caso o operando seja um valor, eh armazenado nesta variavel

    void *operand_ref;  //< Caso o operando seja uma referencia, eh armazenada
                        // nesta variavel
    u1 operand_type;    //< Tipo do operando armazenado na estrutura. A lista de
                        // opcoes esta definida na enumeracao \c tipos_operandos
    struct OpQueue *prox; /**< Ponteiro de acesso ao proximo no da lista*/
    struct OpQueue *ant;  /**< Ponteiro de acesso ao no anterior da lista */
  private:
    OpQueue *CriarOpQueue();
    OpQueue *InserirInicio_operandos();
    OpQueue *InserirFim_operandos();
    OpQueue *RemoverInicio_operandos(OpQueue *lis);
    OpQueue *RemoverFim_operandos(OpQueue *lis);
    void ImprimirOpQueue(OpQueue *lis);
    void LiberarOpQueue(OpQueue *lis);

    OpQueue *RemoverElemento_operandos(OpQueue *lis, i4 operando,
                                       u1 tipo_operando);

    OpQueue *BuscarElemento_operandos(OpQueue *lis, i4 operando,
                                      u1 tipo_operando);

    OpQueue *BuscarPosicao_operandos(OpQueue *lis, int posicao);

    OpQueue *InserirPosicao_operandos(OpQueue *lis, i4 operando,
                                      u1 tipo_operando, int posicao);

    OpQueue *RemoverPosicao_operandos(OpQueue *lis, int posicao);
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