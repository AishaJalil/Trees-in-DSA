#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data) {
	struct Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void Find_KthLargest(Node* root, int k, stack<int>& st) {
	if (root == NULL || k == 0) {
		return;
	}

	stack<Node*> nodes;
	Node* curr = root;

	while (curr != NULL || !nodes.empty()) {
		while (curr != NULL) {
			nodes.push(curr);
			curr = curr->right;
		}

		curr = nodes.top();
		nodes.pop();

		st.push(curr->data);
		k--;

		if (k == 0) {
			return;
		}

		curr = curr->left;
	}
}

int main() {
	stack<int> st;
	// binary tree formation
	struct Node *root = newNode(2);	 /*	 2	 */
	root->left	 = newNode(1);	 /*	 / \ */
	root->right	 = newNode(3);	 /*	 1	 3	 */
	root->left->left = newNode(4);	 /* / \ \ */
	root->left->right = newNode(6);	 /* 4	 6 8 */
	root->right->right = newNode(8); /*	 /	 */
	root->left->right->left = newNode(5);/*	 5	 */
    
    Find_KthLargest(root, 3, st);
    
    if (!st.empty()) {
        cout << st.top() << endl;
    } else {
        cout << "No kth largest element found!" << endl;
    }
    
	return 0;
}
