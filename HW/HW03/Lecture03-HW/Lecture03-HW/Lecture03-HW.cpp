#include <iostream>

using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37
};

int main()
{
    int num = 0; // �Է¹޴� ����
    int temp = 0; // �Է¹��� ���� �ӽ� ����
    int left = 0; // ������ ����
    int arr[7] = { 0 }; //2������ ��ȯ�� ������ �迭
    
    cout << "ȭ�鿡 �׸��� �׸��� ���α׷��Դϴ�." << endl;
    cout << "�й� : 202034017" << endl;
    cout << "�̸� : �ֿ���" << endl << endl;
    

    while (num != 64)
    {
        cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ��� : ";

        cin >> num;
        temp = num;

        //2���� ���·� arr[]�� ����
        for (int i = 6; i > 0; i--)
        {
            left = temp % 2;
            temp = temp / 2;
            if (left == 1)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }

        //�� ��� ���
        for (int i = 0; i < 7; i++)
        {
            if (arr[i] == 1)
            {
                int colorpick = 0;
                switch (i)
                {
                case 1:
                    colorpick = Magenta;
                    break;
                case 2:
                    colorpick = Cyan;
                    break;
                case 3:
                    colorpick = Yellow;
                    break;
                case 4:
                    colorpick = Green;
                    break;
                case 5:
                    colorpick = Red;
                    break;
                case 6:
                    colorpick = White;
                    break;
                }
                cout << "\x1b[1;" << colorpick << "m��";
            }


            //cout << arr[i];       //�׽�Ʈ�� �������� ���

        }
        cout << "\x1b[0m" << endl;  //�� ������� ����
    }
    return 0;
}