#include <bits/stdc++.h>
using namespace std;

int Var = 50;

int main()
{
    int number_of_points;
    cin >> number_of_points;

    vector<int> points(number_of_points);
    for (int i = 0; i < number_of_points; i++)
        cin >> points[i];

    vector<long long> prefix_sum1(number_of_points), prefix_sum2(number_of_points);

    sort(points.begin(), points.end());
    for (int i = 1; i < number_of_points; i++)
    {
        prefix_sum1[i] = prefix_sum1[i - 1];
        prefix_sum1[i] = prefix_sum1[i] + i * (points[i] - points[i - 1]);
    }
    for (int i = number_of_points - 2; i >= 0; i--)
    {
        prefix_sum2[i] = prefix_sum2[i + 1];
        prefix_sum2[i] = prefix_sum2[i] + (number_of_points - i - 1) * (points[i + 1] - points[i]);
    }

    int num_of_queries;
    cin >> num_of_queries;
    for (int i = 0; i < num_of_queries; i++)
    {
        int left_cost;
        int right_cost;
        cin >> left_cost;
        cin >> right_cost;

        long long minimum_cost = LLONG_MAX;
        if (left_cost == right_cost)
        {

            long long middle = number_of_points / 2;
            long long temp = prefix_sum1[middle] * left_cost + prefix_sum2[middle] * right_cost;
            minimum_cost = min(minimum_cost, temp);
            if (middle - 1 >= 0)
            {
                long long temp = prefix_sum1[middle - 1] * left_cost + prefix_sum2[middle - 1] * right_cost;
                minimum_cost = min(minimum_cost, temp);
            }
        }
        else
        {
            long long lower_bound = 0;
            long long upper_bound = number_of_points - 1;
            while (upper_bound - lower_bound > Var)
            {

                long long middle1 = (upper_bound - lower_bound) / 3 + lower_bound;

                long long middle2 = 2 * (upper_bound - lower_bound) / 3 + lower_bound;
                long long x = prefix_sum1[middle1] * left_cost + prefix_sum2[middle1] * right_cost;

                long long y = prefix_sum1[middle2] * left_cost + prefix_sum2[middle2] * right_cost;
                if (x < y)
                {
                    upper_bound = middle2 - 1;
                }
                else
                {
                    lower_bound = middle1;
                }
            }
            for (int itr = lower_bound; itr <= upper_bound; itr++)
            {
                long long temp = prefix_sum1[itr] * left_cost + prefix_sum2[itr] * right_cost;
                minimum_cost = min(minimum_cost, temp);
            }
        }
        cout << minimum_cost << "\n";
    }

    return 0;
}
