#include<iostream>
#include<stack>

using namespace std;

class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int val):val(val), left(nullptr), right(nullptr) {}
		Node(int val, Node* left, Node* right):val(val), left(left), right(right) {}
		~Node();
};

Node::~Node() {
	this->left = nullptr;
	this->right = nullptr;
}

void pre_dfs_rec(Node* root) {
	if(!root)
		return;
	cout << root->val << " ";
	pre_dfs_rec(root->left);
	pre_dfs_rec(root->right);
}

void pre_dfs_com(Node* root) {
	Node* node = root;
	stack<Node*> stack;
	while(!stack.empty() || node) {
		while(node) {
			cout << node->val << " ";
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		stack.pop();
		node = node->right;
	}
}

void in_dfs_rec(Node* root) {
	if(!root)
		return;
	in_dfs_rec(root->left);
	cout << root->val << " ";
	in_dfs_rec(root->right);
}

void in_dfs_com(Node* root) {
	Node* node = root;
	stack<Node*> stack;
	while(node || !stack.empty()) {
		while(node) {
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		cout << node->val << " ";
		stack.pop();
		node = node->right;
	}
}

void post_dfs_rec(Node* root) {
	if(!root)
		return;
	post_dfs_rec(root->left);
	post_dfs_rec(root->right);
	cout << root->val << " ";
}

void post_dfs_com(Node* root) {
	Node* node = root;
	Node* last = nullptr;
	stack<Node*> stack;
	while(node || !stack.empty()) {
		while(node) {
			stack.push(node);
			node = node->left;
		}
		node = stack.top();
		//the right subtree exist and it has not been visited before
		if(node->right && !(node->right == last)) {
			node = node->right;
		}
		else if(!node->right || (node->right == last)) {
			cout << node->val << " ";
			stack.pop();
			last = node;
			node = nullptr;
		}
	}
}

void clear(Node* root) {
	if(!root)
		return;
	clear(root->left);
	clear(root->right);
	delete root;
}

int main(void) {
	Node* l1 = new Node(4);
	Node* l3 = new Node(6);
	Node* l5 = new Node(8);
	Node* l6 = new Node(9);
	Node* l7 = new Node(10);
	Node* l4 = new Node(7, l7, nullptr);
	Node* l2 = new Node(5, l5, l6);
	Node* r2 = new Node(2, l1, l2);
	Node* r3 = new Node(3, l3, l4);
	Node* r1 = new Node(1, r2, r3);
	cout << "preorder search" << endl;
	pre_dfs_rec(r1);
	cout << endl;
	pre_dfs_com(r1);
	cout << endl;
	cout << "inorder search" << endl;
	in_dfs_rec(r1);
	cout << endl;
	in_dfs_com(r1);
	cout << endl;
	cout << "postorder search" << endl;
	post_dfs_rec(r1);
	cout << endl;
	post_dfs_com(r1);
	cout << endl;
	clear(r1);
	return 0;
}
