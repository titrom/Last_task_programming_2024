#include "NodeAVL.h"
#include "Node.h"
#include <iostream>

NodeAVL::NodeAVL(int k) : Node<NodeAVL>{ k }
{

}

NodeAVL* NodeAVL::Insert(NodeAVL* p, int k)
{
	return Balance(Node<NodeAVL>::Insert(p, k));
}

unsigned char NodeAVL::HeightHandler(NodeAVL* node)
{
	return node ? node->height : 0;
}

int NodeAVL::BFactor(NodeAVL* node)
{
	return HeightHandler(node->right) - HeightHandler(node->left);
}

void NodeAVL::FixHeight(NodeAVL* node)
{
	unsigned char hl = HeightHandler(node->left);
	unsigned char hr = HeightHandler(node->right);
	node->height = (hl > hr ? hl : hr) + 1;
}

NodeAVL* NodeAVL::RotateRight(NodeAVL* node)
{
	NodeAVL* q = node->left;
	node->left = q->right;
	q->right = node;
	FixHeight(node);
	FixHeight(q);
	return q;
}

NodeAVL* NodeAVL::RotateLeft(NodeAVL* node)
{
	NodeAVL* q = node->right;
	node->right = q->left;
	q->left = node;
	FixHeight(node);
	FixHeight(q);
	return q;
}
NodeAVL* NodeAVL::Balance(NodeAVL* node)
{
	FixHeight(node);
	if (BFactor(node) == 2) {
		if (BFactor(node->right) < 0) {
			node->right = RotateRight(node->right);
		}
		return RotateLeft(node);
	}
	if (BFactor(node) == -2) {
		if (BFactor(node->left) > 0) {
			node->left = RotateLeft(node->left);
		}

		return RotateRight(node);
	}
	return node;
}

void NodeAVL::Display(NodeAVL* ptr, int level)
{
	int i;
	if (ptr != nullptr)
	{
		Display(ptr->right, level + 1);
		printf("\n");
		if (ptr == this)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != this; i++)
			cout << "        ";
		cout << ptr->key;
		Display(ptr->left, level + 1);
	}
}
