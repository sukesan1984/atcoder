#include <unordered_set>
#include <iostream>

using ll = int64_t;
using namespace std;

int main()
{
	ll N;
	unordered_set<ll> s;

	cin >> N;

	for (ll i = 2; i * i <= N; i++)
	{
		ll x = i * i;
		while (x <= N)
		{
			s.insert(x);
			x *= i;
		}
	}
	cout << N - s.size() << endl;
}
