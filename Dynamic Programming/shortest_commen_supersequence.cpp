#include <bits/stdc++.h>
using namespace std;

string findLCS(string x, string y, int m, int n)
{
    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    string s = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s += x[i - 1];
            i--, j--;
        }
        else
        {
            if (t[i - 1][j] < t[i][j - 1])
            {
                s.push_back(y[j - 1]);
                j--;
            }
            else
            {
                s.push_back(x[i - 1]);
                i--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(y[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << findLCS(x, y, x.length(), y.length()) << endl;
}