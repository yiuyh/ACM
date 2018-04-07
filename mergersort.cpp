//πÈ≤¢≈≈–Ú    
#include<iostream>
#define maxn 10000+10
using namespace std;
int arr[maxn];
int n;

void Merge(int *arr, int l, int m, int r){
	int *help = new int[r-l+1];
	int p1 = l;
	int p2 = m+1;
	int i = 0;
	while(p1 <= m && p2 <= r){
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while(p1 <= m) help[i++] = arr[p1++];
	while(p2 <= r) help[i++] = arr[p2++];
	for(i = 0; i < (r-l+1); i++){
		arr[l+i] = help[i];
	}
}

void mergeSort(int *arr, int l, int r){
	if(l == r) return;
	int mid = l + ((r-l) >> 1);
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	Merge(arr, l, mid, r);
}

void mergeSort(int *arr){
	if(n < 2){
		return;
	}
	mergeSort(arr, 0, n-1);
}  

void input(){
	cin >> n;
	int i;
	for(i = 0; i < n; i++){
		cin >> arr[i];
	}
} // ‰»Î

void Print(){
	int i;
	for(i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}// ‰≥ˆ 

int main(){
	input();
	mergeSort(arr);
	Print();
	return 0;
}
