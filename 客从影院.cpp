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

void readusers();//��ȡ���� 
void zhuceusers();//ע�ᾭ�� 
void writeusers();// д�뾭�� 
void denglusers();// ��½����
void readshows();// ��ȡ��ƱԱ 
void zhuceshows();// ע����ƱԱ 
void writeshows();// д����ƱԱ 
void denglushows();// ��¼��ƱԱ 
void help();// ����ʹ��ϵͳ�İ��� 
void add();// ���ӰƬ��Ϣ 
void del();// ɾ��ӰƬ��Ϣ 
void modify();// �޸�ӰƬ��Ϣ 
void amendname();// ���յ�Ӱ�����޸�ӰƬ��Ϣ 
void amendid();// ���յ�Ӱ�����޸�ӰƬ��Ϣ 
void seek();// ����ӰƬ��Ϣ 
void findname();// ���յ�Ӱ���ֲ��� 
void findid();// ���յ�Ӱ������� 
void display();// ӰƬ��Ϣչʾ 
void save();// ӰƬ��Ϣ���� 
void read();// ӰƬ��Ϣ��ȡ 
void menu();//����ϵͳ��ҳ�� 
void mainmanger(); //����˵�ѡ�� 
void manger1();//��Ӱ��Ϣѡ�� 
void show2();// ������Ϣѡ�� 
void manger3();// Ӱ����Ϣѡ�� 
void menu1();//����˵���ҳ�� 
void menu1dy(); // ����˵ĵ�Ӱ���� 
void menu1yy();// ����˵�ӰԺ���� 
void menu2cc(); // ����˵ĳ��β��� 
void readchangci();// ��ȡ������Ϣ 
void savechangci();// ���泡����Ϣ 
void displaychangci();// չʾ������Ϣ 
void addchangci();// ���ӳ�����Ϣ 
void delchangci();// ɾ��������Ϣ 
void amendccnum();// ���ճ��� 
void modifychangci();// �޸ĳ�����Ϣ 
void readyingting();// ��ȡӰ����Ϣ 
void saveyingting();// ����Ӱ����Ϣ 
void displayyingting();// չʾӰ����Ϣ 
void addyingting();// ����Ӱ����Ϣ 
void delyingting();// ɾ��Ӱ����Ϣ 
void modifyyingting();// �޸�Ӱ����Ϣ 
void amendyynum();// ����Ӱ������޸� 
void menu2();// ��ƱԱ����ҳ�� 
void goupiao();// ��ƱԱ��Ʊ 
void tuipiao();// ��ƱԱ��Ʊ 
void mainshow();//��ƱԱѡ�� 
void xiugaiusersmima();//�޸ľ����˺����� 
void xiugaishowsmima();//�޸���ƱԱ���� 
void sortshowsyye();//����ƱԱӪҵ������ 
void displayyye();// չʾ��ƱԱӪҵ�� 
void displayyingtingusers();//�Ծ���չʾӰ����Ϣ 
void tongji();//ͳ��Ʊ�� 
void mmain();//������ 
void showsyye(); //�������ƱԱӪҵ������ 
void jiangxusort();//�������ƱԱӪҵ������ 
void xingming();//�����������ֵ������� 
void findchangci();//���ҵ�Ӱ�ĳ���ѡ�� 
void finddiany();//ֻ���Ҹõ�Ӱ�ĳ���
void findday();//ֻ���ҵ�ǰ�ĵ�Ӱ����
void findtwo();//��ȷ���ҳ��� 
 
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
	printf(" ��ѡ��ʲô˳������\n");
	printf("1.��������\n");
	printf("2.��������\n");
	printf("3.����������\n"); 
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
			printf("����1-3֮��ѡ��"); 
	}
}

