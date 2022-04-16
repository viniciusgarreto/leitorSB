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

#ifndef printer_h
#define printer_h
/**
* @file printer.h
* @brief Imprime o conteúdo do arquivo .class.
*/
/**
  * @brief Função de exibir o conteúdo do arquivo .class.
  * @param class_file - referencia para o arquivo .class
  */
void imprimirArquivo(ClassFile *class_file, ostream& output = cout);

#endif
