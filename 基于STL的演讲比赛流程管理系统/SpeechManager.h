#pragma once
#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"
using namespace std;

//����ݽ�������
class SpeechManager
{
public:

	//���캯��
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�����
	void exitSystem();

	//��ʼ������
	void initSpeech();

	//��ʼ������12��ѡ��
	void createSpeaker();

	//��ʼ�������������������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ļ�Ϊ�ձ�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;

	//��ʾ����÷�
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//��������
	~SpeechManager();

	//����ѡ�� ���� 12��
	vector<int>v1;

	//��һ�ֽ������� 6��
	vector<int>v2;

	//����ǰ�������� 3��
	vector<int>vVictory;

	//��ű���Լ���Ӧ�ľ���ѡ������
	map<int, Speaker> m_Speaker;

	//��¼��������
	int m_Index;

};