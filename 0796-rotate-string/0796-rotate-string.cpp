class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string ds = s + s;

        if(ds.find(goal) != string::npos ) return true;


        return false;
        
    }
};