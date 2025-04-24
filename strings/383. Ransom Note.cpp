bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26, 0);

    for (char ch : magazine)
        count[ch - 'a']++;

    for (char ch : ransomNote) {
        if (count[ch - 'a'] == 0)
            return false;
        count[ch - 'a']--;
    }

    return true;
}
