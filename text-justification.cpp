class Solution {
public:
    string justify(vector<string> &line_tokens, int limit, int sum_token_length) {
        int total_space_left = limit - sum_token_length;
        int n = line_tokens.size();
        string line;
        if (n == 1) {
            line += line_tokens[0];
            for (int i = 0; i < total_space_left; ++i) line += " ";
            return line;
        }
        int default_space_len = total_space_left / (n - 1);
        int extra_space_count = total_space_left % (n - 1);
        for (int i = 0; i < n; ++i) {
            string token = line_tokens[i];
            line += token;
            int space_len = i == n - 1 ? 0 : default_space_len;
            if (i < extra_space_count) space_len += 1;
            for (int j = 0; j < space_len; ++j) line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> line_tokens;
        vector<string> result;
        int total_word_len = 0;
        for (string &word : words) {
            if (word.size() + total_word_len + line_tokens.size() > L) {
                /* the line is full, justify it and push to result */
                result.push_back(justify(line_tokens, L, total_word_len));
                total_word_len = 0;
                line_tokens.clear();
            }
            line_tokens.push_back(word);
            total_word_len += word.size();
        }
        if (line_tokens.size()) {
            string last_line;
            for (auto &token : line_tokens)
                last_line += last_line.size() == 0 ? token : " " + token;
            while (last_line.size() < L) last_line += " ";
            result.push_back(last_line);
        }
        return result;
    }
};