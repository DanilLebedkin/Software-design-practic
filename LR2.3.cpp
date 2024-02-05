#include<iostream>
using namespace std;
void crmatr(int **matr,int x,int y);
int main() {
	int x, y;
	cout << "Input x"<<endl;
	cin >> x;
	cout << "Input y"<<endl;
	cin >> y;
	int** matr = new int*[x];
	for (int i = 0; i < x; i++) matr[i] = new int[y];
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) {
			cout << "m[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
	crmatr(matr,x,y);
	system("pause");
	return 0;
}
void crmatr(int **matr,int x,int y){
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
}