#include "MSList.h"

MSList::MSList()
{
	
}
MSList::~MSList()
{

}

HeadNode* MSList::createList()		//�� ����Ʈ ����
{	
	HeadNode* H = new HeadNode;			// ������ ����Ʈ�� ����Ű�� ������(HeadNode)
	H->link = nullptr;					// ���� ����ִ� Node�� ������ Null�� ����
	return H;							// ������ ����Ʈ�� �ּҸ� ��ȯ
}

void MSList::pushBack(HeadNode* headNode, MObject* star)	//����Ʈ�� �������� MObject�� ��ü �߰��ϱ�
{
	Node* inputNode = new Node;			//���� ���� Star��ü
	Node* lastNode;						//����Ʈ�� ���� �������� �ִ� Star��ü

	inputNode->link = nullptr;
	inputNode->value = star;

	if (headNode->link == nullptr)		//����Ʈ�� ����ִٸ�
	{	
		headNode->link = inputNode;				//HeadNode�� inputNode�� ����Ű�� �ϸ� ��
		return;
	}
	else								//����Ʈ�� ������� �ʴٸ�
	{
		lastNode = headNode->link;				//lastNode�� �켱 HeadNode�� �־
		while (lastNode->link != nullptr)		//��¥ �������� �ִ� Node(link�� Null�� ���)�� ã���� ����
		{
			lastNode = lastNode->link;			//�ϳ��� �ڷ� ��
		}
		lastNode->link = inputNode;				//������ ��带 ã���� while���� ���������� inputnode�� �ּ� ���� ����������� link�� �������
	}
}

MObject* MSList::begin(HeadNode* headNode)		//����Ʈ�� ù��° ��ü�� ��ȯ�ϴ� �Լ�
{
	Node* firstNode;								//ù��° node ��ġ firstNode
	firstNode = headNode->link;						//ù ���� HeadNode�� ����Ű�� �����
	return firstNode->value;						//ù ����� Value�� ������
}

MObject* MSList::end(HeadNode* headNode)		//����Ʈ�� ������ ��ü�� ��ȯ�ϴ� �Լ�
{
	Node* lastNode;									//������ node ��ġ lastNode
	lastNode = headNode->link;						//�ϴ� lastnode�� ù ��带 ����Ű��
	while (lastNode->link != nullptr)				//link�� NULL�� ��带 ã�� �� ����
	{
		lastNode = lastNode->link;					//�ϳ��� �ڷ� ��
	}
	return lastNode->value;							//������ ��带 ã����(while���� ����������) ������ ����� Value�� ������
}