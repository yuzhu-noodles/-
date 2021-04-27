#include<iostream>
using namespace std;
#include<vector>
//��ʦ��������Ƿַ��ǹ����� N ������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�
//����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���
//ÿ���������ٷ��䵽 1 ���ǹ���
//���ָ��ߵĺ��ӱ�������������λ���ӻ�ø�����ǹ���

//̰���㷨
int Candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candynum(size, 1);
    for (int i = 1; i < size; i++) //�������������ұߴ�����ߣ����ұ��ǹ����������+1
    {
        if (ratings[i] > ratings[i - 1]) candynum[i] = candynum[i - 1] + 1;
    }
    for (int i = size - 2; i >= 0; i--)//�������
    {
        if (ratings[i] > ratings[i + 1]) //�����ߴ����ұߣ�ȡ����ǹ��������ұ��ǹ�+1 �����ֵ
        {
            candynum[i] = max(candynum[i], candynum[i + 1] + 1);
        }
    }
    int ret = 0;
    for (int i = 0; i < size; i++)
    {
        ret += candynum[i];
    }
    return ret;
}

int main()
{
    int a[3] = { 1,2,2 };
    vector<int>v(a, a + 3);
    cout << "����Ҫ׼�����ǹ�������" << Candy(v) << endl;
	return 0;
}