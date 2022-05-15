// https://www.acmicpc.net/problem/20366

/*
������ �־��� n���� ������ �� 4���� �����̷� 2���� ������ ������� 2�� ����
������� Ű�� �� ������ ������ �հ� ����
�� ������� Ű�� ������ �ּڰ�?

2 3 5 5 9

�糡�� �����͸� �ΰ� ������ ����������
��ó���� 2, 9�� �����ϰ� 3, 5 ->  5, 5
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