#include <iostream>
#include <vector>

using namespace std;

int maxSubSum(const vector<int> &arr, int left, int right) {
    if (left == right) {
        if (arr[left] > 0) {
            return arr[left];
        } else {
            return 0;
        }
    } else {
        int mid = (left + right) / 2;
        int leftMaxSSum = maxSubSum(arr, left, mid);
        int rightMaxSSum = maxSubSum(arr, mid + 1, right);

        int maxLeftBorderSum = 0, leftBorderSum = 0; 
        for (int i = mid; i >= left; i--) {
            leftBorderSum += arr[i];
            if (leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        int maxRightBorderSum = 0, rightBorderSum = 0; 
        for (int i = mid + 1; i <= right; i++) {
            rightBorderSum += arr[i];
            if (rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        }

        return max(maxLeftBorderSum + maxRightBorderSum, max(leftMaxSSum, rightMaxSSum));
    }
}

int maxSubMax(const vector<int> &arr) {
    int sum = 0, maxSum = 0;
    for (auto v : arr) {
        sum += v;
        if (sum > maxSum) {
            maxSum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr {1, 0, -1, -4, 6, 8, -2, 4, -7, 12, 1, -4, 6};
    for (auto v : arr) {
        cout << v << " ";
    }
    cout << endl << "Maximum Contiguous Subsequence Sum:" << endl;
    cout << "\tRecursive: "<< maxSubSum(arr, 0, arr.size() - 1) << endl;
    cout << "\tOnline Algorithms: " << maxSubMax(arr) << endl; 
    return 0;
}