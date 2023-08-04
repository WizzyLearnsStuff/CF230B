#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool is_comp[1000001] = {0};

int main() {
	int n;
	cin >> n;

	vector<int> primes;
	vector<long long int> primesq;

	for (int i = 2; i <= 1000000; i++) {
		if (!is_comp[i]) { primes.push_back(i); primesq.push_back((long long int)i * (long long int)i); }
		for (int j = 0; j < primes.size() && i * primes[j] < 1000001; j++) {
			is_comp[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}

	for (int i = 0; i < n; i++) {
		long long int a = 0;
		cin >> a;
		cout << (binary_search(primesq.begin(), primesq.end(), a) ? "YES\n" : "NO\n");
	}
}
