// Circular linked list

#include<iostream>
#include<conio.h>

using namespace std;

class linkedlist{
       
	struct node {
		
		int data;
		node *link;
		
	}*p;
	
	public :
	
	linkedlist(){
		
		p = NULL;
		
	}
	
	void addtolast(int num){
		
		node *temp, *r;
		
		cout << "\nAppending " << num << " to the list\n";
		
		if (p == NULL){
			
			temp = new node;
			temp -> data = num;
			temp -> link = temp;
			p = temp;
			
		}
		else {
		
			temp = p;
			while (temp -> link != p)
				temp = temp -> link;
				
			r = new node;
			r -> data = num;
			r -> link = p;
			temp -> link = r;
			
		}
		display();
		
	}
	
	void display(){
		
		node *temp;
		temp = p;
		
		cout << "\nCurrent list is :\n";
		do{
			
			cout << temp -> data << "\n";
			temp = temp -> link;
			
		} while (temp != p);
		
	}
	
};

int main(){
    
    linkedlist l;
    
    l.addtolast(9);
    l.addtolast(99);
    l.addtolast(999);
    l.addtolast(9999);
    
    getch();
    return 0;
    
}
