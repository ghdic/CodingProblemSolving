/*
https://www.acmicpc.net/problem/11286

&Title
11286번 - 절댓값 힙

&Question
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.배열에 정수 
x (x ≠ 0)를 넣는다.배열에서 절댓값이 가장 작은 값을 
출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 
여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 
제거한다.프로그램은 처음에 비어있는 배열에서 시작하게 된다. 

&Input
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 
줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 
x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 
0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 
배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다. 


&Output
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 
비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 
경우에는 0을 출력하면 된다. 

&Example
-input
18
1
-1
0
0
0
1
1
-1
-1
2
-2
0
0
0
0
0
0
0

-output
-1
1
0
-1
-1
1
1
-2
2
0


*/

/*
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(int y, int x) {
	int a = abs(y), b = abs(x);
	return ((a == b && y > x) || a > b);
}

class MinHeap {
	int* harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int capacity);

	void MinHeapify(int i);

	int parent(int i) { return (i - 1) / 2; }

	int left(int i) { return (2 * i + 1); }

	int right(int i) { return (2 * i + 2); }

	int extractMin();

	void decreaseKey(int i, int new_val);

	int getMin() { return harr[0]; };

	void deleteKey(int i);

	void insertKey(int k);
};

MinHeap::MinHeap(int cap) {
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k) {
	if (heap_size == capacity) {
		cout << "\n Overflow \n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;
	while (i != 0) {
		
		if (comp(harr[parent(i)], harr[i])) {
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
		else break;
	}
}

void MinHeap::decreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0) {
		if (comp(harr[parent(i)], harr[i])) {
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
		else break;
	}
}

int MinHeap::extractMin() {
	if (heap_size <= 0)
		return 0;
	if (heap_size == 1) {
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);

	return root;
}

void MinHeap::deleteKey(int i) {
	decreaseKey(i, -1e9);
	extractMin();
}

void MinHeap::MinHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && comp(harr[i], harr[l]))
		smallest = l;
	if (r < heap_size && comp(harr[smallest], harr[r]))
		smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	MinHeap mh(100001);
	cin >> n;
	int item;
	while (n--) {
		cin >> item;
		if (item) {
			mh.insertKey(item);
		}
		else {
			cout << mh.extractMin() << '\n';
		}
	}

	return 0;
}
*/