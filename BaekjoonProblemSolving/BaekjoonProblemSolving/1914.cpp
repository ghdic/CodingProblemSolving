/*
https://www.acmicpc.net/problem/1914

&Title
1914번 - 하노이 탑

&Question
세 개의 장대가 있고 첫 번째 장대에는 반경이 
서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 
큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 
번째 장대에서 세 번째 장대로 옮기려 한다.한 번에 한 
개의 원판만을 다른 탑으로 옮길 수 있다.쌓아 놓은 원판은 
항상 위의 것이 아래의 것보다 작아야 한다.이 작업을 수행하는데 
필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 
최소가 되어야 한다.아래 그림은 원판이 5개인 경우의 예시이다. 

&Input
첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 
N (1 ≤ N ≤ 100)이 주어진다. 

&Output
첫째 줄에 옮긴 횟수 K를 출력한다.N이 20 이하인 
입력에 대해서는 두 번째 줄부터 수행 과정을 출력한다. 두 
번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 
빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 
있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다. N이 
20보다 큰 경우에는 과정은 출력할 필요가 없다. 

&Example
-input
3

-output
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3


*/

/*
// 1.맨밑꺼를 제외한 모든 것을 from에서 tmp로 옮김
// 2.맨밑꺼 from에서 to로 옮김
// 3.tmp로 옮겼던 나머지 것들도 tmp -> to로 옮김
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 1000000

void hanoi_tower(int n, int from, int tmp, int to) {
	if (n <= 20) {
		if (n == 1)
			printf("%d %d\n", from, to);
		else {
			hanoi_tower(n - 1, from, to, tmp);
			printf("%d %d\n", from, to);
			hanoi_tower(n - 1, tmp, from, to);
		}
	}
}

int main() {
	int n = 0;
	char k_result[MAX];
	long double pow_d = 2.0, tmp;
	scanf("%d", &n);

	tmp = pow(pow_d, n);
	sprintf(k_result, "%.0Lf", tmp);
	int size = strlen(k_result);
	--k_result[size - 1]; // 48 == '0' 2^n이므로 (2, 4, 8, 6) 사이클반복 1을 빼줘도 내림이 되진 않음
	printf("%s\n", k_result);

	if (n <= 20)
		hanoi_tower(n, 1, 2, 3);
	return 0;
}
*/