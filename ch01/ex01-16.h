#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using std::vector;

template <typename Object>
class Matrix {
    private:
        vector<vector<Object> > array;
    
    public:
        Matrix(int rows, int cols);

        Matrix(vector<vector<Object> > v);

        Matrix(vector<vector<Object> > &&v);

        const vector<Object> & operator[](int row) const;

        vector<Object> & operator[](int row);

        int numrows() const;

        int numcols() const;

        /*------------Answer------------*/

        explicit Matrix();

        void resize(int row, int col);


};

template <typename Object>
Matrix<Object>::Matrix() : Matrix(1, 1) {

}

template <typename Object>
void Matrix<Object>::resize(int row, int col) {
    array.resize(row);
    for (auto &thisRow : array) {
        thisRow.resize(col);
    }
}

/*----------------------Above is implements Answer---------------------------*/

template <typename Object>
Matrix<Object>::Matrix(int rows, int cols) : array(rows) {
    for (auto &thisRow : array) {
        thisRow.resize(cols);
    }
}

template <typename Object>
Matrix<Object>::Matrix(vector<vector<Object> > v) : array{ v } {

}

template <typename Object>
Matrix<Object>::Matrix(vector<vector<Object> > &&v) : array { std::move(v) }{

}

template <typename Object>
const vector<Object> & Matrix<Object>::operator[](int row) const {
    return array[row];
}

template <typename Object>
vector<Object> & Matrix<Object>::operator[](int row) {
    return array[row];
}

template <typename Object>
int Matrix<Object>::numrows() const { 
    return array.size( );
}

template <typename Object>
int Matrix<Object>::numcols() const { 
    return numrows( ) ? array[ 0 ].size( ) : 0; 
}

#endif