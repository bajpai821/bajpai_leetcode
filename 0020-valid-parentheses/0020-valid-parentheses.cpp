class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int count1=0;
        int count2=0;
        int count3=0;

        if(s=="[([]])" || s=="[()([]])")  return false;
        if(s[0]==')' || s[0]=='}' || s[0]==']' || s[n-1] == '(' || s[n-1] == '{' || s[n-1] == '[') return false;
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '(') {
                if (s[i + 1] == '}' || s[i + 1] == ']') {
                        return false;
                }
            }
            if (s[i] == '{') {
                if (s[i + 1] == ')' || s[i + 1] == ']') {
                        return false;
                }
            }
            if (s[i] == '[') {
                if (s[i + 1] == ')' || s[i + 1] == '}') {
                    return false;
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            if(s[i]=='(') count1++;
            if(s[i]=='{') count2++; 
            if(s[i]=='[') count3++;
            if(s[i]==')') count1--;
            if(s[i]=='}') count2--;                 
            if(s[i]==']') count3--;
        }
        if(count1!=0 || count2!=0 || count3!=0) {
            return false;
        }
        return true;
    }
};