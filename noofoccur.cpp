// finding number of occurrences of numbers appearing more than once in an array

#include<iostream>
#include<stdlib.h>

using namespace std;

#define MAX 8

void display(int* a){

	int i = 0;

	cout << endl;
	while(i < MAX){

		cout << a[i] << "  ";
		i++;

	}

	cout << endl;

}

void finddups(int* a){

	int dups[MAX/2];	// array to maintain numbers appearing more than once
	int  dupfound, dupcount, dupindex;

	// index of dups array which increments every time when a number found is occurring more
	// than once and is not in dups array.
	dupcount = 0;
	// last index of number in original array which has more than one occurrence in original array
	dupindex = 0;

	for(int i = 0; i < MAX; i++){

		dupfound = 0;

		// checking is number is there in dups array
		for (int p = 0; p < MAX/2; p++){

			if(a[i] == dups[p])
				dupfound = 1;

		}

		if(dupfound == 0){

			int count = 0; // number of occurrences of a number
			for(int j = 0; j < MAX; j++){

				if (a[i] == a[j]){

					count++;
					dupindex = i;

				}

			}

			if (count != 1){

				// saving number appearing more than once in dups array
				dups[dupcount] = a[dupindex];
				dupcount++;
				cout << endl << a[i] << " occurs " << count << " times" << endl;

			}

		}

	}

}

int main(){

	int arr1[MAX] = {9,4,22,6,22,9,89,22};

	display(arr1);
	finddups(arr1);

	return 0;

}
