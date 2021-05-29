
#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H


template <class T> class DynamicArray {
private:
	T* elem;
	int size;
public:
	//��������
	DynamicArray(T* item, int n);
	DynamicArray(int n);
	DynamicArray(const DynamicArray<T>& dynArr);
	//������������
	T Get(int i);
	int GetSize();
	//��������
	void Set(T Value, int i);
	void Resize(int newsz);
};

#endif // !DINAMICARRAY_H

