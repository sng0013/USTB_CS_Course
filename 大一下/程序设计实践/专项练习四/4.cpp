#include <iostream>
#include <string>

const int SEAT_NUM = 10;

class Seat {
private:
    static int count;
protected:
    void acquire(std::string name = "seat") {
        if (count < SEAT_NUM)
        {
            ++count;
            std::cout << name << "boy: allocated "
                << count << "/" << SEAT_NUM << std::endl;
        }
        else
        {
            std::cout << "out of memory" << std::endl;
        }
    }

    void release()
    {
        if (count > 0)
        {
            std::cout << "release: " << count
                << "/" << SEAT_NUM << std::endl;
            --count;
        }
    }

public:
    virtual ~Seat() {}
};

int Seat::count = 0;


class Boy : public Seat {
private:
    bool flag;
    std::string name;
public:
    Boy() :flag(false) {
    }

    virtual ~Boy() {
    }

    void g() {
        flag = true;
        Seat::acquire(name);
    }

    void f() {
        flag = true;
        Seat::release();
    }
};

Boy* b[26];
int op[100], op2[100];

int main(int argc, char* argv[])
{
    int round_;//输入回合
    int n;//输入每回合的操作数
    std::cin >> round_ >> n;

    for (int i = 0; i < n; ++i)
    {
        char c;
        std::cin >> op[i] >> c;//输入数字op和字符c，op=0有座，op=1无座，字符c是座位名称
        op2[i] = c - 'a';//将座位字符号化为座位数字序号
    }

    for (int i = 0; i < 26; ++i)
    {
        b[i] = NULL;
    }

    //进行回合输出
    for (int r = 0; r < round_; ++r)
    {
        std::cout << "#round: " << r << std::endl;
        for (int i = 0; i < n; ++i)
        {
            int d = op2[i];
            bool _t = 0;
            //改动的代码，让程序执行release函数
            for (int t = 0; t <=i; t++)
            {
                if ((b[t]!=NULL)&&(t == op2[i])) { _t = 1; break; }
            }
            if (_t) {
                delete b[d];//释放座位
                b[d] = NULL;
                if (op[i] == 0)
                {

                    b[d] = new Boy();
                    b[d]->f();
                    b[d]->g();
                }
            }
            else {
                if (op[i] == 0)
                {

                    b[d] = new Boy();
                    b[d]->g();
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        delete b[i];
    }
    return 0;
}


