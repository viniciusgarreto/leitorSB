#ifndef jvm_h
#define jvm_h

#include <vector>
#include "../headers/definitions.h"
#include "../headers/StackFrame.h"
#include "../headers/ClassFile.h"
#include "../headers/Object.h"

using namespace std;

class ClassFile;
class Object;

class JVM {
  public:
    JVM();
    ~JVM();

    // deal with instance (we're using a singleton model)
    static JVM& getInstance();
    static void removeInstance();

    ClassFile& getClassFileByName(string classfile_name);
    void ReadClassFile(string classfile_name);

    void execute();
    void pushFrame(ClassFile& current_class, u2 max_locals);

    u4 pc;
    u2 exception;

  private:
    // singleton instance
    static JVM* instance;
    char* exception_name;
    StackFrame* frame_stack;
    vector<ClassFile*> classes;
    vector<Object> objects;
    // static Instructions instructions; // idk ?????
};

#endif
