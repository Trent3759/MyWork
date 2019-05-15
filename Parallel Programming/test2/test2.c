#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//	Trenton Scott
//	
//



int * NUMS_ARRAY[100000];
void Get_args(int argc, char* argv[]);


int sumTotal(fileSize){
	long sum = 0;
	for (long y = 0; y < fileSize; y++) sum += NUMS_ARRAY[y];
	printf("%l", sum);
}


int findlen(char* fname) {
  //Returns the number of integers in the file fname
  FILE* f;
  int x;  //Variable to receive numbers read from the file
  int n = 0;  //Variable to count numbers in the file
  
  f = fopen(fname, "r");
  while (fscanf(f, "%d", &x) > 0) n++;
  fclose(f);
  //printf("Findlen returns %d\n", n);
  return n;
}

int readfile(char fname[], int nums[]) {
  FILE* f;
  int i;  //Loop index
  f = fopen(fname, "r");
  i = 0;
  while (fscanf(f, "%d", &nums[i]) > 0) {
    i++;
  }
  fclose(f);
  return i;
}


int main(int argc, char** argv) {
  char fname[] = "randnums.txt";
  int global_n; //Number of numbers in file

  long thread;
  pthread_t * thread_handles;
  
  int thread_count;
  thread_count = strtol(argv[1], NULL, 10);
  
  thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t));

  int i;  //Loop index
  int total = 0;  //Accumulates sum
  double start_time, end_time; //Used for timing
  
  int fileSize = findlen(fname);
  
  readfile(fname, &NUMS_ARRAY);
  
  for (thread = 0; thread < thread_count; thread++)
	  pthread_create(&thread_handles[thread], NULL, sumTotal, (void*)thread);  

  for (thread = 0; thread < thread_count; thread++) 
	  pthread_join(thread_handles[thread], NULL); 
  
  long sumation = sumTotal(fileSize);
  
  printf("%i", sumation);
  return 0;
}


