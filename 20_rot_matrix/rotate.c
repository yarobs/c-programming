#include <stdio.h>

void rotate(char matrix[10][10]) {
  char temp_mtx[10][10];

  for (int i=0, j=0; i < 10; i++) {
    for (j=0; j < 10; j++) {
      //printf("Rotating %c: [%d][%d] to [%d][%d]\n", matrix[9-j][i], i, j, 9-j, i);
      temp_mtx[i][j] = matrix[9-j][i];
    }
    temp_mtx[i][j] = '\0';
  }

  for (int i=0, j; i<10; i++) {
    for (j=0; j<10; j++) {
      matrix[i][j] = temp_mtx[i][j];
    }
  }
  return;
}
