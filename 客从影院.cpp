#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define LEN 15
#define piaowu_txt "2.txt"
#define users_txt "4.txt"
#define shows_txt "5.txt"
#define changci_txt "6.txt"
#define yingting_txt "7.txt"
char  f[LEN];
int ff; 

void readusers();//读取经理 
void zhuceusers();//注册经理 
void writeusers();// 写入经理 
void denglusers();// 登陆经理
void readshows();// 读取售票员 
void zhuceshows();// 注册售票员 
void writeshows();// 写入售票员 
void denglushows();// 登录售票员 
void help();// 最先使用系统的帮助 
void add();// 添加影片信息 
void del();// 删除影片信息 
void modify();// 修改影片信息 
void amendname();// 按照电影名字修改影片信息 
void amendid();// 按照电影编码修改影片信息 
void seek();// 查找影片信息 
void findname();// 按照电影名字查找 
void findid();// 按照电影编码查找 
void display();// 影片信息展示 
void save();// 影片信息保存 
void read();// 影片信息读取 
void menu();//管理系统主页面 
void mainmanger(); //经理端的选择 
void manger1();//电影信息选择 
void show2();// 场次信息选择 
void manger3();// 影厅信息选择 
void menu1();//经理端的主页面 
void menu1dy(); // 经理端的电影操作 
void menu1yy();// 经理端的影院操作 
void menu2cc(); // 经理端的场次操作 
void readchangci();// 读取场次信息 
void savechangci();// 保存场次信息 
void displaychangci();// 展示场次信息 
void addchangci();// 增加场次信息 
void delchangci();// 删除场次信息 
void amendccnum();// 按照场次 
void modifychangci();// 修改场次信息 
void readyingting();// 读取影厅信息 
void saveyingting();// 保存影厅信息 
void displayyingting();// 展示影厅信息 
void addyingting();// 增加影厅信息 
void delyingting();// 删除影厅信息 
void modifyyingting();// 修改影厅信息 
void amendyynum();// 按照影厅编号修改 
void menu2();// 售票员端主页面 
void goupiao();// 售票员售票 
void tuipiao();// 售票员退票 
void mainshow();//售票员选择 
void xiugaiusersmima();//修改经理账号密码 
void xiugaishowsmima();//修改售票员密码 
void sortshowsyye();//对售票员营业额排序 
void displayyye();// 展示售票员营业额 
void displayyingtingusers();//对经理展示影厅信息 
void tongji();//统计票房 
void mmain();//主函数 
void showsyye(); //升序对售票员营业额排序 
void jiangxusort();//降序对售票员营业额排序 
void xingming();//按照姓名的字典序排序 
void findchangci();//查找电影的场次选择 
void finddiany();//只查找该电影的场次
void findday();//只查找当前的电影场次
void findtwo();//精确查找场次 
 
int n=0;
struct piaowu{
	char dyname[LEN];
	char director[LEN];
	char zhuyan1[LEN];
	char zhuyan2[LEN];
	char time[LEN];
	char label[LEN];
	char area[LEN];
	int fare;
	char shiyong[LEN];
	char language[LEN];
	char id[LEN];
	struct piaowu * next;
}*head,*p,*p1,*p2;

int k=0;
struct users{
    char username[LEN];
    char userpass[LEN];
    struct users * next;
}*headd,*q,*q1,*q2;

int z=0;
struct shows{
    char showname[LEN];
    char showpass[LEN];
    int yeji;
    struct shows * next;
}*hhead,*l,*l1,*l2;
  
int t=0;
struct changci{
	char ccname[LEN];
	char cclabel[LEN];
	char ccshichang[LEN];
	char ccriqi[LEN];
	char cctime[LEN];
	char ccyingting[LEN];
	int ccpiaojia;
	int ccyupiao;
	char ccnum[LEN]; 
	struct changci * next;
}*shead,*s,*s1,*s2;

int i=0;
struct yingting{
	char yynum[LEN];
	char yyname[LEN];
	char bofang[LEN];
	int r;
	int l;
	int yyseat[30][30];
	int yishou;
	int shouru;
	struct yingting * next;
	
}*yhead,*y,*y1,*y2;

void jiangxusort(){
	char nametemp[LEN];
	char passtemp[LEN];
	int temp;
	l=hhead; 
    while(l->next!=NULL){
        while(l->next!=NULL){
            if((l->yeji)<(l->next->yeji)){
                temp=l->yeji;
                strcpy(nametemp,l->showname);
                strcpy(passtemp,l->showpass);
                
                l->yeji=l->next->yeji;
                strcpy(l->showname,l->next->showname);
                strcpy(l->showpass,l->next->showpass);
                
                l->next->yeji=temp;
                strcpy(l->next->showname,nametemp);
                strcpy(l->next->showpass,passtemp);
            }
            l=l->next;
        }
    }
}

void sortshowsyye(){
	char nametemp[LEN];
	char passtemp[LEN];
	int temp;
	l=hhead; 
    while(l->next!=NULL){
        while(l->next!=NULL){
            if((l->yeji)>(l->next->yeji)){
                temp=l->yeji;
                strcpy(nametemp,l->showname);
                strcpy(passtemp,l->showpass);
                
                l->yeji=l->next->yeji;
                strcpy(l->showname,l->next->showname);
                strcpy(l->showpass,l->next->showpass);
                
                l->next->yeji=temp;
                strcpy(l->next->showname,nametemp);
                strcpy(l->next->showpass,passtemp);
            }
            l=l->next;
        }
    }
}

void xingming(){
	char nametemp[LEN];
	char passtemp[LEN];
	int temp;
	l=hhead;
    while(l->next!=NULL){
        while(l->next!=NULL){
            if(strcmp((l->showname),(l->next->showname))>0){
                temp=l->yeji;
                strcpy(nametemp,l->showname);
                strcpy(passtemp,l->showpass);
                
                l->yeji=l->next->yeji;
                strcpy(l->showname,l->next->showname);
                strcpy(l->showpass,l->next->showpass);
                
                l->next->yeji=temp;
                strcpy(l->next->showname,nametemp);
                strcpy(l->next->showpass,passtemp);
            }
            l=l->next;
        }
    }
}

void showsyye(){
	int a;
	printf(" 请选择按什么顺序排序\n");
	printf("1.升序排序\n");
	printf("2.降序排序\n");
	printf("3.按姓名排序\n"); 
	scanf("%d",&a);
	switch(a){
		case 2:
			jiangxusort();
			jiangxusort();
			displayyye();
			return menu1();
		case 1:
			sortshowsyye();
			sortshowsyye();
			displayyye();
			return menu1();
		case 3:
			xingming();
			xingming();
			displayyye();
			return menu1();
		default:
			printf("请在1-3之间选择"); 
	}
}

