class Solution {
public:
    string read_string(string s) {
        stringstream ss;
        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind2nd(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
    
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            str = read_string(str);
        }
        return str;
    }
};