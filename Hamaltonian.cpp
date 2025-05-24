// HAMILTONIAN CYCLE CODE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void hc(vector<vector<int>> v, vector<int> path, set<int> s, int start, int end, int size)
{
    if (s.size()==size)
    {
        if(v[start][end]==1)
        {
        vector<int> temppath = path;
        temppath.push_back(end);
        ans.push_back(temppath);
        }
    }
    else{
    for (int i = 0; i < size; i++)
    {
        if (i != start && (!s.count(i)))
        {
            if (v[start][i] == 1)
            {
                set<int> temps = s;
                temps.insert(i);
                vector<int> temppath = path;
                temppath.push_back(i);
                hc(v, temppath, temps, i, end, size);
            }
        }
    }
    }
}
int main()
{
    int size, temp, start;
    vector<vector<int>> arr;
    cout << "ENTER NUMBER OF NODES :- ";
    cin >> size;
    cout << "ENTER 1 IF PATH AND 0 FOR NO PATH :- \n";
    for (int i = 0; i < size; i++)
    {
        vector<int> row;
        for (int j = 0; j < size; j++)
        {
            cout << i << "---->" << j << " : ";
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }
    cout << "ENTERED ADJACENCY MATRIX IS :- \n";
    for (auto row : arr)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    cout << "\nENTER THE START NODE :- ";
    cin >> start;
    hc(arr, {start}, {start}, start, start, size);
    cout << "ALL POSSIBLE PATHS ARE :- \n\n";
    for (auto path : ans)
    {
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << "\n\n";
    }
    return 0;
}