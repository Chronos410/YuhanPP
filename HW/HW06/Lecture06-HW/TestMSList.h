#pragma once
#include "MObject.h"

using namespace std;

struct Node {
	MObject* value;			//Node가 가진 값
	struct Node* link;		//'다음' Node를 가르키는 포인터
};
struct HeadNode {
	Node* link;				//HeadNode는 value없이 '첫번째' Node를 가리키는 포인터만 가지고 있음
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