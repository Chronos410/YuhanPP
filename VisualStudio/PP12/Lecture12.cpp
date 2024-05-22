#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	chrono::steady_clock::time_point afterwait = chrono::steady_clock::now();

	chrono::steady_clock::duration diff;

	chrono::steady_clock::duration waittime = afterwait - end;

	int count = 0;

	while (count < 100) 
	{

		count++;
		cout << "Ä«¿îÆ® :" << count << endl;
		

		prev_end = end;
		end = chrono::steady_clock::now();

		diff = waittime - (end - prev_end);
		int duration = chrono::duration_cast<chrono::milliseconds>(diff).count();

		cout << duration << endl;
		cout << chrono::duration_cast<chrono::milliseconds>(waittime).count() << endl;

		this_thread::sleep_for(chrono::milliseconds(1000-duration));

		afterwait = chrono::steady_clock::now();
		waittime = afterwait - end;


	}

	

	return 0;
}