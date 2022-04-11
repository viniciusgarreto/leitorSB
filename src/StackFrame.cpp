#include "../headers/StackFrame.h"

StackFrame::StackFrame() {
  cout << "TODO: implement" << endl;
}
StackFrame::~StackFrame() {
  for (auto frame : this->frames)
    delete frame;
  this->frames.clear();
}
