#include "TestMObject.h"
#include <iostream>

using namespace std;

TestMObject::TestMObject()
{
	cout << "생성되었다" << endl;
}

TestMObject::~TestMObject()
{

	cout << "소멸되었다" << endl;
}

void TestMObject::render()
{
	cout << "별을 랜더링했다" << endl;
}