/*
https://www.acmicpc.net/problem/11944

&Title
11944번 - NN

&Question
문제는 매우 간단하다. N을 N번 출력하는 프로그램을 작성하여라. 
다만, 답이 길어지는 경우 답의 앞 M자리만 출력한다. 

&Input
첫 번째 줄에는 N, M이 주어진다. (1 ≤ 
N, M ≤ 2016) 

&Output
N을 N번 출력한다. 만약 답이 길어지면 답의 앞 
M자리를 출력한다. 

&Example
-input
20 16

-output
2020202020202020


*/

/*
#include <iostream>
using namespace std;

int main() {
	int a, b, cnt = 0, tmp, num, arr[4], i;
	cin >> a >> b;
	tmp = a;
	i = 0;
	while (tmp % 10 != 0 || tmp / 10 != 0) {
		cnt++;
		arr[i++] = tmp % 10;
		tmp /= 10;
	}
	num = a*cnt > b ? b : a*cnt;
	for (int i = 0; i < num;i++) {
		cout << arr[cnt - i % cnt - 1];
	}
	cout << endl;
	return 0;
}
*/