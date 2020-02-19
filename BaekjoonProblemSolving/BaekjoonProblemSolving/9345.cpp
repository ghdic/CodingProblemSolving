/*
https://www.acmicpc.net/problem/9345

&Title
9345번 - 디지털 비디오 디스크(DVDs)

&Question
최근 유튜브와 같은 온라인 비디오 스트리밍 서비스 때문에 
DVD 대여점들이 자취를 감추고 있다. 이러한 어려운 상황 속에서, 
DVD 대여점 주인들은 실낱같은 희망을 잡고자 인기있는 N개의 DVD들로 
구성된 시리즈를 구매한다(각 DVD들은 0번부터 N-1 까지 이루어져 있다).ACM 
대여점의 주인 원주연 또한 울며 겨자먹기로 인기있는 시리즈물을 구매했고, 
진열을 하기 위해 맞춤형 선반을 주문제작 하였다(맟춤제작이기 때문에 선반의 
번호 또한 0번부터 N-1 까지 이루어져 있다). 주연이는 매우 
정갈한 사람이기 때문에 DVD를 진열할 때 i번 DVD는 i번 
선반에 진열을 한다.이 시리즈의 열렬한 팬인 민호는 주연이네 대여점에 
시리즈가 입고되었다는 소식을 듣고 찾아왔다. 시리즈물은 연속으로 봐야 흥미가 
안떨어지기 때문에 민호는 L번부터 R번까지의 DVD들을 빌리려고 한다. 민호는 
주연이가 매우 정갈한 성격인 것임을 알기에 주연이를 믿고 실제 
DVD들의 번호를 확인하지 않고 L번 선반부터 R번 선반까지 존재하는 
DVD들을 들고 카운터에 가져왔다.그러나, 민호는 간과한 사실이 있다. 주연이네 
대여점에는 진상 손님인 진일이가 찾아온다는 것이였다. 진일이는 선반 A 
에 있는 DVD와 선반 B에 있는 DVD를 서로 바꿔 
놓는다. 이러한 진일이의 몰상식한 행동때문에 민호와 같이 주연이를 믿고 
DVD의 번호를 확인 안하는 선량한 고객들이 피해를 입는 사례들이 
속출하였다. 아무 이유가 없는 묻지마 테러로 인해 가게매출이 떨어질 
위기에 처하자 주연이는 진일이가 보일때마다 쫒아 냈지만, 시도때도없이 찾아오는 
진일이의 진상짓을 막기에는 역부족이였다.이러한 주연이를 보고 안타까운 마음이 든 
민호는 주연이를 위해 프로그램을 작성하기로 결심을 한다. 의욕이 넘치는 
민호의 마음과는 달리 실력이 따라주지 못해 프로그램의 기능은 조촐하기만 
하다. 프로그램의 기능은 다음과 같다.손님이 L번 선반부터 R번 선반까지에 
있는 DVD들을 가져 왔을때 실제로 DVD가 L번부터 R번까지 있나 
확인을 해 줄 수 있다.DVD의 순서는 상관이 없다. 예를 
들어 손님이 2번 선반부터 4번 선반까지에 있는 DVD를 가져왔을 
때 DVD가 2, 3, 4 순서로 진열되어 있건, 4, 
2, 3 순서로 진열되어 있건 상관이 없다는 얘기다. 즉 
L번부터 R번까지의 DVD가 있으면 된다.문제의 단순화를위해 고객이 DVD를 빌려가면, 
그 즉시 시청한뒤 바로 반납한다고 가정한다. 또한 가져다 놓는 
위치는 빌리기 전과 동일하다(4, 3, 2 순서로 진열되어 있었으면 
다시 4, 3, 2 순서로 진열한다). 

&Input
첫 번째 줄에는 테스트 케이스의 수 T가 주어진다. 
(T ≤ 20 인 자연수)각각의 테스트 케이스 첫 번째 
줄에는 DVD들의 수를 의미하는 정수 N 과 대여점에서 일어나는 
사건의 수를 의미하는 정수 K 가 주어진다. (1 ≤ 
N ≤ 100,000 , 1 ≤ K ≤ 50,000)이어서 
대여점에서 일어나는 사건 K 개가 주어진다. 각각의 줄은 세 
정수 Q, A, B 을 포함한다. (Q는 0또는 1이고, 
0 ≤ A ≤ B < N )Q는 0 
일때, 진상 손님 진일이가 A와 B의 DVD를 서로 바꿔 
끼우는 사건을 의미한다. Q가 1 일때는 손님이 선반 A부터 
선반 B에 있는 DVD를 카운터에 가져오는 사건을 의미한다. 위에서도 
언급했듯이 이 사건이 DVD들의 위치를 바꾸는 일은 일어나지 않는다. 


&Output
손님이 DVD를 카운터에 가져왔을 때 손님이 원하는 DVD가 
전부 존재하면, (A번 선반부터 B번 선반까지에 있는 DVD를 전부 
가져왔을 때 순서에 상관없이 A번 DVD부터 B번 DVD까지 있다면) 
"YES"를 출력하고, 그렇지 않다면 "NO"를 출력한다. 

&Example
-input
2
5 8
1 0 4
1 1 2
0 1 3
1 2 2
1 1 3
1 0 0
1 0 2
1 2 4
5 5
0 1 2
0 2 3
0 1 3
1 0 1
1 0 2

-output
YES
YES
YES
YES
YES
NO
NO
YES
NO


*/

