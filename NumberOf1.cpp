#include<iostream>
using namespace std;

int  NumberOf1(unsigned int num) 
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int num = 0;
	cin >> num;
	int ret = NumberOf1(num);
	cout << "����32λ�����Ʊ�ʾ��1�ĸ���:" << ret << endl;

	system("pause");
	return 0;
}