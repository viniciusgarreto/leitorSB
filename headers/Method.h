/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

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
    /**
     * @brief Lê atributos de um arquivo
     * @param fp - arquivo a ser lido
     * @param cp - Constant Pool
     * @return void
     */
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    /**
     * @brief Adiciona atributo
     * @param attb - Atributo a ser adicionado
     * @return void
     */
    void AddAttribute(Attribute* attb);

    ///Flags de acesso
    u2 access_flags;
    /// Index do nome
    u2 name_index;
    /// Index da descrição
    u2 descriptor_index;
    /// Contador de atributos
    u2 attributes_count;
    /// Vetor de atributos
    std::vector<Attribute*> attributes;
};

#endif
