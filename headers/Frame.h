#include "./definitions.h"
#include "./OpQueue.h"
#include "./CpInfo.h"
class frame {
    u4 end_retorno;  // Verificar se é realmente endereço de retorno
    OpQueue pilhaOP;
    // Vetor_locais *v;
    u2 vetor_length;
    CpInfo *cp;
    char *classeCorrente;
};