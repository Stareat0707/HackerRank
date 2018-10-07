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

class Solution
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
			return new Node(data);
		else
		{
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
	}

	int search(Node* node, int height)
	{
		int result = height;
		if (node->left != NULL)
			result = max(result, search(node->left, height + 1));

		if (node->right != NULL)
			result = max(result, search(node->right, height + 1));

		return result;
	}

	int height(Node* root)
	{
		return search(root, 0);
	}
};

int main()
{

	Solution myTree;
	Node* root = NULL;

	int t;
	cin >> t;

	while (t--)
	{
		int data;
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	cout << myTree.height(root) << endl;
	return 0;
}
