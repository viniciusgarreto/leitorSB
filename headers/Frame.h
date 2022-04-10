#ifndef frame_h
#define frame_h

#include <vector>
#include <list>

#include "../headers/definitions.h"
#include "../headers/CpInfo.h"

using namespace std;

struct Op {
  i4 operand;
  u1 operand_type;
};

struct OpList {
  list<Op> OpList;
};

typedef struct vetor_locais {
  u4 *variavel;
  u1 tipo_variavel;
} Vetor_locais;

class Frame {
  public:
    Frame();
    ~Frame();

  private:
    u4 end_retorno;  // Verificar se é realmente endereço de retorno
    vector<OpList> OpStack; //pilha de operandos
    Vetor_locais *v;
    u2 vetor_length;
    CpInfo *cp;
    char *classeCorrente;
};

#endif
