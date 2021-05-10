#include"heap.hpp"
#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	Heap heap;
	heap.init();
	int val = 9;
	heap.push(val);
	int data = 8;
	int bte = 4;
	heap.push(data);
	heap.push(bte);
	heap.output();
	return 0;
}
