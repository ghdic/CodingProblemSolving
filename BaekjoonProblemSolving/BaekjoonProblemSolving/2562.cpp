/*
https://www.acmicpc.net/problem/2562

&Title
최대값
&Question
9개의 서로 다른 자연수가 주어질 때, 이들 중 최대값을 찾고 그 최대값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.

예를 들어, 서로 다른 9개의 자연수

3, 29, 38, 12, 57, 74, 40, 85, 61

이 주어지면, 이들 중 최대값은 85이고, 이 값은 8번째 수이다.
&Input
첫 째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수는 100 보다 작다.
&Output
첫째 줄에 최대값을 출력하고, 둘째 줄에 최대값이 몇 번째 수인지를 출력한다.
&Example
-input
3
29
38
12
57
74
40
85
61
-output
85
8
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, max = 0, index = 0;
	for (int i = 0; i < 9; i++) {
		cin >> N;
		if (N > max) {
			max = N;
			index = i + 1;
		}
	}
	cout << max << endl;
	cout << index << endl;
	return 0;
}
*/