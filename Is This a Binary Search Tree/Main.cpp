#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void inOrder(Node* root, vector<int>& v)
{
	if (root == NULL)
		return;

	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
}

bool checkBST(Node* root)
{
	vector<int> v;
	v.push_back(-1);

	inOrder(root, v);

	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] >= v[i])
			return false;
	}

	return true;
}
