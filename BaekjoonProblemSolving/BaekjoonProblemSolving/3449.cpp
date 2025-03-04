/*
https://www.acmicpc.net/problem/3449

&Title
3449번 - 해밍 거리

&Question
해밍 거리란 두 숫자의 서로 다른 자리수의 개수이다. 
두 이진수가 주어졌을 때, 해밍 거리를 계산하는 프로그램을 작성하시오. 


&Input
입력을 여러 개의 테스트 케이스로 이루어져 있다. 첫째 
줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 
두 줄로 이루어져 있다. 각 줄에는 이진수가 하나씩 주어진다. 
두 이진수는 길이가 서로 같고, 100자리를 넘지 않는다. 

&Output
각 테스트 케이스에 대해서, 해밍 거리를 계산한 뒤, 
"Hamming distance is X."라고 출력한다. X는 해밍 거리이다. 

&Example
-input
4
0
1
000
000
1111111100000000
0000000011111111
101
000

-output
Hamming distance is 1.
Hamming distance is 0.
Hamming distance is 16.
Hamming distance is 2.


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j])
				cnt++;
		}
		cout << "Hamming distance is " << cnt <<"."<< endl;
	}
	return 0;
}
*/