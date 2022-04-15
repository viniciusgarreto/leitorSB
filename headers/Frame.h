#ifndef frame_h
#define frame_h

class Frame;

#include <vector>
#include <list>

#include "../headers/definitions.h"
#include "../headers/ClassFile.h"
#include "../headers/ConstantPool.h"

using namespace std;

/**
* @file Frame.h
* @brief Define a estrutura de um único Frame 
*/

/// Estrutura do Operando
struct Op {
  /// Operando
  i4 operand;
  /// Tipo do operando
  u1 operand_type;
};

/// estrutura de variaveis locais
typedef struct local {
  /// variavel - ponteiro para a variável
  u4 *variavel;
  /// tipo da variavel
  u1 tipo_variavel;
} Local;

class Frame {
  public:
    /// construtor
    Frame(ClassFile& currentClass, u2 max_locals);
    ~Frame();

    string getClassName();

  private:
    /// endereço de retorno
    u4 end_retorno;        
    /// tamanho do vetor                 
    u2 vetor_length;
    /// nome da classe atual
    string classeCorrente;
    /// constant pool
    ConstantPool& constant_pool;
    /// pilha de operandos
    vector<Op> OpStack;
    /// vetor de variaveis locais
    vector<Local> local_vector;
};

#endif
