using namespace std;

#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res(0, 0);
        int counterPart;
        vector<int>::iterator it;
        for (int i = 0; i <= nums.size(); i++) {
            if (nums[i] >= target) {
                break;
            }
            counterPart = target - nums[i];
            it = find(nums.begin(), nums.end(), counterPart);
            if (it != nums.end()) {
                res[0] = i;
                res[1] = it - nums.begin();
                return res;
            } else {
                continue;
            }
        }
        return res;
    }

    void main(){

    }

};
