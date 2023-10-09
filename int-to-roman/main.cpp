#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::cout, std::endl;

string intToRoman(int);

int main() {
    string s = intToRoman(508);
    cout << "\n\nresult: [" << s << "]" << endl;
    return 0;
}


string intToRoman(int num) {
    string s;
    std::vector<string> thounsands = {"M", "MM", "MMM"};
    std::vector<string> hundreds = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    std::vector<string> tens = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    std::vector<string> ones = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    int v = num / 1000;
    if (v) {
        s += thounsands[v];
    }

    v = (num % 1000) / 100;
    if (v) {
        s += hundreds[v];
    }

    v = (num % 100) / 10;
    if (v) {
        s += tens[v];
    }

    v = (num % 10);
    if (v) {
        s += ones[v];
    }

    return s;
}

