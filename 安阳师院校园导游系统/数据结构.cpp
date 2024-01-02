#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#define MAX 105
using namespace std;

struct Information{//景点信息
	string id,name,jianjie;
};

struct Edge{//边信息 
	string begin,end;
	int w;
};

int graph[MAX][MAX],cnt,mark[MAX],road[MAX];//邻接矩阵  景点数量

string password="123456789";
vector<Information> m;//存景点信息
vector<Edge> edge;//存边
map<string,int> name_xiabiao; //保存景点名称和下标对应关系
map<int,string> xiabiao_name; //保存下标和景点名称对应关系
map<string,string> id_name,name_id;//保存编号和景点名称对应关系 
 
int choose_way();//选择登陆方式 
void print_loginmenu();//打印登陆菜单 
int visitor();//游客登录 
void print_visitormenu();//打印菜单 
int administrator();//管理员登录 
void print_administratormenu();//打印菜单 
void find();//查询函数
void print_findmenu();//打印查询菜单 
int find_id();//按编号查询
int find_name();//按名称查询
void shortest_route();//最短路
void all_route();//所有路径 
void getShortest_routename(string x,string y);//查询x到y的最短路(名称)
void getShortest_routeid(string x,string y);//查询x到y的最短路(编号)
void getall_routeid(string x,string y,int i,int sum,int z);//查询x到y的所有路径(编号)
void getall_routename(string x,string y,int i,int sum,int z);//查询x到y的所有路径(名称) 
void print_findroadmenu();//打印查询路径菜单 
void add();//增添信息函数 
void add_edge();//添加边
void add_edgemenu();//添加边菜单 
void delete_edgemenu();//删除边菜单 
void delete_edge();//删除边 
void Delete();//删除信息函数
int delete_id();//按编号删除 
int delete_name();//按名称删除 
void update();//更新信息函数
int update_id();//按编号更新
int update_name();//按名称更新
void update_menu();//打印修改菜单
void update_menu2();//打印修改方式菜单
void shownum();//显示景点数量 
void printall();//打印所有景点信息 
void update_password();//修改管理员密码 
void print_deletemenu();//打印删除菜单
void change();//把vector的数据传换成邻接矩阵 
void coutmap();
void readfile();//读取文件 
void writefile();//写入文件 

int main(){
	readfile();//读取文件
//	system("aynu.jpg");//调用校园地图 （就是一个图片）
//	system("123.png");//调用校园地图 （就是一个图片）
	while(1){
		print_loginmenu();
		
		if(choose_way()==1){//退出系统 
			cout<<"感谢您使用本系统"<<endl;
			writefile();//写入文件
			return 0;
		}
	}
	return 0;
}


//登录菜单
void print_loginmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      欢迎使用本套校园导游系统                  |\n");
	printf("			|                      1.游客登录                                |\n");
	printf("			|                      2.管理员登录                              |\n");
	printf("			|                      0.退出系统                                |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
} 

//选择登陆方式
int choose_way(){
	int a;
	cin>>a;
	switch(a){//选择登陆方式 
		case 1:visitor();break;
		case 2:administrator();break;
		case 0:return 1;
		default:cout<<"请重新选择"<<endl;break; 
	}
	return 0;
}

//游客登录 
int visitor(){
	while(1){
		print_visitormenu();
		int a;
		cin>>a;
		switch(a){
			case 1:find();break;//1.查询景点信息
			case 2:shownum();break;//2.显示景点数量
			case 3:printall();break;//3.显示所有景点信息
			case 4:shortest_route();break;//4.查询任意两个景点间的最短路径
			case 5:all_route();break;//5.查询任意两个景点间的所有路径
			case 0:return 1;//0.退出登录 
			default:cout<<"请重新选择"<<endl;break; 
		}
	}
	return 0; 
}

//打印游客菜单
void print_visitormenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      欢迎使用本套校园导游系统                  |\n");
	printf("			|                     1.查询景点信息                             |\n");
	printf("			|                     2.显示景点数量                             |\n");
	printf("			|                     3.显示所有景点信息                         |\n");
	printf("			|                     4.查询任意两个景点间的最短路径             |\n");
	printf("			|                     5.查询任意两个景点间的所有路径             |\n");
	printf("			|                     0.退出登录                                 |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
}

