#include <bits/stdc++.h>
using namespace std;
//vectors
vector<int> v = {5, 2, 8, 1};

// Add element at end
v.push_back(10);

// Remove last element
v.pop_back();

// Access element
int x = v[2];         // or v.at(2)

// Size of vector
int n = v.size();

// Sort ascending
sort(v.begin(), v.end());

// Sort descending
sort(v.rbegin(), v.rend());

// Reverse
reverse(v.begin(), v.end());

// Sum of elements
int sum = accumulate(v.begin(), v.end(), 0);

// Remove all elements
v.clear();

// Insert 99 at index 2
v.insert(v.begin() + 2, 99);

// Erase element at index 3
v.erase(v.begin() + 3);

// Check if empty
bool isEmpty = v.empty();

// First and last elements
int first = v.front();
int last = v.back();

//pairs
// Declare a pair
pair<int, int> p = {10, 20};

// Access elements
int a = p.first;
int b = p.second;

// Modify elements
p.first = 100;
p.second = 200;

// Nested pair
pair<int, pair<int, int>> np = {1, {2, 3}};
int x = np.first;
int y = np.second.first;
int z = np.second.second;

// Array of pairs
pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
int val1 = arr[0].first;   // 1
int val2 = arr[1].second;  // 4

// Vector of pairs
vector<pair<int, int>> vp = {{1, 2}, {3, 4}};
vp.push_back({5, 6});

//maps
//map keeps keys in sorted order and is slower, while unordered_map does not sort keys and is faster.
map<int, string> m;

// Insertion
m[1] = "one";
m[5] = "five";
m.insert({3, "three"});

// Access
string s = m[5];  // returns "five"

// Iteration
for (auto it : m) {
    cout << it.first << " " << it.second << endl;
}

// Check if key exists
if (m.count(3)) {
    cout << "Key 3 exists";
}

// Erase by key
m.erase(5);

//unordered map
unordered_map<string, int> um;

// Insertion
um["apple"] = 10;
um["banana"] = 20;

// Access
int price = um["apple"];

// Iteration
for (auto it : um) {
    cout << it.first << " => " << it.second << endl;
}

// Check if key exists
if (um.count("banana")) {
    cout << "Yes";
}

// Erase
um.erase("apple");

// set stores unique elements in sorted order

set<int> s;

s.insert(5);      // insert 5
s.insert(2);
s.insert(7);

bool exists = s.count(5);  // check if 5 exists (1 = yes, 0 = no)

s.erase(2);       // remove 2

int n = s.size(); // number of elements

for (int x : s)   // iterate and print
    cout << x << " ";

auto it = s.find(7);  // returns iterator to 7

// stack follows LIFO (last in, first out)

stack<int> st;

st.push(10);       // add 10 on top

int top = st.top(); // get top element

st.pop();          // remove top

int n = st.size(); // current size

bool empty = st.empty(); // check if stack is empty

// queue follows FIFO (first in, first out)

queue<int> q;

q.push(5);         // add to back
q.push(10);

int front = q.front(); // get front element

q.pop();           // remove front

int n = q.size();  // size of queue

bool empty = q.empty(); // check if empty

// string is a sequence of characters

string s = "hello";

int len = s.length();   // get length

char c = s[1];          // access index 1

string sub = s.substr(1, 3); // substring from index 1 of length 3

reverse(s.begin(), s.end()); // reverse string

sort(s.begin(), s.end());    // sort characters

// common STL algorithms used with vectors and arrays

vector<int> v = {4, 2, 7, 1};

sort(v.begin(), v.end());        // sort ascending

sort(v.rbegin(), v.rend());      // sort descending

reverse(v.begin(), v.end());     // reverse the vector

int maxVal = *max_element(v.begin(), v.end()); // largest element

int minVal = *min_element(v.begin(), v.end()); // smallest element

int sum = accumulate(v.begin(), v.end(), 0);   // sum of elements

int count2 = count(v.begin(), v.end(), 2);     // count 2s

bool found = binary_search(v.begin(), v.end(), 7); // check if 7 is present (sorted only)
