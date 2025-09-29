#include <iostream>
#include <vector>
using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int aliceScore = 0;
    int bobScore = 0;

    for (int i = 0; i < 3; ++i) {
        if (a[i] > b[i]) {
            aliceScore++;
        } else if (a[i] < b[i]) {
            bobScore++;
        }
        // No score if equal
    }

    return {aliceScore, bobScore};
}

int main() {
    vector<int> a(3);
    vector<int> b(3);

    // Input for Alice
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }

    // Input for Bob
    for (int i = 0; i < 3; ++i) {
        cin >> b[i];
    }

    vector<int> result = compareTriplets(a, b);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
