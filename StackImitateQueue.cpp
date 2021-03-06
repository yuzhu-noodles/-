#include<iostream>
using namespace std;
#include<stack>


//˼·��
//��ӣ�stack1�������
//���ӣ���satck2Ϊ��ʱ��stack2��ջstack1�ĳ�ջԪ�أ�Ȼ��stack2��ջ

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }
    int pop() 
    {
        if (stack2.empty()) 
        {
            while (!stack1.empty()) 
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int x = stack2.top();
        stack2.pop();
        return x;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution S;
    for (int i = 0; i < 5; i++)
    {
        S.push(i);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << S.pop() << " ";
    }
    cout << endl;
    system("pause");
    return 0;

}

