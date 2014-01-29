// Binary search

#include<iostream>
#include<conio.h>

using namespace std;

const int MAX = 11;	// size of the array to be used

class binsearch{

	// variables for maintaining index of array which will help in search
	int a[MAX], upper, lower, mid, count;
	bool found;
	
	public :
		
		// initializing array to 0
		binsearch(){
			
			for (int i = 0; i < MAX; i++)
				a[i] = 0;
			
			count = 0;
			
		}
		
		// function to add to the array
		void add(int num){
			
			if (count < MAX){
				
				a[count] = num;
				count++;
				
			}
			else
				cout << "\nArray is full.\n";
				
			
		}
		
		void display(){
			
			for (int i = 0; i < MAX; i++)
				cout << a[i] << "\t";
			
		}
		
		void binarysearch(int num){
			
			int i=0;
			upper = MAX;
			lower = count = 0;
			mid = MAX/2;
			found = false;
			
			cout << "\nBinary search says :\n";
			
			while (i < MAX){
				
				if (num == a[mid]){
					
					found = true;
					break;
					
				}
					
				else{
					
					if (num < a[mid] )
						upper = mid;	// setting upper if number is less than middle value
					else
						lower = mid;	// setting lower if number is greater than middle value
						
					mid = (lower + upper) / 2;
					i++;
						
				}
					
			}
			
			if (found)
				cout << "\n" << num << " is at " << mid + 1 << " position in array\n";
			else
				cout << "\n" << num << " not found\n";
				
		}

};

int main(){
    
	binsearch bs;
	
	bs.add(9);
	bs.add(19);
	bs.add(89);
	bs.add(99);
	bs.add(109);
	bs.add(129);
	bs.add(229);
	bs.add(289);
	bs.add(889);
	bs.add(899);
	bs.add(998);
	
	bs.display();
	bs.binarysearch(899);
	bs.binarysearch(19);
	bs.binarysearch(900);

    getch();
    return 0;
    
}
