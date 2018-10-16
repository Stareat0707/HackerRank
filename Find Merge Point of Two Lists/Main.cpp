#include <iostream>
#include <stack>
#include <string>

using namespace std;

class SinglyLinkedListNode
{
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) : data(node_data), next(nullptr)
	{
	}
};

class SinglyLinkedList
{
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() : head(nullptr), tail(nullptr)
	{
	}

	void insert_node(int node_data)
	{
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (head == nullptr)
			head = node;
		else
			tail->next = node;

		tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep)
{
	while (node != nullptr)
	{
		cout << node->data;

		node = node->next;

		if (node != nullptr)
			cout << sep;
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node)
{
	while (node != nullptr)
	{
		SinglyLinkedListNode* temp = node;
		node = node->next;

		delete temp;
	}
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
	stack<int> datas1, datas2;
	while (head1 != nullptr)
	{
		datas1.push(head1->data);
		head1 = head1->next;
	}
	while (head2 != nullptr)
	{
		datas2.push(head2->data);
		head2 = head2->next;
	}

	int result = datas1.top();

	while (datas1.size() > 2 && datas2.size() > 2)
	{
		datas1.pop();
		datas2.pop();

		if (datas1.top() != datas2.top())
			break;

		result = datas1.top();
	}

	return result;
}

int main()
{
	int tests;
	cin >> tests;

	for (int tests_itr = 0; tests_itr < tests; ++tests_itr)
	{
		int index;
		cin >> index;

		SinglyLinkedList* llist1 = new SinglyLinkedList();

		int llist1_count;
		cin >> llist1_count;

		for (int i = 0; i < llist1_count; ++i)
		{
			int llist1_item;
			cin >> llist1_item;

			llist1->insert_node(llist1_item);
		}

		SinglyLinkedList* llist2 = new SinglyLinkedList();

		int llist2_count;
		cin >> llist2_count;

		for (int i = 0; i < llist2_count; ++i)
		{
			int llist2_item;
			cin >> llist2_item;

			llist2->insert_node(llist2_item);
		}

		SinglyLinkedListNode* ptr1 = llist1->head;
		SinglyLinkedListNode* ptr2 = llist2->head;

		for (int i = 0; i < llist1_count; ++i)
		{
			if (i < index)
				ptr1 = ptr1->next;
		}

		for (int i = 0; i < llist2_count; ++i)
		{
			if (i != llist2_count - 1)
				ptr2 = ptr2->next;
		}

		ptr2->next = ptr1;

		int result = findMergeNode(llist1->head, llist2->head);

		cout << result << endl;
	}

	return 0;
}