/*
dvd 0~n-1개까지 이루어짐
i번 선반은 i번에 진열
진상 손님 진일이가 A, B 서로 바꿔놓음

실제로 L~R번 있는지, 진열 순서는 상관없음

만약 세그트리의 합으로 하는 경우 1 2 3 4 5 6 7 8 9 에서 4~6을
쿼리하기전에 4<->8, 6<->2 해주면 합이 같기 때문에
예외가 발생한다.. 따라서 합으로는 불가..

매번 할때마다 정렬을 해주는건 O(nlogn)이고
최대 최소를 구하는건 O(n) 이므로 최대 최소를 통해 a~b인 경우 최소 a, 최대 b인지 확인하자.
그 안에 값을 신경 안써도 되냐구? 최대 최소가 일치할 경우 안에꺼는 순서만 바뀔 가능성 밖에 없다.
*/

/*
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

struct node {
	int Max, Min;
};

int n, k;
node tree[MAXN * 4];
int arr[MAXN];

node init(int index, int start, int end) {
	if (start == end) {
		tree[index].Max = tree[index].Min = arr[start] = start;
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		node y = init(index * 2 + 1, start, mid);
		node x = init(index * 2 + 2, mid + 1, end);
		tree[index].Max = max(y.Max, x.Max);
		tree[index].Min = min(y.Min, x.Min);
		return tree[index];
	}
}

bool query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return true;
	if (left <= start && end <= right)
		return left <= tree[index].Min && tree[index].Max <= right;
	else{
		int mid = (start + end) / 2;
		return query(index * 2 + 1, left, right, start, mid) && query(index * 2 + 2, left, right, mid + 1, end);
	}
}

node update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	tree[index].Max = max(tree[index].Max, value);
	tree[index].Min = min(tree[index].Min, value);
	if (start == end) {
		arr[target] = tree[index].Max = tree[index].Min = value;
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		node y = update(index * 2 + 1, target, value, start, mid);
		node x = update(index * 2 + 2, target, value, mid + 1, end);
		tree[index].Max = max(y.Max, x.Max);
		tree[index].Min = min(y.Min, x.Min);
		return tree[index];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		init(0, 0, n - 1);
		int q, a, b;
		while (k--) {
			cin >> q >> a >> b;
			if (q == 0) { // 바꿔치기
				int p = arr[a];
				update(0, a, arr[b], 0, n - 1);
				update(0, b, p, 0, n - 1);
			}
			else {
				cout << (query(0, a, b, 0, n - 1) ? "YES\n" : "NO\n");
			}
		}
	}
	return 0;
}
*/