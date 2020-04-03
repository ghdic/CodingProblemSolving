// https://www.algospot.com/judge/problem/read/JOSEPHUS

/*
#include <iostream>
#include <list>

using namespace std;

void josephus(int n, int k) {
	// 리스트 준비
	list<int> survivors;
	for (int i = 1; i <= n; ++i)
		survivors.push_back(i);
	// 죽을 사람을 나타내는 포인터
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		// 첫번째 사람이 자살. erase는 지운 다음 원소 반환
		kill = survivors.erase(kill);
		if (kill == survivors.end())
			kill = survivors.begin();
		--n;
		// k-1번 다음 사람으로 옮긴다
		for (int i = 0; i < k - 1; ++i) {
			++kill;
			if (kill == survivors.end())
				kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		josephus(n, k);
	}
	return 0;
}
*/