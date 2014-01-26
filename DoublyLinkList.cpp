// Doubly linked list

#include<iostream>
#include<conio.h>

using namespace std;

class doublylinklist{
       
	struct node { 
		
		int data;
		node *prev;
		node *next;
		
	}*p;
	
	public :
	
	doublylinklist(){
		
		p = NULL;
		
	}
	
	void addtolast(int num){
		
		node *temp, *r;
		temp = p;
		
		if (temp == NULL){
			
			temp = new node;
			temp -> data = num;
			temp -> next = NULL;
			temp -> prev = NULL;
			p = temp;
			
		}else {
			
			temp = p;
			r = new node;
			
			while (temp -> next != NULL)
				temp = temp -> next;
				
			r -> data = num;
			r -> next = NULL;
			r -> prev = temp;
			temp -> next = r;
			
		}
		
		cout << "\nAppending " << num << " to list\n";
		display();
		
	}
	
	void display(){
		
		node *temp;
		temp = p;
		
		cout << "\nCurrent list is :\n";
		while( temp != NULL){
			
			cout << temp -> data << "\n";
			temp = temp -> next;
			
		}
		
	}
	
	void deletenum (int num){
		
		node *temp, *r, *q;
		temp = p;
		
		while (temp != NULL){
			
			if (temp -> data == num){
				
				r = temp -> next;
				q = temp -> prev;
				r -> prev = q;
				q -> next = r;

				cout << "\n" << num << " deleted from list.\n";
				display();
				break;
				
			}
			
			temp = temp -> next;
		}
		
		if (temp == NULL)
			cout << "\n" << num << " not in list. Cannot be deleted.\n";
		
	}
	
	void addatbeg(int num){
		
		node *temp;
				
		cout << "\nAdding " << num << " at the beginning of list\n";
		
		temp = new node;
		temp -> next = p;
		temp -> data = num;
		temp -> prev = NULL;
		p = temp;

		display();
		
	}
	
	void addatloc(int loc, int num){
		
		node *temp, *r;
		temp = p;
		
		cout << "\nAdding " << num << " at location " << loc << "\n";
		for (int i =1; i < loc - 1; i++)
			temp = temp -> next;
			
		r = new node;
		r -> data = num;
		r -> next = temp -> next;
		r -> prev = temp;
		temp -> next = r;
		
		display();
		
	}
	
};

int main(){
    
    doublylinklist l;
    
    l.addtolast(9);
    l.addtolast(99);
    l.addtolast(999);
    l.addtolast(9999);
    l.deletenum(99);
    l.deletenum(999);
    l.deletenum(90);
    l.addatbeg(909);
    l.addatloc(2,91);
	    
    getch();
    return 0;
    
}
