/*
https://www.acmicpc.net/problem/2346

&Title
2346번 - 풍선 터뜨리기

&Question
N개의 풍선이 있다. 각 풍선 안에는 -N부터 N까지의 
수가 적혀있는 종이가 들어 있다. 이 풍선들을 다음과 같은 
규칙으로 터뜨린다.우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 
안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 
다음 풍선을 터뜨린다. 양수가 적혀 있을 경우에는 오른쪽으로, 음수가 
적혀 있을 때는 왼쪽으로 이동한다. 풍선은 원형으로 놓여 있다고 
생각한다. 즉, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 
풍선의 오른쪽에 1번 풍선이 있는 것이다. 이동할 때에는 이미 
터진 풍선은 빼고 생각한다.예를 들어 다섯 개의 풍선 안에 
차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자. 
이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 
있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 
적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 
순서대로 터지게 된다. 

&Input
첫째 줄에 자연수 N(1≤N≤1,000)이 주어진다. 다음 줄에는 차례로 
각 풍선 안의 종이에 적혀 있는 수가 주어진다. 편의상 
0은 적혀있지 않다고 가정하자. 

&Output
첫째 줄에 터진 풍선의 번호를 차례로 나열한다. 

&Example
-input
5
3 2 1 -3 -1
-output
1 4 5 3 2

*/

/*
#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> q;
pair<int, int>p;
int N;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		q.push_back(make_pair(i, a));
	}

	int pos = 0, target, a;

	p = q.front();
	q.pop_front();
	cout << p.first;
	target = p.second;
	while (!q.empty()) {
		pos = 0;
		if (target > 0) {

			while (++pos < target) {
				p = q.front(); q.pop_front();
				q.push_back(p);
			}
			p = q.front(); q.pop_front();

		}
		else {
			while (--pos > target) {
				p = q.back(); q.pop_back();
				q.push_front(p);
			}
			p = q.back(); q.pop_back();

		}
		a = p.first;
		target = p.second;
		cout << " " << a;
	}
}
*/