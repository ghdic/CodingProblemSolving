/*
https://www.acmicpc.net/problem/13458

&Title
13458번 - 시험 감독

&Question
총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. 
i번 시험장에 있는 응시자의 수는 Ai명이다.감독관은 총감독관과 부감독관으로 두 
종류가 있다. 총감독관은 한 방에서 감시할 수 있는 응시자의 
수가 B명이고, 부감독관은 한 방에서 감시할 수 있는 응시자의 
수가 C명이다.각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 
여러 명 있어도 된다.각 시험장마다 응시생들을 모두 감시해야 한다. 
이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 
1,000,000)이 주어진다.둘째 줄에는 각 시험장에 있는 응시자의 수 Ai 
(1 ≤ Ai ≤ 1,000,000)가 주어진다.셋째 줄에는 B와 C가 
주어진다. (1 ≤ B, C ≤ 1,000,000) 

&Output
각 시험장마다 응시생을 모두 감독하기 위해 필요한 감독관의 
최소 수를 출력한다. 

&Example
-input
1
1
1 1

-output
1

-input
3
3 4 5
2 2

-output
7

-input
5
1000000 1000000 1000000 1000000 1000000
5 7

-output
714290

-input
5
10 9 10 9 10
7 20

-output
10

-input
5
10 9 10 9 10
7 2

-output
13


*/

/*
// result가 int 범위 넘어 설수 있다는걸 잊다니 흑
#include <iostream>
using namespace std;

int n; // 1<=n<=1,000,000
int exam_class[1000000]; // 1<=Ai<=1,000,000
int b, c; // i<=b,c<=1,000,000
int cache[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> exam_class[i];
	cin >> b >> c;
	int person = 1, val = b;
	for (int i = 1; i < 1000001; ++i) {
		cache[i] = person;
		if (val == i) {
			val += c;
			++person;
		}
	}
	long long result = 0;
	for (int i = 0; i < n; ++i)
		result += cache[exam_class[i]];
	cout << result << endl;
	return 0;
}
*/

/*
// 나눗셈 연산자 안쓰는게 더 빠를줄 알았는데 아닌가보네 ㅜ-ㅜ
#include <cstdio>
#include <sys/stat.h>
#include <sys/mman.h>

#define __BLANK(c) (c == ' ' \
              || c == '\n' \
              || c == '\t' \
              || c == '\v' \
              || c == '\f' \
              || c == '\r')
#define __END(c) (c == '\0')

class Fio {
	size_t len;
	unsigned char* data;
	int pos;
public:
	Fio() : pos(0) {
		struct stat buf;
		fstat(0, &buf);
		len = buf.st_size;
		data = (unsigned char*)mmap(0, len, PROT_READ, MAP_FILE | MAP_PRIVATE, 0, 0);
	}

	inline int readInt() {
		int res = 0;
		int flag = 0;

		while (__BLANK(data[pos])) pos++;

		if (data[pos] == '-') {
			flag = 1;
			pos++;
		}

		while (!__BLANK(data[pos]) && !__END(data[pos])) {
			res = 10 * res + data[pos] - '0';
			pos++;
		}
		return flag ? -res : res;
	}
};

int arr[1000001];

int main() {
	Fio fio;
	int N = fio.readInt();
	for (int i = 0; i < N; i++) {
		arr[i] = fio.readInt();
	}
	int ju = fio.readInt();
	int bu = fio.readInt();
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		arr[i] -= ju;
		ans++;
		if (arr[i] > 0) ans += arr[i] / bu + (arr[i] % bu != 0);
	}
	printf("%lld", ans);
	return 0;
}
*/