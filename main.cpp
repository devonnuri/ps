#include <bits/stdc++.h>

using namespace std;

using vi=vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi W(n);
    for (int i=0;i<n;i++)
        cin >> W[i];
    set<int> okay;
    okay.insert(0);
    for (int i=0;i<n;i++) {
        set<int> tmp_set;
        for (auto it=okay.begin(); it!=okay.end(); it++) {
            tmp_set.insert(*it + W[i]);
            tmp_set.insert(*it - W[i]);
        }
        okay.insert(tmp_set.begin(), tmp_set.end());
    }
    int m; cin >> m;
    for (int i=0;i<m;i++) {
        int w; cin >> w;
        cout << (okay.count(w) > 0 ? 'Y' : 'N') << ' ';
    }
}