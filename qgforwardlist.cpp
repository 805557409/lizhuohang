#include"qgforwardlist.h"
using namespace std;

void QGForwardList::show_Menu()
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
	cout << "*****************8.在链表的第index + 1个元素前插入元素e*********************"<< endl;
	cout << "*****************9.删除任意位置元素*****************************************" << endl;
	cout << "*****************10.清空链表************************************************" << endl;
	cout << "*****************11.查找元素是否存在****************************************" << endl;
	cout << "*****************12.返回链表中元素的数量************************************" << endl;
	cout << "*****************13.遍历链表, 对每个元素调用visit指向的函数*****************" << endl;
	cout << "*****************14.反转链表，1234反转后变成4321****************************" << endl;
	cout << "*****************15.链表判环************************************************" << endl;
	cout << "*****************16.偶节点反转，1234反转后变成2143**************************" << endl;
	cout << "*****************17.返回中间节点********************************************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void QGForwardList::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

QGForwardList::QGForwardList() {
	
}

QGForwardList::~QGForwardList() {
	if (head == NULL)  //判断是否为空链表
	{
		cout << "This is an empty LinkList" << endl;
		return;
	}
	Node* pTemNode = NULL;
	while (head->next)  //这种情况下，包含了只有头节点的情况；
	{  //不只含有头节点时，最后*pHead指到最后的一个元素；
		pTemNode = head->next;
		delete head;
		head = pTemNode;
	}
	if (head != NULL)  //将只有一个头节点或者最后一个节点销毁
	{
		delete head;
		head = NULL;
	}
	cout << "Now LinkList has been cleared!" << endl;
}

/*
 * 返回链表中第一个元素的引用
 */
QGForwardList::ElemType& QGForwardList::front() {
	QGForwardList::Node* p;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	static int &a1 = p->data;

END:
	return a1;
}

/*
 * 返回链表中最后一个元素的引用
 */
QGForwardList::ElemType& QGForwardList::back() {

	QGForwardList::Node* p;

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
QGForwardList::Node* QGForwardList::push_front(ElemType& e1) {
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
	QGForwardList::Node* p2;
	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout<<"这个是一个空链表。"<<endl;
		goto END;
	}
	
	p = head;

	p1 = p->next;

	p2 = new Node;

	p2->data = e1;

	p1 = p2->next;

	p->next = p2;

END:
	return head;
}

/*
 * 删除链表第一个元素
 */
QGForwardList::Node* QGForwardList::pop_front()
{
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
	QGForwardList::Node* p2;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p = head;

	p1 = p->next;

	p2 = p->next;

	p1 = p1->next;

	head = p2;
	free(p);

END:
	return head;
}

/*
 * 在链表最后一个元素后添加元素e
 */
QGForwardList::Node* QGForwardList::push_back(ElemType& e2) {
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
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

END:
	return head;

}

/*
 * 删除链表最后一个元素
 */
QGForwardList::Node* QGForwardList::pop_back() {
	QGForwardList::Node* p;

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

/*
 * 在链表的第index + 1个元素前插入元素e
 */
QGForwardList::Node* QGForwardList::insert(unsigned int index, ElemType& e3) {

	QGForwardList::Node* p0, * p1, * p2;

	p1 = head;
	p0 = new Node;
	p0->data = e3;
	p2 = NULL;

	if (NULL == head)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->data > p1->data) && (p1->next != NULL))	//两种情况退出while； 
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->data <= p1->data)
		{
			if (head == p1)		//p1是头结点，插入头部 
			{
				head = p0;
			}
			else				//p1是普通情况，插入中间 
			{
				p2->next = p0;
			}
			p0->next = p1;
		}
		else	//p0的number最大，插入到尾部 
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;	//由于插入了，所以增加了一位数据成员进入列表中 

	return head;
}

/*
 * 删除任意位置元素
 */
