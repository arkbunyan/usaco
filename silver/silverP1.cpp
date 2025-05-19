#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input the initial values
    long long number, number_of_stack, difference;
    cin >> number >> number_of_stack >> difference;

    // Declare a vector 
    vector<pair<long long, long long>> vector_of_pair;

    // Input pairs 
    for (int i = 0; i < number; i++)
    {
        long long a, b;
        cin >> a >> b;
        vector_of_pair.push_back({a, b});
    }

    // store the total number of cows
    long long total_cows = 0;

    // Calculate the total 
    for (auto i : vector_of_pair)
    {
        total_cows += i.second;
    }

    // Sort
    sort(vector_of_pair.begin(), vector_of_pair.end());

    // Declare two vectors
    vector<pair<long long, long long>> vector_of_pair_2, vector_of_pair_3;

    // Iterate
    for (auto i : vector_of_pair)
    {
        if (i.second <= number_of_stack)
        {
            vector_of_pair_2.push_back({i.first, i.second});
            number_of_stack -= i.second;
        }
        else
        {
            // If there are more cows than available stack space, distribute them 
            i.second -= number_of_stack;
            if (number_of_stack != 0)
                vector_of_pair_2.push_back({i.first, number_of_stack});
            number_of_stack = 0;
            vector_of_pair_3.push_back({i.first, i.second});
        }
    }

    // Declare a deque 
    deque<pair<long long, long long>> double_queue;

    // Transfer values
    for (auto i : vector_of_pair_2)
        double_queue.push_back(i);

    // store the number of cows not included
    long long not_included = 0;

    // Iterate 
    for (auto i : vector_of_pair_3)
    {
        if (i.first - double_queue.front().first < difference)
        {
        
            not_included += i.second;
        }
        else
        {
            // Process the current pair and update the double-ended queue

            long long weight = i.first;
            long long num_cows = 0;
            int s = double_queue.size();
            while (s > 0 && i.first - double_queue.front().first >= difference && i.second > 0)
            {
                if (double_queue.front().second <= i.second)
                {
                    num_cows += double_queue.front().second;
                    i.second -= double_queue.front().second;
                    s--;
                    double_queue.pop_front();
                }
                else
                    break;
            }

            if (s == 0)
            {
                double_queue.push_back({weight, num_cows});
                not_included += i.second;
            }
            else
            {
                if (i.first - double_queue.front().first >= difference)
                {
                    if (i.second > 0)
                    {
                        double_queue.push_back({weight, num_cows + i.second});
                        pair<long long, long long> temp = {double_queue.front().first, double_queue.front().second - i.second};
                        double_queue.pop_front();
                        double_queue.push_front(temp);
                    }
                    else
                    {
                        if (num_cows != 0)
                            double_queue.push_back({weight, num_cows});
                    }
                }
                else
                {
                    if (num_cows != 0)
                        double_queue.push_back({weight, num_cows});
                    not_included += i.second;
                }
            }
        }
    }

    // Output the result 
    cout << total_cows - not_included << "\n";

    return 0;
}
