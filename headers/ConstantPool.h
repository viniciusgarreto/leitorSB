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
    ConstantPool(FILE* fp, u2 cp_count);
    ~ConstantPool();

  private:
    void AddCpInfo(CpInfo* cp_info);
    void ReadConstantPoolFromFile(FILE* fp, u2 cp_count);
    std::vector<CpInfo*> cp_infos;
};


#endif
