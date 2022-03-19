#include <iostream>

#include "../headers/ConstantPool.h"
#include "../headers/definitions.h"
#include "../headers/CpInfo.h"

using namespace std;

// constructor
ConstantPool::ConstantPool(FILE *fp, u2 cp_count) {

  for (int i = 1; i <= cp_count+1; i++) {
    u1 tag = u1READ(fp);

    switch (tag) {
      // tag 1, type string (2+x bytes)
			case CONSTANT_Utf8:
        this->AddCpInfo((CpInfo*) new CONSTANT_Utf8_info(fp));
				break;
      
      // tag 3, type integer (4 bytes)
      case CONSTANT_Integer: 
        this->AddCpInfo((CpInfo*) new CONSTANT_Integer_info(fp));
				break;

      // tag 4, type float (4 bytes)
      case CONSTANT_Float:
        this->AddCpInfo((CpInfo*) new CONSTANT_Float_info(fp));
				break;

      // tag 5, type long (8 bytes)
      case CONSTANT_Long: 
        this->AddCpInfo((CpInfo*) new CONSTANT_Long_info(fp));
				// i++;
				break;

      // tag 6, type double (8 bytes)
      case CONSTANT_Double:
        this->AddCpInfo((CpInfo*) new CONSTANT_Double_info(fp));
				// i++;
				break;

      // tag 7, type classRef (2 bytes)
      case CONSTANT_Class: 
        this->AddCpInfo((CpInfo*) new CONSTANT_Class_info(fp));
				break;

      // tag 8, type string ref (2 bytes)
      case CONSTANT_String: 
        this->AddCpInfo((CpInfo*) new CONSTANT_String_info(fp));
				break;

      // tag 9, type fieldRef (4 bytes)
			case CONSTANT_Fieldref: 
        this->AddCpInfo((CpInfo*) new CONSTANT_Fieldref_info(fp));
				break;

      // tag 10, type methodRef (4 bytes)s
			case CONSTANT_Methodref: 
        this->AddCpInfo((CpInfo*) new CONSTANT_Methodref_info(fp));
				break;

      // tag 11, type interfaceMethodRef (4 bytes)
			case CONSTANT_InterfaceMethodref:
        this->AddCpInfo((CpInfo*) new CONSTANT_InterfaceMethodref_info(fp));
				break;

      // tag 12, type nameAndType (4 bytes)
			case CONSTANT_NameAndType: 
        this->AddCpInfo((CpInfo*) new CONSTANT_NameAndType_info(fp));
				break;

      // tag 13, type methodHandle (3 bytes)
			case CONSTANT_MethodHandle: 
        this->AddCpInfo((CpInfo*) new CONSTANT_MethodHandle_info(fp));
				break;

      // tag 14, type methodType (4 bytes)
			case CONSTANT_MethodType: 
        this->AddCpInfo((CpInfo*) new CONSTANT_MethodType_info(fp));
				break;

      // tag 17, type Dynamic (4 bytes)

      // tag 18, type invokeDynamic (4 bytes)
			case CONSTANT_InvokeDynamic: 
        this->AddCpInfo((CpInfo*) new CONSTANT_InvokeDynamic_info(fp));
				break;

      // tag 19, type module (2 bytes)

      // tag 20, type module (2 bytes)

			default:
        cout << "[ERROR] unidentified tag value" << tag << endl;
				break;
    }
  }
}

// destructor
ConstantPool::~ConstantPool() {
  // delete all items from vector
  for (const auto cp_info : this->cp_infos)
    delete cp_info;

  this->cp_infos.clear();
}

void ConstantPool::AddCpInfo(CpInfo* cp_info) {
  this->cp_infos.push_back(cp_info);
}
