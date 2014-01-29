// Bubble Sort, Selection Sort, Quick Sort

#include<iostream>
#include<conio.h>

using namespace std;

const int MAX = 8;	// size of the array to be used

class sort{

	// declaring array
	int count;
	int a[MAX] = {9,800,909,21,8,499,4,99};
	int b[MAX] = {22,4,88,999,9,66,909,89};
	int c[MAX] = {21,2,999,90,75,199,49,500};
	
 	public :
		
		void display(int *arr){
			
			cout << endl;
			
			for (int i = 0; i < MAX; i++)
				cout << arr[i] << "\t";
			
		}
		
		void bubblesort(){
			
			cout << "\nOriginal array\n";
			display(a);
			
			for (int i = 0; i < MAX; i++)
				for(int j = 0; j < MAX-i-1; j++){
					
					// this will sort array in ascending order
					if(a[j] > a[j+1]){
						
						int tmp = a[j];
						a[j] = a[j+1];
						a[j+1] = tmp;
						
					}
					
				}
				
			cout << "\nSorted array through bubble sort\n";
			display(a);
				
		}
		
		void selectionsort(){
			
			cout << "\nOriginal array\n";
			display(b);
			
			for (int i = 0; i < MAX; i++)
				for (int j = i; j < MAX; j++){
					
					if (b[i] > b[j]){
						
						int tmp = b[i];
						b[i] = b[j];
						b[j] = tmp;
						
					}
					
				}
				
			cout << "\nSorted array through selection sort\n";
			display(b);
			
		}
		
		void quicksort(int lower, int upper){
			
			if (lower < upper){
				
				int i = split(c, lower, upper);
				quicksort(lower, i-1);
				quicksort(i+1, upper);
				
			}
			
		}
		
		int split(int *arr, int lower, int upper){
			
			int i, p, q, t;
			
			p = lower+1;
			q = upper;
			i = arr[lower];
			
			while (q >= p){
				
				while (arr[p] < i)
					p++;
				
				while (arr[q] > i)
					q--;
				
				if (q > p){
					
					t = arr[lower];
					arr[lower] = arr[q];
					arr[q] = t;
					
				}
				
			}
			
			t = arr[lower];
			arr[lower] = arr[q];
			arr[q] = t;
			
			return q;
			
		}
		
		void displayquicksort(){
			
			display(c);
			
		}
};

int main(){
    
	sort b;
	
	b.bubblesort();
	b.selectionsort();
	
	cout << "\nOriginal array\n";
	b.displayquicksort();
	b.quicksort(0,MAX);
	cout << "\nSorted array through quick sort\n";
	b.displayquicksort();
	
    getch();
    return 0;
    
}
