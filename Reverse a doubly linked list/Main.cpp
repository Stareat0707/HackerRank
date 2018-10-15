#include <iostream>
#include <stack>
#include <string>

using namespace std;

class DoublyLinkedListNode
{
public:
	int data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;

	DoublyLinkedListNode(int node_data) : data(node_data), next(nullptr), prev(nullptr)
	{
	}
};

class DoublyLinkedList
{
public:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;

	DoublyLinkedList() : head(nullptr), tail(nullptr)
	{
	}

	void insert_node(int node_data)
	{
		DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

		if (head == nullptr)
			this->head = node;
		else
		{
			tail->next = node;
			node->prev = tail;
		}

		tail = node;
	}
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep)
{
	while (node != nullptr)
	{
		cout << node->data;

		node = node->next;

		if (node != nullptr)
			cout << sep;
	}
}

void free_doubly_linked_list(DoublyLinkedListNode* node)
{
	while (node != nullptr)
	{
		DoublyLinkedListNode* temp = node;
		node = node->next;

		delete temp;
	}
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{
	if (head != nullptr)
	{
		int list_count = 0;
		DoublyLinkedListNode* now = head;
		DoublyLinkedListNode* prev = head;
		while (now != nullptr && now->next != nullptr)
		{
			now = now->next;
			++list_count;
		}
		++list_count;

		for (int i = 0; i < list_count / 2; ++i)
		{
			int temp = prev->data;
			prev->data = now->data;
			now->data = temp;

			prev = prev->next;
			now = now->prev;
		}
	}

	return head;
}

int main()
{
	int t;
	cin >> t;

	for (int t_itr = 0; t_itr < t; ++t_itr) {
		DoublyLinkedList* llist = new DoublyLinkedList();

		int llist_count;
		cin >> llist_count;

		for (int i = 0; i < llist_count; ++i)
		{
			int llist_item;
			cin >> llist_item;

			llist->insert_node(llist_item);
		}

		DoublyLinkedListNode* llist1 = reverse(llist->head);

		print_doubly_linked_list(llist1, " ");
		cout << endl;

		free_doubly_linked_list(llist1);
	}

	return 0;
}
