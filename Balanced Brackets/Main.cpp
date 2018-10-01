#include <iostream>
#include <stack>
#include <string>

using namespace std;

string isBalanced(string s)
{
	stack<char> st;

	for (auto& c : s)
	{
		if (c == '{' || c == '(' || c == '[')
			st.push(c);
		else if (st.empty())
			return "NO";
		else if ((st.top() == '{' && c == '}') || (st.top() == '(' && c == ')') || (st.top() == '[' && c == ']'))
			st.pop();
		else
			return "NO";
	}

	return (st.empty() ? "YES" : "NO");
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;

		cout << isBalanced(s) << endl;
	}

	return 0;
}
