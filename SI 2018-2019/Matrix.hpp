#pragma once
#include <iostream>

template <class T>
class Matrix 
{
private:
	T** mtx;
	size_t rows;
	size_t cols;

	void init();

	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	void free();

public:
	Matrix();
	Matrix(size_t rows, size_t cols);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	Matrix(Matrix&& other) noexcept;
	Matrix& operator=(Matrix&& other) noexcept;
	~Matrix();

	void setAt(unsigned int x, unsigned int y, T element);
	T& getAt(unsigned int x, unsigned int y);
	const T& getAt(unsigned int x, unsigned int y) const;
	void transpose();

	void print() const;
};

template <class T>
void Matrix<T>::init()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mtx[i][j] = T();
		}
	}
}
template <class T>
Matrix<T>::Matrix():rows(2),cols(2)
{
	mtx = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		mtx[i] = new T[cols];
	}

	init();
}

template <class T>
Matrix<T>::Matrix(size_t rows, size_t cols) :rows(rows), cols(cols)
{
	mtx = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		mtx[i] = new T[cols];
	}
	init();
}

template <class T>
void Matrix<T>::copyFrom(const Matrix<T>& other)
{
	mtx = new T*[other.rows];
	for (int i = 0; i < other.rows; i++)
	{
		mtx[i] = new T[other.cols];
	}
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			mtx[i][j] = other.mtx[i][j];
		}
	}
	rows = other.rows;
	cols = other.cols;
}

template <class T>
void Matrix<T>::free()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& other)
{
	copyFrom(other);
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
	if (this!=&other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <class T>
Matrix<T>::~Matrix()
{
	free();
}

template <class T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, T element)
{
	x = x - 1;
	y = y - 1;

	if (x>=rows || y>=cols)
	{
		throw std::invalid_argument("Out of range");
	}
	mtx[x][y] = element;
}

template <class T>
T& Matrix<T>::getAt(unsigned int x, unsigned int y) 
{
	x = x - 1;
	y = y - 1;
	if (x>=rows||y>=cols)
	{
		throw std::invalid_argument("Out of range");
	}

	return mtx[x][y];
}

template <class T>
const T& Matrix<T>::getAt(unsigned int x, unsigned int y) const
{
	x = x - 1;
	y = y - 1;

	if (x>=rows||y>=cols)
	{
		throw std::invalid_argument("Out of range");
	}
	return mtx[x][y];
}

template <class T>
void Matrix<T>::transpose()
{
	T** newMtx = new T * [cols];
	for (size_t i = 0; i < cols; i++) 
	{
		newMtx[i] = new T[rows];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newMtx[j][i] = mtx[i][j];
		}
	}
	for (size_t i = 0; i < rows; i++) 
	{
		delete[] mtx[i];
	}
	delete[] mtx;
	
	mtx = newMtx;
	newMtx = nullptr;
	std::swap(rows, cols);
}

template <class T>
void Matrix<T>::print() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << mtx[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

template <class T>
void Matrix<T>::moveFrom(Matrix<T>&& other)
{
	mtx = other.mtx;
	other.mtx = nullptr;

	rows = other.rows;
	other.rows = 0;

	cols = other.cols;
	other.cols = 0;
}

template <class T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept
{
	if (this!=&other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}