void menu(){
	int num;
	printf("  *****************************************************\n\n");
	printf("  *                �ʹ�Ʊ�����ϵͳ                   *\n \n");
	printf("  *****************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�**********************\n");
	printf("  ------------------------   --------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               0.����                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               1.�������                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.��ƱԱ����               ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.�˳�                     ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
}

void menu1(){
	printf("  *****************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�**********************\n");
	printf("  ------------------------   --------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.��Ӱ����                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.Ӱ������                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.�޸�����                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.�鿴��ƱԱӪҵ��         ******\n");
	printf("  *****************************************************\n");
	printf("  *****               5.ͳ��Ʊ��                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               6.�˳�                     ******\n");
	printf("  *****************************************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
}

void help(){
	printf("\n0.��ӭʹ�ÿʹ�Ʊ��ϵͳ��������\n");
	printf("\n1.���ν���ϵͳ������Ϊ�ۻ�Ա����ע��һ���˺�;\n");
	printf("\n2.���Ѿ����˺���ֱ�ӵ�¼;\n");
	printf("\n4.���ӻ����޸�Ʊ����Ϣ��,�мǱ���;\n");
	printf("\n5.��л����ʹ�ã�\n"); 	
}

void menu1dy(){
	printf("  ******************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.�鿴���е�Ӱ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.����ӰƬ��Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.ɾ��ӰƬ��Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.�޸�ӰƬ��Ϣ             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.��ѯӰƬ��Ϣ             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               6.���浽�ļ����˳�         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
} 

void menu2cc(){
	printf("  ******************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.�鿴���г���             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.���ӳ�����Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.ɾ��������Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.�޸ĳ�����Ϣ             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.���浽�ļ����˳�         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
}

void menu1yy(){
	printf("  ******************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.�鿴����Ӱ��             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.����Ӱ����Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.ɾ��Ӱ����Ϣ             ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.�޸�Ӱ����Ϣ             ******\n");
	printf("  ************************** **************************\n");
	printf("  *****               5.���浽�ļ����˳�         ******\n");
	printf("  ************************** **************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
} 

void menu2(){
	printf("  ******************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�***********************\n");
	printf("  ------------------------   ---------------------------\n");
	printf("  *****************************************************\n");
	printf("  *****               1.������                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               2.��ѯ����                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               3.��Ʊ                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               4.��Ʊ                     ******\n");
	printf("  *****************************************************\n");
	printf("  *****               5.�޸�����                 ******\n");
	printf("  *****************************************************\n");
	printf("  *****               6.���浽�ļ����˳�         ******\n");
	printf("  *****************************************************\n");
	printf("  -------------------------   -------------------------\n");
	printf("��ѡ��˵����:");
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
									default:printf("����1-6֮��ѡ��\n");
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

									default:printf("����1-5֮��ѡ��\n");
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
	
										default:printf("����1-5֮��ѡ��\n");
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
					default:printf("����0-6֮��ѡ��\n");
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
	printf("�洢���\n");
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
	printf("�������Ӱ�����֣�");
    scanf("%s",&p1->dyname);
    printf("������õ�Ӱ���ݵ����֣�");
    scanf("%s",&p1->director);
    printf("�������ӰƬ��ʱ����");
    scanf("%s",&p1->time);
    printf("�������ӰƬ�ĵ�һ�����ݣ�");
    scanf("%s",&p1->zhuyan1);
    printf("�������ӰƬ�ĵڶ������ݣ�");
    scanf("%s",&p1->zhuyan2);
    printf("�������ӰƬ�ı�ǩ��");
    scanf("%s",&p1->label);
    printf("�������ӰƬ�ĵ�����");
	scanf("%s",&p1->area);
	printf("�������ӰƬ��Ʊ�ۣ�");
	scanf("%d",&p1->fare);
	printf("�������ӰƬ�ʺϵĹ�Ӱ��Ⱥ��");
	scanf("%s",&p1->shiyong);
	printf("�������ӰƬ�����ԣ�");
	scanf("%s",&p1->language);
	printf("�������ӰƬ�ı�ţ�");
	scanf("%s",&p1->id); 
	p2=p1;
	p2->next=NULL;
	n++;
	printf("����ɹ���\n");
	system("cls");
}

void del(){
	if(n!=0){
		struct piaowu * t;
		char a[LEN];
		printf("������Ҫɾ���ĵ�Ӱ���ƣ�");
		scanf("%s",&a);
		fflush(stdin);
		p=head;
		for(;p!=NULL;p=p->next){
			if(strcmp(p->next->dyname,a)==0){
				t=p->next;
				p->next=p->next->next;
				free(t);
				printf("�õ�Ӱ��Ϣ�Ѿ���ɾ������\n ");
				break; 
			}
		}
	}else{
		printf("******����û���������Ӵ!"); 
	}
}

void modify(){
	void amendname();
	void amendid();
	if(n!=0){
		int a;
		printf("1.����Ӱ�����޸�\n2.����Ӱ����޸�\n3.�˳����˵�\n");
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
		default:printf("����1-3֮��ѡ��\n");
		}
	}else{
		printf("******����û���������Ӵ!\n");
		system("pause");
	} 
}

void amendname(){
	int c;
	int flag=0;
	char a[LEN];
	printf("��������Ҫ�޸ĵĵ�Ӱ���ƣ�");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->dyname)==0){
			printf("\n���޸�ӰƬ����Ϣ���£�\n");
			printf("----------------------------------------------------------\n");
			printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			flag=1;
			break;
		}
		p=p->next;
	}while(p!=NULL);
	if(flag==1){
	 	printf("\n\n1.�޸ĵ�Ӱ����\n2.�޸ĵ�������\n");
		printf("3.�޸ĵ�һ����������\n4.�޸ĵڶ�����������\n");
		printf("5.�޸�ʱ��\n6.�޸ľ�Ŀ��ǩ\n");
		printf("7.�޸ĵ���\n8.�޸�Ʊ��\n");
		printf("9.�޸����˵Ĺ�Ӱ��Ⱥ\n10.�޸�ӰƬ����\n");
		printf("11.�޸�ӰƬ���\n"); 
		scanf("%d",&c);
		fflush(stdin);
		switch(c){
			case 1:
				printf("��Ӱ�����޸�Ϊ��");
				scanf("%s",&p->dyname);
				break;
			case 2:
				printf("ӰƬ�����޸�Ϊ��");
				scanf("%s",&p->director);
				break;
			case 3:
				printf("ӰƬ��һ�����������޸�Ϊ��");
				scanf("%s",&p->zhuyan1);
				break;
			case 4:
				printf("ӰƬ�ڶ������������޸�Ϊ��");
				scanf("%s",&p->zhuyan2);
				break;
			case 5:
				printf("ӰƬʱ���޸�Ϊ��");
				scanf("%s",&p->time);
				break;
			case 6:
				printf("ӰƬ��Ŀ��ǩ�޸�Ϊ��");
				scanf("%s",&p->label);
				break;
			case 7:
				printf("ӰƬ�����޸�Ϊ��");
				scanf("%s",&p->area);
				break;
			case 8:
				printf("ӰƬƱ���޸�Ϊ��");
				scanf("%d",&p->fare);
				break;
			case 9:
				printf("ӰƬ���˹ۿ�����Ⱥ�޸�Ϊ��");
				scanf("%s",&p->shiyong);
				break;
			case 10:
				printf("ӰƬ�����޸�Ϊ��");
				scanf("%s",&p->language);
				break;
			case 11:
				printf("ӰƬ����޸�Ϊ��");
				scanf("%s",&p->id);
				break; 
		}
		
	 }
	 else{
	 	printf("������˼��û���ҵ�"); 
	 }
	
}

void amendid(){
	int c;
	char a[LEN];
	printf("��������Ҫ�޸ĵĵ�Ӱ��ţ�");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->id)==0){
			printf("\n���޸�ӰƬ����Ϣ���£�\n");
			printf("----------------------------------------------------------\n");
			printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			break;
		}
		p=p->next;
	} while(p!=NULL);
	printf("\n\n1.�޸ĵ�Ӱ����\n2.�޸ĵ�������\n");
	printf("3.�޸ĵ�һ����������\n4.�޸ĵڶ�����������\n");
	printf("5.�޸�ʱ��\n6.�޸ľ�Ŀ��ǩ\n");
	printf("7.�޸ĵ���\n8.�޸�Ʊ��\n");
	printf("9.�޸����˵Ĺ�Ӱ��Ⱥ\n10.�޸�ӰƬ����\n");
	printf("11.�޸�ӰƬ���\n"); 
	scanf("%d",&c);
	fflush(stdin);
	switch(c){
		case 1:
			printf("��Ӱ�����޸�Ϊ��");
			scanf("%s",&p->dyname);
			break;
		case 2:
			printf("ӰƬ�����޸�Ϊ��");
			scanf("%s",&p->director);
			break;
		case 3:
			printf("ӰƬ��һ�����������޸�Ϊ��");
			scanf("%s",&p->zhuyan1);
			break;
		case 4:
			printf("ӰƬ�ڶ������������޸�Ϊ��");
			scanf("%s",&p->zhuyan2);
			break;
		case 5:
			printf("ӰƬʱ���޸�Ϊ��");
			scanf("%s",&p->time);
			break;
		case 6:
			printf("ӰƬ��Ŀ��ǩ�޸�Ϊ��");
			scanf("%s",&p->label);
			break;
		case 7:
			printf("ӰƬ�����޸�Ϊ��");
			scanf("%s",&p->area);
			break;
		case 8:
			printf("ӰƬƱ���޸�Ϊ��");
			scanf("%d",&p->fare);
			break;
		case 9:
			printf("ӰƬ���˹ۿ�����Ⱥ�޸�Ϊ��");
			scanf("%s",&p->shiyong);
			break;
		case 10:
			printf("ӰƬ�����޸�Ϊ��");
			scanf("%s",&p->language);
			break;
		case 11:
			printf("ӰƬ����޸�Ϊ��");
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
			printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
			printf("----------------------------------------------------------\n");
			printf("\t\t��%dҳ\t\t\t��%dҳ\n\n",t,m);
			t++;
			p=p->next;
		}while(p!=NULL);
	}
	else{
		printf("******����û���������Ӵ!\n");
	}
	system("pause");
	system("cls");

}

