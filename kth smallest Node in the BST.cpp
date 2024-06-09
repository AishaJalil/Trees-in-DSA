#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(Node* val) {
        if (top == NULL) {
            top = val;
        } else {
            val->next = top;
            top = val;
        }
    }

    Node* pop() {
        if (top == NULL) {
            return NULL; 
        }
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        return temp;
    }

    Node* peek() {
        return top;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

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

    void PreOrder(Node*& root1) {
        if (root1 == NULL)
            return;

        cout << root1->data << " ";

        PreOrder(root1->left);
        PreOrder(root1->right);
    }

    void getInorder(Stack* st, Node* root) {
        if (root == NULL)
            return;

        getInorder(st, root->left);
        st->push(root);
        getInorder(st, root->right);
    }

    Node* Kth_SmallestNode(Node* root, int k) {
        Stack st;
        getInorder(&st, root);
        Node* temp = NULL;
        for (int i = 0; i < k; i++) {
            temp = st.pop();
        }
        return temp;
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

    cout << "Preorder traversal: ";
    bst.PreOrder(bst.root);
    cout << endl;

    int k = 2; 
    Node* kthNode = bst.Kth_SmallestNode(bst.root, k);

    if (kthNode != NULL) {
        cout << "Kth smallest node value: " << kthNode->data << endl;
    } else {
        cout << "Kth smallest node not found ...\n" << endl;
    }

    return 0;
}
