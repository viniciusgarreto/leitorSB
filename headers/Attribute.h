#ifndef attribute_h
#define attribute_h

#include <stdio.h>

class Attribute;
class ExceptionsAttribute;
class SourceFileAttribute;
class CodeAttribute;
class LineNumberTableAttribute;
class StackMapAttribute;
class InnerClassesAttribute;
class SignatureAttribute;
class ConstantValueAttribute;
class ExceptionsAttribute;

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Classes.h"
#include "../headers/LineNumberTable.h"
#include "../headers/StackMapFrame.h"
#include "../headers/JVM.h"
#include "../headers/Method.h"
#include "../headers/ExceptionTable.h"

/**
 * @file Attributes.h
 * @brief Classes sobre os atributos do arquivo class
 */


/** Classe Atributo*/
class Attribute {
  public:
    /// construtor
    Attribute(u2 attbName, u4 attbLength);
    ~Attribute();
    /**
     * @brief Le o array de atributos do arquivo fonte
     * 
     * @param fp - referência a um File que tem o conteúdo do arquivo de classe
     * carregado nele. O File seek deve ser o primeiro atributo.
     * @param cp - referencia para o atual class file na constant pool
     *
     * @return attributo - array de Attribute  
     */
    static Attribute* readAttribute(FILE* fp, ConstantPool& cp);
    /**
    * @brief pega o nome da classe no constant pool
    */
    string getName(ConstantPool& cp);

    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  protected:
    /// nome do atributo
    u2 attribute_name;
    /// tamanho do atributo
    u4 attribute_length;
    void *info;   
};

/** @name Informações dos Atributos - Attributes*/
///@{
class ExceptionsAttribute;

/** Atributo do Arquivo de origem*/
class SourceFileAttribute : public Attribute {
  public:
    /// construtor
    SourceFileAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~SourceFileAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// arquivo fonte
    u2 source_file;
};

/** Atributo de codigo*/
class CodeAttribute : public Attribute {
  public:
    /// construtor
    CodeAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~CodeAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;


    /**
     * @brief metodo que interpreta o code atualmente.
     * @param jvm - referencia para a jvm e utilizar a pilha de frames e colocar as instruções
     * @param method - metodo a qual esse atributo pertence.
     * nao possui retorno
     */
    void interpret(JVM& jvm, Method& method);
    /// numero maximo de variaveis locais no code array 
    string bytecodeToString(u1 bytecode) const;
    vector<ExceptionTable*> getExceptionTable();

    /**
     * @brief pega a tabela de exceções 
     * @return vetor de exception table
     */
    vector<ExceptionTable*> getExceptionTable();

    /// numero maximo de variaveis locais no code array 
    u2 max_locals;

  private:
    /**
     * @brief adiciona atributo no array de atributos
     * @param interface - atributo a ser adicionado
     * retorna void
     */
    void AddAttribute(Attribute* interface);
    /**
     * @brief adiciona exceção na tabela de exceção
     * @param table - tabela de exceção a ser adicionada
     * retorna void
     */
    void AddExceptionTable(ExceptionTable* table);
    /// Tamanho maximo da pilha (stack)
    u2 max_stack;
    /// numero de bytes no code array
    u4 code_length;
    /// Fluxo de bytecode deste método
    u1 *code;
    /// Numero de atributos internos (inner attributes)
    u2 attributes_count;
    /// atributos internos (inner attributes)
    std::vector<Attribute*> attributes;
    /// tamanho da tabela de exceções (exception table)
    u2 exception_info_length;
    /// manipuladores de exceção para este código. @see ExceptionTable
    std::vector<ExceptionTable*> exception_table;
};

/** Tabela para associar os numeros das linhas do arquivo aos indexes do codigo */
class LineNumberTableAttribute : public Attribute {
  public:
    /// construtor
    LineNumberTableAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~LineNumberTableAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /**
    * @brief adicona numero da linha na tabela
    * 
    * @param table - referencia para a tabela de numero de linhas
    */
    void AddLineNumberTable(LineNumberTable* table);
    /// tamanho da tabela
    u2 line_number_table_length;
    //// Tabela com o numero das linhas e seus correspondentes start_pc no array
    std::vector<LineNumberTable*> line_number_table;
};



class StackMapAttribute : public Attribute {
  public:
    /// construtor
    StackMapAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~StackMapAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /**
     * @brief le pilha de frames???
     *
     * @param fp - referencia para o arquivo fonte
     */
    void readStackMapFrame(FILE* fp);
    /// numero de entradas do frame
    u2 num_entries;
    /// @see StackMapFrame
    StackMapFrame** entries;
};

/** Array de inner classes*/
class InnerClassesAttribute : public Attribute {
  public:
    /// construtor
    InnerClassesAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~InnerClassesAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /**
     * @brief Adiciona as classes internas ao vetor de classes
     * @param c- classe a ser adicionada ao vetor classes. @see Classes
     * retorno void
     */
    void AddClasses(Classes* c);
    /// numero de classes
    u2 num_classes;
    /// array de classes. @see Classes
    std::vector<Classes*> classes;
};

/** Atributo de Assinatura*/
class SignatureAttribute : public Attribute {
  public:
    /// construtor
    SignatureAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~SignatureAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// assinatura
    u2 signature;
};

/** Atributo Valor Constante*/
class ConstantValueAttribute : public Attribute {
  public:
    /// construtor
    ConstantValueAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ConstantValueAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// Index na constant pool para o Cnstant Value
    u2 constantValue;
};

/**Exceções que um metodo pode lançar (throw)*/
class ExceptionsAttribute : public Attribute {
  public:
    /// construtor
    ExceptionsAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ExceptionsAttribute();

    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// numero de exceções
    u2 num_exceptions;
    /// table of indexes in the constant pool to CONSTANT_Class_info
    std::vector<u2> exception_index_table;
};

///@}

class StackMapAttribute : public Attribute {
  public:
    /// construtor
    StackMapAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~StackMapAttribute();
    
    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /**
     * @brief le pilha de frames???
     *
     * @param fp - referencia para o arquivo fonte
     */
    void readStackMapFrame(FILE* fp);
    /// numero de entradas do frame
    u2 num_entries;
    /// @see StackMapFrame
    StackMapFrame** entries;
};

/** Array de inner classes*/
class InnerClassesAttribute : public Attribute {
  public:
    /// construtor
    InnerClassesAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~InnerClassesAttribute();
    
    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /**
     * @brief Adiciona as classes internas ao vetor de classes
     * @param c- classe a ser adicionada ao vetor classes. @see Classes
     * retorno void
     */
    void AddClasses(Classes* c);
    /// numero de classes
    u2 num_classes;
    /// array de classes. @see Classes
    std::vector<Classes*> classes;
};

/** Atributo de Assinatura*/
class SignatureAttribute : public Attribute {
  public:
    /// construtor
    SignatureAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~SignatureAttribute();
    
    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// assinatura
    u2 signature;
};

/** Atributo Valor Constante*/
class ConstantValueAttribute : public Attribute {
  public:
    /// construtor
    ConstantValueAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ConstantValueAttribute();
    
    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// Index na constant pool para o Cnstant Value
    u2 constantValue;
};

/**Exceções que um metodo pode lançar (throw)*/
class ExceptionsAttribute : public Attribute {
  public:
    /// construtor
    ExceptionsAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ExceptionsAttribute();

    /// print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    /// numero de exceções
    u2 num_exceptions;
    /// table of indexes in the constant pool to CONSTANT_Class_info
    std::vector<u2> exception_index_table;
};

///@}

#endif
