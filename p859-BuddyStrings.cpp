//
// Created by zy234 on 1/3/19.
//
using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <set>
//my solution: 8ms 43%
/*class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length())
            return false;
        if(A == "" || B == ""){
            return false;
        }
        int cnt=0;
        bool repeatChar = false;
        int alphabet[26]={};
        int swapWord[3];

        for(int i = 0; i < A.length() && cnt <= 2; i++){
            if(A[i] != B[i]){
                swapWord[cnt] = i;
                cnt++;
            }else{
                if(!repeatChar){
                    alphabet[int(A[i]-97)]++;
                    if(alphabet[int(A[i]-97)]>1)
                        repeatChar = true;
                }
            }
        }
        if(cnt == 0){
            return repeatChar;
        }else if (cnt == 2){
            swap(A[swapWord[0]], A[swapWord[1]]);
            return A.compare(B)==0;
        }else{
            return false;
        }
    }
};*/
//my solution: 8ms 43%
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) dif.push_back(i);
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
    }

};

int main() {
    string A = "ab";
    string B = "ab";
    Solution test;
    cout << (test.buddyStrings(A, B) ? "true" : "false") << endl;
}
