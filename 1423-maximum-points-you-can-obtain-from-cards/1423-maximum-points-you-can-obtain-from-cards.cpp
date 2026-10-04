class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int sum1=0;
        int sum2=0;
        int n=cardPoints.size();
        int maxsum=0;
        for(int i=0;i<k;i++){
            sum1=sum1+cardPoints[i];
        }
        maxsum=max(maxsum,sum1);
        for(int j=0;j<k;j++){
            sum2=sum2+cardPoints[n-1-j];
            sum1=sum1-cardPoints[k-1-j];
            maxsum=max(maxsum,sum1+sum2);
        }
        return maxsum;
    }
};