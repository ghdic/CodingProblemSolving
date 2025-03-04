/*
https://www.acmicpc.net/problem/5596

&Title
5596번 - 시험 점수

&Question
대한고등학교에 재학 중인 민국이와 만세는 4과목(정보, 수학, 과학, 
영어)에 대한 시험을 봤습니다. 민국이와 만세가 본 4과목의 점수를 
입력하면, 민국이의 총점 S와 만세의 총점 T 중에서 큰 
점수를 출력하는 프로그램을 작성하세요. 다만, 서로 동점일 때는 민국이의 
총점 S를 출력하세요. 

&Input
입력은 2줄로 이루어져 있습니다.1번째 줄에는 순서대로 민국이의 정보, 
수학, 과학, 영어 점수(정수형)를 입력하는데, 이 때 공백을 끊어서 
구분합니다.2번째 줄에는 마찬가지로 순서대로 만세의 정보, 수학, 과학, 영어 
점수(정수형)를 입력하고 위와 같이 공백을 끊어서 구분합니다. 

&Output
출력은 문제에서 제시했던 방법대로 구하면 됩니다. 

&Example
-input
100 80 70 60
80 70 80 90

-output
320


*/

/*
#include <iostream>
using namespace std;

int main() {
	int s1 = 0, s2 = 0, a;
	for (int i = 0; i < 8; i++) {
		cin >> a;
		if (i < 4) {
			s1 += a;
		}
		else {
			s2 += a;
		}
	}
	if (s1 > s2)cout << s1 << endl;
	else cout << s2 << endl;
	return 0;
}
*/