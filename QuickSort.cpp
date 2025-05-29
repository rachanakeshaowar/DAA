// Quick Sort with 3-letter variable names
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void qsr(vector<int>& arr, int beg, int end)
{
    if (beg < end)
    {
        int piv = arr[end];
        int idx = beg - 1;

        for (int jdx = beg; jdx <= end - 1; jdx++)
        {
            if (arr[jdx] < piv)
            {
                idx++;
                swap(arr[idx], arr[jdx]);
            }
        }

        swap(arr[idx + 1], arr[end]);
        qsr(arr, beg, idx);
        qsr(arr, idx + 2, end);
    }
}

int main()
{
    int siz;
    cout << "ENTER THE SIZE :- ";
    cin >> siz;

    vector<int> vec(siz);
    srand(time(0));
    generate(vec.begin(), vec.end(), rand);

    cout << "RANDOM GENERATED ARRAY IS :- ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    qsr(vec, 0, vec.size() - 1);

    cout << "\nSORTED ARRAY IS :- ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
