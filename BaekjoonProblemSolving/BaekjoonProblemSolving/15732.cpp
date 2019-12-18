/*
https://www.acmicpc.net/problem/15732

&Title
15732번 - 도토리 숨기기

&Question
HEPC 1등 상금으로 도토리 D개를 받은 욕심많은 다람쥐 
수형이는 자신의 모든 도토리를 뺏기지 않게 보관하려고 한다. 수형이는 
1~N까지의 번호가 붙여있는 N개의 상자를 가지고 있고 이 안에 
도토리를 넣어 다른 다람쥐들이 찾지 못하게 전부 숨기려고 한다. 
방이 너무 많아 도토리가 있는 상자를 모두 외울 수 
없는 수형이는 A번 상자부터 B번 상자까지 C개 간격으로 도토리를 
하나씩 더 넣는 규칙을 만들었다! 다른 다람쥐들이 규칙을 눈치채고 
모든 도토리를 잃는 것이 무서운 나머지 이러한 규칙들을 K개를 
만들어 도토리를 최대한 안전하게 저장해 놓으려고 한다. 예를 들어 
100번 상자부터 150번상자까지 10개 간격으로, 110번 상자부터 150번 상자까지 
15개 간격으로 넣는다면 100, 110, 120, 125, 130, 140, 
150번 상자에 도토리가 있으며 110번 상자와 140번 상자에는 2개의 
도토리가 들어가 있게 된다. 상자 하나에 들어갈 수 있는 
도토리의 개수는 제한이 없으며 앞의 상자부터 최대한 꽉꽉 채워나간다고 
했을 때 마지막 도토리가 들어가 있는 상자의 번호를 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 상자의 개수 N(1 ≤ N ≤ 
1,000,000)과 규칙의 개수 K(1 ≤ K ≤ 10,000), 도토리의 
개수 D(1 ≤ D ≤ 1,000,000,000)가 주어진다. 그 후 
K개 줄에는 A, B, C(1 ≤ C ≤ A 
≤ B ≤ N)가 주어지며 A번 상자부터 B번 상자까지 
C개 간격으로 도토리를 하나씩 넣는 규칙을 뜻한다. D는 모든 
규칙으로 넣을 수 있는 도토리의 수보다 같거나 작다. 

&Output
D개의 도토리를 규칙에 맞게 상자 앞에서부터 넣었을 때 
마지막 도토리가 들어가는 상자의 번호를 출력하시오. 

&Example
-input
200 2 5
100 150 10
110 150 15

-output
125


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

struct rule {
	int a, b, c;
};
int n, k, d;
rule principle[10000];

bool isShort(int last) {
	long long int cnt = 0;

	for (int i = 0; i < k; ++i) {
		if (last < principle[i].a)continue;
		int a = principle[i].a, b = min(principle[i].b, last);
		cnt += (b - a) / principle[i].c + 1;
	}

	return cnt < d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l = 1, r = 0;
	cin >> n >> k >> d;
	for (int i = 0; i < k; ++i) {
		cin >> principle[i].a >> principle[i].b >> principle[i].c;
		r = max(r, principle[i].b);
	}

	while (l <= r) {
		int mid = (l + r) / 2;
		if (isShort(mid)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l << endl;
	return 0;
}
*/