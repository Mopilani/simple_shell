#include "main.h"

int main(int ac, char **argv){
  char *prompt = "(Eshell) $ ";
  char *lineptr;
  size_t n = 0; 

  printf("%s", prompt);
  getline(&lineptr, &n, stdin);

  free(lineptr);
  return (0);
}
