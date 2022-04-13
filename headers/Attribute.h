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

class Attribute {
  public:
    Attribute(u2 attbName, u4 attbLength);
    ~Attribute();
    static Attribute* readAttribute(FILE* fp, ConstantPool& cp);

    string getName(ConstantPool& cp);

    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 attribute_name;
    u4 attribute_length;
    void *info;
};

class ExceptionsAttribute;

class SourceFileAttribute : public Attribute {
  public:
    SourceFileAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~SourceFileAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    u2 source_file;
};

class CodeAttribute : public Attribute {
  public:
    CodeAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~CodeAttribute();
    
    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

    // the method that actually interprets the code.
    void interpret(JVM& jvm, Method& method);

    u2 max_locals;

  private:
    void AddAttribute(Attribute* interface);
    void AddExceptionTable(ExceptionTable* table);

    u2 max_stack;
    u4 code_length;
    u1 *code;

    u2 attributes_count;
    std::vector<Attribute*> attributes;

    u2 exception_info_length;
    std::vector<ExceptionTable*> exception_table;
};

class LineNumberTableAttribute : public Attribute {
  public:
    LineNumberTableAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~LineNumberTableAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    void AddLineNumberTable(LineNumberTable* table);

    u2 line_number_table_length;
    std::vector<LineNumberTable*> line_number_table;
};

class StackMapAttribute : public Attribute {
  public:
    StackMapAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~StackMapAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    void readStackMapFrame(FILE* fp);

    u2 num_entries;
    StackMapFrame** entries;
};

class InnerClassesAttribute : public Attribute {
  public:
    InnerClassesAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~InnerClassesAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    void AddClasses(Classes* c);

    u2 num_classes;
    std::vector<Classes*> classes;
};

class SignatureAttribute : public Attribute {
  public:
    SignatureAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~SignatureAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    u2 signature;
};

class ConstantValueAttribute : public Attribute {
  public:
    ConstantValueAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ConstantValueAttribute();
    
    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  private:
    u2 constantValue;
};

class ExceptionsAttribute : public Attribute {
  public:
    ExceptionsAttribute(FILE* fp, u2 attbName, u4 attbLength);
    ~ExceptionsAttribute();

    // print methods
    ostream& print(ConstantPool& cp, unsigned int indent = 0, ostream& output = cout) const;

  private:
    u2 num_exceptions;
    std::vector<u2> exception_index_table;
};



#endif
