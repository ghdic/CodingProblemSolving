//https://algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <string>
using namespace std;

int aaa(string &s) {
	s[2] = 'k';
	return 0;
}

int main() {
	string s = "abcde";
	const char *a;
	a = s.c_str();
	printf("%c\n", a);
}