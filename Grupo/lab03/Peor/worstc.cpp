#include <iostream>
using namespace std;
int array[0];

void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void peor (int num){
    array [num];
    for (int i = num; i > -1; i--){
        array [i] = num-i;
    }
    print(array,num);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
	print(array,n);
    }
}

int main()
{
    int num;
    cout<<"Ingrese el valor del array"<<endl;
    cin>>num;
    peor(num);
    insertionSort(array,num);
}
