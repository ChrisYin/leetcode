//
// Created by zy234 on 1/2/19.
//
using namespace std;
#include <vector>
#include <iostream>
//my solution: 48ms
/*class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size(), 0);
        for(int i=0, even= 0, odd = A.size()-1; i < A.size(); i++){
            if(A[i]%2==0){
                res[even] = A[i];
                //printf("even: %d\n", res[even]);
                even++;
            } else{
                res[odd] = A[i];
                //printf("odd: %d\n", res[odd]);
                odd--;
            }
        }
        return res;
    }
};*/
//quick sort: 36ms
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A);
        int i = 0;
        int j = res.size()-1;
        while(i < j){
            if((res[i] & 0x01) == 0x00){
                //printf("[%d]:%d is even\n", i, res[i]);
                i++;
                continue;
            }
            if((res[j] & 0x01) == 0x01){
                //printf("[%d]:%d is odd\n", j, res[j]);
                j--;
                continue;
            }
            int temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            i++;
            j--;
        }
        return res;
    }
};

int main(){
    vector<int> testArray = {0,1};
    Solution test;
    vector<int> res = test.sortArrayByParity(testArray);
    for(int i = 0; i < res.size(); i++) {
        printf("%d, ", res[i]);
    }
    printf("\n");
}
