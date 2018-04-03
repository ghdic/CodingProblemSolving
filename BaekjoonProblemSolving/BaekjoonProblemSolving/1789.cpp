/*
https://www.acmicpc.net/problem/1789

&Title
수들의 합
&Question
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최대값은 얼마일까?
&Input
첫째 줄에 자연수 S(1≤S≤4,294,967,295)가 주어진다.
&Output
첫째 줄에 자연수 N의 최대값을 출력한다.
&Example
-input
200
-output
19
*/

/*
#include <iostream>
using namespace std;

int main() {
	int i=1, cnt=0;
	long int S;
	
	cin >> S;
	while (i <= S) {
		S -= i;
		i++;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}
*/