class Solution {
public:

    bool solve(vector<int> &matchsticks,int side,vector<int>&sides,int index){
        if(index==matchsticks.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            if(i>0 && sides[i]==sides[i-1])
            continue;
            if(sides[i]+matchsticks[index]<=side){
            sides[i]+=matchsticks[index];
            if(solve(matchsticks,side,sides,index+1))
            return true;
            sides[i]-=matchsticks[index];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int s=0;
        sort(matchsticks.begin(),matchsticks.end());
        for(int j=0;j<matchsticks.size();j++){
            s=s+matchsticks[j];
        }
        if(s % 4 != 0)
            return false;
        int side=s/4;
        vector<int>sides(4,0);
        return solve(matchsticks,side,sides,0);       
    }
};