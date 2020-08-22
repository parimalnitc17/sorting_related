#include<bits/stdc++.h>
using namespace std;
int findpeak(int arr[], int st, int en, int n) {
	int mid = (st + en) / 2;
	if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
		return mid;
	}
	if (mid > 0 && arr[mid] < arr[mid - 1]) {
		return findpeak(arr, st, mid - 1, n);
	}
	else {
		return findpeak(arr, mid + 1, en, n);
	}
}
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
	vector<int> v;
	int i, j;
	for ( i = 0, j = 0; i < n && j < m;) {
		if (arr1[i] < arr2[j]) {
			v.push_back(arr1[i]);
			int x = i;
			while (arr1[x] == arr1[i]) {
				i++;
			}

			continue;
		}
		if (arr1[i] > arr2[j]) {
			v.push_back(arr2[j]);
			int x = j;
			while (arr2[x] == arr2[j]) {
				j++;
			}
			continue;
		}
		if (arr1[i] == arr2[j]) {
			v.push_back(arr2[j]);
			int x = i;
			while (arr1[x] == arr1[i]) {
				i++;
			}
			int z = j;
			while (arr2[z] == arr2[j]) {
				j++;
			}
		}
	}

	if (i < n) {
		for (int k = i; k < n;) {
			v.push_back(arr1[k]);
			int x = k;
			while (arr1[x] == arr1[k]) {
				k++;
			}
		}
	}
	if (j < m) {
		for (int k = j; k < m;) {
			v.push_back(arr2[k]);
			int z = k;
			while (arr2[z] == arr2[k]) {
				k++;
			}
		}
	}
	return v;
}
vector<int> printIntersection(int arr1[], int arr2[], int N, int M) {
	vector<int> v;
	int i = 0;
	int j = 0;
	while (i < N && j < M) {
		if (arr1[i] < arr2[j]) {
			int x = i;
			while (arr1[x] == arr1[i]) {
				i++;
			}
			continue;
		}
		if (arr1[i] > arr2[j]) {
			int x = j;
			while (arr2[x] == arr2[j]) {
				j++;
			}
			continue;
		}
		if (arr1[i] == arr2[j]) {
			v.push_back(arr1[i]);
			int x = j;
			while (arr2[x] == arr2[j]) {
				j++;
			}
			int z = i;
			while (arr1[z] == arr1[i]) {
				i++;
			}

		}


	}
	if (v.size() == 0) {
		v.push_back(-1);
	}

	return v;

}

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[n];
	int arr2[m];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	vector<int> v = findUnion(arr1, arr2, n, m);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	/*cout << findpeak(arr, 0, n - 1, n) << endl;*/

}
