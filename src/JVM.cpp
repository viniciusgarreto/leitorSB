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

#include "../headers/JVM.h"
#include "../headers/Frame.h"
#include <climits>
#include <string>

JVM* JVM::instance = nullptr;

JVM::JVM() {
  this->frame_stack = new StackFrame();

  this->pc = 0;
  this->exception = 0;
  this->exception_name = string("");
}

JVM::~JVM() {
  delete this->frame_stack;
  for (auto classFile : this->classes)
    delete classFile;
  this->classes.clear();
  this->objects.clear();
}

JVM& JVM::getInstance() {
  if (JVM::instance == nullptr) {
    // cout << "instantiating new JVM instance";
    JVM::instance = new JVM();
  }

  return *JVM::instance;
}
void JVM::removeInstance() {
  delete JVM::instance;
}

void JVM::ReadClassFile(string classfile_name) {
  this->classes.push_back(ClassFile::lerArquivo(classfile_name));
}

ClassFile& JVM::getClassFileByName(string classfile_name) {
  for (auto classFile : this->classes)
  if (classfile_name == classFile->getName())
    return *classFile;

  cout << "ERROR: tried to search for class \"" << classfile_name << "\" but couldn't find a match";
  exit(1);
}


void JVM::execute() {
  if (this->classes.empty()) {
    cout << "[ERROR] tried to execute jvm, but no classfiles loaded" << endl;
    exit(1);
  }

  // class being executed
  auto exec_class = this->classes.at(0);

  // execute clint and main methods, if they exist.
  auto clInit = exec_class->getCLinit();
  if (clInit) clInit->execute(*this, *exec_class, true);

  auto main = exec_class->getMain();
  if (main) main->execute(*this, *exec_class, true);

  if (!main && !clInit) {
    cout << "[ERROR] tried to execute jvm, but loaded class has no clinit or main method" << endl;
    exit(1);
  }
}

void JVM::pushFrame(ClassFile& current_class, u2 max_locals) {
  this->frame_stack->pushFrame(new Frame(current_class, max_locals));
}

u2 JVM::findHandlerMethod(Method& method) {
	// Procurar no método corrente se existe um handler para a exceção que foi lançada
	auto classeAtual = this->getClassFileByName(this->frame_stack->topFrame()->getClassName());
  auto code = method.getCodeAttb(classeAtual.getConstantPool());

  // auto* auxmetodo;

  Frame* curFrame;
	while (nullptr != (curFrame = this->frame_stack->topFrame())) {
    for (auto except : code->getExceptionTable()){
      auto nomeexcecao = classeAtual.getConstantPool().getValueUTF8String(except->catch_type);
      if (nomeexcecao == this->exception_name)
        return except->handler_pc;
    }

		// Se não encontrar o handler, pop o frameatual
    this->frame_stack->popFrame();
	}

	// Retornar USHRT_MAX para indicar que o handler não foi encontrado
	return USHRT_MAX;
}
