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

// A. Ela Sorting Books
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output


// Ela loves reading a lot, just like her new co-workers in DTL! 
//On her first day after becoming an engineer in DTL, 
//she is challenged by a co-worker to sort a heap of books 
//into different compartments on the shelf.

// 𝑛 books must be split into 𝑘 compartments on the bookshelf (𝑛 is divisible by 𝑘). 
//Each book is represented by a lowercase Latin letter from 'a' to 'y' inclusively, 
//which is the beginning letter in the title of the book.
// Ela must stack exactly 𝑛𝑘 books in each compartment. 
//After the books are stacked, for each compartment indexed from 1 to 𝑘, 
//she takes the minimum excluded (MEX) letter of the multiset of letters 
//formed by letters representing all books in that compartment, 
//then combines the resulting letters into a string. 
//The first letter of the resulting string is the MEX letter of the multiset 
//of letters formed by the first compartment, the second letter of the 
//resulting string is the MEX letter of the multiset of letters formed by 
//the second compartment, ... and so on. Please note, under the constraint of this problem, 
//MEX letter can always be determined for any multiset found in this 
//problem because 'z' is not used.

// What is the lexicographically greatest resulting string possible that Ela can create?


// A string 𝑎 is lexicographically greater than a string 𝑏 
//if and only if one of the following holds:

// - 𝑏 is a prefix of 𝑎, but 𝑏≠𝑎;
// - in the first position where 𝑎 and 𝑏 differ, 
//the string 𝑎 has a letter that appears later in the alphabet than the corresponding letter in 𝑏.

// The minimum excluded (MEX) letter of a multiset of letters is the letter 
//that appears earliest in the alphabet and is not contained in the multiset. 
//For example, if a multiset of letters contains 7 letters 'b', 'a', 'b', 'c', 'e', 'c', 'f' 
//respectively, then the MEX letter of this compartment is 'd', 
//because 'd' is not included in the multiset, and all letters comes before 'd' in the alphabet, 
//namely 'a', 'b' and 'c', are included in the multiset.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤100). Description of the test cases follows.
// The first line of each test case contains two integers 𝑛 and 𝑘 (1≤𝑛≤200; 1≤𝑘≤𝑛). It is guaranteed that 𝑛 is divisible by 𝑘.
// The second line of each test case contains a string of 𝑛 lowercase Latin letters from 'a' to 'y' inclusively. Each letter represents the starting letter of the title of a book in the initial heap.
// It is guaranteed that the sum of 𝑛 over all test cases does not exceed 1000.

// Output
// For each test case, output a string of 𝑘 letters which is the most optimal string that Ela can find.

// TEST
// 5
// 12 3
// cabccadabaac
// 12 6
// cabccadabaac
// 12 12
// cabccadabaac
// 25 1
// abcdefghijklmnopqrstuvwxy
// 10 5
// bcdxedbcfg

// edb
// ccbbba
// bbbbbaaaaaaa
// z
// aaaaa

void solve() {
	int n, k;
	string s, ans = "";
	cin >> n >> k;
	cin >> s;
	map<char, int> m;
	for(char x : s) {
		if(m.count(x)) {
			m[x]++;
		} else {
			m.insert({x, 1});
		}
	}
	int c = n/k;
	for(int i = 0; i < k; i++) {
		string temp = "";
		for(auto itr = m.begin(); itr!=m.end(); itr++) {
			if(temp.length()<c && (*itr).ss>0){
				temp = temp + (*itr).ff;
				m[(*itr).ff]--;
			} else {
				break;
			}
		}
		sort(all(temp));
		for(int i = 97; i <= 122; i++) {
			bool ok = false;
			char g = i;
			for(auto s : temp) {
				if(s==g) {
					ok = true;
					break;
				}
			}
			if(ok == false) {
				ans=ans+g;
				break;
			}
		}
	}
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