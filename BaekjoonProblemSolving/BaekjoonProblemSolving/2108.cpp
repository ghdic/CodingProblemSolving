/*
https://www.acmicpc.net/problem/2108

&Title
2108번 - 통계학

&Question
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 
N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 
단, N은 홀수라고 가정하자.산술평균 : N개의 수들의 합을 N으로 
나눈 값중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 
그 중앙에 위치하는 값최빈값 : N개의 수들 중 가장 
많이 나타나는 값범위 : N개의 수들 중 최댓값과 최솟값의 
차이N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 
정수의 절댓값은 4,000을 넘지 않는다. 

&Output
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 
반올림한 값을 출력한다.둘째 줄에는 중앙값을 출력한다.셋째 줄에는 최빈값을 출력한다. 
여러 개 있을 때에는 최빈값 중 두 번째로 작은 
값을 출력한다.넷째 줄에는 범위를 출력한다. 

&Example
-input
5
1
3
8
-2
2

-output
2
2
1
10

-input
1
4000

-output
4000
4000
4000
0

-input
5
-1
-2
-3
-1
-2

-output
-2
-2
-1
2


*/

/*
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[500001] = {};
int main() {
	int N;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	double average = arr[0];
	int median = 0, mode = arr[0], range = 0, cnt = 1, val = arr[0], best = 0, check = 0;
	for (int i = 1; i <= N; i++) {
		average += arr[i];
		if (val == arr[i]) {
			cnt++;
		}
		else {
			if (best < cnt) {
				best = cnt;
				mode = val;
				check = cnt;
			}
			else if (best == cnt) {
				if (check == cnt) {
					check++;
					mode = val;
				}
			}
			val = arr[i];
			cnt = 1;
		}
	}
	average /= N;
	median = arr[N / 2];
	range = arr[N - 1] - arr[0];
	printf("%d\n%d\n%d\n%d\n", (int)round(average), median, mode, range);
	return 0;
}
*/