/*
https://www.acmicpc.net/problem/10874

&Title
10874번 - 이교수님의 시험

&Question
이교수님은 UCPC의 교수이다. 그의 강좌는 선다형 방식으로 이루어지는 
기말고사로 유명하다. 시험에는 총 10문제가 출제되며 학생들은 5개의 보기 
중 가장 답에 가까운 것을 선택해야한다. 이것이 UCPC의 학생들이 
그의 강좌를 좋아하는 이유이다. 하지만, 보통 문제들이 까다로워서 학생들이 
시험에서 만점을 받는 것은 거의 어렵다. 이번 학기에는 놀라운 
일이 일어났다; 그의 한 강좌에서, 시험 문제들의 정답이 특별한 
패턴을 형성하는 것이다! j번째 문제의 정답은 ((j-1) mod 5) 
+1 번이며, 여기서 mod는 나머지 연산을 의미한다. 예를 들어 
첫번째 문제의 정답은 ((1-1) mod 5) +1 = 1로 
1번이며, 여덟번째 문제의 정답은 ((8-1) mod 5) +1 = 
3 으로 3번이 된다. 문제의 번호는 1번부터 10번이며 문제의 
다섯가지 보기는 1번부터 5번까지임을 유의해라.하지만 UCPC의 학생들의 실력은 이 
패턴을 시험 시간동안 깨달았을 정도로 우수하다. 상대적으로 쉬운 앞부분의 
몇 문제를 푼 후, 많은 수의 학생들이 위의 공식을 
발견했고 나머지 어려운 문제들을 실제로 풀지 않고 답할 수 
있었다. 이것은 명확한 부정행위이기 때문에, 이 교수님은 만점을 받은 
학생들을 대상으로 새로운 시험문제로 재시험을 보기로 결정했다. (물론, 새로운 
시험 문제의 답들은 아무런 패턴도 형성하지 않는다.)N명의 학생들의 답안지가 
주어졌을 때, 재시험을 보아야하는 학생의 목록을 구하는 프로그램을 작성해라. 


&Input
첫번째 줄은 시험을 본 학생수를 나타내는 정수 N이 
주어진다.(1 ≤ N ≤ 100)N번째 줄까지는 1에서 5사이에 해당하는 
정수 열개가 주어진다. i번째 줄의 j번째 수는 i번째 학생이 
고른 j번째 문제의 답을 의미한다. (1 ≤ i ≤ 
N, 1 ≤ j ≤ 10)한줄에 입력되는 수들은 공백으로 
구분된다. 

&Output
재시험을 보아야하는 학생의 목록을 오름차순으로 출력한다.각 학생의 번호는 
한줄에 하나씩 출력한다. 

&Example
-input
5
1 1 1 1 1 1 1 1 1 1
1 2 3 4 5 1 2 3 4 5
3 2 2 1 5 1 2 2 2 2
1 2 3 4 5 1 2 3 4 5
1 2 3 4 5 1 2 3 4 5

-output
2
4
5


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N, num = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= 10; j++) {
			int a;
			scanf("%d", &a);
			if (a == ((j - 1) % 5) + 1) {
				cnt++;
			}
		}
		if (cnt == 10)
			printf("%d\n", i);
	}
	return 0;
}
*/