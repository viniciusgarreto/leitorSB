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
    ClassFile& getClassFileByName(string classfile_name); //método para pegar uma classe pelo nome
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

    ///Contador de programa
    u4 pc;
    /// Exceção 
    u2 exception;

  private:
    /// singleton instance
    static JVM* instance;
    /// Nome da exception
    string exception_name;
    /// Pilha de frames
    StackFrame* frame_stack;
    /// Vetor de classes
    vector<ClassFile*> classes;
    /// Vetor de objetos
    vector<Object> objects;
    // static Instructions instructions; // idk ?????
};

#endif
