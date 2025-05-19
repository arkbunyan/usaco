#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input the total number of elements
    int total_numbers, permutaion_length;
    cin >> total_numbers >> permutaion_length;

    // Input the first permutation
    vector<int> permutation_1(permutaion_length);
    for (int i = 0; i < permutaion_length; i++)
        cin >> permutation_1[i];

    // Input the second permutation
    vector<int> permutation_2(permutaion_length);
    for (int i = 0; i < permutaion_length; i++)
        cin >> permutation_2[i];

    // Create a mapping of values
    map<int, int> mapping;
    for (int i = 0; i < permutaion_length; i++)
    {
        mapping[permutation_1[i]] = i;
    }

    // Create two mappings
    map<int, int> mapping2, mapping3;
    long long counter = 0;

    // Iterate through the second permutation
    for (int i = 0; i < permutaion_length; i++)
    {
        if (mapping.find(permutation_2[i]) == mapping.end())
        {
            //skip
            continue;
        }
        // Calculate the rotation
        long long rotation = (mapping[permutation_2[i]] - i + permutaion_length) % permutaion_length;

        // Update mapping2 with the rotations
        mapping2[rotation]++;
    }

    // Find the maximum count in mapping2
    long long maxima = 0;
    for (auto i : mapping2)
    {
        maxima = max(maxima, (long long)i.second);
    }

    // Reverse the second permutation
    reverse(permutation_2.begin(), permutation_2.end());

    // Iterate through the reversed 
    for (int i = 0; i < permutaion_length; i++)
    {
        if (mapping.find(permutation_2[i]) == mapping.end())
        {
            //increment the counter
            counter++;
            continue;
        }
        // Calculate the rotation needed to match the two permutations
        long long rotation = (mapping[permutation_2[i]] - i + permutaion_length) % permutaion_length;

        // Update mapping3 with the rotations
        mapping3[rotation]++;
    }

    // Find the maximum count in mapping3
    for (auto i : mapping3)
    {
        maxima = max(maxima, (long long) i.second);
    }

    // Output the result
    cout << maxima + (total_numbers - permutaion_length - counter) << "\n";

    return 0;
}
