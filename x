curl



#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> pierwsze;
	int T[n + 1];
	for (int i = 2; i <= n; i++) {
		T[i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		if (T[i] == 0) {
			pierwsze.push_back(i);
			int temp = i;
			while (temp <= n) {
				T[temp] = 1;
				temp = temp + i;
			}
		}
	}
	for (int i = 0; i < pierwsze.size(); i++) {
		cout << pierwsze[i] << " ";
	}
}
