class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, int> occurance;
        for (int i = 0; i < n; i++) {
            int key = A[i];
            if (occurance.find(key) == occurance.end()) {
                occurance[key] = 1;
            } else {
                occurance[key]++;
            }
        }
        for (map<int, int>::iterator ii = occurance.begin(); ii != occurance.end(); ii++) {
            if ((*ii).second == 1)
                return (*ii).first;
        }
    }
};