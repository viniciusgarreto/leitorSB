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
    vector<OpList> OpStack;
    vector<Local> local_vector;
    u2 vetor_length;
    CpInfo *cp;
    string classeCorrente;
};

#endif
