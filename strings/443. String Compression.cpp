int compress(vector<char>& chars) {
    int index = 0;  // Position to write compressed result
    int i = 0;

    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;

        // Count consecutive characters
        while (i < chars.size() && chars[i] == current) {
            count++;
            i++;
        }

        chars[index++] = current;  // Add the character

        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt)
                chars[index++] = c;  // Add each digit of count
        }
    }

    return index;
}