void menu(){
	int num;
	printf("  *****************************************************\n\n");
	printf("  *                客从票务管理系统                   *\n \n");
	printf("  *****************************************************\n\n");
	printf("  *******************系统功能菜单**********************\n");
	printf("  ------------------------   --------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               0.帮助                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               1.经理操作                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.售票员操作               ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.退出                     ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
}

void menu1(){
	printf("  *****************************************************\n\n");
	printf("  *******************系统功能菜单**********************\n");
	printf("  ------------------------   --------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.电影管理                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.影厅管理                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.修改密码                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.查看售票员营业额         ******\n");
	printf("  *****************************************************\n");
	printf("  *****               5.统计票房                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               6.退出                     ******\n");
	printf("  *****************************************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
}

void help(){
	printf("\n0.欢迎使用客从票务系统帮助功能\n");
	printf("\n1.初次进入系统，若您为售货员请先注册一个账号;\n");
	printf("\n2.若已经有账号请直接登录;\n");
	printf("\n4.增加或者修改票务信息后,切记保存;\n");
	printf("\n5.感谢您的使用！\n"); 	
}

void menu1dy(){
	printf("  ******************************************************\n\n");
	printf("  *******************系统功能菜单***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.查看所有电影             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.增加影片信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.删除影片信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.修改影片信息             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.查询影片信息             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               6.保存到文件并退出         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
} 

void menu2cc(){
	printf("  ******************************************************\n\n");
	printf("  *******************系统功能菜单***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.查看所有场次             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.增加场次信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.删除场次信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.修改场次信息             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.保存到文件并退出         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
}

void menu1yy(){
	printf("  ******************************************************\n\n");
	printf("  *******************系统功能菜单***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.查看所有影厅             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.增加影厅信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.删除影厅信息             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.修改影厅信息             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.保存到文件并退出         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
} 

void menu2(){
	printf("  ******************************************************\n\n");
	printf("  *******************系统功能菜单***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.管理场次                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.查询场次                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.购票                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.退票                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               5.修改密码                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               6.保存到文件并退出         ******\n");
	printf("  *****************************************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("请选择菜单编号:");
}

void manger1(){
				system("cls");
				while(1){
				menu1dy();
				int c;
				scanf("%d",&c);
				fflush(stdin);		
						switch(c){
									case 1:
										display();
										system("pause");
										system("cls");
										break;
									case 2:
										add();
										system("pause");
										system("cls");
										break;
									case 3:
										del();
										system("pause");
										system("cls");
										break;
									case 4:
										modify();
										system("pause");
										system("cls");
										break;
									case 5:
										seek();
										system("pause");
										system("cls");
										break;
									case 6:
										save();
										system("pause");
										system("cls");
										return;
									default:printf("请在1-6之间选择\n");
								}
}
}

void show2(){
	system("cls");
			while(1){
							menu2cc();
							int c;
							scanf("%d",&c);
							fflush(stdin);
							switch(c){
									case 1:
										displaychangci();
										system("cls");
										break;
									case 2:
										addchangci();
										system("cls");
										break;
									case 3:
										delchangci();
										system("cls");
										break;
									case 4:
										modifychangci();
										system("cls");
										break;
									case 5:
										savechangci();
										system("cls");
										return ;

									default:printf("请在1-5之间选择\n");
								}
					}
					
}

void manger3(){
	system("cls");
							while(1){
								menu1yy();
								int c;
								scanf("%d",&c);
								fflush(stdin);
								
								switch(c){
										case 1:
											displayyingtingusers();
											system("pause");
											system("cls");
											break;
										case 2:
											addyingting();
											system("pause");
											system("cls");
											break;
										case 3:
											delyingting();
											system("pause");
											system("cls");
											break;
										case 4:
											modifyyingting();
											system("pause");
											system("cls");
											break;
										case 5:
											saveyingting();
											system("pause");
											system("cls");
											return ;
	
										default:printf("请在1-5之间选择\n");
									}
						}
}

void mainmanger(){
	system("cls");
	denglusers();
			
	while(1){
	system("cls");
		menu1();
		int e;
		
		scanf("%d",&e);
		fflush(stdin);
		switch(e){
			case 1:
				manger1();
				system("cls");
				break;
			case 2:
				manger3();		
				system("cls");
				break;
			case 3:
				xiugaiusersmima();
				system("cls");
				break ;
			case 4:
				showsyye(); 
				system("cls");
				break;
			case 6:
				system("cls");
				return;
			case 5:
				tongji();
				system("cls");
				break; 
			}
	}
}

void mainshow(){
	system("cls");
	denglushows();
	while(1){
				displaychangci();
				menu2();
				int c;
				fflush(stdin);
				scanf("%d",&c);
				fflush(stdin);
				switch(c){
					case 1:
						show2();
						system("cls");
						break;
					case 3:
						goupiao();
						system("cls");
						break;
					case 4:
						tuipiao();
						system("cls");
						break;
					case 5:
						xiugaishowsmima();
						system("cls");
						break;
					case 2:
						findchangci();
						system("cls");
						break;
					case 6:
						savechangci();
						saveyingting();
						writeshows();
						system("cls");
					    return ;
					default:printf("请在0-6之间选择\n");
				}
		
			}
}

void mmain(){
	read();
	readusers();
	readshows();
	readchangci(); 
	readyingting();
	while(1){
		system("cls");
		menu();
		int w;
		fflush(stdin);
		scanf("%d",&w);
		fflush(stdin);
		switch(w){
			case 0:
				system("cls");
				help();
				system("pause");
				system("cls");
				break;
			case 1:
				mainmanger();
				break;
			case 2:
				mainshow();
				break;
			case 3:
				
				return;
		}
	}
	
}

void save(){
    FILE *fp;
    struct piaowu *p;
    if((fp=fopen(piaowu_txt,"wb"))==NULL){
    	printf("Can not open the file!");  
	}
    p=head;
    while(p!=NULL){
		fprintf(fp,"%s\t\t",p->dyname);
        fprintf(fp,"%s\n",p->director);
        fprintf(fp,"%s\t",p->zhuyan1);
        fprintf(fp,"%s\t",p->zhuyan2);
        fprintf(fp,"%s\n",p->time);
        fprintf(fp,"%s\t",p->label);
        fprintf(fp,"%s\t",p->area);
        fprintf(fp,"%d\n",p->fare);
        fprintf(fp,"%s\t",p->shiyong);
        fprintf(fp,"%s\t",p->language);
        fprintf(fp,"%s\n",p->id);
		p=p->next;
    }
    fclose(fp);
	printf("存储完成\n");
	system("pause");
	system("cls");
}

void read(){
	FILE *fp;
	if((fp=fopen(piaowu_txt,"rb"))==NULL){
		printf("Can not open file!");
		exit(-1);
	}
    while(!feof(fp)){
		p1=(struct piaowu *)malloc(sizeof(struct piaowu));
		if(n==0){
		    head=p1;
		}
		else{
			p2->next=p1;
			p1->next=NULL;
		}
		fscanf(fp,"%s\t\t",&p1->dyname);
        fscanf(fp,"%s\n",&p1->director);
        fscanf(fp,"%s\t",&p1->zhuyan1);
        fscanf(fp,"%s\t",&p1->zhuyan2);
        fscanf(fp,"%s\n",&p1->time);
        fscanf(fp,"%s\t",&p1->label);
        fscanf(fp,"%s\t",&p1->area);
        fscanf(fp,"%d\n",&p1->fare);
        fscanf(fp,"%s\t",&p1->shiyong);
        fscanf(fp,"%s\t",&p1->language);
        fscanf(fp,"%s\n",&p1->id);
		p2=p1;
		n+=1;;
	}
    fclose(fp);
}

void add(){
	p1=(struct piaowu * )malloc(sizeof(struct piaowu));
	if(n==0){
		head=p1;
	}else{
		p2->next=p1;
	}
	printf("请输入电影的名字：");
    scanf("%s",&p1->dyname);
    printf("请输入该电影导演的名字：");
    scanf("%s",&p1->director);
    printf("请输入该影片的时长：");
    scanf("%s",&p1->time);
    printf("请输入该影片的第一个主演：");
    scanf("%s",&p1->zhuyan1);
    printf("请输入该影片的第二个主演：");
    scanf("%s",&p1->zhuyan2);
    printf("请输入该影片的标签：");
    scanf("%s",&p1->label);
    printf("请输入该影片的地区：");
	scanf("%s",&p1->area);
	printf("请输入该影片的票价：");
	scanf("%d",&p1->fare);
	printf("请输入该影片适合的观影人群：");
	scanf("%s",&p1->shiyong);
	printf("请输入该影片的语言：");
	scanf("%s",&p1->language);
	printf("请输入该影片的编号：");
	scanf("%s",&p1->id); 
	p2=p1;
	p2->next=NULL;
	n++;
	printf("输入成功！\n");
	system("cls");
}

void del(){
	if(n!=0){
		struct piaowu * t;
		char a[LEN];
		printf("请输入要删除的电影名称：");
		scanf("%s",&a);
		fflush(stdin);
		p=head;
		for(;p!=NULL;p=p->next){
			if(strcmp(p->next->dyname,a)==0){
				t=p->next;
				p->next=p->next->next;
				free(t);
				printf("该电影信息已经被删除啦！\n ");
				break; 
			}
		}
	}else{
		printf("******您还没有添加数据哟!"); 
	}
}

void modify(){
	void amendname();
	void amendid();
	if(n!=0){
		int a;
		printf("1.按电影名称修改\n2.按电影编号修改\n3.退出本菜单\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			amendname();
			break;
		case 2:
			amendid();
			break;
		case 3:
			return;
		default:printf("请在1-3之间选择\n");
		}
	}else{
		printf("******您还没有添加数据哟!\n");
		system("pause");
	} 
}

void amendname(){
	int c;
	int flag=0;
	char a[LEN];
	printf("请输入需要修改的电影名称：");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->dyname)==0){
			printf("\n被修改影片的信息如下：\n");
			printf("----------------------------------------------------------\n");
			printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			flag=1;
			break;
		}
		p=p->next;
	}while(p!=NULL);
	if(flag==1){
	 	printf("\n\n1.修改电影名称\n2.修改导演名称\n");
		printf("3.修改第一个主演名字\n4.修改第二个主演名字\n");
		printf("5.修改时长\n6.修改剧目标签\n");
		printf("7.修改地区\n8.修改票价\n");
		printf("9.修改适宜的观影人群\n10.修改影片语言\n");
		printf("11.修改影片编号\n"); 
		scanf("%d",&c);
		fflush(stdin);
		switch(c){
			case 1:
				printf("电影名称修改为：");
				scanf("%s",&p->dyname);
				break;
			case 2:
				printf("影片导演修改为：");
				scanf("%s",&p->director);
				break;
			case 3:
				printf("影片第一个主演名字修改为：");
				scanf("%s",&p->zhuyan1);
				break;
			case 4:
				printf("影片第二个主演名字修改为：");
				scanf("%s",&p->zhuyan2);
				break;
			case 5:
				printf("影片时长修改为：");
				scanf("%s",&p->time);
				break;
			case 6:
				printf("影片剧目标签修改为：");
				scanf("%s",&p->label);
				break;
			case 7:
				printf("影片地区修改为：");
				scanf("%s",&p->area);
				break;
			case 8:
				printf("影片票价修改为：");
				scanf("%d",&p->fare);
				break;
			case 9:
				printf("影片适宜观看的人群修改为：");
				scanf("%s",&p->shiyong);
				break;
			case 10:
				printf("影片语言修改为：");
				scanf("%s",&p->language);
				break;
			case 11:
				printf("影片编号修改为：");
				scanf("%s",&p->id);
				break; 
		}
		
	 }
	 else{
	 	printf("不好意思，没有找到"); 
	 }
	
}

void amendid(){
	int c;
	char a[LEN];
	printf("请输入需要修改的电影编号：");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->id)==0){
			printf("\n被修改影片的信息如下：\n");
			printf("----------------------------------------------------------\n");
			printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			break;
		}
		p=p->next;
	} while(p!=NULL);
	printf("\n\n1.修改电影名称\n2.修改导演名称\n");
	printf("3.修改第一个主演名字\n4.修改第二个主演名字\n");
	printf("5.修改时长\n6.修改剧目标签\n");
	printf("7.修改地区\n8.修改票价\n");
	printf("9.修改适宜的观影人群\n10.修改影片语言\n");
	printf("11.修改影片编号\n"); 
	scanf("%d",&c);
	fflush(stdin);
	switch(c){
		case 1:
			printf("电影名称修改为：");
			scanf("%s",&p->dyname);
			break;
		case 2:
			printf("影片导演修改为：");
			scanf("%s",&p->director);
			break;
		case 3:
			printf("影片第一个主演名字修改为：");
			scanf("%s",&p->zhuyan1);
			break;
		case 4:
			printf("影片第二个主演名字修改为：");
			scanf("%s",&p->zhuyan2);
			break;
		case 5:
			printf("影片时长修改为：");
			scanf("%s",&p->time);
			break;
		case 6:
			printf("影片剧目标签修改为：");
			scanf("%s",&p->label);
			break;
		case 7:
			printf("影片地区修改为：");
			scanf("%s",&p->area);
			break;
		case 8:
			printf("影片票价修改为：");
			scanf("%d",&p->fare);
			break;
		case 9:
			printf("影片适宜观看的人群修改为：");
			scanf("%s",&p->shiyong);
			break;
		case 10:
			printf("影片语言修改为：");
			scanf("%s",&p->language);
			break;
		case 11:
			printf("影片编号修改为：");
			scanf("%s",&p->id);
			break; 
	}
}

