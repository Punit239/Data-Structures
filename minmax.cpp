// Finding min and max in a range of an array

#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX 40

void createarr(int*);
void display(int*);
void displayrange(int*,int, int);
void findmaxmininrange(int*,int,int);

void createarr(int* a){

	int i = 0;
	while(i < MAX){

		a[i] = rand() % 100 + 1;
		i++;

	}

}

void display(int* a){

	int i = 0;

	cout << endl;
	while(i < MAX){

		cout << a[i] << "  ";
		i++;

	}

	cout << endl;

}

void displayrange(int *a,int start,int end){

	for(int i = start-1; i <=end-1; i++)
		cout << a[i] << "  ";

}

void findmaxmininrange(int *a,int start,int end){

	int arrmax = a[start-1];
	int arrmin = a[start-1];

	// finding maximum in range

	for (int i = start-1; i < end-1; i++){

		if(arrmax <= a[i+1]){

			arrmax = a[i+1];

		}

	}

	cout << "\nGiven range is :\n";
	displayrange(a, start, end);
	cout << "\nMax in given range is : " << arrmax << "\n";

	// finding minimum in range

	for (int i = start-1; i < end-1; i++){

		if(arrmin >= a[i+1]){

			arrmin = a[i+1];

		}

	}

	cout << "\nMin in given range is : " << arrmin << "\n";

}

int main(){

	int arr[MAX];

	createarr(arr);
	cout << "\nGiven array is :\n";
	display(arr);

	findmaxmininrange(arr,10, 19);

	return 0;

}
