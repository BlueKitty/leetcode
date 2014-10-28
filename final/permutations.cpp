class Solution {
private:
    void permute_recursive(vector<int> &vec, int i, vector<vector<int> > &result) {
        if (i == vec.size()) {
            result.push_back(vec);
        } else {
            for (int j = i; j < vec.size(); ++j) {
                swap(vec[i], vec[j]);
                permute_recursive(vec, i+1, result);
                swap(vec[i], vec[j]);
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permute_recursive(num, 0, result);
        return result;
    }
};

/* Iterative solution: add new number to all possible slots in previous sub_permutation. */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 0) return {};
        list<list<int> > permutation;
        permutation.push_back({num[0]});
        while(permutation.front().size() < num.size()) {
            list<int> &sub_permutation = permutation.front();
            int i = sub_permutation.size();
            for (auto it = sub_permutation.begin(); it != sub_permutation.end(); ++it) {
                auto inserted = sub_permutation.insert(it, num[i]);
                permutation.push_back(sub_permutation);
                sub_permutation.erase(inserted);
            }
            sub_permutation.push_back(num[i]);
            permutation.push_back(sub_permutation);
            permutation.pop_front();
        }
        vector<vector<int> > result(permutation.size());
        int i = 0;
        for (auto it = permutation.begin(); it != permutation.end(); ++it, ++i) {
            result[i].insert(result[i].begin(), it->begin(), it->end());
        }
        return result;
    }
};