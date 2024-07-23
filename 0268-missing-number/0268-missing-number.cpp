class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0 , xor2=0;
        int n = nums.size() + 1;
         for(int i=0;i<nums.size();i++){
           
            xor2 ^= nums[i];
        }
         
         for(int i=1;i<=nums.size();i++){
            xor1^=i;
         }
         return xor1 ^ xor2;

    }
};