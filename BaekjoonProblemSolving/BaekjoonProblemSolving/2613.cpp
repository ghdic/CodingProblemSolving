/*
https://www.acmicpc.net/problem/2613

&Title
2613번 - 숫자구슬스페셜 저지

&Question
N개의 숫자 구슬이 <그림 1>과 같이 막대에 꿰어져 
일자로 놓여 있다. 이들 구슬은 막대에서 빼낼수 없고 따라서 
바꿀 수 없다. 이 숫자 구슬을 M개의 그룹으로 나누었을 
때 각각의 그룹의 합 중 최댓값이 최소가 되도록 하려 
하다. 예를 들어 세 그룹으로 나눈다고 할 때 <그림 
2>와 같이 그룹을 나누면 그룹의 합은 각각 11, 15, 
18이 되어 그 중 최댓값은 18이 되고, <그림 3>과 
같이 나누면 각 그룹의 합은 각각 17, 12, 15가 
되어 그 중 최댓값은 17이 된다. 숫자 구슬의 배열이 
위와 같을 때는 그룹의 합 중 최댓값이 17보다 작게 
만들 수는 없다. 각 그룹의 합 중 최댓값이 최소가 
되도록 M개의 그룹으로 나누었을 때, 그 최댓값과 각 그룹을 
구성하는 구슬의 개수를 찾아 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 구슬의 개수 N과 그룹의 수 M이 
주어진다. 둘째 줄에는 각 구슬이 적혀진 숫자가 왼쪽부터 차례로 
주어진다. N은 300 이하의 자연수, M은 N이하의 자연수이며, 구슬에 
적혀진 숫자는 100 이하의 자연수이다. 

&Output
각 그룹의 합 중 최댓값이 최소가 되도록 M개의 
그룹으로 나누었을 때 그 최댓값을 첫째 줄에 출력하고, 둘째 
줄에는 각 그룹을 구성하는 구슬의 개수를 왼쪽부터 순서대로 출력한다. 
구슬의 개수를 출력할 때는 사이에 한 칸의 공백을 둔다. 
만약 그룹의 합의 최댓값이 최소가 되도록 하는 경우가 둘 
이상이라면 그 중 하나만을 출력한다. 

&Example
-input
8 3
5 4 2 6 9 3 8 7
-output
17
4 2 2

*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int marble[301];


bool maxMarbleSum(int val) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (marble[i] > val)return false;
		if (sum + marble[i] <= val) {
			sum += marble[i];
		}
		else {
			++cnt;
			sum = marble[i];
		}
	}

	return cnt <= m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> marble[i];
	int l = 1, r = n * 100;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (maxMarbleSum(mid)) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << endl;
	int cnt = 0, sum = 0, group = 1;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		sum += marble[i];
		if (sum > l) {
			ans.push_back(cnt);
			sum = marble[i];
			cnt = 0;
			++group;
		}
		++cnt;
	}
	ans.push_back(cnt);
	int pos = ans.size() - 1;
	while (group < m) {
		if (ans[pos] == 1) {
			--pos;
		}
		else {
			--ans[pos];
			ans.push_back(1);
			++group;
		}
	}
	for (int val : ans) {
		cout << val << " ";
	}
	return 0;
}
*/