//管理员登录 
int administrator(){
	string s;
	cout<<"请输入管理员密码"<<endl;
	while(cin>>s){
		if(s!=password)cout<<"密码错误，请重新输入管理员密码"<<endl;
		else{
			cout<<"密码正确"<<endl;
			break; 
		}
	}
	while(1){
		print_administratormenu();
		int a;
		cin>>a;
		switch(a){
			case 1:add();break;//1.添加景点信息 
			case 2:add_edge();break;//2.添加边 
			case 3:Delete();break;//3.删除景点信息
			case 4:delete_edge();break;//4.删除边 
			case 5:update();break;//5.修改景点信息
			case 6:find();break;//6.查询景点信息
			case 7:shownum();break;//7.显示景点数量
			case 8:printall();break;//8.显示所有景点信息
			case 9:shortest_route();break;//9.查询任意两个景点间的最短路径
			case 10:all_route();break;//10.查询任意两个景点间的所有路径
			case 11:update_password();return 1;break;//11.修改管理员密码 
//			case 12:coutmap();break;
//			case 13:change();break; 
			case 0:return 1;//0.退出登录 
			default:cout<<"请重新选择"<<endl;break; 
		}
	}
	return 0;
}

//打印管理员菜单
void print_administratormenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      欢迎使用本套校园导游系统                  |\n");
	printf("			|                     1.添加景点信息                             |\n");
	printf("			|                     2.添加边                                   |\n");
	printf("			|                     3.删除景点信息                             |\n");
	printf("			|                     4.删除边                                   |\n");
	printf("			|                     5.修改景点信息                             |\n");
	printf("			|                     6.查询景点信息                             |\n");
	printf("			|                     7.显示景点数量                             |\n");
	printf("			|                     8.显示所有景点信息                         |\n");
	printf("			|                     9.查询任意两个景点间的最短路径             |\n");
	printf("			|                     10.查询任意两个景点间的所有路径            |\n");
	printf("			|                     11.修改管理员密码                          |\n");
//	printf("			|                     12.coutmap()                               |\n");
//	printf("			|                     13.change()                                |\n");
	printf("			|                     0.退出登录                                 |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
}

//添加景点 
void add(){
	string id,name,jianjie;
	cout<<"请输入要添加的景点编号"<<endl;
	cin>>id;
	cout<<"请输入要添加的景点名称"<<endl;
	cin>>name;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==name||i->id==id){
			cout<<"已有该景点信息，请勿重复添加"<<endl;
			return ;
		}
	}
	cnt++;
	cout<<"请输入要添加的景点简介"<<endl;
	cin>>jianjie;
	id_name[id]=name;
	name_id[name]=id;
	m.push_back({id,name,jianjie});
	return ; 
}

//添加边菜单
void add_edgemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择添加边的方式                         |\n");
	printf("			|                       1.按照编号添加                           |\n");
	printf("			|                       2.按照名称添加                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
	return ; 
}

//添加边
void add_edge(){
	cout<<"请输入添加方式"<<endl;
	add_edgemenu();
	int a;
	while(cin>>a){
		if(a==1){//按编号添加 
			string x,y; 
			cout<<"请输入起点编号，终点编号和距离"<<endl;
			cin>>x>>y>>a;
			while(x==y){//起点和终点相同 
				cout<<"输入非法，请重新输入起点和终点"<<endl;
				cin>>x>>y; 
			}
			int flag=0;
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->id==x)flag++;
				else if(i->id==y)flag++;
			}
			if(flag==2){//起点，终点都在 
				edge.push_back({id_name[x],id_name[y],a});
				cout<<"添加成功"<<endl;
			}
			else cout<<"添加失败";
			return ;
		}
		else if(a==2){//按名称添加 
			string x,y;
			cout<<"请输入起点名称，终点名称和距离"<<endl;
			cin>>x>>y>>a;
			while(x==y){//起点和终点相同
				cout<<"输入非法，请重新输入起点和终点"<<endl;
				cin>>x>>y;
			}
			int flag=0;
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->name==x)flag++;
				else if(i->name==y)flag++;
			}
			if(flag==2){//起点，终点都在
				edge.push_back({x,y,a});
				cout<<"添加成功"<<endl;
			}
			else cout<<"添加失败";
			return ;
		} 
		else if(a==0)return ;
		else cout<<"请重新选择"<<endl;
	}
	return ;
}

