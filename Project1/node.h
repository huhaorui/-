#pragma once
struct Node
{
	int value;
	Node* next;
};
Node* new_node(int n);
bool add_node(Node* n, int k, int value);
bool delete_node(Node* n, int k);
int get_node(Node* n, int k);