#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define ar array
#define pi pair<int, int> 
#define pi pair<int, int> 
#define pl pair<ll,ll>
#define pd pair<ld,ld>
#define vi vt<int>
#define vl vt<ll>
#define vs vt<string>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define sz(x) (int)(x).size()
#define all(c) (c).begin(), (c).end()

#define INF 1e18
#define NINF -1 * 1e18
#define PI 3.141592653589793238462
#define MOD 1000000007

template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}

#define EACH(x, a) for(auto& x: a)

void print(int a) { cerr << a; }
void print(ll a) { cerr << a; }
void print(bool a) { cerr << a; }
void print(string a) { cerr << a; }
void print(char a) { cerr << a; }
void print(float a) { cerr << a; }
void print(double a) { cerr << a; }
template<class T> void print(vt<T> v) { cerr << "[ ";for (T i : v) {print(i);cerr << " ";} cerr << "]";}
template<class T> void print(set<T> s) { cerr << "[ ";for (T i : s) {print(i); cerr << " ";} cerr << "]";}
template <class T> void prar(T arr[], size_t size) { cerr << "[ "; for (size_t i = 0; i < size; ++i) { print(arr[i]); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[ " << #x << " = "; print(x); cerr << " ]" << endl;
#define dbga(x, y) cerr << "[ " << #x << " = "; prar(x, y); cerr << " ]" << endl;
#else
#define debug(x)
#define dbga(x, y)
#endif

template<typename T_vector>
void print_vector(const T_vector &v, int start = -1, int end = -1) {if (start < 0) start = 0;if (end < 0) end = int(v.size());for (int i = start; i < end; i++) {cout << v[i] << (i < end - 1 ? ' ' : '\n');}}

void solve() {
	// taking input
	
	int n, k;
	string s, ans = "";
	cin >> n >> k;
	cin >> s;
	
	// creating a map with all distinct alphabet letters and their number of repetitions in the string s
	
	map<char, int> m;
	
	for( char x : s ) {
		if( m.count(x) ) {
			m[x]++;
		} else {
			m.insert( {x, 1} );
		}
	}
	
	// looping k times to create k compartments
	
	for( int i = 0; i < k; i++ ) {
		
		// create temporary compartment
		
		string temp = "";
		
		// loop through the map until compartment's size is within its limit
		// we want as many distinct letters in on compartment as possible to get the lexigraphically highest possible letter
		
		for( auto itr = m.begin(); itr != m.end(); ++itr ) {
			
			// checking if the size of the compartment is still available for more books and if the letter is still usable
			
			if( temp.length() < n/k && (*itr).ss > 0 ){
				
				// add the letter
				
				temp = temp + (*itr).ff;
				
				m[ (*itr).ff ]--;
			
			} else {
				
				// if the size of the compartment is already full, stop the loop
				
				break;
			}
		}
		// sort the string for convenience of searching the minimum excluded (MEX) letter
		
		sort( all(temp) ); // temp.begin(), temp.end()
		
		// loop through alphabet (ascii table: 97 - a, 122 - z)
		
		for( int i = 97; i <= 122; ++i ) {
		
			// check if the letter exists in the compartment, if yes, set it to true
			
			bool ok = false;
			
			// switching from 97 to a (from int to char)
			
			char g = i;
			
			// check if the letter exists in the compartment
			
			for(auto s : temp) {
				if( s == g ) {
					ok = true;
					break;
				}
			}
			
			// if it doesn't exist in the string, it means that it is the MEX letter
			
			if(ok == false) {
			
				// add the MEX letter to the answer
				
				ans = ans + g;
				break;
			}
		}
	}
	// cout the answer
	
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		solve();
	}
	return 0;
}
