using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        //input elements
        for(vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++){
            printf("%d ", nums[it-nums.begin()]);
        }

        vector<int> res;

        sort(nums.begin(), nums.end());

        int counterPart;
        vector<int>::iterator it;
        for (int i = 0; i <= nums.size(); i++) {
            if (nums[i] >= target) {
                break;
            }
            counterPart = target - nums[i];
            it = find(nums.begin(), nums.end(), counterPart);
            if (it != nums.end()) {
                res.push_back(i);
                res.push_back(it - nums.begin());
                return res;
            } else {
                continue;
            }
        }
        return res;
    }
};

int main(){
    vector<int> testArray = {2, 7, 11, 15};
    int target = 26;
    Solution test;
    vector<int> res = test.twoSum(testArray, target);
    printf("%d\n", res[0]);
    printf("[%d %d]: %d + %d = %d\n", res[0], res[1], testArray[res[0]], testArray[res[1]], target);
    return 0;
}
