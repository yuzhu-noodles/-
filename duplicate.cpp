#include<iostream>
using namespace std;
#include<vector>

int duplicate(vector<int>& numbers)
{
	if (numbers.empty()||numbers.size()==1)
		return -1;
	int count[255] = { 0 };
	for (int i = 0; i < numbers.size(); i++)
	{
		count[numbers[i]]++;
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		if (count[numbers[i]] > 1)
		{
			return numbers[i];
			break;
		}
	}
	return -1;
}

int main()
{
	vector<int> v;
	int arr[] = { 0,2,3,1,0,2,5,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++)
	{
		v.push_back(arr[i]);
	}
	cout << "���飺";
	for (int i = 0; i < len; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout <<"�����е�һ���ظ������֣�"<< duplicate(v) << endl;
	system("pause");
	return 0;
}