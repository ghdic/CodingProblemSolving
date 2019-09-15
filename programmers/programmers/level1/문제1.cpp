
/*
#include <string>
#include <vector>
using namespace std;

int arr[1000001];
int solution(int n) {
	int answer = 0;
	for (int i = 2; i <= n; ++i) {
		if (!arr[i]) {
			for (int j = i + i; j <= n; j += i)
				arr[j] = 1;
		}
	}
	for (int i = 2; i <= n; ++i)
		if (arr[i] == 0)++answer;

	return answer;
}

int main() {

	int res = solution(10);
}
*/