void seek(){
	void findname();
	void findid();
	if(n!=0){
		int a;
		printf("1.����Ӱ���Ʋ���\n2.����Ӱ��Ų�ѯ\n3.�˳����˵�\n");
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
		default:printf("����1-3֮��ѡ��\n");
		}
	}else{
		printf("******����û���������Ӵ!\n");
		system("pause");
	}
}

void findtwo(){
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN];
	struct changci *s;
	s=shead;
	printf("��������Ҫ��ѯ�ĵ�Ӱ���ƣ�");
	scanf("%s",a);
	printf("��������Ҫ��ѯ�ĳ������ڣ�");
	scanf("%s",c); 
	do{
		if(strcmp(a,s->ccname)==0&&strcmp(c,s->ccriqi)){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
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
		printf("\n\t\t\t��������֤�룺");
		j=0;
		while(j<5&&(ch=getch())!='\r'){
			passWord[j++]=ch;
			putchar('*');
		}
		passWord[j]='\0';
		if(strcmp(passWord,"asdf")==0){
			system("cls");
			printf("\n\t\t\t\t��֤�ɹ���\n");
			break;
		}else{
				printf("\n\n\t\t\t����������������룡\n");	
		}
}
	if(i>3){
		printf("\n\t\t\t�����Ѿ�����3�Σ�����Ȩʹ�ã����˳���\n");
		getch();
		exit(0);
	}
	system("cls");
}

