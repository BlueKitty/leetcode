class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<int> sorted = num;
        vector<vector<int> > result;
        sort(sorted.begin(), sorted.end());
        auto a = sorted.begin();
        while (a != sorted.end()) {
            auto b = a + 1;
            while (b != sorted.end()) {
                auto c = b + 1, d = sorted.end() - 1;
                while (c < d) {
                    int sum = *a + *b + *c + *d;
                    if (sum < target) {
                        do { ++c; } while (c != sorted.end() && *c == *(c - 1));
                    } else if (sum > target) {
                        do { --d; } while (d > b && *d == *(d + 1));
                    } else {
                        result.push_back({*a, *b, *c, *d});
                        do { ++c; } while (c != sorted.end() && *c == *(c - 1));
                        do { --d; } while (d > b && *d == *(d + 1));
                    }
                }
                do { ++b; } while (b != sorted.end() && *b == *(b - 1));
            }
            do { ++a; } while (a != sorted.end() && *a == *(a - 1));
        }
        return result;
    }
};