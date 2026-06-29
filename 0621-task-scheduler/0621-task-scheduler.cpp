class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                pq.push(freq[i]);
        }
        int t=0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle=n+1;
            for(int i=0;i<cycle;i++){
                if(!pq.empty())
                {
                    int count=pq.top();
                    pq.pop();
                    count--;
                    if(count>0)
                        temp.push_back(count);
                } 
                t++;
                if(pq.empty() && temp.empty())
                    break;
            }
            for(int count:temp)
                pq.push(count);
        }
        return t;
    }
};