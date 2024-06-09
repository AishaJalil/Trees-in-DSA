#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

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

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(NULL) {}

    BinarySearchTree(int data) {
        root = new Node(data);
    }

    void Insert(Node*& root1, int data) {
        if (root1 == NULL) {
            root1 = new Node(data);
            return;
        } else if (data < root1->data) {
            Insert(root1->left, data);
        } else {
            Insert(root1->right, data);
        }
    }

    void PreOrder(Node* root1) {
        if (root1 == NULL) {
            return;
        }

        cout << root1->data << " ";

        PreOrder(root1->left);
        PreOrder(root1->right);
    }

    void InOrder(Node* root1) {
        if (root1 == NULL) {
            return;
        }

        InOrder(root1->left);
        cout << root1->data << " ";
        InOrder(root1->right);
    }

    void PostOrder(Node* root1) {
        if (root1 == NULL) {
            return;
        }

        PostOrder(root1->left);
        PostOrder(root1->right);
        cout << root1->data << " ";
    }

    void LevelOrder(Node* root1) {
        if (root1 == NULL) {
            return;
        }

        Queue q;
        q.Enqueue(root1);

        while (!q.isEmpty()) {
            Node* curr = q.Dequeue();
            cout << curr->data << " ";

            if (curr->left) {
                q.Enqueue(curr->left);
           }

            if (curr->right) {
                q.Enqueue(curr->right);
            }
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.Insert(bst.root, 4);
    bst.Insert(bst.root, 2);
    bst.Insert(bst.root, 1);
    bst.Insert(bst.root, 3);
    bst.Insert(bst.root, 6);
    bst.Insert(bst.root, 5);
    bst.Insert(bst.root, 7);

    cout << "Preorder: ";
    bst.PreOrder(bst.root);
    cout << endl;

    cout << "Inorder: ";
    bst.InOrder(bst.root);
    cout << endl;

    cout << "Postorder: ";
    bst.PostOrder(bst.root);
    cout << endl;

    cout << "Level Order: ";
    bst.LevelOrder(bst.root);
}

