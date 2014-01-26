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
			temp -> link = NULL;
			p = temp;
			
		}
		else {
		
			temp = p;
			while (temp -> link != NULL)
				temp = temp -> link;
				
			r = new node;
			r -> data = num;
			r -> link = NULL;
			temp -> link = r;
			
		}
		display();
		
	}
	
	void display(){
		
		node *temp;
		temp = p;
		
		cout << "\nCurrent list is :\n";
		while (temp != NULL){
			
			cout << temp -> data << "\n";
			temp = temp -> link;
			
		}
		
	}
	
	void reverse(){
		
		node *temp, *r, *q;
		r = NULL;
		temp = p;
		
		while ( temp != NULL ){
			
			q = r;
			r = temp;
			temp = temp -> link;
			r -> link = q;
			
		}
		
		p = r;
		cout << "\nList reversed\n";
		display();
	}

};

int main(){
    
    linkedlist l;
    
    l.addtolast(9);
    l.addtolast(99);
    l.addtolast(999);
    l.reverse();
    l.addtolast(9999);
    
    getch();
    return 0;
    
}
