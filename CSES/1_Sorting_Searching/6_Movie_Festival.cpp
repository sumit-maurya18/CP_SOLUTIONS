#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solve(vector<pair<int, int>> &time)
{
    sort(time.begin(), time.end(), comparator);

    int lastEnd = time[0].second;
    int count = 1;

    for(int i = 1; i < (int)time.size(); i++)
    {
        if(time[i].first >= lastEnd)
        {
            count++;
            lastEnd = time[i].second;
        }
    }

    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> time;

    while(n--)
    {
        int a, b;
        cin >> a >> b;

        time.push_back({a,b});
    }

    int result = solve(time);

    cout << result << '\n';
}