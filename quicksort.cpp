// **** Quick sort ****

// Author : Punit Sharma
// Dated : 2/17/2014

#include<iostream>

using namespace std;

#define MAX 10 // size of array

void display(int* a, int);
void quicksort(int*, int, int);
int partition(int*, int, int);

void quicksort(int* arr, int lower, int upper){ // lower & upper are indexes of original array 
												// maintained during recursion. These are indexes we'll deal with
												// while dealing with parts of array during recursion.
	
	if(lower < upper){
		
		int pindex = partition(arr, lower, upper);	// pindex is the index of the element, for which all elements lower than this
													// element are shifted to its left and higher than this are shifted to its right
													// in original array.
		quicksort(arr, lower, pindex-1);
		quicksort(arr, pindex+1, upper);
		
	}
	
}

int partition(int* a, int start, int end){
	
	int pivot = a[end];		// randomly any element selected for which elements lower and higher 
							// than this will be arranged at its left and right respectively.
	int pindex = start;	
	
	for (int i=start; i<end; i++){
		
		// arranging elements lower than pivot at leftmost indexes in array
		if(a[i] <= pivot){
			
			int tmp = a[i];
			a[i] = a[pindex];
			a[pindex] = tmp;
			
			pindex++;
			
		}
		
	}
	
	// when all elements lower than pivot are at left most indexes than swapping current "pindex" value with pivot.
	int ptmp = a[end];
	a[end] = a[pindex];
	a[pindex] = ptmp;
	
	return pindex;
	
}

void display(int* a, int size){
		
	cout << endl;
	for (int i=0; i<size; i++)
		cout << a[i] << "\t";
	
	cout << endl;
		
}

int main(){
	
	int B[] = {99,19,999,199,9,909,89,599,899,299};
	
	cout << "Original array :\n";
	display(B, MAX);
	quicksort(B, 0, MAX-1);
	cout << "Array sorted through quicksort:\n";
	display(B, MAX);
	
}
