class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        string cpy = "";
        for (char ch : s) {
            if ((ch >= 'a' && ch <= 'z') || ch >= '0' && ch <= '9') {
                str += ch;
                cpy = ch + cpy;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
                str += ch;
                cpy = ch + cpy;
            }
        }
        cout << s << endl << str << endl << cpy << endl << endl;
        if (str == cpy) {
            return true;
        }
        return false;
    }
};
