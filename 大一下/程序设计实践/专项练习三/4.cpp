#include<iostream>  

using namespace std;

class MyStack
{
public:
    bool push(int);
    bool pop();
    void print();
    ~MyStack() {};
private:
    int m_array[10];
    int m_top = -1; // ʹ��m_top��Ϊջ��ָ��  
};

bool MyStack::push(int m)
{
    if (m_top < 9) // ջδ��ʱѹ��Ԫ��  
    {
        m_array[++m_top] = m; // ������m_top�ٸ�ֵ  
        return true;
    }
    else
    {
        //cout << "Stack is full, cannot push element." << endl;
        return false;
    }
}

bool MyStack::pop()
{
    if (m_top != -1) // ջ�ǿ�ʱ����Ԫ��  
    {
        m_top--; // ����ջ��Ԫ�أ�m_top��1  
        return true;
    }
    else
    {
        //cout << "Stack is empty, cannot pop element." << endl;
        return false;
    }
}

void MyStack::print()
{
    cout << '('<<' ';
    for (int i = 0; i <= m_top; i++) // ��ջ�׵�ջ����ӡԪ��  
    {
        cout << m_array[i] << ' ';
    }
    cout << ')' << endl;
}

int main()
{
    char ch;
    int i;
    MyStack stack;
    while (cin >> ch)
    {
        if (ch == 'i')
        {
            cin >> i;
            if (stack.push(i))
            {
                //cout << "Element pushed successfully." << endl;
            }
            continue;
        }
        if (ch == 'o')
        {
            if (stack.pop())
            {
                //cout << "Element popped successfully." << endl;
            }
            else { cout << "Can not pop empty stack" << endl; }
            continue;
        }
        if (ch == 's')
        {
            stack.print();
            break;
        }
        if (ch == 'q')
        {
            break; // �����˳�ѡ��'q'  
        }
    }
    return 0;
}
