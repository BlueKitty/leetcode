class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            // determine if the gas in gas stataion i is enough for 
            // the next piece of journey from i to (i + 1) % n.
            gas[i] -= cost[i];
        }
        int total_surplus = 0;
        int start = 0;
        int gas_in_tank = 0;
        for (int i = 0; i < n; ++i) {
            total_surplus += gas[i];
            gas_in_tank += gas[i];
            if (gas_in_tank < 0) {
                start = i + 1;
                gas_in_tank = 0;
            }
        }
        if (total_surplus >= 0) {
            // TODO: still need to fully understand the proof
            return start;
        } else {
            return -1;
        }
    }
};