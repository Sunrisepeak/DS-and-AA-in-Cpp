#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//use Kth unit 'arr'
void insert_value(vector<int> &arr, int n) {
    int i = 1;
    while(i < arr.size() && arr[i] < n){ // left-shift
        arr[i - 1] = arr[i];
        i++;
    }
    arr[i - 1] = n;
}

int main() {
    cout << "Select Problem of kth-max when k = N/2:" << endl;
    int N, K;
    cin >> N;
    K = N / 2;
    vector<int> arr;
    int temp;
    for (int i = 0; i < K; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for (int i = K; i < N; i++) {
        cin >> temp;
        if (temp > arr[0]) {
            insert_value(arr, temp);
        }
        for (auto v : arr) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << arr[0] << endl;
    return 0;
}
