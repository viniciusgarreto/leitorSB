#ifndef stack_frame_h
#define stack_frame_h

#include <vector>
#include "../headers/Frame.h"

class StackFrame {
  public:
    StackFrame();
    ~StackFrame();

  private:
    vector<Frame*> frames;
};

#endif
