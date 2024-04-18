#include "MSList.h"

MSList::MSList()
{
	
}
MSList::~MSList()
{

}

HeadNode* MSList::createList()		//빈 리스트 생성
{	
	HeadNode* H = new HeadNode;			// 생성될 리스트를 가리키는 포인터(HeadNode)
	H->link = nullptr;					// 아직 들어있는 Node가 없으니 Null로 선언
	return H;							// 생성된 리스트의 주소를 반환
}

void MSList::pushBack(HeadNode* headNode, MObject* star)	//리스트의 마지막에 MObject형 객체 추가하기
{
	Node* inputNode = new Node;			//새로 넣을 Star객체
	Node* lastNode;						//리스트의 가장 마지막에 있는 Star객체

	inputNode->link = nullptr;
	inputNode->value = star;

	if (headNode->link == nullptr)		//리스트가 비어있다면
	{	
		headNode->link = inputNode;				//HeadNode가 inputNode를 가르키게 하면 끝
		return;
	}
	else								//리스트가 비어있지 않다면
	{
		lastNode = headNode->link;				//lastNode에 우선 HeadNode를 넣어봄
		while (lastNode->link != nullptr)		//진짜 마지막에 있는 Node(link가 Null인 노드)를 찾을때 까지
		{
			lastNode = lastNode->link;			//하나씩 뒤로 감
		}
		lastNode->link = inputNode;				//마지막 노드를 찾으면 while문을 빠져나오고 inputnode의 주소 값을 마지막노드의 link에 집어넣음
	}
}

MObject* MSList::begin(HeadNode* headNode)		//리스트의 첫번째 객체를 반환하는 함수
{
	Node* firstNode;								//첫번째 node 위치 firstNode
	firstNode = headNode->link;						//첫 노드는 HeadNode가 가리키는 노드임
	return firstNode->value;						//첫 노드의 Value를 리턴함
}

MObject* MSList::end(HeadNode* headNode)		//리스트의 마지막 객체를 반환하는 함수
{
	Node* lastNode;									//마지막 node 위치 lastNode
	lastNode = headNode->link;						//일단 lastnode로 첫 노드를 가르키고
	while (lastNode->link != nullptr)				//link가 NULL인 노드를 찾을 때 까지
	{
		lastNode = lastNode->link;					//하나씩 뒤로 감
	}
	return lastNode->value;							//마지막 노드를 찾으면(while문을 빠져나오면) 마지막 노드의 Value를 리턴함
}