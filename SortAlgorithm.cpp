#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;


	// Quick Sort
	//************************************************************************
	
	
void sort(int a[], int left, int right) {
	if(left > right) {
		return;
	}
	int i = left;
	int j = right;
	int pivot = a[(left+right)/2];
	do {
		while(a[i] < pivot) {
			i++;
		}
		while(a[j] > pivot) {
			j--;
		}
		if(i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while(i < j);
	sort(a,left,j);
	sort(a,i,right);
}


	// Merge Sort
	//************************************************************************
	
	
void merge(int a[], int left, int mid, int right) {
	int x = right-left+1;
	int temp[x];
	int pos = 0, i = left, j = mid+1;
	while(!(i > mid && j > right)) {
		if(i <= mid && j <= right && a[i] < a[j] || j > right) {
			temp[pos++] = a[i++];
		} else {
			temp[pos++] = a[j++];
		}
	}
	for(int i = 0; i < x; i++) {
		a[left+i] = temp[i];
	}
}

void mergesort(int a[], int left, int right) {
	if(left >= right) {
		return;
	}
	int mid = (left+right)/2;
	mergesort(a,left,mid);
	mergesort(a,mid+1,right);
	merge(a,left,mid,right);
}

int main () {
	srand(time(NULL));
	int n, a[100];
	cin >> n;
	for(int i = 0; i < n; i++) {
		a[i] = rand() % 100 + 1;
	}
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	
	//************************************************************************
	// Selection Sort
	
	
	/*int max;
	for(int i = 0; i < n; i++) {
		max = i;
		for(int j = i+1; j < n; j++) {
			if(a[j] > a[max]) {
				max = j;
			}
		}
		if(a[max] != a[i]) {
			int temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}*/
	
	//************************************************************************
	// Insertion Sort
	
	
	/*int x, j;
	for(int i = 1; i < n; i++) {
		x = a[i];
		for(j = i; j > 0 && a[j-1] > x; j--) {
			a[j] = a[j-1];
		}
		a[j] = x;
	}*/

	//************************************************************************
	// Interchange Sort
	
	
	/*for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}*/
	
	//************************************************************************
	
	return 0; 
}
