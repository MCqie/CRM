#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct passenger{
	char roomNum[3];	// ����
	char name[20];	// ����
	char ID[18];	//���֤ 
};

passenger pngInfo[100];	// �Ǽ��ÿ���Ϣ�ṹ�� 

// �˳�ϵͳʱ���յ��û����� 
char confirmSelection()
{
	char c;	
	while(1)
	{
		fflush(stdin);	// ��ջ����� 
		c = getchar();
		if(c == 'y' || c == 'Y' || c == 'n' || c == 'N' )
		{
			break;
		}  
		else
		{
			printf("\nѡ��������������룺\n");
		}
	}  
	return c;
}

//	�ÿ͵Ǽ� 
void registerPassenger()
{
	char roomNum[3];
	char name[20];
	char ID[18];
	FILE *file = fopen("info.txt","a");
	if(file == NULL)
	{
		printf("\n�ļ���ʧ�ܣ�3��󷵻�\n");
		return;
	}
	
	system("cls");
	printf("\n�������ÿ���Ϣ\n\n");
	
	while(1)
	{
		system("cls");
		printf("\n�����뷿���(1-999)��\n");
		while(1)
		{
			fflush(stdin);	// ��ջ����� 
			scanf("%s",roomNum);
			if(strlen(roomNum) < 1 || strlen(roomNum) >= 4)
			{
				printf("\n����Ŵ������������룺\n");
			}
			else
			{
				break; 
			}
		}
		
		printf("\n�������ÿ�������\n");
		scanf("%s",name);
		
		printf("\n�������ÿ����֤�ţ�18λ����\n");
		while(1)
		{
			fflush(stdin);	// ��ջ����� 
			scanf("%s",ID);
			if(strlen(ID) != 18)
			{
				printf("\n���֤����������������룺\n");
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
		
		printf("\n�Ƿ��������ÿ���Ϣ��Y/N����\n");
		char isAdd = confirmSelection();	// �����û�������  
		if(isAdd == 'y' || isAdd == 'Y')
		{
			continue;
		}
		break;
	}
	fclose(file);
	printf("\n��Ϣ�Ǽ���ɣ�3��󷵻�\n"); 
	Sleep(3000);
}

// ����ͳ�� 
void readInfo()
{
	FILE *file = fopen("info.txt","r");
	int num=0;	// ��¼�ÿ����� 
	char buf[1024]={0};
	system("cls");
	if(file == NULL)
	{
		printf("\n�ļ���ʧ�ܣ�3��󷵻�\n");
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
	
	printf("\n�ڵ��ÿ͹���%d��\n\n",num);
	printf("\n3��󷵻ز˵�\n");
	
	fclose(file);
	Sleep(3000); 
} 

// �˵� 
void deletePassenger()
{
	FILE *file = fopen("info.txt","r");
	int num=0;	// ��¼�ÿ����� 
	int i;
	char room[3];
	char buf[1024]={0};
	system("cls");
	if(file == NULL)
	{
		printf("\n��ȡ�ÿ���Ϣʧ�ܣ�3��󷵻�\n");
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
	
	int temp = 0;	//��־�Ƿ��ҵ���ɾ�ÿͣ�0��ʾδ�ҵ� 
	while(1)
	{
		printf("\n�������˵��ÿ͵ķ���ţ�\n");
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
		printf("\n�÷���ûס�ÿ�\n");
		else
		num--;
		printf("\n�Ƿ����ɾ���ÿ���Ϣ��Y/N����\n");
		char isAdd = confirmSelection();	// �����û�������  
		if(isAdd == 'y' || isAdd == 'Y')
		{
			continue;
		}
		break;
	}
	
	FILE *fp = fopen("info.txt","w");
	if(fp == NULL)
	{
		printf("\nд���ÿ���Ϣʧ�ܣ�3��󷵻�\n");
		Sleep(3000);
		return;
	}
	for(i=0;i<num;i++)
	{
		fputs(pngInfo[i].roomNum, fp);
		fputs(pngInfo[i].name, fp);
		fputs(pngInfo[i].ID, fp);
	}
	
	printf("\n�ÿ��˵�ɹ���3��󷵻ز˵�\n");
	fclose(file);
	fclose(fp);
	Sleep(3000); 
} 

// ���������� 
void enterMainMenu()
{
	int isExit = 0;	// ϵͳ�Ƿ��˳��ı�־��0��ʾδ�˳���1��ʾ�˳�  
	int menu;
	char isexit;
	char a[10];
	while(!isExit)
	{
		system("cls");
		printf("\n---------------------�ÿ͵Ǽ�ϵͳ---------------------\n\n");
		printf("                      1.�ÿ͵Ǽ�\n");
		printf("                      2.����ͳ��\n");
		printf("                      3.�ÿ��˵�\n");
		printf("                      4.�˳�ϵͳ\n");
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
				printf("�Ƿ�ȷ���˳���Y/N����\n"); 
				isexit = confirmSelection();	// �˳�ʱ�����û�������  
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
