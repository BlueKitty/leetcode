class Solution {
public:
    string simplifyPath(string path) {
        stack<string> path_stack;
        int i = 0;
        while (i != path.size()) {
            int dirname_start = path.find_first_not_of('/', i);
            if (dirname_start == string::npos) dirname_start = path.size();
            int dirname_end = path.find_first_of('/', dirname_start);
            if (dirname_end == string::npos) dirname_end = path.size();
            i = dirname_end;
            if (dirname_end > dirname_start) {
                string dirname = path.substr(dirname_start, dirname_end - dirname_start);
                if (dirname == ".") {
                    continue;
                } else if (dirname == "..") {
                    if (!path_stack.empty()) path_stack.pop();
                } else {
                    path_stack.push(dirname);
                }
            }
        }
        string result = "";
        while (!path_stack.empty()) {
            result = ("/" + path_stack.top()) + result;
            path_stack.pop();
        }
        if (result == "") result = "/";
        return result;
    }
};