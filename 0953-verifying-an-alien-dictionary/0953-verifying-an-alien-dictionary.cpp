class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        for(int i=0;i<order.size();i++){
            rank[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int j=0;
            while(j<w1.size() && j<w2.size() && w1[j]==w2[j])
            j++;
            if(j==w2.size() && j<w1.size())
            return false;
            if(j<w1.size() && j<w2.size()){
                if(rank[w1[j]-'a']>rank[w2[j]-'a'])
                return false;
            }
        }
        return true;
    }
};