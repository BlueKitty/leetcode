/* A bottom-up DP solution */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> minlen(triangle.back());
        for (int layer = n-2; layer >= 0; layer--)
        {
            for (int i = 0, num_nodes = layer + 1; i < num_nodes; i++)
            {
                minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
            }
        }
        return minlen[0];
    }
};
