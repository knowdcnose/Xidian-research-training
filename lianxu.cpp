#include <stdio.h>  //33���޸��ļ�·�� 
#include <string.h>  
int StringFind(const char *pSrc, const char *pDst)  
{  
    int i, j;  
    for (i=0; pSrc[i]!='\0'; i++)  
    {  
        if(pSrc[i]!=pDst[0])  
            continue;         
        j = 0;  
        while(pDst[j]!='\0' && pSrc[i+j]!='\0')  
        {  
            j++;  
            if(pDst[j]!=pSrc[i+j])  
            break;  
        }  
        if(pDst[j]=='\0')  
            return i;  
    }  
    return -1;  
}  
int main()  
{  printf("�����޸��ļ�·������\n")  ;
 char name[6];FILE *fptr = fopen("����ͳ�ƽ��.txt", "w");
while(printf("������Ҫͳ�Ƶ�������(���ִ�Сд  ����ctrl+Z��������)\n")&&scanf("%s",name)!=EOF)
{   int choice; 
    printf("�����Ƿ���Ҫ�����������ľ�������������������1,��ֻ��������������2\n");
    scanf("%d",&choice);
    int a[30000],count=0,num1=0,loc1,grop1[50000][2],adr1,time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0,b[30000];
    char szTest[1000] = {0};  
    int len = 0;                                                             //          //                                                                     //     //     //       // 
    FILE *fp = fopen("text1.txt", "r");  //�������޸��ļ�·���������� // 
    
	if(NULL == fp)                                                    //                          // 
    {                                                                   //                    //                                                                  //             // 
        printf("failed to open dos.txt\n");                                   //       // 
        return 1;                                                                 // 
    }  
    while(!feof(fp))  
    {  
        memset(szTest, 0, sizeof(szTest));  
        fgets(szTest, sizeof(szTest) - 1, fp);  
        if(StringFind(szTest,name)!=-1)//�������Ҫ���ҵ�Ŀ�� 
		{
		
		loc1=StringFind(szTest,name)+strlen(name)+1;             //                 ||
        if(szTest[loc1+1]==32)                                  //                 ||||
        {                                                     //                 ||||||||
        	a[count]=szTest[loc1]-48;                       //                 ||||||||||||
        	count++;                                         //                    ||||
		}                                                    //                    ||||
        else                                                //                     ||||
        {                                                   //                     |||| 
        	a[count]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;//                    |||||| 
        	count++;
		}
	    }
    }  num1=count;num2=count2;
    fprintf(fptr,"%d�������� ",count);
     
    for(count=0;count<num1;count++)
    {   
    	if(a[count]==a[count+1])
		{   
		    count++;
			time1=time1+1;grop1[time1][0]+=2;
			grop1[time1][1]=a[count];
			while(a[count]==a[count+1])
			{
				count++;
				grop1[time1][0]++;
			}
		}
	}
	fprintf(fptr,"��������%d��������ͬ��%s\n****************************���Ƿָ���*****************************\n\n",time1,name);
if(choice==1)	
    
	{
	for(count=1;count<=time1;count++)
	{
		fprintf(fptr,"��%d�������ظ����ظ����ֵ�������%d,�ظ�������%d��\n",count,grop1[count][1],grop1[count][0]);//������ô�ӡ̫���˿��԰�����ע�͵� 
	}
    } 
	fclose(fp); 
}
    return 0;  
    fclose(fptr);
}  

