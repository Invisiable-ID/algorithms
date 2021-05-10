#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int val): val(val), left(nullptr), right(nullptr) {}
		Node(int val, Node* left, Node* right): val(val), left(left), right(right) {}
		~Node() {
			this->left = nullptr;
			this->right = nullptr;
		}
};

void del_sub(Node* root) {
	if(!root)
		return;
	del_sub(root->left);
	del_sub(root->right);
	delete(root);
}

void bfs_rec(Node* root) {
	if(!root)
		return;
	if(root->left)
		cout << root->left->val << " ";
	if(root->right)
		cout << root->right->val << " ";
	bfs_rec(root->left);
	bfs_rec(root->right);
}

void bfs_com(Node* root) {
	queue<Node*> queue;
	queue.push(root);
	while(!queue.empty()) {
		Node* node = queue.front();
		cout << node->val << " ";
		queue.pop();
		if(node->left)
			queue.push(node->left);
		if(node->right)
			queue.push(node->right);
		delete node;
	}
	cout << endl;
}

int main(void) {
	//create a tree
	//		5
	//	   / \
	//	  2   8
	//	 / \ / \
	//	1  3 7  9
	int val1 = 1;
	Node* l1 = new Node(val1);
	int val2 = 3;
	Node* l2 = new Node(val2);
	int val3 = 7;
	Node* l3 = new Node(val3);
	int val4 = 9;
	Node* l4 = new Node(val4);
	int val5 = 2;
	Node* r1 = new Node(val5, l1, l2);
	int val6 = 8;
	Node* r2 = new Node(val6, l3, l4);
	int val7 = 5;
	Node* root = new Node(val7, r1, r2);
	cout << root->val << " ";
	bfs_rec(root);
	cout << endl;
	bfs_com(root);
	del_sub(root);
	return 0;
}
