#ifndef methods_h
#define methods_h

class Methods;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Method.h"

/**
* @file Methods.h
* @brief Dispõe os metodos em um vetor - vetor de metodos
*/

class Methods {
  public:
    /// construtor
    Methods(FILE* fp, ConstantPool& cp);
    ~Methods();

    /// pega o metodo main
    Method* getMain(ConstantPool& cp);
    /// pega o metodo cl initi se houver
    Method* getCLinit(ConstantPool& cp);

    /// print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    /**
     * @brief Lê metodos do arquivo fonte e os adiciona no vetor de metodos
     * @param fp - referencia para o arquivo fonte
     * @param cp - constant pool
     */
    void ReadMethodsFromFile(FILE* fp, ConstantPool& cp);
    /**
     * @brief Adiciona método ao vetor de matodos
     * @param method - metodo a ser adicionado ao vetor
     */
    void AddMethod(Method* method);

    /// vetor de metodos
    std::vector<Method*> methods;
    /// contagem de metodos
    u2 methods_count;
};

#endif
