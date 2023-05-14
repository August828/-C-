#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//��ϵ�˽ṹ��
struct Person {
	string m_name;
	int m_Sex;  //1�У�2Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};


//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};


//�˵�����
void showMenu()
{
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
}

//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl << "1 --- ��" << endl << "2 --- Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "����������������룡" << endl;
			}
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������ͥסַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ϵ����ӳɹ���" << endl;

		//��������
		system("pause");
		system("cls");
	}
}


//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ��
int isExit(Addressbooks* abs, string name)
{

	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].m_name)
		{
			return i;
		}
	}
	return -1;
}


//3.ɾ����ϵ��
void delPerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}


//4.������ϵ��
void finePerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "��ѯ�ɹ���" << endl;
		cout << "������" << abs->personArray[ret].m_name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}


//5.�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl << "1 --- ��" << endl << "2 --- Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "����������������룡" << endl;
			}
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		string addr;
		cout << "�������ͥסַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;


		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	//��������
	system("pause");
	system("cls");
}


//6.�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼Ϊ�գ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;

	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;  //�����û�ѡ���������

	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:  //1.�����ϵ��
			addPerson(&abs);  //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:  //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //3.ɾ����ϵ��
			delPerson(&abs);
			break;
		case 4:  //4.������ϵ��
			finePerson(&abs);
			break;
		case 5:  //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:  //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:  //0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
