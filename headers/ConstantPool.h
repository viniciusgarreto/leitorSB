#ifndef constant_pool_h
#define constant_pool_h

#include <vector>
#include <stdio.h>
// #include <stdlib.h>

#include "../headers/definitions.h"
#include "../headers/CpInfo.h"

using namespace std;

class ConstantPool {
  public:
    ConstantPool(FILE* fp);
    ~ConstantPool();
    void printConstantPool();

  private:
    void AddCpInfo(CpInfo* cp_info);
    void ReadConstantPoolFromFile(FILE* fp);
    u2 count;
    std::vector<CpInfo*> cp_infos;
};


#endif
