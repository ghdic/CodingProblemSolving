/*
https://www.acmicpc.net/problem/11637

&Title
11637번 - 인기 투표

&Question
9694번 한신이는 당내 최고의원을 선출하기 위한 사전 인기 
투표의 결과를 받게 되었다. 하지만 공식 선거를 통해서 당내 
최고의원이 되기위해선 과반수의 표를 받아야 하기 때문에 현재의 인기 
투표 결과를 보고 본 최고의원 선거를 준비하려 한다. 한신이를 
도와 누가 최고 득표자인지, 받은 투표수가 과반수득표인지 아닌지를 빠르게 
판단할수 있도록 도와주자. 

&Input
맨 위 첫번째 줄에 T(1 <T< 500)는 테스트케이스 
수를 의미한다. 각 테스트 케이스의 첫번째 줄에는 n이 주어지고 
n은 후보자 수를 의미하며, 다음 n줄에는 순서대로 각 후보자가 
받은 득표 수를 입력받는다.후보자는 최소 2명에서 10명보다 많지 않으며, 
득표 수는 50000표를 넘지 않으며, 후보자들은 분명 자기 자신을 
찍기 때문에 최소 1표 이상은 받게된다. 

&Output
각 테스트 케이스는 첫번째 줄부터 순서대로 출력된다. 최다 
득표자가 과반수 득표를 했을경우에는 "majority winner R", 절반 이하의 
득표를 하였을 경우엔 "minority winner R"가 되며, 최다 득표자가 
없을때(최다 득표자가 1명 초과일 경우) "no winner"를 출력한다. 이때 
R은 최다 득표자의 후보자 번호를 의미하며, 후보자의 번호는 각 
케이스에서 1, 2, . . . , n 으로 
부여된다. 

&Example
-input
4
3
10
21
10
3
20
10
10
3
10
10
10
4
15
15
15
45

-output
majority winner 2
minority winner 1
no winner
minority winner 4


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n, candidate[11], sum = 0, max = 0, index = 0;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &candidate[j]);
			sum += candidate[j];
			if (max < candidate[j]) {
				max = candidate[j];
				index = j;
			}
		}
		sort(candidate + 1, candidate + n + 1);
		if (candidate[n] == candidate[n - 1]) {
			printf("no winner\n");
		}
		else if (max > sum / 2.0) {
			printf("majority winner %d\n", index);
		}
		else {
			printf("minority winner %d\n", index);
		}
	}

	return 0;
}
*/