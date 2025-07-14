string removeKdigits(string num, int k) {
    string result;

    for (char digit : num) {
        // Remove bigger digits from the end of result
        while (!result.empty() && result.back() > digit && k > 0) {
            result.pop_back();
            k--;
        }
        result.push_back(digit);
    }

    // Remove remaining digits from the end
    while (k > 0 && !result.empty()) {
        result.pop_back();
        k--;
    }

    // Remove leading zeroes
    int start = 0;
    while (start < result.size() && result[start] == '0') start++;

    string finalResult = result.substr(start);
    return finalResult.empty() ? "0" : finalResult;
}
