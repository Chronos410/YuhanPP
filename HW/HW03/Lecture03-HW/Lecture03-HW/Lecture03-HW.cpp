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
    int num = 0;
    int arr[7] = { 0 };
    int memo, left;

    while (num != 64)
    {
        cout << "화면에 그림을 그리는 프로그램입니다." << endl;
        cout << "학번 : 202034017" << endl;
        cout << "이름 : 최영수" << endl;
        cout << "화면에 그릴 물체코드를 입력하세요 : ";

        cin >> num;

        //2진수로 만들기
        memo = num;

        for (int i = 6; i > 0; i--)
        {
            left = memo % 2;
            memo = memo / 2;
            if (left == 1)
            {
                arr[i] = 1;
            }
            else
            {
                arr[i] = 0;
            }
        }

        //색 블록 출력하기
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
                cout << "\x1b[1;" << colorpick << "m■";
            }
            //cout << arr[i];
            //이진수 전환 작동 실험
        }
        cout << "\x1b[0m" << endl;
    }
    return 0;
}