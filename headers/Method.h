#ifndef method_h
#define method_h

class Method;

#include <stdio.h>
#include <vector>

#include "../headers/JVM.h"
#include "../headers/definitions.h"
#include "../headers/Attribute.h"

/**
* @file Method.h
* @brief Descreve todos os metodos do arquivo .class
*/

class Method {
  public:
   ///cosntrutor
    Method(FILE* fp, ConstantPool& cp);
    ~Method();

    // run method
    /**
     * @brief Executa o método
     * @param jvm - jvm usada para interpretação do code attribute
     * @param current_class - class file atual 
     * @param createFrame - flag para criação de u novo frame na jvm: se for 1 cria um frame com a classe atual
     * @return void
     */
    void execute(JVM& jvm, ClassFile& current_class, bool createFrame);

    /// pega o nome do metodo a partir da constant pool
    string getName(ConstantPool& cp);
    /// pega o descriptor a partir da constrant pool
    string getDescriptor(ConstantPool& cp);
    CodeAttribute* getCodeAttb(ConstantPool& cp);

    /// print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attb);

    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<Attribute*> attributes;
};

#endif
