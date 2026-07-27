class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int first=0,second=0;
    int n=nums.size();
    for(int i=0;i<n;i++){

        if(nums[i]>first){
            second=first;
            first=nums[i];
        }else if (nums[i]>second){
            second=nums[i];
        }
    }
    
    return (first-1)*(second-1);
    }
};