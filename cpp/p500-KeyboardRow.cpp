//
// Created by zy234 on 1/15/19.
//
using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

//my solution: 0ms 100%
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        //row0:0, row1:1, row2:2
        unordered_map<char, int> wordMap;
        //small case
        wordMap['q'] = 0;
        wordMap['w'] = 0;
        wordMap['e'] = 0;
        wordMap['r'] = 0;
        wordMap['t'] = 0;
        wordMap['y'] = 0;
        wordMap['u'] = 0;
        wordMap['i'] = 0;
        wordMap['o'] = 0;
        wordMap['p'] = 0;
        wordMap['a'] = 1;
        wordMap['s'] = 1;
        wordMap['d'] = 1;
        wordMap['f'] = 1;
        wordMap['g'] = 1;
        wordMap['h'] = 1;
        wordMap['j'] = 1;
        wordMap['k'] = 1;
        wordMap['l'] = 1;
        wordMap['z'] = 2;
        wordMap['x'] = 2;
        wordMap['c'] = 2;
        wordMap['v'] = 2;
        wordMap['b'] = 2;
        wordMap['n'] = 2;
        wordMap['m'] = 2;
        //big case
        for(int i = 'A'; i <= 'Z'; i++){
            unordered_map<char, int>::const_iterator it = wordMap.find((char)(i+32));
            wordMap[(char)i]=it->second;
        }
        unordered_map<char, int>::const_iterator it;
        for(int i = 0; i < words.size(); i++){
            string st = words[i];
            int val = wordMap.find(st[0])->second;
            bool isUniRow = true;
            for(int j = 1; j < st.size(); j++){
                if(wordMap.find(st[j])->second != val){
                    isUniRow = false;
                    break;
                }
            }
            if(isUniRow)
                res.push_back(st);

        }
        return res;

    }
};

int main(){
    vector<string> testStrings = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> res;
    Solution test;
    res = test.findWords(testStrings);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
}