class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum=0,rightsum=0,maxsum=0;
        for(int i=k-1;i>=0;i--){
            leftsum+=cardPoints[i];
            maxsum=leftsum;
        }
        int rightindex=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            leftsum-=cardPoints[i];
            rightsum+=cardPoints[rightindex];
            rightindex--;
            maxsum=max(maxsum,leftsum+rightsum);
        }
        return maxsum;
    }
};