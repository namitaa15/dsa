Problem 1: Print Name N Times
📌 Goal: Print your name N times using recursion (e.g., "Namita").

void printName(int i, int n) {
    if (i > n) return;         // Base condition
    cout << "Namita" << endl;     // Print name
    printName(i + 1, n);       // Recursive call
}

Problem 2: Print 1 to N (Linear Order)
📌 Goal: Print numbers from 1 to N.

void print1toN(int i, int n) {
    if (i > n) return;    // Base case
    cout << i << " ";
    print1toN(i + 1, n);  // Next number
}
✅ Call:
print1toN(1, n);

Problem 3: Print N to 1 (Reverse Order)
📌 Goal: Print numbers from N to 1.

void printNto1(int i) {
    if (i < 1) return;     // Base case
    cout << i << " ";
    printNto1(i - 1);      // Decrease number
}
✅ Call:
printNto1(n);

Problem 4: Print 1 to N using Backtracking
📌 Goal: Print from 1 to N but use recursion in reverse direction.

void printBacktrack(int i) {
    if (i < 1) return;
    printBacktrack(i - 1);   // Call first
    cout << i << " ";        // Print later (on return)
}
✅ Call:
printBacktrack(n);

✅ Problem 1: Sum of First N Numbers
🔸 1. Parameterised Recursion Approach
👉 You carry the result (sum) as a parameter.
void sumParam(int i, int sum) {
    if (i < 1) {
        cout << sum << endl;
        return;
    }
    sumParam(i - 1, sum + i);
}
🧪 Example:
int n = 3;
sumParam(n, 0); // Output: 6 (3 + 2 + 1)
Time: O(n)
Space (stack): O(n)

🔸 2. Functional Recursion Approach
👉 You return the result from the function instead of passing it.
int sumFunc(int n) {
    if (n == 0) return 0;
    return n + sumFunc(n - 1);
}
🧪 Example:
int n = 3;
cout << sumFunc(n);  // Output: 6
✅ This method is helpful when the result is required to be returned and reused (used a lot in DP problems).

✅ Problem 2: Factorial of N
🔸 Functional Approach
int factorial(int n) {
    if (n == 0) return 1;  // Base case must return 1, not 0!
    return n * factorial(n - 1);
}
🧪 Example:
int n = 4;
cout << factorial(n); // Output: 24 (4 * 3 * 2 * 1)

1. Two Pointer Approach
void reverseArray(int l, int r, int arr[]) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray(l + 1, r - 1, arr);
}
Call from main:
int arr[] = {1, 3, 5, 4, 2};
int n = 5;
reverseArray(0, n - 1, arr);
🔸 2. Single Pointer Approach (Optimized)

void reverseArray(int i, int arr[], int n) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray(i + 1, arr, n);
}
 Call from main:
int arr[] = {1, 3, 5, 4, 2};
int n = 5;
reverseArray(0, arr, n);

✅ Problem 2: Check Palindrome using Recursion
🔸 Functional Approach
bool isPalindrome(int i, string &s) {
    if (i >= s.size() / 2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return isPalindrome(i + 1, s);
}
 Call from main:
string s = "madam";
cout << isPalindrome(0, s);  // Output: 1 (true)
