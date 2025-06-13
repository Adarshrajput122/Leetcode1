class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int n = nums.size();
    double sum = 0, maxAvg = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // Jab tak window size < k hai, hum wait karenge
        if (i >= k - 1) {
            maxAvg = max(maxAvg, sum / k);

            // ab window slide karega — remove i-k+1 element
            sum -= nums[i - k + 1];
        }
    }

    return maxAvg;
    }
};