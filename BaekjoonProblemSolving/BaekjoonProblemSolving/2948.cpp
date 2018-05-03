/*
https://www.acmicpc.net/problem/2948

&Title
2948번 - 2009년

&Question
2009년 날짜가 주어졌을 때, 무슨 요일인지 출력하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 D와 M이 주어진다. M월 D일이다. 

&Output
2009년 M월 D일의 요일을 영어로 출력한다. 출력은 다음 
중 하나이다. "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday". 


&Example
-input
1 1

-output
Thursday


*/

/*
//2009년 1월 1일은 목요일이다.
#include <iostream>
using namespace std;

int main() {
	int M, D;
	cin >> D >> M;
	M--;
	while (M != 0) {
		if (M == 1)D+=31;
		else if (M == 2)D+=28;
		else if (M == 3)D += 31;
		else if (M == 4)D += 30;
		else if (M == 5)D += 31;
		else if (M == 6)D += 30;
		else if (M == 7)D += 31;
		else if (M == 8)D += 31;
		else if (M == 9)D += 30;
		else if (M == 10)D += 31;
		else if (M == 11)D += 30;
		else if (M == 12)D += 31;
		M--;

	}
	D--;
	D %= 7;
	if (D == 0)cout << "Thursday" << endl;
	else if (D == 1)cout << "Friday" << endl;
	else if (D == 2)cout << "Saturday" << endl;
	else if (D == 3)cout << "Sunday" << endl;
	else if (D == 4)cout << "Monday" << endl;
	else if (D == 5)cout << "Tuesday" << endl;
	else if (D == 6)cout << "Wednesday" << endl;
	return 0;
}
*/