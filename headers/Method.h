#ifndef method_h
#define method_h

class Method;

#include <stdio.h>
#include <vector>

#include "../headers/JVM.h"
#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Method {
  public:
    Method(FILE* fp, ConstantPool& cp);
    ~Method();

    // run method
    void execute(JVM& jvm, ClassFile& current_class, bool createFrame);

    string getName(ConstantPool& cp);
    string getDescriptor(ConstantPool& cp);

    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attb);
    CodeAttribute* GetCodeAttb(ConstantPool& cp);

    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<Attribute*> attributes;
};

#endif
