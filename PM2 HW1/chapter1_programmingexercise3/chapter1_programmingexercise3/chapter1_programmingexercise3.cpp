// Mhammed Alhayek Homework 1: Chapter 1 Programming Exercise 3

#include <iostream>

using namespace std;

class Matrix{
public:
    /** adds two matrices together
     @pre mat1 and mat2 have equal dimensions
     @post a new matrix which is the mat1 and mat2 added together is returned.
     @param mat1 and mat2 are the matrices being added together.
     
    */
    Matrix addMatrices(Matrix mat1, Matrix mat2);
    
    /** multiplies two matrices to form a third one
     @pre mat1 and mat2 are n by m matrices. dimension m of mat1 is equal to dimension n of mat2
     @post a new matrix which is the matrix product of mat1 and mat2 is returned.
     @param mat1 and mat2 are the matrices being multiplied together.
     
     */
    Matrix multMatrices(Matrix mat1, Matrix mat2);
    
    /** multiplies a matrix by a scalar.
     @pre mat1 is an n by m matrices. scalar is an int that you want to scale the matrix by.
     @post a new matrix which is the mat1 multiplied by the scalar is returned.
     @param mat1 is a matrix. scalar is an int to multiply it by.
     
     */
    Matrix scaleMatrix(Matrix mat1, int scalar);
    
    /** transposes a matrix
     @pre mat1 is an n by m matrices. 
     @post a new matrix which is mat1 with m by n dimensions is returned.
     @param mat1 is the matrix to transpose.
     
     */
    Matrix transposeMatrix(Matrix mat1);
private:
    int m;
    int n;
    int mat[1][1];
};
