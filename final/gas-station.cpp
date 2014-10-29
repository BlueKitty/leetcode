class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), total_surplus = 0, start = 0, gas_in_tank = 0;
        for (int i = 0; i < n; ++i) {
            total_surplus += (gas[i] - cost[i]);
            gas_in_tank += (gas[i] - cost[i]);
            if (gas_in_tank < 0) {
                start = i + 1;
                gas_in_tank = 0;
            }
        }
        if (total_surplus >= 0) return start;
        return -1;
    }
};