// Palindrome

// Author	: Punit Sharma
// Date		: 2/18/2014

#include<iostream>

using namespace std;

void display(char*);
void palindrome(char*);
int sizearr(char*);

void palindrome(char* arr){
	
	int i = sizearr(arr);
	int mid = i/2;		// finding middle index value to comapre array elements, starting with comparing
						// the first and last element, second and second last and so on till middle value is reached.
	bool palin = true;
	
	for(int j=0; j<mid; j++){
		
		if(arr[j] != arr[i-1-j]){	// comparing the first and last element, second and 
									// second last and so on till middle value is reached.
			
			palin = false;
			break;
			
		}
		
	}
	
	display(arr);
	if(palin)
		cout << "is a plaindrome\n";
	else
		cout << "is a not plaindrome\n";
	
}

int sizearr(char* arr){
	
	int i = 0;
	while(arr[i] != '\0')
		i++;
	
	return i;
	
}

void display(char* arr){
	
	int i = 0;
	
	cout << endl;
	while (arr[i] != '\0'){
		
		cout << arr[i];
		i++;
		
	}
	cout << endl;
		
}

int main(){
	
	char B[] = "punitsharma";
	char A[] = "aabbpbbaa";
	char C[] = "aabbppbbaa";
	
	palindrome(B);
	palindrome(A);
	palindrome(C);
	
}
