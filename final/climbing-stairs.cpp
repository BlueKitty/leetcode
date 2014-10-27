class Solution {
public:
    int climbStairs(int n) {
        int steps_two_levels_down = 1, steps_one_level_down = 1, steps = 1;
        for (int i = 2; i <= n; i++) {
            steps = steps_two_levels_down + steps_one_level_down;
            steps_two_levels_down = steps_one_level_down;
            steps_one_level_down = steps;
        }
        return steps;
    }
};