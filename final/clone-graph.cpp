/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> copied;
        return clone(node, copied);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node,
            unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &copied) {
        if (copied.count(node) > 0) return copied[node];
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copied[node] = new_node;
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(clone(neighbor, copied));
        }
        return new_node;
    }
};