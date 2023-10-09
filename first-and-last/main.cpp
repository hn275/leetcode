#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> buf = {};

        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;

        while (l < r) {
            if (nums[mid] == target) {
                break;
            }

            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            };
            mid = (l + r) / 2;
        }

        if (nums[mid] != target) {
            buf = {-1, -1};
            return buf;
        }

        while (nums[mid - 1] == target) {
            mid--;
        }

        buf.push_back(mid);
        while (nums[mid] == target) {
            mid++;
        }
        buf.push_back(mid);

        return buf;
    }
};
int main() {
    std::vector<int> m = {5,7,7,8,8,10};
    auto result = Solution().searchRange(m, 8);

    for (auto r : result) {
        std::cout << " " << r;
    }
    std::cout << std::endl;





    m = {};
    result = Solution().searchRange(m,  6);

    for (auto r : result) {
        std::cout << " " << r;
    }
    std::cout << std::endl;

    return 0;
}
