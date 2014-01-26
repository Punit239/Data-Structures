// Implementing Binary Tree and preorder, postorder and inorder traversing.
// Deleting from binary tree 

#include<iostream>
#include<conio.h>

using namespace std;

class btree{
       
    struct node {
    	
    	node *left;
    	node *right;
    	int data;
    	
    }*root, *par; // root and parent node
    
    bool rightleg; // to check if node found is left or right child of parent
    
	public :
		
	btree(){
		
		root = NULL;
		
	}
	
	// function to add new node 
	void insert(int num){
		
		node *t, *r;
		int flag =0;
		
		t = root;
		
		// creating new node
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

	void deletenum(int num){
		
		node *t;
		t = NULL;
		rightleg = 0;
		
		t = search(num);
		
		if (t != NULL){
			
			cout << "\nDeleting " << num << " from tree\n";
			
			// if node found is a leaf node
			if (t -> left == NULL && t -> right == NULL){
				
				if (rightleg)
					par -> right = NULL;
				else
					par -> left = NULL;
				
			}
			
			// if node found has only right child
			else if (t -> left == NULL){
			
				if (rightleg)
					par -> right = t -> right;
				else
					par -> left = t -> right;
			
			}
			
			// if node found has only left child
			else if (t -> right == NULL){
			
				if (rightleg)
					par -> right = t -> left;
				else
					par -> left = t -> left;
			
			}
			
			// if node found has both children
			else{
				
				node *succ;
				// inorder successor of a node to be deleted will be its right child in this case.
				succ = t -> right;
			
				if (rightleg)
					par -> right = succ;
				else
					par -> left = succ;
					
				succ -> left = t -> left;
			
			}
			
		}
		else
			cout << "\n"<< num << " is not present in btree. Cannot be deleted.\n";
		
		
	}
	
	// search for a given number and return that node
	node* search(int n){
		
		node *temp;
		temp = root;
		
		while (temp != NULL){
			
			if (temp -> data == n){
				
				cout << "\n" << n << " is there in btree\n";
				return temp;
				
			}
			
			par = temp;
			
			if (temp -> data > n){
				
				rightleg = 0;
				temp = temp -> left;
				
			}
				
			else{
				
				rightleg = 1;
				temp = temp -> right;
				
			}
				
		}
			
		return temp;
		
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

	bt.deletenum(5);
	bt.deletenum(22);
	
	bt.displayinorder();
	bt.displaypreorder();
	bt.displaypostorder();

    getch();
    return 0;
    
} 
