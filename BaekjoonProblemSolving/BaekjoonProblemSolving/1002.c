/*
https://www.acmicpc.net/problem/1002

&Title
터렛

&Question
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.
첫째 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.

&Output
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.

&Example
-input
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5
-output
2
1
0

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N;
	double x1, y1, x2, y2;
	int r1, r2;
	double R, distance, K;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf %d %lf %lf %d", &x1, &y1, &r1, &x2, &y2, &r2);
		R = r1 + r2;
		K = abs(r1 - r2);
		distance = sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));

		if (r1 == 0 || r2 == 0) // 예외
			printf("1\n");
		else if (distance == 0 && r1 == r2)
			printf("-1\n");
		else if (K < distance && distance < R) //두점에서 만나는 경우
			printf("2\n");
		else if (K == distance || R == distance) // 한점에서 만나는 경우
			printf("1\n");
		else if (R < distance || distance < K || (distance == 0 && r1 != r2)) // 만나지 않는경우
			printf("0\n");
		
	}
	return 0;
}
*/