void display(){
	if(n!=0){
		p=head;
		int t=1; 
		do{
			int m=n; 
			printf("\n----------------------------------------------------------\n");
			printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			printf("\t\t第%d页\t\t\t共%d页\n\n",t,m);
			t++;
			p=p->next;
		}while(p!=NULL);
	}
	else{
		printf("******您还没有添加数据哟!\n");
	}
	system("pause");
	system("cls");

}

void seek(){
	void findname();
	void findid();
	if(n!=0){
		int a;
		printf("1.按电影名称查找\n2.按电影编号查询\n3.退出本菜单\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			findname();
			break;
		case 2:
			findid();
			break;
		case 3:
			return;
		default:printf("请在1-3之间选择\n");
		}
	}else{
		printf("******您还没有添加数据哟!\n");
		system("pause");
	}
}

void findtwo(){
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN];
	struct changci *s;
	s=shead;
	printf("请输入你要查询的电影名称：");
	scanf("%s",a);
	printf("请输入你要查询的场次日期：");
	scanf("%s",c); 
	do{
		if(strcmp(a,s->ccname)==0&&strcmp(c,s->ccriqi)){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}s=s->next;
	}while(s!=NULL);
	system("pause");
}

int yanzhengdenglu(){
	char passWord[10];
	char ch;
	int i,j;
	system("cls");
	for(i=1;i<=3;i++){
		printf("\n\t\t\t请输入验证码：");
		j=0;
		while(j<5&&(ch=getch())!='\r'){
			passWord[j++]=ch;
			putchar('*');
		}
		passWord[j]='\0';
		if(strcmp(passWord,"asdf")==0){
			system("cls");
			printf("\n\t\t\t\t验证成功！\n");
			break;
		}else{
				printf("\n\n\t\t\t密码错误，请重新输入！\n");	
		}
}
	if(i>3){
		printf("\n\t\t\t密码已经输入3次，您无权使用，请退出！\n");
		getch();
		exit(0);
	}
	system("cls");
}

