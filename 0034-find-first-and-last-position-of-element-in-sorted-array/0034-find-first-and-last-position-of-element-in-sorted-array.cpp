class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int lowerBound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lowerBound == n || nums[lowerBound] != target) {
            return {-1, -1};
        }

        int upperBound = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return {lowerBound, upperBound};
    }
};