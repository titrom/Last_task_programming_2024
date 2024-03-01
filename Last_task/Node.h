#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
	int key;
	unsigned char height;
	T* left;
	T* right;

	Node(int k);
	virtual T* Insert(T* p, int k);
	virtual T* Remove(T* p, int k);
	virtual T* Search(T* p, int k);
private:
	virtual T* Balance(T* p);
	T* FindMin(T* p);
	T* RemoveMin(T* p);
};

template<typename T>
Node<T>::Node(int k) : key{ k }, left{ 0 }, right{ 0 }, height{ 1 }
{

};

template<typename T>
T* Node<T>::Insert(T* p, int k)
{
	if (!p) return new T(k);
	if (k < p->key) {
		p->left = Insert(p->left, k);
	}
	else {
		p->right = Insert(p->right, k);
	}
	return Balance(p);
}

template<typename T>
T* Node<T>::Remove(T* p, int k)
{
	if (!p) return 0;
	if (k < p->key) {
		p->left = Remove(p->left, k);
	}
	else if (k > p->key) {
		p->right = Remove(p->right, k);
	}
	else {
		T* l = p->left;
		T* r = p->right;
		delete p;
		if (!r) return l;
		T* min = FindMin(r);
		min->right = RemoveMin(r);
		min->left = l;
		return Balance(min);
	}
	return Balance(p);
}

template<typename T>
inline T* Node<T>::Search(T* p, int k)
{
	if (p == nullptr || p->key == k) {
		return p;
	}
	if (p->key < k) {
		return Search(p->right, k);
	}

	return Search(p->left, k);
}

template<typename T>
T* Node<T>::Balance(T* p)
{
	return p;
}

template<typename T>
T* Node<T>::FindMin(T* p)
{
	return p->left ? FindMin(p->left) : p;;
}

template<typename T>
T* Node<T>::RemoveMin(T* p)
{
	if (p->left == 0) {
		return p->right;
	}
	p->left = RemoveMin(p->left);
	return Balance(p);
}