#ifndef attribute_h
#define attribute_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Classes.h"
#include "../headers/LineNumberTable.h"

class Attribute {
  public:
    Attribute(u2 attbName, u4 attbLength);
    ~Attribute();
    static Attribute* readAttribute(FILE* fp, ConstantPool& cp);
    void printAttribute(ConstantPool& cp, unsigned int indent = 0);

  protected:
    u2 attribute_name;
    u4 attribute_length;
    void *info;
};

class ExceptionsAttribute;

class SourceFileAttribute : public Attribute {
  public:
    SourceFileAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~SourceFileAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    u2 source_file;
};

class CodeAttribute : public Attribute {
  public:
    CodeAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~CodeAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    void AddAttribute(Attribute* interface);

    u2 max_locals;
    u2 max_stack;
    u4 code_length;
    u1 *code;

    u2 attributes_count;
    std::vector<Attribute*> attributes;

    u2 exception_info_length;
    ExceptionsAttribute* ex_info;
    
    /* Exception_info *ex_info; */
};

class LineNumberTableAttribute : public Attribute {
  public:
    LineNumberTableAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~LineNumberTableAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    void AddLineNumberTable(LineNumberTable* table);

    u2 line_number_table_length;
    std::vector<LineNumberTable*> line_number_table;
};

class StackMapAttribute : public Attribute {
  public:
    StackMapAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~StackMapAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    void readStackMapFrame(FILE* fp);

    u2 num_entries;
    std::vector<Attribute*> attributes;
};

class InnerClassesAttribute : public Attribute {
  public:
    InnerClassesAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~InnerClassesAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    void AddClasses(Classes* c);

    u2 num_classes;
    std::vector<Classes*> classes;
};

class SignatureAttribute : public Attribute {
  public:
    SignatureAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~SignatureAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    u2 signature;
};

class ConstantValueAttribute : public Attribute {
  public:
    ConstantValueAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~ConstantValueAttribute();
    void printAttribute(ConstantPool& cp, unsigned int indent);

  private:
    u2 constantValue;
};

class ExceptionsAttribute : public Attribute {
  public:
    ExceptionsAttribute(FILE* fp, ConstantPool& cp, u2 attbName, u4 attbLength);
    ~ExceptionsAttribute();
    void printAttribute(ConstantPool& cp,  unsigned int indent);

  private:
    u2 num_exceptions;
    u2* exceptions;
};



#endif
