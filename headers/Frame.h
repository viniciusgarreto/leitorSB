#include "./definitions.h"
#include "./OpStack.h"
#include "./CpInfo.h"
typedef struct vetor_locais {
  u4 *variavel;
  u1 tipo_variavel;
} Vetor_locais;

class frame {
    u4 end_retorno;  // Verificar se é realmente endereço de retorno
    OpStack pilhaOP;
    Vetor_locais *v;
    u2 vetor_length;
    CpInfo *cp;
    char *classeCorrente;
};