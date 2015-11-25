#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


/* I think it is better to make a function that initializes the matrix A and vector b (at first hardcoded as this is at main() */

/* It is reasonable to move the computational part into a separate functions that takes A, b and the index of variable to eliminate and returnes newA, newB */

int main (int argc, char *argv[]){

	/* Need to use dynamic arrays instead of static (like you do for newA, newB) */
	int numRows;
	cin>> numRows;
	cin>> numVariables;
	int** A = new int* [numRows];
	for (int i = 0; i<numRows; i++){
		A[i] = new int[numVariables];
	}
	for (int i = 0; i<numRows; i++){
		for(int j=0; j<numVariables; j++){
			A[i][j]=rand()% (20 + (-10));      //rand()% (high - low) + low
		}
	}
	int* b = new int[numRows];
	for (int i = 0; i<numRows; i++){
		b[i]=rand()%10;
	}
	int * positiveRows = new int[numRows];
	int * negativeRows = new int[numRows];
	int * zeroRows = new int[numRows];
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < numRows ; i ++)
		if(A[i][1]>0)
			positiveRows[numPositiveRows++] = i;
		else if (A[i][1] < 0)
			negativeRows[numNegativeRows++] = i;
		else
			zeroRows[numZeroRows++] = i;

	int newNumRows = numPositiveRows * numNegativeRows + numZeroRows;
	int ** newA = new int*[newNumRows];
	int * newB = new int[newNumRows];
	for (int i = 0; i < newNumRows; i++){
		newA[i] = new int[numVariables];
	}
	int rw =0;
	//Combinations  of positive & negative rows ( copied to newA and newB)
	for(int i=0; i< numNegativeRows ; i++){
		int HCF = (A[negativeRows[i]][1]*(-1)); 
		int mul = HCF *(A[positiveRows[i]][1]);
		for(int j=0; j< numPositiveRows; j++){ 
			for(int k =0; k<numVariables; k++){ /* Need to fix it: linear combinations need to be done on the whole row of A, not a single element of it */
				newA[rw][k] = (mul/A[negativeRows[i]][1])*(A[negativeRows[i]][k]) + (mul/A[positiveRows[i]][1])*(A[positiveRows[i]][k]);
			}
			newB[rw]=(mul/A[negativeRows[i]][1])*(b[negativeRows[i]]) + (mul/A[positiveRows[0]][1])*(b[positiveRows[j]]);
			rw++;
			}
		}
	
	//copy zero rows from A to newA and b to newB
	int a=0, n =0 ;
	for( int i = rw; i < newNumRows; i++){
		for (int j =0; j<numVariables; j++){
			newA[i][j] = A[zeroRows[a]][j];
		}
		newB[i] = zeroRows[n];
        n++;
		a++;
	}

	//Free memory
	for (int i = 0; i < numRows; i++){
		delete [] A[i]
	}
	delete []A;
	for (int i = 0; i < newNumRows; i++){
		delete [] newA[i]
	}
	delete []A;
	delete []b;
	delete []newB;

	return 0;
}