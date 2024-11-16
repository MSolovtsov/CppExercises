#include <iostream>

using namespace std;

void evendigits(long long& num, int& count){
    if (num != 0) {
        if ((num % 10) % 2 == 0) count++;
        num /= 10;
        evendigits(num, count);
    }
}

int main() {
    cout << "\nTask  #4\n" << endl;

    long long numLong = 9223372036854775806;
    int ans = 0;

    cout << "In list: " << numLong;
    evendigits(numLong, ans);
    cout << " even numbers = " << ans << endl;
    return 0;
}
