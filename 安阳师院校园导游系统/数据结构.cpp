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

struct Information{//������Ϣ
	string id,name,jianjie;
};

struct Edge{//����Ϣ 
	string begin,end;
	int w;
};

int graph[MAX][MAX],cnt,mark[MAX],road[MAX];//�ڽӾ���  ��������

string password="123456789";
vector<Information> m;//�澰����Ϣ
vector<Edge> edge;//���
map<string,int> name_xiabiao; //���澰�����ƺ��±��Ӧ��ϵ
map<int,string> xiabiao_name; //�����±�;������ƶ�Ӧ��ϵ
map<string,string> id_name,name_id;//�����ź;������ƶ�Ӧ��ϵ 
 
int choose_way();//ѡ���½��ʽ 
void print_loginmenu();//��ӡ��½�˵� 
int visitor();//�ο͵�¼ 
void print_visitormenu();//��ӡ�˵� 
int administrator();//����Ա��¼ 
void print_administratormenu();//��ӡ�˵� 
void find();//��ѯ����
void print_findmenu();//��ӡ��ѯ�˵� 
int find_id();//����Ų�ѯ
int find_name();//�����Ʋ�ѯ
void shortest_route();//���·
void all_route();//����·�� 
void getShortest_routename(string x,string y);//��ѯx��y�����·(����)
void getShortest_routeid(string x,string y);//��ѯx��y�����·(���)
void getall_routeid(string x,string y,int i,int sum,int z);//��ѯx��y������·��(���)
void getall_routename(string x,string y,int i,int sum,int z);//��ѯx��y������·��(����) 
void print_findroadmenu();//��ӡ��ѯ·���˵� 
void add();//������Ϣ���� 
void add_edge();//��ӱ�
void add_edgemenu();//��ӱ߲˵� 
void delete_edgemenu();//ɾ���߲˵� 
void delete_edge();//ɾ���� 
void Delete();//ɾ����Ϣ����
int delete_id();//�����ɾ�� 
int delete_name();//������ɾ�� 
void update();//������Ϣ����
int update_id();//����Ÿ���
int update_name();//�����Ƹ���
void update_menu();//��ӡ�޸Ĳ˵�
void update_menu2();//��ӡ�޸ķ�ʽ�˵�
void shownum();//��ʾ�������� 
void printall();//��ӡ���о�����Ϣ 
void update_password();//�޸Ĺ���Ա���� 
void print_deletemenu();//��ӡɾ���˵�
void change();//��vector�����ݴ������ڽӾ��� 
void coutmap();
void readfile();//��ȡ�ļ� 
void writefile();//д���ļ� 

int main(){
	readfile();//��ȡ�ļ�
//	system("aynu.jpg");//����У԰��ͼ ������һ��ͼƬ��
//	system("123.png");//����У԰��ͼ ������һ��ͼƬ��
	while(1){
		print_loginmenu();
		
		if(choose_way()==1){//�˳�ϵͳ 
			cout<<"��л��ʹ�ñ�ϵͳ"<<endl;
			writefile();//д���ļ�
			return 0;
		}
	}
	return 0;
}


//��¼�˵�
void print_loginmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      ��ӭʹ�ñ���У԰����ϵͳ                  |\n");
	printf("			|                      1.�ο͵�¼                                |\n");
	printf("			|                      2.����Ա��¼                              |\n");
	printf("			|                      0.�˳�ϵͳ                                |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
} 

//ѡ���½��ʽ
int choose_way(){
	int a;
	cin>>a;
	switch(a){//ѡ���½��ʽ 
		case 1:visitor();break;
		case 2:administrator();break;
		case 0:return 1;
		default:cout<<"������ѡ��"<<endl;break; 
	}
	return 0;
}

