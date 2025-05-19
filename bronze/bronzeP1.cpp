#include<bits/stdc++.h>
using namespace std;

 
int main() {
    
    long long num_intervals, target_time;
    cin >> num_intervals >> target_time;

    vector<vector<long long>> intervals(num_intervals, vector<long long>(2));

    for(long long i = 0; i < num_intervals; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }

    long long ans = 0, remaining_time = 0, curr_interval = 0;

    if(intervals.back()[0] < target_time){
        vector<long long> temp = {target_time, 0LL};
        intervals.push_back(temp);

    }else{

        long long ind = 0;
        for(int i = 0; i < num_intervals; i++){
            if(intervals[i][0] >= target_time){
                ind = num_intervals - i - 1LL;
                if(intervals[i][0] > target_time)intervals[i][1] = 0;
                intervals[i][1] = target_time;
                break;
            }
        }

        if(ind != 0){
            while(ind--)intervals.pop_back();
        }

    }

    num_intervals = intervals.size();

    for(long long i = 0; i < num_intervals - 1; i++){

        long long interval_duration = (intervals[i + 1][0] - intervals[i][0]);

        remaining_time += intervals[i][1];
        ans += min(interval_duration, remaining_time);
        remaining_time -= interval_duration;
        if(remaining_time < 0)remaining_time = 0;

    }

    if(remaining_time + intervals[num_intervals - 1][1] > 0){
        ans++;
    }

    cout << ans << "\n";
    return 0;
  
}
