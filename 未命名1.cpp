#include<stdio.h>
#include<time.h>
#include<string.h>
void time(clock_t start,clock_t finish)
{
	double alltimes;
	alltimes=(double)(finish-start) / CLOCKS_PER_SEC;
	printf("��ʱ��%f s\n",alltimes);
}
int main ()
{	
	clock_t start,finish;
	double alltimes;     //ʱ�����
	
	FILE *fp=NULL;
	char name[20];       //name�ļ���   �ļ�����
	
	char go[50],arrivals[50];        //go�������� arrivals�������
	char goa[50],arrivalsa[50];      // goa�������� arrivals��������
	char gok[50],arrivalsk[50];       //�ݴ� 
	char cmane[50],type[50],shixiao[20];           //cmane��˾�� type����
	float zhongjia,zhongzhe,qingjia,qingzhe,zuipiao,h;
	
	int a,b,c,d,e,f;                 //������ 
	char q;
	
	printf("��ӭʹ��������Ϣ����ϵͳ��\n");
	printf("�������ļ�����\n");
	scanf("%s",name);
	start=clock();
	printf("\n");
	printf("��ȡ�ļ��С�����\n"); 
	fp=fopen(name,"r");                //��ȡ�ļ� 
	
	if(fp==NULL){
		printf("��ȡ����\n");
		finish=clock();
		alltimes=(double)(finish-start) / CLOCKS_PER_SEC;
		printf("��ʱ��%f s\n",alltimes);
		return 0;                        //��ȡ���� 
	}
	
	printf("��ȡ�ɹ���\n");
	
	finish=clock();
	time(start,finish);                       //��ȡ�ļ���ʱ 
	
	printf("����������У�\n");
	scanf("%s",go);
	start=clock();
	fseek(fp,0,0);
	fscanf(fp,"%s",cmane);
	fscanf(fp,"%s",gok);
	if(strcmp(gok,go)==0)goto a; 
	for(;!feof(fp);)
	{
		for(;!feof(fp);)
		{
			a=getc(fp);
			if(a=='\n')break;	
			fseek(fp,1L,1);
		}
		fscanf(fp,"%s",cmane);
		fscanf(fp,"%s",gok);
		if(strcmp(gok,go)==0)goto a; 
	}
	
	printf("\nδ�ҵ��˳��У�");
	finish=clock();
	time(start,finish);
	return 0;
	
	a:
	printf("%s\n",cmane);
	for(;!feof(fp);)
	{
		for(;!feof(fp);)
		{
			a=getc(fp);
			if(a=='\n')
			{
				break;	
			}
			fseek(fp,1L,1);
		}
		fscanf(fp,"%s %s",cmane,gok);
		if(strcmp(gok,go)==0)printf("%s\n",cmane);
		else break;
	}
	
	finish=clock();
	time(start,finish);
	
	printf("����������������֣���");
	scanf("%f",&h);
	printf("������������ͣ���1.�ػ���2.�������"); 
	scanf("%d",&b);
	
	start=clock();
	
	fseek(fp,0,0);
	fscanf(fp,"%s",cmane);
	fscanf(fp,"%s",gok);
	if(strcmp(gok,go)==0)goto b; 
	for(;!feof(fp);)
	{
		for(;!feof(fp);)
		{
			a=getc(fp);
			if(a=='\n')break;	
			fseek(fp,1L,1);
		}
		fscanf(fp,"%s",cmane);
		fscanf(fp,"%s",gok);
		if(strcmp(gok,go)==0)break;
	}
	b:{
		for(;!feof(fp);)
		{
			a=getc(fp);printf("%s,%c\n",cmane,a);
			if(a=='\n')break;	
			fseek(fp,-2L,1);
		}
		for(;!feof(fp);){
		fscanf(fp,"%s",cmane);
		fscanf(fp,"%s",gok);
		if(strcmp(gok,go)!=0)break;
		fscanf(fp,"%c",&q);
		if(q=='\t'||q==' ')goa[0]='\0';
		else 
		{
			fseek(fp,-2L,1);
			fscanf(fp,"%s",goa);
		}
		fscanf(fp,"%s",arrivals);
		fscanf(fp,"%c",&q);
		fscanf(fp,"%c",&q);
		if(q=='\t'||q==' ')arrivalsa[0]='\0';
		else 
		{
			fseek(fp,-2L,1);
			fscanf(fp,"%s",arrivalsa);
		}
		fscanf(fp,"%c",&q);
		if(q=='\t'||q==' ')shixiao[0]='0';
		else 
		{
			fseek(fp,-2L,1);
			fscanf(fp,"%d",&shixiao);
		}
		fscanf(fp,"%s%f%f%f%f%f",type,zhongjia,zhongzhe,qingjia,qingzhe,zuipiao);
		if(b==1)printf("%g\n",zhongjia*zhongzhe*h);
		if(b==2)printf("%g\n",qingjia*qingzhe*h);
		else {
			printf("����\n");
			break;}
		}
	}
	
	finish=clock();
	time(start,finish);
	
	return 0;
 } 
