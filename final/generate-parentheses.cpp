class Solution {
public:
    // from https://github.com/soulmachine/leetcode
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        for (int i = 0; i < n; i++) {
            for (auto inner : generateParenthesis(i)) {
                for (auto outer : generateParenthesis(n - i - 1)) {
                    result.push_back("(" + inner + ")" + outer);
                }
            }
        }
        return result;
    }
};

/* Solution from Pumbaa */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result = {};
        gen_par_recur(n, n, "", result);
        return(result);
    }
    void gen_par_recur(int l, int r, string cur_str, vector<string>& vec_out) {
        if (l == 0) {
            string closing(r, ')');
            vec_out.push_back(cur_str + closing);
        } else {
            gen_par_recur(l - 1, r, cur_str + "(", vec_out);
            if (r > l) {
                gen_par_recur(l, r - 1, cur_str + ")", vec_out);
            }
        }
    }
};