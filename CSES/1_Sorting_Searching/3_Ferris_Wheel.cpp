#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, int x)
{
    int left = 0, right = weight.size() - 1;
    int count = 0;

    sort(weight.begin(), weight.end());

    while(left < right)
    {
        if(weight[left] + weight[right] <= x)
        {
            count++;
            left++;
            right--;
        }

        else
        {
            count++;
            right--;
        }
    }

    if(left == right && weight[left] <= x)
    count++;

    return count;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    cin >> weight[i];

    int result = solve(weight, x);

    cout << result << '\n';
}