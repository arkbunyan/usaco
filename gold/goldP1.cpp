#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long number_of_cities;
    cin >> number_of_cities;
    long long direct_routes = 0;
    vector<string> parity_vector(number_of_cities - 1);
    for (long long i = 0; i < number_of_cities - 1; i++)
    {
        string s;
        cin >> s;
        parity_vector[i] = s;
    }
    vector<vector<long long>> total_ways;

    for (int i = 0; i < number_of_cities; i++)
    {
        vector<long long> way_from_one;
        for (int j = 0; j < number_of_cities; j++)
        {
            way_from_one.push_back(0);
        }
        total_ways.push_back(way_from_one);
    }

    for (long long i = number_of_cities - 2; i >= 0; i--)
    {
        vector<long long> temp_routes_parity(number_of_cities);
        for (long long j = i + 1; j < number_of_cities; j++)
        {

            if ((temp_routes_parity[j] % 2 == 0 && parity_vector[i][j - i - 1] == '1'))
            {
                direct_routes++;
                temp_routes_parity[j]++;

                for (long long k = i + 2; k < number_of_cities; k++)
                {
                    temp_routes_parity[k] = temp_routes_parity[k] + total_ways[j][k];
                    temp_routes_parity[k] = temp_routes_parity[k] % 2;
                }
            }
            else if (temp_routes_parity[j] % 2 == 1 && parity_vector[i][j - i - 1] == '0')
            {
                direct_routes++;
                temp_routes_parity[j]++;

                for (long long k = i + 2; k < number_of_cities; k++)
                {
                    temp_routes_parity[k] = temp_routes_parity[k] + total_ways[j][k];
                    temp_routes_parity[k] = temp_routes_parity[k] % 2;
                }
            }
        }

        total_ways[i] = temp_routes_parity;
    }
    cout << direct_routes << "\n";
    return 0;
}