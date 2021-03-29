#include"qgforwardlist.h"
using namespace std;

void QGForwardList::show_Menu()
{
	cout << "****************************************************************************" << endl;
	cout << "*****************0.�˳�ϵͳ*************************************************" << endl;
	cout << "*****************1.�����б�*************************************************" << endl;
	cout << "*****************2.���������е�һ��Ԫ�ص�����*******************************" << endl;
	cout << "*****************3.�������������һ��Ԫ�ص�����*****************************" << endl;
	cout << "*****************4.�������һ��Ԫ��ǰ���Ԫ��e******************************" << endl;
	cout << "*****************5.ɾ�������һ��Ԫ��***************************************" << endl;
	cout << "*****************6.���������һ��Ԫ�غ����Ԫ��e****************************" << endl;
	cout << "*****************7.ɾ���������һ��Ԫ��*************************************" << endl;
	cout << "*****************8.������ĵ�index + 1��Ԫ��ǰ����Ԫ��e*********************"<< endl;
	cout << "*****************9.ɾ������λ��Ԫ��*****************************************" << endl;
	cout << "*****************10.�������************************************************" << endl;
	cout << "*****************11.����Ԫ���Ƿ����****************************************" << endl;
	cout << "*****************12.����������Ԫ�ص�����************************************" << endl;
	cout << "*****************13.��������, ��ÿ��Ԫ�ص���visitָ��ĺ���*****************" << endl;
	cout << "*****************14.��ת����1234��ת����4321****************************" << endl;
	cout << "*****************15.�����л�************************************************" << endl;
	cout << "*****************16.ż�ڵ㷴ת��1234��ת����2143**************************" << endl;
	cout << "*****************17.�����м�ڵ�********************************************" << endl;
	cout << "****************************************************************************" << endl;
	cout << endl;
}

void QGForwardList::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

QGForwardList::QGForwardList() {
	
}

QGForwardList::~QGForwardList() {
	if (head == NULL)  //�ж��Ƿ�Ϊ������
	{
		cout << "This is an empty LinkList" << endl;
		return;
	}
	Node* pTemNode = NULL;
	while (head->next)  //��������£�������ֻ��ͷ�ڵ�������
	{  //��ֻ����ͷ�ڵ�ʱ�����*pHeadָ������һ��Ԫ�أ�
		pTemNode = head->next;
		delete head;
		head = pTemNode;
	}
	if (head != NULL)  //��ֻ��һ��ͷ�ڵ�������һ���ڵ�����
	{
		delete head;
		head = NULL;
	}
	cout << "Now LinkList has been cleared!" << endl;
}

/*
 * ���������е�һ��Ԫ�ص�����
 */
QGForwardList::ElemType& QGForwardList::front() {
	QGForwardList::Node* p;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
		goto END;
	}

	p = head;

	static int &a1 = p->data;

END:
	return a1;
}

/*
 * �������������һ��Ԫ�ص�����
 */
