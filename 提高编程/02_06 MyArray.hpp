#define _CRT_SECURE_NO_WARNINGS 1   
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		//cout << "有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//按照容量开辟数组
	}
	//拷贝构造函数
	MyArray(const MyArray& arr)
	{
		//cout << "拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//堆区数据深拷贝
		this->pAddress=new T[arr.m_Capacity];
		//将arr中的数据都copy过来
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator=  防止浅拷贝问题 运算符重载
	MyArray& operator=(const MyArray& arr)  //返回自身，可以连续=
	{
		//cout << "operator=" << endl;
		//先判断原来堆区是否有数据，有的话先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//堆区数据深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都copy过来
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void Push_Back(const T &val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;  //数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	//尾删方法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑上的删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//通过下标方式访问元素  如果函数的返回想要作为函数的左值存在，需要返回引用
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}

	//析构函数 释放堆区数据
	~MyArray()
	{
		//cout << "析构" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress; //指针指向堆区开辟的真实的数组
	int m_Capacity;   //数组容量
	int m_Size;    //数组大小

};