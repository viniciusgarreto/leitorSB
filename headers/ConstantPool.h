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

    // print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const ConstantPool& cf);

    CpInfo* getCpInfo(u2 index);
    string getValueUTF8String(u2 index);
  private:
    void ReadConstantPoolFromFile(FILE* fp);
    u2 count;
    CpInfo** cp_infos;
};


#endif
