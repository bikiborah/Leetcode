class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        long long ans = 1;

        while (n > 0) {
            if (n % 2 == 0) {
                x = (x * x) % MOD;
                n = n / 2;
            }
            else {
                ans = (ans * x) % MOD;
                n--;
            }
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long NoOfEvenPlaces = (n + 1) / 2;
        long long NoOfOddPlaces = n / 2;

        return power(5, NoOfEvenPlaces) * power(4, NoOfOddPlaces) % MOD;
    }
};