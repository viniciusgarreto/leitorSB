#ifndef frame_h
#define frame_h

#include <vector>
#include <list>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

/**
* @file Frame.h
* @brief Define a estrutura de um único Frame 
*/

/// Operando e seu tipo
struct Op {
  /// Operando
  i4 operand;
  /// Tipo do operando
  u1 operand_type;
};

struct OpList {
  /// Lista de operandos
  list<Op> OpList;
};

/// Variaveis locais
typedef struct local {
  u4 *variavel;
  u1 tipo_variavel;
} Local;

class Frame {
  public:
    Frame(ClassFile& currentClass, u2 max_locals);
    ~Frame();

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
    vector<OpList> OpStack;
    /// vetor de variaveis local
    vector<Local> local_vector;
};

#endif
