#pragma once
#include "Node.h"

using namespace std;

class NodeAVL : public Node<NodeAVL>
{
public:
	NodeAVL(int k);
	NodeAVL* Insert(NodeAVL* p, int k) override;
	void Display(NodeAVL* ptr, int level);

private:
	unsigned char HeightHandler(NodeAVL* node);

	int BFactor(NodeAVL* node);

	void FixHeight(NodeAVL* node);

	NodeAVL* RotateRight(NodeAVL* node);

	NodeAVL* RotateLeft(NodeAVL* node);

	NodeAVL* Balance(NodeAVL* node);

};

