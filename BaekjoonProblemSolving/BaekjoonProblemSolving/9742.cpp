/*
https://www.acmicpc.net/problem/9742

&Title
	9742번 - 순열출처다국어 

&Question
집합의 순열이란 집합의 서로 다른 원소를 모두 사용해 
만들 수 있는 순서이다. 예를 들어, {2,3,5}의 순열은 다음과 
같다.2 3 52 5 33 2 53 5 25 
2 35 3 2각각의 순열은 숫자로 나타낼 수 있다. 
위의 순열은 사전순으로 쓰여져 있으며, 등장하는 순서를 이용해 나타낸다. 
즉, 3 5 2는 위치 4에 있고, 5 3 
2는 마지막 위치인 6에 있다.{b,e,i,n}으로 만들 수 있는 순열은 
다음과 같다.b e i nb e n ib i 
e nb i n eb n e ib n 
i ee b i ne b n ie i 
b ne i n be n b i e 
n i bi b e ni b n ei 
e b ni e n bi n b ei 
n e bn b e in b i en 
e b in e i bn i b en 
i e b서로 다른 숫자와 문자로 이루어진 집합과 위치가 
주어졌을 때, 그 집합의 순열 중 주어진 위치의 순열을 
구하는 프로그램을 작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 문자열은 
서로 다른 숫자와 알파벳으로 이루어져 있으며, 길이는 최대 10이다. 
또한, 사전순 순서대로 주어진다. 문자열 다음에는 찾아야 하는 위치가 
주어지며, 이 값은 3,628,800보다 작거나 같은 자연수이다. 

&Output
각각의 테스트 케이스마다, 입력으로 주어진 위치에 해당하는 순열을 
공백없이 출력한다. 만약, 해당하는 순열이 없는 경우에는 "No permutation"을 
출력한다. 

&Example
-input
235 4
bein 20
123456 700
mnpqr 130
tuvwxyz 4000

-output
235 4 = 352
bein 20 = nbie
123456 700 = 651342
mnpqr 130 = No permutation
tuvwxyz 4000 = ywuxvzt


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n;

int fact(int num) {
	return num == 1 ? 1 : num * fact(num - 1);
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> s >> n) {
		cout << s << " " << n << " = ";
		if (fact(s.length()) < n)
			cout << "No permutation\n";
		else {
			for (int i = 1; i < n; i++) {
				next_permutation(s.begin(), s.end());
			}
			cout << s << "\n";
		}
		
	}
	return 0;
}
*/