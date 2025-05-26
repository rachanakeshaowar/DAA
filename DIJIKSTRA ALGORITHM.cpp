#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mnc = -1;
vector<int> mnp;

void djk(vector<vector<int>> adj, vector<int> pth, set<int> vis, int sz, int cst, int cur, int end)
{
    if (cur == end)
    {
        if (mnc == -1 || mnc >= cst)
        {
            mnc = cst;
            mnp = pth;
        }
    }
    else
    {
        for (int i = 0; i < sz; i++)
        {
            if (!vis.count(i) && adj[cur][i] != -1)
            {
                vector<int> tmp_pth = pth;
                set<int> tmp_vis = vis;
                int tmp_cst = cst + adj[cur][i];
                tmp_pth.push_back(i);
                tmp_vis.insert(i);
                djk(adj, tmp_pth, tmp_vis, sz, tmp_cst, i, end);
            }
        }
    }
}

int main()
{
    int sz, val, str, end;
    vector<vector<int>> adj;

    cout << "ENTER NUMBER OF NODES :- ";
    cin >> sz;

    cout << "ENTER THE VALUES OF ADJACENCY MATRIX :- \n";
    for (int i = 0; i < sz; i++)
    {
        vector<int> row;
        for (int j = 0; j < sz; j++)
        {
            cout << i << " ----> " << j << " :- ";
            cin >> val;
            row.push_back(val);
        }
        adj.push_back(row);
    }

    cout << "ENTERED MATRIX IS :- \n";
    for (auto r : adj)
    {
        for (auto e : r)
        {
            cout << e << " ";
        }
        cout << "\n";
    }

    cout << "ENTER START NODE AND END NODE :- ";
    cin >> str >> end;

    djk(adj, {str}, {str}, sz, 0, str, end);

    cout << "\n\nMINIMUM COST IS :- " << mnc;
    cout << "\nMINIMUM PATH IS :- ";
    for (auto n : mnp)
    {
        cout << n << " ";
    }

    return 0;
}
