/*
https://www.acmicpc.net/problem/1874

&Title
1874번 - 스택 수열

&Question
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 
작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 
입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 
자료가 제일 먼저 나오는 (LIFO, Last in First out) 
특성을 가지고 있다.1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 
하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 
반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 
스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 
어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 
있다. 이를 계산하는 프로그램을 작성하라. 

&Input
첫 줄에 n (1 ≤ n ≤ 100,000)이 
주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 
정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 
나오는 일은 없다. 

&Output
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 
한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 
한다. 불가능한 경우 NO를 출력한다. 

&Example
-input
8
4
3
6
8
7
5
2
1

-output
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-

-input
5
1
2
5
3
4

-output
NO


*/

/*
#include <iostream>
#include <stack>
using namespace std;

int arr[100001] = {};
char result[10001] = {};
int main() {
	int N;
	stack<int> st;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	int a = 1, idx = 0;
	bool check = true;
	st.push(-1);
	for (int i = 1; i <= N;) {
		if (arr[a] == st.top()) {
			result[idx++] = '-';
			st.pop();
			++a;
		}
		else {
			result[idx++] = '+';
			st.push(i++);
		}
	}
	while (idx < N+N) {
		if (arr[a] == st.top()) {
			result[idx++] = '-';
			st.pop();
			++a;
		}
		else {
			check = false;
			break;
		}
	}

	if (!check) cout << "NO\n";
	else for (int i = 0; i < idx; i++)cout << result[i] << "\n";
	return 0;
}

*/

/*
먼저 getchar로 입력시간을 상당히 줄인듯

```
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
	stack<int> st;

	int n, k;
	int num = 0;
	int i, j, buffer_size = 0;
	char *	buffer;
	n = readInt();

	st.push(0);

	buffer = (char *)malloc(sizeof(char) * n * 2 * 2);

	for (i = 0; i < n; i++)
	{
		k = readInt();

		while (st.top() < k)
		{
			st.push(++num);
			buffer[buffer_size] = '+';
			buffer_size++;
			buffer[buffer_size] = '\n';
			buffer_size++;

			if (num > n)
				break;
		}

		if (num > n)
			break;

		while (st.top() >= k)
		{
			buffer[buffer_size] = '-';
			buffer_size++;
			buffer[buffer_size] = '\n';
			buffer_size++;
			st.pop();
		}
	}

	if (i == n)
	{
		buffer[buffer_size - 1] = '\0';
		cout << buffer << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}
```
*/