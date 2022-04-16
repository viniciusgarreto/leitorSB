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

#ifndef stack_frame_h
#define stack_frame_h

class StackFrame;

#include <vector>
#include "../headers/Frame.h"

/**
* @file StackFrame.h
* @brief Clsse Stack Frame define uma pilha de frames.
*/

class StackFrame {
  public:
    /// construtor
    StackFrame();
    ~StackFrame();

    /**
    * @brief adiciona frame na pilha de frames
    * @param frame - frame a ser adicionado na pilha
    */
    void pushFrame(Frame* frame);
    
    /**
    * @brief Pega o topo da pilha de frames
    * @return frame que está no topo da pilha de frames  
    */
    Frame* topFrame();
    
    /**
    * @brief Remove topo da pilha de frames
    */
    void popFrame();

  private:
    /// Vetor de frames
    vector<Frame*> frames;
};

#endif
