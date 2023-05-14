#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//联系人结构体
struct Person {
	string m_name;
	int m_Sex;  //1男，2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};


//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};


//菜单界面
void showMenu()
{
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
}

//1.添加联系人
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl << "1 --- 男" << endl << "2 --- 女" << endl;
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
				cout << "输入错误，请重新输入！" << endl;
			}
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入家庭住址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;

		cout << "联系人添加成功！" << endl;

		//清屏操作
		system("pause");
		system("cls");
	}
}


//2.显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}


//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置
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


//3.删除联系人
void delPerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
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
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}


//4.查找联系人
void finePerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "查询成功！" << endl;
		cout << "姓名：" << abs->personArray[ret].m_name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}


//5.修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl << "1 --- 男" << endl << "2 --- 女" << endl;
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
				cout << "输入错误，请重新输入！" << endl;
			}
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入家庭住址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;


		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	//清屏操作
	system("pause");
	system("cls");
}


//6.清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录为空！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;

	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;  //创建用户选择输入变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:  //1.添加联系人
			addPerson(&abs);  //利用地址传递，可以修饰实参
			break;
		case 2:  //2.显示联系人
			showPerson(&abs);
			break;
		case 3:  //3.删除联系人
			delPerson(&abs);
			break;
		case 4:  //4.查找联系人
			finePerson(&abs);
			break;
		case 5:  //5.修改联系人
			modifyPerson(&abs);
			break;
		case 6:  //6.清空联系人
			cleanPerson(&abs);
			break;
		case 0:  //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
