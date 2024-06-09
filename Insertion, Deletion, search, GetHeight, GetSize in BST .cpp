#include <iostream>

using namespace std;

class Node{
	
	public:
		int data;
		Node *left;
		Node *right;
		
		Node()
		{
			
		}
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
	//	int count=0;
		BinarySearchTree()
		{
				
		}
		BinarySearchTree(int data)
		{
			root = new Node(data);
		//	count++; 
		}
		void Insert(Node *&root1, int data)
		{
			if(root1 == NULL)
		    {
		    		root1 = new Node(data);
		    	//	count++;
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
		Node* Search(Node *&root1, int key)
		{
			
		    if(root == NULL)
		    return NULL;
			if(root1->data == key)
			{
				return root1;
			}
		
			else if(root1->data>key)
			{
				return Search(root1->left, key);
			
			}
			else
			{
				return Search(root1->right, key);
				
			}
			
		}
		
		int getSize(Node *&root1, int size)
		{
			if(root1 == NULL)
	       	return size;
	        size++;	
	        
	        size= getSize(root1->left, size);
	        size =getSize(root1->right, size);
	        return size;
	        
		}
		void PreOrder(Node *&root1)
		{
			if(root1 == NULL)
	       	return;
	        	
	        cout<<root1->data<<" ";
	        	
	        PreOrder(root1->left);
	        PreOrder(root1->right);
	        return;
		}
		int getHeight(Node *&root1,  int high)
		{
			if(root1 == NULL)
			{
				return high;
				
			}
			int hl = getHeight(root1->left,++high);
			high=0;
			int hr = getHeight(root1->right, ++high);
			
			if(hl<hr)
			return hr;
			return hl;
		}
		Node* deleteNode(Node* root, int k)
        {

           if (root == NULL)
             return root;

           if (root->data > k) {
               root->left = deleteNode(root->left, k);
               return root;
           }
           else if (root->data < k) {
               root->right = deleteNode(root->right, k);
               return root;
           }

           if (root->left == NULL) {
               Node* temp = root->right;
               delete root;
               return temp;
           }  
            else if (root->right == NULL) {
               Node* temp = root->left;
               delete root;
               return temp;
           }
 
           else {
 
            Node* succParent = root;
 
            Node* succ = root->right;
            while (succ->left != NULL) {
               succParent = succ;
               succ = succ->left;
            }
 
             if (succParent != root)
               succParent->left = succ->right;
             else
               succParent->right = succ->right;
 
           root->data = succ->data;
 
          delete succ;
          return root;
         }
   }
		
};


int main()
{
	BinarySearchTree bst;
	bst.Insert(bst.root, 4);
	bst.Insert(bst.root, 2);
	bst.Insert(bst.root, 1);
	bst.Insert(bst.root, 3);
	bst.Insert(bst.root, 6);
	bst.Insert(bst.root, 5);
    bst.Insert(bst.root, 7);
	//cout<<bst.root->data;
	bst.PreOrder(bst.root);
	
	Node *searchNode= bst.Search(bst.root, 6);
	if(searchNode != NULL)
	cout<<"\nValue found...!\n";
	else 
	{
		cout<<"\nValue not found...!\n";
	}
	
	cout<<"Size of Binary Search Tree : "<<bst.getSize(bst.root, 0);
	cout<<"\nHeight of Binary Search Tree is : "<<bst.getHeight(bst.root,0);
    cout<<endl;
    cout<<"BST after deleting node have value 4: ";
    bst.deleteNode(bst.root, 4);
    bst.PreOrder(bst.root);
}

