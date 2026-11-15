class Solution {
public:
    vector<vector<int>>res;
    void backtrack(vector<int>&nums,vector<bool>&users,vector<int>&path){
        if(path.size()==nums.size()){
            res.push_back(path);
        }
        for(int i=0;i<nums.size();i++){
            if(users[i]){
            continue;
        }
            path.push_back(nums[i]);
            users[i]=true;
            backtrack(nums,users,path);
            path.pop_back();
            users[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        vector<bool>users(nums.size(),false);
        backtrack(nums,users,path);
        return res;
    }
};
