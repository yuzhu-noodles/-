#include<iostream>
using namespace std;
#include<algorithm>


//˼·��
//�ж��ַ����Ƿ�Ϊ��
//Ϊ�շ��ؿ��ַ���""
//��Ϊ��    ���磺abcdef  2
//����תǰn���ַ���  ba cdef
//����תn������ַ��� ba fedc
//�����תȫ��     cdefab
string LeftRotateString(string str, int n)
{
	if (str.empty())
		return "";
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}
int main()
{
	string s = "\0";
	string s2 = LeftRotateString(s, 2);
	cout << s2 << endl;
	system("pause");
	return 0;
}