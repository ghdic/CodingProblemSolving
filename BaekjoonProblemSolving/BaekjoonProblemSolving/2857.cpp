/*
https://www.acmicpc.net/problem/2857

&Title
2857번 - FBI

&Question
5명의 요원 중 FBI 요원을 찾는 프로그램을 작성하시오. 
FBI요원은 요원의 첩보원명에 FBI가 들어있다. 

&Input
5개 줄에 요원의 첩보원명이 주어진다. 첩보원명은 알파벳 대문자, 
숫자 0~9, 대시 (-)로만 이루어져 있으며, 최대 10글자이다. 

&Output
첫째 줄에 FBI 요원을 출력한다. 이 때, 해당하는 
요원이 몇 번째 입력인지를 공백으로 구분하여 출력해야 하며, 오름차순으로 
출력해야 한다. 만약 FBI 요원이 없다면 "HE GOT AWAY!"를 
출력한다. 

&Example
-input
47-FBI
BOND-007
RF-FBI18
MARICA-13
13A-FBILL

-output
1 3 5


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int arr[5] = { 0 }, cnt = 0;
	for (int i = 1; i <= 5; i++) {
		cin >> s;
		if (s.find("FBI") != -1) {
			arr[cnt++] = i;
		}
	}
	if (cnt == 0)cout << "HE GOT AWAY!" << endl;
	else {
		for (int i = 0; i < cnt; i++) {
			if (i == cnt - 1)cout << arr[i] << endl;
			else cout << arr[i] << " ";
		}
	}
	return 0;
}
*/