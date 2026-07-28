class Solution {
public:
    string smallestPalindrome(string s) {

        int n = s.size();

        int left = 0;
        int right = n - 1;

        vector<int> freq(26, 0);

        string result(n, ' ');

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {

            while (freq[i] >= 2) {

                result[left] = char(i + 'a');
                result[right] = char(i + 'a');

                left++;
                right--;

                freq[i] -= 2;
            }

            if (freq[i] == 1) {
                result[n / 2] = char(i + 'a');
            }
        }

        return result;
    }
};