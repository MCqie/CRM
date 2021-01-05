#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct passenger{
	char roomNum[3];	// 房号
	char name[20];	// 姓名
	char ID[18];	//身份证 
};

passenger pngInfo[100];	// 登记旅客信息结构体 

// 退出系统时接收的用户输入 
char confirmSelection()
{
	char c;	
	while(1)
	{
		fflush(stdin);	// 清空缓存区 
		c = getchar();
		if(c == 'y' || c == 'Y' || c == 'n' || c == 'N' )
		{
			break;
		}  
		else
		{
			printf("\n选择错误，请重新输入：\n");
		}
	}  
	return c;
}

//	旅客登记 
void registerPassenger()
{
	char roomNum[3];
	char name[20];
	char ID[18];
	FILE *file = fopen("info.txt","a");
	if(file == NULL)
	{
		printf("\n文件打开失败，3秒后返回\n");
		return;
	}
	
	system("cls");
	printf("\n请输入旅客信息\n\n");
	
	while(1)
	{
		system("cls");
		printf("\n请输入房间号(1-999)：\n");
		while(1)
		{
			fflush(stdin);	// 清空缓存区 
			scanf("%s",roomNum);
			if(strlen(roomNum) < 1 || strlen(roomNum) >= 4)
			{
				printf("\n房间号错误，请重新输入：\n");
			}
			else
			{
				break; 
			}
		}
		
		printf("\n请输入旅客姓名：\n");
		scanf("%s",name);
		
		printf("\n请输入旅客身份证号（18位）：\n");
		while(1)
		{
			fflush(stdin);	// 清空缓存区 
			scanf("%s",ID);
			if(strlen(ID) != 18)
			{
				printf("\n身份证输入错误，请重新输入：\n");
			}
			else
			{
				break; 
			}
		}
		
		fputs(roomNum, file);
		fputs("\n",file);
		fputs(name, file);
		fputs("\n",file);
		fputs(ID, file);
		fputs("\n",file);
		
		printf("\n是否继续添加旅客信息（Y/N）：\n");
		char isAdd = confirmSelection();	// 接收用户的输入  
		if(isAdd == 'y' || isAdd == 'Y')
		{
			continue;
		}
		break;
	}
	fclose(file);
	printf("\n信息登记完成，3秒后返回\n"); 
	Sleep(3000);
}

// 人数统计 
void readInfo()
{
	FILE *file = fopen("info.txt","r");
	int num=0;	// 记录旅客人数 
	char buf[1024]={0};
	system("cls");
	if(file == NULL)
	{
		printf("\n文件打开失败，3秒后返回\n");
		return;
	}	
	
	while(1)
	{
		if(fgets(buf,1024,file)!=NULL)
		{
			strcpy(pngInfo[num].roomNum, buf);
		}
		else break;
		fgets(buf,1024,file);
		strcpy(pngInfo[num].name, buf);
		fgets(buf,1024,file);
		strcpy(pngInfo[num].ID, buf);
		num++;
	}
	
	printf("\n在店旅客共有%d人\n\n",num);
	printf("\n3秒后返回菜单\n");
	
	fclose(file);
	Sleep(3000); 
} 

// 退店 
void deletePassenger()
{
	FILE *file = fopen("info.txt","r");
	int num=0;	// 记录旅客人数 
	int i;
	char room[3];
	char buf[1024]={0};
	system("cls");
	if(file == NULL)
	{
		printf("\n读取旅客信息失败，3秒后返回\n");
		Sleep(3000);
		return;
	}	
	
	while(1)
	{
		if(fgets(buf,1024,file)!=NULL)
		{
			strcpy(pngInfo[num].roomNum, buf);
		}
		else break;
		fgets(buf,1024,file);
		strcpy(pngInfo[num].name, buf);
		fgets(buf,1024,file);
		strcpy(pngInfo[num].ID, buf);
		num++;
	}
	
	int temp = 0;	//标志是否找到待删旅客，0表示未找到 
	while(1)
	{
		printf("\n请输入退店旅客的房间号：\n");
		scanf("%s",room);
		room[strlen(room)] = '\n';
		for(i=0;i<num;i++)
		{
			if(strcmp(pngInfo[i].roomNum, room)==0)
			{
				temp = 1; 
			}	
			if(temp == 1)
			pngInfo[i] = pngInfo[i+1];
		}
		if(temp == 0)
		printf("\n该房间没住旅客\n");
		else
		num--;
		printf("\n是否继续删除旅客信息（Y/N）：\n");
		char isAdd = confirmSelection();	// 接收用户的输入  
		if(isAdd == 'y' || isAdd == 'Y')
		{
			continue;
		}
		break;
	}
	
	FILE *fp = fopen("info.txt","w");
	if(fp == NULL)
	{
		printf("\n写入旅客信息失败，3秒后返回\n");
		Sleep(3000);
		return;
	}
	for(i=0;i<num;i++)
	{
		fputs(pngInfo[i].roomNum, fp);
		fputs(pngInfo[i].name, fp);
		fputs(pngInfo[i].ID, fp);
	}
	
	printf("\n旅客退店成功，3秒后返回菜单\n");
	fclose(file);
	fclose(fp);
	Sleep(3000); 
} 

// 进入主窗口 
void enterMainMenu()
{
	int isExit = 0;	// 系统是否退出的标志，0表示未退出，1表示退出  
	int menu;
	char isexit;
	char a[10];
	while(!isExit)
	{
		system("cls");
		printf("\n---------------------旅客登记系统---------------------\n\n");
		printf("                      1.旅客登记\n");
		printf("                      2.人数统计\n");
		printf("                      3.旅客退店\n");
		printf("                      4.退出系统\n");
		printf("\n\n\n------------------------------------------------------\n\n");
		
		scanf("%d",&menu);
		
		switch(menu)
		{
			case 1:
				registerPassenger();
				break;
			case 2:
				readInfo();
				break;
			case 3:
				deletePassenger();
				break;
			case 4:
				printf("是否确认退出（Y/N）：\n"); 
				isexit = confirmSelection();	// 退出时接收用户的输入  
				if(isexit == 'y' || isexit == 'Y')
				{
					isExit = 1;
				}
				break; 
		}
	}
	
}

int main()
{
	enterMainMenu();
	return 0;
} 
