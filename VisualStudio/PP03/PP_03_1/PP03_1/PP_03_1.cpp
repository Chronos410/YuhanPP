#include <iostream>
using namespace std;
enum ForeColor {
	Default = 0,
	White = 0,
	Red = 31,
	Grey = 90,
	Yellow = 33,
	Brown = 00,	//아직 못찾음
	Magenta = 35,

};
int main() 
{ 
	int num = 0;

	cout << "\x1b[033m" << "색상 넣기";

	//					십진수		이진수
	//흰색 블록 키코드 : 1			1
	//빨강 블록 키코드 : 2			10
	//회색 블록 키코드 : 4			100
	//노란 블록 키코드 : 8			1000
	//갈색 블록 키코드 : 16			10000
	//마젠타 블록 키코드 : 32		100000
	//프로그램 종료 키코드 : 64		1000000
	
	/*
	출력물

	화면에 그림을 그리는 프로그램입니다.
	학번 : 202034017
	이름 : 최영수
	

	*/
	
	cin >> num;
	
	return 0;
}