#include "fifth.h"

int main(int argc, char** argv){
  if (argc != 2){
    printf("error\n");
    return 0;
  }

  FILE *file = fopen(argv[1], "r");
  int row1, col1, row2, col2;
  int i, j, k, value = 0;

  if(file == NULL){
    printf("error\n");
    return 0;
  }

  fscanf(file, "%d %d", &row1, &col1);
  int matrix1[100][100];
  int matrix2[100][100];
  int resultant[100][100];

  /*first matrix*/
  for(i = 0; i < row1; i++){
    for(j = 0; j < col1; j++){
      fscanf(file, "%d", &matrix1[i][j]);
    }
    fscanf(file, "\n");
  }

  /*second matrix*/
  fscanf(file, "%d %d", &row2, &col2);
  for(i = 0; i < row2; i++){
    for(j = 0; j < col2; j++){
      fscanf(file, "%d", &matrix2[i][j]);
    }
    fscanf(file, "\n");
  }

  /*resultant matrix*/
  for(i = 0; i < row1; i++){
    for(j = 0; j < col2; j++){
      for(k = 0; k < row2; k++){
	value = value + matrix1[i][k] * matrix2[k][j];
      }
      resultant[i][j] = value;
      value = 0;
    }
  }

  /*prints matrix*/
  for(i = 0; i < row1; i++){
    for(j = 0; j < col2; j++){
      printf ("%d\t", resultant[i][j]);
    }
    printf("\n");
  }

  return 0;
}
