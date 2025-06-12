class Solution {
public:
    int findLHS(vector<int>& nums) {
         sort(nums.begin(), nums.end());  // Step 1: sort the array
    int start = 0, maxLen = 0;

    for (int end = 0; end < nums.size(); ++end) {
        // Step 2: Slide window if difference > 1
        while (nums[end] - nums[start] > 1) {
            start++;
        }

        // Step 3: If diff == 1, update maxLen
        if (nums[end] - nums[start] == 1) {
            maxLen = max(maxLen, end - start + 1);
        }
    }

    return maxLen; 
    }
};