//�ο͵�¼ 
int visitor(){
	while(1){
		print_visitormenu();
		int a;
		cin>>a;
		switch(a){
			case 1:find();break;//1.��ѯ������Ϣ
			case 2:shownum();break;//2.��ʾ��������
			case 3:printall();break;//3.��ʾ���о�����Ϣ
			case 4:shortest_route();break;//4.��ѯ�����������������·��
			case 5:all_route();break;//5.��ѯ������������������·��
			case 0:return 1;//0.�˳���¼ 
			default:cout<<"������ѡ��"<<endl;break; 
		}
	}
	return 0; 
}

//��ӡ�οͲ˵�
void print_visitormenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      ��ӭʹ�ñ���У԰����ϵͳ                  |\n");
	printf("			|                     1.��ѯ������Ϣ                             |\n");
	printf("			|                     2.��ʾ��������                             |\n");
	printf("			|                     3.��ʾ���о�����Ϣ                         |\n");
	printf("			|                     4.��ѯ�����������������·��             |\n");
	printf("			|                     5.��ѯ������������������·��             |\n");
	printf("			|                     0.�˳���¼                                 |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
}

//����Ա��¼ 
int administrator(){
	string s;
	cout<<"���������Ա����"<<endl;
	while(cin>>s){
		if(s!=password)cout<<"��������������������Ա����"<<endl;
		else{
			cout<<"������ȷ"<<endl;
			break; 
		}
	}
	while(1){
		print_administratormenu();
		int a;
		cin>>a;
		switch(a){
			case 1:add();break;//1.��Ӿ�����Ϣ 
			case 2:add_edge();break;//2.��ӱ� 
			case 3:Delete();break;//3.ɾ��������Ϣ
			case 4:delete_edge();break;//4.ɾ���� 
			case 5:update();break;//5.�޸ľ�����Ϣ
			case 6:find();break;//6.��ѯ������Ϣ
			case 7:shownum();break;//7.��ʾ��������
			case 8:printall();break;//8.��ʾ���о�����Ϣ
			case 9:shortest_route();break;//9.��ѯ�����������������·��
			case 10:all_route();break;//10.��ѯ������������������·��
			case 11:update_password();return 1;break;//11.�޸Ĺ���Ա���� 
//			case 12:coutmap();break;
//			case 13:change();break; 
			case 0:return 1;//0.�˳���¼ 
			default:cout<<"������ѡ��"<<endl;break; 
		}
	}
	return 0;
}

//��ӡ����Ա�˵�
void print_administratormenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                      ��ӭʹ�ñ���У԰����ϵͳ                  |\n");
	printf("			|                     1.��Ӿ�����Ϣ                             |\n");
	printf("			|                     2.��ӱ�                                   |\n");
	printf("			|                     3.ɾ��������Ϣ                             |\n");
	printf("			|                     4.ɾ����                                   |\n");
	printf("			|                     5.�޸ľ�����Ϣ                             |\n");
	printf("			|                     6.��ѯ������Ϣ                             |\n");
	printf("			|                     7.��ʾ��������                             |\n");
	printf("			|                     8.��ʾ���о�����Ϣ                         |\n");
	printf("			|                     9.��ѯ�����������������·��             |\n");
	printf("			|                     10.��ѯ������������������·��            |\n");
	printf("			|                     11.�޸Ĺ���Ա����                          |\n");
//	printf("			|                     12.coutmap()                               |\n");
//	printf("			|                     13.change()                                |\n");
	printf("			|                     0.�˳���¼                                 |\n");
	printf("			|                                                                |\n");
	printf("			==================================================================\n");
	puts("");
}

//��Ӿ��� 
void add(){
	string id,name,jianjie;
	cout<<"������Ҫ��ӵľ�����"<<endl;
	cin>>id;
	cout<<"������Ҫ��ӵľ�������"<<endl;
	cin>>name;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==name||i->id==id){
			cout<<"���иþ�����Ϣ�������ظ����"<<endl;
			return ;
		}
	}
	cnt++;
	cout<<"������Ҫ��ӵľ�����"<<endl;
	cin>>jianjie;
	id_name[id]=name;
	name_id[name]=id;
	m.push_back({id,name,jianjie});
	return ; 
}

