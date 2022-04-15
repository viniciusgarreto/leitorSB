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

#include "../headers/StackMapFrame.h"

StackMapFrame* StackMapFrame::readStackMapFrame(FILE* fp) {
  u1 tag = u1READ(fp);

  if (tag <= 63)
    return new SameFrame(tag);

  if (tag >= 64 && tag <= 127)
    return new SameLocals1StackItemFrame(tag, fp);

  if (tag == 247)
    return new SameLocals1StackItemFrameExtended(tag, fp);

  if (tag >= 248 && tag <= 250)
		return new ChopFrame(tag, fp);

  if (tag == 251)
    return new SameFrameExtended(tag, fp);

  if (tag >= 252 && tag <= 254) {
		return new AppendFrame(tag, fp);
	}
  if (tag == 255)
    return new FullFrame(tag, fp);

  return nullptr;
}

StackMapFrame::StackMapFrame(u1 tag) {
  this->frame_type = tag;
}
StackMapFrame::~StackMapFrame() {}
ostream& StackMapFrame::print(unsigned int indent, ostream& output) const {
  if (this->frame_type <= 63)
    return ((SameFrame*) this)->print(indent, output);

  if (this->frame_type >= 64 && this->frame_type <= 127)
    return ((SameLocals1StackItemFrame*) this)->print(indent, output);

  if (this->frame_type == 247)
    return ((SameLocals1StackItemFrameExtended*) this)->print(indent, output);

  if (this->frame_type >= 248 && this->frame_type <= 250)
		return ((ChopFrame*) this)->print(indent, output);

  if (this->frame_type == 251)
    return ((SameFrameExtended*) this)->print(indent, output);

  if (this->frame_type >= 252 && this->frame_type <= 254) {
		return ((AppendFrame*) this)->print(indent, output);
	}
  if (this->frame_type == 255)
    return ((FullFrame*) this)->print(indent, output);

  return output;
}

SameFrame::SameFrame(u1 tag): StackMapFrame(tag) {}
ostream& SameFrame::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "SameFrame: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;

	return output;
}
SameFrame::~SameFrame() {}

SameFrameExtended::SameFrameExtended(u1 tag, FILE* fp): StackMapFrame(tag) {
  this->offset_delta = u2READ(fp);
}
ostream& SameFrameExtended::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "SameFrameExtended: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "offset_delta: " << (unsigned) this->offset_delta << endl;

	return output;
}
SameFrameExtended::~SameFrameExtended() {}

SameLocals1StackItemFrame::SameLocals1StackItemFrame(u1 tag, FILE* fp): StackMapFrame(tag) {
  this->item = VerificationTypeInfo::readVerificationTypeInfo(fp);
}
ostream& SameLocals1StackItemFrame::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "SameLocals1StackItemFrame: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "item: " << endl;
  this->item->print(indent+2, output);

	return output;
}
SameLocals1StackItemFrame::~SameLocals1StackItemFrame() {
  delete this->item;
}

SameLocals1StackItemFrameExtended::SameLocals1StackItemFrameExtended(u1 tag, FILE* fp): StackMapFrame(tag) {
  this->offset_delta = u2READ(fp);
  this->item = VerificationTypeInfo::readVerificationTypeInfo(fp);
}
ostream& SameLocals1StackItemFrameExtended::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "SameLocals1StackItemFrameExtended: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "offset_delta: " << (unsigned) this->offset_delta << endl;
  indentBy(indent+1, output) << "item: " << endl;
  this->item->print(indent+2, output);

	return output;
}
SameLocals1StackItemFrameExtended::~SameLocals1StackItemFrameExtended() {}

ChopFrame::ChopFrame(u1 tag, FILE* fp): StackMapFrame(tag) {
  this->offset_delta = u2READ(fp);
}
ostream& ChopFrame::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "ChopFrame: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "offset_delta: " << (unsigned) this->offset_delta << endl;

  return output;
}
ChopFrame::~ChopFrame() {}

AppendFrame::AppendFrame(u1 tag, FILE* fp): StackMapFrame(tag) {
  this->offset_delta = u2READ(fp);
  
  int sizeStack = tag - 251;
  for (int i = 0; i < sizeStack; i++) {
    this->stack.push_back(VerificationTypeInfo::readVerificationTypeInfo(fp));
  }
}
ostream& AppendFrame::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "AppendFrame: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "offset_delta: " << (unsigned) this->offset_delta << endl;
  indentBy(indent+1, output) << "stack: " << endl;

  for (auto vInfo : stack)
    vInfo->print(indent+2, output);
  
  return output;
}
AppendFrame::~AppendFrame() {
  for (auto vInfo : this->stack) {
    delete vInfo;
  }
  this->stack.clear();
}

FullFrame::FullFrame(u1 tag, FILE* fp): StackMapFrame(tag) {
	this->offset_delta = u2READ(fp);
	this->number_of_locals = u2READ(fp);

  for (int i = 0; i < this->number_of_locals; i++) {
    auto vInfo = VerificationTypeInfo::readVerificationTypeInfo(fp);
    this->locals.push_back(vInfo);
    if (vInfo->tag == 7) {
      //????
    }
  }
		
  this->number_of_stack_items = u2READ(fp);
  for (int i = 0; i < this->number_of_stack_items; i++) {
    this->stack.push_back(VerificationTypeInfo::readVerificationTypeInfo(fp));
  }
}
ostream& FullFrame::print(unsigned int indent, ostream& output) const {
  indentBy(indent, output) << "FullFrame: " << endl;
  indentBy(indent+1, output) << "frame_type: " << (unsigned) this->frame_type << endl;
  indentBy(indent+1, output) << "offset_delta: " << (unsigned) this->offset_delta << endl;
  indentBy(indent+1, output) << "number_of_locals: " << (unsigned) this->number_of_locals << endl;
  indentBy(indent+1, output) << "locals: " << endl;
  for (auto vInfo : locals)
    vInfo->print(indent+2, output);

  indentBy(indent+1, output) << "number_of_stack_items: " << (unsigned) this->number_of_stack_items << endl;
  indentBy(indent+1, output) << "stack: " << endl;
  for (auto vInfo : stack)
    vInfo->print(indent+2, output);

  return output;
}
FullFrame::~FullFrame() {}
