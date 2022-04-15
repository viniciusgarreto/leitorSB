#ifndef attributes_h
#define attributes_h

class Attributes;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

/**
* @file Attributes.h
* @brief Contem a lista de todos os attributes 
*/

class Attributes {
  public:
    /// construtor
    Attributes(FILE* fp, ConstantPool& cp);
    ~Attributes();
    
    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /**
     * @brief lê os atributos do arquivo fonte e od lista em attributes usando AddAttribue
     * @param fp - referencia para o arquivo fonte
     * @param cp - constant pull
     * retorno vazio
     */
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    /**
     * @brief adiciona o atributo na lista (vector) attributes
     * @param attributes - atributo a ser adicionado. @see Attribute
     */
    void AddAttribute(Attribute* attributes);

    /// lista de atributos
    std::vector<Attribute*> attributes;
    /// numero de atributos que há (contagem)
    u2 attributes_count;
};

#endif
