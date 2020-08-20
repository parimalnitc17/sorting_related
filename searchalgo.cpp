#include<iostream>
#include<algorithm>

using namespace std ;

int bsearch(int* arr, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int mid = (r + l) / 2;
		if (arr[mid] == x) {
			return x;
		}
		if (arr[mid] < x) {
			l = mid + 1;
		}
		if (arr[mid] > x) {
			r = mid - 1;
		}
	}
	return -1;
}

int recurbsearch(int* arr, int st, int en, int x) {
	if (st > en) {
		return -1;
	}
	int mid = (st + en) / 2;
	if (arr[mid] == x) {
		return x;
	}
	if (arr[mid] < x) {
		return recurbsearch(arr, mid + 1, en, x);
	}

	return recurbsearch(arr, st, mid - 1, x);

}

int ternarysearch(int* arr, int st, int en, int x) {
	if (st > en) {
		return -1;
	}
	int mid1 = st + (st + en) / 3;
	int  mid2 = en - (st + en) / 3;

	if (arr[mid1] == x || arr[mid2] == x) {
		return x;
	}

	if (arr[mid1] < x && arr[mid2] > x) {
		return ternarysearch(arr, mid1 + 1, mid2 - 1, x);
	}

	if (arr[mid1] > x) {
		return ternarysearch(arr, st, mid1 - 1, x);
	}

	return ternarysearch(arr, mid2 + 1, en, x);

}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int x;
	cin >> x;
	cout << bsearch(arr, n, x) << endl;
	cout << recurbsearch(arr, 0, n - 1, x) << endl;
	cout << ternarysearch(arr, 0, n - 1, x) << endl;

	return 0;
}