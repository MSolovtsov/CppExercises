#include <iostream>

using namespace std;

#define SPRING "spring"
#define SUMMER "summer"
#define AUTUMN "autumn"
#define WINTER "winter"

#ifdef SUMMER
int main() {
    cout << SUMMER << endl;
    return 0;
}
#endif