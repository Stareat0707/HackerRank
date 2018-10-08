#include <algorithm>
#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
			return new Node(data);

		Node* cur;
		if (data <= root->data)
		{
			cur = insert(root->left, data);
			root->left = cur;
		}
		else
		{
			cur = insert(root->right, data);
			root->right = cur;
		}

		return root;
	}

	Node *lca(Node *root, int v1, int v2)
	{
		if (v1 > v2)
			swap(v1, v2);

		if (root->data >= v1 && root->data <= v2)
			return root;

		if (root->data <= v1 && root->data <= v2)
			return lca(root->right, v1, v2);

		if (root->data >= v1 && root->data >= v2)
			return lca(root->left, v1, v2);

		return NULL;
	}
};

int main()
{
	Solution myTree;
	Node* root = NULL;

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int data;
		cin >> data;
		root = myTree.insert(root, data);
	}

	int v1, v2;
	std::cin >> v1 >> v2;

	cout << myTree.lca(root, v1, v2)->data << endl;
	return 0;
}
