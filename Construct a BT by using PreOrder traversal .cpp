#include <iostream>
#include <string>

using namespace std;

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

    void Insert(Node*& root, int pre[], int size, int& index) {
        if (index >= size)
            return;
        if (root == NULL) {
            root = new Node(pre[index++]);
        }
        InsertLeft(root->left, pre, size, index);
        //index+= size/2;
        InsertRight(root->right, pre, size,index);
        return;
    }
    
    void InsertLeft(Node*& root, int pre[], int size, int& index) {
        if (index > size/2)
            return;
        if (root == NULL) {
            root = new Node(pre[index++]);
        }
        Insert(root->left, pre, size, index);
        Insert(root->right, pre, size, index);
        
    }
    
    
    void InsertRight(Node*& root, int pre[], int size, int& index) {
        if (index >= size)
            return;
        if (root == NULL) {
            root = new Node(pre[index++]);
        }
        Insert(root->left, pre, size, index);
        Insert(root->right, pre, size, index);
    }
   
    void PreOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        cout << node->data << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
};

int main() {

    int preOrder[7] = {1, 2, 4, 5, 3, 6, 7};
    BinaryTree bt;
    int indx = 0;
    int size = 7;

    bt.Insert(bt.root, preOrder, size, indx);

    cout << "Tree data in preOrder: ";
    bt.PreOrder(bt.root);
    cout<<endl;
   
    return 0;
}












