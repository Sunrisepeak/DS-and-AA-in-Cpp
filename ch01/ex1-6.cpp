#include <iostream>
#include <string>

using namespace std;

/*
 *  think of for permute of 1234
 *  _   _   _   _ ----- position
 *  |   |   |   |
 *  4 x 3 x 2 x 1 = 256 
 *
 *  4 x (3 x 2 x 1) = 256
 *
 *  To permute(1234)
 *  see as:
 *  1 x permute(234)
 *  2 x permute(134)
 *  3 x permute(124)
 *  4 x permute(123)
 *
 * */

const int row_wide = 10;
int count = 0; 

void permute(const string &str, int low, int high) {
    string temp = str;
    if (low >= high) {
        count++;
        if (count % 10 == 0) {
            cout << temp << endl;
        } else {
            cout << temp << "\t";
        }
    } else {
        for (int i = low; i <= high; i++) {
            swap(temp[i], temp[low]);
            permute(temp, low + 1, temp.length() - 1);
        }
    }
}

void permute(const string &str) {
    permute(str, 0, str.length() - 1);
}

int main() {
    string s;
    cin >> s;
    permute(s);
    return 0;
}
