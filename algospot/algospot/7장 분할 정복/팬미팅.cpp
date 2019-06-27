////https://algospot.com/judge/problem/read/FANMEETING
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
////정규화 생략
///*
////num[]의 자릿수 올림을 처리한다
//
//void normalize(vector<int> &num)
//
//{
//	num.push_back(0);
//	//자릿수 올림을 처리한다
//	for (int i = 0; i < num.size() - 1; i++) //num.size()-1 중요
//	{
//		if (num[i] < 0)
//		{
//			int borrow = (abs(num[i]) + 9) / 10;
//			num[i + 1] -= borrow;
//			num[i] += borrow * 10;
//		}
//		else
//		{
//			num[i + 1] += num[i] / 10;
//			num[i] %= 10;
//		}
//	}
//
//	while (num.size() > 1 && num.back() == 0)
//		num.pop_back();
//}
//*/
//
//vector<int> multiply(const vector<int>&a, const vector<int>&b) {
//	vector<int> c(a.size() + b.size() + 1, 0);
//	for (int i = 0; i < a.size(); ++i)
//		for (int j = 0; j < b.size(); ++j)
//			c[i + j] += (a[i] * b[j]);
//	//normalize(c);
//	return c;
//}
//
//void addTo(vector<int> &a, const vector<int> &b, int k) {
//	int length = b.size();
//	a.resize(max(a.size(), b.size() + k));
//
//	for (int i = 0; i < length; ++i)
//		a[i + k] += b[i];
//	//정규화 생략
//	/*
//	for (int i = 0; i < a.size(); ++i) {
//		if (a[i] > 10) {
//			a[i + 1] += a[i] / 10;
//			a[i] %= 10;
//		}
//	}
//	*/
//}
//
//void subFrom(vector<int> &a, const vector<int> &b) {
//	int length = b.size();
//	a.resize(max(a.size(), b.size()) + 1);
//
//	for (int i = 0; i < length; ++i)
//		a[i] -= b[i];
//	//정규화 생략
//	/*
//	for(int i=0;i<a.size();++i){
//		if(a[i]<0){
//			a[i]+=10;
//			a[i+1]-=1;
//		}
//	}
//	*/
//}
//
//vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
//	int an = a.size(), bn = b.size();
//
//	if (an < bn)
//		return karatsuba(b, a);
//
//	if (an == 0 || bn == 0)
//		return vector<int>();
//
//	if (an <= 50)
//		return multiply(a, b);
//	int half = an / 2;
//
//	vector<int> a0(a.begin(), a.begin() + half);
//	vector<int> a1(a.begin() + half, a.end());
//	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
//	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
//
//	vector<int> z2 = karatsuba(a1, b1);
//	vector<int> z0 = karatsuba(a0, b0);
//
//	addTo(a0, a1, 0);
//	addTo(b0, b1, 0);
//
//	vector<int> z1 = karatsuba(a0, b0);
//	subFrom(z1, z0);
//	subFrom(z1, z2);
//
//	vector<int> result;
//	addTo(result, z0, 0);
//	addTo(result, z1, half);
//	addTo(result, z2, half + half);
//	return result;
//}
//
//int hugs(const string &members, const string &fans) {
//	int N = members.size(), M = fans.size();
//	vector<int> A(N), B(M);
//	for (int i = 0; i < N; ++i)A[i] = (members[i] == 'M');
//	for (int i = 0; i < M; ++i)B[M - i - 1] = (fans[i] == 'M');
//
//	vector<int> C = karatsuba(A, B);
//	int allHugs = 0;
//	for (int i = N - 1; i < M; i++)
//		if (C[i] == 0)
//			allHugs++;
//	return allHugs;
//}
//
//int main() {
//	int C;
//	cin >> C;
//	if (C < 0 || C>20)
//		exit(-1);
//
//	for (int i = 0; i < C; i++) {
//		string members, fans;
//		cin >> members >> fans;
//		if (members.size() < 1 || fans.size() < 1 || members.size() > 200000 || fans.size() > 200000)
//			exit(-1);
//		cout << hugs(members, fans) << endl;
//	}
//	return 0;
//}
