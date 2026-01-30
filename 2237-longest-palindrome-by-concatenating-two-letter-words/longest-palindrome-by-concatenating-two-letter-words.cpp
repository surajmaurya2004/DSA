class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int> mp;

        for (auto &w : words)
            mp[w]++;

        int ans = 0;
        bool center = false;

        for (auto &it : mp) {

            string w = it.first;
            string rev = string(w.rbegin(), w.rend());

            // reverse pair case
            if (w != rev) {
                if (w < rev && mp.count(rev)) {
                    int pairs = min(mp[w], mp[rev]);
                    ans += pairs * 4;
                }
            }
            // same word like "aa"
            else {
                int pairs = mp[w] / 2;
                ans += pairs * 4;

                if (mp[w] % 2 == 1)
                    center = true;
            }
        }

        if (center)
            ans += 2;

        return ans;
    }
};