//删除边菜单
void delete_edgemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择删除边的方式                         |\n");
	printf("			|                       1.按照编号删除                           |\n");
	printf("			|                       2.按照名称删除                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
	return ;
}

//删除边
void delete_edge(){
	cout<<"请输入删除方式"<<endl;
	delete_edgemenu();
	int a;
	while(cin>>a){
		if(a==1){//按编号删除 
			string x,y; 
			int flag=0;
			cout<<"请输入起点编号，终点编号"<<endl;
			cin>>x>>y;
			for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
				if(name_id[i->begin]==x&&name_id[i->end]==y||name_id[i->begin]==y&&name_id[i->end]==x){//无向图 
					edge.erase(i);
					cout<<"删除成功"<<endl;
					return ;	
				}
			}
			cout<<"删除失败"<<endl;
			return ;
		}
		else if(a==2){//按名称删除 
			int flag=0;
			string x,y; 
			cout<<"请输入起点名称，终点名称"<<endl;
			cin>>x>>y;
			for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
				if(i->begin==x&&i->end==y||i->begin==y&&i->end==x){
					edge.erase(i);
					cout<<"删除成功"<<endl;
					return ;
				}
			}
			cout<<"删除失败"<<endl;
			return ;
		} 
		else if(a==0)return ;
		else cout<<"请重新选择"<<endl;
	}
	return ;
}

//删除景点 
void Delete(){
	int a;
	print_deletemenu();
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"请重新选择删除方式"<<endl;
		cin>>a;
	}
	if(a==1){//按编号删除景点 
		int flag=delete_id();
		if(flag==1)cout<<"删除失败，未查询到该景点"<<endl;//删除失败
		else if(flag==0)cout<<"删除成功"<<endl;
		return ;
	}
	else if(a==2){//按名称删除景点
		int flag=delete_name();
		if(flag==1)cout<<"删除失败，未查询到该景点"<<endl;//删除失败
		else if(flag==0)cout<<"删除成功"<<endl;
		return ;
	}
	else if(a==0)return ;
}

//打印删除菜单 
void print_deletemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择删除景点的方式                       |\n");
	printf("			|                       1.按照编号删除                           |\n");
	printf("			|                       2.按照名称删除                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//按编号删除 
int delete_id(){
	string a;
	cout<<"请输入要删除景点的编号"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){//有这个顶点 
			name_id.erase(i->name);
			id_name.erase(i->id);
			for(vector<Edge>::iterator j=edge.begin();j!=edge.end();j++){//删除边 
				if(j->begin==i->name||j->end==i->name)edge.erase(j);
			}
			m.erase(i);//删除结点 
			cnt--;//景点数-1 
			return 0;//删除成功 
		}
	}
	return 1;//删除失败	
}

//按名称删除
int delete_name(){
	string s;
	cout<<"请输入要删除景点的名称"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			name_id.erase(i->name);
			id_name.erase(i->id);
			for(vector<Edge>::iterator j=edge.begin();j!=edge.end();j++){//删除边 
				if(j->begin==i->name||j->end==i->name)edge.erase(j);
			}
			m.erase(i);
			cnt--;
			return 0;//删除成功 
		}
	}
	return 1;//删除失败	
}

//修改信息函数
void update(){
	int a;
	update_menu();
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"请重新选择修改方式"<<endl;
		cin>>a;
	}
	if(a==1){//按编号修改景点 
		int flag=update_id();
		if(flag==1)cout<<"修改失败，未查询到该景点"<<endl;//修改失败
		return ;
	}
	else if(a==2){//按名称修改景点
		int flag=update_name();
		if(flag==1)cout<<"修改失败，未查询到该景点"<<endl;//修改失败
		return ;
	}
	else if(a==0)return ;
}

