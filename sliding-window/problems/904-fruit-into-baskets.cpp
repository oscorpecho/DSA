class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int maxlen=0;
        unordered_map<int,int>mp;
        for(int r=0;r<fruits.size();r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                //if fruit count becomes 0, remove from map coz it will still count it in mp.size() tho its quantity is 0
                //like {1, 1}, {2, 1},{3, 1} after this removing 1 means 1,0 now still it will show mp.size() as 3 tho 1 is removed thats why erase it from map
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
