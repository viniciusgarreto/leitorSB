#ifndef stack_frame_h
#define stack_frame_h

class StackFrame;

#include <vector>
#include "../headers/Frame.h"

/*
Clsse Stack Frame
define uma pilha de frames.
*/

class StackFrame {
  public:
    StackFrame();
    ~StackFrame();

    void pushFrame(Frame* frame);
    Frame* topFrame();
    void popFrame();

  private:
    vector<Frame*> frames;
};

#endif
