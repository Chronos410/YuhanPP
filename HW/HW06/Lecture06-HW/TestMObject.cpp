#include "TestMObject.h"
#include <iostream>

using namespace std;

TestMObject::TestMObject()
{
	cout << "�����Ǿ���" << endl;
}

TestMObject::~TestMObject()
{

	cout << "�Ҹ�Ǿ���" << endl;
}

void TestMObject::render()
{
	cout << "���� �������ߴ�" << endl;
}