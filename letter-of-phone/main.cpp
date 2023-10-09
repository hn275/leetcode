#include <vector>
#include <map>
#include <iostream>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        this->len = digits.size();
        this->doTheThing("", digits);
        return this->result;
    }

private:
    int len;
    std::vector<std::string> result = {};
    std::map<char, std::string> keymap{
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
        {'0', " "},
    };
    void doTheThing(std::string buf, std::string digit) {
        if (digit.size() == 0) {
            this->result.push_back(buf);
            return;
        }
        for (char c : this->keymap[digit[0]]) {
            doTheThing(buf + c, digit.substr(1, this->len));
        }
    };
};

int main() {
    std::vector<std::string> r = Solution().letterCombinations("2508889636");
    for (auto c : r) {
        std::cout << "\"" << c << "\" " << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
