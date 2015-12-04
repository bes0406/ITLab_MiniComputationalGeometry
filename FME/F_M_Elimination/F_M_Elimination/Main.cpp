#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;



/* Functions that initializes the matrix A and vector b  */
int ** create_a(int col, int rows);
int* create_b(int rows);
void printResult(int ** a, int * b, int numrows, int numcols);
/* It is reasonable to move the computational part into a separate functions that takes A, b and the index of variable to eliminate and returnes newA, newB */
void Calculating_new_system(int **&old, int *&b,int index_to_eliminate, int &numrows, int numcol);

int main (int argc, char *argv[]){
	srand(time(NULL));
	int numVariables , numRows, choice;
	cout << " Test with random numbers (press 1). "<<'\n'
		 <<"Fill the variables manually (press 2) \n";
	cin>> choice;
	cout<< "Enter Total number of inequalities and number of variables "<<'\n';
	cin>> numRows;
	cin>> numVariables;
	int** A = new int* [numRows];
	int* b = new int[numRows];
	if (choice == 1){
		A = create_a(numVariables, numRows);
		b = create_b(numRows);
		for (int i = 0; i < numRows; i++){
			for(int j = 0; j < numVariables; j++){
				cout <<setw(4)<<A[i][j];
			}
			cout <<setw(4)<<b[i]<<'\n';
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i<numRows; i++){
			A[i] = new int[numVariables];
		}
		for (int i = 0; i<numRows; i++){
			for(int j=0; j<numVariables; j++){
				cin>>A[i][j];
			}
			cin>>b[i];
		}
	}

	int element_to_eliminate;
	cout << "Eenter index of element to eliminate"<<'\n';
	cin>> element_to_eliminate;
	Calculating_new_system(A,b,element_to_eliminate,numRows,numVariables);    //all computations here
	printResult(A, b, numRows, numVariables);
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
void printResult(int ** a, int * b, int numrows, int numcols) {
	for (int i = 0; i < numrows; i++) {
		for (int j = 0; j < numcols; j++)
			cout << a[i][j] << " ";
		cout << " | " << b[i] << endl;
	}
}
void Calculating_new_system(int **&old, int *&b,int index_to_eliminate, int &numrows, int numcol){
	int * positiveRows = new int[numrows];
	int * negativeRows = new int[numrows];
	int * zeroRows = new int[numrows];
	int numPositiveRows = 0, numNegativeRows = 0, numZeroRows = 0;
	// classify into positive, negative, zero
	for (int i = 0; i < numrows ; i ++)
		if(old[i][index_to_eliminate]>0)
			positiveRows[numPositiveRows++] = i;
		else if (old[i][index_to_eliminate] < 0)
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
		int NegCoff = -old[negativeRows[i]][index_to_eliminate]; 
		for(int j=0; j< numPositiveRows; j++){ 
			int PosCoff = old[positiveRows[j]][index_to_eliminate];
			for(int k =0; k<numcol; k++){ 
				newA[rw][k] = PosCoff * old[negativeRows[i]][k] +
					          NegCoff * old[positiveRows[j]][k];
			}
			newB[rw] = PosCoff * b[negativeRows[i]] + NegCoff * b[positiveRows[j]];
			rw++;
		}
	}
	
	//copy zero rows from A to newA and b to newB
	int a=0;
	for( int i = rw; i < newNumRows; i++){
		for (int j =0; j<numcol; j++){
			newA[i][j] = old[zeroRows[a]][j];
		}
		newB[i] = zeroRows[a];
		a++;
	}
	
	//reset memory
	for (int i = 0; i < newNumRows; i++){ //deleting old memory
		delete [] old[i];
	}
	delete []old;
	delete [] b;
	old = newA;
	b = newB;
	numrows = newNumRows;
}