void findname(){
	char a[LEN];
	printf("请输入需要查找的电影名称：");
	scanf("%s",&a);
	p=head;
	char * f;
	int flag=0;
	do{
		if(strcmp(a,p->dyname)==0){
			printf("\n查找到该影片的信息如下：\n");
			printf("----------------------------------------------------------\n");
			printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			flag=1;
			break;
		}
		p=p->next;
	}while(p!=NULL);
	if(flag==1){
		return ;
	}
	else{
		p=head;
		do{
			f=strstr(p->dyname,a);
			if(f){
				printf("\n你可能要搜索影片的信息如下：\n");
				printf("----------------------------------------------------------\n");
				printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
				printf("----------------------------------------------------------\n");
			}
			p=p->next;
		}while(p!=NULL);
	}
	
}

void findid(){
	char a[LEN];
	printf("请输入要查找的影片编号：");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->id)==0){
			printf("\n查找到该影片的信息如下：\n");
			printf("----------------------------------------------------------\n");
			printf("||电影名称：%-s\t\t\t导演：%-s\t||\n||主演：%-s    %-s\t时长：%-s \t\t||\n||剧目标签：%-s\t地区：%-s\t票价：%-d\t||\n||观影人群：%-s\t语言：%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
		}
		p=p->next;
	}while(p!=NULL);
}

void zhuceusers(){
	system("cls"); 
	FILE *fp;
    char temp[20];
    char ch; 
    do{
    	q1=(struct  users*)malloc(sizeof(struct users));
		q=headd;
        printf("\t\t\t\t用户注册");
        printf("\n\t\t用户名:");
        fflush(stdin);
        scanf("%s",&q1->username);
        fp=fopen(users_txt,"r");
        do{
        	if(strcmp(q1->username,q->username)==0){
        		printf("\n\t该用户名已经存在！");
				printf("%s\t",q->username);
				printf("%s\n",q->userpass);
				fclose(fp);
				printf("你还要继续注册吗？\n1.继续重新注册\n2.登录账号\n");
				fflush(stdin);
				if(getch()=='1'){
					zhuceusers();
				}
				if(getch()=='2') {
					denglusers();
				}
			}
			q=q->next;
		}while(q!=NULL);
		if(k==0){
			headd=q1;
		}else{
			q2->next=q1;
		}
        printf("\n\t\t密  码:");
        int p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				q1->userpass[p++]=ch;
				printf("*");
			}
			q1->userpass[p]='\0';
		}
        //scanf("%s",q1->userpass);
        printf("\n\t\t确认密码:");
        p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				temp[p++]=ch;
				printf("*");
			}
			temp[p]='\0';
		}
        //scanf("%s",temp);
		if(strcmp(q1->userpass,temp)!=0){
			printf("\n\t\t两次密码不一样，请重新输入！"); 
		}
    }while(strcmp(q1->userpass,temp)!=0);
    fp=fopen(users_txt,"w");
    if(fp==NULL){
          printf("\n\t注册失败\n");
          exit(0);
       }else{
        system("cls");
        printf("\n\t注册成功");
        
        q2=q1;
		q2->next=NULL;
		k++;
        writeusers();
        denglusers();
    }
}

void writeusers(){
	FILE *fp;
    struct users *q;
    if((fp=fopen(users_txt,"wb"))==NULL){
    	printf("Can not open the file!");  
	}
    q=headd;
    while(q!=NULL){
        fprintf(fp,"%s\t",q->username);
        fprintf(fp,"%s\n",q->userpass);
		q=q->next;
    }
    fclose(fp);
	printf("\n存储完成\n");
	system("pause");
	system("cls");
}

void readusers(){
	FILE *fp;
	if((fp=fopen(users_txt,"rb"))==NULL){
		printf("Can not open file!");
		exit(-1);
	}
    while(!feof(fp)){
		q1=(struct users *)malloc(sizeof(struct users));
		if(k==0){
		    headd=q1;
		}
		else{
			q2->next=q1;
			q1->next=NULL;
		}
        fscanf(fp,"%s\t",&q1->username);
        fscanf(fp,"%s\n",&q1->userpass);
		q2=q1;
		k+=1;;
	}
    fclose(fp);
}

void denglusers(){
	FILE *fp;
	char u[LEN],c[LEN],temp[LEN],ch;
	int m=0;
	int o;
	system("cls"); 
    printf("\n\t\t\t用户登录");
    printf("\n\t\t用户名在15个字符之内哦！"); 
    printf("\n\n\t\t用户名:");
    scanf("%s",u);
    fflush(stdin);
    fp=fopen(users_txt,"r+");
    q=headd;
    do{
    	if(strcmp(u,q->username)==0){
    		strcpy(temp,q->userpass);
    		m=1;
		}q=q->next;
	}while(q!=NULL);
	
    if(m==0){
        printf("\n\t\t用户不存在,请注册");
        printf("\n\t\t1.注册\n\t\t2.重新登陆\n");
        fflush(stdin);
        scanf("%d",&o);
        if(o==1){
            system("cls");
            return zhuceusers();
        }
        if(o==2){
        	return denglusers();
		}
    }
    do{
    	printf("\n\n\t\t密  码:");
    	int p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				c[p++]=ch;
				printf("*");
			}
			c[p]='\0';
		}
		//scanf("%s",c);
		if(strcmp(c,temp)!=0){
			printf("\n\t\t密码错误\n\t\t1.退出 \n\t\t2.重新登录\n");
			scanf("%d",&o);
			if(o==1){
                fclose(fp);
                mmain();
                break;
        	}
        	if(o==2){
        		readusers();
        		return denglusers();
			}
		}
	}while(strcmp(c,temp)!=0);
	printf("\n\n\t\t登录成功,欢迎使用!\n");
	system("pause");
	system("cls");
	return ;
}

void xiugaiusersmima(){
	FILE *fp;
	printf("\n\t\t请输入原始密码：");
	
	char u[LEN],c[LEN],ch,t[LEN];
	int m;

    //scanf("%s",t);    
	int p=0;
	while((ch=getch())!='\r'){
		if(ch=='\b'){
			if(p>0){
				p--;
				printf("\b \b");
			}else{
				putchar(7);
			}
		}else{
			t[p++]=ch;
			printf("*");
		}
		t[p]='\0';
	}
	fflush(stdin);
    fp=fopen(users_txt,"r+");
    q=headd;
    do{
    	if(strcmp(t,q->userpass)==0){
			m=1;	
		}q=q->next;
	}while(q!=NULL);
	
    if(m==0){
        printf("\n\t\t密码错误，请重新输入：");
		return xiugaiusersmima(); 
	}   
    printf("\n\n\t\t请输入新的密码：");
    	p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				c[p++]=ch;
				printf("*");
			}
			c[p]='\0';
		}
    do{
    	printf("\n\n\t\t密  码:");
    	int k=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(k>0){
        			k--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				u[k++]=ch;
				printf("*");
			}
			u[k]='\0';
		}
		//scanf("%s",c);
		
		if(strcmp(c,u)!=0){
			printf("\n\t\t两次密码不一致，请重新设置");
			return xiugaiusersmima(); 
		}
	}while(strcmp(c,u)!=0);
	q=headd;
    do{
    	if(strcmp(t,q->userpass)==0){
			strcpy(q->userpass,c);
		}q=q->next;
	}while(q!=NULL);
	writeusers();
	printf("\n\t\t修改成功,欢迎使用!\n");
	return denglusers();
	system("pause");
	system("cls");	
}

