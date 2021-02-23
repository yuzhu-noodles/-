//�����е�����K���ڵ�
//1��ѭ�����Σ���һ�μ��������ĳ��ȣ��ټ���������ĵ�K�����length-k+1��
struct ListNode* FindKthToTail(struct ListNode* head, int k)
{
    int count = 1;
    struct ListNode* node = head;
    while (node->next != NULL)
    {
        node = node->next;
        count++;
    }
    struct ListNode* find = head;
    for (int i = 1; i < count - k + 1; i++)
    {
        find = find->next;
    }
    return find;
}

//2��ѭ��һ�Σ�˫ָ�룬����ǰ������ָ�룬���Ϊk-1,��ǰָ��ָ������β���ʱ����ָ��պ�ָ������k�����
struct ListNode* FindKthToTail(struct ListNode* head, int k)
{
    if (head == NULL || k == 0)
        return NULL;
    struct ListNode* p1 = head;
    struct ListNode* p2 = NULL;
    for (int i = 0; i < k - 1; i++)
    {
        if (p1->next != NULL)
            p1 = p1->next;
        else
            return NULL;
    }
    p2 = head;
    while (p1->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}