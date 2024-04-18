#include "TestMSList.h"
#include <iostream>

using namespace std;
TestMSList::TestMSList()
{
	cout << "생성되었다" << endl;
}
TestMSList::~TestMSList()
{
	cout << "소멸되었다" << endl;
}

HeadNode* TestMSList::createList()
{
	cout << "빈 연결 리스트가 생성되었다" << endl;
	HeadNode* emptyList = new HeadNode;
	return emptyList;
}

void TestMSList::pushBack(HeadNode* headNode, MObject* star)
{
	cout << "리스트의 맨뒤에 새로운 값을 연결시켜 넣는다" << endl; 
}

MObject* TestMSList::begin(HeadNode* headNode)
{
	cout << "리스트의 맨 앞에 있는 객체를 반환한다" << endl;
	MObject* firstValue = new MObject;
	return firstValue;
}

MObject* TestMSList::end(HeadNode* headNode)
{
	cout << "리스트의 맨 마지막에 있는 객체를 반환한다" << endl;
	MObject* lastValue = new MObject;
	return lastValue;
}
//begin이랑 end는 기껏 만들어놓고 안쓴다.
//왜 만든걸까?