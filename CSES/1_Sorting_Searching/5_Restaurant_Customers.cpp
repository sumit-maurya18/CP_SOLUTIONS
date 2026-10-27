#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int>> &time)
{
    vector<pair<int, int>> events;

    for(auto p : time)
    {
        events.push_back({p.first, 1});
        events.push_back({p.second, -1});
    }

    sort(events.begin(), events.end());

    int result = 0;
    int count = 0;

    for(auto it : events)
    {
        count += it.second;
        result = max(result, count);
    }

    return result;
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
        time.push_back({a, b});
    }

    int result = solve(time);

    cout << result << "\n";
}