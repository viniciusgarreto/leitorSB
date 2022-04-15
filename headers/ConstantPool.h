#ifndef constant_pool_h
#define constant_pool_h

class ConstantPool;

#include <vector>
#include <stdio.h>
// #include <stdlib.h>

#include "../headers/definitions.h"
#include "../headers/CpInfo.h"

using namespace std;

class ConstantPool {
  public:
    //Construtor
    ConstantPool(FILE* fp);
    ~ConstantPool();

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const ConstantPool& cf);

    /**
     * @brief Retorna Constant Pool Info
     * @param index - index valido da tabela de constant pool
     * @return Contant Pool Info
     */
    CpInfo* getCpInfo(u2 index) const;

    /**
     * @brief Retorna valor UTF8 em string
     * @param index - index valido de valor UTF8
     * @return string UTF8
     */
    string getValueUTF8String(u2 index) const;
  private:

    /**
     * @brief Lê constant pool de algum arquivo .class
     * @param fp - Arquivo .class a ser lido
     */
    void ReadConstantPoolFromFile(FILE* fp);
    u2 count;
    CpInfo** cp_infos;
};


#endif
