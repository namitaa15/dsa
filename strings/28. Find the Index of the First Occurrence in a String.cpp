 Simple C++ Solution (Using Built-in Function):
int strStr(string haystack, string needle) {
    return haystack.find(needle);  // returns -1 if not found
}
Brute-force C++ Solution (Manual Search):
int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();

    for (int i = 0; i <= m - n; i++) {
        if (haystack.substr(i, n) == needle)
            return i;
    }

    return -1;
}
