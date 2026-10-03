#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int &result){

    set<int> st;

    for(auto &num : arr){
        st.insert(num);
    }

    result = st.size();
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    int result = 0;

    solve(arr, result);

    cout << result << "\n";
}