#include"qglist.h"

void QGList::show_Menu()
{
	cout << "****************************************************************************" << endl;
	cout << "*****************0.退出系统*************************************************" << endl;
	cout << "*****************1.创建列表*************************************************" << endl;
	cout << "*****************2.返回链表中第一个元素的引用*******************************" << endl;
	cout << "*****************3.返回链表中最后一个元素的引用*****************************" << endl;
	cout << "*****************4.在链表第一个元素前添加元素e******************************" << endl;
	cout << "*****************5.删除链表第一个元素***************************************" << endl;
	cout << "*****************6.在链表最后一个元素后添加元素e****************************" << endl;
	cout << "*****************7.删除链表最后一个元素*************************************" << endl;
	cout << "*****************8.在链表的第index + 1个元素前插入元素e*********************" << endl;
	cout << "*****************9.删除任意位置元素*****************************************" << endl;
	cout << "*****************10.清空链表************************************************" << endl;
	cout << "*****************11.查找元素是否存在****************************************" << endl;
	cout << "*****************12.返回链表中元素的数量************************************" << endl;
	cout << "*****************13.遍历链表, 对每个元素调用visit指向的函数*****************" << endl;
	cout << "****************************************************************************" << endl;
}

void QGList::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

QGList::QGList() {
	head = new Node;
	head->next = NULL;
	head->prior = NULL;
}

QGList::~QGList() {
	QGList::Node*q;
	QGList::Node*p = head->next; /* p指向第一个结点 */
	while (p != head) /* p没到表头 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(head);
	head = NULL;
}

/*
 * 返回链表中第一个元素的引用
 */
QGList::ElemType& QGList::front()
{
	QGList::Node* p;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	static int& a1 = p->data;

END:
	return a1;
}

/*
 * 返回链表中最后一个元素的引用
 */
QGList::ElemType& QGList::back() {
	QGList::Node* p;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	while (p->next != NULL) {
		p = p->next;
	}

	static int& b1 = p->data;

END:
	return b1;
}

/*
 * 在链表第一个元素前添加元素e
 */
QGList::Node* QGList::push_front(QGList::ElemType& e1)
{
	QGList::Node* p;
	QGList::Node* p1;
	QGList::Node* p2;
	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	p1 = p->next;

	p2 = new Node;

	p2->data = e1;

	p1 = p2->next;

	p->next = p2;

	p2->prior = p;

	p1->prior = p2;

END:
	return head;
}

/*
 * 删除链表第一个元素
 */
QGList::Node* QGList::pop_front() {
	QGList::Node* p;
	QGList::Node* p1;
	QGList::Node* p2;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	p1 = p->next;

	p2 = p->next;

	p1 = p1->next;

	p2->prior =NULL;

	head = p2;

	free(p);
END:
	return head;
}

/*
 * 在链表最后一个元素后添加元素e
 */
QGList::Node* QGList::push_back(QGList::ElemType& e2) {
	QGList::Node* p;
	QGList::Node* p1;
	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	while (p->next != NULL) {
		p = p->next;
	}

	p1 = new Node;

	p1->data = e2;

	p1->next = NULL;

	p->next = p1;

	p1->prior = p;

END:
	return head;
}

/*
 * 删除链表最后一个元素
 */
QGList::Node* QGList::pop_back() {
	QGList::Node* p;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	while (p->next->next != NULL) {
		p = p->next;
	}

	p->next = NULL;

END:
	return head;
}

QGList::Node* QGList::GetElemP(unsigned int index) /* 另加 */
{ /* 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在，*/
/* 返回NULL */
	int j;
	QGList::Node* p = head; /* p指向头结点 */
	if (index<0 || index>size()) { /* i值不合法 */
		return NULL;
	}
	for (j = 1; j <= index; j++) {
		p = p->next;
	}
	return p;
}


/*
 * 在链表的第index + 1个元素前插入元素e
 */
QGList::Node* QGList::insert(unsigned int index, QGList::ElemType& e) {
	QGList::Node* p;
	QGList::Node* s;
	if (index<1 || index>size() + 1) /* index值不合法 */
	{
		cout << "index值不合法" << endl;
		return 0;
	}
	p = GetElemP(index - 1); /* 在L中确定第i个元素前驱的位置指针p */
	if (!p) /* p=NULL,即第i个元素的前驱不存在(设头结点为第1个元素的前驱) */
	{
		cout << "ERROR" << endl;
		return 0;

	}
	s = new Node;
	if (!s) {
		cout << "OVERFLOW" << endl;
		return 0;
	}
	s->data = e;
	s->prior = p; /* 在第i-1个元素之后插入 */
	s->next = p->next;
	p->next->prior = s;
	p->next = s;

	cout << "插入成功" << endl;
	return head;
}

/*
 * 删除任意位置元素
 */
bool QGList::erase(unsigned int index) {
	QGList::Node* p;
	if (index < 1) /* index值不合法 */
	{
		cout << "ERROR" << endl;
		return 0;

	}
	p = GetElemP(index); /* 在L中确定第i个元素的位置指针p */
	if (!p) /* p=NULL,即第i个元素不存在 */
	{
		cout << "ERROR" << endl;
		return 0;

	}
	//*e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	cout << "插入成功" << endl;
	return 1;
}

/*
 * 清空链表,重置链表为空表
 */
bool QGList::clear() {
	QGList::Node* q;
	QGList::Node* p = head->next; /* p指向第一个结点 */
	if (head->next == head && head->prior == head) {
		return 1;
	}

	while (p != head) /* p没到表头 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = head->prior = head; /*头结点的两个指针域均指向自身 */
	return 1;
}

/*
 * 查找元素是否存在
 */
bool QGList::contain(QGList::ElemType& e) {
	int i = 0;
	QGList::Node* p = head->next; /* p指向第1个元素 */
	while (p != head)
	{
		i++;
		if (p->data == e) {/* 找到这样的数据元素*/
			return i;
		}
		p = p->next;
	}
	return 0;
}

/*
 * 返回链表中元素的数量
 */
unsigned int QGList::size() {
	int i = 0;
	QGList::Node* p = head->next; /* p指向第一个结点 */
	while (p != head) /* p没到表头 */
	{
		i++;
		p = p->next;
	}
	return i;
}

/*
 * 遍历链表, 对每个元素调用visit指向的函数
 */
bool QGList::traverse(void (*visit)(QGList::ElemType& e)) {
	QGList::Node* p = head;
	int e;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}
	if (p->next != NULL) {
		goto END;
	}
	p = p->next;

	while (p->next != NULL) {
		visit(e);
		p = p->next;
	}

END:
	return 1;
}

