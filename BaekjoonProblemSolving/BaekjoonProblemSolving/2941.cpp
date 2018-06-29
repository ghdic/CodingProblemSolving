/*
https://www.acmicpc.net/problem/2941

&Title
2941번 - 크로아티아 알파벳

&Question
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 
다음과 같이 크로아티아 알파벳을 다음과 같이 변경해서 입력했다.크로아티아 알파벳변경čc=ćc-dždz=ñd-ljljnjnjšs=žz=예를 
들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, 
k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 
알파벳으로 이루어져 있는지 출력한다.dž는 무조건 하나의 알파벳으로 쓰이고, d와 
ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 
목록에 없는 알파벳은 한 글자씩 센다. 

&Input
첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 
'-', '='로만 이루어져 있다.문제 설명에 나와있는 크로아티아 알파벳만 주어진다. 


&Output
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 
있는지 출력한다. 

&Example
-input
ljes=njak

-output
6

-input
ddz=z=

-output
3

-input
nljj

-output
3

-input
c=c=

-output
2


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string arr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
//	string input;
//	int cnt = 0;
//	cin >> input;
//	int i = 0;
//	while (i < input.size()) {
//		bool find = false;
//		for(int j=0;j<8;j++)
//			if (i == input.find(arr[j], i)) {
//				find = true;
//				i += arr[j].size();
//				cnt++;
//				break;
//			}
//		if (!find) {
//			cnt++;
//			i++;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}
