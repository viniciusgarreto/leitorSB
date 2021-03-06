#include "../headers/JVM.h"
#include "../headers/ClassFile.h"
#include "../headers/printer.h"
#include "../headers/Instructions.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

string readMode = string("read");
string execMode = string("exec");

int main(int argc, char *argv[]) {

  if (argc < 3) {
    cout << "Incorrect use of the program. Either call:" << endl
      << "\t - \"" << argv[0] << " read fileName.java [output_file_name]\", to read and print the file" << endl
      << "\t - \"" << argv[0] << " exec fileName.java, to read and execute the file" << endl
      << endl
    ;
    return 1;
  }

  // get mode to run
  string mode(argv[1]);

  // if read mode
  if (mode == readMode) {
    string javaclass_filename(argv[2]);
    
    // read file
    ClassFile* class_file = ClassFile::lerArquivo(javaclass_filename);

    // if printing to console
    if (argc == 3) {
      cout << endl << "Printing classfile \"" << javaclass_filename << "\" to console." << endl << endl;
      imprimirArquivo(class_file, cout);

    // if printing to file
    } else {
      string output_filename(argv[3]);
      ofstream output_file(output_filename);
      cout << endl << "Printing classfile \"" << javaclass_filename << "\" to output file \"" << output_filename << "\" ." << endl << endl;
      imprimirArquivo(class_file, output_file);
      output_file.close();
    }

    delete class_file;
    return 0;
  }

  // if exec mode
  if (mode == execMode) {
    // get command argument
    string filename(argv[1]);

    // initialize JVM
    auto jvm = new JVM();

    // read file
    jvm->ReadClassFile(filename);

    // execute JVM
    jvm->execute();

    JVM::removeInstance();
    return 0;
  }

  // if invalid mode
  cout << "ERROR INVALID MODE SUPPLIED. USAGE GUIDE BELOW." << endl;
  cout << "Incorrect use of the program. Either call:" << endl
    << "\t - \"" << argv[0] << " read fileName.java [output_file_name]\", to read and print the file" << endl
    << "\t - \"" << argv[0] << " exec fileName.java, to read and execute the file" << endl
    << endl
  ;
  return 1;
}
