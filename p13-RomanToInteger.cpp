//
// Created by zy234 on 1/3/19.
//
using namespace std;
#include <string>
#include <stdexcept>
//my solution: 72ms 48% 
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            switch (s[i]){
                case 'I':
                    if(s[i+1] == 'V'){
                        res += 4;
                        i++;
                    }else if (s[i+1] == 'X'){
                        res += 9;
                        i++;
                    } else{
                        res += 1;
                    }
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'X':
                    if(s[i+1] == 'L'){
                        res += 40;
                        i++;
                    }else if (s[i+1] == 'C'){
                        res += 90;
                        i++;
                    }else{
                        res += 10;
                    }
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'C':
                    if(s[i+1] == 'D'){
                        res += 400;
                        i++;
                    }else if (s[i+1] == 'M'){
                        res += 900;
                        i++;
                    }else {
                        res += 100;
                    }
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'M':
                    res += 1000;
                    break;
                default:
                    throw runtime_error("undefined roman character\n");
            }
            //printf("%d\n", res);
        }
        return res;
    }
};

int main(){
    string s = "III";
    Solution test;
    int res = test.romanToInt(s);
    printf("res: %d\n", res);
}