#include"qglist.h"

void QGList::show_Menu()
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
	cout << "*****************8.������ĵ�index + 1��Ԫ��ǰ����Ԫ��e*********************" << endl;
	cout << "*****************9.ɾ������λ��Ԫ��*****************************************" << endl;
	cout << "*****************10.�������************************************************" << endl;
	cout << "*****************11.����Ԫ���Ƿ����****************************************" << endl;
	cout << "*****************12.����������Ԫ�ص�����************************************" << endl;
	cout << "*****************13.��������, ��ÿ��Ԫ�ص���visitָ��ĺ���*****************" << endl;
	cout << "****************************************************************************" << endl;
}

void QGList::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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
	QGList::Node*p = head->next; /* pָ���һ����� */
	while (p != head) /* pû����ͷ */
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(head);
	head = NULL;
}

/*
 * ���������е�һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::front()
{
	QGList::Node* p;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
		goto END;
	}

	p = head;

	static int& a1 = p->data;

END:
	return a1;
}

/*
 * �������������һ��Ԫ�ص�����
 */
QGList::ElemType& QGList::back() {
	QGList::Node* p;

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
QGList::Node* QGList::push_front(QGList::ElemType& e1)
{
	QGList::Node* p;
	QGList::Node* p1;
	QGList::Node* p2;
	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ɾ�������һ��Ԫ��
 */
QGList::Node* QGList::pop_front() {
	QGList::Node* p;
	QGList::Node* p1;
	QGList::Node* p2;

	if (NULL == head)//���ͷ���ָ��NULL,�����һ��������
	{
		cout << "�����һ��������" << endl;
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
 * ���������һ��Ԫ�غ����Ԫ��e
 */
QGList::Node* QGList::push_back(QGList::ElemType& e2) {
	QGList::Node* p;
	QGList::Node* p1;
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

	p1->prior = p;

END:
	return head;
}

/*
 * ɾ���������һ��Ԫ��
 */
QGList::Node* QGList::pop_back() {
	QGList::Node* p;

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

QGList::Node* QGList::GetElemP(unsigned int index) /* ��� */
{ /* ��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�*/
/* ����NULL */
	int j;
	QGList::Node* p = head; /* pָ��ͷ��� */
	if (index<0 || index>size()) { /* iֵ���Ϸ� */
		return NULL;
	}
	for (j = 1; j <= index; j++) {
		p = p->next;
	}
	return p;
}


/*
 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
 */
QGList::Node* QGList::insert(unsigned int index, QGList::ElemType& e) {
	QGList::Node* p;
	QGList::Node* s;
	if (index<1 || index>size() + 1) /* indexֵ���Ϸ� */
	{
		cout << "indexֵ���Ϸ�" << endl;
		return 0;
	}
	p = GetElemP(index - 1); /* ��L��ȷ����i��Ԫ��ǰ����λ��ָ��p */
	if (!p) /* p=NULL,����i��Ԫ�ص�ǰ��������(��ͷ���Ϊ��1��Ԫ�ص�ǰ��) */
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
	s->prior = p; /* �ڵ�i-1��Ԫ��֮����� */
	s->next = p->next;
	p->next->prior = s;
	p->next = s;

	cout << "����ɹ�" << endl;
	return head;
}

/*
 * ɾ������λ��Ԫ��
 */
bool QGList::erase(unsigned int index) {
	QGList::Node* p;
	if (index < 1) /* indexֵ���Ϸ� */
	{
		cout << "ERROR" << endl;
		return 0;

	}
	p = GetElemP(index); /* ��L��ȷ����i��Ԫ�ص�λ��ָ��p */
	if (!p) /* p=NULL,����i��Ԫ�ز����� */
	{
		cout << "ERROR" << endl;
		return 0;

	}
	//*e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	cout << "����ɹ�" << endl;
	return 1;
}

/*
 * �������,��������Ϊ�ձ�
 */
bool QGList::clear() {
	QGList::Node* q;
	QGList::Node* p = head->next; /* pָ���һ����� */
	if (head->next == head && head->prior == head) {
		return 1;
	}

	while (p != head) /* pû����ͷ */
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = head->prior = head; /*ͷ��������ָ�����ָ������ */
	return 1;
}

/*
 * ����Ԫ���Ƿ����
 */
bool QGList::contain(QGList::ElemType& e) {
	int i = 0;
	QGList::Node* p = head->next; /* pָ���1��Ԫ�� */
	while (p != head)
	{
		i++;
		if (p->data == e) {/* �ҵ�����������Ԫ��*/
			return i;
		}
		p = p->next;
	}
	return 0;
}

/*
 * ����������Ԫ�ص�����
 */
unsigned int QGList::size() {
	int i = 0;
	QGList::Node* p = head->next; /* pָ���һ����� */
	while (p != head) /* pû����ͷ */
	{
		i++;
		p = p->next;
	}
	return i;
}

/*
 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
 */
bool QGList::traverse(void (*visit)(QGList::ElemType& e)) {
	QGList::Node* p = head;
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

void visit1(QGList::ElemType& e)
{
	cout << "����visit�����ɹ�" << endl;
}

//��ӡ����
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

QGList::Node* QGList::creat()     //��������
{
	QGList::Node* p1;

	p1 = new Node;

	cout << "���������: " << endl;//��p1��num����0ʱ����˵�������������
	cin >> head->data;
	cout << "���������: " << endl;
	cin >> p1->data;
	p1->next = head->next;
	p1->prior = head;
	head->next = p1;
	Node* p2 = p1;
	while (p1->data != 0)//��p1��num����0ʱ����˵������������� 
	{
		p1 = new Node;
		cout << "���������: " << endl;//��p1��num����0ʱ����˵�������������
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
		cout << "����������ѡ��" << endl;
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
		case 2://���������е�һ��Ԫ�ص�����
			a11 = s1.QGList::front();
			cout << "�����е�һ��Ԫ�ص������ǣ�" << a11 << endl;
			break;
		case 3://�������������һ��Ԫ�ص�����
			b11 = s1.QGList::back();
			cout << "���������һ��Ԫ�ص���ֵ�ǣ�" << b11 << endl;
			break;
		case 4://�������һ��Ԫ��ǰ���Ԫ��e
			cout << "�����������Ԫ��e��ֵ\n" << endl;
			cin >> e1;
			pat = s1.push_front(e1);
			print1(pat);
			break;
		case 5://ɾ�������һ��Ԫ��
			pat = s1.QGList::pop_front();
			print1(pat);
			break;
		case 6://���������һ��Ԫ�غ����Ԫ��e
			cout << "�����������Ԫ��e��ֵ\n" << endl;
			cin >> e2;
			pat = s1.QGList::push_back(e2);
			print1(pat);
			break;
		case 7://ɾ���������һ��Ԫ��
			pat = s1.QGList::pop_back();
			print1(pat);
			break;
		case 8://������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
			cin >> index;
			s1.QGList::insert(index, e3);
			break;
		case 9://ɾ������λ��Ԫ��
			cin >> index;
			s1.QGList::erase(index);
			break;
		case 10:// �������
			s1.QGList::clear();
			break;
		case 11://����Ԫ���Ƿ����
			s1.contain(e4);
			break;
		case 12://����������Ԫ�ص�����
			s1.size();
			break;
		case 13://��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
			s1.QGList::traverse(visit1);
			break;
		default:
			system("cls");
			break;


		}
	}
		return 0;
}