QGForwardList::Node* QGForwardList::erase(unsigned int index) {
	QGForwardList::Node* p1, * p2;
	p2 = NULL;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p1 = head;
	while (p1->data != index && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (index == p1->data)
	{
		if (p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}

		cout << "删除的元素的data：" << index << "  成功！" << endl;
		n = n - 1;
	}
	else
	{
		cout << "元素的：" << index << "  并没有被找到！" << endl;
	}

END:
	return head;

}

/*
 * 清空链表
 */
bool QGForwardList::clear() {
	/*QGForwardList::Node* p;

	p = head;

	p->next = NULL;

	return 1;*/
	if (head == nullptr)
	{
		cout << "This is an empty LinkList!" << endl;
		return 1;
	}
	if (head->next == nullptr)  //相比链表销毁，多一步判断是否只有头节点这种情况
	{  //这种情况下，直接返回，不做处理
		cout << "The LinkList is originally empty!" << endl;
		return 1;
	}
	while (head->next)
	{
		Node* pTemNode = (head)->next;
		delete head;
		head = pTemNode;
	}
	if (head)
	{
		delete head;
		head = nullptr;
	}
	cout << "Now The LinkList has been cleared!" << endl;
}

/*
 * 查找元素是否存在
 */
QGForwardList::Node* QGForwardList::contain(ElemType& e4) {
	QGForwardList::Node* p1, * p2;
	p1 = NULL;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		goto END;
	}

	p1 = head;
	while (p1->data != e4 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (e4 == p1->data)
	{

		cout << "元素为：" << e4 << "  查找成功！" << endl;
		n = n - 1;
	}
	else
	{
		cout << "元素为：" << e4 << "  并没有被找到！" << endl;
	}

END:
	return p1;

}

/*
 * 返回链表中元素的数量
 */
unsigned int QGForwardList::size() {
	QGForwardList::Node* p;
	int i=0;

	if (NULL == head)//如果头结点指向NULL,这个是一个空链表。
	{
		cout << "这个是一个空链表。" << endl;
		return 0;
	}

	p = head;

	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;


}

/*
 * 遍历链表, 对每个元素调用visit指向的函数
 */
bool QGForwardList::traverse(void (*visit)(QGForwardList::ElemType& e)) {
	QGForwardList::Node* p = head;
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

void visit1(QGForwardList::ElemType& e) 
{
	cout << "调用visit函数成功" << endl;
}

/*
 * 反转链表，1234反转后变成4321
 */
QGForwardList::Node* QGForwardList::reverse(){
	if (head->next == NULL || head->next->next == NULL)
	{
		return head;   /*链表为空或只有一个元素则直接返回*/
	}

	QGForwardList::Node* t = NULL;
	QGForwardList::Node* p = head->next;
	QGForwardList::Node* q = head->next->next;
	while (q != NULL)
	{
		t = q->next;
		q->next = p;
		p = q;
		q = t;
	}

	/*此时q指向原始链表最后一个元素，也是逆转后的链表的表头元素*/
	head->next->next = NULL;  /*设置链表尾*/
	head->next = p;           /*调整链表头*/
	return head;


}

/*
 * 链表判环
 */
bool QGForwardList::isLoop() {
	if (head == NULL)
		return 0;
	QGForwardList::Node* pSlow = head->next;
	QGForwardList::Node* pFast = NULL;
	if (pSlow != NULL)
		pFast = pSlow->next;
	while (pFast != NULL && pSlow != NULL) {
		if (pFast == pSlow)
			return 1;
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != NULL)
			pFast = pFast->next;
	}
	return 0;
}

/*
 * 偶节点反转，1234反转后变成2143
 */
QGForwardList::Node* QGForwardList::reverseEven() {
	QGForwardList::Node* p = head;
	int i = 1;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	while (count > 0)
	{
		Inverted(head,i, i + 1);//p
		if (count > 2)
		{
			count -= 2;
			i += 2;
			if (count <= 2)
				continue;
		}
		if (count <= 2)
		{
			i += count;
			count -= 2;
		}
	}
	return head;

}

void Inverted(QGForwardList::Node* head,int a, int b)
{
	
	int i = a - 1;
	int j = b - 1;
	int size = Size(head);
	if (size<a || b>size)return;
	QGForwardList::Node* p = head->next;
	QGForwardList::Node* q = head;
	QGForwardList::Node* prve = NULL;//保存反转节点段前面一个节点.
	QGForwardList::Node* last = NULL;//保存反转节点段后面一个节点.
	if (a == 1)
	{
		while (j)
		{
			last = p->next;
			p->next = q;
			q = p;
			p = last;
			j--;
		}
		head->next = p;
		head = q;
	}
	else
	{
		p = head;
		q = head;
		while (i)
		{
			prve = p;
			p = p->next;
			i--;
		}
		while (j)
		{
			q = q->next;
			j--;
		}
		last = q->next;
		QGForwardList::Node* save = NULL;
		QGForwardList::Node* m = p->next;
		QGForwardList::Node* n = p;
		while (p != last)
		{
			save = p->next;
			p->next = m;
			m = p;
			p = save;
		}
		prve->next = m;
		n->next = last;
	}
}

int Size(QGForwardList::Node* head)
{
	QGForwardList::Node* p = head;
	return Size1(p);
}

int Size1(QGForwardList::Node* p)
{
	if (p == NULL)return 0;
	return Size1(p->next) + 1;
}

/*
 * 返回中间节点
 */
QGForwardList::Node* QGForwardList::middleElem() {
	if (head == NULL) {
		return NULL;
	}

	QGForwardList::Node* p1 = head;
	QGForwardList::Node* p2 = head;

	if (head->next == NULL) {
		return head;
	}
	if (head->next->next == NULL) {
		return head;
	}

		while (1) {
			p1 = p1->next->next;
			p2 = p2->next;
			if (p1->next == NULL) {
				return p2;
			}
			if (p1->next->next == NULL) {
				return p2;
			}
		}

	return NULL;

}

//打印链表
void print1(QGForwardList::Node* head)
{
	QGForwardList::Node* p;

	p = head;
	if (head)
	{
		cout << endl;
		do
		{
			cout <<p->data << endl;
			p = p->next;
		} while (p);
	}
}


QGForwardList::Node* QGForwardList::creat()     //创建链表
{
	QGForwardList::Node* p1, * p2;

	p1 = new Node;
	p2 = new Node;

	cout << "请输入编码: " << endl;//当p1的num等于0时，则说明该链表结束；
	cin >> p1->data;

	head = NULL;
	n = 0;

	while (p1->data != 0)//当p1的num等于0时，则说明该链表结束； 
	{
		n++;
		if (1 == n) {
			head = p1;
		}
		else {
			p2->next = p1;
		}

		p2 = p1;

		p1 = new Node;

		
		cout << "请输入编码: " << endl;//当p1的num等于0时，则说明该链表结束；
		cin >> p1->data;
		if (p1->data == 0) { break; }
	}

	p2->next = NULL;

	return head;
}

int main()
{

	QGForwardList s1;

	int choice = 0;
	while (true)
	{
		int e1, e2, e3, e4, e5;
		QGForwardList::Node* pat;
		unsigned int index;
		int a11; int b11;

		s1.show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			s1.exitSystem();
			break;
		case 1://创建列表
			pat = s1.QGForwardList::creat();
			print1(pat);
			break;
		case 2://返回链表中第一个元素的引用
			a11 = s1.QGForwardList::front();
			cout << "链表中第一个元素的数据是：" << a11 << endl;
			break;
		case 3://返回链表中最后一个元素的引用
			b11 = s1.QGForwardList::back();
			cout << "链表中最后一个元素的数值是：" << b11 << endl;
			break;
		case 4://在链表第一个元素前添加元素e
			cout << "输入您想添加元素e的值\n" << endl;
			cin >> e1;
			pat = s1.push_front(e1);
			print1(pat);
			break;
		case 5://删除链表第一个元素
			pat = s1.QGForwardList::pop_front();
			print1(pat);
			break;
		case 6://在链表最后一个元素后添加元素e
			cout << "输入您想添加元素e的值\n" << endl;
			cin >> e2;
			pat = s1.QGForwardList::push_back(e2);
			print1(pat);
			break;
		case 7://删除链表最后一个元素
			pat = s1.QGForwardList::pop_back();
			print1(pat);
			break;
		case 8://在链表的第index + 1个元素前插入元素e
			cin >> index;
			s1.QGForwardList::insert(index,e3);
			break;
		case 9://删除任意位置元素
			cin >> index;
			s1.QGForwardList::erase(index);
			break;
		case 10:// 清空链表
			s1.QGForwardList::clear();
			break;
		case 11://查找元素是否存在
			s1.contain(e4);
			break;
		case 12://返回链表中元素的数量
			s1.size();
			break;
		case 13://遍历链表, 对每个元素调用visit指向的函数
			s1.QGForwardList::traverse(visit1);
			break;
		case 14://反转链表，1234反转后变成4321
			s1.QGForwardList::reverse();
			break;
		case 15://链表判环
			s1.QGForwardList::isLoop();
			break;
		case 16://偶节点反转，1234反转后变成2143
			s1.QGForwardList::reverseEven();
			break;
		case 17://返回中间节点
			s1.QGForwardList::middleElem();
			break;
		default:
			system("cls");
			break;


		}
	}
	system("pause");

	return 0;
}

