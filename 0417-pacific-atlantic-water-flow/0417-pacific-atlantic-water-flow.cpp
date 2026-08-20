class Solution {
public:
    vector<vector<int>> res;
    void atlantic(vector<vector<int>> &heights,int row,int col,vector<vector<int>> &vis){
        int R=heights.size();
        int C=heights[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        if(vis[row][col]==1) 
        {
            res.push_back({row,col});
        }
        if(vis[row][col]==2)return;
        vis[row][col]=2;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C && heights[nr][nc]>=heights[row][col])
            atlantic(heights,nr,nc,vis);
        }
    }
    void pacific(vector<vector<int>> &heights,int row,int col,vector<vector<int>> &vis){
        int R=heights.size();
        int C=heights[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        if(vis[row][col]==1) return;
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C && heights[nr][nc]>=heights[row][col])
            pacific(heights,nr,nc,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));//for storing whether the cell is close to pacific or atlantic
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0)
                pacific(heights,i,j,vis);
            }
        }
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==r-1 || j==c-1)
                atlantic(heights,i,j,vis);
            }
        }
        return res;
    }
};