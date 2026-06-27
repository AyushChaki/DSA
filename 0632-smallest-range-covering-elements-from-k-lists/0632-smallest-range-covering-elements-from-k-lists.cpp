class node{
    public:
    int data;
    int row;
    int column;
    node(int d,int r,int c){
        data=d;
        row=r;
        column=c;
    }

};
class compare{
    public:
    bool operator()(node* a,node* b){
        return (a->data > b->data);
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*,vector<node*>,compare> pq;
        int mini;
        int maxi=INT_MIN;
        int r=nums.size();
        int n=nums[0].size();
        for(int i=0;i<r;i++){
            int element=nums[i][0];
            maxi=max(maxi,element);
            pq.push(new node(nums[i][0],i,0));
        }
        mini=pq.top()->data;
        int start=mini;
        int end=maxi;
        while(!pq.empty()){
            node* temp=pq.top();
            pq.pop();
            mini=temp->data;
            if((maxi-mini) < (end-start)){
                start=mini;
                end=maxi;
            }
            int row=temp->row;
            if((temp->column+1)<nums[row].size())
            {
                maxi=max(maxi,nums[row][temp->column+1]);
                pq.push(new node(nums[row][temp->column+1],row,temp->column+1));
            }
            else
            break;
        }
        return {start,end};
    }
};