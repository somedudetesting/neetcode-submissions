class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        vector<int> arr(26, 0);
        vector<int> prem(26, 0);
        int winSize = s1.size();
        
        for (int i = 0; i < winSize; i++) {
            arr[s1[i] - 'a']++;
            prem[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == prem[i]) matches++;
        }

        int l = 0, r = winSize;
        while (r < s2.size()) {
            if (matches == 26) {
                return true;
            }

            int idx = s2[r] - 'a';
            prem[idx]++;
            if (arr[idx] == prem[idx]) { // Updating perm makes them match
                matches++;
            } else if (arr[idx] + 1 == prem[idx]) { 
                /* Updating perm makes them not match, i.e they matched previously and now they don't match so we remove a match. if we just used else, then every time they don't appear to match, we would decrement the matches which is now we want. we only want to remove a match if it once matched and now does not match*/
                matches--;
            }

            idx = s2[l] - 'a';
            prem[idx]--;
            if (arr[idx] == prem[idx]) {
                matches++;
            } else if (arr[idx] - 1 == prem[idx]) {
                matches--;
            }
            l++;
            r++;
        }

        return 26 == matches;
    }
};
