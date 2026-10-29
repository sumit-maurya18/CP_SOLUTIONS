#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

//due to hash collisions the searching time can go upto O(n^2)
//so we can use another technique to do it in O(nlogn)
// pair<int, int> solve(vector<int> &array, int target)
// {
//     if(array.size() <= 1)
//     return {-1, -1};

//     unordered_map<int, int> mpp;

//     for(int i = 0; i < (int)array.size(); i++)
//     {
//         int required = target - array[i];

//         if(mpp.find(required) == mpp.end())
//         {
//             mpp[array[i]] = i;
//         }

//         else
//         {
//             return {i + 1, mpp[required] + 1};
//         }
//     }

//     return {-1, -1};

// }

pair<int, int> solve(vector<pair<int, int>> &array, int target)
{
    if(array.size() <= 1)
    return {-1, -1};

    sort(array.begin(), array.end(), comparator);

    int left = 0, right = (int)array.size() - 1;

    while(left < right)
    {
        int sum = array[left].first + array[right].first;

        if(sum == target)
        return {array[left].second + 1, array[right].second + 1};

        else if(sum < target)
        left++;

        else
        right--;
    }

    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;

    cin >> n >> target;

    //vector<int> array;
    vector<pair<int, int>> array;//it contains value an its original index
    int size = n;

    while(n)
    {
        int num;
        cin >> num;

        array.push_back({num, size - n});
        n--;
    }

    pair<int, int> result = solve(array, target);

    if(result.first == -1)
    cout << "IMPOSSIBLE" << "\n";
    
    else
    cout << result.first << " " << result.second << "\n";
}