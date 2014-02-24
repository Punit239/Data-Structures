// Removing duplicates from linked list

// Author	: Punit Sharma
// Date		: 2/24/2014

#include<iostream>

using namespace std;

void append(int);

struct node{
	
	int data;
	node* next;
	
}*root = NULL;

void append(int num){
	
	node *n;
	
	node *t = new node;
	t -> data = num;
	t -> next = NULL;
	
	if (root == NULL){ 	// for creating the root node
		
		root = t;
		return;
		
	}
		
	n = root;
	
	while (n -> next != NULL ) 	// traversing till end of list
		n = n -> next;
		
	n -> next = t; 	// adding node at the end
	
}

void display(){
	
	node *t = root;
	
	cout << endl;
	
	while (t != NULL){
		
		cout << t -> data << "\t";
		t = t -> next;
		
	}
	
	cout << endl;
	
}

void removedups(){
	
	node *n, *p, *t = root;
	
	// lets say this while loop starts with node 'n'
	while(t != NULL){ // traversing entire linked list
		
		n = p = t -> next; // p is used to hold value of last accessed
						   // node during inner while loop iterations
		
		int first = 0; // if in the very first interation of inner while
					   // duplicate value is one then this flag will be 
					   // set to 1.
		
		// this while loop start with node 'n+1'
		while (n != NULL){ // traversing entire list starting from node 'n+1'
			
			if (t -> data == n -> data ){
				
				if(first == 0)
					t -> next = n -> next;
					
				p -> next = n -> next;
				n = n -> next;
				
				continue;
				
			}
				
			first = 1;
			p = n; // getting value of n before incrementing so that
				   // it can be used in next iteration when needed
			n = n -> next;
			
		}
		
		t = t -> next;
		
	}
	
	cout << "\nArray after removing duplicates : \n";
	display();
	
}

int main(){
	
	append(99);
	append(99);
	append(9);
	append(999);
	append(9);
	append(989);
	append(9);
	append(989);
	append(919);
	append(989);
	append(989);
	append(909);
	append(900);
	append(900);
	
	cout << "Current array : \n";
	display();
	removedups();

	return 1;
	
}
