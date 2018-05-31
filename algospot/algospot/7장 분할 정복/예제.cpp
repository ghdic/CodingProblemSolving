/*
7.1 1부터 n까지의 합을 구하는 분할 정복 알고리즘

//필수 조건: n은 자연수
//1 + 2 + ... + n 을 반환한다.
int fastSum(int n){
	//기저 사례
	if(n == 1) return 1;
	if(n % 2 == 1) return fastSum(n-1) + n;
	return 2*fastSum(n/2) + (n/2)*(n/2);
}
//fastSum(n) = 2 * fastSum(n/2) + n^2/2 (n이 짝수일때)
*/

/*
7.2 행렬의 거듭제곱을 구하는 분할 정복 알고리즘
//정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정하자.
class SquareMatrix;
//n*n 크기의 항등 행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);
//A^m을 반환한다.
SquareMatrix pow(const SquareMatrix &A, int m){
	//기저 사례:A^0=I
	if(m == 0) return identity(A.size());
	if(m % 2 > 0) return pow(A, m-1) * A;
	SquareMatrix half = pow(A, m / 2);
	//A^m = (A^(m/2)) * (A^(m/2))
	return half * half;
*/

/*
7.3 두 큰 수를 곱하는 O(n^2)시간 알고리즘
//num[]의 자릿수 올림을 처리한다.
void normalize(vector<int>&num) {
	num.push_back(0);
	//자릿수 올림을 처리한다.
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	if (num.back() == 0) num.pop_back();
}
//두 긴 자연수의 곱을 반환한다.
//각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
//예: mulitply({3,2,1}, {6,5,4}) = 123*456 = 56088 = {8, 8 ,0, 6, 5}
vector <int> multiply(const vector<int>&a, const vector<int>&b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}
*/

/*
//7.4 카라츠바의 빠른 정수 곱셈 알고리즘
//a+=b*(10^k); 를 구현한다.
void addTo(vector<int>&a, const vector<int>&b, int k);
//a-=b;를 구현한다. a>=b를 가정한다.
void subFrom(vector<int>&a, const vector<int>&b);
//두 긴 정수의 곱을 반환한다.
vector<int> karatsub(const vector<int>&a, const vector<int>&b) {
	int an = a.size(), bn = b.size();
	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn) return karatsub(b, a);
	//기저 사례: a나 b가 비어 있는 경우
	if (an == 0 || bn == 0)return vector<int>();
	//기저 사례:a나 b가 비교적 짧은 경우 O(n^2)곱셈으로 변경한다.
	if (an <= 50)return multiply(a, b);
	int half = an / 2;
	//a와 b를 밑에서 half 자리와 나머지로 분리한다.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	//z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);
	//z0 - a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	//a0 = a0 + a1; b0 = b0 + b1
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	//z1 = (a0 * b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	//ret = z0 + z1 * 10^half + z2 * 10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;

}
*/

