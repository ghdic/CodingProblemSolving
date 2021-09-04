/*
https://www.acmicpc.net/problem/22193

&Title
	22193번 - Multiply서브태스크출처다국어 

&Question
Write a program that computes a product of 
two non-negative integers A and B. The integers are 
represented in decimal notation and have N and M 
digits, respectively. 

&Input
The first line contains the lengths N and 
M, separated by a space. A is given on 
the second and B on the third line. The 
numbers will not have leading zeros. 

&Output
Output the product of A and B without 
leading zeros. 

&Example
-input
3 4
123
4567

-output
561741

-input
3 1
100
0

-output
0


*/


n, m = map(int, input().split())
a = int(input())
b = int(input())
print(a * b)