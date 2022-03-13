int main(int argc, char *argv[])
{
  //Declara file
  char *file;

  //Faz alocação de memoria necessária para o file
  file = (char *)malloc(strlen(argv[1]) * sizeof(char));

  //Copia file do argumento para file do código
  strcpy(file, argv[1]);
}