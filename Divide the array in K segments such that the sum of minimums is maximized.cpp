//https://www.geeksforgeeks.org/divide-the-array-in-k-segments-such-that-the-sum-of-minimums-is-maximized/

// C++ program to find the sum of
// the minimum of all the segments
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;

// Function to maximize the sum of the minimums
int maximizeSum(int a[], int n, int ind,
				int k, int dp[MAX][MAX])
{

	// If k segments have been divided
	if (k == 0) {
		// If we are at the end
		if (ind == n)
			return 0;

		// If we donot reach the end
		// then return a negative number
		// that cannot be the sum
		else
			return -1e9;
	}

	// If at the end but
	// k segments are not formed
	else if (ind == n)
		return -1e9;

	// If the state has not been visited yet
	else if (dp[ind][k] != -1)
		return dp[ind][k];

	// If the state has not been visited
	else {
		int ans = 0;

		// Get the minimum element in the segment
		int mini = a[ind];

		// Iterate and try to break at every index
		// and create a segment
		for (int i = ind; i < n; i++) {

			// Find the minimum element in the segment
			mini = min(mini, a[i]);

			// Find the sum of all the segments trying all
			// the possible combinations
			ans = max(ans, maximizeSum(
			a, n, i + 1, k - 1, dp) + mini);
		}

		// Return the answer by
		// memoizing it
		return dp[ind][k] = ans;
	}
}

// Driver Code
int main()
{
	int a[] = { 5, 7, 4, 2, 8, 1, 6 };
	int k = 3;
	int n = sizeof(a) / sizeof(a[0]);

	// Initialize dp array with -1
	int dp[MAX][MAX];
	memset(dp, -1, sizeof dp);

	cout << maximizeSum(a, n, 0, k, dp);

	return 0;
}
