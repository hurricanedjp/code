
#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//增加的数据结构
#define max_vertex_num 600
#define max_subvertex_num 50
#define INFINITY 100000
typedef struct{
	unsigned short arcs[max_vertex_num][max_vertex_num];
	int vertex_num,arc_num;

}Graph;
typedef struct{
	int source,destination,subvertex_num;
	int subset[max_subvertex_num];
}Demand; 
//你要完成的功能总入
char* substring(char* str,int pos,int length)  
{  

	char* substr=(char*)calloc(sizeof(char),length+1);  
	char *pstr=str+pos;  
	int i;  

	for(i=0;i<length;i++)  
	{  
		substr[i]=*(pstr++);  
	}  
	substr[length]='\0'; 
	return substr;       
}
//我们这里假设顶点索引从0开始并且连续 
void init_data(Graph *pG,Demand *pD,char *topo[5000],int edge_num,char *demand)
{
	bool exist_flag[max_vertex_num];
	int vertex_num=0;
	int arc_head,arc_tail;
	int pos,flag,i,j;

	for(i=0;i<edge_num;i++)
	{ 
		j=0;
		flag=0;
		while(topo[i][j]!='\0')
		{
			if(topo[i][j]==',')
			{
				flag++;
				if(flag==1)
				{
					pos=j+1;
				}
				else if(flag==2)
				{
					arc_head=atoi(substring(topo[i],pos,j-pos));
					pos=j+1;
				}

				else if(flag==3)
				{
					arc_tail=atoi(substring(topo[i],pos,j-pos));
					pos=j+1;
				}


			}
			j++;
		}
		if(!exist_flag[arc_head])
		{
			vertex_num++;
			exist_flag[arc_head]=true;
		}
		if(!exist_flag[arc_tail])
		{
			vertex_num++;
			exist_flag[arc_tail]=true;

		}
		pG->arcs[arc_head][arc_tail]=(unsigned short)(atoi(substring(topo[i],pos,j-pos)));

	}
	pG->arc_num=edge_num;
	pG->vertex_num=vertex_num;
	i=0;
	j=0;
	pos=0;
	flag=0;
	while(demand[i]!='\0')
	{
		if(demand[i]==',')
		{
			flag++;
			if(flag==1)
			{
				pD->source=atoi(substring(demand,pos,i-pos));
				pos=i+1;
			}
			else if(flag==2)
			{
				pD->destination=atoi(substring(demand,pos,i-pos));
				pos=i+1;
			}
		}
		else if(demand[i]=='|')
		{
			pD->subset[j++]=atoi(substring(demand,pos,i-pos));
			pos=i+1;

		}
		i++;
	}
	pD->subset[j++]=atoi(substring(demand,pos,i-pos));
	pD->subvertex_num=j;
}

//打印数据
void print_data(Graph *pG,Demand *pD)
{
	int i,j;
	int vertex_num=pG->vertex_num;
	int subvertex_num=pD->subvertex_num;
	printf("\n该图中顶点的个数为:%d,边的个数为:%d\n弧的权值为:\n",pG->vertex_num,pG->arc_num);

	for(i=0;i<vertex_num;i++)
	{
		for(j=0;j<vertex_num;j++)
		{
			printf("%2d  ",pG->arcs[i][j]);

		}
		printf("\n");
	}
	printf("\n路径的源点为:%d,终点为:%d,子集数目为%d\n子集的索引:\n",pD->source,pD->destination,pD->subvertex_num);
	for(i=0;i<subvertex_num;i++)
	{
		printf("%3d  ",pD->subset[i]);
	}
	printf("\n");

}
void shortest_path(Graph *pG,Demand *pD)
{


}
void search_route(char *topo[5000], int edge_num, char *demand)
{
	bool visit_flag[max_vertex_num];
	Graph G;
	Demand D;	
	init_data(&G,&D,topo,edge_num,demand);
	print_data(&G,&D);
	//	for(int i=0;i<edge_num;i++)
	//
	//	{
	//
	//
	//		printf("%s\n",topo[i]);  
	//	}
	//	printf("%s",demand);
	//	unsigned short result[] = {2, 6, 3};//示例中的一个解
	//
	//	for (int i = 0; i < 3; i++)
	//		record_result(result[i]);
}
