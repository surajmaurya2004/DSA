class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c:t) mp[c]++;
        int l= 0, count=t.size(), start=0,len = INT_MAX;
        for(int r= 0;r<s.size();r++){
            if(mp[s[r]] > 0) count--;
            mp[s[r]]--;
            while(count == 0){
                if(r-l+1 <len){
                    len = r-l+1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count++;
                l++;
            }
        }
        return len==INT_MAX ? "" :s.substr(start,len);
        
    }
};