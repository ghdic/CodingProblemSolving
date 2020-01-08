/*
https://www.acmicpc.net/problem/1275

&Title
1275번 - 커피숍2

&Question
모두 알다시피 동호는 커피숍의 마담이다. (마담이 무엇인지는 본인에게 
물어보도록 하자.)어느 날 커피숍의 손님 A씨가 동호에게 게임을 하자고 
했다.그 게임은 다음과 같은 규칙을 갖는다.N개의 정수가 있으면, 동호는 
다음과 같이 말한다. “3~7번째 수의 합은 무엇이죠?” 그러면 상대방은 
“그 답은 000입니다. 그리고 8번째 수를 2로 고치도록 하죠” 
그러면 동호는 “네 알겠습니다.”라고 한 뒤에 다시 상대방이 동호가 
했던 것처럼 “8~9번째 수의 합은 무엇이죠?”라고 묻게된다. 이 것을 
번갈아 가면서 반복하는 게임이다.당신은 이 게임의 심판 역을 맡았다. 
요컨대, 질문에 대한 답들을 미리 알아야 한다는 것이다.당신의 머리가 
출중하다면 10만개 가량 되는 정수와 10만턴 정도 되는 게임을 
기억할 수 있을 것이다. 몇판 이 게임을 즐기던 동호는 
많은 사람들이 이 게임을 하기를 바라게 되었고, 당신에게 심판 
프로그램을 구현해달라고 요청했다. 

&Input
첫째 줄에 수의 개수 N과 턴의 개수 Q가 
주어진다.(1 ≤ N, Q ≤ 100,000) 둘째 줄에는 처음 
배열에 들어가 있는 정수 N개가 주어진다. 세 번째 줄에서 
Q+2번째 줄까지는 x y a b의 형식으로 x~y까지의 합을 
구하여라, a번째 수를 b로 바꾸어라 라는 뜻의 데이터가 주어진다.입력되는 
모든 수는 32비트 부호있는 정수이다. 

&Output
한 턴마다 구한 합을 한 줄마다 한 개씩 
출력한다. 

&Example
-input
5 2
1 2 3 4 5
2 3 3 1
3 5 4 1

-output
5
10


*/

/*
#include <iostream>
using namespace std;
const int MAX = 100001;

int n, q;
long long tree[MAX * 4];
long long node[MAX];

long long init(int index, int start, int end) {
	if (start == end) {
		return tree[index] = node[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[index] = init(index * 2, start, mid) + init(index * 2 + 1, mid + 1, end);
	}
}

long long query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return query(index * 2, left, right, start, mid) + query(index * 2 + 1, left, right, mid + 1, end);
	}
}

void update(int index, int target, long long diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end) {
		node[target] += diff;
	}
	else {
		int mid = (start + end) / 2;
		update(index * 2, target, diff, start, mid);
		update(index * 2 + 1, target, diff, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> node[i];
	init(1, 1, n);
	int x, y, a, b;
	while (q--) {
		cin >> x >> y >> a >> b;
		if (x > y)
			x ^= y ^= x ^= y;
		cout << query(1, x, y, 1, n) << '\n';
		long long diff = b - node[a];
		update(1, a, diff, 1, n);
	}
	return 0;
}
*/