//打印修改菜单
void update_menu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择修改景点的方式                       |\n");
	printf("			|                       1.按照编号修改                           |\n");
	printf("			|                       2.按照名称修改                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//打印修改方式菜单 
void update_menu2(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择要修改景点的内容                     |\n");
	printf("			|                        1.修改名称                              |\n");
	printf("			|                        2.修改简介                              |\n");
	printf("			|                        3.修改编号                              |\n");
	printf("			|                        0.返回主菜单                            |\n");
	printf("			==================================================================\n");
	puts("");
}

//按编号更新
int update_id(){
	string a;
	cout<<"请输入要修改景点的编号"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){
			update_menu2(); 
			int x;
			string s;
			while(cin>>x){
				if(x==0)return 0;
				else if(x==1){//修改名称 
					cout<<"请输入修改后的名称"<<endl; 
					cin>>s;
					name_id.erase(i->name);
					id_name[a]=s;
					name_id[s]=a;
					i->name=s;
					cout<<"修改成功"<<endl;
					return 0;
				}
				else if(x==2){//修改简介 
					cout<<"请输入修改后的简介"<<endl; 
					cin>>s;
					i->jianjie=s;
					cout<<"修改成功"<<endl;
					return 0;
				}
				else if(x==3){//修改编号 
					cout<<"请输入修改后的编号"<<endl; 
					id_name.erase(a);
					cin>>s;
					i->id=s;
					name_id[i->name]=s;
					id_name[s]=i->name;
					cout<<"修改成功"<<endl;
					return 0; 
				}
				else cout<<"请重新选择"<<endl;
			}	
		}
	}
	return 1;//修改失败
}

//按名称更新
int update_name(){
	string s;
	cout<<"请输入要修改景点的名称"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			update_menu2(); 
			int x;
			while(cin>>x){
				if(x==0)return 0;
				else if(x==1){//修改名称 
					cout<<"请输入修改后的名称"<<endl;
					name_id.erase(s);
					cin>>s;
					id_name[i->id]=s;
					name_id[s]=i->id;
					i->name=s;
					cout<<"修改成功"<<endl;
					return 0;
				}
				else if(x==2){//修改简介 
					cout<<"请输入修改后的简介"<<endl; 
					cin>>s;
					i->jianjie=s;
					cout<<"修改成功"<<endl;
					return 0;
				}
				else if(x==3){//修改编号 
					cout<<"请输入修改后的编号"<<endl; 
					name_id.erase(s);
					cin>>s;
					i->id=s;
					name_id[i->name]=s;
					id_name[s]=i->name;
					cout<<"修改成功"<<endl;
					return 0; 
				}
				else cout<<"请重新选择"<<endl;
			}	
		}
	}
	return 1;//修改失败
}

//查询景点 
void find(){
	print_findmenu();
	int a;
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"请重新选择查询方式"<<endl;
		cin>>a;
	}
	if(a==1){//按编号名称查询景点 
		int flag=find_id();
		if(flag==0)cout<<"查询失败，未找到此景点"<<endl;
		return ;
	}
	else if(a==2){//按名称查询景点 
		int flag=find_name();
		if(flag==0)cout<<"查询失败，未找到此景点"<<endl;
		return ;
	}
	if(a==0)return;
}

//打印查询菜单
void print_findmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择查询景点的方式                       |\n");
	printf("			|                       1.按照编号查询                           |\n");
	printf("			|                       2.按照名称查询                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//按编号查询
int find_id(){
	string a;
	cout<<"请输入要查询的景点编号"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){
			cout<<endl<<"查询成功"<<endl<<"该景点的信息为："<<endl;
			cout<<"编号："<<i->id<<endl; 
			cout<<"名称："<<i->name<<endl; 
			cout<<"简介："<<i->jianjie<<endl<<endl; 
			return 1;//查询成功 
		}
	}
	return 0;
}

//按名称查询
int find_name(){
	string s;
	cout<<"请输入要查询的景点名称"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			cout<<endl<<"查询成功"<<endl<<"该景点的信息为："<<endl;
			cout<<"编号："<<i->id<<endl; 
			cout<<"名称："<<i->name<<endl; 
			cout<<"简介："<<i->jianjie<<endl<<endl; 
			return 1;//查询成功 
		}
	}
	return 0;
}

