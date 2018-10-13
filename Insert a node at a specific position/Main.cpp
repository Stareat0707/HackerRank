#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& cout) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
	SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

	if (position == 0)
	{
		node->next = head;
		return node;
	}


	SinglyLinkedListNode* prev = head;
	for (int i = 0; i < position - 1; ++i)
		prev = prev->next;

	node->next = prev->next;
	prev->next = node;

	return head;
}

int main()
{
	SinglyLinkedList* llist = new SinglyLinkedList();

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

	int position;
	cin >> position;

	SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

	print_singly_linked_list(llist_head, " ", cout);
	cout << "\n";

	free_singly_linked_list(llist_head);

	return 0;
}
