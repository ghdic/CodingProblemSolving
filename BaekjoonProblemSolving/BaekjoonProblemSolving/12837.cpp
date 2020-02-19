/*
https://www.acmicpc.net/problem/12837

&Title
12837번 - 가계부 (Hard)

&Question
살아있는 화석이라고 불리는 월곡이는 돈에 찌들려 살아가고 있다. 
그에게 있어 수입과 지출을 관리하는 것은 굉장히 중요한 문제이다. 
스마트폰에 가계부 어플리케이션을 설치해서 사용하려 했지만, 월곡이는 굉장히 오래 
살았기에 원하는 정보를 얻기에는 동작 속도가 너무나도 느렸다. 가끔 
입력을 빼먹은 것이 생기면 다시 추가하고 계산하는 것도 느려서, 
성격이 급한 월곡이는 결국 스마트폰을 부숴버리고 말았다. 월곡이를 도와주는 
프로그램을 작성하기 위해, 아래와 같은 동작들을 처리하는 프로그램을 작성하시오.작성될 
가계부 프로그램은 두 가지 동작을 처리해야 한다. 첫 번째는 
월곡이의 생후 p일에 수입/지출 내용을 추가하는 것이다. 수입은 양수, 
지출은 음수의 형태로 입력이 들어온다. 두 번째는 월곡이의 생후 
p일부터 q일까지 잔고가 변화한 값을 구하고 출력하는 것이다. 월곡이가 
빚을 지고 있을 수도 있기에 어떤 i에 대해서 생후 
i일의 잔고는 음수일 수 있다. 

&Input
첫째 줄에 월곡이가 살아온 날 N, 쿼리의 개수 
Q가 주어진다. (N ≤ 106, Q ≤ 105)둘째 줄부터 
Q+1번째 줄까지는 아래와 같은 형식의 쿼리가 주어진다.1 p x 
: 생후 p일에 x를 추가한다. (1 ≤ p ≤ 
N, -109 ≤ x ≤ 109)2 p q : 
생후 p일부터 q일까지 변화한 양을 출력한다. (1 ≤ p 
≤ q ≤ N) 

&Output
각 2 쿼리에 대해 계산된 값을 각 줄에 
출력한다. 

&Example
-input
10 6
1 3 10000
1 4 -5000
1 7 -3000
2 1 10
1 6 35000
2 4 10

-output
2000
27000


*/

/*
1. p일에 수입 지출 내용을 추가 수입을 양수 지출은 음수
2. 월곡이의 생후 p일부터 q일까지 잔고가 변화한 값을 출력(음수도 ok)
*/
/*
#include <iostream>
using namespace std;
const int MAX = 1000000;

int n, q;
long long tree[MAX * 4];

void update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)return;
	tree[index] += value;
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, value, start, mid);
		update(index * 2 + 1, target, value, mid + 1, end);
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;

	int a, b, c;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b, c, 1, n);
		}
		else {
			cout << query(1, b, c, 1, n) << '\n';
		}
	}

	return 0;
}
*/