void findname(){
	char a[LEN];
	printf("��������Ҫ���ҵĵ�Ӱ���ƣ�");
	scanf("%s",&a);
	p=head;
	char * f;
	int flag=0;
	do{
		if(strcmp(a,p->dyname)==0){
			printf("\n���ҵ���ӰƬ����Ϣ���£�\n");
			printf("----------------------------------------------------------\n");
			printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
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
				printf("\n�����Ҫ����ӰƬ����Ϣ���£�\n");
				printf("----------------------------------------------------------\n");
				printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
				printf("----------------------------------------------------------\n");
			}
			p=p->next;
		}while(p!=NULL);
	}
	
}

void findid(){
	char a[LEN];
	printf("������Ҫ���ҵ�ӰƬ��ţ�");
	scanf("%s",&a);
	fflush(stdin);
	p=head;
	do{
		if(strcmp(a,p->id)==0){
			printf("\n���ҵ���ӰƬ����Ϣ���£�\n");
			printf("----------------------------------------------------------\n");
			printf("||��Ӱ���ƣ�%-s\t\t\t���ݣ�%-s\t||\n||���ݣ�%-s    %-s\tʱ����%-s \t\t||\n||��Ŀ��ǩ��%-s\t������%-s\tƱ�ۣ�%-d\t||\n||��Ӱ��Ⱥ��%-s\t���ԣ�%-s\tID:%-s\t||\n",p->dyname,p->director,p->zhuyan1,p->zhuyan2,p->time,p->label,p->area,p->fare,p->shiyong,p->language,p->id);
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
        printf("\t\t\t\t�û�ע��");
        printf("\n\t\t�û���:");
        fflush(stdin);
        scanf("%s",&q1->username);
        fp=fopen(users_txt,"r");
        do{
        	if(strcmp(q1->username,q->username)==0){
        		printf("\n\t���û����Ѿ����ڣ�");
				printf("%s\t",q->username);
				printf("%s\n",q->userpass);
				fclose(fp);
				printf("�㻹Ҫ����ע����\n1.��������ע��\n2.��¼�˺�\n");
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
        printf("\n\t\t��  ��:");
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
        printf("\n\t\tȷ������:");
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
			printf("\n\t\t�������벻һ�������������룡"); 
		}
    }while(strcmp(q1->userpass,temp)!=0);
    fp=fopen(users_txt,"w");
    if(fp==NULL){
          printf("\n\tע��ʧ��\n");
          exit(0);
       }else{
        system("cls");
        printf("\n\tע��ɹ�");
        
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
	printf("\n�洢���\n");
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
    printf("\n\t\t\t�û���¼");
    printf("\n\t\t�û�����15���ַ�֮��Ŷ��"); 
    printf("\n\n\t\t�û���:");
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
        printf("\n\t\t�û�������,��ע��");
        printf("\n\t\t1.ע��\n\t\t2.���µ�½\n");
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
    	printf("\n\n\t\t��  ��:");
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
			printf("\n\t\t�������\n\t\t1.�˳� \n\t\t2.���µ�¼\n");
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
	printf("\n\n\t\t��¼�ɹ�,��ӭʹ��!\n");
	system("pause");
	system("cls");
	return ;
}

void xiugaiusersmima(){
	FILE *fp;
	printf("\n\t\t������ԭʼ���룺");
	
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
        printf("\n\t\t����������������룺");
		return xiugaiusersmima(); 
	}   
    printf("\n\n\t\t�������µ����룺");
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
    	printf("\n\n\t\t��  ��:");
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
			printf("\n\t\t�������벻һ�£�����������");
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
	printf("\n\t\t�޸ĳɹ�,��ӭʹ��!\n");
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
        printf("\t\t\t\t�û�ע��");
        printf("\n\t\t�û���:");
        scanf("%s",&l1->showname);
        fflush(stdin);
        fp=fopen(shows_txt,"r");
        do{
        	if(strcmp(l1->showname,l->showname)==0){
        		printf("\n\t���û����Ѿ����ڣ�");
				fclose(fp);
				printf("�㻹Ҫ����ע����\n1.��������ע��\n2.��¼�˺�\n");
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
        printf("\n\t\t��  ��:");
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
        printf("\n\t\tȷ������:");
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
			printf("\n\t\t�������벻һ�������������룡"); 
		}
    }while(strcmp(l1->showpass,temp)!=0);
    printf("\n\t\t��ǰҵ����");
    scanf("%d",&l1->yeji);
    fflush(stdin);
    fp=fopen(shows_txt,"w");
    if(fp==NULL){
          printf("\n\tע��ʧ��\n");
          exit(0);
       }else{
        system("cls");
        printf("\n\tע��ɹ�");
        
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
	printf("\n�洢���\n");
	system("cls");
}

void denglushows(){
	FILE *fp;
	char u[LEN],c[LEN],temp[LEN],ch;
	int m=0;
	int o,p;
	system("cls");
    printf("\n\t\t\t\t��ƱԱ��¼");
    printf("\n\t\t�û���:");
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
        printf("\n\t\t��ƱԱ������,��ע��");
        printf("\n\t\t1.ע��\n\t\t2.���µ�½\n");
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
    	printf("\n\t\t��  ��:");
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
			printf("\n\t\t�������\n\t\t1.�˳� \n\t\t2.���µ�¼\n");
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
	printf("\n\t\t��¼�ɹ�,��ӭʹ��!\n");
	
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
	printf("\n\t\t������ԭʼ���룺");
	
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
        printf("\n\t\t����������������룺");
		return xiugaishowsmima(); 
	}   
    printf("\n\n\t\t�������µ����룺");
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
    	printf("\n\n\t\t��  ��:");
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
			printf("\n\t\t�������벻һ�£�����������");
			return xiugaishowsmima(); 
		}
	}while(strcmp(c,u)!=0);
	l=hhead;
    do{
    	if(strcmp(t,l->showpass)==0){
			strcpy(l->showpass,c);
		}l=l->next;
	}while(l!=NULL);
	printf("\n\t\t�޸ĳɹ�,��ӭʹ��!\n");
	return denglushows();
	system("pause");
	system("cls");	
}

