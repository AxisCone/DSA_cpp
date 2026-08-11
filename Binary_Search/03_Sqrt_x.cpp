#include <iostream>
using namespace std;

int mySqrt(int x) {
    int start = 0, end = x;
    int ans = x;

    while (start <= end) {
        long mid = start + (end - start) / 2;

        if (mid * mid == x) {
            ans = mid;
            break;
        }
        else if (mid * mid < x) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x = 88;

    int result = mySqrt(x);

    cout << "Number            : " << x << endl;
    cout << "Integer Square Root: " << result << endl;

    return 0;
}