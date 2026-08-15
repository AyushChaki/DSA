class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>>&image,int color,int delrows[],int delcol[],int icolor){
        ans[row][col]=color;
        int n=image.size();
        int m =image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrows[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==icolor && ans[nrow][ncol]!=color)
            dfs(nrow,ncol,ans,image,color,delrows,delcol,icolor);           
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrows[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,color,delrows,delcol,icolor);
        return ans;        
    }
};