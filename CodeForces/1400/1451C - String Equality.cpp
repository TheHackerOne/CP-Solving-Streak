#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n, m, i, j, k;
    string s, ss;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s >> ss;
        int ar[26] = {0}, br[26] = {0}, flag = 0;
        for (i = 0; i < s.size(); i++)
            ar[s[i] - 'a']++;
        for (i = 0; i < s.size(); i++)
            br[ss[i] - 'a']++;

        for (i = 0; i < 25; i++)
        {
            if (ar[i] < br[i])
                flag = 1;
            else
            {
                int d = ar[i] - br[i];
                if (d % k != 0)
                    flag = 1;
                else
                    ar[i + 1] += d;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else    
            cout << "YES" << endl;
    }
    return 0;
}