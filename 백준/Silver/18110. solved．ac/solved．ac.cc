#include <bits/stdc++.h>
using namespace std;
int n, sum;
int main()
{
    cin >> n;
    if (n == 0) cout << 0;
    else {
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int t = round((double)n / 100 * 15), divnum = n - (t * 2);
        for (int i = t; i < n - t; i++) {
            sum += v[i];
        }
        cout << round((double)sum / divnum);
    }
}