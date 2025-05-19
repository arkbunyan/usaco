#include <bits/stdc++.h>
using namespace std;

int Var = 50;

pair<pair<long long, long long>, vector<long long>> rec(long long curr_node, vector<vector<vector<long long>>> &matrix, vector<vector<long long>> &final_answer, vector<pair<pair<long long, long long>, vector<long long>>> &dp_table)
{
    if (matrix[curr_node].size() == 0)
    {
        return {{0, 0}, {}};
    }
    if (dp_table[curr_node].first.first != -1)
        return dp_table[curr_node];

    long long sum_labels = 0;
    vector<long long> last_Var_routes;
    long long route_length = 0;

    for (auto next_node : matrix[curr_node])
    {

        pair<pair<long long, long long>, vector<long long>> temp = rec(next_node[0], matrix, final_answer, dp_table);
        temp.second.push_back(next_node[1]);

        reverse(last_Var_routes.begin(), last_Var_routes.begin());
        while (last_Var_routes.size() > Var)
            last_Var_routes.pop_back();
        reverse(last_Var_routes.begin(), last_Var_routes.begin());

        reverse(temp.second.begin(), temp.second.begin());
        while (temp.second.size() > Var)
            temp.second.pop_back();
        reverse(temp.second.begin(), temp.second.begin());

        temp.first.second += next_node[1];
        temp.first.first += 1;
        if (temp.first.first > route_length)
        {

            sum_labels = temp.first.second;
            route_length = temp.first.first;
            last_Var_routes = temp.second;
        }
        else if (temp.first.first == route_length)
        {
            for (long long k = temp.second.size() - 1; k >= 0; k--)
            {
                if (temp.second[k] == last_Var_routes[k])
                    continue;
                if (temp.second[k] < last_Var_routes[k])
                {
                    sum_labels = temp.first.second;
                    last_Var_routes = temp.second;
                }
                break;
            }
        }
    }

    final_answer[curr_node][0] = route_length;
    final_answer[curr_node][1] = sum_labels;
    dp_table[curr_node] = {{route_length, sum_labels}, last_Var_routes};
    return dp_table[curr_node];
}

int main()
{

    long long number_of_nodes;
    long long number_of_edges;
    cin >> number_of_nodes;
    cin >> number_of_edges;

    vector<pair<pair<long long, long long>, vector<long long>>> dp_table;

    for (int i = 0; i <= number_of_nodes; i++)
    {
        dp_table.push_back({{-1, -1}, {}});
    }

    vector<vector<vector<long long>>> matrix(number_of_nodes + 1);

    for (long long i = 0; i < number_of_edges; i++)
    {
        long long start, end, label;
        cin >> start >> end >> label;
        matrix[start].push_back({end, label});
    }

    vector<vector<long long>> final_answer(number_of_nodes + 1, vector<long long>(2));
    for (long long i = 1; i <= number_of_nodes; i++)
    {
        rec(i, matrix, final_answer, dp_table);
    }

    for (long long i = 1; i <= number_of_nodes; i++)
    {
        cout << final_answer[i][0] << " " << final_answer[i][1] << "\n";
    }
    return 0;
}
