#include "seventh.h"

int main(int argc, char** argv){
  int i, len;
  char *word;

  for(i = 1; i < argc; i++){
    word = argv[i];
    len = strlen(word);
    printf("%c", argv[i][len-1]);
  }
  printf("\n");
  return 0;

}
