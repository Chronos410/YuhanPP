#include "TestMSList.h"
#include <iostream>

using namespace std;
TestMSList::TestMSList()
{
	cout << "�����Ǿ���" << endl;
}
TestMSList::~TestMSList()
{
	cout << "�Ҹ�Ǿ���" << endl;
}

HeadNode* TestMSList::createList()
{
	cout << "�� ���� ����Ʈ�� �����Ǿ���" << endl;
	HeadNode* emptyList = new HeadNode;
	return emptyList;
}

void TestMSList::pushBack(HeadNode* headNode, MObject* star)
{
	cout << "����Ʈ�� �ǵڿ� ���ο� ���� ������� �ִ´�" << endl; 
}

MObject* TestMSList::begin(HeadNode* headNode)
{
	cout << "����Ʈ�� �� �տ� �ִ� ��ü�� ��ȯ�Ѵ�" << endl;
	MObject* firstValue = new MObject;
	return firstValue;
}

MObject* TestMSList::end(HeadNode* headNode)
{
	cout << "����Ʈ�� �� �������� �ִ� ��ü�� ��ȯ�Ѵ�" << endl;
	MObject* lastValue = new MObject;
	return lastValue;
}
//begin�̶� end�� �ⲯ �������� �Ⱦ���.
//�� ����ɱ�?