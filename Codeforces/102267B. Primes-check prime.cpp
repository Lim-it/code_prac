#include <bits/stdc++.h>

using namespace std;

#define fn(i, n) for(int i = 0; i < n; i++)
#define forn(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rforn(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;
/*************************/
/******** own func *******/

bool prime_check(int n){  //check if n prime
    if(n%2 == 0) return false;
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    /*for(int i=2; i <= n; i+=2){
        isprime[i] = false;
    }*/
    for (int i = 3; i <= n; i+=2) {
        if (isprime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    return isprime[n];
}

void solve(){
    int n;
    cin >> n;
    if(prime_check(n-2)){
        cout << "2 " << n-2 << '\n';
    }
    else cout << "-1\n";
}

/*************************/
/******* main func *******/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
	tc = 1;
	//cin >> tc;

	while(tc--){
		solve();
	}
	return 0;
}
