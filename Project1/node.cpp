#include "node.h"
#include <cstddef>
Node* new_node(int n)
{
	Node* head = new Node;
	head->value = record();
	Node* tail = head;
	for (int x = 1; x <= n; x++)
	{
		Node* tmp = new Node;
		tail->next = tmp;
		tail = tmp;
	}
	tail->next = NULL;
	return head;
}
bool add_node(Node* n, int k, record value)
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
record get_node(Node* n, int k)
{
	for (int x = 1; x < k; x++)
	{
		n = n->next;
	}
	return n->value;
}
Node* read_data_from_array(record r[], int k)
{
	Node* head = new Node;
	Node* tail = head;
	head->value = r[0];
	for (int x = 1; x < k; x++)
	{
		Node* tmp = new Node;
		tmp->next = NULL;
		tmp->value = r[x];
		tail->next = tmp;
		tail = tmp;
	}
	return head;
}