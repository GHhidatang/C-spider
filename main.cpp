#include <iostream>
#include <windows.h>
#include <string>
#include <queue> // C++���еĿ� C����

#include "http.h"

using namespace std;

// ��ʼץȡ����������
bool StartCatch(string url);

int main()
{
    cout << "*********************************" << endl;
    cout << "*\t��ӭʹ����������ϵͳ\t*" << endl;
    cout << "*\t  ��ǰ�汾: 1.0\t\t*" << endl;
    cout << "*\tCopyRight @ 2021\t*" << endl;
    cout << "*********************************" << endl;

    // �ڵ�ǰ�����λ�ô�����������������ݵ��ļ���
    CreateDirectory("./Data", NULL);

    cout << "����������Ҫץȡ����ҳ��ʼURL:\n";
    string url; // cû�е��ַ�������string
    cin >> url;

    StartCatch(url);

    system("pause");
    return 0;
}

// ��ʼץȡ
bool StartCatch(string url)
{
    // c++��STL��׼ģ�����
    queue<string> q; // URL���� ��ʾ���е�Ԫ�ض���string(�ַ���)����
    q.push(url); // �Ѵ���������ʼURL�������

    while (!q.empty()) // q.empty()�������ж϶���q�Ƿ�Ϊ�� ����qΪ�շ�����
    {
        string currentUrl = q.front(); // �Ӷ���q����һ��URL��ֵ��currentUrl
        q.pop(); // �Ӷ���q�е����ղ�����URL

        // ����URL
        // http://www.dm5.com/m606296/#ipg1

        CHttp http;
        http.AnalyseUrl(url);
        if (false == http.Connect())
        {
            cout << "����ʧ��" << endl;
        } else
        {
            cout << "���ӳɹ�" << endl;
        }

        string html;
        http.GetHtml(html);

        cout << html << endl;
    }

    return true;
}
