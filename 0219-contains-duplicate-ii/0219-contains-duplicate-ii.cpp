class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
          unordered_set<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        // If current number is already in the set — duplicate found
        if (window.find(nums[i]) != window.end()) {
            return true;
        }

        // Add current number to the set (window)
        window.insert(nums[i]);

        // Maintain window size <= k
        if (window.size() > k) {
            window.erase(nums[i - k]);  // Remove the element out of the window
        }
    }

    return false;
    }
};