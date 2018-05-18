/*
https://www.acmicpc.net/problem/1371

&Title
1371번 - 가장 많은 글자

&Question
영어에서는 어떤 글자가 다른 글자보다 많이 쓰인다. 에를 
들어, 긴 글에서 약 12.31% 글자는 e이다.어떤 글이 주어졌을 
때, 가장 많이 나온 글자를 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄부터 글의 문장이 주어진다. 글은 최대 5000글자로 
구성되어 있고, 공백, 알파벳 소문자, 엔터로만 이루어져 있다. 그리고 
적어도 하나의 알파벳이 있다. 

&Output
첫째 줄에 가장 많이 나온 문자를 출력한다. 여러 
개일 경우에는 알파벳 순으로 앞서는 것부터 모두 공백없이 출력한다. 


&Example
-input
english is a west germanic
language originating in england
and is the first language for
most people in the united
kingdom the united states
canada australia new zealand
ireland and the anglophone
caribbean it is used
extensively as a second
language and as an official
language throughout the world
especially in common wealth
countries and in many
international organizations

-output
a


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int arr[26] = {};
	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z')
				arr[s[i] - 'a']++;
		}
	}
	int max = 0, cnt = 0;
	for (int i = 0; i < 26; i++)
		if (max < arr[i]) {
			max = arr[i];
		}

	for (int i = 0; i < 26; i++)
		if (arr[i] == max)
			printf("%c", i + 'a');
	printf("\n");
	return 0;
}
*/