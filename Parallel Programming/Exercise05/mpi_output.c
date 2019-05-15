/* Illustrates nondeterministic output */
#include <stdio.h>
#include <string.h>
#include <mpi.h>


const int MAX_STRING = 100;  //Max length of string


int main(void) {
  char greeting[MAX_STRING];
  int my_rank, comm_sz, q;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  
  if (my_rank != 0) {
    sprintf(greeting, "Proc %d of %d > Does anybody really know what time it is? Does anybody really care?", my_rank, comm_sz);
    MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  } else {
    printf("Proc %d of %d > Does anybody really know what time it is? Does anybody really care?\n", my_rank, comm_sz);
    for (q = 1; q < comm_sz; q++) {
      MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE); //Receive msg from process
      printf("%s\n", greeting);
    }
  }
  
  MPI_Finalize();
  return 0;
}