//��ӱ߲˵�
void add_edgemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ����ӱߵķ�ʽ                         |\n");
	printf("			|                       1.���ձ�����                           |\n");
	printf("			|                       2.�����������                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
	return ; 
}

//��ӱ�
void add_edge(){
	cout<<"��������ӷ�ʽ"<<endl;
	add_edgemenu();
	int a;
	while(cin>>a){
		if(a==1){//�������� 
			string x,y; 
			cout<<"����������ţ��յ��ź;���"<<endl;
			cin>>x>>y>>a;
			while(x==y){//�����յ���ͬ 
				cout<<"����Ƿ������������������յ�"<<endl;
				cin>>x>>y; 
			}
			int flag=0;
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->id==x)flag++;
				else if(i->id==y)flag++;
			}
			if(flag==2){//��㣬�յ㶼�� 
				edge.push_back({id_name[x],id_name[y],a});
				cout<<"��ӳɹ�"<<endl;
			}
			else cout<<"���ʧ��";
			return ;
		}
		else if(a==2){//��������� 
			string x,y;
			cout<<"������������ƣ��յ����ƺ;���"<<endl;
			cin>>x>>y>>a;
			while(x==y){//�����յ���ͬ
				cout<<"����Ƿ������������������յ�"<<endl;
				cin>>x>>y;
			}
			int flag=0;
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->name==x)flag++;
				else if(i->name==y)flag++;
			}
			if(flag==2){//��㣬�յ㶼��
				edge.push_back({x,y,a});
				cout<<"��ӳɹ�"<<endl;
			}
			else cout<<"���ʧ��";
			return ;
		} 
		else if(a==0)return ;
		else cout<<"������ѡ��"<<endl;
	}
	return ;
}

//ɾ���߲˵�
void delete_edgemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ��ɾ���ߵķ�ʽ                         |\n");
	printf("			|                       1.���ձ��ɾ��                           |\n");
	printf("			|                       2.��������ɾ��                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
	return ;
}

//ɾ����
void delete_edge(){
	cout<<"������ɾ����ʽ"<<endl;
	delete_edgemenu();
	int a;
	while(cin>>a){
		if(a==1){//�����ɾ�� 
			string x,y; 
			int flag=0;
			cout<<"����������ţ��յ���"<<endl;
			cin>>x>>y;
			for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
				if(name_id[i->begin]==x&&name_id[i->end]==y||name_id[i->begin]==y&&name_id[i->end]==x){//����ͼ 
					edge.erase(i);
					cout<<"ɾ���ɹ�"<<endl;
					return ;	
				}
			}
			cout<<"ɾ��ʧ��"<<endl;
			return ;
		}
		else if(a==2){//������ɾ�� 
			int flag=0;
			string x,y; 
			cout<<"������������ƣ��յ�����"<<endl;
			cin>>x>>y;
			for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
				if(i->begin==x&&i->end==y||i->begin==y&&i->end==x){
					edge.erase(i);
					cout<<"ɾ���ɹ�"<<endl;
					return ;
				}
			}
			cout<<"ɾ��ʧ��"<<endl;
			return ;
		} 
		else if(a==0)return ;
		else cout<<"������ѡ��"<<endl;
	}
	return ;
}

//ɾ������ 
void Delete(){
	int a;
	print_deletemenu();
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"������ѡ��ɾ����ʽ"<<endl;
		cin>>a;
	}
	if(a==1){//�����ɾ������ 
		int flag=delete_id();
		if(flag==1)cout<<"ɾ��ʧ�ܣ�δ��ѯ���þ���"<<endl;//ɾ��ʧ��
		else if(flag==0)cout<<"ɾ���ɹ�"<<endl;
		return ;
	}
	else if(a==2){//������ɾ������
		int flag=delete_name();
		if(flag==1)cout<<"ɾ��ʧ�ܣ�δ��ѯ���þ���"<<endl;//ɾ��ʧ��
		else if(flag==0)cout<<"ɾ���ɹ�"<<endl;
		return ;
	}
	else if(a==0)return ;
}

