class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for(int x : s){
            if(!s.count(x-1)){
                int curr = x;
                int len = 1;
                while(s.count(curr + 1)){
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
        
    }
};