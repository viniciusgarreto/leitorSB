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

#ifndef classFile_h
#define classFile_h

class ClassFile;

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Interfaces.h"
#include "../headers/Fields.h"
#include "../headers/Methods.h"
#include "../headers/Attributes.h"

/**
* @file ClassFile.h
* @brief Define a estrutura de um arquivo .class. 
*/
using namespace std;
class ClassFile {
  public:
    /// construtor
    ClassFile(FILE* fp);
    ~ClassFile();

    /// read .class file
    /**
     * @brief lê arquivo .class
     * @param nomeArquivo - nome do arquivo a ser lido
     * @return ClassFile - @see ClassFile
     */
    static ClassFile* lerArquivo(string nomeArquivo);
    
    /**
     * @brief Pega na constant pool o nome do class file
     * @return string - nome do class file
     */
    string getName();

    /**
     * @brief Pega a constant pool desse arquivo
     * @return COnstat Pool
     */
    ConstantPool& getConstantPool();

    /**
     * @brief Pega o metodo main no class file
     * @return Mathod - Matodo Main.
     */
    Method* getMain();
    /**
     * @brief Se hover, pega o metodo que é executado antes da main, o CL init
     * @return Mathod - metodo CL init
     */
    Method* getCLinit();

    /// print methods
    ostream& print(ostream& output = cout) const;
    friend ostream& operator<<(ostream& out, const ClassFile& cf);

  private:
    /// Identifica o formato do class file, possui o valor 0xCAFEBABE.
    u4 magic;
    /// O menor numero de versão do class file.                     
    u2 minor_version;
    /// O maior numero de versao do class file, junto do minor version, determina a versao do formato do class file.             
    u2 major_version;
    /// Tabela de estruturas representando constantes de string, classes, nome de interfaces, fields e outras contantes que sao referenciadas dentro das estruturas e subestruturas do class file.             
    ConstantPool* constant_pool;
    /// O valor do access flags e uma mascara de flags usadas para denotar permissões de acesso e propriedades de classe ou interface  
    u2 access_flags;
    /// Um valor valido de index dentro da table de constant pool              
    u2 this_class;
    /// Um valor valido de index dentro da table de constant pool ou zero                
    u2 super_class; 
    /// Um array de valores validos de index dentro da table de constant pool              
    Interfaces* interfaces;  
    /// Devem ser do tipo field info que da uma descrição completa de um field dessa classe ou interface     
    Fields* fields;   
    /// Devem ser do tipo methods info que da uma descrição completa de um metodo dessa classe ou interface            
    Methods* methods;  
    /// Devem ser do tipo attribute info           
    Attributes* attributes;       
};

#endif
