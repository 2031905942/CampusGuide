#include<stdio.h>//无向带权图 
#include<stdlib.h>
#include<string.h>
#define Infinity 2000//表示无穷大 
#define MaxVertexNum 50
#define MAX 50
#define key 26//key为顶点个数 
typedef struct arcell//边的权值信息
{ 	int adj;//权值  
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum];//图的邻接矩阵类型
typedef struct vexsinfo//顶点信息 
{ 	int position;//景点的编号 
	char name[32];//景点的名称 
	char introduction[256];//景点的介绍
}vexsinfo;
typedef struct mgraph//图结构信息
{  	vexsinfo vexs[MaxVertexNum];//顶点向量（数组） 
	adjmatrix arcs;//邻接矩阵 
	int vexnum,arcnum;//顶点数和边数 
}mgraph;
//全局变量
mgraph campus; //图变量（大学校园） 
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];//定义全局变量存储最小路径 
int pathh[MaxVertexNum][MaxVertexNum];//定义存储路径 
mgraph initgraph()
{	int i=0,j=0;
	mgraph c;
	c.vexnum=26;//顶点个数 
	c.arcnum=47;//边的个数 
	for(i=1;i<=key;i++)//依次设置顶点编号 
	  c.vexs[i].position=i;
	//依次输入顶点信息
	strcpy(c.vexs[1].name,"工商学院楼");
	strcpy(c.vexs[1].introduction,"工商管理学院的学院楼，其基础设施等条件在学校里是名列前茅的"); 
	strcpy(c.vexs[2].name,"三食堂");
	strcpy(c.vexs[2].introduction,"emmm没怎么去过，难以介绍"); 
	strcpy(c.vexs[3].name,"第三教学楼");
	strcpy(c.vexs[3].introduction,"3"); 
	strcpy(c.vexs[4].name,"问鼎广场");
	strcpy(c.vexs[4].introduction,"4"); 
	strcpy(c.vexs[5].name,"北区宿舍楼");
	strcpy(c.vexs[5].introduction,"5"); 
	strcpy(c.vexs[6].name,"南区北门、校医院");
	strcpy(c.vexs[6].introduction,"6"); 
	strcpy(c.vexs[7].name,"静庐");
	strcpy(c.vexs[7].introduction,"7"); 
	strcpy(c.vexs[8].name,"祥庐");
	strcpy(c.vexs[8].introduction,"8"); 
	strcpy(c.vexs[9].name,"一食堂");
	strcpy(c.vexs[9].introduction,"9"); 
	strcpy(c.vexs[10].name,"商业街、生肖广场");
	strcpy(c.vexs[10].introduction,"收发快递处"); 
	strcpy(c.vexs[11].name,"二食堂");
	strcpy(c.vexs[11].introduction,"11"); 
	strcpy(c.vexs[12].name,"宁庐");
	strcpy(c.vexs[12].introduction,"12");
	strcpy(c.vexs[13].name,"教室公寓");
	strcpy(c.vexs[13].introduction,"13");
	strcpy(c.vexs[14].name,"和庐");
	strcpy(c.vexs[14].introduction,"14");
	strcpy(c.vexs[15].name,"运动场、网球场");
	strcpy(c.vexs[15].introduction,"15");
	strcpy(c.vexs[16].name,"篮球场");
	strcpy(c.vexs[16].introduction,"16");
	strcpy(c.vexs[17].name,"图文信息楼");
	strcpy(c.vexs[17].introduction,"17");
	strcpy(c.vexs[18].name,"萃庐");
	strcpy(c.vexs[18].introduction,"18");
	strcpy(c.vexs[19].name,"大活、礼堂");
	strcpy(c.vexs[19].introduction,"19");
	strcpy(c.vexs[20].name,"体育馆");
	strcpy(c.vexs[20].introduction,"20");
	strcpy(c.vexs[21].name,"群庐");
	strcpy(c.vexs[21].introduction,"21");
	strcpy(c.vexs[22].name,"荟庐");
	strcpy(c.vexs[22].introduction,"22");
	strcpy(c.vexs[23].name,"一教");
	strcpy(c.vexs[23].introduction,"23");
	strcpy(c.vexs[24].name,"二教");
	strcpy(c.vexs[24].introduction,"24");
	strcpy(c.vexs[25].name,"英庐");
	strcpy(c.vexs[25].introduction,"25");
	strcpy(c.vexs[26].name,"南区南门");
	strcpy(c.vexs[26].introduction,"26");
	for(i=1;i<=key;i++)
	  for(j=1;j<=key;j++)
	    c.arcs[i][j].adj=Infinity;//先初始化图的邻接矩阵 	
	c.arcs[1][2].adj = 30;
	c.arcs[1][3].adj = 80;
	c.arcs[2][3].adj = 50;
	c.arcs[3][4].adj = 20;
	c.arcs[3][5].adj = 40;
	c.arcs[4][6].adj = 100;
	c.arcs[4][5].adj = 50;
	c.arcs[5][6].adj = 50;
	c.arcs[6][7].adj = 20;
	c.arcs[6][8].adj = 40;
	c.arcs[7][10].adj = 20;
	c.arcs[7][9].adj = 30;
	c.arcs[8][10].adj = 30;
	c.arcs[8][11].adj = 10;
	c.arcs[9][10].adj = 80;
	c.arcs[9][12].adj = 20;
	c.arcs[10][11].adj = 80;
	c.arcs[10][13].adj = 50;
	c.arcs[10][14].adj = 50;
	c.arcs[11][14].adj = 100;
	c.arcs[11][15].adj = 100;
	c.arcs[12][13].adj = 100;
	c.arcs[12][16].adj = 50;
	c.arcs[13][14].adj = 20;
	c.arcs[13][16].adj = 60;
	c.arcs[13][17].adj = 25;
	c.arcs[14][17].adj = 25;
	c.arcs[14][21].adj = 120;
	c.arcs[15][21].adj = 100;
	c.arcs[16][17].adj = 30;
	c.arcs[16][18].adj = 20;
	c.arcs[17][19].adj = 40;
	c.arcs[17][20].adj = 40;
	c.arcs[18][19].adj = 30;
	c.arcs[18][22].adj = 50;
	c.arcs[19][20].adj = 100;
	c.arcs[19][23].adj = 40;
	c.arcs[20][21].adj = 40;
	c.arcs[20][24].adj = 50;
	c.arcs[21][25].adj = 30;
	c.arcs[22][23].adj = 80;
	c.arcs[22][26].adj = 250;
	c.arcs[23][24].adj = 70;
	c.arcs[23][26].adj = 200;
	c.arcs[24][25].adj = 50;
	c.arcs[24][26].adj = 200;
	c.arcs[25][26].adj = 250;
	for(i=1;i<=key;i++)//邻接矩阵是对称矩阵，对称赋值（无向图需要对称赋值） 
	  for(j=1;j<=key;j++)
	    c.arcs[j][i].adj=c.arcs[i][j].adj;
    return c;
}//initgraph
//2.查找景点在图中的序号
int locatevex(mgraph c,int v)//locatevex
{	int i;
	for(i=1;i<=c.vexnum;i++)
	  if(v==c.vexs[i].position)  return i;//找到，返回顶点序号i 
 	return -1;//没有找到这个顶点 
} 
//3.查找并输出序号为m,n景点间的长度不超过特定个景点的路径 
void path(mgraph c,int m,int n,int k)
{	int s,t=k+1,length=0;//t用于存放路径上下一个顶点对应的d[]数组元素的下标 
	if(d[k]==n&&k<26)//若d[k]是终点n且景点个数<=26,则输出该路径 
	{	for(s=0;s<k;s++)//计算路径长度 
	    {    	 
	    	length=length+c.arcs[d[s]][d[s+1]].adj;
		} 
		if(length<=565)//打印路径长度小于定长的路径 
		{	for(s=0;s<k;s++)//输出该路径。s=0时为起点m
	        {
	    	   printf("%d%s--->",d[s],c.vexs[d[s]].name);
		    } 
	        printf("%d%s  ",d[s],c.vexs[d[s]].name);//输出最后一个景点名（即顶点n的名字，此时s==k）	
	        printf("总路线长为%d米\n\n",length);
		}
	} 
	else
	{	s=1;
		while(s<=c.vexnum)//从第m个顶点，试探所有顶点是否有路径 
		{	if((c.arcs[d[k]][s].adj<Infinity)&&(visited[s]==0))//顶点m到顶点s有边(权值不为无穷大)，且未被访问 
			{	visited[s]=1;
				d[k+1]=s;//存储顶点编号 
				path(c,m,n,t);
				visited[s]=0;//将找到的路径上顶点的访问标志重新设置为0，以用于试探新的路径 
			}
			s++;//试探从下一个顶点s开始是否有到终点的路径 
		}
	}	
} 
//4.查找两景点间的景点的所有路径
int allpath(mgraph c)
{	int k,i,j,m,n;
	printf("\n\n请输入您想要查询的两个景点的编号：\n\n");
	scanf("%d%d",&i,&j);printf("\n\n");
	m=locatevex(c,i);//locatevex 确定该顶点是否存在。若存在，返回该顶点编号。 
	n=locatevex(c,j);
	d[0]=m;//存储路径起点m（int d[]数组是全局变量） 
	for(k=0;k<key;k++)//全部顶点访问标志初值设为0 
	  visited[k]=0;
	visited[m]=1;//第m个顶点访问标志设置为1 
	path(c,m,n,0);//调用程序。k=1，对应起点d[1]==m。k为d[]数组下标 
	return 1;
}
//5.用迪杰斯特拉算法，求出一个景点到其他景点间的最短路径，
void shortestpath_dij(mgraph c)
{	int v0,v,w,k=1,min,t,p;
	int final[MaxVertexNum];//final[w]=1表示已经求得顶点V0到Vw的最短路径
	int Patharc[MaxVertexNum];//用于存储最短路径下标的数组 
    int ShortPathtable[MaxVertexNum];//用于存储到各点最短路径的权值和 
	printf("\n请输入一个起始景点的编号："); 
	scanf("%d",&v0);printf("\n\n"); 
	while(v0<0||v0>key)
	{	printf("\n您输入的景点编号不存在\n");
		printf("请重新输入：");
		scanf("%d",&v0); 
	}
	//初始化数据
	for(v=1;v<=c.vexnum;v++)//数组0还是空出来 
	{	final[v]=0;//全部顶点初始化为未找到最短路径 
		ShortPathtable[v]=c.arcs[v0][v].adj;//将与v0点有连线的顶点加上权值 
		Patharc[v]=0;//初始化路径数组p为0 
	 }
	 ShortPathtable[v0]=0; // V0至v0的路径为0 
	 final[v0]=1;//V0至v0不需要路径 	 
	 //开始主循环，每次求得V0到某个v顶点的 最短路径 
	 for(v=1;v<=c.vexnum;v++)
	 {	min=Infinity;
	 	for(w=1;w<=c.vexnum;w++)//找出最近的顶点和权值 
	 	{	if(!final[w]&&ShortPathtable[w]<min)//有边 
	 		{	k=w;
	 			min=ShortPathtable[w];
			 }
		 }
		 final[k]=1;//将目前找到的最近的顶点置1 
	 	 //修正当前最短路径及距离
		 for(w=1;w<=c.vexnum;w++)
		 {	//如果经过v顶点的路径比现在这条路径的长度短的话，更新
			if(!final[w]&&(min+c.arcs[k][w].adj<ShortPathtable[w])) 
			{	ShortPathtable[w]=min+c.arcs[k][w].adj;//修改当前路径长度
				Patharc[w]=k; //存放前驱结点（像糖葫芦） 
			}
		  } 
     }  
     //打印最短路径
	 for(t=1;t<=c.vexnum;t++)
	 {  p=t;
	 	if(t!=v0)//反向输出 
	 	{	printf("%d%s",t,c.vexs[t].name);
	 		for(w=1;w<=c.vexnum;w++)
	 		{	if(Patharc[p]!=0)
	 			{	printf("<--%d%s",Patharc[p],c.vexs[p].name);
	 				p=Patharc[p];
				 }
			 }
			 printf("<--%d%s",v0,c.vexs[v0].name);
			 printf("\n总路线长为%d米\n\n",ShortPathtable[t]); 
		 }
	  }     
}
//菜单 
void menu()
{	printf(" ┌──────────────────────────────────────────────────────┐\n");
	printf(" │ ╭ ═══════════════════════════════════════════════ ╮  │\n");
	printf(" │ ││        欢 迎 使 用 校 园 导 游 系 统         	   ││ │\n");
  	printf(" │ ╰ ═══════════════════════════════════════════════ ╯  │\n");
  	printf(" │                      欢迎来到                         │\n");
  	printf(" │                    江西财经大学                    	 │\n");
  	printf(" │                     菜 单 选 择                       │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  1.菜单                **   2.查看游览路线（迪）*   │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  3.查询景点间最短路径  **   4.查询景点间所有路径*    │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  5.学校景点介绍        **   6.景点信息查询        * │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  0.退出                **   第一小组0v0          * │\n");
	printf(" │  *************************************************** │\n");
	printf(" └──────────────────────────────────────────────────────┘\n");
}
//6.输出图的邻接矩阵的值 
void printmatrix(mgraph c)
{	int i,j,k=0;
	for(i=1;i<=key;i++)
	{  if(c.vexs[i].position!=-1)
		  printf("%6d",i);//横着的标号1到26
	}
	printf("\n");
	for(i=1;i<=c.vexnum;i++)
	{   	for(j=1;j<=c.vexnum;j++)
	        {	if(c.arcs[i][j].adj==Infinity)
	  	            printf(" *#@* ");
	  	        else
	  	            printf("%6d",c.arcs[i][j].adj);
	         	k++;
	  	        if(k%c.vexnum==0) printf("\n");
	         }		
	  }		
} 

