//
// Created by zy234 on 1/3/19.
//
using namespace std;

#include <string>
#include <iostream>
//my solution: 12ms 52%
class Solution {
private:
    bool isVowels(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

public:
    string reverseVowels(string s) {
        int first = 0;
        int last = s.length() - 1;
        while (first < last) {
            while (!isVowels(s[first]) && first < last) {
                first++;
            }
            while (!isVowels(s[last]) && first < last) {
                last--;
            }
            swap(s[first], s[last]);
            first++;
            last--;
        }
        return s;
    }
};

int main() {
    string testString = "hello";
    Solution test;
    cout << "reversed string:" << test.reverseVowels(testString) << endl;
}

