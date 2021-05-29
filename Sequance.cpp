#include "Sequance.h"
#include <iostream>
#include <math.h>



template <class T>
ArrayVector<T>::ArrayVector(T* item, int n) {
	items = new DynamicArray<T> (item,n);
 }

template <class T> 
ArrayVector<T>::ArrayVector() {
	items = new DynamicArray<T>(0);
}

template <class T> 
ArrayVector<T>::ArrayVector(const ArrayVector<T>& arrVec) {
	items = new DynamicArray<T>(*(arrVec.items)) ;
}


//декомпозиция
template <class T>
T  ArrayVector<T>::GetFirst() {
	return items->Get(0);
}

template <class T> 
T ArrayVector<T>::GetLast() {
	return items->Get(items->GetSize() - 1);
}

template <class T> 
T ArrayVector<T>::Get(int i) {
	return items->Get(i);
}


template <class T> 
ArrayVector<T>* ArrayVector<T>::GetSubVector(int i, int j) {
	try {
		ArrayVector<T>* newVec = new ArrayVector<T>;
		for (int k = 0; k < j - i + 1; k++) {
			newVec->Append(items->Get(i + k));
		}
		return newVec;
		throw ;
	}
	catch(int i)  {
		std::cout << "Out of range in GetSubLVector\n" << std::endl;
	}
}

template <class T> 
int ArrayVector<T>::GetLength() {
	return items->GetSize();
}


//операции
template <class T> 
void ArrayVector<T>::Append(T item) {
	items->Resize(items->GetSize() + 1);
	items->Set(item, items->GetSize() - 1);
}

template <class T> 
void ArrayVector<T>::Prepend(T item) {
	items->Resize(items->GetSize() + 1);
	for (int i = items->GetSize() - 1; i > 0; i--) {
		items->Set(items->Get(i - 1), i);
	}
	items->Set(item, 0);
}

template <class T> 
void ArrayVector<T>::InsertAt(T item, int i) {
	try {
		items->Resize(items->GetSize() + 1);
		for (int k = items->GetSize() - 1; k >= i; k--) {
			items->Set(items->Get(k - 1), k);
		}
		items->Set(item, i);
		throw i;
	}
	catch (int i) {
		std::cout << "Out of range in InsertAt: " << i << std::endl;
	}
}

template <class T>
ArrayVector<T>* ArrayVector<T>::Concat(ArrayVector<T>* arrVec) {
	ArrayVector<T>* newVec = new ArrayVector<T>;
	for (int i = 0; i < this->items->GetSize(); i++) {
		newVec->Append(this->Get(i));
	}
	for (int i = 0; i < arrVec->GetLength(); i++) {
		newVec->Append(arrVec->Get(i));
	}
	return newVec;
}

template <class T>
void ArrayVector<T>::Sum(ArrayVector<T>* vec) {
	if (vec->GetLength() != this->GetLength()) {
		std::cout << "different sizes in Sum\n";
		return;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		this->items->Set(vec->Get(i) + this->Get(i), i);
	}
}

template <class T>
void ArrayVector<T>::MultOnScal(int k) {
	for (int i = 0; i < this->GetLength(); i++) {
		items->Set(this->Get(i) * k, i);
	}
}

template <class T>
T ArrayVector<T>::Norm() {
	T norm = 0;
	for (int i = 0; i < this->GetLength(); i++) {
		norm += this->Get(i) * this->Get(i);
	}
	return sqrt(norm);
}

template <class T> 
T ArrayVector<T>::ScalMult(ArrayVector<T>* vec) {
	if (this->GetLength() != vec->GetLength()) {
		std::cout << "different sizes if ScalMult\n";
		return 0;
	}
	T scal = 0;
	for (int i = 0; i < this->GetLength(); i++) {
		scal += this->Get(i) * vec->Get(i);
	}
	return scal;
}

template <class T>
void ArrayVector<T>::Output() {
	for (int i = 0; i < this->GetLength(); i++) {
		std::cout << this->Get(i) << " ";
	}
	std::cout << std::endl;
}

//list-----------------------------

template <class T>
ListVector<T>::ListVector(T* item, int n) {
	items = new LinkedList<T>(item, n);
}

template <class T>
ListVector<T>::ListVector() {
	items = new LinkedList<T>;
}

template <class T>
ListVector<T>::ListVector(const ListVector<T>& listVec) {
	items = new LinkedList<T>(*(listVec.items));
}

//декомпозиция
template <class T>
T ListVector<T>::GetFirst() {
	return items->GetFirst();
}

template <class T>
T ListVector<T>::GetLast() {
	return items->GetLast();
}

