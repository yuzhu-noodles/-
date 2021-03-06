#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

//��������
ListNode* Creat()
{
    ListNode* temp;  //ͷָ��
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = 1;
    node->next = NULL;
    temp = node;
    //��������
    for (int i = 2; i <= 5; i++)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        p->val = i;
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
    return node;
}
void Print(ListNode* header)
{
    ListNode* a = header;
    while (a != NULL)
    {
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}

//��ת����
ListNode* ReverseList(ListNode* pHead)
{
    if (pHead == NULL || pHead->next == NULL)
    {
        return pHead;
    }
    ListNode* node = pHead;  //��ǰ���
    ListNode* pre = NULL;   //ǰ���
    ListNode* next = NULL;  //����
    ListNode* NewHead = NULL; //��ͷ���

    //��ת
    while (node != NULL)
    {
        next = node->next;
        if (next == NULL)
        {
            NewHead = node;
        }
        node->next = pre;
        pre = node;
        node = next;
    }
    return NewHead;
}
int main()
{
    ListNode* p = Creat();
    cout << "ԭ����:";
    Print(p);
    cout << endl;
    ListNode* new_p = ReverseList(p);
    cout << "��ת�������";
    Print(new_p);
    cout << endl;
	system("pause");
	return 0;
}