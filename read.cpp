#include <stdio.h>  
#include <string.h>  
//目前可以求src重复组数，剩下的就明天（其实已经到明天了) 
//查找字符串第一次出现的位置 
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
{   int a[30000],count=0,num1=0,loc1,grop1[50000][2],time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0,b[30000];
    char szTest[1000] = {0};  
    int len = 0;  
  
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\text1.txt", "r");  //请输入文件路径 
    if(NULL == fp)  
    {  
        printf("failed to open dos.txt\n");  
        return 1;  
    }  
  
    while(!feof(fp))  
    {  
        memset(szTest, 0, sizeof(szTest));  
        fgets(szTest, sizeof(szTest) - 1, fp);  
        if(StringFind(szTest,"SRC:")!=-1)//在这里改要查找的目标 
		{
		
		  loc1=StringFind(szTest,"SRC:")+4;
          if(szTest[loc1+1]==32)
          {
        	  a[count]=szTest[loc1]-48;
        	  count++;
	  	  }
          else
          {
        	  a[count]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  count++;
		  }
	    }
	    if(StringFind(szTest,"DST:")!=-1)//
		{
		
		  loc1=StringFind(szTest,"DST:")+4;
          if(szTest[loc1+1]==32)
          {
        	  b[count2]=szTest[loc1]-48;
        	  count2++;
	  	  }
          else
          {
        	  b[count2]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  count2++;
		  }
	    }
	    
	    
	    }
	    
        //printf("%d ",loc);
		//printf("%s", szTest);  
     num1=count;num2=count2;
    printf("%d组数据中 ",count);
     
    //for(count=0;count<num;count++)
	//printf("%d ",a[count]);
	//printf("%d",num);
    //printf("\n");  
    //printf("%d ",time);
    for(count=0;count<num1;count++)
    {   //printf("%d ",count);
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
	printf("共出现了%d次连续相同的SRC \n",time1);
	for(count=1;count<=time1;count++)
	{
		//printf("第%d次连续重复，重复出现的数据是%d,重复出现了%d次\n",count,grop1[count][1],grop1[count][0]);//如果觉得打印太慢了可以吧这行注释掉 
		
	}
	printf("*******************我是分割线********************\n%d组数据中 ",num2);
     
    //for(count=0;count<num;count++)
	//printf("%d ",a[count]);
	//printf("%d",num);
    //printf("\n");  
    //printf("%d ",time);
  
	for(count=0;count<num2;count++)
    {   //printf("%d ",count);
    	if(b[count]==b[count+1])
		{   
		    count++;
			time2=time2+1;grop2[time2][0]+=2;
			grop2[time2][1]=b[count];
			while(b[count]==b[count+1])
			{
				count++;
				grop2[time2][0]++;
			}
		}
	
	}
	printf("共出现了%d次连续相同的DST \n",time2);
	for(count=1;count<=time2;count++)
	{
		//printf("第%d次连续重复，重复出现的数据是%d,重复出现了%d次\n",count,grop2[count][1],grop2[count][0]);//如果觉得打印太慢了可以吧这行注释掉 
		
	}
	fclose(fp); 
    return 0;  
}  

