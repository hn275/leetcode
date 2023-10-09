#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        this->gen(0, 0, n, "");
        return this->buf;
    }
private:
    std::vector<std::string> buf = {};
    void gen(int left, int right, int n, std::string paren) {
        if (left == n && right == n) {
            this->buf.push_back(paren);
            return;
        }

        if (left == n) {
            gen(left, right + 1, n, paren+")");
            return;
        }

        if (left == right) {
            gen(left + 1, right, n, paren+"(");
            return;
        }

        gen(left + 1, right, n, paren+"(");
        gen(left, right + 1, n, paren+")");
    };
};

int main() {
    std::vector<std::string> result = Solution().generateParenthesis(10);
    std::cout << result.size() << std::endl;
    return EXIT_SUCCESS;
}
