#include "../headers/VerificationTypeInfo.h"


VerificationTypeInfo* VerificationTypeInfo::readVerificationTypeInfo(FILE* fp) {
  u1 tag = u1READ(fp);

  switch (tag) {
    case 0:
      return new TopVariableInfo();
    case 1:
      return new IntegerVariableInfo();
    case 2:
      return new FloatVariableInfo();
    case 3:
      return new LongVariableInfo();
    case 4:
      return new DoubleVariableInfo();
    case 5:
      return new NullVariableInfo();
    case 6:
      return new UninitializedThisVariableInfo();
    case 7:
      return new ObjectVariableInfo(fp);
    case 8:
      return new UninitializedVariableInfo(fp);

    default:
      cout << "[ERROR] something wrong with verificationTypeInfo..." << endl;
      exit(0);
  }
}

VerificationTypeInfo::VerificationTypeInfo(u1 tag) {
  this->tag = tag;
}
VerificationTypeInfo::~VerificationTypeInfo() {}
ostream& VerificationTypeInfo::print(unsigned int indent, ostream& output) const {
  switch (this->tag) {
    case 0:
      return ((TopVariableInfo*) this)->print(indent, output);
    case 1:
      return ((IntegerVariableInfo*) this)->print(indent, output);
    case 2:
      return ((FloatVariableInfo*) this)->print(indent, output);
    case 3:
      return ((LongVariableInfo*) this)->print(indent, output);
    case 4:
      return ((DoubleVariableInfo*) this)->print(indent, output);
    case 5:
      return ((NullVariableInfo*) this)->print(indent, output);
    case 6:
      return ((UninitializedThisVariableInfo*) this)->print(indent, output);
    case 7:
      return ((ObjectVariableInfo*) this)->print(indent, output);
    case 8:
      return ((UninitializedVariableInfo*) this)->print(indent, output);

    default:
      cout << "[ERROR] something wrong with verificationTypeInfo..." << endl;
      exit(0);
  }
}

TopVariableInfo::TopVariableInfo(): VerificationTypeInfo(0) {}
ostream& TopVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "TopVariableInfo (tag: 0)"<< endl;
  return output;
}
TopVariableInfo::~TopVariableInfo() {}

IntegerVariableInfo::IntegerVariableInfo(): VerificationTypeInfo(1) {}
ostream& IntegerVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "IntegerVariableInfo (tag: 1)"<< endl;
  return output;
}
IntegerVariableInfo::~IntegerVariableInfo() {}

FloatVariableInfo::FloatVariableInfo(): VerificationTypeInfo(2) {}
ostream& FloatVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "FloatVariableInfo (tag: 2)"<< endl;
  return output;
}
FloatVariableInfo::~FloatVariableInfo() {}

LongVariableInfo::LongVariableInfo(): VerificationTypeInfo(3) {}
ostream& LongVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "LongVariableInfo (tag: 3)"<< endl;
  return output;
}
LongVariableInfo::~LongVariableInfo() {}

DoubleVariableInfo::DoubleVariableInfo(): VerificationTypeInfo(4) {}
ostream& DoubleVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "DoubleVariableInfo (tag: 4)"<< endl;
  return output;
}
DoubleVariableInfo::~DoubleVariableInfo() {}

NullVariableInfo::NullVariableInfo(): VerificationTypeInfo(5) {}
ostream& NullVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "NullVariableInfo (tag: 5)"<< endl;
  return output;
}
NullVariableInfo::~NullVariableInfo() {}

UninitializedThisVariableInfo::UninitializedThisVariableInfo(): VerificationTypeInfo(6) {}
ostream& UninitializedThisVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "UninitializedThisVariableInfo (tag: 6)"<< endl;
  return output;
}
UninitializedThisVariableInfo::~UninitializedThisVariableInfo() {}

ObjectVariableInfo::ObjectVariableInfo(FILE* fp): VerificationTypeInfo(7) {
  this->cpool_index = u2READ(fp);
}
ostream& ObjectVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "ObjectVariableInfo (tag: 7)"<< endl;
  indentBy(indent+1) << "cpool_index: " << (unsigned) this->cpool_index << endl;
  return output;
}
ObjectVariableInfo::~ObjectVariableInfo() {}

UninitializedVariableInfo::UninitializedVariableInfo(FILE* fp): VerificationTypeInfo(8) {
  this->offset = u2READ(fp);
}
ostream& UninitializedVariableInfo::print(unsigned int indent, ostream& output) const {
  indentBy(indent) << "UninitializedVariableInfo (tag: 8)"<< endl;
  indentBy(indent+1) << "offset: " << (unsigned) this->offset << endl;
  return output;
}
UninitializedVariableInfo::~UninitializedVariableInfo() {}
