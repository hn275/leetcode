#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

class Solution {
public:
    int threeSumClosest (std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[n - 1]; 
        int dif = abs(sum - target);

        for (int i = 0; i < n - 1; i++) {
            int n1 = nums[i];
            int l = i + 1; 
            int r = n - 1;
            while (l < r) {
                int s = n1 + nums[l] + nums[r];
                if (s == target) {
                    return s;
                }

                if (s < target) {
                    int d = abs(target - s);
                    if (d < dif) {
                        dif = d;
                        sum = s;
                    }
                    l++;
                } else {
                    int d = abs(target - s);
                    if (d < dif) {
                        dif = d;
                        sum = s;
                    }
                    r--;
                }
            }
        }

        return sum;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 0};
    int target =  -100;
    int s = Solution().threeSumClosest(nums, target);
    std::cout << "threeSumClosest" << std::endl;
    std::cout << "[" << s << "]" << std::endl;



    nums = {-1, 2, 1, -4};
    target =  1;
    s = Solution().threeSumClosest(nums, target);
    std::cout << "threeSumClosest" << std::endl;
    std::cout << "[" << s << "]" << std::endl;
}
