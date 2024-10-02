// SK1PY's template - KACTL superset
#include <bits/stdc++.h>

using namespace std;

// types
#define int long long

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vector<pii>> vvpii;
typedef vector<pll> vpll;
typedef vector<vector<pll>> vvpll;


// iterators
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(a) a.end(), a.begin()

// shortcuts
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sz(x) (int)(x).size()

// constants
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF numeric_limits<ll>::max()
#define NINF numeric_limits<ll>::min()
#define INF_I numeric_limits<int>::max()
#define NINF_I numeric_limits<int>::min()

template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    os << p.F << " " << p.S;
    return os;
}

string SEP = " ";
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    string s;
    for (auto&& x : v) {
        os << s << x;
        s = SEP;
    }
    return os;
}

// debugging (https://codeforces.com/blog/entry/76087)
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef DEBUG
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve() {

}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n=1;
    cin >> n;
    for (ll i=0; i<n; i++) {
        solve();
    }
    return 0;
}
