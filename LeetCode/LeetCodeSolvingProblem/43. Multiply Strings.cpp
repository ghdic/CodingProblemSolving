/*
https://leetcode.com/problems/multiply-strings/

&Title
43. Multiply Strings

&Question
Given two non-negative integers num1 and num2 repr
esented as strings, return the product of num1 and
 num2, also represented as a string.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero
, except the number 0 itself.
You must not use any built-in BigInteger library o
r convert the inputs to integer directly.

*/

#include "header.h"

/*
class Solution {
public:
    string multiply(string num1, string num2) {
		string s = "0";
		if (num1 == "0" || num2 == "0" || num1.empty() || num2.empty())
			return s;
		
		for (int i = num2.length() - 1, cnt = 0; i >= 0; i--, cnt++) {
			int a = num2[i] - '0';
			if (a == 0)continue;
			for (int j = num1.length() - 1, cnt2 = 0; j >= 0; j--, cnt2++) {
				string temp = "";
				int b = (num1[j] - '0') * a;
				if (b == 0)continue;
				while (b) {
					temp = char(b % 10 + '0') + temp;
					b /= 10;
				}

				for (int i = 0; i < cnt + cnt2; i++)
					temp = temp + '0';
				s = this->add(s, temp);
			}

		}
		return s;
    }

	string add(string num1, string num2) {
		int sz = num1.length() > num2.length() ? num2.length() : num1.length(), i;
		int n1 = num1.length(), n2 = num2.length();
		string s = "";
		bool up = false;
		for (i = 1; i <= sz; i++) {
			int a = num1[n1 - i] - '0', b = num2[n2 - i] - '0';
			int sum = a + b + up;
			up = false;
			if (sum > 9) {
				up = true;
			}
			s = (char)(sum % 10 + '0') + s;
		}
		if (n1 == n2) {
			if (up) {
				s = '1' + s;
			}
		}
		else {
			while (i <= n1) {
				int sum = num1[n1 - i] - '0' + up;
				up = false;
				if (sum > 9)
					up = true;
				s = (char)(sum % 10 + '0') + s;
				i++;
			}
			while (i <= n2) {
				int sum = num2[n2 - i] - '0' + up;
				up = false;
				if (sum > 9)
					up = true;
				s = (char)(sum % 10 + '0') + s;
				i++;
			}

			if (up) {
				s = '1' + s;
			}
		}
		return s;
	}
};



int main(){
	string num1 = "123";
	string num2 = "124";
	cout << Solution().multiply(num1, num2);
	return 0;
}
*/

/*
&Solution
숫자의 곱을 string으로 구하는 문제...
당연히 testcase에서 어마어마한 범위의 숫자를 준다.
곱할때마다 더하니깐 좀 느리게 짜여진듯.. 타임 오바 했다..

C++
각 자리수가 될 곳에 대한 index에 products라는 배열에 값을 담는다.
그리고 올림이 있을 경우 올림에 대한 처리를 해준다.
그리고 배열의 값을 string으로 바꾸어주면 된다!!
```
class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.length(), n2 = num2.length();
		vector<int>products(n1 + n2);
		for (int i = n1 - 1; i >= 0; i--) {
			for (int j = n2 - 1; j >= 0; j--) {
				int d1 = num1[i] - '0';
				int d2 = num2[j] - '0';
				products[i + j + 1] += d1 * d2;
			}
		}
		int carry = 0;
		for (int i = products.size() - 1; i >= 0; i--) {
			int tmp = (products[i] + carry) % 10;
			carry = (products[i] + carry) / 10;
			products[i] = tmp;
		}
		string s;
		for (int i = 0; i < n1 + n2; i++)
			s = s + char(products[i] + '0');
		while (s.length() != 0 && s[0] == '0') s.erase(s.begin() + 0);
		return s.length() == 0 ? "0" : s;
	}
};
```



C++
요건 faster than 98%인 소스이다.
방식은 같은데 좀더 깔끔하게 짜였다.
```
class Solution {
public:
	string multiply(string num1, string num2) {
		unsigned int l1=num1.size(), l2=num2.size();
		if(l1==0||l2==0||num1=="0"||num2=="0") return "0";
		vector<int> v(l1+l2, 0);

		for(unsigned int i = 0; i<l1; i++) {
			int carry=0;
			int n1=(int)(num1[l1-i-1]-'0');
			for(unsigned int j=0; j<l2; j++) {
				int n2 = (num2[l2-j-1] - '0');
				int sum = n1*n2+v[i+j]+carry;
				carry = sum/10;
				v[i+j]=sum%10;
			}
			if(carry>0)
				v[i+l2]+=carry;
		}
		int start = l1 + l2 - 1;
		while(v[start]==0) start--;
		if(start==-1) return "0";
		string s = "";
		for(int i =start; i>=0;i--)
			s+=(char)(v[i]+'0');
		return s;
	}
};
```
*/