#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a = -2, b = 1, c = -14, d = 17;
    if(x <= -3) cout << -1 * (x + 4) * (x + 4) + 8;
    else if (x > -3 && 2 >= x) cout << a * x + b;
    else cout << x * x * x + c * x + d;
    return 0;
}
