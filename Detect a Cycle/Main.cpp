struct Node
{
	Node* next;
};

bool has_cycle(Node* head)
{
	for (int i = 0; i < 101; ++i)
	{
		if (!head)
			return false;

		head = head->next;
	}

	return true;
}