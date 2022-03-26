#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring> 
#include<string>
#include<cmath>
using namespace std;
int i;
class yxStudent//定义一个学生类 
{
	public: /*数据成员*/ 
		   	char Name[21];
		   	long long Id;
			float Wuli;
			float Shuxue;
			float Yingyu;
			float Sum;
			~yxStudent(){};//析构函数 
};
yxStudent yxStu[100];//存放学生信息 
void yxWenjian()//实现文件操作的函数 
{
	ifstream ifile;
	ifile.open("F:\\学生成绩数据1.txt");
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
void yxZengjia(void)//增加学生信息的函数 
{
	while(1)
	{
		cout<<"请选择要进行的操作"<<endl;
		cout<<"1.增加一位学生"<<endl;
		cout<<"2.退出"<<endl;
		char name[21];
		int c2;
		getchar();
		cin>>c2;
		if(c2==1)
		{
			cout<<"请输入姓名"<<endl;
			getchar();
			cin.getline(yxStu[i].Name, 21);
			cout<<"请依次输入学号，物理成绩，数学成绩，英语成绩。"<< endl;
			cin >>yxStu[i].Id;
			if(yxStu[i].Id>100)
			{
				cout<<"学号位数错误，请重新输入"<<endl;
				cin>>yxStu[i].Id;
			}
			cout<<"学号正确，请继续输入物理成绩，数学成绩，英语成绩"<<endl; 
			cin>>yxStu[i].Wuli>>yxStu[i].Shuxue>>yxStu[i].Yingyu;
			yxStu[i].Sum = yxStu[i].Wuli+yxStu[i].Shuxue+yxStu[i].Yingyu;
			i++;
			cout<<"已录入"<<endl;
		}
		if(c2==2){break;}
	}
}
void yxChazhao(void)
{
	cout<<"请选择要进行的操作"<<endl;
	cout<<"1.按学号查找"<<endl;
	cout<<"2.按姓名查找"<<endl;
	cout<<"3.按分数段查找"<<endl;
	cout<<"4.模糊查找"<<endl;
	int b=0, c=0, f=0, e=1;
	int N[100];
	getchar();
	cin>>b;
	switch(b) 
	{
	case 1://按照学号来进行查找 
	{	
		cout<<"请输入学号"<<endl;
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
		cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
		cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
		N[0]=c;
		break;
	}
	case 2://按照姓名来进行查找 
	{	
		cout<<"请输入姓名"<<endl;
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
		cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
		cout<<e<<'\t'<<yxStu[c].Id<<'\t'<<yxStu[c].Name<<'\t'<<yxStu[c].Wuli<<'\t'<<yxStu[c].Shuxue<<'\t'<<yxStu[c].Yingyu<<'\t'<<yxStu[c].Sum<<'\t'<<endl;
		N[0]=c;
		break;
	}
	case 3://按照分数段来进行查找 
	{
		cout<<"请选择要查询的科目"<<endl;
		cout<<"1.物理"<<endl;
		cout<<"2.数学"<<endl;
		cout<<"3.英语"<<endl;
		cout<<"4.总分"<<endl;
		int d;
		getchar();
		cin>>d;
		float max,min;
		cout<<"请依次输入下限上限:"<<endl;
		getchar();
		cin>>min>>max;
		cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
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
	case 4://按照模糊化方式查找 
	{
		char name[21];
		cout <<"请输入姓名的一部分"<<endl;
		getchar();
		cin.getline(name, 21);
		cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
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
	cout<<"是否进行修改或删除:"<<endl;
	cout<<"1.修改"<<endl;
	cout<<"2.删除"<<endl;
	cout<<"3.不进行"<<endl;
	cin>>f;
	switch(f)
	{
		case 1:
		{
			cout<<"修改第几个学生？"<<endl;
			cin>>n;
			m=N[n-1];
			cout<<"1.姓名"<<endl;
			cout<<"2.学号"<<endl;
			cout<<"3.物理"<<endl;
			cout<<"4.数学"<<endl;
			cout<<"5.英语"<<endl;
			int x;
			cin>>x;
			if(x==1)
			{
				cout<<"输入学生姓名：";
				cin.getline(yxStu[m].Name, 21);
			}
			if(x==2)
			{
				cout<<"输入学生学号：";
				cin>>yxStu[m].Id;
			}
			if(x==3)
			{
				cout<<"输入学生物理成绩：";
				cin>>yxStu[m].Wuli;
			}				
			if(x==4)
			{
				cout<<"输入学生数学成绩：";
				cin>>yxStu[m].Shuxue;
			}				
			if(x==5)
			{
				cout<<"输入学生英语成绩：";
				cin>>yxStu[m].Yingyu;
			}
			cout<<"修改成功！"<<endl;
			break;
		}
		case 2: 
		{
			cout<<"请输入要删除的学生序号"<<endl;
			cin>>n;
			m=N[n-1];
			cout<<"确定要删除么？"<<endl;
			cout<<"1.是"<<endl;
			cout<<"2.否"<<endl;
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
	cout<<"修改第几个学生？"<< endl;
	int y;
	getchar();
	cin >> y;
	cout<<"1.学号"<<endl;
	cout<<"2.姓名"<<endl;
	cout<<"3.物理"<<endl;
	cout<<"4.数学"<<endl;
	cout<<"5.英语"<<endl;
	int x;
	cin>>x;
	if(x==1)
	{
		cout<<"输入学生姓名：";
		getchar();
		cin.getline(yxStu[y-1].Name,21);
	}
	if(x==2)
	{
		cout<<"输入学生学号：";
		getchar();
		cin>>yxStu[y-1].Id;
	}
	if(x==3) 
	{
		cout<<"输入学生物理成绩：";
		getchar();
		cin>>yxStu[y-1].Wuli;
	}
	if(x==4)
	{
		cout<<"输入学生数学成绩：";
		getchar();
		cin>>yxStu[y-1].Shuxue;
	}
	if(x==5) 
	{
		cout<<"输入学生英语成绩：";
		getchar();
		cin>>yxStu[y-1].Yingyu;
	}
	cout<<"修改成功！"<<endl;
	cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
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
	t1=t1+yxStu[s].Sum;     //总分的合
	t1=t1/i;                                 //总分的平均分
	for(d=0;d<i;d++)
	{
		if(yxStu[d].Sum>=180){ q++; }                        //及格人数
	}
	t2=(double)q/(double)i;                     //及格率
	for(j=0;j<i;j++)t3=t3+(yxStu[j].Sum-t1)*(yxStu[j].Sum-t1)/i;  //标准差
	cout<<"总分"<<endl;
	cout<<"平均分:"<<t1<<"  合格率:"<<t2<<"  标准差:"<<sqrt(t3)<<endl;
}
void tongji(int c3) 
{
		double t1=0,t2=0,t3=0;
		int j,s,d,q=0;
		if(c3==1)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Wuli;     //物理分的合
			t1=t1/i;                                 //物理分的平均分
			for(d=0;d<i;d++)
			{
	     		if(yxStu[d].Wuli>=60)q++;                        //及格人数
			}
			t2=(double)q/(double)i;                           //及格率
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Wuli-t1)*(yxStu[j].Wuli-t1)/i;  //标准差
			cout<<"总分"<<endl;
			cout<<"平均分:"<<t1<<"  合格率:"<<t2<<"  标准差:"<<sqrt(t3)<<endl;
		}
		if(c3==2)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Shuxue;     //数学分的合
			t1=t1/i;                                 //数学分的平均分
			for(d=0;d<i;d++)
			{
				if(yxStu[d].Shuxue>=60)q++;                        //及格人数
			}
			t2=(double)q/(double)i;                          //及格率
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Shuxue-t1)*(yxStu[j].Shuxue-t1)/i;  //标准差
			cout<<"总分"<<endl;
			cout<<"平均分:"<<t1<<"  合格率:"<<t2<<"  标准差:"<<sqrt(t3)<<endl;
		}
		if(c3==3)
		{
			for(s=0;s<i;s++)
			t1=t1+yxStu[s].Yingyu;     //英语分的合
			t1=t1/i;                                 //数学分的平均分
			for(d=0;d<i;d++) 
			{
				if(yxStu[d].Yingyu>=60)q++;                        //及格人数
			}
			t2=(double)q/(double)i;                        //及格率
			for(j=0;j<i;j++)
			t3=t3+(yxStu[j].Yingyu-t1)*(yxStu[j].Yingyu-t1)/i;  //标准差
			cout<<"总分"<<endl;
			cout<<"平均分:"<<t1<<"  合格率:"<<t2<<"  标准差:"<<sqrt(t3)<<endl;
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
	cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
	for(int a=0;a<i;a++)
	{
		cout<<a+1<<'\t'<<yxStu[a].Id<<'\t'<<yxStu[a].Name<<'\t'<<yxStu[a].Wuli<<'\t'<<yxStu[a].Shuxue<<'\t'<<yxStu[a].Yingyu<<'\t'<<yxStu[a].Sum<<'\t'<<endl;
	}
}
void yxXianshi(void) 
{
	cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"物理"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"总分"<<endl;
	for(int a=0;a<i;a++)
	{
		cout<<a+1<<'\t'<<yxStu[a].Id<<'\t'<<yxStu[a].Name<<'\t'<<yxStu[a].Wuli<<'\t'<<yxStu[a].Shuxue<<'\t'<<yxStu[a].Yingyu<<'\t'<<yxStu[a].Sum<<'\t'<<endl;
	}
	while(1)
	{
		int f,n,o,m=0;
		cout<<"是否进行修改或删除:"<<endl;
		cout<<"1.修改"<<endl;
		cout<<"2.删除"<<endl;
		cout<<"3.不进行"<<endl;
		getchar();
		cin>>f;
		switch(f)
		{
		case 1:
				cout<<"修改第几个学生？"<<endl;
				int y;
				cin>>y;
				cout<<"1.学号"<<endl;
				cout<<"2.姓名"<<endl;
				cout<<"3.物理"<<endl;
				cout<<"4.数学"<<endl;
				cout<<"5.英语"<<endl;
				int x;
				cin>>x;
				if(x==1) 
				{
					cout<<"输入学生姓名：";
					cin.getline(yxStu[y-1].Name,21);
				}
				if(x==2) 
				{
					cout<<"输入学生学号：";
					cin>>yxStu[y-1].Id;
				}
				if(x==3)
				{
					cout<<"输入学生物理成绩：";
					cin>>yxStu[y-1].Wuli;
				}
				if(x==4) 
				{
					cout<<"输入学生数学成绩：";
					cin>>yxStu[y-1].Shuxue;
				}
				if(x==5) 
				{
					cout<<"输入学生英语成绩：";
					cin>>yxStu[y-1].Yingyu;
				}
				cout<<"修改成功！"<<endl;
				break;
		case 2:
				cout<<"请输入要删除的学生序号"<<endl;
				cin>>n;
				cout<<"确定要删除么？"<<endl;
				cout<<"1.是"<<endl;
				cout<<"2.否"<<endl;
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
	ofile.open("F:\\学生成绩数据");
	for(int j=0;j<i;j++) 
	{
		ofile<<setw(10)<<yxStu[j].Id<<setw(20)<<yxStu[j].Name<<setw(10)<<yxStu[j].Wuli<<setw(10)<<yxStu[j].Shuxue<<setw(10)<<yxStu[j].Yingyu<<endl;
	}
	ofile.close();
	cout<<"保存完成"<<endl;
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
		cout<<"         欢迎进入学生成绩管理系统！     "<<endl; 
		cout<<"                 请选择                 "<<endl; 
		cout<<"               1:增加学生               "<<endl;
		cout<<"               2:删除学生               "<<endl;
		cout<<"               3:查找学生               "<<endl;
		cout<<"               4:修改信息               "<<endl;
//		cout<<"               5:统计分析               "<<endl;
		cout<<"               5:成绩排序               "<<endl;
		cout<<"               6:显示成绩               "<<endl;
		cout<<"               7:保存成绩               "<<endl;
		cout<<"               8:读取文件               "<<endl;
		cout<<"               9:退出系统              "<<endl; 
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
					cout<<"求哪门求平均分、标准差、合格率"<<endl;
					cout<<"1.物理"<<endl;
					cout<<"2.数学"<<endl;
					cout<<"3.英语"<<endl;
					cout<<"4.总分"<<endl;
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
