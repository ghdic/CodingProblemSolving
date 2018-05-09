/*
https://www.acmicpc.net/problem/5586

&Title
5586번 - JOI와 IOI

&Question
입력으로 주어지는 문자열에서 연속으로 3개의 문자가 JOI 또는 
IOI인 곳이 각각 몇 개 있는지 구하는 프로그램을 작성하시오. 
문자열을 알파벳 대문자로만 이루어져 있다. 예를 들어, 아래와 같이 
"JOIOIOI"에는 JOI가 1개, IOI가 2개 있다. 

&Input
첫째 줄에 알파벳 10000자 이내의 문자열이 주어진다. 

&Output
첫째 줄에 문자열에 포함되어 있는 JOI의 개수, 둘째 
줄에 IOI의 개수를 출력한다. 

&Example
-input
JOIOIOIOI

-output
1
3


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int joi = 0, ioi = 0;
	cin >> s;
	for (int i = 0; i < s.size();) {
		int temp = s.find("JOI", i);
		if (temp == -1)break;
		else {
			i = temp + 1;
			joi++;
		}
	}
	for (int i = 0; i < s.size();) {
		int temp = s.find("IOI", i);
		if (temp == -1)break;
		else {
			i = temp + 1;
			ioi++;
		}
	}
	cout << joi << "\n" << ioi << endl;
	return 0;
}
*/