#include<iostream>
using namespace std;

void ReplaceBlack(char* arr, char* key, int len)
{
	if (NULL == arr || NULL == key)
		return;
	char* tmp = arr;
	while (*tmp != '\0')
	{
		char* prev = key;
		if (*tmp == ' ')
		{
			//�ַ�������ƶ�key-1���ַ���λ
			int tlen = strlen(tmp);
			while (tlen)
			{
				tmp[tlen + 2] = tmp[tlen];
				tlen--;
			}
			while (*prev != '\0')
			{
				*tmp = *prev;
				tmp++, prev++;
			}
		}
		tmp++;
	}
}
int main()
{
	char arr[100] = " My github name is yuzhu noodles! ";
	printf("ԭ�ַ���: %s\n", arr);
	char key[] = "%20";
	ReplaceBlack(arr, key, strlen(arr) - 1);
	printf("�滻����ַ���: %s\n", arr);
	system("pause");
	return 0;
}