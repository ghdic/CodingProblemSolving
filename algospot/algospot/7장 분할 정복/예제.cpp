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