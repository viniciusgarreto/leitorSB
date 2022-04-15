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

    // read .class file
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
    u4 magic;
    u2 minor_version;
    u2 major_version;
    ConstantPool* constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    Interfaces* interfaces;
    Fields* fields;
    Methods* methods;
    Attributes* attributes;
};

#endif
