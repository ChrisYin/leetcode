//
// Created by zy234 on 1/6/19.
//
using namespace std;

#include <iostream>
#include <limits>
//Time Exceed limit
/*class Solution {
public:
    int mySqrt(int x) {
        int num;
        for(int i = 0; i <= x; i++){
            if(i * i == x){
                num = i;
                break;
            }else if ( i * i > x){
                num= i-1;
                break;
            }
        }
        return num;
    }
};*/
//binary search: 20ms 46%
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x == 1)
            return 1;
        int start = 0, end = x;
        while(start + 1 < end){
            int mid = (start + end)/2;
            if(mid <= x/mid){
                start = mid;
                //cout<<"start:  "<<start<<endl;
            }else{
                end = mid;
                //cout<<"end:  "<<end<<endl;
            }
        }
        return start;
    }
};

int main(){
    Solution test;
    cout<<"sqrt: "<<test.mySqrt(1345234)<<endl;
}
