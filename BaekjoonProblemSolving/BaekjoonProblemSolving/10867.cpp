/*
https://www.acmicpc.net/problem/10867

&Title
10867번 - 중복 빼고 정렬하기

&Question
N개의 정수가 주어진다. 이 때, N개의 정수를 오름차순으로 
정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다. 

&Input
첫째 줄에 수의 개수 N (1 ≤ N 
≤ 100,000)이 주어진다. 둘째에는 숫자가 주어진다. 이 수는 절대값이 
1,000보다 작거나 같은 정수이다. 

&Output
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이 
때, 같은 수는 한 번만 출력한다. 

&Example
-input
10
1 4 2 3 1 4 2 3 1 2

-output
1 2 3 4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, arr[100000] = {};
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);

	printf("%d ", arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i - 1])
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
*/