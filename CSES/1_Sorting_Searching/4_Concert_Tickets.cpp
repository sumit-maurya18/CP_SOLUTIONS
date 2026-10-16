#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a, vector<int> &b)
{
    multiset<int> st(a.begin(), a.end());
    vector<int> result;

    for(int i = 0; i < (int)b.size(); i++) //O(m)
    {
        auto it = st.upper_bound(b[i]);

        if(it == st.begin())
        result.push_back(-1);

        else
        {
            it--;
            result.push_back(*it);
            st.erase(it);
        }

    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> ticketPrice(n);
    vector<int> maximumTicketPrice(m);

    for(int i = 0; i < n; i++)
    {
        cin >> ticketPrice[i];
    }

    for(int j = 0; j < m; j++)
    {
        cin >> maximumTicketPrice[j];
    }

    vector<int> result = solve(ticketPrice, maximumTicketPrice);

    for(auto it : result)
    {
        cout << it << "\n";
    }
}