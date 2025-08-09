class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length(); // ✅ Use 'n' consistently
        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);

        // Prefix: count of 'N' from left to right
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (customers[i] == 'N' ? 1 : 0);
        }

        // Suffix: count of 'Y' from right to left
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int minPen = n + 5;
        int result = 0;

        for (int i = 0; i <= n; i++) {
            int penalty = pre[i] + suf[i];
            if (penalty < minPen) {
                minPen = penalty;
                result = i;
            }
        }

        return result;
    }
};
