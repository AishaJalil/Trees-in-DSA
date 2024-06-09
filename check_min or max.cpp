#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node* next;    //for Queue class

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
            }
            else {
                q.Enqueue(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = new Node(data);
                return;
            }
            else {
                q.Enqueue(temp->right);
            }
        }
    }
    void push_in_queue(Node*& root, int* arr, int& i) {
        if (root == NULL) {
            return;
        }

        Queue q;
        q.Enqueue(root);
        arr[i++] = root->data;

        while (!q.isEmpty()) {
            Node* curr = q.Dequeue();

            if (curr->left) {
                q.Enqueue(curr->left);
                arr[i++] = curr->left->data;
            }

            if (curr->right) {
                q.Enqueue(curr->right);
                arr[i++] = curr->right->data; 
            }
        }
    }
    int check_MaxMin_heap(Node*& root) {
        int arr[50];
        int i = 0;

        push_in_queue(root, arr, i);

        bool maxFlag = true;
        bool minFlag = true;

        // Check for max heap
        for (int j = 0; j < i; j++) {
            if ((2 * j + 1) < i && arr[j] < arr[2 * j + 1]) {
                maxFlag = false;
            }
            if ((2 * j + 2) < i && arr[j] < arr[2 * j + 2]) {
                maxFlag = false;
            }
        }

        // Check for min heap
        for (int j = 0; j < i; j++) {
            if ((2 * j + 1) < i && arr[j] > arr[2 * j + 1]) {
                minFlag = false;
            }
            if ((2 * j + 2) < i && arr[j] > arr[2 * j + 2]) {
                minFlag = false;
            }
        }

        if (maxFlag && !minFlag) {
            return 1; // Max heap
        }
        else if (!maxFlag && minFlag) {
            return -1; // Min heap
        }
        else {
            return 0; // Neither max nor min heap
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

    bt.Insert(8);
    bt.Insert(7);
    bt.Insert(6);
    bt.Insert(5);
    bt.Insert(4);
    bt.Insert(3);
    bt.Insert(2);
    bt.Insert(1);

    cout << "Tree data: ";
    bt.Display(bt.root);
    cout << endl;


    //if flag is 1 , it means tree is max heap, -1 means it is min heap and 0 means tree is neither min heap nor max heao
    int flag = bt.check_MaxMin_heap(bt.root);

    switch (flag)
    {
    case -1:
        cout << "Given tree is min heap.\n";
        break;
    case 0:
        cout << "Given tree is neither max heap nor min heap.\n";
        break;
    case 1:
        cout << "Given tree is max heap.\n";
        break;
    }


    return 0;
}







