#include <iostream>

using namespace std;

int numOf1_binary(unsigned int n) {
    if (n != 0) {
        cout << n % 2;
        return (n % 2 == 1) + numOf1_binary(n >> 1);
    }
    cout << "(reverse_binary)" << endl;
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << numOf1_binary(n) << endl;
    return 0;
}
