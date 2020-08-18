#include<bits/stdc++.h>
using namespace std;
int partition(int* arr, int st, int en) {

	int pivot = st;
	int count = 0;
	for (int i = st; i <= en; i++) {
		if (arr[pivot] > arr[i]) {
			count++;
		}
	}
	swap(arr[pivot], arr[pivot + count]);
	pivot = st + count;
	int j = st;
	int k = en;
	while (j < pivot && k > pivot) {
		if (arr[j] >= arr[pivot] && arr[k] < arr[pivot]) {
			swap(arr[j], arr[k]);
			j++;
			k--;
		}
		if (arr[j] < arr[pivot]) {
			j++;
		}
		if (arr[k] >= arr[pivot]) {
			k--;
		}


	}

	return pivot;

}


void quickSort(int* arr, int st, int en) {
	if (st >= en) {
		return;
	}
	int pivot = partition(arr, st, en);
	quickSort(arr, st, pivot - 1);
	quickSort(arr, pivot + 1, en);

}
int main() {

	int n;
	cin >> n;
	int arr[n];
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;




	return 0;

}
