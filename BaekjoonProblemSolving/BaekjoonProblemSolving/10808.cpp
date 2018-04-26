/*
https://www.acmicpc.net/problem/10808

&Title
10808번 - 알파벳 개수

&Question
알파벳 소문자로만 이루어진 단어 S가 주어진다. 이 때, 
각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 
넘지 않으며, 알파벳 소문자로만 이루어져 있다. 

&Output
단어에 포함되어 있는 a의 개수, b의 개수, …, 
z의 개수를 공백으로 구분해서 출력한다. 

&Example
-input
baekjoon

-output
1 1 0 0 1 0 0 0 0 1 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int arr[26] = { 0 };
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		arr[N[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
		if (i == 25)cout << arr[i];
		else cout << arr[i] << " ";
		cout << endl;
	return 0;
}
*/