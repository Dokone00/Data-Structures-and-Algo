#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }

        int i = 0, j = 0;
        while (j < haystack.size() && i <= haystack.size() - needle.size()) {
            if (j - i + 1 < needle.size()) {
                j++;
            } else if (j - i + 1 == needle.size()) {
                string substr = haystack.substr(i, needle.size());
                int res = substr.compare(needle);
                if (res == 0) {
                    return i;
                }
                i++;
                j++;
            }
        }
        return -1;
    }
};