template <class T>
T ListVector<T>::Get(int i) {

	return items->Get(i);
}


template <class T>
ListVector<T>* ListVector<T>::GetSubVector(int i, int j) {
	 LinkedList<T>* ptr = items->GetSubList(i, j);
	 items = ptr;
	 return this;
}

template <class T>
int ListVector<T>::GetLength() {
	return items->GetLength();
}


//операции
template <class T>
void ListVector<T>::Append(T item) {
	items->Append(item);
}

template <class T>
void ListVector<T>::Prepend(T item) {
	items->Prepend(item);
}

template <class T>
void ListVector<T>::InsertAt(T item, int i) {
	items->InsertAt(item, i);
}

template <class T>
ListVector<T>* ListVector<T>::Concat(ListVector<T>* arrVec) {
	LinkedList<T> ptr = items->Concat(arrVec->items);
	*items = ptr;
	return this;
}

//доп операции

template <class T>
void ListVector<T>::Sum(ListVector<T>* vec) {
	if (this->GetLength() != vec->GetLength()) {
		std::cout << "different sizez in sum\n";
		return;
	}
	for (int i = 0; i < this->GetLength(); i++) {
		this->items->Set(this->Get(i) + vec->Get(i), i);
	}
}

template <class T>
void ListVector<T>::MultOnScal(int k) {
	for (int i = 0; i < this->GetLength(); i++) {
		this->items->Set(this->Get(i) * k, i);
	}
}

template <class T>
T ListVector<T>::Norm() {
	T norm = 0;
	for (int i = 0; i < this->GetLength(); i++) {
		norm += this->Get(i) * this->Get(i);
	}
	return sqrt(norm);
}

template <class T>
T ListVector<T>::ScalMult(ListVector<T>* vec) {
	if (this->GetLength() != vec->GetLength()) {
		std::cout << "Differen Sizes in ScalMult\n";
		return 0;
	}
	T scal = 0;
	for (int i = 0; i < this->GetLength(); i++) {
		scal += this->Get(i) * vec->Get(i);
	}
	return scal;
}

template <class T>
void ListVector<T>::Output() {
	for (int i = 0; i < this->GetLength(); i++) {
		std::cout << this->Get(i) << " ";
	}
	std::cout << std::endl;
}


//stek array

template <class T>
ArrayStek<T>::ArrayStek(T* item, int n) {
	items = new DynamicArray<T>(item, n);
}

template <class T>
ArrayStek<T>::ArrayStek() {
	items = new DynamicArray<T>(0);
}

template <class T>
ArrayStek<T>::ArrayStek(const ArrayVector<T>& arrVec) {
	items = new DynamicArray<T>(*(arrVec.items));
}

template <class T>
T ArrayStek<T>::GetLast() {
	return items->Get(items->GetSize() - 1);
}

template <class T>
void ArrayStek<T>::Append(T item) {
	items->Resize(items->GetSize() + 1);
	items->Set(item, items->GetSize() - 1);
}

template <class T>
int ArrayStek<T>::GetLength() {
	return items->GetSize();
}

template <class T>
void ArrayStek<T>::Output() {
	for (int i = 0; i < this->GetLength(); i++) {
		std::cout << this->Get(i) << " ";
	}
	std::cout << std::endl;
}

template <class T>
void ArrayStek<T>::Pop()
{
	items->Resize(items->GetSize() - 1);
}

template <class T>
T ArrayStek<T>::Get(int i) {
	return items->Get(i);
}

//stek list

template <class T>
ListStek<T>::ListStek(T* item, int n) {
	items = new LinkedList<T>(item, n);
}

template <class T>
ListStek<T>::ListStek() {
	items = new LinkedList<T>;
}

template <class T>
ListStek<T>::ListStek(const ListVector<T>& listVec) {
	items = new LinkedList<T>(*(listVec.items));
}

template <class T>
T ListStek<T>::GetLast() {
	return items->GetLast();
}

template <class T>
void ListStek<T>::Append(T item) {
	items->Append(item);
}

template <class T>
int ListStek<T>::GetLength() {
	return items->GetLength();
}

template <class T>
void ListStek<T>::Output() {
	for (int i = 0; i < this->GetLength(); i++) {
		std::cout << this->Get(i) << " ";
	}
	std::cout << std::endl;
}

template <class T>
void ListStek<T>::Pop()
{
	LinkedList<T>* ptr = new LinkedList<T>;
	for (int i = 0; i < items->GetLength() - 1; i++)
	{
		ptr->Append(items->Get(i));
	}
	delete[] items;
	items = ptr;
	return;
}

template <class T>
T ListStek<T>::Get(int i) {
	return items->Get(i);
}
