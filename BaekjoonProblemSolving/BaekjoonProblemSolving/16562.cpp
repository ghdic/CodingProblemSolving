/*
https://www.acmicpc.net/problem/16562

&Title
16562번 - 친구비

&Question
19학번 이준석은 학생이 N명인 학교에 입학을 했다. 준석이는 
입학을 맞아 모든 학생과 친구가 되고 싶어한다. 하지만 준석이는 
평생 컴퓨터랑만 대화를 하며 살아왔기 때문에 사람과 말을 하는 
법을 모른다. 그런 준석이에게도 희망이 있다. 바로 친구비다!학생 i에게 
Ai만큼의 돈을 주면 그 학생은 1달간 친구가 되어준다! 준석이에게는 
총 k원의 돈이 있고 그 돈을 이용해서 친구를 사귀기로 
했다. 막상 친구를 사귀다 보면 돈이 부족해질 것 같다는 
생각을 하게 되었다. 그래서 준석이는 “친구의 친구는 친구다”를 이용하기로 
했다.준석이는 이제 모든 친구에게 돈을 주지 않아도 된다!위와 같은 
논리를 사용했을 때, 가장 적은 비용으로 모든 사람과 친구가 
되는 방법을 구하라. 

&Input
첫 줄에 학생 수 N (1 ≤ N 
≤ 10,000)과 친구관계 수 M (0 ≤ M ≤ 
10,000), 가지고 있는 돈 k (1 ≤ k ≤ 
10,000,000)가 주어진다.두번째 줄에 N개의 각각의 학생이 원하는 친구비 Ai가 
주어진다. (1 ≤ Ai ≤ 10,000, 1 ≤ i 
≤ N)다음 M개의 줄에는 숫자 v, w가 주어진다. 이것은 
학생 v와 학생 w가 서로 친구라는 뜻이다. 

&Output
준석이가 모든 학생을 친구로 만들 수 있다면, 친구로 
만드는데 드는 최소비용을 출력한다. 만약 친구를 다 사귈 수 
없다면, “Oh no”(따옴표 제거)를 출력한다. 

&Example
-input
5 3 20
10 10 20 20 30
1 3
2 4
5 4

-output
20

-input
5 3 10
10 10 20 20 30
1 3
2 4
5 4

-output
Oh no


*/

/*
#include <iostream>
#include <unordered_set>
using namespace std;

int n, m, k;
int money[10001];
int relation[10001];
unordered_set<int> us;

int find(int num) {
	if (relation[num] == num)return num;
	return relation[num] = find(relation[num]);
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a == b)return;
	if (money[a] < money[b])relation[b] = a;
	else relation[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		relation[i] = i;
		cin >> money[i];
	}

	int a, b;
	while (m--) {
		cin >> a >> b;
		merge(a, b);
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		us.insert(find(i));
	}

	for (int k : us)
		sum += money[k];

	if (sum > k)
		cout << "Oh no" << endl;
	else
		cout << sum << endl;
	return 0;
}
*/