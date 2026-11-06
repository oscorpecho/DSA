class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int l=0;
        //if s1 string has more elements,it cant be permutation for s2
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]]++;
        }
        for(int r=0;r<s2.size();r++){
            mp2[s2[r]]++;
            if((r-l+1)==k){
                if(mp1==mp2){
                    return true;
                }
                else{
                    mp2[s2[l]]--;
                    //imp condition check coz mp1 != mp2 if zero freq elem are there in mp2
                    if(mp2[s2[l]]==0){
                        mp2.erase(s2[l]);
                    }
                    l++;
                }
            }
        }
        return false;
    }
};

//Mistakes / Learnings – Permutation in String
//- Used a fixed-size sliding window where k = s1.size().
//- Created two frequency maps:
//  - mp1 → frequencies of characters in s1.
//  - mp2 → frequencies of characters in the current window of s2.
//- Used r - l + 1 == k to check when the window reaches the required size.
//- Used mp1 == mp2 to check whether the window is a permutation.
//- Main mistake: Decreased the outgoing character's frequency but didn't erase its key when frequency became zero.
//- Zero-frequency keys still exist in an unordered_map, so map equality can fail.
