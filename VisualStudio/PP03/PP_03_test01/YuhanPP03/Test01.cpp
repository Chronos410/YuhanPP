#include <iostream>	//C++���� stdio.h �ڿ� ���� stream�� ������ζ�� �ǹ�

using namespace std; //std��� ���ӽ����̽��� ���
int main()
{
	int num = 0;
	while (num != 9999)
	{
		cout << "���� �����" << endl;
		cout << "����" << endl;
		cin >> num;
		cout << "���߾�" << endl;
	}
	//���α׷��� ���� : ���ӷ���


	/*
	std::cout << "�� �ֿ��� �Դϴ�\n";	//iostream�� std ���ӽ����̽��� cout �� ��� �տ��� �̸� ������ ��� std::�� ��� ��(�̸� ����Ѵٰ� �����߱⶧����)
	//���
	cin >> num;
	//�Է�
	cout << "�Է°��� " << num << "�Դϴ�";
	//�Է°� ���
	*/

	return 0;
}