void displayyye(){
	if(z!=0){
		l=hhead;
		printf("\n����\t\tӪҵ��\n"); 
		do{ 
		
			
			printf("\n%s\t\t%d\n",l->showname,l->yeji);
			
			l=l->next;
		}while(l!=NULL);
	}
	else{
		printf("******����û���������Ӵ!\n");
	}
	system("pause");
	system("cls");
}

void findchangci(){
	printf("1.ֻ��ѯĳ��ĳ���\n");
	printf("2.ֻ��ѯĳ����Ӱ�ĳ���\n");
	printf("3.��ѯĳ����Ӱĳ��ĳ���\n"); 
	printf("4.�˳�\n"); 
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
	printf("������Ҫ���ҵĳ������ڣ�");
	scanf("%s",a);
	do{
		if(strcmp(a,s->ccriqi)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
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
	printf("��������Ҫ��ѯ�ĵ�Ӱ���ƣ�");
	scanf("%s",a);
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
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
	printf("��������Ҫ����ĵ�Ӱ���ƣ�");
	fflush(stdin);
	scanf("%s",a);
	fflush(stdin);
	int flag=0;
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			flag=1;
		}s=s->next;
	}while(s!=NULL);
	if(flag=1){
		printf("\n��ѡ�񳡴α�ţ�");
	
	scanf("%s",c); 
	fflush(stdin);
	printf("��ѡ�������λ~\n");
	struct yingting*y;
	y=yhead;
	do{
		if(strcmp(c,y->yynum)==0){
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t��ӳ����ţ�%-s\t\t\t���ƣ�%-s\t\n\t\t\t\t ���ʾ������λ ���ʾ����λ\n",y->yynum,y->yyname);
			printf("\t\t\t���%d ��%d\n",y->r,y->l);
			printf("\t\t\t�ΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥ�\n");
			printf("\t\t\t                             ^��                          \n");
			printf("\t\t\t                             |Ļ                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ��");
						}
						if(y->yyseat[k][j]==0){
							printf(" ��");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
            }
            printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t���ۣ�%d\t\t\t���룺%d\n",y->yishou,y->shouru);

		}
		y=y->next;		
	} while(y!=NULL);
	
	int v;
	printf("\n����ȷ��ѡ����λ��\n");
	printf("\n1.ȷ��\n");
	printf("\n2.�˳�\n"); 
	
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
		printf("\n������ڼ��ŵڼ���~\n");
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
			printf("\nѡ��λ�ɹ���"); 
			printf("\n\t\t====================================================================");
			printf("\n\t\t||Hi�`�`�`�`�`                            �ʹ�ӰԺ                ||");
			printf("\n\t\t||  ��  *��.  ����                  %10s                ||",y->yyname);
			printf("\n\t\t||��  . �ģߡġ��ɡ�* ��            %10s                    ||",y->yynum);
			printf("\n\t\t||*  �� (�� ��)/ .                  %d��%d��                        ||",w,b);
			printf("\n\t\t||��.  <���� ��* ��                                               ||");
			printf("\n\t\t||�� * (�� ��  .��             ��Ӱ��%s                     ||",s->ccname);
			printf("\n\t\t||���� (��                                                        ||");
			printf("\n\t\t||  %-10s           %s                     �������   ||",s->ccriqi,s->cctime);
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
			printf("\nѡ����λ������!\n");
			printf("\n����ѡ���!\n");
			return goupiao();
		}
		else{
			printf("\n������˼����ѡ����ǹ���Ŷ��\n");
			printf("\n������ѡ��ɣ�\n");
			return goupiao(); 
		}
			
	}
	if(v==2){
		return ;	
	}
	}
	else{
		printf("�����ӰƬû���ҵ�Ŷ��\n");
		return; 
	}
		
	
}

