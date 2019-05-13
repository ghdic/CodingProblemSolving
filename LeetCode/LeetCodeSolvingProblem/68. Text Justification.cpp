/*
https://leetcode.com/problems/text-justification/

&Title
68. Text Justification

&Question
Given an array of words and a width maxWidth, form
at the text such that each line has exactly maxWid
th characters and is fully (left and right) justif
ied.
You should pack your words in a greedy approach; t
hat is, pack as many words as you can in each line
. Pad extra spaces ' ' when necessary so that each
 line has exactly maxWidth characters.
Extra spaces between words should be distributed a
s evenly as possible. If the number of spaces on a
 line do not divide evenly between words, the empt
y slots on the left will be assigned more spaces t
han the slots on the right.
For the last line of text, it should be left justi
fied and no extra space is inserted between words.
Note:
A word is defined as a character sequence consisti
ng of non-space characters only.
Each word's length is guaranteed to be greater tha
n 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:
Input:
words = ["This", "is", "an", "example", "of", "tex
t", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:
Input:
words = ["What","must","be","acknowledgment","shal
l","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be 
   " instead of "shall     be",
             because the last line must be left-ju
stified instead of fully-justified.
             Note that the second line is also lef
t-justified becase it contains only one word.
Example 3:
Input:
words = ["Science","is","what","we","understand","
well","enough","to","explain",
         "to","a","computer.","Art","is","everythi
ng","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]

*/

#include "header.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int n = words.size();
		vector<string> result;
		for (int i = 0; i < n; ++i) {
			string s = "";
			while (i < n) {

			}
		}
    }
};
