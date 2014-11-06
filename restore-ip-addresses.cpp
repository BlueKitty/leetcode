class Solution {
public:
    vector<string> parse(string s, int num_fields) {
        int n = s.size();
        if (n == 0 && num_fields == 0)
            return { "" }; 
        else if (n == 0 || num_fields == 0)
            return {};
        vector<string> result;
        for (int i = 1; i <= 3 && i <= n; ++i) {
            string last_field = s.substr(n - i, i);
            bool last_field_valid = last_field[0] != '0' || last_field.size() == 1;
            if (!last_field_valid || atoi(last_field.c_str()) > 255) continue;
            for (auto &fields : parse(s.substr(0, n - i), num_fields - 1)) {
                fields = fields.size() > 0 ? fields + "." + last_field : last_field;
                result.push_back(fields);
            }
        }
        return result;
    }
    vector<string> restoreIpAddresses(string s) {
        return parse(s, 4);
    }
};