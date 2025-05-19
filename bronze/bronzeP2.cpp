#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll c = 1;
void Case()
{
    cout << "Case #" << c << ": ";
    c++;
}
ll min2(ll a, ll b)
{
    if (a < b)
        return a;
    else
        return b;
}
ll max2(ll a, ll b)
{
    if (a > b)
        return a;
    else
        return b;
}

ll ceil2(ll a,ll b){
    if(a%b==0) return a/b;
    return (a/b);
}


void rotateMatrix(vector<vector<char>>& matrix)
{
    int N = (int)matrix.size();
    for (int itr1 = 0; itr1 < N / 2; itr1++) {
        for (int itr2 = itr1; itr2 < N - itr1 - 1; itr2++) {
            char temp = matrix[itr1][itr2];
            matrix[itr1][itr2] = matrix[itr2][N - 1 - itr1];
            matrix[itr2][N - 1 - itr1] = matrix[N - 1 - itr1][N - 1 - itr2];
            matrix[N - 1 - itr1][N - 1 - itr2] = matrix[N - 1 - itr2][itr1];
            matrix[N - 1 - itr2][itr1] = temp;
        }
    }
}

void stampOnCanvas(vector<vector<char>>& stamp_variable, vector<vector<char>>& canvas_variable, vector<vector<char>> &newCanvas, int canvasSize, int stampSize){

    for(int i = 0; i <= canvasSize - stampSize; i++){
        for(int j = 0; j <= canvasSize - stampSize; j++){
            bool flag = true;
            for(int itr1 = i; itr1 < i + stampSize; itr1++){
                for(int itr2 = j; itr2 < j + stampSize; itr2++){
                    if(stamp_variable[itr1 - i][itr2 - j] == '*' && canvas_variable[itr1][itr2] == '.'){
                        flag = false;
                    }
                }
            }
            if(flag){
                for(int itr1 = i; itr1 < i + stampSize; itr1++){
                    for(int itr2 = j; itr2 < j + stampSize; itr2++){
                        if(stamp_variable[itr1 - i][itr2 - j] == '*'){
                            newCanvas[itr1][itr2] = '*';
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<vector<char>> canvas_variable(n, vector<char>(n)), newCanvas(n, vector<char>(n));
        for(int i = 0; i < n; i++){
            string str; 
            cin >> str;
            for(int j = 0; j < n; j++){
                canvas_variable[i][j] = str[j];
                newCanvas[i][j] = '.';
            }
        }
        int k; 
        cin >> k;
        vector<vector<char>> stamp_variable(k, vector<char>(k));
        for(int i = 0; i < k; i++){
            string str; 
            cin >> str;
            for(int j = 0; j < k; j++){
                stamp_variable[i][j] = str[j];
            }
        }
        int iterations = 10;
        while(iterations--){
            rotateMatrix(stamp_variable);
            stampOnCanvas(stamp_variable, canvas_variable, newCanvas, n, k);
        }
        if(canvas_variable == newCanvas){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
