//
// Created by 32119 on 2021/1/30.
//

// ͷ�ļ�������: ��ֹͷ�ļ��ظ�����
#ifndef INC_1_30_HTTP_H
#define INC_1_30_HTTP_H

#include <string>

class CHttp
{
public:
    std::string m_host; // ����
    std::string m_object; // ��Դ·��
    SOCKET m_socket; // �ͻ����׽���
public:
    bool AnalyseUrl(std::string url); // ����һ�������ĳ�Ա����������url
    bool InitSock(); // ��ʼ������
    bool Connect(); // ����һ�������ĳ�Ա������ ��������
    bool GetHtml(std::string &html); // ��ȡ��ҳ����
};

#endif //INC_1_30_HTTP_H
