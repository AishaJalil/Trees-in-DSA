
#include <iostream>
//#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node* next;    //for Queue class

    Node() : data(0), left(NULL), right(NULL) , next(NULL){}
    Node(int data) : data(data), left(NULL), right(NULL), next(NULL) {}
};
class Queue {
public:
    Node* front;
    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    void Enqueue(Node* data) {
        if (front == NULL) {
            front = rear = data;
        } else {
            rear->next = data;
            rear = rear->next;
        }
    }

    Node* Dequeue() {
        if (front == NULL) {
            return NULL;
        }

        Node* temp = front;
        front = front->next;
        return temp;
    }

    bool isEmpty() {
        return front == NULL;
    }
};
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(NULL) {}

    void Insert(int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }

        Queue q;
        q.Enqueue(root);

        while (!q.isEmpty()) {
            Node* temp = q.front;
            q.Dequeue();

            if (temp->left == NULL) {
                temp->left = new Node(data);
                return;
            } else {
                q.Enqueue(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = new Node(data);
                return;
            } else {
                q.Enqueue(temp->right);
            }
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
	
    Node* Search(Node* root, int key) {
    	//bool flag = false;
        if (root == NULL) {
            return NULL;  
        }

        if (root->data == key) {
           //flag= true;
           return root; 
        }
 
        Node* leftResult = Search(root->left, key);
        if (leftResult!= NULL ) {
            return leftResult; 
        }

        return Search(root->right, key); 
    }

   void Delete(int val, Node*& root) {
    if (root == NULL) {
        return;
    }

    Node* toDelete = NULL;
    Node* temp = NULL;
    Node* curr = NULL;
    Queue q;
    q.Enqueue(root);
    Node* parent = NULL; // To keep track of the parent node.

    // Traversing to find the deleting node and its parent
    while (!q.isEmpty()) {
        curr = q.Dequeue();
        if (curr->data == val) {
            toDelete = curr;
            break;
        }

        // Keep track of the parent node
        parent = curr;

        if (curr->left) {
            q.Enqueue(curr->left);
        }

        if (curr->right) {
            q.Enqueue(curr->right);
        }
    }

    // If there is no node matching the key value
    if (toDelete == NULL) {
        return;
    }

    if (toDelete->left == NULL && toDelete->right == NULL) 
	{
        if (parent != NULL) {
           
            if (parent->left == toDelete) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        delete toDelete;
        return;
    }

    // Traversal for finding a leaf node to swap with the deleting node
    q.Enqueue(root);
    while (!q.isEmpty()) {
        temp = q.Dequeue();
        if (temp->left) {
            q.Enqueue(temp->left);
        }
        if (temp->right) {
            q.Enqueue(temp->right);
        }
    }

    // swap data of deleting node and leaf node
    toDelete->data = temp->data;

    // Traversal for finding the parent of the leaf node
    q.Enqueue(root);
    parent = NULL;
    while (!q.isEmpty()) {
        curr = q.Dequeue();
        if (curr->left == temp || curr->right == temp) {
            parent = curr;
            break;
        }
        if (temp->left) {
            q.Enqueue(temp->left);
        }
        if (temp->right) {
            q.Enqueue(temp->right);
        }
    }

    if (parent != NULL) {
        if (parent->left == temp) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
    delete temp;
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
	
    void Display(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        Display(node->left);
        Display(node->right);
    }
};

int main() {
    BinaryTree bt;

    bt.Insert(1);
    bt.Insert(2);
    bt.Insert(3);
    bt.Insert(4);
    bt.Insert(5);
    bt.Insert(6);
    bt.Insert(7);
    bt.Insert(8);

    cout << "Tree data: ";
    bt.Display(bt.root);
     
    cout<<"\nBinary tree size: "<<bt.getSize(bt.root, 0);
     cout<<endl;
    Node *temp=bt.Search(bt.root, 5);
    if(temp!=NULL)
    {
    	cout<<"value found... \n";
	}
	else
	cout<<"value not found... \n";
	
	cout<<"Height of Binary Tree : "<<bt.getHeight(bt.root, 0)<<endl;
//	bt.Delete(7, bt.root);
//    cout<<"Tree Data after deleting node 7... \n";
//    bt.Display(bt.root);

    
    return 0;
}



