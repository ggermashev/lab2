#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node {
	T data;
	Node* next;
};

template <class T> class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	//��������
	LinkedList(T* item, int n);
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	//������������
	T GetFirst();
	T GetLast();
	T Get(int i);
	LinkedList<T>* GetSubList(int i, int j);
	int GetLength();
	//��������
	void Append(T item);
	void Prepend( T item );
	void InsertAt(T item, int i);
	LinkedList<T> Concat(LinkedList<T>* list);


	void Set(T item, int i);
};


#endif // !LINKEDLIST_H





