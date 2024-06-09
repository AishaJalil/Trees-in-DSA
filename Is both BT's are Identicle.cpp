#include <iostream>

using namespace std;

class Node{
	
	public:
		int data;
		Node *left;
		Node *right;

		Node(int data)
		{
			this->data=data;
			left=0;
			right=0;
		}
};


class BinarySearchTree{
	public:
		Node *root;
		BinarySearchTree()
		{
			root = NULL;	
		}
		void Insert(Node *&root1, int data)
		{
			if(root1 == NULL)
		    {
		    		root1 = new Node(data);
		        	return;
			}
		    else if(data < root1->data)
			{
				Insert(root1->left, data);
			}
			else
			{
				Insert(root1->right, data);
			}
		}	
	    
		void PreOrder(Node *&root1)
		{
			if(root1 == NULL)
	       	return;
	        	
	        cout<<root1->data<<" ";
	        	
	        PreOrder(root1->left);
	        PreOrder(root1->right);
		}
};


bool isIdenticalTree(Node *&root1, Node *&root2)
	    {
	    	if(root1== NULL && root2== NULL)
	    	return true;
	    	
	    	if( root1 !=NULL && root2 != NULL)
	    	{
	    		if(root1->data == root2->data)
				return isIdenticalTree(root1->left, root2->left) && isIdenticalTree(root1->right, root2->right);
			}
			return false;
			
		}

int main()
{
	BinarySearchTree bst1, bst2;
	
	cout<<"Tree 1 Data: ";
	bst1.Insert(bst1.root, 4);
	bst1.Insert(bst1.root, 2);
	bst1.Insert(bst1.root, 1);
	bst1.Insert(bst1.root, 3);
	bst1.Insert(bst1.root, 6);
	bst1.Insert(bst1.root, 5);
    bst1.Insert(bst1.root, 7);
    bst1.PreOrder(bst1.root);
    cout<<endl;
    
    cout<<"Tree 2 Data: ";
    bst2.Insert(bst2.root, 4);
	bst2.Insert(bst2.root, 2);
	bst2.Insert(bst2.root, 1);
	bst2.Insert(bst2.root, 3);
	bst2.Insert(bst2.root, 6);
	bst2.Insert(bst2.root, 5);
   // bst2.Insert(bst2.root, 7);
	bst2.PreOrder(bst2.root);

	if(isIdenticalTree(bst1.root, bst2.root))
	{
		cout<<"\nBoth trees are identical...\n";
	}
	else
	{
		cout<<"\nTrees are not identical...\n";
	}
	
}







