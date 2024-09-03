#include <iostream>

int dp_count;
int d[100];

int dp(int x);

int main()
{
    dp_count = 0;
    int x = dp(30);
    std::cout << x << " " << dp_count << '\n';
}

int dp(int x) {
    if (x == 1) return 1;
    if (x == 2) return 1;
    if (d[x] != 0) return d[x];
    dp_count++;
    return d[x] = dp(x - 1) + dp (x - 2);
}