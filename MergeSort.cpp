#include<bits/stdc++.h>
using namespace std;

vector<int> mer(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> res;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        res.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        res.push_back(b[j]);
        j++;
    }

    return res;
}

vector<int> mrg(vector<int> arr, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        vector<int> lft = mrg(arr, beg, mid);
        vector<int> rgt = mrg(arr, mid + 1, end);
        return mer(lft, rgt);
    } else {
        return {arr[beg]};
    }
}

int main() {
    int siz;
    cout << "ENTER SIZE OF ARRAY :- ";
    cin >> siz;

    vector<int> arr(siz);
    srand(time(0));
    generate(arr.begin(), arr.end(), rand);

    cout << "RANDOMLY GENERATED ARRAY IS :- ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    arr = mrg(arr, 0, arr.size() - 1);

    cout << "\nSORTED ARRAY IS :- ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
