// Priority Queue as linked list

#include<iostream>
#include<conio.h>

using namespace std;

class pque{
       
    struct node {
    	
    	node *link;
    	int data, pri;
    	
    }*start;
	
	public :
		
	pque(){
		
		start = NULL;
		
	}
	
	void add(int num, int priority){
		
		node *t, *r;
		t = start;
		
		cout << "\nAdding " << num << " to queue\n";
		
		r = new node;
		r -> data = num;
		r -> link = NULL;
		r -> pri = priority;
				
		if (t == NULL)	
			start = r;
		
		else {
			
			r -> link = t;
			start = r;
			
		}
		
		display();
		
	}
	
	void del(){
		
		node *t, *p;
		t = start;
		
		cout << "\nDeleting from queue\n";
		
		if (t == NULL)
			cout << "\nQueue is empty\n";
			
		else if (t -> link == NULL) {
			
			start = NULL;
			cout << "\nQueue is empty now\n";
			
		}
			
		else {
			
			while ( t -> link != NULL){
				
				p = t;
				t = t -> link;
				
			}
			
			p -> link = NULL;				

			display();
			
		}
	}
	
	void display(){
		
		node *t;
		t = start;
		cout << "\nCurrent queue is : ";
		
		while (t != NULL){
			
			cout << t -> data << ":" << t -> pri << "\t";
			t = t -> link;
			
		}
		
		cout << endl;
			
	}
	
	// This function finds the node with highest priority (greater the no. higher the priority)
	// and removes that node from the priority queue after printing it.
	
	void accessprique(){
		
		node *t, *q, *p, *r, *s;
		
		p = q = NULL;
		t = start;
		int max = 0;
		
		while (t -> link != NULL) {
			
			q = p;
			p = t;
			
			if ( max < t -> pri ){
				
				r = q;
				s = t -> link;
				max = t -> pri;
				
			}
			
			t = t -> link;	
			
		} 
		
		t = r -> link;
		r -> link = s;
		
		cout << "\nNode with highest priority is " << t -> data << ":" << t -> pri << "\n";
		display();
		
	}
	
	int count(){
		
		node *t;
		t = start;
		int i = 0;
		
		while (t != NULL){
			
			i++;
			t = t -> link;
			
		}
		
		cout << "\nTotal elements in queue are : " << i << endl;	
		return i;
		
	}
	
};

int main(){
    
	pque pq;
	
	pq.add(9,6);
	pq.add(99,1);
	pq.add(999,4);
	pq.add(909,2);
	pq.add(9,6);
	pq.add(90,8);
	pq.add(91,3);
	pq.del();
	pq.count();
	pq.del();
	pq.accessprique();
	pq.count();
	pq.accessprique();
	pq.count();

    getch();
    return 0;
    
}
