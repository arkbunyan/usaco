#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num_elements, max_diff;
    cin >> num_elements >> max_diff;

    vector<long long> arr(num_elements);
    for(int i = 0; i < num_elements; i++){
        cin >> arr[i];
    }

    long long total_steps = 0;
    for(int i = 0; i < num_elements; i++){
        if(i>0 && arr[i] - arr[i - 1] <= max_diff + 1){
            total_steps += arr[i] - arr[i - 1];
        }
        else{
            total_steps += max_diff + 1;
        }
    }

    cout << total_steps << "\n";
    return 0;
}
