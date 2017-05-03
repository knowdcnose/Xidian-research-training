#include <stdio.h>  //33行修改文件路径 
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
{  printf("请先修改文件路径！！\n")  ;
 char name[6];FILE *fptr = fopen("连续统计结果.txt", "w");
while(printf("请输入要统计的数据名(区分大小写  输入ctrl+Z结束程序)\n")&&scanf("%s",name)!=EOF)
{   int choice; 
    printf("请问是否需要该数据连续的具体情况，如果是请输入1,如只需简略情况请输入2\n");
    scanf("%d",&choice);
    int a[30000],count=0,num1=0,loc1,grop1[50000][2],adr1,time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0,b[30000];
    char szTest[1000] = {0};  
    int len = 0;                                                             //          //                                                                     //     //     //       // 
    FILE *fp = fopen("text1.txt", "r");  //在这里修改文件路径！！！！ // 
    
	if(NULL == fp)                                                    //                          // 
    {                                                                   //                    //                                                                  //             // 
        printf("failed to open dos.txt\n");                                   //       // 
        return 1;                                                                 // 
    }  
    while(!feof(fp))  
    {  
        memset(szTest, 0, sizeof(szTest));  
        fgets(szTest, sizeof(szTest) - 1, fp);  
        if(StringFind(szTest,name)!=-1)//在这里改要查找的目标 
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
    fprintf(fptr,"%d组数据中 ",count);
     
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
	fprintf(fptr,"共出现了%d次连续相同的%s\n****************************我是分割线*****************************\n\n",time1,name);
if(choice==1)	
    
	{
	for(count=1;count<=time1;count++)
	{
		fprintf(fptr,"第%d次连续重复，重复出现的数据是%d,重复出现了%d次\n",count,grop1[count][1],grop1[count][0]);//如果觉得打印太慢了可以吧这行注释掉 
	}
    } 
	fclose(fp); 
}
    return 0;  
    fclose(fptr);
}  

