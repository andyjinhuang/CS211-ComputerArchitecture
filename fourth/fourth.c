#include "fourth.h"

int main(int argc, char** argv){
  if (argc != 2){
    printf("error\n");
    return 0;
  }

  FILE *file = fopen(argv[1], "r");
  int row, col;
  int i, j;

  if(file == NULL){
    printf("error\n");
    return 0;
  }

  fscanf(file, "%d %d", &row, &col);
    
    if(row == 0 || col == 0){
        printf("error\n");
        return 0;
    }
  int matrix1[100][100];

  /*first matrix*/
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      fscanf(file, "%d", &matrix1[i][j]);
    }
    fscanf(file, "\n");
  }

  /*adding numbers of second matrix in*/
  int value;
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      fscanf(file, "%d", &value);
      value = (int) value + matrix1[i][j];
      matrix1[i][j] = value;
    }
    fscanf(file, "\n");
  }

  /*prints matrix*/  
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      printf ("%d\t", matrix1[i][j]);
    }
    printf("\n");
   }

  return 0;
}
