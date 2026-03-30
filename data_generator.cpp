#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
using ll=long long;
vector<ll> generateData(int n, int type) { // 1e18
    vector<ll> a(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000000000;  // this is random no.

    if (type == 2) sort(a.begin(), a.end());
    else if (type == 3) sort(a.begin(), a.end(), greater<int>());

    return a;
}
