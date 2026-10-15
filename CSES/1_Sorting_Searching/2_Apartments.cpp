#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, int k)
{
    int left = 0, right = 0;

    int count = 0;

    while(left < (int)a.size() && right < (int)b.size())
    {
        if(a[left] - k > b[right])
        right++;

        else if(a[left] + k < b[right])
        left++;

        else
        {
            count++;
            left++;
            right++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> requiredSize(n), apartmentSize(m);

    for (int i = 0; i < n; i++)
    cin >> requiredSize[i];

    for (int i = 0; i < m; i++)
    cin >> apartmentSize[i];

    sort(requiredSize.begin(), requiredSize.end());
    sort(apartmentSize.begin(), apartmentSize.end());

    int result = solve(requiredSize, apartmentSize, k);

    cout << result << '\n';

    return 0;

}