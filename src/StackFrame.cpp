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

#include "../headers/StackFrame.h"

StackFrame::StackFrame() {}
StackFrame::~StackFrame() {
  for (auto frame : this->frames)
    delete frame;
  this->frames.clear();
}


void StackFrame::pushFrame(Frame* frame) {
  this->frames.push_back(frame);
}

Frame* StackFrame::topFrame() {
  if (this->frames.empty()) return nullptr;
  return this->frames.back();
}
void StackFrame::popFrame() {
  if (this->frames.empty()) {
    cout << "[ERROR] tried to pop (remove) the top frame, but frame stack is empty" << endl;
    exit(1);
  }

  // no need to delete. pop_back calls the destructor
  this->frames.pop_back();
}