void zhuceshows(){
	FILE *fp;
	char temp[20],ch;
    do{
    	l1=(struct  shows*)malloc(sizeof(struct shows));
		l=hhead;
        printf("\t\t\t\t用户注册");
        printf("\n\t\t用户名:");
        scanf("%s",&l1->showname);
        fflush(stdin);
        fp=fopen(shows_txt,"r");
        do{
        	if(strcmp(l1->showname,l->showname)==0){
        		printf("\n\t该用户名已经存在！");
				fclose(fp);
				printf("你还要继续注册吗？\n1.继续重新注册\n2.登录账号\n");
				if(getch()=='1'){
					zhuceshows();
				}else {
					denglushows();
				}
			}
			l=l->next;
		}while(l!=NULL);
		if(z==0){
			hhead=l1;
		}else{
			l2->next=l1;
		}
        printf("\n\t\t密  码:");
        int p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				l1->showpass[p++]=ch;
				printf("*");
			}
			l1->showpass[p]='\0';
		}
        //scanf("%s",l1->showpass);
        printf("\n\t\t确认密码:");
        p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				temp[p++]=ch;
				printf("*");
			}
			temp[p]='\0';
		}
        //scanf("%s",temp);
		if(strcmp(l1->showpass,temp)!=0){
			printf("\n\t\t两次密码不一样，请重新输入！"); 
		}
    }while(strcmp(l1->showpass,temp)!=0);
    printf("\n\t\t当前业绩：");
    scanf("%d",&l1->yeji);
    fflush(stdin);
    fp=fopen(shows_txt,"w");
    if(fp==NULL){
          printf("\n\t注册失败\n");
          exit(0);
       }else{
        system("cls");
        printf("\n\t注册成功");
        
        l2=l1;
		l2->next=NULL;
		z++;
        writeshows();
        denglushows();
    }
}

void writeshows(){
		FILE *fp;
    struct shows *l;
    if((fp=fopen(shows_txt,"wb"))==NULL){
    	printf("Can not open the file!");  
	}
    l=hhead;
	    while(l!=NULL){
	        fprintf(fp,"%s\t",l->showname);
			for(int i=0;i<strlen(l->showpass);i++){
			if(l->showpass[i]>='A'&&l->showpass[i]<='Z'){
				l->showpass[i]=l->showpass[i]-16;
			fprintf(fp,"%c",l->showpass[i]);
			}else{
			fprintf(fp,"%c",l->showpass[i]);
			}
		}
//        fprintf(fp,"%s\t",l->showpass);
        fprintf(fp,"\t%d\n",l->yeji);
		l=l->next;
    }
    fclose(fp);
	printf("\n存储完成\n");
	system("cls");
}

void denglushows(){
	FILE *fp;
	char u[LEN],c[LEN],temp[LEN],ch;
	int m=0;
	int o,p;
	system("cls");
    printf("\n\t\t\t\t售票员登录");
    printf("\n\t\t用户名:");
    scanf("%s",u);
    fp=fopen(shows_txt,"r+");
    l=hhead;
    do{
    	if(strcmp(u,l->showname)==0){
    		strcpy(temp,l->showpass);
    		m=1;
    		ff=l->yeji;
			strcpy(f,l->showname);
		}l=l->next;
	}while(l!=NULL);
	
    if(m==0){
        printf("\n\t\t售票员不存在,请注册");
        printf("\n\t\t1.注册\n\t\t2.重新登陆\n");
        scanf("%d",&o);
        if(o==1){
            system("cls");
            return zhuceshows();
        }
        if(o==2){
        	return denglushows();
		}
    }
    do{
    	printf("\n\t\t密  码:");
    	p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				c[p++]=ch;
				printf("*");
			}
			c[p]='\0';
		}
		//scanf("%s",&c);
		if(strcmp(c,temp)!=0){
			printf("\n\t\t密码错误\n\t\t1.退出 \n\t\t2.重新登录\n");
			scanf("%d",&o);
			if(o==1){
                fclose(fp);
                mmain();
                break;
        	}
        	if(o==2){
        		readshows();
        		return denglushows();
			}
		}
	}while(strcmp(c,temp)!=0);
	printf("\n\t\t登录成功,欢迎使用!\n");
	
	return ;
}

void readshows(){
	FILE *fp;
	if((fp=fopen(shows_txt,"rb"))==NULL){
		printf("Can not open file!");
		exit(-1);
	}
    while(!feof(fp)){
		l1=(struct shows *)malloc(sizeof(struct shows));
		if(z==0){
		    hhead=l1;
		}
		else{
			l2->next=l1;
			l1->next=NULL;
		}
        fscanf(fp,"%s\t",&l1->showname);
        char temp[15];
			fscanf(fp,"%s",&temp);
        for(int i=0;i<strlen(temp);i++){
			if(temp[i]>='0'&&temp[i]<='9'){
				temp[i]=temp[i]+16;
			}else{
				temp[i]=temp[i];
			}
		}
		strcpy(l1->showpass,temp);
//        fscanf(fp,"%s\t",&l1->showpass);
        fscanf(fp,"\t%d\n",&l1->yeji);
		l2=l1;
		z+=1;;
	}
    fclose(fp);
}

void xiugaishowsmima(){
	FILE *fp;
	printf("\n\t\t请输入原始密码：");
	
	char u[LEN],c[LEN],ch,t[LEN];
	int m;

    //scanf("%s",t);    
	int p=0;
	while((ch=getch())!='\r'){
		if(ch=='\b'){
			if(p>0){
				p--;
				printf("\b \b");
			}else{
				putchar(7);
			}
		}else{
			t[p++]=ch;
			printf("*");
		}
		t[p]='\0';
	}
	fflush(stdin);
    fp=fopen(shows_txt,"r+");
    l=hhead;
    do{
    	if(strcmp(t,l->showpass)==0){
			m=1;
		}l=l->next;
	}while(l!=NULL);
	
    if(m==0){
        printf("\n\t\t密码错误，请重新输入：");
		return xiugaishowsmima(); 
	}   
    printf("\n\n\t\t请输入新的密码：");
    	p=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(p>0){
        			p--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				c[p++]=ch;
				printf("*");
			}
			c[p]='\0';
		}
    do{
    	printf("\n\n\t\t密  码:");
    	int k=0;
        while((ch=getch())!='\r'){
        	if(ch=='\b'){
        		if(k>0){
        			k--;
        			printf("\b \b");
				}else{
					putchar(7);
				}
			}else{
				u[k++]=ch;
				printf("*");
			}
			u[k]='\0';
		}
		//scanf("%s",c);
		
		if(strcmp(c,u)!=0){
			printf("\n\t\t两次密码不一致，请重新设置");
			return xiugaishowsmima(); 
		}
	}while(strcmp(c,u)!=0);
	l=hhead;
    do{
    	if(strcmp(t,l->showpass)==0){
			strcpy(l->showpass,c);
		}l=l->next;
	}while(l!=NULL);
	printf("\n\t\t修改成功,欢迎使用!\n");
	return denglushows();
	system("pause");
	system("cls");	
}

void displayyye(){
	if(z!=0){
		l=hhead;
		printf("\n姓名\t\t营业额\n"); 
		do{ 
		
			
			printf("\n%s\t\t%d\n",l->showname,l->yeji);
			
			l=l->next;
		}while(l!=NULL);
	}
	else{
		printf("******您还没有添加数据哟!\n");
	}
	system("pause");
	system("cls");
}

