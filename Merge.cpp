#include<iostream>
using namespace std;

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;

//��������
ListNode* Creat()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp = head;
	int num = 0;
	do
	{
		cin >> num;
		ListNode*node = (ListNode*)malloc(sizeof(ListNode));
		node->data = num;
		node->next = NULL;
		temp->next = node;
		temp = temp->next;
	} while(cin.get() != '\n');
	return head;
}

void Print(ListNode* head)
{
	ListNode* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}

//�ϲ�
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* Merge = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp = Merge;
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->data <= pHead2->data)
		{
			temp->next = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			temp->next = pHead2;
			pHead2 = pHead2->next;
		}
		temp = temp->next;
	}
	temp->next = pHead1 ? pHead1 : pHead2;
	return Merge->next->next;
}


//�ݹ�
ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	ListNode* Merge = NULL;
	if (pHead1->data < pHead2->data)
	{//ѡȡ��ֵС���׽ڵ�Ϊ�ϲ�����׽ڵ�
		Merge = pHead1;
		Merge->next = Merge2(pHead1->next, pHead2);	//�����²��ֽ��е���
	}
	else
	{
		Merge = pHead2;
		Merge->next = Merge2(pHead1, pHead2->next);
	}
	return Merge;
}
int main()
{
	cout << "�������һ������";
	ListNode* phead1 = Creat();
	cout << "������ڶ�������";
	ListNode* phead2 = Creat();
	cout << "�ϲ��������"<<endl;
	ListNode* M = Merge2(phead1, phead2);
	Print(M);
	system("pause");
	return 0;
}