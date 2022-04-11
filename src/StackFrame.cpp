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

Frame& StackFrame::topFrame() {
  if (this->frames.empty()) {
    cout << "[ERROR] tried to access the top frame, but frame stack is empty" << endl;
    exit(1);
  }

  return *this->frames.back();
}
void StackFrame::popFrame() {
  if (this->frames.empty()) {
    cout << "[ERROR] tried to pop (remove) the top frame, but frame stack is empty" << endl;
    exit(1);
  }

  // no need to delete. pop_back calls the destructor
  this->frames.pop_back();
}