void findchangci(){
	printf("1.只查询某天的场次\n");
	printf("2.只查询某个电影的场次\n");
	printf("3.查询某个电影某天的场次\n"); 
	printf("4.退出\n"); 
	int a;
	scanf("%d",&a);
	switch(a){
		case 1:
			findday();
			break;
		case 2:
			finddiany();
			break;
		case 3:
			findtwo();
			break;
		case 4:
			return ;
	}		
} 

void findday(){
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN];
	struct changci *s;
	s=shead;
	printf("请输入要查找的场次日期：");
	scanf("%s",a);
	do{
		if(strcmp(a,s->ccriqi)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}s=s->next;
	}while(s!=NULL);
	system("pause"); 
} 

void finddiany(){
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN];
	struct changci *s;
	s=shead;
	printf("请输入你要查询的电影名称：");
	scanf("%s",a);
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}s=s->next;
	}while(s!=NULL);
	system("pause"); 
}

void goupiao(){
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN];
	struct changci *s;
	s=shead;
	printf("请输入你要购买的电影名称：");
	fflush(stdin);
	scanf("%s",a);
	fflush(stdin);
	int flag=0;
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			flag=1;
		}s=s->next;
	}while(s!=NULL);
	if(flag=1){
		printf("\n请选择场次编号：");
	
	scanf("%s",c); 
	fflush(stdin);
	printf("请选择你的座位~\n");
	struct yingting*y;
	y=yhead;
	do{
		if(strcmp(c,y->yynum)==0){
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t放映厅编号：%-s\t\t\t名称：%-s\t\n\t\t\t\t ○表示可用座位 ●表示损坏座位\n",y->yynum,y->yyname);
			printf("\t\t\t规格：%d ×%d\n",y->r,y->l);
			printf("\t\t\tノノノノノノノノノノノノノノノノノノノノノノノノノノノノノ\n");
			printf("\t\t\t                             ^屏                          \n");
			printf("\t\t\t                             |幕                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ○");
						}
						if(y->yyseat[k][j]==0){
							printf(" ●");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
            }
            printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t已售：%d\t\t\t收入：%d\n",y->yishou,y->shouru);

		}
		y=y->next;		
	} while(y!=NULL);
	
	int v;
	printf("\n请问确定选择座位吗？\n");
	printf("\n1.确定\n");
	printf("\n2.退出\n"); 
	
	scanf("%d",&v);
	fflush(stdin);
	if(v==1){
		s=shead;
		do{
			if(strcmp(c,s->ccnum)==0){
				break;
			}s=s->next;
		}while(s!=NULL);
		
		int w,b;
		printf("\n请输入第几排第几列~\n");
		scanf("%d %d",&w,&b);
		fflush(stdin);
		
		y=yhead;
		do{
			if(strcmp(c,y->yynum)==0){
				break;
			}y=y->next;
		}while(y!=NULL);
		if(y->yyseat[w][b]==1){
			y->yyseat[w][b]=0;
			y->yishou=y->yishou+1;
			y->shouru=y->shouru+s->ccpiaojia;
			s->ccyupiao-=1; 
			ff+=s->ccpiaojia;
			printf("\n选座位成功！"); 
			printf("\n\t\t====================================================================");
			printf("\n\t\t||Hiーーーーー                            客从影院                ||");
			printf("\n\t\t||  ☆  *　.  　☆                  %10s                ||",y->yyname);
			printf("\n\t\t||　  . ∧＿∧　∩　* ☆            %10s                    ||",y->yynum);
			printf("\n\t\t||*  ☆ (● ●)/ .                  %d排%d列                        ||",w,b);
			printf("\n\t\t||　.  <　　 ノ* ☆                                               ||");
			printf("\n\t\t||☆ * (つ ノ  .☆             电影：%s                     ||",s->ccname);
			printf("\n\t\t||　　 (ノ                                                        ||");
			printf("\n\t\t||  %-10s           %s                     恭候光临   ||",s->ccriqi,s->cctime);
			printf("\n\t\t||                                                                ||");
			printf("\n\t\t||                                                                ||");
			printf("\n\t\t====================================================================\n");
			system("pause");
			
		do{
			if(strcmp(f,l->showname)==0){
				l->yeji=ff;
				break;
			}
			l=l->next;
		}while(l!=NULL);
		}
		else if(y->yyseat[w][b]==0){
			printf("\n选的座位有人啦!\n");
			printf("\n重新选择吧!\n");
			return goupiao();
		}
		else{
			printf("\n不好意思，你选择的是过道哦！\n");
			printf("\n请重新选择吧！\n");
			return goupiao(); 
		}
			
	}
	if(v==2){
		return ;	
	}
	}
	else{
		printf("输入的影片没有找到哦！\n");
		return; 
	}
		
	
}

void tuipiao(){ 
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN],t[LEN];
	struct changci *s;
	s=shead;
	printf("\n\t\t请输入你要退票的电影名称：");
	fflush(stdin);
	scanf("%s",a);
	fflush(stdin);
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}s=s->next;
	}while(s!=NULL);
	printf("\n\t\t请输入放映厅编号:");
	scanf("%s",&c);
		struct yingting*y;
		y=yhead;
		do{
			if(strcmp(c,y->yynum)==0){
				printf("\t\t\t----------------------------------------------------------\n");
				printf("\t\t\t放映厅编号：%-s\t\t\t名称：%-s\t\n\t\t\t\t ○表示可用座位 ●表示损坏座位\n",y->yynum,y->yyname);
				printf("\t\t\t规格：%d ×%d\n",y->r,y->l);
				printf("\t\t\tノノノノノノノノノノノノノノノノノノノノノノノノノノノノノ\n");
				printf("\t\t\t                             ^屏                          \n");
				printf("\t\t\t                             |幕                          \n");
				int k,j;
				printf("\t\t\t");
				for(k=0;k<y->r;k++){
	                for(j=0;j<y->l;j++){
	                        if(y->yyseat[k][j]==1){
	                        	printf(" ○");
							}
							if(y->yyseat[k][j]==0){
								printf(" ●");
							}
							if(y->yyseat[k][j]==3){
								printf("   ");
							}
	                }
	                	printf("\n\t\t\t");
	            }
				break;
			}
			y=y->next;
		} while(y!=NULL);
		
	//退票：
	s=shead;
		do{
			if(strcmp(c,s->ccnum)==0){
				break;
			}s=s->next;
		}while(s!=NULL);
	printf("\n\t\t请输入座位~");
	int w,b;
	int flag=0;
	scanf("%d %d",&w,&b);
	fflush(stdin);
	if(y->yyseat[w][b]==0){
		y->yyseat[w][b]=1;
		s->ccyupiao+=1;
		y->yishou=y->yishou-1;
		y->shouru=y->shouru-s->ccpiaojia;
		ff-=s->ccpiaojia;
		do{
			if(strcmp(f,l->showname)==0){
				l->yeji=ff;
				break;
			}
			l=l->next;
		} while(l!=NULL);
		printf("\n退票成功哦！\n");
	}else{
		printf("这个座位暂时没人预定哦！"); 
	}
	 
	system("pause");
	
	}
	
