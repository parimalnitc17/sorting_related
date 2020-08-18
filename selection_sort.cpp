#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int maxi = INT_MIN;
		int index;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > maxi) {
				maxi = arr[j];
				index = j;
			}
		}
		swap(arr[index], arr[n - i - 1]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;

}