//查询路径菜单 
void print_findroadmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     请选择查询路径的方式                       |\n");
	printf("			|                       1.按照编号查询                           |\n");
	printf("			|                       2.按照名称查询                           |\n");
	printf("			|                       0.返回上一级                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//最短路
void shortest_route(){
	change();//创建邻接矩阵 
	print_findroadmenu();
	int a;
	while(cin>>a){
		if(a==0)return ;
		else if(a==1){//按编号查询 
		int flag=0;
			string x,y;
			cout<<"请输入起点和终点编号"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"非法输入，请重新输入"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->id==x)flag++;
				else if(i->id==y)flag++;
			}
			if(flag==2)getShortest_routeid(x,y);
			else {
				cout<<"景点不存在，请重新查询"<<endl;
			}
			return ;
		}
		else if(a==2){//按名称查询 
		int flag=0;
			string x,y;
			cout<<"请输入起点和终点名称"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"非法输入，请重新输入"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->name==x)flag++;
				else if(i->name==y)flag++;
			}
			if(flag==2)getShortest_routename(x,y);
			else {
				cout<<"景点不存在，请重新查询"<<endl;
			}
			return ;
		}
		else cout<<"请重新选择"<<endl;
	}
	return ;
}
 
//查询x到y的最短路(名称)
void getShortest_routename(string x,string y){
	stack<int> road;//存路径 
	int dis[cnt+5],min,u,book[cnt+5],pre[cnt+5 ];//距离数组
	for(int i=1;i<=cnt;i++)dis[i]=graph[name_xiabiao[x]][i];//初始化距离
	for(int i=1;i<=cnt;i++)book[i]=0;//初始化book数组
	for(int i=1;i<=cnt;i++)pre[i]=0;//初始化pre数组
	book[name_xiabiao[x]]=1; 
	for(int i=1;i<cnt;i++){//找另外cnt-1个点的最短路 
		int min=999999;
		u=name_xiabiao[x];
		for(int j=1;j<=cnt;j++){//找剩下最近的点 
			if(book[j]==0&&dis[j]!=-1&&dis[j]<min){
				min=dis[j];
				u=j;//最近的点
			}
		}
		book[u]=1; 
		if(u==name_xiabiao[x])break;
		if(u==name_xiabiao[y])break;//找到直接break 
		//用最近的点松弛其他点
		for(int j=1;j<=cnt;j++){//j是被松弛的点 
			if(graph[u][j]!=-1){
				if(dis[j]==-1||dis[j]>dis[u]+graph[u][j]){
					dis[j]=dis[u]+graph[u][j];//更新边权 
					pre[j]=u;//j是被u松弛的 
					if(j==name_xiabiao[y]){//j是终点的话，记录路径 
						int z=j;
						while(pre[z]!=0){
							road.push(pre[z]);
							z=pre[z];
						}
					}
				}
			}
		}
	}
	if(dis[name_xiabiao[y]]!=-1){
		cout<<"最短路径长度为："<<dis[name_xiabiao[y]]<<endl;
		cout<<"最短路径路径为："<<x<<"-->";
		while(!road.empty()){//栈不空 
			cout<<xiabiao_name[road.top()]<<"-->";
			road.pop();
		}
		cout<<y<<endl;
	}
	else cout<<"两景点不连通"<<endl; 
	return ;
}