//��ӡɾ���˵� 
void print_deletemenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ��ɾ������ķ�ʽ                       |\n");
	printf("			|                       1.���ձ��ɾ��                           |\n");
	printf("			|                       2.��������ɾ��                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//�����ɾ�� 
int delete_id(){
	string a;
	cout<<"������Ҫɾ������ı��"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){//��������� 
			name_id.erase(i->name);
			id_name.erase(i->id);
			for(vector<Edge>::iterator j=edge.begin();j!=edge.end();j++){//ɾ���� 
				if(j->begin==i->name||j->end==i->name)edge.erase(j);
			}
			m.erase(i);//ɾ����� 
			cnt--;//������-1 
			return 0;//ɾ���ɹ� 
		}
	}
	return 1;//ɾ��ʧ��	
}

//������ɾ��
int delete_name(){
	string s;
	cout<<"������Ҫɾ�����������"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			name_id.erase(i->name);
			id_name.erase(i->id);
			for(vector<Edge>::iterator j=edge.begin();j!=edge.end();j++){//ɾ���� 
				if(j->begin==i->name||j->end==i->name)edge.erase(j);
			}
			m.erase(i);
			cnt--;
			return 0;//ɾ���ɹ� 
		}
	}
	return 1;//ɾ��ʧ��	
}

//�޸���Ϣ����
void update(){
	int a;
	update_menu();
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"������ѡ���޸ķ�ʽ"<<endl;
		cin>>a;
	}
	if(a==1){//������޸ľ��� 
		int flag=update_id();
		if(flag==1)cout<<"�޸�ʧ�ܣ�δ��ѯ���þ���"<<endl;//�޸�ʧ��
		return ;
	}
	else if(a==2){//�������޸ľ���
		int flag=update_name();
		if(flag==1)cout<<"�޸�ʧ�ܣ�δ��ѯ���þ���"<<endl;//�޸�ʧ��
		return ;
	}
	else if(a==0)return ;
}

//��ӡ�޸Ĳ˵�
void update_menu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ���޸ľ���ķ�ʽ                       |\n");
	printf("			|                       1.���ձ���޸�                           |\n");
	printf("			|                       2.���������޸�                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//��ӡ�޸ķ�ʽ�˵� 
void update_menu2(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ��Ҫ�޸ľ��������                     |\n");
	printf("			|                        1.�޸�����                              |\n");
	printf("			|                        2.�޸ļ��                              |\n");
	printf("			|                        3.�޸ı��                              |\n");
	printf("			|                        0.�������˵�                            |\n");
	printf("			==================================================================\n");
	puts("");
}

//����Ÿ���
int update_id(){
	string a;
	cout<<"������Ҫ�޸ľ���ı��"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){
			update_menu2(); 
			int x;
			string s;
			while(cin>>x){
				if(x==0)return 0;
				else if(x==1){//�޸����� 
					cout<<"�������޸ĺ������"<<endl; 
					cin>>s;
					name_id.erase(i->name);
					id_name[a]=s;
					name_id[s]=a;
					i->name=s;
					cout<<"�޸ĳɹ�"<<endl;
					return 0;
				}
				else if(x==2){//�޸ļ�� 
					cout<<"�������޸ĺ�ļ��"<<endl; 
					cin>>s;
					i->jianjie=s;
					cout<<"�޸ĳɹ�"<<endl;
					return 0;
				}
				else if(x==3){//�޸ı�� 
					cout<<"�������޸ĺ�ı��"<<endl; 
					id_name.erase(a);
					cin>>s;
					i->id=s;
					name_id[i->name]=s;
					id_name[s]=i->name;
					cout<<"�޸ĳɹ�"<<endl;
					return 0; 
				}
				else cout<<"������ѡ��"<<endl;
			}	
		}
	}
	return 1;//�޸�ʧ��
}

