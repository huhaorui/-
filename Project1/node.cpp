#include "node.h"
#include <cstddef>
Node* new_node(int n)
{
	Node* head = new Node;
	head->value = 0;
	Node* tail = head;
	for (int x = 1; x <= n; x++)
	{
		Node* tmp = new Node;
		tmp->value = x;
		tail->next = tmp;
		tail = tmp;
	}
	tail->next = NULL;
	return head;
}
bool add_node(Node* n, int k, int value)
{
	for (int x = 1; x < k; x++)
	{
		n = n->next;
	}
	Node* tmp = new Node;
	tmp->value = value;
	tmp->next = n->next;
	n->next = tmp;
	return true;
}
bool delete_node(Node* n, int k)
{
	for (int x = 1; x < k; x++)
	{
		n = n->next;
	}
	n->next = n->next->next;
	return true;
}
int get_node(Node* n, int k)
{
	for (int x = 1; x < k; x++)
	{
		n = n->next;
	}
	return n->value;
}