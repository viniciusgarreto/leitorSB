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
    /// construtor
    Frame(string currentClass, u2 max_locals);
    ~Frame();

  private:
    u4 end_retorno;                         
    u2 vetor_length;
    string classeCorrente;
    ConstantPool& constant_pool;
    vector<OpList> OpStack;
    vector<Local> local_vector;
};

#endif
