#pragma once
#include "record.h"
struct Node
{
	record value;
	Node* next;
};
Node* new_node(int n);
bool add_node(Node* n, int k, record value);
bool delete_node(Node* n, int k);
record get_node(Node* n, int k);
Node* read_data_from_array(record r[], int k);