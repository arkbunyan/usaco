#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Input the number of target points

    int number_of_target_points, length_of_string;
    cin >> number_of_target_points >> length_of_string;

    vector<int> points(number_of_target_points);
    for (int i = 0; i < number_of_target_points; i++)
        cin >> points[i];

    // Store target points

    unordered_set<int> unique_points;
    for (auto i : points)
        unique_points.insert(i);

    string str;
    cin >> str;

    long long answer = 0;

    vector<int> position_variable(length_of_string + 1);

    int current_position = 0;
    unordered_set<int> unique_points_1;
    int sum = 0;

    // Traverse the string, update positions, and count encountered unique target points

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] == 'L')
            current_position -= 1;
        else if (str[i] == 'R')
            current_position += 1;
        else
        {
            if (unique_points.find(current_position) != unique_points.end() && unique_points_1.find(current_position) == unique_points_1.end())
            {
                sum++;
                unique_points_1.insert(current_position);
            }
        }
        position_variable[i + 1] = current_position;
    }

    // Update answer 

    answer = sum;

    // Initialize variables 

    map<int, int> mapping_variable;
    unordered_set<int> unique_points_2;

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position + 1) != unique_points.end())
        {
            mapping_variable[current_position + 1]++;
            unique_points_2.insert(current_position + 1);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'L')
        {
            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
            answer = max(answer, (long long)unique_points_2.size());
        }
        else if (str[i] == 'F')
        {
            if (unique_points.find(current_position + 1) != unique_points.end())
            {
                mapping_variable[current_position + 1]--;
                if (mapping_variable[current_position + 1] == 0)
                    unique_points_2.erase(current_position + 1);
            }

            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
        }

        if (str[i] == 'L' && unique_points.find(current_position) != unique_points.end())
        {
            mapping_variable[current_position]--;
            if (mapping_variable[current_position] == 0)
                unique_points_2.erase(current_position);
        }
    }

    mapping_variable.clear();
    unique_points_2.clear();

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position + 2) != unique_points.end())
        {
            mapping_variable[current_position + 2]++;
            unique_points_2.insert(current_position + 2);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'L')
        {
            answer = max(answer, (long long)unique_points_2.size());
        }
        else if (str[i] == 'F')
        {
            if (unique_points.find(current_position + 2) != unique_points.end())
            {
                mapping_variable[current_position + 2]--;
                if (mapping_variable[current_position + 2] == 0)
                    unique_points_2.erase(current_position + 2);
            }
            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
        }
    }

    mapping_variable.clear();
    unique_points_2.clear();

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position - 1) != unique_points.end())
        {
            mapping_variable[current_position - 1]++;
            unique_points_2.insert(current_position - 1);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'R')
        {
            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
            answer = max(answer, (long long)unique_points_2.size());
        }
        else if (str[i] == 'F')
        {
            if (unique_points.find(current_position - 1) != unique_points.end())
            {
                mapping_variable[current_position - 1]--;
                if (mapping_variable[current_position - 1] == 0)
                    unique_points_2.erase(current_position - 1);
            }
            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
        }

        if (str[i] == 'R' && unique_points.find(current_position) != unique_points.end())
        {
            mapping_variable[current_position]--;
            if (mapping_variable[current_position] == 0)
                unique_points_2.erase(current_position);
        }
    }

    mapping_variable.clear();
    unique_points_2.clear();

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position - 2) != unique_points.end())
        {
            mapping_variable[current_position - 2]++;
            unique_points_2.insert(current_position - 2);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'R')
        {
            answer = max(answer, (long long)unique_points_2.size());
        }
        else if (str[i] == 'F')
        {
            if (unique_points.find(current_position - 2) != unique_points.end())
            {
                mapping_variable[current_position - 2]--;
                if (mapping_variable[current_position - 2] == 0)
                    unique_points_2.erase(current_position - 2);
            }
            if (unique_points.find(current_position) != unique_points.end())
            {
                mapping_variable[current_position]++;
                unique_points_2.insert(current_position);
            }
        }
    }

    mapping_variable.clear();
    unique_points_2.clear();

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position - 1) != unique_points.end())
        {
            mapping_variable[current_position - 1]++;
            unique_points_2.insert(current_position - 1);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'F')
        {
            if (unique_points.find(current_position - 1) != unique_points.end())
            {
                mapping_variable[current_position - 1]--;
                if (mapping_variable[current_position - 1] == 0)
                    unique_points_2.erase(current_position - 1);
            }
            answer = max(answer, (long long)unique_points_2.size());
        }

        if (str[i] == 'F' && unique_points.find(current_position) != unique_points.end())
        {
            mapping_variable[current_position]++;
            if (mapping_variable[current_position] == 1)
                unique_points_2.insert(current_position);
        }
    }

    mapping_variable.clear();
    unique_points_2.clear();

    for (int i = 0; i < length_of_string; i++)
    {
        if (str[i] != 'F')
            continue;
        int current_position = position_variable[i];
        if (unique_points.find(current_position + 1) != unique_points.end())
        {
            mapping_variable[current_position + 1]++;
            unique_points_2.insert(current_position + 1);
        }
    }

    for (int i = 0; i < length_of_string; i++)
    {
        int current_position = position_variable[i];
        if (str[i] == 'F')
        {
            if (unique_points.find(current_position + 1) != unique_points.end())
            {
                mapping_variable[current_position + 1]--;
                if (mapping_variable[current_position + 1] == 0)
                    unique_points_2.erase(current_position + 1);
            }
            answer = max(answer, (long long)unique_points_2.size());
        }

        if (str[i] == 'F' && unique_points.find(current_position) != unique_points.end())
        {
            mapping_variable[current_position]++;
            if (mapping_variable[current_position] == 1)
                unique_points_2.insert(current_position);
        }
    }

    cout << answer << "\n";

    return 0;
}
