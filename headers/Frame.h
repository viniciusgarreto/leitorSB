#ifndef frame_h
#define frame_h

#include <vector>
#include <list>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

struct Op {
  i4 operand;
  u1 operand_type;
};

struct OpList {
  list<Op> OpList;
};

typedef struct local {
  u4 *variavel;
  u1 tipo_variavel;
} Local;

class Frame {
  public:
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
