#include <iostream>
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

		if (this->head == nullptr)
			this->head = node;
		else
		{
			this->tail->next = node;
			node->prev = this->tail;
		}

		this->tail = node;
	}
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep)
{
	while (node)
	{
		cout << node->data;

		node = node->next;

		if (node != nullptr)
			cout << sep;
	}
}

void free_doubly_linked_list(DoublyLinkedListNode* node)
{
	while (node)
	{
		DoublyLinkedListNode* temp = node;
		node = node->next;

		delete temp;
	}
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data)
{
	DoublyLinkedListNode* node = new DoublyLinkedListNode(data);

	DoublyLinkedListNode* next = head;
	DoublyLinkedListNode* prev = nullptr;
	while (next != nullptr && next->data < data)
	{
		prev = next;
		next = prev->next;
	}

	if (prev == nullptr)
	{
		node->next = head;
		head->prev = node;

		return node;
	}

	if (next == nullptr)
	{
		prev->next = node;
		node->prev = prev;
	}
	else
	{
		node->next = prev->next;
		prev->next = node;

		node->prev = next->prev;
		next->prev = node;
	}

	return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		DoublyLinkedList* llist = new DoublyLinkedList();

		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			int llist_item;
			cin >> llist_item;

			llist->insert_node(llist_item);
		}

		int data;
		cin >> data;

		DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

		print_doubly_linked_list(llist1, " ");
		cout << endl;

		free_doubly_linked_list(llist1);
	}

	return 0;
}
