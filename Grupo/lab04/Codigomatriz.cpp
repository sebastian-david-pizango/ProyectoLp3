#include <iostream>
using namespace std;
int const NMAX =10000;
int randomnumber(){ //crear numeros random
    int a;
    a = rand() % 101;
    return a;
}
int sumaMat(int mat[][NMAX], int row, int col){
    int contenedor;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            contenedor+=mat[i][j];
        }
    }
    return contenedor;
}
void crear_matrandom(int mat[][NMAX],int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            mat[i][j] = randomnumber();
        }
    }
}
int main() {
    int row = 5;
    int col = 5;
    int mat[row][col];
    crear_matrandom(mat,row,col);
    sumaMat(mat,row,col);
    return 0;
}
