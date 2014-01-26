#include<iostream>
#include<conio.h>

using namespace std;

class linklist{
       
       private :
	   
	   struct node{
              
              int num;
              node *link;
              
       }*p;
              
       public :
       
       linklist(){
                  
             p = NULL;              
                  
       }
       
       void append(int n){
            
            node *temp, *r;
    		cout << "\nAppend " << n << " to the list\n";
    		
            // if the list is empty create first node

            if (p == NULL){
                  
                  temp = new node;
                  temp -> num = n;
                  temp -> link = NULL;
                  p = temp;
                  
            }
            else{
                 
                 temp = p;
                 
                 // going to the last node
                 
                 while (temp -> link != NULL)
                       temp = temp -> link;
                 
				       r = new node;
					   r -> link = NULL;
                       r -> num = n;
                       temp -> link = r;
                 
            }
       }
       
       
       void addatbeg(int n){
       	
    		node *temp;
    		temp = new node;
    		
    		cout << "\nAdding " << n << " at the beginning\n";
    		
    		temp -> link = p;
    		temp -> num = n;
    		p = temp;
       	
       }
       
       void insertat(int loc, int n){
       	
       		node *temp, *r;
       		int i = 1;
       		temp = p;
       		
       		cout << "\nAdding " << n << " at " << loc << " position\n";
       		
       		while (i < loc-1){
       		
       			temp = temp -> link;
       			i++;
       			
       		}
       		
       		r = new node;
       		r -> link = temp -> link;
       		temp -> link = r;
       		r -> num = n;
       		
       	
       }
       
       void display(){
            
            node *temp = p;
            
            cout << "\nCurrent linklist :\n";
            
            while (temp != NULL){
                  
				  cout << temp -> num << "\n";
                  temp = temp -> link;
                  
            }
            
       }
       
       void nodecount(){
       	
       		node *temp;
       		temp = p;
       		int i=0;
       		
       		while (temp != NULL){
       			
       				temp = temp -> link;
       				i++;
       			
       		}
       		
       		cout << "\nCurrent no. of nodes in list : " << i << "\n";
       	
       }
       
       void deleteat(int loc){
       	
       		node *temp, *temp1;
       		temp = p;
       		int i =1;
       		
       		while (i < loc-1){
       			temp = temp -> link;
       			i++;
       		}
       		
			temp1 = temp -> link;
       		temp -> link = temp1 -> link;
       			
       		cout << "\nDeleting element " << temp1 -> num << " at location " << loc << "\n"; 
       		
       }
};

int main(){
    
    linklist l;
    
    l.append(9);
    l.append(99);
    l.append(999);
    l.display();
    l.addatbeg(90);
    l.display();
    l.nodecount();    
    l.insertat(2,50);
    l.display();
    l.insertat(4,900);
    l.display();
    l.nodecount();
    l.deleteat(2);
    l.display();
    l.deleteat(5);
    l.display();
    
    getch();
    return 0;
    
}