void visit1(QGList::ElemType& e)
{
	cout << "调用visit函数成功" << endl;
}

//打印链表
void print1(QGList::Node* head)
{
	QGList::Node* p;

	p = head;
	if (head)
	{
		cout << endl;
		do
		{
			cout << p->data << endl;
			p = p->next;
		} while (p);
	}
}

QGList::Node* QGList::creat()     //创建链表
{
	QGList::Node* p1;

	p1 = new Node;

	cout << "请输入编码: " << endl;//当p1的num等于0时，则说明该链表结束；
	cin >> head->data;
	cout << "请输入编码: " << endl;
	cin >> p1->data;
	p1->next = head->next;
	p1->prior = head;
	head->next = p1;
	Node* p2 = p1;
	while (p1->data != 0)//当p1的num等于0时，则说明该链表结束； 
	{
		p1 = new Node;
		cout << "请输入编码: " << endl;//当p1的num等于0时，则说明该链表结束；
		cin >> p1->data;
		if (p1->data == 0) { break; }
		p1->next = p2->next;
		p1->prior =p2;
		p2->next = p1;
		p2 = p1;
	}
	return head;
}

int main() {
	QGList s1;

	int choice = 0;
	while (true)
	{
		int e1, e2, e3, e4, e5;
		QGList::Node* pat;
		unsigned int index;
		int a11; int b11;

		s1.show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://
			s1.exitSystem();
			break;
		case 1://
			pat = s1.QGList::creat();
			print1(pat);
			break;
		case 2://返回链表中第一个元素的引用
			a11 = s1.QGList::front();
			cout << "链表中第一个元素的数据是：" << a11 << endl;
			break;
		case 3://返回链表中最后一个元素的引用
			b11 = s1.QGList::back();
			cout << "链表中最后一个元素的数值是：" << b11 << endl;
			break;
		case 4://在链表第一个元素前添加元素e
			cout << "输入您想添加元素e的值\n" << endl;
			cin >> e1;
			pat = s1.push_front(e1);
			print1(pat);
			break;
		case 5://删除链表第一个元素
			pat = s1.QGList::pop_front();
			print1(pat);
			break;
		case 6://在链表最后一个元素后添加元素e
			cout << "输入您想添加元素e的值\n" << endl;
			cin >> e2;
			pat = s1.QGList::push_back(e2);
			print1(pat);
			break;
		case 7://删除链表最后一个元素
			pat = s1.QGList::pop_back();
			print1(pat);
			break;
		case 8://在链表的第index + 1个元素前插入元素e
			cin >> index;
			s1.QGList::insert(index, e3);
			break;
		case 9://删除任意位置元素
			cin >> index;
			s1.QGList::erase(index);
			break;
		case 10:// 清空链表
			s1.QGList::clear();
			break;
		case 11://查找元素是否存在
			s1.contain(e4);
			break;
		case 12://返回链表中元素的数量
			s1.size();
			break;
		case 13://遍历链表, 对每个元素调用visit指向的函数
			s1.QGList::traverse(visit1);
			break;
		default:
			system("cls");
			break;


		}
	}
		return 0;
}