#include<iostream>
using namespace std;
#include<list>

int LastRemaining_Solution(int n, int m)  //��m  ������n
{
	if (n <= 0 || m < 0)
		return -1;
	list<int> L;
	for (int i = 0; i < n; i++)
		L.push_back(i);
	int index = 0;
	while (n > 1)
	{
		index = (index + m - 1) % n;
		list<int>::iterator it = L.begin();
		advance(it, index);
		L.erase(it);
		n--;
	}
	return L.back();
}

int main()
{
	int n;
	cout << "�����ж��ٸ����ӣ�";
	cin >> n;
	cout << "��������һ������";
	int m;
	cin >> m;
	cout << "�н��ĺ��ӣ�";
	int pos = LastRemaining_Solution(n, m);
	cout << pos;
	system("pause");
	return 0;
}