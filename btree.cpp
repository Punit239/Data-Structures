// Implementing Binary Tree and preorder, postorder and inorder traversing 

#include<iostream>
#include<conio.h>

using namespace std;

class btree{
       
    struct node {
    	
    	node *left;
    	node *right;
    	int data;
    	
    }*root;
    
	public :
		
	btree(){
		
		root = NULL;
		
	}
	
	void insert(int num){
		
		node *t, *r;
		int flag =0;
		
		t = root;
		
		r = new node;
		r -> left = NULL;
		r -> right = NULL;
		r -> data = num;

	// Inserting new node
		
		if (root == NULL){  // Creating the root node
			
			root = r;
			flag = 1;  // set to 1 when a node is inserted
			
		} 
		
		while ( flag == 0){
			if (t -> data > num){
			
				if (t -> left == NULL){
				
					t -> left = r;
					flag = 1;
				
				}else{
				
					t = t -> left;
				
				}
				
			} else if (t -> data < num){
				
				if (t -> right == NULL){
					
					t -> right = r;
					flag = 1;
					
				} else {
					
					t = t -> right;
					
				}
				
			}
		}
		
	}
	
	void inorder(node *s){
		
		if (s != NULL){
			
			inorder(s -> left);
			cout << s -> data << "\t";
			inorder(s -> right);
			
		}
		
	}
	
	void displayinorder(){
		
		cout << "\nInorder traversal of tree : \n";
		inorder(root);
		
	}
	
	void preorder(node *s){
		
		if (s != NULL){
			
			cout << s -> data << "\t";
			preorder(s -> left);
			preorder(s -> right);
			
		}
		
	}
	
	void displaypreorder(){
		
		cout << "\nPreorder traversal of tree : \n";
		preorder(root);
		
	}	
	
	void postorder(node *s){
		
		if (s != NULL){
			
			postorder(s -> left);
			postorder(s -> right);
			cout << s -> data << "\t";
			
		}
		
	}
	
	void displaypostorder(){
		
		cout << "\nPostorder traversal of tree : \n";
		postorder(root);
		
	}
};

int main(){
    
	btree bt;
	
	bt.insert(7);
	bt.insert(1);
	bt.insert(0);
	bt.insert(3);
	bt.insert(2);
	bt.insert(5);
	bt.insert(4);
	bt.insert(6);
	bt.insert(9);
	bt.insert(8);
	bt.insert(10);
	
	bt.displayinorder();
	bt.displaypreorder();
	bt.displaypostorder();

    getch();
    return 0;
    
} 
