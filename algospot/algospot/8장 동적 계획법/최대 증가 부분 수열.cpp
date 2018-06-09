//// https://algospot.com/judge/problem/read/LIS
//
//
///*
//정수 수열 S에서 최대 부분 수열의 길이를 구하시오
//*/
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring> //memset
//using namespace std;
//
//int idx; //최대 부분 수열의 길이
//int length; //순열 길이
//int arr[500]; //원래 주어진 순열
//int C[500];
//
////int cache[100]; //list2용
////list3용
////int cache[101]; //index -1을 추가한 캐시(길이를 구할 때 각 위치를 순회하는 코드 생략)
//
//
///*
//
////완전 탐색 알고리즘
//int list(const vector<int> &A)
//{
////기저 사례:A가 텅 비어 있을 때
//if (A.empty())
//return 0;
//int result = 0;
//
//for (int i = 0; i < A.size(); i++)
//{
//vector<int> B;
//for (int j = i + 1; j < A.size(); j++)
//if (A[i] < A[j])
//B.push_back(A[j]);
//result = max(result, 1 + list(B));
//}
//return result;
//}
//
//
//
////메모이제이션 1
////arr[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환
//int list2(int start)
//{
//int &result = cache[start];
//if (result != -1)
//return result;
////항상 arr[start]는 있기 때문에 길이는 최하 1
//result = 1;
//for (int next = start + 1; next < length; next++)
//if (arr[start] < arr[next])
//result = max(result, list2(next) + 1);
//return result;
//}
//
//
////메모이제이션 2
//int list3(int start)
//{
//int &result = cache[start + 1];
//if (result != -1)
//return result;
////항상 arr[start]는 있기 때문에 길이는 최저 1
//result = 1;
//for (int next = start + 1; next < length; next++)
//if (start == -1 || arr[start] < arr[next])
//result = max(result, list3(next) + 1);
//return result;
//}
//*/
//
//
////O(nlogn)에 LIS를 찾을 수 있는 알고리즘
//void list4(int num)
//{
//	if (idx == 0 || (idx>0 && C[idx - 1] <= num)) //해당 숫자가 더 크거나 벡터가 비어있다면
//	{
//		C[idx++] = num;
//		return;
//	}
//
//	//증가 부분 순열에 성립하지 않은 숫자라면 삽입할 위치를 찾는다
//	int front = 0;
//	int rear = idx - 1;
//
//	while (front <= rear) //이진탐색
//	{
//		int mid = (front + rear) / 2;
//
//		if (C[mid] < num)
//			front = mid + 1;
//		else
//			rear = mid - 1;
//	}
//	C[rear + 1] = num;
//}
//
//
//int main(void)
//{
//
//	int test_case;
//	cin >> test_case;
//
//	if (test_case < 0 || test_case>50)
//		exit(-1);
//
//	for (int i = 0; i < test_case; i++)
//	{
//		idx = 0; //최대부분 수열 길이 초기화
//		cin >> length;
//		if (length < 1 || length>500)
//			exit(-1);
//
//		for (int j = 0; j < length; j++)
//
//			cin >> arr[j];
//		for (int j = 0; j < length; j++)
//			list4(arr[j]);
//		cout << idx << endl;
//	}
//	return 0;
//}