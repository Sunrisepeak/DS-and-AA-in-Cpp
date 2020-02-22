#include <iostream>
#include <cmath>

using namespace std;

bool equals(const double &n1, const double &n2) {
    if (n1 - n2 >= 0 && n1 - n2 <= 0) {
        return true;
    }
    return false;
    
}

void printDigit(double n, int nums) {
    double temp{ 0.0 };
    if (n < 0) {
        cout << "-";
        temp = -n;
    } else {
        temp = n;
    }
    cout << static_cast<int>(abs(n));
    if (nums > 0) {
        cout << ".";
    }
    for (int i = 0; i < nums; i++) {
        temp *= 10;
        int output = (int)temp % 10;
        cout << output;
        temp -= (int)temp;
    }
}

int main() {
    double n{ -3.1234567890 };
    printDigit(n, 10);
    return 0;
} 
