/*
https://www.acmicpc.net/problem/2998

&Title
2998번 - 8진수

&Question
창영이는 여러가지 진법을 공부하고 있다. 창영이는 어제 2진법을 
배웠고, 오늘은 8진법을 배웠다. 이제, 2진법 수를 8진법 수로 
변환하려고 한다.창영이가 사용한 방법은 다음과 같다.2진수의 길이가 3으로 나누어 
떨어질 때 까지 수의 앞에 0을 붙인다.그 다음, 3자리씩 
그룹을 나눈다.아래의 표를 참고해 8진수로 바꾼다.2진수가 주어졌을 때, 창영이가 
사용한 방법을 이용해 8진수로 바꾸는 프로그램을 작성하시오.00000011010201131004101511061117 

&Input
첫째 줄에 2진수가 주어진다. 이 수는 100자리 이내이고, 
첫 번째 자리는 1이다. 

&Output
첫째 줄에 8진수를 출력한다. 

&Example
-input
1010

-output
12


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, result;
	int num, i;
	cin >> s;
	if (s.size() % 3 == 0) {
		i = 0;
	}
	else if (s.size() % 3 == 1) {
		num = (s[0] - '0');
		i = 1;
		result += (num + '0');
	}
	else if (s.size() % 3 == 2) {
		num = (s[0] - '0') * 2 + (s[1] - '0');
		i = 2;
		result += (num + '0');
	}

	for (; i < s.size();i+=3) {
		num = (s[i] - '0') * 2 * 2 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
		result += (num + '0');
	}
	cout << result << endl;
	return 0;
}
*/