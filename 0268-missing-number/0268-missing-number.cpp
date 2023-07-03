class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum=nums.size()*(nums.size()+1)/2;
        int s2=0;
        for(int i=0;i<nums.size();i++){
            s2+=nums[i];

        }
        return(sum-s2);
    }
};