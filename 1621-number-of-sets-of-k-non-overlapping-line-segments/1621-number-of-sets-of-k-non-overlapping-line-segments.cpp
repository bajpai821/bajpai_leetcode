class Solution {
public:
    
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;
        
        long long top = n + k - 1;
        long long bottom = 2 * k; 
        
        long long numerator_mul = 1;
        long long denominator_mul = 1;
        
        for (int i = 0; i < bottom; i++) {
            numerator_mul = (numerator_mul * (top - i)) % MOD;
            denominator_mul = (denominator_mul * (i + 1)) % MOD;
        }
        
        long long ans = (numerator_mul * power(denominator_mul, MOD - 2, MOD)) % MOD;
        
        return ans;
    }
};
