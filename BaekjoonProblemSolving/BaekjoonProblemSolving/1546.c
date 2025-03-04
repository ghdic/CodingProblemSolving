/*
https://www.acmicpc.net/problem/1546

&Title
평균

&Question
세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 일단 세준이는 자기 점수 중에 최대값을 골랐다. 이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.

예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.

세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

&Input
첫째 줄에 시험 본 과목의 개수 N이 주어진다. 이 값은 1000보다 작거나 같다. 둘째 줄에 세준이의 현재 성적이 주어진다. 이 값은 100보다 작거나 같은 음이 아닌 정수이고, 적어도 하나의 값은 0보다 크다.

&Output
첫째 줄에 새로운 평균을 출력한다. 정답과의 절대/상대 오차는 10-2까지 허용한다.

&Example
-input
3
40 80 60
-output
75.00

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, max=0;
	int *a;
	float sum = 0.0f;
	scanf("%d", &N);
	a = (int *)malloc(sizeof(int)*N);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (max < a[i])
			max = a[i];
	}

	for (int i = 0; i < N; i++) {
		sum += (float)(a[i] * 100) / max;
	}
	printf("%.2f\n", (float)sum / N);

	free(a);
	return 0;
}
*/