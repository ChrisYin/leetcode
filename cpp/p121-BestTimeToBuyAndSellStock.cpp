//
// Created by zy234 on 1/4/19.
//
using namespace std;
#include <vector>
#include <iostream>
#include <limits>
//my solution: 8ms 54%
//two submit: prices = NULL
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice){
                minPrice = prices[i];
                //cout<<"min price: "<<minPrice<<endl;
            }else if(prices[i]- minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
                //cout<<"max profit: "<<maxProfit<<endl;
            }
        }
        return (maxProfit > 0)?maxProfit:0;
    }
};*/
//clear solution: 8ms 54%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return (maxProfit > 0)?maxProfit:0;
    }
};
int main(){
    vector<int> testArray = {7,6,4,3,1};
    Solution test;
    cout<<"maxprofit: "<<test.maxProfit(testArray)<<endl;
}