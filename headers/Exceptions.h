#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

class Exceptions {
  public:
    /// construtor
    Exceptions(FILE *fp);
    ~Exceptions();

    /**
     * @brief Transforma em String
     * @param cp - Constant Pool
     * @return Pedaço de Constant Pool em string
     */
    string ToString(ConstantPool& cp);

  private:
    std::vector<u2> exceptions; //Vetor de exceptions
    u2 count; //Contador
};


#endif
