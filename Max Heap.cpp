#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node* next;  // for Queue class

    Node() : data(0), left(NULL), right(NULL), next(NULL), parent(NULL) {}
    Node(int data) : data(data), left(NULL), right(NULL), next(NULL), parent(NULL) {}
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    void Enqueue(Node* data) {
        if (front == NULL) {
            front = rear = data;
        }
        else {
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

    void maxHeapify(Node*& root) {
        if (root == NULL || root->parent == NULL) {
            return;
        }

        Node* largest = root;
        Node* parent = root->parent;

        if (parent != NULL && parent->data < largest->data) {
            int temp = parent->data;
            parent->data = largest->data;
            largest->data = temp;
            maxHeapify(parent);
        }
    }

    void Insert(int data) {
        if (root == NULL) {
            root = new Node(data);
            return;
        }

        Queue q;
        q.Enqueue(root);
        Node* temp = NULL;

        while (!q.isEmpty()) {
            temp = q.front;
            q.Dequeue();

            if (temp->left == NULL) {
                temp->left = new Node(data);
                temp->left->parent = temp;
                break;
            }
            else {
                q.Enqueue(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = new Node(data);
                temp->right->parent = temp;
                break;
            }
            else {
                q.Enqueue(temp->right);
            }
        }

        if (temp->left->data == data) {
            maxHeapify(temp->left);
        }
        else {
            maxHeapify(temp->right);
        }
    }

    void delete_maxHeap(Node*& root) {
        if (root == NULL) {
            return;
        }
        if (root->left && root->data < root->left->data) {
            int temp = root->data;
            root->data = root->left->data;
            root->left->data = temp;
        }
        if (root->right && root->right->data > root->data) {
            int temp = root->data;
            root->data = root->right->data;
            root->right->data = temp;
        }
    }

    void Delete() {
        if (root == NULL) {
            return;
        }

        Queue q;
        Node* leafnode = NULL;
        Node* temp = NULL;
        q.Enqueue(root);

        // Traverse the tree to find the deepest and rightmost node
        while (!q.isEmpty()) {
            temp = q.Dequeue();

            if (temp->left) {
                q.Enqueue(temp->left);
                leafnode = temp->left;
            }

            if (temp->right) {
                q.Enqueue(temp->right);
                leafnode = temp->right;
            }
        }

        root->data = leafnode->data;

        Node* parent = leafnode->parent;
        if (leafnode != NULL) {
            if (parent->left == leafnode) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            delete leafnode;
        }

        Queue q1;
        temp = NULL;
        q1.Enqueue(root);

        while (!q1.isEmpty()) {
            temp = q1.Dequeue();
            delete_maxHeap(temp);

            if (temp->left) {
                q1.Enqueue(temp->left);
            }

            if (temp->right) {
                q1.Enqueue(temp->right);
            }
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

    bt.Delete();
    cout << "\nTree Data after deletion : ";
    bt.Display(bt.root);

    return 0;
}

