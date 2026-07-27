#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(pair<char, int> p1, pair<char, int> p2) {
        if (p1.second != p2.second)
            return p1.second > p2.second;   // Higher frequency first
        return p1.first < p2.first;         // Lexicographical order if frequencies are equal
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        // Copy map into vector
        vector<pair<char, int>> freq(mp.begin(), mp.end());

        // Sort by frequency
        sort(freq.begin(), freq.end(), comparator);

        // Build answer
        string ans = "";
        for (auto it : freq) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};