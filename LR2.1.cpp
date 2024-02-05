#include<iostream>
using namespace std;
#define MAX 10
int Max(int array[], int n);
int Min(int array[],int n);
int main(){
	int array[MAX]{}, i = 0, n=0;
	cout << "Enter elements of array" << endl;
	cout << "For ending press 0" << endl;
	do {
		cout << "M[" << i << "]= ";
		cin >> array[i];
		n++;
	} while (array[i++] && i != MAX);
	n--;
	cout << "Max element of array " << Max(array, n)<<endl;
	cout << "Min element of array " << Min(array, n)<<endl;
	
	
	system("pause");
	return 0;
}
int Max(int array[], int n) {
	int i=0, max=0;
	for (i = 0; i < n; i++) {
		if (array[i] > max) max = array[i];
	}
	return max;
}
int Min(int array[], int n) {
	int  min=array[0];
	for (int i = 1; i < n; ++i) {
		if (array[i] < min) min = array[i];
	}
	return min;
}