//7.查询两景点间的最短路径（floyd算法）
void floyd(mgraph c)//一种暴力破解获取最短路径的算法 
{	int i,j,k;
	for(i=1;i<=key;i++)//将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1 
	{	for(j=1;j<=key;j++)
		{	shortest[i][j]=c.arcs[i][j].adj;
			pathh[i][j]=j; 
		}
	}
	printf("\n\n\n");
	
	for(k=1;k<=key;k++)//核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改 
	{	for(i=1;i<=key;i++)
		{	for(j=1;j<=key;j++)
			 {
			 	if(shortest[i][j]>shortest[i][k]+shortest[k][j])
			 	{	shortest[i][j]=shortest[i][k]+shortest[k][j];			 	    
	     	 		pathh[i][j]=pathh[i][k];//记录一下所走的路 //P数组用来存放前驱顶点  
				}
			 }
		}
	}
}
//打印出最短路径 
void display(mgraph c,int i,int j)
{	int a,b;
	a=i;b=j;
	printf("您要查询的两景点间最短路径：\n\n");	
	printf("%d%s",a,c.vexs[a].name);
	while(pathh[i][j]!=b)
	{ printf("-->%d%s",pathh[i][j],c.vexs[pathh[i][j]].name);	  	 
	  i=pathh[i][j]; 	  	 
	}
  	printf("-->%d%s\n\n",b,c.vexs[b].name);
	printf("%s-->%s的最短路径是：%d 米。\n\n",c.vexs[a].name,c.vexs[b].name,shortest[a][b]);
}
//任意两点间最短距离（弗洛伊德算法）
int shortdistance(mgraph c) 
{	int i,j;
	printf("请输入要查询的两个景点的数字编号（1->26）中间用空格间隔开。\n"); 
	scanf("%d %d",&i,&j);
	if(i>key||i<0||j>key||j<0)
	{	printf("输入信息错误！\n\n");
		printf("请输入要查询的两个景点的数字编号（1->26）中间用空格间隔开。\n"); 
		scanf("%d %d",&i,&j);
	}
	else
	{	
		floyd(c);
		// printf_Pshuzu();
		display(c,i,j);
	}
	return 1;
}
//8.查询景点的信息
void seeabout(mgraph c)
{	int k;
	printf("\n请输入要查询的景点编号：");
	scanf("%d",&k);
	while(k<=0||k>key)
	{	printf("\n您所输入的景点编号不存在！");
		printf("\n请重新输入景点编号：");
		scanf("%d",&k); 
	}
	printf("\n\n编号：%-4d\n",c.vexs[k].position);
	printf("\n景点名称：%-10s\n",c.vexs[k].name);
	printf("\n详细介绍：%-80s\n\n",c.vexs[k].introduction);
}
//9.显示所有景点信息
void browsecompus(mgraph c) 
{	int i;
	printf(" \n\n编号        景点名称                   简介\n");
	printf("____________________________________________________________________________________________\n");
	for(i=1;i<=key;i++)
	{	if(c.vexs[i].position!=-1)
		printf("%-10d%-25s%-80s\n",c.vexs[i].position,c.vexs[i].name,c.vexs[i].introduction);
	}
	printf("____________________________________________________________________________________________\n");
}
//10.主要工作函数。操作区用户界面
void mainwork()
{   menu();
	int yourchoice;
	campus=initgraph();
	do
	{	printf("请输入您的选择：");
	    scanf("%d",&yourchoice);
	    switch(yourchoice)
	    {	case 1:system("cls");menu();break; 
			case 2:system("cls");shortestpath_dij(campus);break;
			case 3:system("cls");shortdistance(campus);break; 
			case 4:system("cls");allpath(campus);break; 
			case 5:system("cls");browsecompus(campus);break; 
			case 6:system("cls");seeabout(campus);break; 
			case 0:system("cls");printf("谢谢使用\n");break;
			default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	}while(yourchoice); 
}
int main()
{	
	system("chcp 65001"); /* cmd chcp 命令切换字符编码为 utf-8 以显示中文 */
	// system("color 1f");//背景颜色
	system("mode con: cols=140 lines=130");//程序页面长宽
	// system("SchoolGraph.png");//调用校园地图 （就是一个图片）
	mainwork();
	return 0;
}