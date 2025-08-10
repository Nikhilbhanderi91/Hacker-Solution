#include <iostream>
#include <vector>
using namespace std;


long long aVeryBigSum(const vector<long long>& ar) {
    long long sum = 0;
    for (long long num : ar) {
        sum += num;
    }
    return sum;
}

int main() {
    int n;
    cin >> n; 

    vector<long long> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];  
    }

    long long result = aVeryBigSum(ar);
    cout << result << endl; 

    return 0;
}