//�����Ƹ���
int update_name(){
	string s;
	cout<<"������Ҫ�޸ľ��������"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			update_menu2(); 
			int x;
			while(cin>>x){
				if(x==0)return 0;
				else if(x==1){//�޸����� 
					cout<<"�������޸ĺ������"<<endl;
					name_id.erase(s);
					cin>>s;
					id_name[i->id]=s;
					name_id[s]=i->id;
					i->name=s;
					cout<<"�޸ĳɹ�"<<endl;
					return 0;
				}
				else if(x==2){//�޸ļ�� 
					cout<<"�������޸ĺ�ļ��"<<endl; 
					cin>>s;
					i->jianjie=s;
					cout<<"�޸ĳɹ�"<<endl;
					return 0;
				}
				else if(x==3){//�޸ı�� 
					cout<<"�������޸ĺ�ı��"<<endl; 
					name_id.erase(s);
					cin>>s;
					i->id=s;
					name_id[i->name]=s;
					id_name[s]=i->name;
					cout<<"�޸ĳɹ�"<<endl;
					return 0; 
				}
				else cout<<"������ѡ��"<<endl;
			}	
		}
	}
	return 1;//�޸�ʧ��
}

//��ѯ���� 
void find(){
	print_findmenu();
	int a;
	cin>>a;
	while(a!=1&&a!=2&&a!=0){
		cout<<"������ѡ���ѯ��ʽ"<<endl;
		cin>>a;
	}
	if(a==1){//��������Ʋ�ѯ���� 
		int flag=find_id();
		if(flag==0)cout<<"��ѯʧ�ܣ�δ�ҵ��˾���"<<endl;
		return ;
	}
	else if(a==2){//�����Ʋ�ѯ���� 
		int flag=find_name();
		if(flag==0)cout<<"��ѯʧ�ܣ�δ�ҵ��˾���"<<endl;
		return ;
	}
	if(a==0)return;
}

//��ӡ��ѯ�˵�
void print_findmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ���ѯ����ķ�ʽ                       |\n");
	printf("			|                       1.���ձ�Ų�ѯ                           |\n");
	printf("			|                       2.�������Ʋ�ѯ                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//����Ų�ѯ
int find_id(){
	string a;
	cout<<"������Ҫ��ѯ�ľ�����"<<endl;
	cin>>a;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->id==a){
			cout<<endl<<"��ѯ�ɹ�"<<endl<<"�þ������ϢΪ��"<<endl;
			cout<<"��ţ�"<<i->id<<endl; 
			cout<<"���ƣ�"<<i->name<<endl; 
			cout<<"��飺"<<i->jianjie<<endl<<endl; 
			return 1;//��ѯ�ɹ� 
		}
	}
	return 0;
}

//�����Ʋ�ѯ
int find_name(){
	string s;
	cout<<"������Ҫ��ѯ�ľ�������"<<endl;
	cin>>s;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		if(i->name==s){
			cout<<endl<<"��ѯ�ɹ�"<<endl<<"�þ������ϢΪ��"<<endl;
			cout<<"��ţ�"<<i->id<<endl; 
			cout<<"���ƣ�"<<i->name<<endl; 
			cout<<"��飺"<<i->jianjie<<endl<<endl; 
			return 1;//��ѯ�ɹ� 
		}
	}
	return 0;
}

//��ѯ·���˵� 
void print_findroadmenu(){
	puts("");
	printf("			==================================================================\n");
	printf("			|                     ��ѡ���ѯ·���ķ�ʽ                       |\n");
	printf("			|                       1.���ձ�Ų�ѯ                           |\n");
	printf("			|                       2.�������Ʋ�ѯ                           |\n");
	printf("			|                       0.������һ��                             |\n");
	printf("			==================================================================\n");
	puts("");
}

