#pragma once
#include "MObject.h"

using namespace std;

struct Node {
	MObject* value;			//Node�� ���� ��
	struct Node* link;		//'����' Node�� ����Ű�� ������
};
struct HeadNode {
	Node* link;				//HeadNode�� value���� 'ù��°' Node�� ����Ű�� �����͸� ������ ����
};


class TestMSList
{
public:
	TestMSList();
	~TestMSList();

	virtual HeadNode* createList();
	virtual void pushBack(HeadNode* headPointer, MObject* star);

	virtual MObject* begin(HeadNode* headNode);
	virtual MObject* end(HeadNode* headNode);

};