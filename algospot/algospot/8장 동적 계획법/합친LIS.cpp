// https://algospot.com/judge/problem/read/JLIS
/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로
//인위적인 최소치는 64비트여야한다.
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
//min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하ㅏ는
//합친 증가 부분 수열의 최대 길이를 반환한다.
//단 indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정하다.
int jlis(int indexA, int indexB) {
	//메모리제이션
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1)return ret;
	ret = 0;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	//다음 원소를 찾는다.
	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	for (int nextB = indexB + 1; nextB < m; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	return ret;
}

int main() {
	int C;
	cin >> C;
	if (C < 0 || C>50)exit(-1);
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		if (n < 0 || m < 0 || n>100 || m>100)exit(-1);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];

		cout << jlis(-1, -1) << endl;
	}
	return 0;
}
*/