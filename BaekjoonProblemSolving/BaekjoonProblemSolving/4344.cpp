/*
https://www.acmicpc.net/problem/4344

&Title
4344번 - 평균은 넘겠지

&Question
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 
당신은 그들에게 슬픈 진실을 알려줘야 한다. 

&Input
첫째 줄에는 테스트케이스의 개수 C가 주어진다.둘째 줄부터 각 
테스트케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 
정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 
0보다 크거나 같고, 100보다 작거나 같은 정수이다. 

&Output
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 
반올림하여 소수점 셋째자리까지 출력한다. 

&Example
-input
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

-output
40.000%
57.143%
33.333%
66.667%
55.556%


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int N;
//	double avg = 0;
//	scanf("%d", &N);
//	while (N--) {
//		int k, arr[1000];
//		avg = 0;
//		scanf("%d", &k);
//		for (int i = 0; i < k; i++) {
//			scanf("%d", &arr[i]);
//			avg += arr[i];
//		}
//		avg /= k;
//		int cnt = 0;
//		for (int i = 0; i < k; i++)
//			if (arr[i] > avg)
//				cnt++;
//		printf("%.3lf%%\n", (double)cnt / k * 100);
//	}
//	return 0;
//}
