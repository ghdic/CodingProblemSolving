/*
https://www.acmicpc.net/problem/5430

&Title
5430번 - AC

&Question
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 
만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 
이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.함수 R은 
배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 
숫자를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 
발생한다.함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, 
"AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 
예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 
버리는 함수이다.배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 
최대 100이다.각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 
주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.다음 
줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ 
n ≤ 100,000)다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 
수가 주어진다. (1 ≤ xi ≤ 100)전체 테스트 케이스에 
주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다. 


&Output
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 
함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 
출력한다. 

&Example
-input
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

-output
[2,1]
error
[1,2,3,5,8]
error


*/

/*
#include <iostream>
#include <string>
using namespace std;

int arr[100001] = {};
int main() {
	int T;
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int N;
		string f, s, k = "";
		cin >> f;
		cin >> N;
		cin >> s;
		if (s == "[]") {
			bool check = false;
			for(int i = 0; i < f.size(); i++)
				if (f[i] == 'D') {
					check = true;
					break;
				}
			if (check) cout << "error\n";
			else cout << "[]\n";
			continue;
		}
		int n = 0;
		for (int i = 1; i < s.size() - 1; i++) {
			if (s[i] == ',') {
				arr[n++] = stoi(k);
				k = "";
			}
			else {
				k += s[i];
			}
		}

		arr[n++] = stoi(k);
		int start = 0, end = n - 1;
		bool error = false, reverse = false;
		for (int i = 0; i < f.size(); i++) {
			if (f[i] == 'R') {
				reverse = reverse ? false : true;
			}
			else if (f[i] == 'D') {
				if (start == end + 1) {
					error = true;
					break;
				}
				if (reverse)--end;
				else ++start;
			}
		}
		if (error)cout << "error\n";
		else if (start == end + 1)cout << "[]\n";
		else {
			if(reverse){
				cout << "[";
				for (int i = end; i > start; --i)
					cout << arr[i] << ",";
				cout << arr[start] << "]\n";
			}
			else {
				cout << "[";
				for (int i = start; i < n - 1; i++)
					cout << arr[i] << ",";
				cout << arr[n - 1] << "]\n";
			}
		}
	}
	return 0;
}
*/

//이거  반례 못찾아서.. 그냥 다른 소스 보기로

/*
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int T, n, pos;
	vector<int>num_arr;
	char arr[400005], func_p[100005];
	scanf("%d", &T);

	while (T--) {
		bool normal = true;
		int pos = 0;
		num_arr.clear();

		scanf("%s %d %s", &func_p, &n, &arr);

		//스트링 토큰화
		char* tmp = strtok(arr, "[,]");
		while (tmp) {
			num_arr.push_back(stoi(tmp));
			tmp = strtok(NULL, "[,]");
		}

		int point = 0, start = 0, end = n;
		for (int i = 0; func_p[i]; ++i) {
			if (start == end && func_p[i] == 'D') {
				normal = false;
				break;
			}

			switch (func_p[i])
			{
			case 'R':
				point = point == start ? end : start;
				break;
			case 'D':
				point = point == start ? ++start : --end;
				break;
			}
		}

		if (!normal)
			printf("error\n");
		else {
			printf("[");

			if (point == start && start != end) {
				for (int j = start; j < end - 1; j++)
					printf("%d,", num_arr[j]);
				printf("%d", num_arr[end - 1]);
			}
			else if (start != end) {
				for (int j = end - 1; j > start; j--)
					printf("%d,", num_arr[j]);
				printf("%d", num_arr[start]);
			}
			printf("]\n");
		}
	}
	return 0;
}
*/