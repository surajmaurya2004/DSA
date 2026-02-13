class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        
        if(s.length() < p.length()) return result;
        
        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);
        
        // Frequency of pattern
        for(char ch : p) {
            pCount[ch - 'a']++;
        }
        
        int windowSize = p.length();
        
        for(int i = 0; i < s.length(); i++) {
            
            // Add current character
            windowCount[s[i] - 'a']++;
            
            // Remove character if window exceeds size
            if(i >= windowSize) {
                windowCount[s[i - windowSize] - 'a']--;
            }
            
            // Compare frequencies
            if(windowCount == pCount) {
                result.push_back(i - windowSize + 1);
            }
        }
        
        return result;
    }
};
