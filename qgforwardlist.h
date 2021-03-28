/**
 * ����:��׿�� QG��һ�ܵ���ҵ
 **/


#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

int n;

 /*
  * ��������
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
	 * ��ʼ������
	 */
	QGForwardList();

	/*
	 * ��������
	 */
	~QGForwardList();

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
	QGForwardList::Node* push_front(ElemType& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	QGForwardList::Node* pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	QGForwardList::Node* push_back(QGForwardList::ElemType& e2);
	/*
	 * ɾ���������һ��Ԫ��
	 */
	QGForwardList::Node* pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	QGForwardList::Node* insert(unsigned int index, QGForwardList::ElemType& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	QGForwardList::Node* erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	QGForwardList::Node* contain(QGForwardList::ElemType& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(ElemType& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	QGForwardList::Node* reverse();

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	QGForwardList::Node* reverseEven();

	/*
	 * �����м�ڵ�
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

