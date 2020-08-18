#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
	cin >> n;
	int arr[n];
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n ; i++) {
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;




	return 0;

}
