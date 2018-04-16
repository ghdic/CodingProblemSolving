/*
https://www.acmicpc.net/problem/9506

&Title
약수들의 합
&Question
어떤 숫자 n이 자신을 제외한 약수들의 합으로 나타내어 지면, 그 수를 완벽한 수라고 한다.

예를 들어 6은 6 = 1 + 2 + 3 으로 완벽한 수이다.

n이 완벽한 수 인지 아닌지 판단해주는 프로그램을 작성하라.
&Input
입력은 테스트 케이스마다 한 줄 간격으로 n이 주어진다. (2 < n < 100, 000)

입력의 마지막엔 -1이 주어진다.
&Output
테스트케이스 마다 한줄에 하나씩 출력해야 한다.

n이 완벽한 수라면, n을 n이 아닌 약수들의 합으로 나타내어 출력한다(예제 출력 참고).

이 때, 약수들은 오름차순으로 나열해야 한다.

n이 완벽한 수가 아니라면 n is NOT perfect. 를 출력한다.
&Example
-input
6
12
28
-1
-output
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;

	while (true) {
		int tmp = 0, cnt = 0;
		int arr[1000] = { 0 };
		cin >> N;
		if (N == -1)break;
		for (int i = 1; i <= N/2; i++) {
			if (N%i == 0){
				arr[cnt++] = i;
				tmp += i;
		}
		
		}
		if (N == tmp) {
			cout << N << " =";
			for (int i = 0; i < cnt; i++)
				if (i == cnt - 1)cout << " " << arr[i] << endl;
				else cout << " " << arr[i] << " +";
		}
		else cout << N << " is NOT perfect." << endl;
	}
	return 0;
}
*/