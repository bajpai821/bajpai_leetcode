class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int n=firstWord.size();
        int m=secondWord.size();
        int x=targetWord.size();
        for(int i=0; i<n; i++) {
            sum1=sum1*10+firstWord[i]-'a';
        }
        for(int i=0; i<m; i++) {
            sum2=sum2*10+secondWord[i]-'a';
        }
        for(int i=0; i<x; i++) {
            sum3=sum3*10+targetWord[i]-'a';
        }
        if(sum1+sum2==sum3) return true;
        else return false;
    }
};