#include <fstream>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

class Text      //�����ı���Text����
{
public:
    int page;            //ҳ��
    int chapter;         //�½�
    string bookName;     //����
    string content;      //��������
};

///ȫ  ��  ��  ��
deque <Text> text;       //����һ��Text���˫�˶��У��洢�ı�����
Text one_Content;


void get_text(string book, int ch = 0)       //��ȡ�������ı�����
{
    setlocale(LC_ALL, "zh-CN");              //�ı�2��6�������ַ�
    ifstream in("TXT/" + book + ".txt");     //ƴ��·��
    string line, con;                        //�洢���ж�ȡ��������
    one_Content.bookName = book;             //��ʼ������
    one_Content.page = 1;
    one_Content.chapter = ch;
    int len = 0;
    if (in)                                  // �и��ļ�
    {
        while (getline(in, line))
        {// ѭ����ȡ�ļ���ÿһ��
            len = line.length(); // ��ȡ�еĳ���
            if (len <= 20 && len > 0) //����г���С�ڵ���20�Ҵ���0���������½�����ҳ��
            {
                int counts = 0;
                for (int i = 0; i < len; i++)
                    if (isdigit(line[i]))// ����ַ��Ƿ�������
                        counts++;
                if (counts == len)
                    one_Content.page = atoi(line.c_str()) + 1;  //��ҳ��
                else
                {
                    transform(line.begin(), line.end(), line.begin(), ::tolower);
                    if (line.substr(0, 7) == "chapter")
                        one_Content.chapter++;                  //���½�
                }
            }
            else// ����в����½�����ҳ�룬����Ϊ�����ı�����
            {
                one_Content.content = line;
                text.push_back(one_Content);// ��one_Content������ӵ�text���е�ĩβ
            
            }
        }
    }
    else
        cout << "�����ڴ��ı���" << book << endl;
}

void input_Book()  //�����ı���Ϣ
{
    get_text("J.K. Rowling - HP 0 - Harry Potter Prequel", -1);   //��һ���Ǵӵ�0�¿�ʼ�ģ����Դ���-1������Ķ��Ǵӵ�1�¿�ʼ�����Բ��ô�
    get_text("J.K. Rowling - HP 2 - Harry Potter and the Chamber of Secrets");
    get_text("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban");
    get_text("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire");
    get_text("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince");
    get_text("J.K. Rowling - HP 7 - Harry Potter and the Deathly Hallows");
    get_text("J.K. Rowling - Quidditch Through the Ages");
    get_text("J.K. Rowling - The Tales of Beedle the Bard");
}

// ���ļ���������Ϣ
void search_in_File(string info, deque<Text>& s)    //������Ϣ
{
    int all_len = text.size();
    string::size_type p;
    for (int i = 0; i < all_len; i++)
    {
        p = text[i].content.find(info);
        if (!(p == string::npos))
            s.push_back(text[i]);// �����е��ı���Ϣ��ӵ���������Ķ�����
    }
}

void show_Info(deque<Text> s, string info)                        //��ʾ��ѯ���
{
    cout << "���       ����/����       ҳ��       �½�       ����" << endl;
    for (int i = 0; i < s.size(); i++)
        cout << "  "
        << i + 1 << "       "
        << info << "         "
        << s[i].page << "         "
        << s[i].chapter << "         "
        << s[i].bookName << endl;
}

int main()
{
    input_Book();
    string input_Info;          //�û�����
    deque<Text> search_Info;    //�洢����������Ϣ
    cout << "������Ҫ��ѯ������/����: " << endl;
    getline(cin, input_Info);   //��ȡ����
    search_in_File(input_Info, search_Info);
    if (!search_Info.empty())
    {
        show_Info(search_Info, input_Info);
        cout << endl << "������Ҫ��ʾ�Ķ�������: " << endl;
        while (1)
        {
            int x = 1;
            cin >> x;
            if (x == 0)
                break;
            cout << endl << search_Info[x - 1].content << endl;
            cout << endl << "��Ҫ������ʾ����������������ţ��������� 0:" << endl;
        }
    }
    else
        cout << "�޷���ѯ�� ! ! !" << endl;
    return 0;
}