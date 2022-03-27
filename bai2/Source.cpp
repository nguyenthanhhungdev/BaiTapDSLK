#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

struct list
{
	node* head, * tail;
};

void khoiTaoList(list& l)
{
	l.head = l.tail = NULL;
}

node* getNode(int x)
{
	node* p;
	p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho: " << endl;
		exit(1);
	}
	p->data = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void chenPhanTuVaoCuoi(list& l, node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else {
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}


void danhSachChenCuoi(list& l)
{
	int x, n;
	cout << "Danh sach gom bao nhieu phan tu: ";
	cin >> n;
	khoiTaoList(l);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		chenPhanTuVaoCuoi(l, getNode(x));
	}
}

void inDanhSach(list l)
{
	for (node* p = l.head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
}

void chenDau(list& l, node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void giaiPhong(list& l)
{
	node* p = new node;
	while (l.head != NULL)
	{
		p = l.head;
		l.head = p->next;
		delete p;
	}
}

/*
-Cho nút đầu của a là nút đầu của b
-Cho p là nut đầu của a
-Cho p trỏ tới nút tiếp theo
-Cho q là nút cuối của b
-Nếu q->prev là NULL thì nếu p khác q ta thêm p vào b
						+ nếu q = p thì ta đi tới p->next
-Cứ thế đi hết b nếu k có phần tử nào trung với p thì ta thêm vào b
*/

void createNewList(list a, list& b)
{
	khoiTaoList(b);
	node* p = a.head;
	chenPhanTuVaoCuoi(b, getNode(p->data));
	p = p->next;
	
	while (p != NULL)
	{
		bool timkiem = false;
		node* q = b.tail;
		while (p->data != q->data)
		{
			q = q->prev;
			if (q == NULL)
			{
				timkiem = true;
				break;
			}
		}
		if(timkiem)
			chenPhanTuVaoCuoi(b, getNode(p->data));
		p = p->next;
	}
}

int main()
{
	//1 5 3 7 5 9 7
	list a, b;
	danhSachChenCuoi(a);
	createNewList(a, b);
	inDanhSach(b);
	return 0;
}