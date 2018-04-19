/*
https://www.acmicpc.net/problem/10984

&Title
내 학점을 구해줘
&Question
게으른 근우는 열심히 놀다가 문득, 자신의 학점 평균이 얼마일지 궁금해졌다. 학사시스템도 들어가기 귀찮아하는 근우를 위해 구해주도록 하자.
&Input
첫 번째 줄에 학기의 수 T가 주어진다. 두 번째 줄부터 T개 학기에 대한 정보가 주어진다.

각 학기에 대한 정보는 다음과 같이 구성되어 있다. 첫 번째 줄에 들었던 과목의 수 N이 주어지고, 다음 N개 줄에 걸쳐서 N개 과목들의 학점 C와 성적 G가 주어진다. (1 ≤ N ≤ 10, 1 ≤ C ≤ 6의 정수. G는 0과 x-0.3, x, x+0.3 (x=1, 2, 3, 4) 중 하나로 주어진다.)
&Output
각 학기에 대해 근우의 총 학점과 평점(GPA)을 출력한다. 평점은 소수점 아래 두 번째 자리에서 반올림한다.
&Example
-input
2
4
3 4.3
2 2.0
4 0.0
2 4.0
3
4 0.0
4 0.0
3 0.0
-output
11 2.3
11 0.0
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, S, score, a;
	float sum, b;
	cout.setf(ios::fixed);
	cout.precision(1);
	cin >> N;
	for (int i = 0; i < N; i++) {
		score = 0, sum = 0.0f;
		cin >> S;
		for (int j = 0; j < S; j++) {
			cin >> a >> b;
			score += a;
			sum += a * b;
		}
		cout << score << " " << sum / score << endl;
	}
	return 0;
}
*/