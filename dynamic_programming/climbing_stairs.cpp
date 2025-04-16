/* Leetcode 70. Climbing Stairs
Climbing Stairs
Problem:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb 1 or 2 steps.
Q: How many distinct ways can you climb to the top?
 Example:
Input: n = 3  
Output: 3  
Explanation: 
1 + 1 + 1  
1 + 2  
2 + 1  
Total = 3 ways
Observation:
To reach step n:
You could’ve come from n-1 (by taking 1 step)
OR from n-2 (by taking 2 steps)
So the formula becomes:
ways(n) = ways(n-1) + ways(n-2)
Just like Fibonacci series 
*/
int climbStairs(int n) {
    if (n <= 2) return n;

    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

