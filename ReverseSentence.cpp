#include<iostream>
#include<algorithm>
using namespace std;

//�Կո�Ϊ�ֽ�㣬���ȷ�ת�ַ�����ÿ�����ʣ�
//Ȼ�����巭ת

string ReverseSentence(string str) 
{
	int n = 0;
	for (int i = 0; i < str.length(); i++)
	{
		while (i<str.length()&&str[i] != ' ')
		{
			i++;
		}
		reverse(str.begin() + n, str.begin() + i);
		n = i + 1;
	}
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	string s = "student. a am i";//
	string ss = ReverseSentence(s);
	cout << ss << endl;
	system("pause");
	return 0;
}