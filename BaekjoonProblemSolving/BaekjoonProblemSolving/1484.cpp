/*
https://www.acmicpc.net/problem/1484

&Title
1484번 - 다이어트

&Question
성원이는 다이어트를 시도중이다. 성원이는 정말 정말 무겁기 때문에, 
저울이 부셔졌다.성원이의 힘겨운 다이어트 시도를 보고만 있던 엔토피아는 성원이에게 
새로운 저울을 선물해 주었다.성원이는 엔토피아가가 선물해준 저울 위에 올라갔다. 
“안돼!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! G 킬로그램이나 더 쪘어ㅜㅠ”라고 성원이가 말했다. 여기서 말하는 
G킬로그램은 성원이의 현재 몸무게의 제곱에서 성원이가 기억하고 있던 몸무게의 
제곱을 뺀 것이다.성원이의 현재 몸무게로 가능한 것을 모두 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 G가 주어진다. G는 100,000보다 작거나 같은 
자연수이다. 

&Output
첫째 줄부터 한 줄에 하나씩 가능한 성원이의 현재 
몸무게를 오름차순으로 출력한다. 가능한 몸무게가 없을 때는 -1을 출력한다. 
현재 몸무게는 자연수로 떨어지지 않을 수도 있는데, 이런 경우는 
제외해야 한다. 

&Example
-input
15

-output
4
8


*/

/*
#include <iostream>
using namespace std;
const int MAXG = 100000;
int G;
long long p[MAXG + 1];

long long binarySearch(long long val) {
	int left = 1, right = G;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (p[mid] < val) left = mid + 1;
		else if (p[mid] == val)return mid;
		else right = mid - 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> G;
	for (long long i = 1; i <= G; ++i)
		p[i] = i * i;
	bool check = false;
	long long val;
	for (long long i = 1; i <= G; ++i) {
		if (val = binarySearch(i * i + G)) {
			cout << val << '\n';
			check = true;
		}
	}
	if (!check) {
		cout << -1 << '\n';
	}
	return 0;
}
*/

/*
// 아놔 long long i로 안해줘서 오버플로우 ㅡㅡ 다풀어놓고 이분탐색으로 삽질함
#include <iostream>
using namespace std;
const int MAXG = 100000;
int G;
long long p[MAXG + 1];

int main() {
	ios::sync_with_stdio(false);
	cin >> G;
	for (long long i = 1; i <= G; ++i)
		p[i] = i * i;
	bool check = false;
	int left = 1, right = 2;
	while (left < right) {
		long long value = p[right] - p[left];

		if (value == G) {
			cout << right << '\n';
			check = true;
		}
		if (right - left == 1 && value > G)break;
		if (value <= G)right++;
		else left++;
	}
	if (!check) {
		cout << -1 << '\n';
	}
	return 0;
}
*/