class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();
        int count = 0;
        
        int freq[3] = {0}; // a,b,c
        
        int left = 0;
        
        for(int right = 0; right < n; right++){
            
            freq[s[right] - 'a']++;
            
            // jab tak valid hai
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                
                count += (n - right);
                
                freq[s[left] - 'a']--;
                left++;
            }
        }
        
        return count;
    }
};