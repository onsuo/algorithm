#include <iostream>

int count = 0;
int d[100];

int dp(int x);

int main()
{
    std::cout << dp(30) << " " << count << '\n';
}

int dp(int x) {
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (d[x] != 0) return d[x];
    count++;
    return d[x] = dp(x - 1) + dp (x - 2);
}