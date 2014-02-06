// finding cow & bull
// bull is common number with same index in 2 given arrays
// cow is common number with different index in 2 given arrays

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

void bull(int* a1, int* a2){

	int i = 0;
	while (i < MAX){

		if(a1[i] == a2[i])
			cout << "\nBull is : " << a1[i] << endl;

		i++;

	}
}

void cow(int* a1, int* a2){

	for (int i = 0; i < MAX; i++)
		for (int j = i+1; j < MAX; j++){

			if(a1[i] == a2[j])
				cout << endl << "Cow is : " << a1[i] << endl;

		}

}

int main(){

	int arr1[MAX] = {3,4,22,6,99,9,89,21};
	int arr2[MAX] = {5,4,8,2,9,22,89,6};

	display(arr1);
	display(arr2);
	bull(arr1, arr2);
	cow(arr1, arr2);

	return 0;

}
