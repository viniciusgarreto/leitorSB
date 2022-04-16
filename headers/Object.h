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

#ifndef object_h
#define object_h

class Object;

#include "../headers/definitions.h"
#include "../headers/ClassFile.h"

/*
Classe Object
*/
/**
* @file Object.h
* @brief Classe Object: Define a estrutura de um objeto do arquivo class
*/
class Object {
private:
	/// Objeto
	ClassFile * obj;
	/// Tamanho dos dados
	u1 sizeData;
	/// Dado da classe
	u4 * data;
public:
  /// Construtor
  Object(/* args */);
  ~Object();
};

#endif
