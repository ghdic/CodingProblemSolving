/*
#include <iostream>
#define MAX(a,b) ((a) < (b) ? (b) : (a))
using namespace std;

int arr[101][101];
int cnt[101][101];
int main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++)
			cnt[1][i] = 1;
		for (int i = 2; i <= n; i++) {
			arr[i][1] = arr[i][1] + arr[i - 1][1];
			cnt[i][1] = cnt[i - 1][1];
			for (int j = 2; j < i; j++) {
				if (arr[i - 1][j - 1] < arr[i - 1][j]) {
					arr[i][j] = arr[i][j] + arr[i - 1][j];
					cnt[i][j] = cnt[i - 1][j];
				}
				else if (arr[i - 1][j - 1] > arr[i - 1][j]) {
					arr[i][j] = arr[i][j] + arr[i - 1][j - 1];
					cnt[i][j] = cnt[i - 1][j - 1];
				}
				else {
					arr[i][j] = arr[i][j] + arr[i - 1][j];
					cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j];
				}
				
			}
			arr[i][i] = arr[i][i] + arr[i - 1][i - 1];
			cnt[i][i] = cnt[i - 1][i - 1];
		}
		int result = 0, max = 0;
		for (int i = 1; i <= n; i++) {
			if (max < arr[n][i]) {
				max = arr[n][i];
				result = 0;
			}
			if (max == arr[n][i]) {
				result += cnt[n][i];
			}
		}
		cout << result << "\n";
	}
	return 0;
}
*/
