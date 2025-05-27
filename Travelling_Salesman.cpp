#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mnc = 0; // minimum cost
vector<int> mnp; // minimum path

void tsp(vector<vector<int>> mat, vector<int> pth, set<int> vis, int cur, int cst, int siz)
{
    if (vis.size() == siz)
    {
        pth.push_back(0);
        cst = cst + mat[cur][0];
        if (mnc >= cst || mnc == 0)
        {
            mnc = cst;
            mnp = pth;
        }
    }
    else
    {
        for (int i = 0; i < siz; i++)
        {
            if (!vis.count(i) && (cur != i))
            {
                vector<int> tmp = pth;
                set<int> vst = vis;
                tmp.push_back(i);
                vst.insert(i);
                int tcs = cst + mat[cur][i];
                tsp(mat, tmp, vst, i, tcs, siz);
            }
        }
    }
}

int main()
{
    int num, val;
    vector<vector<int>> mat;

    cout << "ENTER NUMBER OF LOCATIONS :- ";
    cin >> num;

    cout << "ENTER THE VALUES OF ADJACENCY MATRIX :- \n";
    for (int i = 0; i < num; i++)
    {
        vector<int> row;
        for (int j = 0; j < num; j++)
        {
            cout << i << " ----> " << j << " :- ";
            cin >> val;
            row.push_back(val);
        }
        mat.push_back(row);
    }

    cout << "ENTERED MATRIX IS :- \n";
    for (auto r : mat)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

    tsp(mat, {0}, {0}, 0, 0, num);

    cout << "\n\nMINIMUM COST IS :- " << mnc;
    cout << "\nMINIMUM PATH IS :- ";
    for (auto it : mnp)
    {
        cout << it << " ";
    }

    return 0;
}
