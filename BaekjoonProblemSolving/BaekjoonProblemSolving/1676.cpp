/*
https://www.acmicpc.net/problem/1676

&Title
1676번 - 팩토리얼 0의 개수

&Question
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 
0의 개수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 
500) 

&Output
첫째 줄에 구한 0의 개수를 출력한다. 

&Example
-input
10

-output
2


*/

/*
#include <iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

int main() {
	int N, two = 0, five = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp = i;
		while (temp%2 == 0) {
			++two;
			temp /= 2;
		}
		while (temp % 5 == 0) {
			++five;
			temp /= 5;
		}
	}
	cout << MIN(two, five) << "\n";
	return 0;
}
*/