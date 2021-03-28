/**
 * 作者:李卓航 QG第一周的作业
 **/


#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

int n;

 /*
  * 单向链表
  */
class QGForwardList {

public:
	typedef int ElemType;

	struct Node {
		ElemType data;
		struct Node* next;
	};

	Node* head;

public:

	friend class QGForwardList;
	/*
	 * 初始化链表
	 */
	QGForwardList();

	/*
	 * 销毁链表
	 */
	~QGForwardList();

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
	QGForwardList::Node* push_front(ElemType& e);

	/*
	 * 删除链表第一个元素
	 */
	QGForwardList::Node* pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	QGForwardList::Node* push_back(QGForwardList::ElemType& e2);
	/*
	 * 删除链表最后一个元素
	 */
	QGForwardList::Node* pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	QGForwardList::Node* insert(unsigned int index, QGForwardList::ElemType& e);

	/*
	 * 删除任意位置元素
	 */
	QGForwardList::Node* erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	QGForwardList::Node* contain(QGForwardList::ElemType& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(ElemType& e));

	/*
	 * 反转链表，1234反转后变成4321
	 */
	QGForwardList::Node* reverse();

	/*
	 * 链表判环
	 */
	bool isLoop();

	/*
	 * 偶节点反转，1234反转后变成2143
	 */
	QGForwardList::Node* reverseEven();

	/*
	 * 返回中间节点
	 */
	QGForwardList::Node* middleElem();

	
	QGForwardList::Node* creat();

	void show_Menu();

	void exitSystem();
};

	void print1(QGForwardList::Node* head);
	void Inverted(QGForwardList::Node* head, int a, int b);
	int Size(QGForwardList::Node* head);
	int Size1(QGForwardList::Node* p);
	void visit1(QGForwardList::ElemType& e);

#endif

