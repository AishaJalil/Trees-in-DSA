#include <iostream>
#include <vector>

using namespace std;
bool flag = false;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next; // for Queue class

    Node() : data(0), left(NULL), right(NULL), next(NULL) {}
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
            Node* temp = q.Dequeue();

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
    Node* Search(Node* root, int key) {
    	
        if (root == NULL) {
            return NULL;  
        }

        if (root->data == key) {
           
           return root; 
        }
 
        Node* leftResult = Search(root->left, key);
        if (leftResult!= NULL ) {
            return leftResult; 
        }

        return Search(root->right, key); 
    }
    
    
    Node* getLCA(int node1, int node2) {
         
        Node *n1 ,*n2;
        n1 = Search(BinaryTree::root, node1);
        n2 = Search(BinaryTree::root, node2);
        if(n1 != NULL && n2 != NULL)
        {
            vector<int> path1, path2;
            bool flag1, flag2;
            flag1= findPath(root, node1, path1);
            flag2 = findPath(root, node2, path2);
            if (flag1 != true && flag2 != true) {
                 return NULL; 
            }

            int i;
            for (i = 0; i < path1.size() && i < path2.size(); i++) {
                if (path1[i] != path2[i]) {
                break;
                }
            }
            
            return Search(BinaryTree::root, path1[i - 1]);
	    }
	    else
	    {
	    	flag = true;
	    	cout<<"\nGiven Node is not found in binary tree... \n";
	    	return NULL;
		}
	    
    }

    void Display(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        Display(node->left);
        Display(node->right);
    }


    bool findPath(Node* root, int n, vector<int>& path) {
    	
        if (root == NULL) {
            return false;
        }
        bool leftpath, rightpath;
        path.push_back(root->data);

        if (root->data == n) {
            return true;
        }
        if(root->left)
        {
        	leftpath= findPath(root->left, n, path);
		}
        if (root->right)
	    {
            rightpath= findPath(root->right, n, path);
        }
        if(leftpath == true || rightpath == true)
        return true;
        path.pop_back();
        return false;
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
    Node *x = bt.getLCA(8,7);
    if(x != NULL)
    {
    	cout << "\nLowest common Ancestor of 8 and 7 is: ";
        cout << x->data;
	}
    else if(x == NULL && flag == false)
    {
    	cout<<"There is no LCA... \n";
	}
    return 0;
}

