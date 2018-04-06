#include<iostream>
#define maxn 100000+10
using namespace std;
int arr[maxn];
int n;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void Insertionsort(){
	if (n == 0 || n < 2) {
		return;
	}
	int i, j;
	for(i = 1; i < n; i++)
	    for(j = i-1; j >= 0; j--){
	    	if(arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
		}
}

void Selectionsort(){
	if (n == 0 || n < 2) {
		return;
	}
	int minindex, i, j;
	for(i = 0; i < n-1; i++){
		minindex = i;
		for(j = i+1; j < n; j++){
			minindex = arr[j] < arr[minindex] ? j : minindex;
		}
		swap(arr[i], arr[minindex]);
	}
}

void Bubblesort()
{
	if (n == 0 || n < 2) {
		return;
	}
	int i, j;
	for (i = n-1; i > 0; i--)
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
	}
}

void input(){
	cin >> n;
	int i;
	for(i = 0; i < n; i++)
	    cin >> arr[i];
}

void Print(){
	int i;
	for(i = 0; i < n; i++)
	    cout << arr[i] << " ";
}

int main()
{
	input();
	Selectionsort();
	Print();
    return 0;
}