//查询x到y的最短路(编号)
void getShortest_routeid(string x,string y){
	stack<int> road;//存路径 
	int dis[cnt+5],min,u,book[cnt+5],pre[cnt+5];//距离数组
	for(int i=1;i<=cnt;i++)dis[i]=graph[name_xiabiao[id_name[x]]][i];//初始化距离
	for(int i=1;i<=cnt;i++)book[i]=0;//初始化book数组
	for(int i=1;i<=cnt;i++)pre[i]=0;//初始化pre数组
	book[name_xiabiao[id_name[x]]]=1; 
	for(int i=1;i<cnt;i++){//找另外cnt-1个点的最短路 
		int min=999999;
		for(int j=1;j<=cnt;j++){//找剩下最近的点 
			if(book[j]==0&&dis[j]!=-1&&dis[j]<min){
				min=dis[j];
				u=j;//最近的点
			}
		}
		book[u]=1; 
		if(u==name_xiabiao[id_name[x]])break;
		if(u==name_xiabiao[id_name[y]])break;//找到直接break 
		//用最近的点松弛其他点
		for(int j=1;j<=cnt;j++){//j是被松弛的点 
			if(graph[u][j]!=-1){
				if(dis[j]==-1||dis[j]>dis[u]+graph[u][j]){
					dis[j]=dis[u]+graph[u][j];//更新边权 
					pre[j]=u;//j是被u松弛的 
					if(j==name_xiabiao[id_name[y]]){//j是终点的话，记录路径 
						int z=j;
						while(pre[z]!=0){
							road.push(pre[z]);
							z=pre[z];
						}
					}
				}
			}
		}
	}
	
	if(dis[name_xiabiao[id_name[y]]]!=-1){
		cout<<"最短路径长度为："<<dis[name_xiabiao[id_name[y]]]<<endl;
		cout<<"最短路径路径为："<<id_name[x]<<"-->";
		while(!road.empty()){//栈不空 
			cout<<xiabiao_name[road.top()]<<"-->";
			road.pop();
		}
		cout<<id_name[y]<<endl;
	}
	else cout<<"两景点不连通"<<endl; 
	return ;
}

//所有路径
void all_route(){//dfs求解
	change();
	print_findmenu();
	memset(mark,0,sizeof(mark));
	int a;
	while(cin>>a){
		if(a==0)return ;
		else if(a==1){//按编号查询 
			int flag=0;
			string x,y;
			cout<<"请输入起点和终点编号"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"非法输入，请重新输入"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->id==x)flag++;
				else if(i->id==y)flag++;
			}
			if(flag==2){
				mark[name_xiabiao[id_name[x]]]=1;
				road[0]=name_xiabiao[id_name[x]];
				getall_routeid(x,y,name_xiabiao[id_name[x]],0,1);
			}
			else {
				cout<<"景点不存在，请重新查询"<<endl;
			}
			return ;
		}
		else if(a==2){//按名称查询 
		int flag=0;
			string x,y;
			cout<<"请输入起点和终点名称"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"非法输入，请重新输入"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->name==x)flag++;
				else if(i->name==y)flag++;
			}
			if(flag==2){
				mark[name_xiabiao[x]]=1;
				road[0]=name_xiabiao[x];
				getall_routename(x,y,name_xiabiao[x],0,1);
			}
			else {
				cout<<"景点不存在，请重新查询"<<endl;
			}
			return ;
		}
		else{
			cout<<"请重新选择"<<endl;
			cin>>a; 
		} 
	}
	return ;
}

//查询x到y的所有路径(编号)
void getall_routeid(string x,string y,int s,int sum,int z){
	if(road[z-1]==name_xiabiao[id_name[y]]){//到达终点，输出距离和路径 
		cout<<"路径："<<xiabiao_name[s]<<"-->";
		for(int i=1;i<z-1;i++){
			cout<<xiabiao_name[road[i]]<<"-->";
		}
		cout<<id_name[y]<<endl;
		cout<<"距离为："<<sum<<endl<<endl;
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(mark[i]==0&&graph[name_xiabiao[id_name[x]]][i]!=-1){//能到达下一个点 
			mark[i]=1;
			road[z]=i; 
			getall_routeid(name_id[xiabiao_name[i]],y,s,sum+graph[name_xiabiao[id_name[x]]][i],z+1);
			mark[i]=0;
		}
	}
	return ;
}

//查询x到y的所有路径(名称)
void getall_routename(string x,string y,int s,int sum,int z){
	if(road[z-1]==name_xiabiao[y]){//到达终点，输出距离和路径 
		cout<<"路径："<<xiabiao_name[s]<<"-->";
		for(int i=1;i<z-1;i++){
			cout<<xiabiao_name[road[i]]<<"-->";
		}
		cout<<y<<endl;
		cout<<"距离为："<<sum<<endl<<endl;
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(mark[i]==0&&graph[name_xiabiao[x]][i]!=-1){//能到达下一个点 
			mark[i]=1;
			road[z]=i; 
			getall_routename(xiabiao_name[i],y,s,sum+graph[name_xiabiao[x]][i],z+1);
			mark[i]=0;
		}
	}
	return ;
}

