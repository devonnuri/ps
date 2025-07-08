#include <bits/stdc++.h>

using namespace std;

using vi=vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi arr(n);
    for (int i=0;i<n;i++)
        cin >> arr[i];
    
    if (n == 1) {
        cout << arr[0];
        return 0;
    }    

    int offset = 0, median = min(arr[0], arr[1]), next_median = max(arr[0], arr[1]);
    cout << median << '\n' << median << '\n';
    for (int i=2;i<n;i++) {
        if (i%2) {
            // 1 (5) 10 <- 3
            if (median >= arr[i]) {
                next_median = median;
                median = arr[i];
            } else if (next_median > arr[i]) { // 1 (2) 10 <- 5
                next_median = arr[i];
            }
        } else {
            if (median <= arr[i]) {
                if (next_median >= arr[i]) { 
                    // 1 (3) [5] 7 <- 4
                    median = arr[i];
                } else {
                    // 1 (3) [5] 7 <- 6
                    median = next_median;
                    next_median = arr[i];
                }
            }
        }

        cout << median << '\n';
    }
}