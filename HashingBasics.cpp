//Brute Force to Count Frequency
int countFrequency(int num, vector<int> &arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) count++;
    }
    return count;
}
//Number Hashing using Array (small range elements)
int hashArr[13] = {0}; // max element <= 12

for (int i = 0; i < n; i++) {
    hashArr[arr[i]]++;
}

// For queries:
cout << hashArr[num] << endl;

//Character Hashing (all ASCII characters) 
int hashChar[256] = {0}; // full ASCII

for (int i = 0; i < s.size(); i++) {
    hashChar[s[i]]++;
}

cout << hashChar[c] << endl;

// Character Hashing using map
map<char, int> mpp;

for (int i = 0; i < s.size(); i++) {
    mpp[s[i]]++;
}

cout << mpp[c] << endl;
