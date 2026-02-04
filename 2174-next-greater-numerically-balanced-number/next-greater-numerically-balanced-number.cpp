class Solution {
public:
    
    bool isBalanced(int num) {
        vector<int> freq(10, 0);
        
        while (num > 0) {
            freq[num % 10]++;
            num /= 10;
        }
        
        for (int d = 0; d < 10; d++) {
            if (freq[d] != 0 && freq[d] != d)
                return false;
        }
        
        return true;
    }
    
    int nextBeautifulNumber(int n) {
        int num = n + 1;
        
        while (true) {
            if (isBalanced(num))
                return num;
            num++;
        }
    }
};
