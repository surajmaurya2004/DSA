class Solution {
public:
 
        string removeKdigits(string num,int k){
            stack<char> st;
            for(char c:num){
                while(!st.empty() && k>0 && st.top() > c){
                    st.pop();
                    k--;
                }
                if(!st.empty() || c != '0')
                st.push(c);
            }
            while(!st.empty() && k--) st.pop();
            string res = "";
            while(!st.empty()){
                res +=st.top();
                st.pop();
            }
            reverse(res.begin(), res.end());
            return res.empty() ? "0": res;
        }
        
    
};