#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>


class Solution {
    std::vector<std::string> buf = {};

public:
    std::vector<std::string> generateParenthesis(int n) {
        this->buf.push_back("()()");
        return this->buf;
    }
};

int main() {
    std::vector<std::string> result = Solution().generateParenthesis(5);
    std::cout << "result:" << std::endl;

    for (std::string i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
