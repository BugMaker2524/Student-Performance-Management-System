#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring> 
#include<string>
#include<cmath>
using namespace std;
int i;
class yxStudent//����һ��ѧ���� 
{
	public: /*���ݳ�Ա*/ 
		   	char Name[21];
		   	long long Id;
			float Wuli;
			float Shuxue;
			float Yingyu;
			float Sum;
			~yxStudent(){};//�������� 
};
yxStudent yxStu[100];//���ѧ����Ϣ 
void yxWenjian()//ʵ���ļ������ĺ��� 
{
	ifstream ifile;
	ifile.open("F:\\ѧ���ɼ�����1.txt");
	if(ifile)
	{
		while(!ifile.eof()&&ifile.peek()!=EOF)
		{
			ifile>>yxStu[i].Id>>yxStu[i].Name>>yxStu[i].Wuli>>yxStu[i].Shuxue>>yxStu[i].Yingyu;
			char a[500];
			yxStu[i].Sum=yxStu[i].Wuli+yxStu[i].Shuxue+yxStu[i].Yingyu;
			ifile>>yxStu[i].Sum;
			ifile.getline(a,500);
			i++;	
		}
	}	
	ifile.close();
}
void yxZengjia(void)//����ѧ����Ϣ�ĺ��� 
{
	while(1)
	{
		cout<<"��ѡ��Ҫ���еĲ���"<<endl;
		cout<<"1.����һλѧ��"<<endl;
		cout<<"2.�˳�"<<endl;
		char name[21];
		int c2;
		getchar();
		cin>>c2;
		if(c2==1)
		{
			cout<<"����������"<<endl;
			getchar();
			cin.getline(yxStu[i].Name, 21);
			cout<<"����������ѧ�ţ�����ɼ�����ѧ�ɼ���Ӣ��ɼ���"<< endl;
			cin >>yxStu[i].Id;
			if(yxStu[i].Id>100)
			{
				cout<<"ѧ��λ����������������"<<endl;
				cin>>yxStu[i].Id;
			}
			cout<<"ѧ����ȷ���������������ɼ�����ѧ�ɼ���Ӣ��ɼ�"<<endl; 
			cin>>yxStu[i].Wuli>>yxStu[i].Shuxue>>yxStu[i].Yingyu;
			yxStu[i].Sum = yxStu[i].Wuli+yxStu[i].Shuxue+yxStu[i].Yingyu;
			i++;
			cout<<"��¼��"<<endl;
		}
		if(c2==2){break;}
	}
}
void yxChazhao(void)
{
	cout<<"��ѡ��Ҫ���еĲ���"<<endl;
	cout<<"1.��ѧ�Ų���"<<endl;
	cout<<"2.����������"<<endl;
	cout<<"3.�������β���"<<endl;
	cout<<"4.ģ������"<<endl;
	int b=0, c=0, f=0, e=1;
	int N[100];
	getchar();
	cin>>b;
	switch(b) 
	{
	case 1://����ѧ�������в��� 
	{	
		cout<<"������ѧ��"<<endl;
		long long id;
		getchar();
		cin>>id;
		for(int d=0;d<i;d++)
		{
			if(id==yxStu[d].Id)
			{
				c=d;
			}
		}
		cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
		cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
		N[0]=c;
		break;
	}
	case 2://�������������в��� 
	{	
		cout<<"����������"<<endl;
		char name[21];
		getchar();
		cin.getline(name,21);
		for(int d=0;d<i;d++)
		{
			if (strcmp(name,yxStu[d].Name)==0) 
			{
				c=d;
			}
			
		}
		cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
		cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
		N[0]=c;
		break;
	}
	case 3://���շ����������в��� 
	{
		cout<<"��ѡ��Ҫ��ѯ�Ŀ�Ŀ"<<endl;
		cout<<"1.����"<<endl;
		cout<<"2.��ѧ"<<endl;
		cout<<"3.Ӣ��"<<endl;
		cout<<"4.�ܷ�"<<endl;
		int d;
		getchar();
		cin>>d;
		float max,min;
		cout<<"������������������:"<<endl;
		getchar();
		cin>>min>>max;
		cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
		if(d==1)
		{
			for(c=0;c<i;c++)
			{
			   if(yxStu[c].Wuli>=min&&yxStu[c].Wuli<=max)
			   cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
			   N[e-1]=c;
			   e++;
			}
		}

		if(d==2)
		{
			for(c=0;c<i;c++)
			{
				if(yxStu[c].Shuxue>=min&&yxStu[c].Shuxue<=max)
				cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
				N[e-1]=c;
				e++;
			}
		}
		if(d==3)
		{
			for(c=0;c<i;c++)
			{
				if(yxStu[c].Yingyu>=min&&yxStu[c].Yingyu<=max)
				cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
				N[e-1]=c;
				e++;
			}
		}
		if(d==4)
		{
			for(c=0;c<i;c++) 
			{
				if(yxStu[c].Sum>=min&&yxStu[c].Sum<=max)
				cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
				N[e-1]=c;
				e++;
			}
		}
		break;
	}
	case 4://����ģ������ʽ���� 
	{
		char name[21];
		cout <<"������������һ����"<<endl;
		getchar();
		cin.getline(name, 21);
		cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
		int  a=0,d=1,m=0,n=0;
		int cd1;
		cd1=strlen(name);
		for (;m<i;m++)
		{
			if(name[n]==yxStu[m].Name[n]&&name[n+1]==yxStu[m].Name[n+1])d=0;
			if(d==0)
			{
				N[a]=m;
				cout<<a+1<<yxStu[m].Id<<'\t'<<yxStu[m].Name<<'\t'<<yxStu[m].Wuli<<'\t'<<yxStu[m].Shuxue<<'\t'<<yxStu[m].Yingyu<<'\t'<<yxStu[m].Sum<<'\t'<<endl;
				a++;
			}
			d=1;
		}
		break;
	}
	}
	int n,o=0,m=0;
	cout<<"�Ƿ�����޸Ļ�ɾ��:"<<endl;
	cout<<"1.�޸�"<<endl;
	cout<<"2.ɾ��"<<endl;
	cout<<"3.������"<<endl;
	cin>>f;
	switch(f)
	{
		case 1:
		{
			cout<<"�޸ĵڼ���ѧ����"<<endl;
			cin>>n;
			m=N[n-1];
			cout<<"1.����"<<endl;
			cout<<"2.ѧ��"<<endl;
			cout<<"3.����"<<endl;
			cout<<"4.��ѧ"<<endl;
			cout<<"5.Ӣ��"<<endl;
			int x;
			cin>>x;
			if(x==1)
			{
				cout<<"����ѧ��������";
				cin.getline(yxStu[m].Name, 21);
			}
			if(x==2)
			{
				cout<<"����ѧ��ѧ�ţ�";
				cin>>yxStu[m].Id;
			}
			if(x==3)
			{
				cout<<"����ѧ������ɼ���";
				cin>>yxStu[m].Wuli;
			}				
			if(x==4)
			{
				cout<<"����ѧ����ѧ�ɼ���";
				cin>>yxStu[m].Shuxue;
			}				
			if(x==5)
			{
				cout<<"����ѧ��Ӣ��ɼ���";
				cin>>yxStu[m].Yingyu;
			}
			cout<<"�޸ĳɹ���"<<endl;
			break;
		}
		case 2: 
		{
			cout<<"������Ҫɾ����ѧ�����"<<endl;
			cin>>n;
			m=N[n-1];
			cout<<"ȷ��Ҫɾ��ô��"<<endl;
			cout<<"1.��"<<endl;
			cout<<"2.��"<<endl;
			getchar();
			cin>>o;
			if(o==1)
			{
				for(;m<i;m++) 
				{
					yxStu[m]=yxStu[m+1];		
				}
				i=i-1;
			}
		}
	}
}
void yxXiugai(void)
{
	cout<<"�޸ĵڼ���ѧ����"<< endl;
	int y;
	getchar();
	cin >> y;
	cout<<"1.ѧ��"<<endl;
	cout<<"2.����"<<endl;
	cout<<"3.����"<<endl;
	cout<<"4.��ѧ"<<endl;
	cout<<"5.Ӣ��"<<endl;
	int x;
	cin>>x;
	if(x==1)
	{
		cout<<"����ѧ��������";
		getchar();
		cin.getline(yxStu[y-1].Name,21);
	}
	if(x==2)
	{
		cout<<"����ѧ��ѧ�ţ�";
		getchar();
		cin>>yxStu[y-1].Id;
	}
	if(x==3) 
	{
		cout<<"����ѧ������ɼ���";
		getchar();
		cin>>yxStu[y-1].Wuli;
	}
	if(x==4)
	{
		cout<<"����ѧ����ѧ�ɼ���";
		getchar();
		cin>>yxStu[y-1].Shuxue;
	}
	if(x==5) 
	{
		cout<<"����ѧ��Ӣ��ɼ���";
		getchar();
		cin>>yxStu[y-1].Yingyu;
	}
	cout<<"�޸ĳɹ���"<<endl;
	cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
	for(int a=0;a<i;a++)
	{
		cout<<a+1<<yxStu[a].Id<<'\t'<<yxStu[a].Name<<'\t'<<yxStu[a].Wuli<<'\t'<<yxStu[a].Shuxue<<'\t'<<yxStu[a].Yingyu<<'\t'<<yxStu[a].Sum<<'\t'<<endl;
	}
}	
/*void tongji(void) 
{
	double t1=0,t2=0,t3=0;
	int j,s,d,q=0;
	for(s=0;s<i;s++)
	t1=t1+yxStu[s].Sum;     //�ֵܷĺ�
	t1=t1/i;                                 //�ֵܷ�ƽ����
	for(d=0;d<i;d++)
	{
		if(yxStu[d].Sum>=180){ q++; }                        //��������
	}
	t2=(double)q/(double)i;                     //������
	for(j=0;j<i;j++)t3=t3+(yxStu[j].Sum-t1)*(yxStu[j].Sum-t1)/i;  //��׼��
	cout<<"�ܷ�"<<endl;
	cout<<"ƽ����:"<<t1<<"  �ϸ���:"<<t2<<"  ��׼��:"<<sqrt(t3)<<endl;
}
void tongji(int c3) 
{
		double t1=0,t2=0,t3=0;
		int j,s,d,q=0;
		if(c3==1)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Wuli;     //����ֵĺ�
			t1=t1/i;                                 //����ֵ�ƽ����
			for(d=0;d<i;d++)
			{
	     		if(yxStu[d].Wuli>=60)q++;                        //��������
			}
			t2=(double)q/(double)i;                           //������
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Wuli-t1)*(yxStu[j].Wuli-t1)/i;  //��׼��
			cout<<"�ܷ�"<<endl;
			cout<<"ƽ����:"<<t1<<"  �ϸ���:"<<t2<<"  ��׼��:"<<sqrt(t3)<<endl;
		}
		if(c3==2)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Shuxue;     //��ѧ�ֵĺ�
			t1=t1/i;                                 //��ѧ�ֵ�ƽ����
			for(d=0;d<i;d++)
			{
				if(yxStu[d].Shuxue>=60)q++;                        //��������
			}
			t2=(double)q/(double)i;                          //������
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Shuxue-t1)*(yxStu[j].Shuxue-t1)/i;  //��׼��
			cout<<"�ܷ�"<<endl;
			cout<<"ƽ����:"<<t1<<"  �ϸ���:"<<t2<<"  ��׼��:"<<sqrt(t3)<<endl;
		}
		if(c3==3)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Yingyu;     //Ӣ��ֵĺ�
			t1=t1/i;                                 //��ѧ�ֵ�ƽ����
			for(d=0;d<i;d++) 
			{
				if(yxStu[d].Yingyu>=60)q++;                        //��������
			}
			t2=(double)q/(double)i;                        //������
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Yingyu-t1)*(yxStu[j].Yingyu-t1)/i;  //��׼��
			cout<<"�ܷ�"<<endl;
			cout<<"ƽ����:"<<t1<<"  �ϸ���:"<<t2<<"  ��׼��:"<<sqrt(t3)<<endl;
		}
}*/ 
void yxPaixu()
{
	yxStudent temp;
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<i-j;k++)
		{
			if(yxStu[k].Sum<yxStu[k+1].Sum)
			{
				temp=yxStu[k];
				yxStu[k]=yxStu[k+1];
				yxStu[k+1]=temp;
			}
			if(yxStu[k].Sum==yxStu[k+1].Sum) 
			{
				if(yxStu[k].Shuxue<yxStu[k+1].Shuxue) 
				{
					temp=yxStu[k];
					yxStu[k]=yxStu[k+1];
					yxStu[k+1]=temp;
				}
				if(yxStu[k].Shuxue==yxStu[k+1].Shuxue)
				{
					if(yxStu[k].Wuli<yxStu[k+1].Wuli) 
					{
						temp=yxStu[k];
						yxStu[k]=yxStu[k+1];
						yxStu[k+1]=temp;
					}
					if(yxStu[k].Wuli==yxStu[k+1].Wuli) 
					{
						if(yxStu[k].Id<yxStu[k+1].Id)
						{
							temp=yxStu[k];
							yxStu[k]=yxStu[k+1];
							yxStu[k+1]=temp;
						}
					}
				}
			}
		}
	}
	cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
	for(int a=0;a<i;a++)
	{
		cout<<a+1<<'\t'<<yxStu[a].Id<<'\t'<<yxStu[a].Name<<'\t'<<yxStu[a].Wuli<<'\t'<<yxStu[a].Shuxue<<'\t'<<yxStu[a].Yingyu<<'\t'<<yxStu[a].Sum<<'\t'<<endl;
	}
}
void yxXianshi(void) 
{
	cout<<"���"<<'\t'<<"ѧ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"�ܷ�"<<endl;
	for(int a=0;a<i;a++)
	{
		cout<<a+1<<'\t'<<yxStu[a].Id<<'\t'<<yxStu[a].Name<<'\t'<<yxStu[a].Wuli<<'\t'<<yxStu[a].Shuxue<<'\t'<<yxStu[a].Yingyu<<'\t'<<yxStu[a].Sum<<'\t'<<endl;
	}
	while(1)
	{
		int f,n,o,m=0;
		cout<<"�Ƿ�����޸Ļ�ɾ��:"<<endl;
		cout<<"1.�޸�"<<endl;
		cout<<"2.ɾ��"<<endl;
		cout<<"3.������"<<endl;
		getchar();
		cin>>f;
		switch(f)
		{
		case 1:
				cout<<"�޸ĵڼ���ѧ����"<<endl;
				int y;
				cin>>y;
				cout<<"1.ѧ��"<<endl;
				cout<<"2.����"<<endl;
				cout<<"3.����"<<endl;
				cout<<"4.��ѧ"<<endl;
				cout<<"5.Ӣ��"<<endl;
				int x;
				cin>>x;
				if(x==1) 
				{
					cout<<"����ѧ��������";
					cin.getline(yxStu[y-1].Name,21);
				}
				if(x==2) 
				{
					cout<<"����ѧ��ѧ�ţ�";
					cin>>yxStu[y-1].Id;
				}
				if(x==3)
				{
					cout<<"����ѧ������ɼ���";
					cin>>yxStu[y-1].Wuli;
				}
				if(x==4) 
				{
					cout<<"����ѧ����ѧ�ɼ���";
					cin>>yxStu[y-1].Shuxue;
				}
				if(x==5) 
				{
					cout<<"����ѧ��Ӣ��ɼ���";
					cin>>yxStu[y-1].Yingyu;
				}
				cout<<"�޸ĳɹ���"<<endl;
				break;
		case 2:
				cout<<"������Ҫɾ����ѧ�����"<<endl;
				cin>>n;
				cout<<"ȷ��Ҫɾ��ô��"<<endl;
				cout<<"1.��"<<endl;
				cout<<"2.��"<<endl;
				cin>>o;
				if(o==1) 
				{
					for(;m<i;m++) 
					{
						yxStu[n-1]=yxStu[n];
					}
					i=i-1;
				}
				break;
		case 3:	break;
		}
		if(f==3)break;
	}
}
void yxBaoyxStu(void) 
{
	ofstream ofile;
	ofile.open("F:\\ѧ���ɼ�����");
	for(int j=0;j<i;j++) 
	{
		ofile<<setw(10)<<yxStu[j].Id<<setw(20)<<yxStu[j].Name<<setw(10)<<yxStu[j].Wuli<<setw(10)<<yxStu[j].Shuxue<<setw(10)<<yxStu[j].Yingyu<<endl;
	}
	ofile.close();
	cout<<"�������"<<endl;
}
void yxWenjian();
void yxZengjia();
void yxXianshi();
void yxChazhao();
void yxBaoyxStu();
void mohu();
void yxPaixu();
void tongji();
void shanchu();
void yxXiugai();
void tongji(int c3);
int main()
{
	int i=0;
	while(1) 
	{
		system("cls");
		cout<<"****************************************"<<endl;
		cout<<"         ��ӭ����ѧ���ɼ�����ϵͳ��     "<<endl; 
		cout<<"                 ��ѡ��                 "<<endl; 
		cout<<"               1:����ѧ��               "<<endl;
		cout<<"               2:ɾ��ѧ��               "<<endl;
		cout<<"               3:����ѧ��               "<<endl;
		cout<<"               4:�޸���Ϣ               "<<endl;
//		cout<<"               5:ͳ�Ʒ���               "<<endl;
		cout<<"               5:�ɼ�����               "<<endl;
		cout<<"               6:��ʾ�ɼ�               "<<endl;
		cout<<"               7:����ɼ�               "<<endl;
		cout<<"               8:��ȡ�ļ�               "<<endl;
		cout<<"               9:�˳�ϵͳ              "<<endl; 
		cout<<"****************************************"<<endl;
		int c1;
		cin>>c1;
		switch(c1)
		{
			case 1:yxZengjia();continue;
			case 2:yxChazhao();continue;
			case 3:yxChazhao();continue;
			case 4:yxXiugai();continue;
			/*case 5:
					{
					cout<<"��������ƽ���֡���׼��ϸ���"<<endl;
					cout<<"1.����"<<endl;
					cout<<"2.��ѧ"<<endl;
					cout<<"3.Ӣ��"<<endl;
					cout<<"4.�ܷ�"<<endl;
					int c3;
					cin>>c3;
					if(c3<4)tongji(c3);
					if(c3==4)tongji();
					}
					continue;*/
			case 5:yxPaixu();continue;
			case 6:yxXianshi();continue;
			case 7:yxBaoyxStu();continue;
			case 8:yxWenjian();continue;
			case 9:break;
		}
		return 0;
	}
}	
