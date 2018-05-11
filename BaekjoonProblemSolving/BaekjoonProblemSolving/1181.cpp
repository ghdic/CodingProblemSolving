/*
https://www.acmicpc.net/problem/1181

&Title
1181번 - 단어 정렬

&Question
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 
조건에 따라 정렬하는 프로그램을 작성하시오.길이가 짧은 것부터길이가 같으면 사전 
순으로 

&Input
첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 
줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 
줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다. 


&Output
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 
여러 번 입력된 경우에는 한 번씩만 출력한다. 

&Example
-input
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours

-output
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[20000];
int main() {
	int N;
	cin >> N;
	int maxSize = 0;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		if (maxSize < s[i].size()) {
			maxSize = s[i].size();
		}
	}
	int index = 0;
	for (int i = 1; i <= maxSize; i++) {
		int cnt = index;
		for (int j = 0; j < N; j++) {
			if (s[j].size() == i) {
				swap(s[index++], s[j]);
			}
		}
		sort(s + cnt, s + index);
	}
	cout << s[0] << endl;
	for (int i = 1; i < N; i++) {
		if(s[i]!=s[i-1])
			cout << s[i] << endl;
	}
	return 0;
}
*/