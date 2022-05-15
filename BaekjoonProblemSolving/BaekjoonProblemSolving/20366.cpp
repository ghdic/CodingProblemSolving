// https://www.acmicpc.net/problem/20366

/*
지름이 주어진 n개의 눈덩이 중 4개의 눈덩이로 2개로 구성된 눈사람을 2개 만듬
눈사람의 키는 두 눈덩이 지름의 합과 같음
두 눈사람의 키의 차이의 최솟값?

2 3 5 5 9

양끝에 포인터를 두고 범위를 좁혀나간다
맨처음에 2, 9를 선택하고 3, 5 ->  5, 5
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, snow[600];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> snow[i];
	}
	sort(snow, snow + n);
	
	int answer = 2e9;
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 3; j < n; j++) {
			int left = i + 1;
			int right = j - 1;
			int anna = snow[i] + snow[j];
			int elsa = 0;
			while (left < right) {
				elsa = snow[left] + snow[right];
				int result = elsa - anna;
				answer = min(answer, abs(result));

				if (result > 0)
					right = right - 1;
				else
					left = left + 1;
			}
		}
	}

	cout << answer << endl;
}
*/