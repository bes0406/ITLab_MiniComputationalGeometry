#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;



/* I think it is better to make a function that initializes the matrix A and vector b (at first hardcoded as this is at main() */
int ** create_a(int col, int rows);
int* create_b(int rows);

/* It is reasonable to move the computational part into a separate functions that takes A, b and the index of variable to eliminate and returnes newA, newB */
void Calculating_new_system(int **old, int *b,int index_to_eliminate, int numrows, int numcol);

int main (int argc, char *argv[]){
	srand(time(0));
	int numVariables , numRows, choice;
	cout << " Test with random numbers (press 1). "<<'\n'
		 <<"Fill the variables manually (press 2) \n";
	cin>> choice;
	cout<< "Enter number of variables and Total number of inequalities"<<'\n';
	cin>> numRows;
	cin>> numVariables;
	int** A = new int* [numRows];
	int* b = new int[numRows];
	if (choice == 1){
		A = create_a(numVariables, numRows);
		b = create_b(numRows);
	}
	else{
		for (int i = 0; i<numRows; i++){
			A[i] = new int[numVariables];
		}
		for (int i = 0; i<numRows; i++){
			for(int j=0; j<numVariables; j++){
				cin>>A[i][j];
			}
		}
		for (int i = 0; i<numRows; i++){
			cin>>b[i];
		}
	}
	int element_to_eliminate;
	cin>> element_to_eliminate;
	Calculating_new_system(A,b,element_to_eliminate,numRows, numVariables);    //all computations here

	//Free memory
	for (int i = 0; i < numRows; i++){
		delete [] A[i];
	}
	delete []A;
	delete []b;
	

	return 0;
}

int* create_b(int rows){
	int *arr= new int[rows];
	for (int i = 0; i<rows; i++){
		arr[i] = rand()%10;
		}
	return arr;
}

int ** create_a(int col, int rows){
	int **arr = new int*[rows];
	for (int i = 0; i<rows; i++){
		arr[i] = new int[col];
	}
	for (int i = 0; i<rows; i++){
		for(int j = 0; j<col; j++){
			arr[i][j] = rand()% (20 + (-10));      //rand()% (high - low) + low
		}
	}
	return arr;
}
void Calculating_new_system(int **old, int *b,int index_to_eliminate, int numrows, int numcol){
	int * positiveRows = new int[numrows];
	int * negativeRows = new int[numrows];
	int * zeroRows = new int[numrows];
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < numrows ; i ++)
		if(old[i][1]>0)
			positiveRows[numPositiveRows++] = i;
		else if (old[i][1] < 0)
			negativeRows[numNegativeRows++] = i;
		else
			zeroRows[numZeroRows++] = i;

	int newNumRows = numPositiveRows * numNegativeRows + numZeroRows;
	int ** newA = new int*[newNumRows];
	int * newB = new int[newNumRows];
	for (int i = 0; i < newNumRows; i++){
		newA[i] = new int[numcol];
	}
	int rw =0;
	//Combinations  of positive & negative rows ( copied to newA and newB)
	for(int i=0; i< numNegativeRows ; i++){
		int HCF = (old[negativeRows[i]][1]*(-1)); 
		int mul = HCF *(old[positiveRows[i]][index_to_eliminate]);
		for(int j=0; j< numPositiveRows; j++){ 
			for(int k =0; k<numcol; k++){ 
				newA[rw][k] = (mul/old[negativeRows[i]][index_to_eliminate])*(old[negativeRows[i]][k]) + (mul/old[positiveRows[i]][1])*(old[positiveRows[i]][k]);
			}
			newB[rw]=(mul/old[negativeRows[i]][index_to_eliminate])*(b[negativeRows[i]]) + (mul/old[positiveRows[0]][1])*(b[positiveRows[j]]);
			rw++;
		}
	}
	
	//copy zero rows from A to newA and b to newB
	int a=0, n =0 ;
	for( int i = rw; i < newNumRows; i++){
		for (int j =0; j<numcol; j++){
			newA[i][j] = old[zeroRows[a]][j];
		}
		newB[i] = zeroRows[n];
        n++;
		a++;
	}
	// TODO: Copy all the elements (from NewA to A) and ( from NewB to b) . 
	for (int i = 0; i < newNumRows; i++){
		delete [] newA[i];
	}
	delete []newA;
	delete []newB;

}
