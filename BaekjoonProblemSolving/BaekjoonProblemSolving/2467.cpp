/*
https://www.acmicpc.net/problem/2467

&Title
2467번 - 용액스페셜 저지

&Question
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 
용액을 보유하고 있다. 각 용액에는 그 용액의 특성을 나타내는 
하나의 정수가 주어져있다. 산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 
정수로 나타내고, 알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 
나타낸다.같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 
각 용액의 특성값의 합으로 정의한다. 이 연구소에서는 같은 양의 
두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 
한다. 예를 들어, 주어진 용액들의 특성값이 [-99, -2, -1, 
4, 98]인 경우에는 특성값이 -99인 용액과 특성값이 98인 용액을 
혼합하면 특성값이 -1인 용액을 만들 수 있고, 이 용액의 
특성값이 0에 가장 가까운 용액이다. 참고로, 두 종류의 알칼리성 
용액만으로나 혹은 두 종류의 산성 용액만으로 특성값이 0에 가장 
가까운 혼합 용액을 만드는 경우도 존재할 수 있다.산성 용액과 
알칼리성 용액의 특성값이 정렬된 순서로 주어졌을 때, 이 중 
두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 
가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오. 

&Input
첫째 줄에는 전체 용액의 수 N이 입력된다. N은 
2 이상 100,000 이하의 정수이다. 둘째 줄에는 용액의 특성값을 
나타내는 N개의 정수가 빈칸을 사이에 두고 오름차순으로 입력되며, 이 
수들은 모두 -1,000,000,000 이상 1,000,000,000 이하이다. N개의 용액들의 특성값은 
모두 서로 다르고, 산성 용액만으로나 알칼리성 용액만으로 입력이 주어지는 
경우도 있을 수 있다. 

&Output
첫째 줄에 특성값이 0에 가장 가까운 용액을 만들어내는 
두 용액의 특성값을 출력한다. 출력해야 하는 두 용액은 특성값의 
오름차순으로 출력한다. 특성값이 0에 가장 가까운 용액을 만들어내는 경우가 
두 개 이상일 경우에는 그 중 아무것이나 하나를 출력한다. 


&Example
-input
5
-99 -2 -1 4 98

-output
-99 98


*/

/*
#include <iostream>
using namespace std;

int n, Min = 2e9, resA, resB;
int arr[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		int l = 0, r = n, idx;
		while (r - l >= 1) {
			int mid = (l + r) / 2;
			if (arr[mid] == (-1 * arr[i])) {
				idx = mid;
				break;
			}
			else if (arr[mid] < (-1 * arr[i]))
				l = mid + 1;
			else if (arr[mid] > (-1 * arr[i]))
				r = mid;
			idx = mid;
		}
		if (i == idx)continue;
		int tmp_num = arr[i] + arr[idx];
		if (tmp_num < 0)
			tmp_num = -1 * tmp_num;
		if (Min > tmp_num) {
			Min = tmp_num;
			if (arr[i] > arr[idx]) {
				resA = arr[idx];
				resB = arr[i];
			}
			else {
				resA = arr[i];
				resB = arr[idx];
			}
		}
	}
	cout << resA << " " << resB << '\n';
	return 0;
}
*/

/*
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int a[100000];

char buf[1500000];
inline int readint()
{
	static int i = 0;
	int ret = 0;
	bool flag;
	if (buf[i] == '-')
		flag = ++i != 0;
	else
		flag = false;
	while (buf[i] >= '0')
	{
		ret *= 10;
		ret += buf[i++] - '0';
	}
	return ++i, (flag ? -ret : ret);
}

int main()
{
	fread(buf, 1, sizeof(buf), stdin);
	int n, i;
	n = readint();
	for (i = 0; i < n; i++)
		a[i] = readint();

	int lo = 0, hi = n - 1;
	int x = 0, y = n - 1;
	while (lo < hi)
	{
		if (abs(a[lo] + a[hi]) < abs(a[x] + a[y]))
		{
			x = lo;
			y = hi;
		}
		if (a[lo] + a[hi] > 0)
			hi--;
		else
			lo++;
	}
	cout << a[x] << ' ' << a[y];
}
*/