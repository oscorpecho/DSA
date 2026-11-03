class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char>st;
         int size=0;
         int left=0;
         for(int r=0;r<s.size();r++){
            char c=s[r];
            while(st.contains(c)){
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            size=max(size,r-left+1);
         }
         return size;
    }
};
