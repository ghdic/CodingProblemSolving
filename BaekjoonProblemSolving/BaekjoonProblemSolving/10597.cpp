/*
https://www.acmicpc.net/problem/10597

&Title
10597번 - 순열장난스페셜 저지

&Question
kriii는 1부터 N까지의 수로 이루어진 순열을 파일로 저장해 
놓았다. 모든 수는 10진수로 이루어져 있고, 모두 공백으로 분리되어 
있다.그런데 sujin이 그 파일의 모든 공백을 지워버렸다!kriii가 순열을 복구하도록 
도와주자. 

&Input
첫 줄에 공백이 사라진 kriii의 수열이 주어진다.kriii의 순열은 
최소 1개 최대 50개의 수로 이루어져 있다. 

&Output
복구된 수열을 출력한다. 공백을 잊으면 안 된다.복구한 수열의 
경우가 여러 가지 일 경우, 그 중 하나를 출력한다. 


&Example
-input
4111109876532

-output
4 1 11 10 9 8 7 6 5 3 2


*/
/*
// 1~n까지의 집합 중 섞여있는데 여기서 공백을 구하라는거임
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string s;
int nums[51];
bool check[51];

// index는 현재 문자열 위치, cnt는 nums에 담겨져있는 숫자 개수
void func(int index, int cnt) {
	if (index == s.length()) {
		int last = 0;
		for(int i = 1; i <= 51; ++i)
			if (!check[i]) {
				last = i - 1;
				break;
			}
		if (last != cnt)return;
		cout << nums[0];
		for (int i = 1; i < cnt; ++i)
			cout << ' ' << nums[i];
		exit(0);
	}

	int a = s[index] - '0';
	if (!check[a]) {
		check[a] = true;
		nums[cnt] = a;
		func(index + 1, cnt + 1);
		check[a] = false;
		nums[cnt] = 0;
	}

	if (index < s.length() - 1) {
		int b = s[index + 1] - '0';
		b = 10 * a + b;

		if (b <= 50 && !check[b]) {
			check[b] = true;
			nums[cnt] = b;
			func(index + 2, cnt + 1);
			check[b] = false;
			nums[cnt] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	func(0, 0);
	return 0;
}
*/