#include <bits/stdc++.h>
using namespace std;

// n people, m items, starting from k
int lastPosition(int n, int m, int k)
{
    // if m < number of remaining positions in the circle
    if (m <= n - k + 1)
        return m + k - 1;

    // calculate remaining items after giving away n-k+1 items
    m = m - (n - k + 1);

    // we now have m items and we are at the beginning of the circle
    return (m % n == 0) ? n : (m % n);
}

int main()
{
	int n = 5, m = 8, k = 2;
	cout << lastPosition(n,m,k);
}
