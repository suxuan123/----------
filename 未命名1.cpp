#include<stdio.h>
#include<time.h>
#include<string.h>
void time(clock_t start,clock_t finish)
{
	double alltimes;
	alltimes=(double)(finish-start) / CLOCKS_PER_SEC;
	printf("用时：%f s\n",alltimes);
}
int main ()
{	
	clock_t start,finish;
	double alltimes;     //时间计算
	
	FILE *fp=NULL;
	char name[20];       //name文件名   文件操作
	
	char go[50],arrivals[50];        //go出发城市 arrivals到达城市
	char goa[50],arrivalsa[50];      // goa出发区域 arrivals到达区域
	char gok[50],arrivalsk[50];       //暂存 
	char cmane[50],type[50],shixiao[20];           //cmane公司名 type类型
	float zhongjia,zhongzhe,qingjia,qingzhe,zuipiao,h;
	
	int a,b,c,d,e,f;                 //计数器 
	char q;
	
	printf("欢迎使用物流信息管理系统！\n");
	printf("请输入文件名：\n");
	scanf("%s",name);
	start=clock();
	printf("\n");
	printf("读取文件中。。。\n"); 
	fp=fopen(name,"r");                //读取文件 
	
	if(fp==NULL){
		printf("读取错误！\n");
		finish=clock();
		alltimes=(double)(finish-start) / CLOCKS_PER_SEC;
		printf("用时：%f s\n",alltimes);
		return 0;                        //读取错误 
	}
	
	printf("读取成功！\n");
	
	finish=clock();
	time(start,finish);                       //读取文件计时 
	
	printf("输入出发城市：\n");
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
	
	printf("\n未找到此城市！");
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
	
	printf("请输入货物重量（吨）：");
	scanf("%f",&h);
	printf("请输入货物类型：（1.重货。2.轻货。）"); 
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
			printf("错误！\n");
			break;}
		}
	}
	
	finish=clock();
	time(start,finish);
	
	return 0;
 } 
