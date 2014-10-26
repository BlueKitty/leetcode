class Solution {
public:
    void sortColors(int A[], int n) {
        int red_index = 0; // insertion index for red
        int blue_index = n - 1; // insertion index for blue
        int i = 0;
        while (i <= blue_index) {
            if (A[i] == 0) {
                swap(A[i++], A[red_index++]);
            } else if (A[i] == 2) {
                swap(A[i], A[blue_index--]);
            } else {
                i++;
            }
        }
    }
};