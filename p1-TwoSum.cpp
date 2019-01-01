using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>

//using sort
/*class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> res;

        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int counterPart;
        vector<int>::iterator it;
        for (int i = 0; i <= temp.size(); i++) {
            if (temp[i] >= target) {
                break;
            }
            counterPart = target - temp[i];

            it = find(temp.begin()+i+1, temp.end(), counterPart);
            if (it != temp.end()) {
                res.push_back(find(nums.begin(), nums.end(), temp[i]) - nums.begin());
                res.push_back(find(nums.begin(), nums.end(), temp[it - temp.begin()]) - nums.begin());
                return res;
            } else {
                continue;
            }
        }
        return res;
    }
};*/

//not using sort
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> tempNums = nums;
        vector<int> res;
        vector<int>::iterator it;
        for(int i = nums.size()-1 ; i >= 0; i--){
            int counterPartNum = target - nums[i];
            tempNums.pop_back();
            //printf("find vector: ");
            for(int j = 0; j < tempNums.size(); j++){
                //printf("%d ", tempNums[j]);
            }
            //("\n");
            //printf("find num: %d\n", counterPartNum);
            it = find(tempNums.begin(), tempNums.end(), counterPartNum);
            if (it != tempNums.end()) {
                res.push_back(i);
                res.push_back(it - tempNums.begin());
                //printf("res: %d %d\n", i, it - tempNums.begin());
                return res;
            }
        }
        return res;
    }
};

int main(){
    vector<int> testArray = {2, 7, 11, 15, 3 , 5, 10};
    int target = 26;
    //input elements
    for(int i = 0; i < testArray.size(); i++){
        printf("%d ", testArray[i]);
    }
    printf("\n");

    Solution test;
    vector<int> res = test.twoSum(testArray, target);
    printf("[%d %d]: %d + %d = %d\n", res[0], res[1], testArray[res[0]], testArray[res[1]], target);
    return 0;
}
