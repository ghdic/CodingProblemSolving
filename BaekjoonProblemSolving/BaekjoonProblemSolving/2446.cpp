/*
https://www.acmicpc.net/problem/2446

&Title
별찍기 - 9
&Question
예제를 보고 별찍는 규칙을 유추한 뒤에 별을 찍어 보세요.
&Input
첫째 줄에 N (1<=N<=100)이 주어진다.
&Output
첫째 줄부터 2*N-1번째 줄 까지 차례대로 별을 출력한다.
&Example
-input

-output

*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N * 2 - 1; i++) {
		int k = N - abs(i - (N - 1));
		for (int j = 0; j < N * 2; j++) {
			if (j < k-1 )cout << " ";
			else if (j >= N * 2 - k);
			else cout << "*";
		}
		cout << endl;
	}
	return 0;
}
*/