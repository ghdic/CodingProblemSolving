/*
https://www.acmicpc.net/problem/17298

&Title
	17298번 - 오큰수

&Question
크기가 N인 수열 A = A1, A2, ..., 
AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 
구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 
중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 
경우에 오큰수는 -1이다.예를 들어, A = [3, 5, 2, 
7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) 
= 7, NGE(4) = -1이다. A = [9, 5, 
4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, 
NGE(3) = 8, NGE(4) = -1이다. 

&Input
첫째 줄에 수열 A의 크기 N (1 ≤ 
N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, 
A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다. 


&Output
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 
구분해 출력한다. 

&Example
-input
4
3 5 2 7

-output
5 7 7 -1

-input
4
9 5 4 8

-output
-1 8 8 -1


*/

/*
#include <iostream>
#include <stack>
using namespace std;

int input[1000000], output[1000000], n;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	output[n - 1] = -1;
	
	for (int i = n - 2; i >= 0; i--) {
		if (input[i] < input[i + 1]) {
			st.push(input[i + 1]);
			output[i] = input[i + 1];
		}
		else {
			while (!st.empty() && input[i] >= st.top()) {
				st.pop();
			}
			if (st.empty()) {
				output[i] = -1;
			}
			else {
				output[i] = st.top();
			}
		}
	}
	cout << output[0];
	for (int i = 1; i < n; i++) {
		cout << " " << output[i];
	}
	return 0;
}
*/