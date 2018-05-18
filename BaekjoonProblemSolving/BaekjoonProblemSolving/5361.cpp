/*
https://www.acmicpc.net/problem/5361

&Title
5361번 - 전투 드로이드 가격

&Question
상근이는 망가진 전투 드로이드를 고치려고 하고 있다. 전투 
드로이드의 각 부품의 가격은 다음과 같다.블래스터 라이플\$350.34시각 센서\$230.90청각 센서\$190.55팔\$125.30다리\$180.90 


&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 
케이스는 음이 아닌 정수 다섯 개(A B C D 
E)로 이루어져 있다.A: 필요한 블래스터 라이플의 개수B: 필요한 시각 
센서의 개수C: 필요한 청각 센서의 개수D: 필요한 팔의 수E: 
필요한 다리의 수 

&Output
각 테스트 케이스 마다, 입력으로 주어진 부품을 모두 
구매하는데 필요한 비용을 소수점 둘째 자리까지 출력한다. 달러 표시도 
출력해야 한다. 정답은 1억보다 작거나 같다. 

&Example
-input
3
20 10 14 3 9
19 17 12 8 10
11 9 8 22 33

-output
$13987.50
$15679.76
$16182.54


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	const double part[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
	int arr[5];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
		double sum = 0.0;
		for (int j = 0; j < 5; j++) {
			sum += arr[j] * part[j];
		}
		printf("$%0.2lf\n", sum);

	}
	return 0;
}
*/