void addchangci(){
	char a[LEN],b[LEN],c[LEN];
	s1=(struct changci * )malloc(sizeof(struct changci));
	if(t==0){
		shead=s1;
	}else{
		s2->next=s1;
	}
	printf("请输入电影的名字：");
    scanf("%s",&s1->ccname);
    strcpy(c,s1->ccname);
    fflush(stdin);
    printf("请输入该影片的标签：");
    scanf("%s",&s1->cclabel);
    printf("请输入该影片的时长：");
	scanf("%s",&s1->ccshichang);
	printf("请输入场次的日期：");
	scanf("%s",&s1->ccriqi);
	printf("请输入该场次的时间：");
	scanf("%s",&s1->cctime); 
	printf("请输入该场次的影厅："); 
	scanf("%s",&s1->ccyingting); 
	strcpy(a,s1->ccyingting);
	printf("请输入该影片的票价：");
	scanf("%d",&s1->ccpiaojia);
	printf("请输入余票：");
	scanf("%d",&s1->ccyupiao); 
	printf("请输入该场次的编号：");
	scanf("%s",&s1->ccnum); 
	strcpy(b,s1->ccnum);
	s2=s1;
	s2->next=NULL;
	t++;
	printf("输入成功！\n");
	
	y=yhead;
	do{
		if(strcmp(a,y->yyname)==0){
					break;
		}
		y=y->next;
	} while(y!=NULL);
	
	
	y1=(struct yingting * )malloc(sizeof(struct yingting));
	if(i==0){
		yhead=y1;
	}else{
		y2->next=y1;
	}
	strcpy(y1->yynum,b);
	strcpy(y1->yyname,a);
    y1->r=y->r;
    y1->l=y->l;
    int k,j; 
    for( k=0;k<y1->r;k++){
        for(j=0;j<y1->l;j++){
        	if(y->yyseat[k][j]==0){
        		y1->yyseat[k][j]=1;
			}else{
				y1->yyseat[k][j]=y->yyseat[k][j];
			}
        }
    }
    strcpy(y1->bofang,c);
	y2=y1;
	y2->next=NULL;
	i++;
	printf("\n已经生成新座位表\n");
	
	
	
	
	system("pause");
	system("cls");
}

void delchangci(){
	if(t!=0){
		struct changci * k;
		char a[LEN];
		printf("请输入要删除的场次编号：");
		

		scanf("%s",&a);
		fflush(stdin);
		s=shead;
		for(;s!=NULL;s=s->next){
			if(strcmp(s->next->ccnum,a)==0){
				k=s->next;
				s->next=s->next->next;
				free(k);
				printf("该电影信息已经被删除啦！\n ");
				break; 
			}
		}
	}else{
		printf("******您还没有添加数据哟!"); 
	}
}

void modifychangci(){
	if(t!=0){
		int a;
		printf("\n1.按电影编号修改\n2.退出本菜单\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			amendccnum();
			break;
		case 2:
			return;
		default:printf("请在1-2之间选择\n");
		}
	}else{
		printf("******您还没有添加数据哟!\n");
		system("pause");
	} 
}

void amendccnum(){
	int c;
	int flag=0;
	char a[LEN];
	printf("请输入需要修改的电影编号：");

	scanf("%s",&a);
	fflush(stdin);
	s=shead;
	do{
		if(strcmp(a,s->ccnum)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			flag=1;
			break;
		}
		s=s->next;
	} while(s!=NULL);
	if(flag==1){
		printf("\n\n1.修改影片名称\n2.修改影片类型\n");
		printf("3.修改影片时长\n4.修改放映日期\n");
		printf("5.修改放映时间\n6.修改放映影厅\n");
		printf("7.修改票价\n8.修改余票\n");
		printf("9.修改影片编号\n"); 
		scanf("%d",&c);
		fflush(stdin);
	switch(c){
		case 1:
			printf("电影名称修改为：");
			scanf("%s",&s->ccname);
			break;
		case 2:
			printf("影片类型修改为：");
			scanf("%s",&s->cclabel);
			break;
		case 3:
			printf("影片时长修改为：");
			scanf("%s",&s->ccshichang);
			break;
		case 4:
			printf("影片放映日期修改为：");
			scanf("%s",&s->ccriqi);
			break;
		case 5:
			printf("影片放映时间修改为：");
			scanf("%s",&s->cctime);
			break;
		case 6:
			printf("影片放映影厅修改为：");
			scanf("%s",&s->ccyingting);
			break;
		case 7:
			printf("影片票价修改为：");
			scanf("%d",&s->ccpiaojia);
			break;
		case 8:
			printf("影片余票修改为：");
			scanf("%d",&s->ccyupiao);
			break;
		case 9:
			printf("场次编号修改为：");
			scanf("%s",s->ccnum);
			break; 
	}
	}
	if(flag==0){
		printf("不好意思，没有找到"); 
	}
	
}

void readchangci(){
	FILE *fp;
	if((fp=fopen(changci_txt,"rb"))==NULL){
		printf("Can not open file!");
		exit(-1);
	}
    while(!feof(fp)){
		s1=(struct changci *)malloc(sizeof(struct changci));
		if(t==0){
		    shead=s1;
		}
		else{
			s2->next=s1;
			s1->next=NULL;
		}
		fscanf(fp,"%s\t",&s1->ccname);
		fscanf(fp,"%s\t",&s1->cclabel);
		fscanf(fp,"%s\n",&s1->ccshichang);
		fscanf(fp,"%s\t",&s1->ccriqi);
		fscanf(fp,"%s\t",&s1->cctime);
		fscanf(fp,"%s\n",&s1->ccyingting);
		fscanf(fp,"%d\t",&s1->ccpiaojia);
		fscanf(fp,"%d\t",&s1->ccyupiao);
		fscanf(fp,"%s\n",&s1->ccnum);
        
		s2=s1;
		t+=1;;
	}
    fclose(fp);
}

void savechangci(){
	FILE *fp;
    struct changci *s;
    if((fp=fopen(changci_txt,"wb"))==NULL){
    	printf("Can not open the file!");  
	}
    s=shead;
    while(s!=NULL){
        fprintf(fp,"%s\t",s->ccname);
        fprintf(fp,"%s\t",s->cclabel);
        fprintf(fp,"%s\n",s->ccshichang);
        fprintf(fp,"%s\t",s->ccriqi);
        fprintf(fp,"%s\t",s->cctime);
        fprintf(fp,"%s\n",s->ccyingting);
        fprintf(fp,"%d\t",s->ccpiaojia);
        fprintf(fp,"%d\t",s->ccyupiao);
        fprintf(fp,"%s\n",s->ccnum);
        
		s=s->next;
    }
    fclose(fp);
	printf("\n存储完成\n");
	system("pause");
	system("cls");
}

void displaychangci(){
	if(t!=0){
		s=shead;
		int k=1;
		do{
			int m=t; 
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   影片名称   |  类型 |   时 长 |   放映日期  |    放映时间   |    放映影厅  |    票 价   |   余 票  |   编号   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t第%d页\t\t\t共%d页\n\n",k,m);
			k++;
			s=s->next;
		}while(s!=NULL);	
	}
	else{
		printf("******您还没有添加数据哟!\n");
	}
	system("pause");
	system("cls");
}

void readyingting(){
	FILE *fp;
	if((fp=fopen(yingting_txt,"rb"))==NULL){
		printf("Can not open file!");
		exit(-1);
	}
    while(!feof(fp)){
		y1=(struct yingting *)malloc(sizeof(struct yingting));
		if(i==0){
		    yhead=y1;
		}
		else{
			y2->next=y1;
			y1->next=NULL;
		}
		fscanf(fp,"%s\t",&y1->yynum);
		fscanf(fp,"%s\n",&y1->yyname);
		fscanf(fp,"%d\t",&y1->r);
		fscanf(fp,"%d\n",&y1->l);
		
		int k,j;
		for( k=0;k<y1->r;k++){
                for(j=0;j<y1->l;j++){
                        fscanf(fp,"%d",&y1->yyseat[k][j]);
                }
                fscanf(fp,"\n");
        }
        fscanf(fp,"%d\t",&y1->yishou);
		fscanf(fp,"%d\n",&y1->shouru);
		fscanf(fp,"%s\n",&y1->bofang);
		y2=y1;
		i+=1;;
	}
    fclose(fp);
}

