#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
};

void setDepth(Node* node, map<int, vector<Node*>>& depths, int depth)
{
	depths[depth].push_back(node);

	if (node->left != NULL)
		setDepth(node->left, depths, depth + 1);

	if (node->right != NULL)
		setDepth(node->right, depths, depth + 1);
}

void search(vector<int>& result, Node* now)
{
	if (now == NULL)
		return;

	search(result, now->left);
	result.push_back(now->val);
	search(result, now->right);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
	vector<Node> tree(indexes.size());
	for (int i = 0; i < indexes.size(); ++i)
		tree[i] = { i + 1, 0, 0 };

	for (int i = 0; i < indexes.size(); ++i)
	{
		if (indexes[i][0] != -1)
			tree[i].left = &tree[indexes[i][0] - 1];

		if (indexes[i][1] != -1)
			tree[i].right = &tree[indexes[i][1] - 1];
	}

	map<int, vector<Node*>> depths;
	setDepth(&tree[0], depths, 1);

	vector<vector<int>> result;
	for (int k : queries)
	{
		for (int depth = k; depth <= indexes.size(); depth += k)
		{
			for (Node* node : depths[depth])
			{
				Node* temp = node->left;
				node->left = node->right;
				node->right = temp;
			}
		}

		vector<int> res;
		search(res, &tree[0]);
		result.push_back(res);
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> indexes(n);
	for (auto& index : indexes)
	{
		index.resize(2);
		cin >> index[0] >> index[1];
	}

	int t;
	cin >> t;

	vector<int> queries(t);
	for (int i = 0; i < t; ++i)
	{
		cin >> queries[i];
	}

	vector<vector<int>> result = swapNodes(indexes, queries);
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << ' ';

		cout << endl;
	}
	return 0;
}
