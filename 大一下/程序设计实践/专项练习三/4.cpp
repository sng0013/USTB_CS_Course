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
    int m_top = -1; // 使用m_top作为栈顶指针  
};

bool MyStack::push(int m)
{
    if (m_top < 9) // 栈未满时压入元素  
    {
        m_array[++m_top] = m; // 先增加m_top再赋值  
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
    if (m_top != -1) // 栈非空时弹出元素  
    {
        m_top--; // 弹出栈顶元素，m_top减1  
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
    for (int i = 0; i <= m_top; i++) // 从栈底到栈顶打印元素  
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
            break; // 增加退出选项'q'  
        }
    }
    return 0;
}
