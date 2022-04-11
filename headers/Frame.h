#include "./definitions.h"
#include "./OpQueue.h"
class frame {
    u4 end_retorno;  // Verificar se é realmente endereço de retorno
    OpQueue pilhaOP;
    // Vetor_locais *v;
    u2 vetor_length;
    // Cp_info *cp;
    char *classeCorrente;
};