//���·
void shortest_route(){
	change();//�����ڽӾ��� 
	print_findroadmenu();
	int a;
	while(cin>>a){
		if(a==0)return ;
		else if(a==1){//����Ų�ѯ 
		int flag=0;
			string x,y;
			cout<<"�����������յ���"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"�Ƿ����룬����������"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->id==x)flag++;
				else if(i->id==y)flag++;
			}
			if(flag==2)getShortest_routeid(x,y);
			else {
				cout<<"���㲻���ڣ������²�ѯ"<<endl;
			}
			return ;
		}
		else if(a==2){//�����Ʋ�ѯ 
		int flag=0;
			string x,y;
			cout<<"�����������յ�����"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"�Ƿ����룬����������"<<endl;
				cin>>x>>y;
			}
			for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
				if(i->name==x)flag++;
				else if(i->name==y)flag++;
			}
			if(flag==2)getShortest_routename(x,y);
			else {
				cout<<"���㲻���ڣ������²�ѯ"<<endl;
			}
			return ;
		}
		else cout<<"������ѡ��"<<endl;
	}
	return ;
}
 
//��ѯx��y�����·(����)
void getShortest_routename(string x,string y){
	stack<int> road;//��·�� 
	int dis[cnt+5],min,u,book[cnt+5],pre[cnt+5 ];//��������
	for(int i=1;i<=cnt;i++)dis[i]=graph[name_xiabiao[x]][i];//��ʼ������
	for(int i=1;i<=cnt;i++)book[i]=0;//��ʼ��book����
	for(int i=1;i<=cnt;i++)pre[i]=0;//��ʼ��pre����
	book[name_xiabiao[x]]=1; 
	for(int i=1;i<cnt;i++){//������cnt-1��������· 
		int min=999999;
		u=name_xiabiao[x];
		for(int j=1;j<=cnt;j++){//��ʣ������ĵ� 
			if(book[j]==0&&dis[j]!=-1&&dis[j]<min){
				min=dis[j];
				u=j;//����ĵ�
			}
		}
		book[u]=1; 
		if(u==name_xiabiao[x])break;
		if(u==name_xiabiao[y])break;//�ҵ�ֱ��break 
		//������ĵ��ɳ�������
		for(int j=1;j<=cnt;j++){//j�Ǳ��ɳڵĵ� 
			if(graph[u][j]!=-1){
				if(dis[j]==-1||dis[j]>dis[u]+graph[u][j]){
					dis[j]=dis[u]+graph[u][j];//���±�Ȩ 
					pre[j]=u;//j�Ǳ�u�ɳڵ� 
					if(j==name_xiabiao[y]){//j���յ�Ļ�����¼·�� 
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
		cout<<"���·������Ϊ��"<<dis[name_xiabiao[y]]<<endl;
		cout<<"���·��·��Ϊ��"<<x<<"-->";
		while(!road.empty()){//ջ���� 
			cout<<xiabiao_name[road.top()]<<"-->";
			road.pop();
		}
		cout<<y<<endl;
	}
	else cout<<"�����㲻��ͨ"<<endl; 
	return ;
}

//��ѯx��y�����·(���)
void getShortest_routeid(string x,string y){
	stack<int> road;//��·�� 
	int dis[cnt+5],min,u,book[cnt+5],pre[cnt+5];//��������
	for(int i=1;i<=cnt;i++)dis[i]=graph[name_xiabiao[id_name[x]]][i];//��ʼ������
	for(int i=1;i<=cnt;i++)book[i]=0;//��ʼ��book����
	for(int i=1;i<=cnt;i++)pre[i]=0;//��ʼ��pre����
	book[name_xiabiao[id_name[x]]]=1; 
	for(int i=1;i<cnt;i++){//������cnt-1��������· 
		int min=999999;
		for(int j=1;j<=cnt;j++){//��ʣ������ĵ� 
			if(book[j]==0&&dis[j]!=-1&&dis[j]<min){
				min=dis[j];
				u=j;//����ĵ�
			}
		}
		book[u]=1; 
		if(u==name_xiabiao[id_name[x]])break;
		if(u==name_xiabiao[id_name[y]])break;//�ҵ�ֱ��break 
		//������ĵ��ɳ�������
		for(int j=1;j<=cnt;j++){//j�Ǳ��ɳڵĵ� 
			if(graph[u][j]!=-1){
				if(dis[j]==-1||dis[j]>dis[u]+graph[u][j]){
					dis[j]=dis[u]+graph[u][j];//���±�Ȩ 
					pre[j]=u;//j�Ǳ�u�ɳڵ� 
					if(j==name_xiabiao[id_name[y]]){//j���յ�Ļ�����¼·�� 
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
		cout<<"���·������Ϊ��"<<dis[name_xiabiao[id_name[y]]]<<endl;
		cout<<"���·��·��Ϊ��"<<id_name[x]<<"-->";
		while(!road.empty()){//ջ���� 
			cout<<xiabiao_name[road.top()]<<"-->";
			road.pop();
		}
		cout<<id_name[y]<<endl;
	}
	else cout<<"�����㲻��ͨ"<<endl; 
	return ;
}

//����·��
void all_route(){//dfs���
	change();
	print_findmenu();
	memset(mark,0,sizeof(mark));
	int a;
	while(cin>>a){
		if(a==0)return ;
		else if(a==1){//����Ų�ѯ 
			int flag=0;
			string x,y;
			cout<<"�����������յ���"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"�Ƿ����룬����������"<<endl;
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
				cout<<"���㲻���ڣ������²�ѯ"<<endl;
			}
			return ;
		}
		else if(a==2){//�����Ʋ�ѯ 
		int flag=0;
			string x,y;
			cout<<"�����������յ�����"<<endl;
			cin>>x>>y;
			while(x==y){
				cout<<"�Ƿ����룬����������"<<endl;
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
				cout<<"���㲻���ڣ������²�ѯ"<<endl;
			}
			return ;
		}
		else{
			cout<<"������ѡ��"<<endl;
			cin>>a; 
		} 
	}
	return ;
}

//��ѯx��y������·��(���)
void getall_routeid(string x,string y,int s,int sum,int z){
	if(road[z-1]==name_xiabiao[id_name[y]]){//�����յ㣬��������·�� 
		cout<<"·����"<<xiabiao_name[s]<<"-->";
		for(int i=1;i<z-1;i++){
			cout<<xiabiao_name[road[i]]<<"-->";
		}
		cout<<id_name[y]<<endl;
		cout<<"����Ϊ��"<<sum<<endl<<endl;
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(mark[i]==0&&graph[name_xiabiao[id_name[x]]][i]!=-1){//�ܵ�����һ���� 
			mark[i]=1;
			road[z]=i; 
			getall_routeid(name_id[xiabiao_name[i]],y,s,sum+graph[name_xiabiao[id_name[x]]][i],z+1);
			mark[i]=0;
		}
	}
	return ;
}

//��ѯx��y������·��(����)
void getall_routename(string x,string y,int s,int sum,int z){
	if(road[z-1]==name_xiabiao[y]){//�����յ㣬��������·�� 
		cout<<"·����"<<xiabiao_name[s]<<"-->";
		for(int i=1;i<z-1;i++){
			cout<<xiabiao_name[road[i]]<<"-->";
		}
		cout<<y<<endl;
		cout<<"����Ϊ��"<<sum<<endl<<endl;
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(mark[i]==0&&graph[name_xiabiao[x]][i]!=-1){//�ܵ�����һ���� 
			mark[i]=1;
			road[z]=i; 
			getall_routename(xiabiao_name[i],y,s,sum+graph[name_xiabiao[x]][i],z+1);
			mark[i]=0;
		}
	}
	return ;
}

//��ʾ��������
void shownum(){
	cout<<"��ǰ��������Ϊ��"<<cnt<<endl;
	return ; 
}

//��ӡ���о�����Ϣ 
void printall(){
	if(m.size()==0){
		cout<<"��ǰϵͳ��δ��ž�����Ϣ"<<endl;
		return ; 
	}
	cout<<"���о�����Ϣ����"<<endl;
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		cout<<i->id<<"  "<<i->name<<"  "<<i->jianjie<<endl; 
	}
	return ;
}

//�޸Ĺ���Ա���� 
void update_password(){
	int x=0;
	string s;
	cout<<"�������ʼ����"<<endl;
	while(cin>>s){
		if(s==password){
			cout<<"�������޸ĺ������"<<endl;
			cin>>password;
			cout<<"�޸ĳɹ�������µ�¼"<<endl;
			return ;//�޸ĳɹ� 
		}
		cout<<"�����������������"<<endl;
		x++;
		if(x>=5){
			cout<<"�������������࣬����µ�¼"<<endl;
			return ;
		}
	}
	return ;
}


void coutmap(){//���map 
	for(map<string,string>::iterator i=name_id.begin();i!=name_id.end();i++){
		cout<<i->first<<"  "<<i->second<<endl;
	}
	cout<<endl;
	for(map<string,string>::iterator i=id_name.begin();i!=id_name.end();i++){
		cout<<i->first<<"  "<<i->second<<endl;
	}
	cout<<endl;
}

//��vectorת�����ڽӾ��� 
void change(){
	for(int i=0;i<m.size();i++){
		xiabiao_name[i+1]=m[i].name;//�±��Ӧ���� 
		name_xiabiao[m[i].name]=i+1;//���ֶ�Ӧ�±� 
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<xiabiao_name[i]<<" ";
//	}
//	cout<<endl;
	//��ʼ���ڽӾ��� 
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(i==j)graph[i][j]=0;
			else graph[i][j]=-1;//�޷�����
		}
	}
	for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
		graph[name_xiabiao[i->begin]][name_xiabiao[i->end]]=i->w;
		graph[name_xiabiao[i->end]][name_xiabiao[i->begin]]=i->w;
	}
	
//	//����ڽӾ��� 
//	for(int i=1;i<=cnt;i++){
//		for(int j=1;j<=cnt;j++){
//			cout<<graph[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
	return ; 
}

//��ȡ�ļ�
void readfile(){
	ifstream fin("Attraction information.txt");
	if(fin.is_open()==false){
		ofstream fout("Attraction information.txt");//�����ʧ�ܣ��ʹ���һ�� 
		fout.close();
	}
	else{
		int x,y,w;
		string id,name,jianjie,s,begin,end;
		fin>>cnt;
		x=cnt;
		while(x--){//��������Ϣ 
			fin>>id>>name>>jianjie;
			m.push_back({id,name,jianjie});
			id_name[id]=name;
			name_id[name]=id;
		}
		fin>>y;//�ߵ����� 
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

//д���ļ�
void writefile(){
	FILE *pf=fopen("Attraction information.txt","w");
	fprintf(pf,"%d\n",cnt);
	for(vector<Information>::iterator i=m.begin();i!=m.end();i++){
		string s=i->id,x=i->name,y=i->jianjie;
		char arr1[s.size()+1],arr2[x.size()+1],arr3[y.size()+1];//��stringת��char����,������� 
		strcpy(arr1,s.c_str());
		strcpy(arr2,x.c_str());
		strcpy(arr3,y.c_str());
		fprintf(pf,"%s  %s  %s\n",arr1,arr2,arr3);
	}
	fprintf(pf,"%d\n",edge.size());
	for(vector<Edge>::iterator i=edge.begin();i!=edge.end();i++){
		string s=i->begin,x=i->end;
		int w=i->w;
		char arr1[s.size()+1],arr2[x.size()+1];//��stringת��char����,������� 
		strcpy(arr1,s.c_str());
		strcpy(arr2,x.c_str());
		fprintf(pf,"%s  %s  %d\n",arr1,arr2,w);
	}
	char pw[password.size()+1];
	strcpy(pw,password.c_str());
	fprintf(pf,"%s\n",pw);
	fclose(pf);
}


