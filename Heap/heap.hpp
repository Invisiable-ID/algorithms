#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include<iostream>
#include<vector>

using namespace std;

class Heap
{
	private:
		vector<int> data;
	public:
		void init();
		int top();
		void push(int k);
		void pop();
		//the most important functions
		void swim(int position);
		void sink(int position);
		void swap(int& key1, int& key2);
		int size();
		void output();
};

//in order to deal with it easier, we don't use the first position of the array
void Heap::init()
{
	if(this->data.size() == 0)
		this->data.push_back(0);
	else
		return;
}

//return the size of the heap
int Heap::size()
{
	return this->data.size()-1;
}

int Heap::top()//return the top of the heap
{
	return this->data[1];
}

void Heap::push(int k)//push any element into the heap
{
	this->data.push_back(k);
	swim(this->data.size()-1);//the k's position is data.size()-1
}

void Heap::pop()
{
	//pop the first one, after that we need to remake the whole heap
	//swap the first one with the last one and delete the last one
	swap(this->data[1], this->data.back());
	this->data.pop_back();
	//sink the new first one, whose position is 0
	sink(0);
}

void Heap::swim(int position)
{
	//the maximum swim to the top
	//we consider the heap as a tree rather than an array, then we can see that the position is from 1 rather than 0
	while(position>1 && this->data[position/2]<this->data[position])
	{
		swap(this->data[position/2], this->data[position]);
		position /= 2;
	}
}

void Heap::sink(int position)
{
	int size = this->data.size()-1;
	while(position*2 <= size)
	{
		int temp = position*2;
		if(this->data[position] <= this->data[temp])
			break;
		else
		{
			swap(this->data[position], this->data[temp]);
			position = temp;
		}
	}
}
void Heap::swap(int& key1, int& key2)
{
	key1 ^= key2;
	key2 ^= key1;
	key1 ^= key2;
}

void Heap::output()
{
	vector<int>::iterator it = this->data.begin();
	it++;
	for(; it!=this->data.end(); it++)
		cout << *it << endl;
}

#endif