void tuipiao(){ 
	struct shows * l;
	l=hhead;
	char a[LEN],c[LEN],t[LEN];
	struct changci *s;
	s=shead;
	printf("\n\t\t��������Ҫ��Ʊ�ĵ�Ӱ���ƣ�");
	fflush(stdin);
	scanf("%s",a);
	fflush(stdin);
	do{
		if(strcmp(a,s->ccname)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}s=s->next;
	}while(s!=NULL);
	printf("\n\t\t�������ӳ�����:");
	scanf("%s",&c);
		struct yingting*y;
		y=yhead;
		do{
			if(strcmp(c,y->yynum)==0){
				printf("\t\t\t----------------------------------------------------------\n");
				printf("\t\t\t��ӳ����ţ�%-s\t\t\t���ƣ�%-s\t\n\t\t\t\t ���ʾ������λ ���ʾ����λ\n",y->yynum,y->yyname);
				printf("\t\t\t���%d ��%d\n",y->r,y->l);
				printf("\t\t\t�ΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥ�\n");
				printf("\t\t\t                             ^��                          \n");
				printf("\t\t\t                             |Ļ                          \n");
				int k,j;
				printf("\t\t\t");
				for(k=0;k<y->r;k++){
	                for(j=0;j<y->l;j++){
	                        if(y->yyseat[k][j]==1){
	                        	printf(" ��");
							}
							if(y->yyseat[k][j]==0){
								printf(" ��");
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
		
	//��Ʊ��
	s=shead;
		do{
			if(strcmp(c,s->ccnum)==0){
				break;
			}s=s->next;
		}while(s!=NULL);
	printf("\n\t\t��������λ~");
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
		printf("\n��Ʊ�ɹ�Ŷ��\n");
	}else{
		printf("�����λ��ʱû��Ԥ��Ŷ��"); 
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
	printf("�������Ӱ�����֣�");
    scanf("%s",&s1->ccname);
    strcpy(c,s1->ccname);
    fflush(stdin);
    printf("�������ӰƬ�ı�ǩ��");
    scanf("%s",&s1->cclabel);
    printf("�������ӰƬ��ʱ����");
	scanf("%s",&s1->ccshichang);
	printf("�����볡�ε����ڣ�");
	scanf("%s",&s1->ccriqi);
	printf("������ó��ε�ʱ�䣺");
	scanf("%s",&s1->cctime); 
	printf("������ó��ε�Ӱ����"); 
	scanf("%s",&s1->ccyingting); 
	strcpy(a,s1->ccyingting);
	printf("�������ӰƬ��Ʊ�ۣ�");
	scanf("%d",&s1->ccpiaojia);
	printf("��������Ʊ��");
	scanf("%d",&s1->ccyupiao); 
	printf("������ó��εı�ţ�");
	scanf("%s",&s1->ccnum); 
	strcpy(b,s1->ccnum);
	s2=s1;
	s2->next=NULL;
	t++;
	printf("����ɹ���\n");
	
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
	printf("\n�Ѿ���������λ��\n");
	
	
	
	
	system("pause");
	system("cls");
}

void delchangci(){
	if(t!=0){
		struct changci * k;
		char a[LEN];
		printf("������Ҫɾ���ĳ��α�ţ�");
		

		scanf("%s",&a);
		fflush(stdin);
		s=shead;
		for(;s!=NULL;s=s->next){
			if(strcmp(s->next->ccnum,a)==0){
				k=s->next;
				s->next=s->next->next;
				free(k);
				printf("�õ�Ӱ��Ϣ�Ѿ���ɾ������\n ");
				break; 
			}
		}
	}else{
		printf("******����û���������Ӵ!"); 
	}
}

void modifychangci(){
	if(t!=0){
		int a;
		printf("\n1.����Ӱ����޸�\n2.�˳����˵�\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			amendccnum();
			break;
		case 2:
			return;
		default:printf("����1-2֮��ѡ��\n");
		}
	}else{
		printf("******����û���������Ӵ!\n");
		system("pause");
	} 
}

void amendccnum(){
	int c;
	int flag=0;
	char a[LEN];
	printf("��������Ҫ�޸ĵĵ�Ӱ��ţ�");

	scanf("%s",&a);
	fflush(stdin);
	s=shead;
	do{
		if(strcmp(a,s->ccnum)==0){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			flag=1;
			break;
		}
		s=s->next;
	} while(s!=NULL);
	if(flag==1){
		printf("\n\n1.�޸�ӰƬ����\n2.�޸�ӰƬ����\n");
		printf("3.�޸�ӰƬʱ��\n4.�޸ķ�ӳ����\n");
		printf("5.�޸ķ�ӳʱ��\n6.�޸ķ�ӳӰ��\n");
		printf("7.�޸�Ʊ��\n8.�޸���Ʊ\n");
		printf("9.�޸�ӰƬ���\n"); 
		scanf("%d",&c);
		fflush(stdin);
	switch(c){
		case 1:
			printf("��Ӱ�����޸�Ϊ��");
			scanf("%s",&s->ccname);
			break;
		case 2:
			printf("ӰƬ�����޸�Ϊ��");
			scanf("%s",&s->cclabel);
			break;
		case 3:
			printf("ӰƬʱ���޸�Ϊ��");
			scanf("%s",&s->ccshichang);
			break;
		case 4:
			printf("ӰƬ��ӳ�����޸�Ϊ��");
			scanf("%s",&s->ccriqi);
			break;
		case 5:
			printf("ӰƬ��ӳʱ���޸�Ϊ��");
			scanf("%s",&s->cctime);
			break;
		case 6:
			printf("ӰƬ��ӳӰ���޸�Ϊ��");
			scanf("%s",&s->ccyingting);
			break;
		case 7:
			printf("ӰƬƱ���޸�Ϊ��");
			scanf("%d",&s->ccpiaojia);
			break;
		case 8:
			printf("ӰƬ��Ʊ�޸�Ϊ��");
			scanf("%d",&s->ccyupiao);
			break;
		case 9:
			printf("���α���޸�Ϊ��");
			scanf("%s",s->ccnum);
			break; 
	}
	}
	if(flag==0){
		printf("������˼��û���ҵ�"); 
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
	printf("\n�洢���\n");
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
			printf("|   ӰƬ����   |  ���� |   ʱ �� |   ��ӳ����  |    ��ӳʱ��   |    ��ӳӰ��  |    Ʊ ��   |   �� Ʊ  |   ���   |\n");
			printf("|%14s|%7s|%9s|%7s|%15s|%10s|%12d|%10d|%10s|\n",s->ccname,s->cclabel,s->ccshichang,s->ccriqi,s->cctime,s->ccyingting,s->ccpiaojia,s->ccyupiao,s->ccnum);
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t��%dҳ\t\t\t��%dҳ\n\n",k,m);
			k++;
			s=s->next;
		}while(s!=NULL);	
	}
	else{
		printf("******����û���������Ӵ!\n");
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
	printf("\n�洢���\n");
	system("cls");
}

void displayyingtingusers(){
	if(i!=0){
		y=yhead;
		int t=1;
		do{
			int m=i; 
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t��ӳ����ţ�%-s\t\t\t���ƣ�%-s\t\n\t\t\t\t ���ʾ������λ ���ʾ������λ \n",y->yynum,y->yyname);
			printf("\t\t\t���%d ��%d\n",y->r,y->l);
			printf("\t\t\t�ΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥ�\n");
			printf("\t\t\t                             ^��                          \n");
			printf("\t\t\t                             |Ļ                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ��");
						}
						if(y->yyseat[k][j]==0){
							printf(" ��");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
                
        	}
			printf("\t\t\t\t\t\t��Ӱ��%s\n",y->bofang);
			printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t���ۣ�%d\t\t\t���룺%d\n",y->yishou,y->shouru);
			
			printf("\t\t\t\t��%dҳ\t\t\t\t��%dҳ\n\n",t,m);
			t++;
			y=y->next;
		}while(y!=NULL);	
	}
	else{
		printf("******����û���������Ӵ!\n");
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
			printf("\t\t\t��ӳ����ţ�%-s\t\t\t���ƣ�%-s\t\n\t\t\t\t ���ʾ������λ ���ʾ������λ \n",y->yynum,y->yyname);
			printf("\t\t\t���%d ��%d\n",y->r,y->l);
			printf("\t\t\t�ΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥ�\n");
			printf("\t\t\t                             ^��                          \n");
			printf("\t\t\t                             |Ļ                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ��");
						}
						if(y->yyseat[k][j]==0){
							printf(" ��");
						}
						if(y->yyseat[k][j]==3){
							printf("   ");
						}
                }
                	printf("\n\t\t\t");
                
        	}
			printf("\n");
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t\t��%dҳ\t\t\t\t��%dҳ\n\n",t,m);
			t++;
			y=y->next;
		}while(y!=NULL);	
	}
	else{
		printf("******����û���������Ӵ!\n");
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
	printf("������Ӱ���ı�ţ�");
    scanf("%s",&y1->yynum);
    printf("������Ӱ�������֣�");
    scanf("%s",&y1->yyname);
    printf("�������Ӱ����������");
    scanf("%d",&y1->r);
    printf("�������Ӱ����������");
    scanf("%d",&y1->l);
    printf("�������Ӱ������λ��Ϣ��");
    int k,j; 
    for( k=0;k<y1->r;k++){
        for(j=0;j<y1->l;j++){
        	scanf("%d",&y1->yyseat[k][j]);
        	}
    }
	y2=y1;
	y2->next=NULL;
	i++;
	printf("����ɹ���\n");
	system("pause");
	system("cls");
}

void delyingting(){
	if(i!=0){
		struct yingting * t;
		char a[LEN];
		printf("������Ҫɾ����Ӱ����ţ�");
		scanf("%s",&a);
		fflush(stdin);
		y=yhead;
		for(;y!=NULL;y=y->next){
			if(strcmp(y->next->yynum,a)==0){
				t=y->next;
				y->next=y->next->next;
				free(t);
				printf("�õ�Ӱ��Ϣ�Ѿ���ɾ������\n ");
				break; 
			}
		}
	}else{
		printf("******����û���������Ӵ!"); 
	}
}

void modifyyingting(){
	if(i!=0){
		int a;
		printf("\n1.��Ӱ������޸�\n2.�˳����˵�\n");
		scanf("%d",&a);
		fflush(stdin);
		switch(a){
		case 1:
			amendyynum();
			break;
		case 2:
			return ;
		default:printf("����1-2֮��ѡ��\n");
		}
	}else{
		printf("******����û���������Ӵ!\n");
		system("pause");
	} 
}

void amendyynum(){
	int c;
	int flag=0;
	char a[LEN];
	printf("��������Ҫ�޸ĵ�Ӱ����ţ�");
	scanf("%s",&a);
	fflush(stdin);
	y=yhead;
	do{
		if(strcmp(a,y->yynum)==0){
			printf("\t\t\t----------------------------------------------------------\n");
			printf("\t\t\t��ӳ����ţ�%-s\t\t\t���ƣ�%-s\t\n\t\t\t\t ���ʾ������λ ���ʾ����λ\n",y->yynum,y->yyname);
			printf("\t\t\t���%d ��%d\n",y->r,y->l);
			printf("\t\t\t�ΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥΥ�\n");
			printf("\t\t\t                             ^��                          \n");
			printf("\t\t\t                             |Ļ                          \n");
			int k,j;
			printf("\t\t\t");
			for(k=0;k<y->r;k++){
                for(j=0;j<y->l;j++){
                        if(y->yyseat[k][j]==1){
                        	printf(" ��");
						}
						if(y->yyseat[k][j]==0){
							printf(" ��");
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
		printf("\n\n1.�޸�Ӱ�����\n2.�޸�Ӱ������\n");
		printf("3.�޸�Ӱ������\n4.�޸�Ӱ������\n");
		printf("5.�޸���λ\n");
		scanf("%d",&c);
		fflush(stdin);
		switch(c){
			case 1:
				printf("Ӱ������޸�Ϊ��");
				scanf("%s",&y->yynum);
				break;
			case 2:
				printf("Ӱ�������޸�Ϊ��");
				scanf("%s",&y->yyname);
				break;
			case 3:
				printf("Ӱ�������޸�Ϊ��");
				scanf("%d",&y->r);
				break;
			case 4:
				printf("Ӱ�������޸�Ϊ��");
				scanf("%d",&y->l);
				break;
			case 5:
				printf("Ӱ����λ�޸�Ϊ��");
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
		printf("������˼��û���ҵ�"); 
	}
	
}

void tongji(){
	struct yingting*y;
	char a[LEN];
	printf("�������ѯ�ĵ�ӰƱ����" );
	scanf("%s",a); 
	int temp=0;
		y=yhead;
		do{	
			if(strcmp(a,y->bofang)==0){
				temp+=y->shouru;
			}	
			y=y->next;
		} while(y!=NULL);
		
		printf("%dԪ\n",temp);
		system("pause");
} 

int main(){
	yanzhengdenglu();
	mmain();
	return 0;
}
