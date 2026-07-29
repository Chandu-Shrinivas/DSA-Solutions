#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    const long long MAX = 1000001; // Cap to prevent overflow beyond max k

    // Computes n Choose k, capped at MAX
    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        k = min(k, n - k);
        long long res = 1;
        for (int i = 1; i <= k; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }
        return res;
    }

    // Calculates total unique arrangements for current half character counts
    long long countArrangements(const vector<int>& count) {
        int total = 0;
        for (int c : count) total += c;

        long long res = 1;
        for (int freq : count) {
            res *= nCk(total, freq);
            if (res >= MAX) return MAX;
            total -= freq;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> halfCount(26, 0);
        string midLetter = "";

        for (int i = 0; i < 26; ++i) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2 == 1) {
                midLetter = string(1, (char)('a' + i));
            }
        }

        long long totalPerm = countArrangements(halfCount);
        if (k > totalPerm) {
            return ""; // k exceeds maximum possible palindromic permutations
        }

        int halfLen = 0;
        for (int c : halfCount) halfLen += c;

        string leftHalf = "";
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;

                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);

                if (arrangements >= k) {
                    leftHalf += (char)('a' + i);
                    break; // Keep character choice and move to next position
                } else {
                    k -= arrangements;
                    halfCount[i]++; // Backtrack and check next character
                }
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + midLetter + rightHalf;
    }
};