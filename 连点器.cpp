#include <bits/stdc++.h>//���ܿ� 
#include <windows.h>//Windows�� 
using namespace std;

#define START (GetKeyState(VK_MENU)<0) 
#define STOP (GetKeyState(VK_SPACE)<0)
#define END (GetKeyState(VK_ESCAPE)<0)
#define SET (GetKeyState('S')<0&&GetKeyState('E')<0&&GetKeyState('T')<0)

void go(int,int);//��궨λ���� 
void color(int);//�ı���ɫ���ú��� 

void setpinl();//���õ��Ƶ�� 

void weikaishi();//״̬��ʾΪ δ��ʼ��� 
void dianjizhong();//״̬��ʾΪ ����� 
void shezhizhong();//״̬��ʾΪ ����Ƶ���� 
void jieshu();//�������  

int pinl=10;//���Ƶ�� 
int times=0;//������� 

int main()
{
	system("mode con cols=40 lines=10");//���ô��ڵ����������� 
	
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع�� 
	
	SetWindowPos(GetForegroundWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//�ö����� 
	
	SetConsoleTitle("������");//���ô��ڱ����ı� 

	color(15);
	go(1,1);
		cout<<"����[Alt]��ʼ���";
	go(1,2);
		cout<<"����[Space]��ͣ���";
	go(1,3);
		cout<<"ͬʱ����[S][E][T]����Ƶ�ʣ� "<<pinl<<"��/s   ";
	go(1,4);
		cout<<"����[Esc]�˳�����";
	
	go(1,7);
		cout<<"��ǰ״̬��";
	
	while(!START)//δ��ʼ���ʱ 
	{
		Sleep(100);
		weikaishi();
		if(SET)
		{
			setpinl();
			weikaishi();
		}
		if(END)
		{
			jieshu();
			return 0;
		}
			
	}
	dianjizhong();
	while(!END)//����δ���� 
	{
		if(STOP)//��ͣ 
		{
			weikaishi();	
			while(!START)
			{
				if(SET)
				{
					setpinl();
					weikaishi();
				} 	
				if(END)
				{
					jieshu();
					return 0;
				}
				Sleep(100);
			}
			dianjizhong();
		}
		if(SET)//����Ƶ�� 
		{
			setpinl();
			dianjizhong();
		}	
		
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);//����������
		Sleep(500/pinl); 
		mouse_event(MOUSEEVENTF_LEFTUP  ,0,0,0,0);//������̧�� 
		Sleep(500/pinl);
		
		times++;//�������+1 
	}
	jieshu();
	

	return 0;
}

void setpinl()
{
	shezhizhong();
	
	CONSOLE_CURSOR_INFO cursor_info={1,1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//��ʾ��� 
	
	go(15,3);
		color(8);
		cout<<"�������룩";
	
	go(15,3);
		color(15);
	
	
	pinl=0;
	char a;
	a=getchar();//���ַ���ʽ���� 
	while(a!='\n')//ֻҪ��û���뻻�з� 
	{
		if(a<='9'&&a>='0')//�����ǰ�ַ������� 
			pinl=pinl*10+(a-'0');//����pinl�ĺ���һλ 
		a=getchar();//�������� 
	}
	
	CONSOLE_CURSOR_INFO cursor_info2={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info2);//���ع�� 
	
	if(pinl>500)
	{
		setpinl();
		return;
	}
	go(1,3);
		cout<<"ͬʱ����[S][E][T]����Ƶ�ʣ� "<<pinl<<"��/s   ";
}

void weikaishi()
{
	go(6,7);
		color(175);cout<<"δ��ʼ���";
}
void dianjizhong()
{
	go(6,7);
		color(79);cout<<"�����";
		color(15);cout<<"    ";
}
void shezhizhong()
{
	go(6,7);
		color(159);cout<<"����Ƶ����";
}

void jieshu()
{
	go(6,7);
		color(240);
		cout<<"�������";
		color(15);
		cout<<"  ";

	go(1,8);
		color(15);
		cout<<"�����"<<times<<"��"<<endl<<"                    ";
	
	color(8);
	system("pause");
}

void go(int x,int y)  //����ƶ�������X��ʾ�����꣬Y��ʾ�����ꡣ
{
    COORD coord;         //ʹ��ͷ�ļ��Դ�������ṹ
    coord.X=x*2;            //���ｫint����ֵ����short,�����������漰������ֵ�����ᳬ��short��Χ
    coord.Y=y;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);  //��ñ�׼������
    SetConsoleCursorPosition(a,coord);         //�Ա�׼����ľ��Ϊ�������ÿ���̨�������
}
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}//�� ���� ���� ǳ��  ��  ����  ���� ǳ�� ��� ���� ����  ����� �Һ� ǳ��  �׻�  ��
