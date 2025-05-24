class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = 0, sum = 0;
    int min_len = INT_MAX;

    while (end < n) {
        sum += nums[end];  // window mein end add karo
        end++;

        while (sum >= s) {  // agar sum >= s
            min_len = min(min_len, end - start);  // window size check karo
            sum -= nums[start];  // start hatake window chhota karo
            start++;
        }
    }

    return min_len == INT_MAX ? 0 : min_len;
 
    }
};