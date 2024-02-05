#include<iostream>
using namespace std;
double ser(int *arr,int n);
int main() {
	int n;
	cout << "Input n"<<endl;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n;i++) {
		cout << "M[" << i << "]= ";
		cin >> arr[i];
	}
	cout << "Average number " << ser(arr, n) << endl;;
	system("pause");
	return 0;
}
double ser(int *arr, int n) {
	double sum = 0,seredne;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	seredne = sum / n;
	return seredne;
}
