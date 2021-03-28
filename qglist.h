/**
 * ����:��׿�� QG��һ�ܵ���ҵ
 **/
#pragma once
#include <iostream>
using namespace std;


#ifndef __QGLIST_H__
#define __QGLIST_H__

/*
 * ˫������
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
	 * ��ʼ������
	 */
	QGList();

	/*
	 * ��������
	 */
	~QGList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front();


	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	QGList::Node* push_front(QGList::ElemType& e1);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	QGList::Node* pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	QGList::Node* push_back(QGList::ElemType& e2);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	QGList::Node* pop_back();

	QGList::Node* GetElemP(unsigned int index);

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	QGList::Node* insert(unsigned int index, QGList::ElemType& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(ElemType& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(ElemType& e));

	void show_Menu();

	void exitSystem();

	QGList::Node* creat();
};

void visit1(QGList::ElemType& e);
void print1(QGList::Node* head);

#endif
