class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return "";

        unordered_map<int, int> countStr, win;

        for (char ch : t) {
            countStr[ch]++;
        }

        int res = INT_MAX;
        pair<int, int> resIdx = {-1, -1}; 
        
        int l = 0, r = 0;
        int have = 0, need = countStr.size();

        while(r < s.size()) {
            char c = s[r];
            win[c]++;

            if (countStr.count(c) && win[c] == countStr[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < res) {
                    res = r - l + 1;
                    resIdx = {l, r};
                }
                
                win[s[l]]--;
                if (countStr.count(s[l]) && win[s[l]] < countStr[s[l]]) {
                    have--;
                }
                l++;
            }
            r++;
        }

        return res == INT_MAX ? "" : s.substr(resIdx.first, res);
    }
};
