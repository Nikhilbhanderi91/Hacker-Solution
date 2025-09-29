#include <iostream>
#include <vector>
using namespace std;

int simpleArraySum(const vector<int>& ar) {
    int sum = 0;
    for (int num : ar) {
        sum += num;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;  

    vector<int> ar(n);  
    for (int i = 0; i < n; i++) {
        cin >> ar[i]; 
    }

    int result = simpleArraySum(ar);
    cout << result << endl;  
    return 0;
}
