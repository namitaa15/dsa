bool checkValidString(string s) {
    int low = 0, high = 0;

    for (char c : s) {
        if (c == '(') {
            low++; high++;
        } else if (c == ')') {
            low--; high--;
        } else {  // '*'
            low--; high++;  // '*' can be '(' or ')'
        }

        if (high < 0) return false;  // Too many ')'

        low = max(low, 0);  // '*' can't make negative open count
    }

    return low == 0;
}
