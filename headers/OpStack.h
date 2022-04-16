/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

#ifndef opStack_h
#define opStack_h

#include "./definitions.h"
#include <vector>

/**
* @file OpStack.h
* @brief Define a Pilha de Operandos e os tipos de operandos
*/
class OpStack {
  public:
    /// Caso o operando seja um valor, eh armazenado nesta variavel
    i4 operand;  
    /// Caso o operando seja uma referencia, eh armazenada nesta variavel
    void *operand_ref;  
    /// Tipo do operando armazenado na estrutura. A lista de opcoes esta definida na enumeracao \c tipos_operandos
    u1 operand_type;    
  
  private:
    /**
     * @brief Insere operando no inicio da lista
     * @param lis - Lista
     * @param op - Operando
     * @param ref - Referência
     * @param opType - Tipo de operando
     */
    std::vector<OpStack> InserirInicio_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType);
    /**
     * @brief Insere operando no final da lista
     * @param lis - Lista
     * @param op - Operando
     * @param ref - Referência
     * @param opType - Tipo de operando
     */
    std::vector<OpStack> InserirFim_operandos(std::vector<OpStack> lis, i4 op, void *ref, u1 opType);
    /**
     * @brief Remove operando do inicio da lista
     * @param lis - Lista
     */
    std::vector<OpStack> RemoverInicio_operandos(std::vector<OpStack> lis);
    /**
     * @brief Remove operando do final da lista
     * @param lis - Lista
     */
    std::vector<OpStack> RemoverFim_operandos(std::vector<OpStack> lis);
     /**
     * @brief Imprime pilha de operandos
     * @param lis - Lista
     */
    void ImprimirOpStack(std::vector<OpStack> lis);
     /**
     * @brief Limpa pilha de operandos
     * @param lis - Lista
     */
    void LiberarOpStack(std::vector<OpStack> lis);

     /**
     * @brief Busca elemento na pilha de operandos
     * @param lis - Lista
     * @param op - Operando
     * @param opType - Tipo de operando
     */
    std::vector<OpStack> BuscarElemento_operandos(std::vector<OpStack> lis, i4 op, u1 opType);
     /**
     * @brief Busca elemento na pilha de operandos pela posição
     * @param lis - Lista
     * @param posicao - Posição do operando
     */
    OpStack BuscarPosicao_operandos(std::vector<OpStack> lis, int posicao);
    std::vector<OpStack> InserirPosicao_operandos(std::vector<OpStack> lis, i4 op, u1 opType, int posicao);
    std::vector<OpStack> RemoverPosicao_operandos(std::vector<OpStack> lis, int posicao);
};
///@{
/// Tipos possíveis de operando
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
///@}
#endif