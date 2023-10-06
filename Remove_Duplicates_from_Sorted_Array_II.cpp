#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) {       return n;       }

    int i = 2, j = 2;

    while (j < n) {
        if (nums[j] != nums[i - 1] || ((nums[j] == nums[i - 1]) && (nums[j] != nums[i - 2]))) {
            nums[i] = nums[j];
            i = i + 1;
        }
        j = j + 1;
    }

    return i;
}
