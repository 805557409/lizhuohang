/**
 * 作者:李卓航 QG第一周的作业
 **/
#pragma once
#include <iostream>
using namespace std;


#ifndef __QGLIST_H__
#define __QGLIST_H__

/*
 * 双向链表
 */
class QGList {

public:
	typedef int ElemType;

	struct Node {
		ElemType data;
		struct Node* prior;
		struct Node* next;
	};

	Node* head;

public:

	/*
	 * 初始化链表
	 */
	QGList();

	/*
	 * 销毁链表
	 */
	~QGList();

	/*
	 * 返回链表中第一个元素的引用
	 */
	ElemType& front();


	/*
	 * 返回链表中最后一个元素的引用
	 */
	ElemType& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	QGList::Node* push_front(QGList::ElemType& e1);

	/*
	 * 删除链表第一个元素
	 */
	QGList::Node* pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	QGList::Node* push_back(QGList::ElemType& e2);

	/*
	 * 删除链表最后一个元素
	 */
	QGList::Node* pop_back();

	QGList::Node* GetElemP(unsigned int index);

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	QGList::Node* insert(unsigned int index, QGList::ElemType& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(ElemType& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(ElemType& e));

	void show_Menu();

	void exitSystem();

	QGList::Node* creat();
};

void visit1(QGList::ElemType& e);
void print1(QGList::Node* head);

#endif