QGForwardList::ElemType& QGForwardList::back() {

	QGForwardList::Node* p;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * �������һ��Ԫ��ǰ���Ԫ��e
 */
QGForwardList::Node* QGForwardList::push_front(ElemType& e1) {
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
	QGForwardList::Node* p2;
	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout<<"�����һ��������"<<endl;
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
 * ɾ�������һ��Ԫ��
 */
QGForwardList::Node* QGForwardList::pop_front()
{
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
	QGForwardList::Node* p2;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ���������һ��Ԫ�غ����Ԫ��e
 */
QGForwardList::Node* QGForwardList::push_back(ElemType& e2) {
	QGForwardList::Node* p;
	QGForwardList::Node* p1;
	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ɾ���������һ��Ԫ��
 */
QGForwardList::Node* QGForwardList::pop_back() {
	QGForwardList::Node* p;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
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
		while ((p0->data > p1->data) && (p1->next != NULL))	//��������˳�while�� 
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->data <= p1->data)
		{
			if (head == p1)		//p1��ͷ��㣬����ͷ�� 
			{
				head = p0;
			}
			else				//p1����ͨ����������м� 
			{
				p2->next = p0;
			}
			p0->next = p1;
		}
		else	//p0��number��󣬲��뵽β�� 
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;	//���ڲ����ˣ�����������һλ���ݳ�Ա�����б��� 

	return head;
}

/*
 * ɾ������λ��Ԫ��
 */
QGForwardList::Node* QGForwardList::erase(unsigned int index) {
	QGForwardList::Node* p1, * p2;
	p2 = NULL;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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

		cout << "ɾ����Ԫ�ص�data��" << index << "  �ɹ���" << endl;
		n = n - 1;
	}
	else
	{
		cout << "Ԫ�صģ�" << index << "  ��û�б��ҵ���" << endl;
	}

END:
	return head;

}

/*
 * �������
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
	if (head->next == nullptr)  //����������٣���һ���ж��Ƿ�ֻ��ͷ�ڵ��������
	{  //��������£�ֱ�ӷ��أ���������
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
 * ����Ԫ���Ƿ����
 */
QGForwardList::Node* QGForwardList::contain(ElemType& e4) {
	QGForwardList::Node* p1, * p2;
	p1 = NULL;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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

		cout << "Ԫ��Ϊ��" << e4 << "  ���ҳɹ���" << endl;
		n = n - 1;
	}
	else
	{
		cout << "Ԫ��Ϊ��" << e4 << "  ��û�б��ҵ���" << endl;
	}

END:
	return p1;

}

/*
 * ����������Ԫ�ص�����
 */
unsigned int QGForwardList::size() {
	QGForwardList::Node* p;
	int i=0;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool QGForwardList::traverse(void (*visit)(QGForwardList::ElemType& e)) {
	QGForwardList::Node* p = head;
	int e;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
	cout << "����visit�����ɹ�" << endl;
}

/*
 * ��ת����1234��ת����4321
 */
QGForwardList::Node* QGForwardList::reverse(){
	if (head->next == NULL || head->next->next == NULL)
	{
		return head;   /*����Ϊ�ջ�ֻ��һ��Ԫ����ֱ�ӷ���*/
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

	/*��ʱqָ��ԭʼ�������һ��Ԫ�أ�Ҳ����ת�������ı�ͷԪ��*/
	head->next->next = NULL;  /*��������β*/
	head->next = p;           /*��������ͷ*/
	return head;


}

/*
 * �����л�
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
 * ż�ڵ㷴ת��1234��ת����2143
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
	QGForwardList::Node* prve = NULL;//���淴ת�ڵ��ǰ��һ���ڵ�.
	QGForwardList::Node* last = NULL;//���淴ת�ڵ�κ���һ���ڵ�.
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
 * �����м�ڵ�
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

//��ӡ����
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


QGForwardList::Node* QGForwardList::creat()     //��������
{
	QGForwardList::Node* p1, * p2;

	p1 = new Node;
	p2 = new Node;

	cout << "���������: " << endl;//��p1��num����0ʱ����˵�������������
	cin >> p1->data;

	head = NULL;
	n = 0;

	while (p1->data != 0)//��p1��num����0ʱ����˵������������� 
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

		
		cout << "���������: " << endl;//��p1��num����0ʱ����˵�������������
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
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			s1.exitSystem();
			break;
		case 1://�����б�
			pat = s1.QGForwardList::creat();
			print1(pat);
			break;
		case 2://���������е�һ��Ԫ�ص�����
			a11 = s1.QGForwardList::front();
			cout << "�����е�һ��Ԫ�ص������ǣ�" << a11 << endl;
			break;
		case 3://�������������һ��Ԫ�ص�����
			b11 = s1.QGForwardList::back();
			cout << "���������һ��Ԫ�ص���ֵ�ǣ�" << b11 << endl;
			break;
		case 4://�������һ��Ԫ��ǰ���Ԫ��e
			cout << "�����������Ԫ��e��ֵ\n" << endl;
			cin >> e1;
			pat = s1.push_front(e1);
			print1(pat);
			break;
		case 5://ɾ�������һ��Ԫ��
			pat = s1.QGForwardList::pop_front();
			print1(pat);
			break;
		case 6://���������һ��Ԫ�غ����Ԫ��e
			cout << "�����������Ԫ��e��ֵ\n" << endl;
			cin >> e2;
			pat = s1.QGForwardList::push_back(e2);
			print1(pat);
			break;
		case 7://ɾ���������һ��Ԫ��
			pat = s1.QGForwardList::pop_back();
			print1(pat);
			break;
		case 8://������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
			cin >> index;
			s1.QGForwardList::insert(index,e3);
			break;
		case 9://ɾ������λ��Ԫ��
			cin >> index;
			s1.QGForwardList::erase(index);
			break;
		case 10:// �������
			s1.QGForwardList::clear();
			break;
		case 11://����Ԫ���Ƿ����
			s1.contain(e4);
			break;
		case 12://����������Ԫ�ص�����
			s1.size();
			break;
		case 13://��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
			s1.QGForwardList::traverse(visit1);
			break;
		case 14://��ת����1234��ת����4321
			s1.QGForwardList::reverse();
			break;
		case 15://�����л�
			s1.QGForwardList::isLoop();
			break;
		case 16://ż�ڵ㷴ת��1234��ת����2143
			s1.QGForwardList::reverseEven();
			break;
		case 17://�����м�ڵ�
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

