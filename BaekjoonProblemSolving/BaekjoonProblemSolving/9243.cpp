/*
https://www.acmicpc.net/problem/9243

&Title
9243번 - 파일 완전 삭제

&Question
어느날, 상근이의 여자친구는 상근이에게 매우 긴급한 목소리로 전화했다."상근아, 
나 급하게 지워야 될 파일이 있어! 이 파일은 절대 
복구되면 안돼."파일을 완전 삭제하려면 하드드라이브에서 그 구간을 새로운 데이터로 
반복해서 덮어써야 한다.상근이는 여자친구를 위해 파일 완전 삭제 프로그램을 
만드려고 한다. 파일 완전 삭제 프로그램은 매우 간단하다. 사용자는 
삭제할 파일을 하나 고르고, 몇 번 덮어씌울지 n을 입력한다. 
n은 1부터 20까지 숫자 중 하나를 골라야 한다. 상근이의 
프로그램은 파일을 비트단위로 덮어씌운다. 한 번 덮어씌울 때, 0인 
비트는 1로, 1인 비트는 0으로 덮어씌운다.상근이는 프로그램을 완성했고 테스트해보려고 
한다. 파일을 삭제하기 전에 파일이 있었던 곳의 비트와 파일을 
삭제한 후에 파일이 있었던 곳의 비트가 주어졌을 때, 프로그램을 
올바르게 작성했는지 출력한다.이 문제에서 파일이 실제로 삭제되었는지는 중요한 것은 
아니다. 따라서, 문제에서 설명한대로 상근이가 프로그램을 작성했으면 삭제가 성공한 
것으로, 그 외의 경우는 모두 실패한 것이다. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
20) 둘째 줄에는 파일을 삭제하기 전에 파일이 있었던 곳의 
비트가 주어지고, 셋째 줄에는 삭제한 후에 비트가 주어진다. 비트는 
0과 1로만 이루어져 있고, 두 문자열의 길이는 같다. 비트는 
최대 1000개의 문자로 이루어져 있다. 

&Output
첫째 줄에 삭제가 성공했으면 "Deletion succeeded"을, 실패했으면 "Deletion 
failed"을 출력한다. 

&Example
-input
1
10001110101000001111010100001110
01110001010111110000101011110001

-output
Deletion succeeded

-input
20
0001100011001010
0001000011000100

-output
Deletion failed


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s, r;
	cin >> N;
	cin >> s;
	cin >> r;
	if (N % 2 == 0) {
		if (s == r)cout << "Deletion succeeded" << endl;
		else cout << "Deletion failed" << endl;
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0')s[i] = '1';
			else if (s[i] == '1')s[i] = '0';
		}
		if (s == r)cout << "Deletion succeeded" << endl;
		else cout << "Deletion failed" << endl;
	}
	return 0;
}
*/