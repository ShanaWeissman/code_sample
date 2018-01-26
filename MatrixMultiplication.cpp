#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int matrixMult(int n){
	clock_t start_time = clock ();

	//printf("%d \n", n);
	
	//create two nxn matrices
	/*int A[n][n];
	int B[n][n];
	int AB[n][n];
	*/
	int i, j, k;
	int **A = new int*[n];
	int **B = new int*[n];
	int **AB = new int*[n];
	
	for (i = 0; i<n; i++){
		A[i] = new int[n];
		B[i] = new int[n];
		AB[i] = new int[n];

		for(j=0; j<n; j++) {
			int r = rand() % 10;
			//printf("%d \n", r);
			A[i][j] = r;
			r = rand() % 10;
			B[i][j] = r;
		}
	}
	int entry = 0;
	int accumulate = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			entry = 0;
			accumulate = 0;
			for(k=0; k<n; k++) {
				accumulate = A[i][k] * B[k][j];
				entry = entry + accumulate;
			}
		AB[i][j] = entry;
		}
	}
	
	
	/*
	printf("A is a %d x %d matrix: ",n,n);
	for(i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			
			printf("%d ", A[i][j]);
		}
	}
	printf("\n");
	printf("B is a %d x %d matrix: ",n,n);
	for(i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			
			printf("%d ", B[i][j]);
		}
	}
	printf("\n");
	
		printf("\n");
	printf("AB is a %d x %d matrix: ",n,n);
	for(i=0; i<n; i++) {
		printf("\n");
		for(j=0; j<n; j++) {
			
			printf("%d ", AB[i][j]);
		}
	}
	printf("\n");
	*/
	for (i = 0; i<n; i++ ) {
      delete[] AB[i];
      delete[] B[i];
      delete[] A[i];
   }
   delete[] AB;
   delete[] B;
   delete[] A;
   
	//clock_t end_time = clock ();
	
	double total_time = (clock () - start_time) / (double) (CLOCKS_PER_SEC);
	printf("time: %f \n", total_time);
	return 0;
}
int main(int argc, char** argv){
	int n = atoi(argv[1]);

	matrixMult(n);


	return 0;
}




