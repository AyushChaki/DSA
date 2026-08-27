class Solution {
public:
    bool dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,string word,int i,int j,int index){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m)
        return false;
        if(vis[i][j])
        return false;
        if(grid[i][j]!=word[index])
        return false;
        if(index==word.length()-1)
        return true;
        vis[i][j]=1;
        bool found =dfs(grid, vis, word, i + 1, j, index + 1) || dfs(grid, vis, word, i - 1, j, index + 1) ||dfs(grid, vis, word, i, j + 1, index + 1) ||dfs(grid, vis, word, i, j - 1, index + 1);
        vis[i][j]=0;
        return found;

    }
    bool exist(vector<vector<char>>& grid, string word) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                    if(dfs(grid,vis,word,i,j,0))
                    return true;
                }
            }
        }
        return false;
    }
};