void saveyingting(){
	FILE *fp;
    struct yingting*s;
    if((fp=fopen(yingting_txt,"wb"))==NULL){
    	printf("Can not open the file!");  
	}
    y=yhead;
    while(y!=NULL){
        fprintf(fp,"%s\t",y->yynum);
        fprintf(fp,"%s\n",y->yyname);
        fprintf(fp,"%d\t",y->r);
        fprintf(fp,"%d\n",y->l);
        int i,j;
        for(i=0;i<y->r;i++){
                for(j=0;j<y->l;j++){
                    fprintf(fp,"%d ",y->yyseat[i][j]);
                }
                fprintf(fp,"\n");
        }
        fprintf(fp,"%d\t",y->yishou);
        fprintf(fp,"%d\n",y->shouru);
        fprintf(fp,"%s\n",y->bofang);
        fprintf(fp,"\n");
		y=y->next;
    }
    fclose(fp);
	printf("\n存储完成\n");
	system("cls");
}

void displayyingtingusers(){
	if(i!=0){
		y=yhead;
		int t=1;
		do{
			int m=i; 
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t放映厅编号：%-s\t\t\t名称：%-s\t\n\t\t\t\t ○表示可用座位 ●表示已买座位 \n",y->yynum,y->yyname);
			printf("\t\t\t规格：%d ×%d\n",y->r,y->l);
			printf("\t\t\tノノノノノノノノノノノノノノノノノノノノノノノノノノノノノ\n");
			printf("\t\t\t                             ^屏                          \n");
			printf("\t\t\t                             |幕                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ○");
						}
						if(y->yyseat[k][j]==0){
							printf(" ●");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
                
        	}
			printf("\t\t\t\t\t\t电影：%s\n",y->bofang);
			printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t已售：%d\t\t\t收入：%d\n",y->yishou,y->shouru);
			
			printf("\t\t\t\t第%d页\t\t\t\t共%d页\n\n",t,m);
			t++;
			y=y->next;
		}while(y!=NULL);	
	}
	else{
		printf("******您还没有添加数据哟!\n");
	}
	system("pause");
	system("cls");
}

void displayyingting(){
	if(i!=0){
		y=yhead;
		int t=1;
		do{
			int m=i; 
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t放映厅编号：%-s\t\t\t名称：%-s\t\n\t\t\t\t ○表示可用座位 ●表示已买座位 \n",y->yynum,y->yyname);
			printf("\t\t\t规格：%d ×%d\n",y->r,y->l);
			printf("\t\t\tノノノノノノノノノノノノノノノノノノノノノノノノノノノノノ\n");
			printf("\t\t\t                             ^屏                          \n");
			printf("\t\t\t                             |幕                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ○");
						}
						if(y->yyseat[k][j]==0){
							printf(" ●");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
                
        	}
			printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t第%d页\t\t\t\t共%d页\n\n",t,m);
			t++;
			y=y->next;
		}while(y!=NULL);	
	}
	else{
		printf("******您还没有添加数据哟!\n");
	}
	system("pause");
	system("cls");
}

void addyingting(){
	y1=(struct yingting * )malloc(sizeof(struct yingting));
	if(i==0){
		yhead=y1;
	}else{
		y2->next=y1;
	}
	printf("请输入影厅的编号：");
    scanf("%s",&y1->yynum);
    printf("请输入影厅的名字：");
    scanf("%s",&y1->yyname);
    printf("请输入该影厅的行数：");
    scanf("%d",&y1->r);
    printf("请输入该影厅的列数：");
    scanf("%d",&y1->l);
    printf("请输入该影厅的座位信息：");
    int k,j; 
    for( k=0;k<y1->r;k++){
        for(j=0;j<y1->l;j++){
        	scanf("%d",&y1->yyseat[k][j]);
        	}
    }
	y2=y1;
	y2->next=NULL;
	i++;
	printf("输入成功！\n");
	system("pause");
	system("cls");
}

void delyingting(){
	if(i!=0){
		struct yingting * t;
		char a[LEN];
		printf("请输入要删除的影厅编号：");
		scanf("%s",&a);
		fflush(stdin);
		y=yhead;
		for(;y!=NULL;y=y->next){
			if(strcmp(y->next->yynum,a)==0){
				t=y->next;
				y->next=y->next->next;
				free(t);
				printf("该电影信息已经被删除啦！\n ");
				break; 
			}
		}
	}else{
		printf("******您还没有添加数据哟!"); 
	}
}

void modifyyingting(){
	if(i!=0){
		int a;
		printf("\n1.按影厅编号修改\n2.退出本菜单\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			amendyynum();
			break;
		case 2:
			return ;
		default:printf("请在1-2之间选择\n");
		}
	}else{
		printf("******您还没有添加数据哟!\n");
		system("pause");
	} 
}

void amendyynum(){
	int c;
	int flag=0;
	char a[LEN];
	printf("请输入需要修改的影厅编号：");
	scanf("%s",&a);
	fflush(stdin);
	y=yhead;
	do{
		if(strcmp(a,y->yynum)==0){
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t放映厅编号：%-s\t\t\t名称：%-s\t\n\t\t\t\t ○表示可用座位 ●表示损坏座位\n",y->yynum,y->yyname);
			printf("\t\t\t规格：%d ×%d\n",y->r,y->l);
			printf("\t\t\tノノノノノノノノノノノノノノノノノノノノノノノノノノノノノ\n");
			printf("\t\t\t                             ^屏                          \n");
			printf("\t\t\t                             |幕                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ○");
						}
						if(y->yyseat[k][j]==0){
							printf(" ●");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
                
        	}
			printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			flag=1;
			break;
		}
		y=y->next;
	} while(y!=NULL);
	if(flag==1){
		printf("\n\n1.修改影厅编号\n2.修改影厅名称\n");
		printf("3.修改影厅行数\n4.修改影厅列数\n");
		printf("5.修改座位\n");
		scanf("%d",&c);
		fflush(stdin);
		switch(c){
			case 1:
				printf("影厅编号修改为：");
				scanf("%s",&y->yynum);
				break;
			case 2:
				printf("影厅名称修改为：");
				scanf("%s",&y->yyname);
				break;
			case 3:
				printf("影厅行数修改为：");
				scanf("%d",&y->r);
				break;
			case 4:
				printf("影厅列数修改为：");
				scanf("%d",&y->l);
				break;
			case 5:
				printf("影厅座位修改为：");
				int k,j; 
			    for( k=0;k<y1->r;k++){
			        for(j=0;j<y1->l;j++){
			        	scanf("%d",&y1->yyseat[k][j]);
			        	}
			    }
				break;
		}
	}
	if(flag==0){
		printf("不好意思，没有找到"); 
	}
	
}

void tongji(){
	struct yingting*y;
	char a[LEN];
	printf("请输入查询的电影票房：" );
	scanf("%s",a); 
	int temp=0;
		y=yhead;
		do{	
			if(strcmp(a,y->bofang)==0){
				temp+=y->shouru;
			}	
			y=y->next;
		} while(y!=NULL);
		
		printf("%d元\n",temp);
		system("pause");
} 

int main(){
	yanzhengdenglu();
	mmain();
	return 0;
}
