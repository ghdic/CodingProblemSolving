/*
https://www.acmicpc.net/problem/9226

&Title
9226번 - 도깨비말

&Question
도깨비말은 언어 유희 중 하나로, 글자를 특정 법칙에 
따라 재구성하는 것을 말한다.영어권에서는 피그라틴어라는 것이 있다. 주로 어린이들이 
많이 쓰는 데, 남들에게 무슨 말인지 모르게 하기 위해 
종종 쓴다. 여기엔 규칙이 있는데, 맨 앞글자가 모음이 아닐때 
까지 맨 앞 글자를 어미로 돌린 후 그 끝에 
ay를 붙여서 완성한다. 예를 들면 frog는 ogfray이 된다. 만약 
맨 앞자음이 없는 apple과 같은 경우는 끝에 ay만 붙여 
appleay가 된다. 또는, 단어에 모음이 없는 경우에도 단어의 끝에 
ay만 붙인다.주어진 단어를 피그라틴어로 바꾸는 프로그램을 작성하시오. 

&Input
한 줄에 하나의 단어씩 주어진다. 그리고 마지막 줄에 
#을 입력받고 끝낸다.주어진 단어는 20자를 넘지 않고 공백없이 소문자로만 
이루어져있다. 여기서 모음이란 'a', 'e', 'i', 'o', 'u' 를 
말한다. 

&Output
한 줄에 하나씩 피그라틴어를 출력한다. 

&Example
-input
frog
apple
pear
#

-output
ogfray
appleay
earpay


*/

/*
#include <cstdio>
#include <cstring>

char s[23], alpha[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	setbuf(stdout, NULL);
	while (true) {
		scanf("%s", s);
		if (strcmp(s, "#") == 0)break;
		int len = strlen(s), count = 0;
		bool check = true;
		while (check) {
			for (int i = 0; i < 5; ++i) {
				if (s[0] == alpha[i]) {
					check = false;
					break;
				}
			}
			if (check) {
				char c = s[0];
				strcpy(s, s + 1);
				s[len - 1] = c;
				++count;
			}
			if (count == len)break;
		}
		s[len] = 'a';
		s[len + 1] = 'y';
		s[len + 2] = '\0';
		printf("%s\n", s);
	}
	
	return 0;
}
*/