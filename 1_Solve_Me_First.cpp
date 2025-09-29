#include <iostream>
using namespace std;

// Function to return the sum of two integers
int solveMeFirst(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    cin >> a >> b;
    int result = solveMeFirst(a, b);
    cout << result << endl;
    return 0;
}
