#pragma once  //��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
using namespace std;
#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void show_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ������ڷ��ر�ţ������ڷ���-1
	int IsExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();
	
	//��־�ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;

	//��������
	~WorkerManager();

	
	
};
