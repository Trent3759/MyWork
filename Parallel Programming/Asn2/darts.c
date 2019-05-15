#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

/****

Programmer Name: Trenton Scott
Course Code: CSC 338
Course Name: Parallel & Distributive Computing
Production Date: 10/19/2016


This program is used to estimate the value of pi. 

Compile using 'mpicc –g –Wall –o mpi_darts darts.c'
in the cygwin command line and navigated to the containing folder. 

To execute, type 'mpiexec –n 4 mpi_darts <amount of throws>'
where <amount of throws> is a long long int. 

****/


double randCoord(){
	double n, sign;
	sign = rand()/(double)RAND_MAX;
	if (sign > .5){
		n = (rand()/(double)RAND_MAX)-1;
	} else {
		n = (rand()/(double)RAND_MAX);
	}
	return n;
}


double throw(double darts){
	
	double x_coord, y_coord, pi, sqr; 
	long long score, toss;
	score = 0;
	
	
	
	for (toss = 0; toss <= darts; toss++)  {
		x_coord = randCoord();
		y_coord = randCoord();
		
		sqr = (x_coord * x_coord)+(y_coord * y_coord);
		
		if (sqr <= 1.0)
			score++;
		}

	pi = 4.0 * score /(double)darts;
	return(pi);
	
}

int main(int argc, char * argv[]) {
	long long global_n, local_n; 
	double local_pi, global_pi;
	int comm_sz, my_rank;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	srandom (my_rank);
	
	if (my_rank != 0){

		
		int i;
		
		local_pi = 0;
		
		MPI_Bcast(&local_n, 1, MPI_LONG, 0, 
				  MPI_COMM_WORLD);

	
		local_pi = throw(local_n);
		
		MPI_Reduce(&local_pi, &i, 1, MPI_DOUBLE,
				   MPI_SUM, 0, MPI_COMM_WORLD);
	} else {
		
		local_pi = 0;
		global_pi = 0;

		global_n = atoll(argv[1]);
		
		local_n = global_n/comm_sz;

		MPI_Bcast(&local_n, 1, MPI_DOUBLE, 0, 
				  MPI_COMM_WORLD);
				  
		//local_nums = malloc(local_n * sizeof(long long));
		
		local_pi = throw(local_n);
		
		MPI_Reduce(&local_pi, &global_pi, 1, 
				   MPI_DOUBLE, MPI_SUM, 0,
				   MPI_COMM_WORLD);
				   
		printf("Global sum: %10.8f\n", global_pi/comm_sz);
	}
	
	MPI_Finalize();
	return(0);
}