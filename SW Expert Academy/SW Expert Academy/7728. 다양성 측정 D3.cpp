/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWq40NEKLyADFARG&categoryId=AWq40NEKLyADFARG&categoryType=CODE

7728. 다양성 측정 D3
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

숫자는 다양성을 가지고 있다. 다양성이란, 숫자를 구성하는 수의 종류를 의미한다.

예를 들어서 1512 라는 숫자는 ‘1’, ‘5’, ‘2’로 구성되어 있기 때문에 다양성이 3이다.

숫자가 주어졌을 때 그 숫자의 다양성을 구하는 프로그램을 작성하라.

[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 100)가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 다양성을 체크하고 싶은 숫자 X(1 ≤ X ≤ 109) 가 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

주어진 숫자의 다양성을 출력하라.

입력
2
1512
20170310 // 테스트 케이스 개수
// 첫 번째 테스트 케이스, X = 1512
  sample_input.txt
출력
#1 3
#2 5 // 첫 번째 테스트 케이스 결과
// 두 번째 테스트 케이스 결과
sample_output.txt
*/

/*
#include <iostream>
using namespace std;

int main() {
	int T, num;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		bool check[10] = {};
		int diversity = 0;
		cin >> num;
		while (num) {
			if (!check[num % 10]) {
				check[num % 10] = true;
				diversity++;
			}
			num /= 10;
		}
		cout << "#" << t + 1 << " " << diversity << "\n";
	}
	return 0;
}
*/