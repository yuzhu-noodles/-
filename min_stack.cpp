#include<iostream>
using namespace std;
#include<stack>


//��������ջs2
//���s2��ջ��Ԫ��>value,��s2��valueѹջ,����֮ǰ����Сֵ�ͻ��Ϊ��Сֵ
class Solution {
public:
    void push(int value) 
    {
        s1.push(value);
        if (s2.empty() || s2.top() > value)
        {
            s2.push(value);
        }
    }
    void pop()
    {
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top() 
    {
        return s1.top();
    }
    int min() 
    {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    Solution S;
    S.push(5);
    S.push(3);
    S.push(4);
    cout << "��СԪ�أ�" << S.min() << endl;
    cout << "ջ��Ԫ��:" << S.top() << endl;
	system("pause");
	return 0;
}