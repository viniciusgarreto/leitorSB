#ifndef jvm_h
#define jvm_h

class JVM;

#include <vector>
#include "../headers/definitions.h"
#include "../headers/StackFrame.h"
#include "../headers/ClassFile.h"
#include "../headers/Method.h"
#include "../headers/Object.h"

using namespace std;
/*
Define a classe JVM 
possui um exception name, uma pila de frames, uma lista de objetos e uma lista de classes. Também pssui o program counter e exception.

*/
/**
* @file JVM.h
* @brief Define a classe JVM. Possui um exception name, uma pila de frames, uma lista de objetos e uma lista de classes. Também pssui o program counter e exception.
*/
class JVM {
  public:
    /// construtor
    JVM();
    ~JVM();

    // deal with instance (we're using a singleton model)
    /** 
     * @brief Singleton é o padrão utilizado, então garante que haja apaenas uma instancia JVM
     * @return JVM instance
     */
    static JVM& getInstance();
    /**
    * @brief Remove a instancia JVM.
    */
    static void removeInstance();

    /**
    * @brief Pega um class file pelo seu nome
    * @param classfile_name - string: nome do arquivo .class
    * @return ClassFIle - retorna o arquivo .class. @see ClassFile
    */
    ClassFile& getClassFileByName(string classfile_name); //métorod para pegar uma classe pelo nome
    void ReadClassFile(string classfile_name);

    /**
    * @brief Executa a JVM 
    */
    void execute();

    /**
    * @brief Adiciona arquibvo class atual na pilha de frames
    * @param current_class
    * @param max_locals
    */
    void pushFrame(ClassFile& current_class, u2 max_locals);
    u2 findHandlerMethod(Method& method);

    u4 pc;
    u2 exception;

  private:
    // singleton instance
    static JVM* instance;
    string exception_name;
    StackFrame* frame_stack;
    vector<ClassFile*> classes;
    vector<Object> objects;
    // static Instructions instructions; // idk ?????
};

#endif