//显示景点数量
void shownum(){
	cout<<"当前景点数量为："<<cnt<<endl;
	return ; 
}

//打印所有景点信息 
void printall(){
	if(m.size()==0){
		cout<<"当前系统中未存放景点信息"<<endl;
		return ; 
	}
	cout<<"所有景点信息如下"<<endl;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		cout<<i->id<<"  "<<i->name<<"  "<<i->jianjie<<endl; 
	}
	return ;
}

//修改管理员密码 
void update_password(){
	int x=0;
	string s;
	cout<<"请输入初始密码"<<endl;
	while(cin>>s){
		if(s==password){
			cout<<"请输入修改后的密码"<<endl;
			cin>>password;
			cout<<"修改成功，请从新登录"<<endl;
			return ;//修改成功 
		}
		cout<<"密码错误，请重新输入"<<endl;
		x++;
		if(x>=5){
			cout<<"密码错误次数过多，请从新登录"<<endl;
			return ;
		}
	}
	return ;
}


void coutmap(){//输出map 
	for(map<string,string>::iterator i=name_id.begin();i!=name_id.end();i++){
		cout<<i->first<<"  "<<i->second<<endl;
	}
	cout<<endl;
	for(map<string,string>::iterator i=id_name.begin();i!=id_name.end();i++){
		cout<<i->first<<"  "<<i->second<<endl;
	}
	cout<<endl;
}

//将vector转换成邻接矩阵 
void change(){
	for(int i=0;i<m.size();i++){
		xiabiao_name[i+1]=m[i].name;//下标对应名字 
		name_xiabiao[m[i].name]=i+1;//名字对应下标 
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<xiabiao_name[i]<<" ";
//	}
//	cout<<endl;
	//初始化邻接矩阵 
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(i==j)graph[i][j]=0;
			else graph[i][j]=-1;//无法到达
		}
	}
	for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
		graph[name_xiabiao[i->begin]][name_xiabiao[i->end]]=i->w;
		graph[name_xiabiao[i->end]][name_xiabiao[i->begin]]=i->w;
	}
	
//	//输出邻接矩阵 
//	for(int i=1;i<=cnt;i++){
//		for(int j=1;j<=cnt;j++){
//			cout<<graph[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
	return ; 
}

//读取文件
void readfile(){
	ifstream fin("Attraction information.txt");
	if(fin.is_open()==false){
		ofstream fout("Attraction information.txt");//如果打开失败，就创建一个 
		fout.close();
	}
	else{
		int x,y,w;
		string id,name,jianjie,s,begin,end;
		fin>>cnt;
		x=cnt;
		while(x--){//读景点信息 
			fin>>id>>name>>jianjie;
			m.push_back({id,name,jianjie});
			id_name[id]=name;
			name_id[name]=id;
		}
		fin>>y;//边的数量 
		while(y--){
			fin>>begin>>end>>w;
			edge.push_back({begin,end,w});
		}
		fin>>password;
//		cout<<password<<endl;
//		for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
//			cout<<i->id<<"  "<<i->name<<"  "<<i->jianjie<<endl;
//		}

	}
}

//写入文件
void writefile(){
	FILE *pf=fopen("Attraction information.txt","w");
	fprintf(pf,"%d\n",cnt);
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		string s=i->id,x=i->name,y=i->jianjie;
		char arr1[s.size()+1],arr2[x.size()+1],arr3[y.size()+1];//将string转成char类型,方便输出 
		strcpy(arr1,s.c_str());
		strcpy(arr2,x.c_str());
		strcpy(arr3,y.c_str());
		fprintf(pf,"%s  %s  %s\n",arr1,arr2,arr3);
	}
	fprintf(pf,"%d\n",edge.size());
	for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
		string s=i->begin,x=i->end;
		int w=i->w;
		char arr1[s.size()+1],arr2[x.size()+1];//将string转成char类型,方便输出 
		strcpy(arr1,s.c_str());
		strcpy(arr2,x.c_str());
		fprintf(pf,"%s  %s  %d\n",arr1,arr2,w);
	}
	char pw[password.size()+1];
	strcpy(pw,password.c_str());
	fprintf(pf,"%s\n",pw);
	fclose(pf);
}


