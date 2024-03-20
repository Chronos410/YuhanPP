#include <iostream>	//C++버전 stdio.h 뒤에 붙은 stream은 연결통로라는 의미

using namespace std; //std라는 네임스페이스를 사용
int main()
{
	int num = 0;
	while (num != 9999)
	{
		cout << "게임 실행됨" << endl;
		cout << "숫자" << endl;
		cin >> num;
		cout << "망했어" << endl;
	}
	//프로그래밍 패턴 : 게임루프


	/*
	std::cout << "난 최영수 입니다\n";	//iostream의 std 네임스페이스의 cout 을 사용 앞에서 미리 정의한 경우 std::는 없어도 됨(미리 사용한다고 정의했기때문에)
	//출력
	cin >> num;
	//입력
	cout << "입력값은 " << num << "입니다";
	//입력값 출력
	*/

	return 0;
}