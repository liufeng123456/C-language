#include<stdio.h>
#include<stdlib.h>
#define MAX_PERSON_INFO_SIZE 300
	//实现一个通讯录程序，完成联系人信息的存储
	//1、新增 
	//2、删除
	//3、修改记录
	//4、查找记录
	//5、打印全部记录
	//6、排序记录
	//7、清空全部记录
	//管理
	//1、把基本信息抽象并描述出来（结构体）
	//2、需要管理很多数据，就需要组织起来（数据结构）
	typedef struct PersonInfo {
		char name[1024];
		char phone[1024];
	}PersonInfo;
	typedef struct AddressBook {
		PersonInfo persons[MAX_PERSON_INFO_SIZE];
		int size;
	}AddressBook;
	AddressBook g_address_book;
	void Init() { 
		g_address_book.size = 0;
		for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i) {
			g_address_book.persons[i].name[0] = '\0';
			g_address_book.persons[i].phone[0] = '\0';

		}
	}
	int Menu() {
		printf("*****************************\n");
		printf("   1、新增联系人\n");
		printf("   2、删除联系人\n");
		printf("   3、查找联系人\n");
		printf("   4、修改联系人\n");
		printf("   5、打印全部联系人\n");
		printf("   6、排序联系人\n");
		printf("   7、清空联系人\n");
		printf("   0、退出\n");
		printf("*****************************\n");
		printf("请输入您的选择：");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
	}
	void Empty() {
		//这个函数啥也不干，就是用来凑数的
	}
	void AddPersonInfo() {
		printf("新增联系人\n");
		if (g_address_book.size >= MAX_PERSON_INFO_SIZE) {
			printf("新增联系人失败！\n");

		}
		printf("请输入联系人姓名: ");
		//必须获取到一个指针，修改的内容是一个预期的内容
		PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
		scanf("%s", person_info->name);
		printf("请输入联系人电话:");
		scanf("%s", person_info->phone);
		++g_address_book.size;
		printf("新增联系人成功！\n");
	}
	void DelPersonInfo() {
		printf("删除联系人\n");
		if (g_address_book.size <= 0) {
			printf("删除失败！通讯录为空！\n");
			return;
		}
		printf("请输入要删除的序号：");
		int id = 0;
		scanf("%d", &id);
		if (id < 0 || id >= g_address_book.size) {
			printf("删除失败！输入的序号有误!\n");
			return;
		}
		g_address_book.persons[id] =
			g_address_book.persons[g_address_book.size - 1];
		--g_address_book.size;
		printf("删除联系人成功!\n");
	}
	void FindPersonInfo() {
		printf("查找联系人\n");
		if (g_address_book.size <= 0) {
			printf("查找失败，通讯录为空！\n");
			return;
		}
		//根据姓名找电话
		printf("请输入要查找的姓名： ");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < g_address_book.size; ++i) {
			PersonInfo* info = &g_address_book.persons[i];
			if (strcmp(info->name, name) == 0) {
				printf("[%d] %s\t%s\n", i, info->name, info->phone);
			}
			break;
		}
		printf("查找联系人成功！\n");
	}
	void UpdatePersonInfo() {
		printf("更新联系人\n");
		if (g_address_book.size <= 0) {
			printf("修改失败，通讯录为空！\n");
		}
		printf("请输入要修改的序号：");
		int id = 0;
		scanf("%d", &id);
		if (id < 0 || id >= g_address_book.size) {
			printf("修改失败，输入的序号有误!\n");
			return;
		}
		PersonInfo* info = &g_address_book.persons[id];
		printf("请输入新的姓名：（%s）\n",info->name);
		char name[1024] = { 0 };
		scanf("%s", name);
		if (strcmp(name, "*") != 0) {
			strcpy(info->name, name);
		}
		char phone[1024] = { 0 };
		printf("请输入新的电话：(%s)\n", info->phone);
		scanf("%s", phone);
		if (strcmp(phone, "*") != 0) {
			strcpy(info->phone, phone);
		}
		printf("更新联系人成功!\n");
	}
	void PrintAllPersonInfo() {
		printf("打印全部联系人\n");
		for (int i = 0; i < g_address_book.size; ++i) {
			PersonInfo* info = &g_address_book.persons[i];
			printf("[%d] %s\t%s\n", i, info->name, info->phone);
		}
		printf("共打印了 %d 条数据！\n,", g_address_book.size);
		printf("打印全部联系人成功\n");
	}
	void SortPersonInfo() {
		char Sort_Name[1024] = { 0 };
		char Sort_Phone_Number[1024] = { 0 };
		int bound, size;
		int i = 0;
		for (i = 0; i < g_address_book.size; i++) {
			for (bound = 0; bound < g_address_book.size; bound++) {
				for (size = bound; size < g_address_book.size - 1; size++) {
					if (strcmp(g_address_book.persons[size].name, g_address_book.persons[size + 1].name) > 0) {
						strcpy(Sort_Name, g_address_book.persons[size].name);
						strcpy(g_address_book.persons[size].name, g_address_book.persons[size + 1].name); 					
						strcpy(g_address_book.persons[size + 1].name, Sort_Name); 					//copy 电话号码 				
						strcpy(Sort_Phone_Number,g_address_book.persons[size].phone);
						strcpy(g_address_book.persons[size].phone,g_address_book.persons[size+1].phone); 				
						strcpy(g_address_book.persons[size+1].phone, Sort_Phone_Number);
					} 			
				} 		
			} 	
		} 

		printf("排序所有联系人:\n"); 
		printf("排序成功!\n");

	}

	
	void ClearAllPersonInfo() {
		printf("清空全部数据\n");
		printf("您真的要清空全部数据吗？Y/N\n");
		char choice[1024] = { 0 };
		scanf("%s", choice);
		if (strcmp(choice,"Y") == 0) {
			g_address_book.size = 0;
			printf("清空全部数据成功！\n");
		}
		else {
			printf("清空操作取消！\n");
		}
	}
	typedef void(*Func)();
int main() {
	Func arr[] = {
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatePersonInfo,
		PrintAllPersonInfo,
		SortPersonInfo,
		ClearAllPersonInfo
	};
	Init();
	while (1) {
		int choice = Menu();
		if (choice<0 || choice >sizeof(arr) / sizeof(arr[0])) {
			printf("您的输入有误，请您重新输入！\n");
			continue;
		}
		if (choice == 0) {
			printf("退出游戏！\n");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}