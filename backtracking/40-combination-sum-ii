class Solution {
public:
    vector<vector<int>>res;
    vector<int>nums;
    void backtrack(int start,int remaining,vector<int>&path){
        if(remaining<0){
            return;
        }
        if(remaining==0){
            res.push_back(path);
        }
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
            continue;
        }
            path.push_back(nums[i]);
            backtrack(i+1,remaining-nums[i],path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        nums=candidates;
        backtrack(0,target,path);
        return res;
    }
};
