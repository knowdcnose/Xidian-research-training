#include <stdio.h>  
#include <string.h>  
int StringFind(const char *pSrc, const char *pDst)  //pSrcΪ�������ַ�����pDstΪ����Ŀ�� 
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
    return -1;  //���������ƶ��ַ����򷵻�-1�� 
} 
int main()  
{   int i, a[30000],count=0,num1=0,loc1,grop1[50000][2],time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0,b[30000];//a ��b�����������ڴ����ݣ�grop������������� 
    int src[65][1] ,dst[65][1];int data[65][65][1];// �ֱ��� ��Դ Ŀ�ĵ� �������� 
	char szTest[1000] = {0};  //szTest��ÿ�е��ַ��� 
    int len = 0;  
    FILE *fptr = fopen("ͳ�ƽ��.txt", "w");  //�������ļ�·�� 
    FILE *fp = fopen("text1.txt", "r");  //�������ļ�·�� 
    if(NULL == fp)  
    {  
        printf("failed to open dos.txt\n");  //��ʧ��ʱ 
        return 1;  
    }  
  
    while(!feof(fp))  //���ж���ֱ���ļ����� 
    {  
        memset(szTest, 0, sizeof(szTest));  //�ÿ��ַ��� 
        fgets(szTest, sizeof(szTest) - 1, fp);  //���ж��� 
        if(StringFind(szTest,"SRC:")!=-1)//�������Ҫ���ҵ�Ŀ�� 
		{
		
		  loc1=StringFind(szTest,"SRC:")+4;//ȷ��SRC���һ�����ֵ��±� 
          if(szTest[loc1+1]==32)// ����Ϊ��λ�� 
          {
        	  a[count]=szTest[loc1]-48;
			  src[a[count]][0]++;
        	  
        	  
	  	  }
          else//����Ϊ��λ�� 
          {
        	  a[count]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  src[a[count]][0]++;
        	  
		  }
	    }
	    if(StringFind(szTest,"DST:")!=-1) 
		{
		
		    loc1=StringFind(szTest,"DST:")+4;
            if(szTest[loc1+1]==32)
            {
        	    b[count2]=szTest[loc1]-48;
        	     dst[b[count2]][0]++;
        	   
	  	    }
            else
            {
        	    b[count2]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	     dst[b[count2]][0]++;
        	   
		    }
	    }
		data[a[count]][b[count2]][0]++;
		
		count++; count2++;
	}
	    
     num1=count-1;num2=count2-1;
    printf("%d�������� ",count);
     
    for(count=0;count<num1;count++)//timieͳ���������ֵ����� 
    {   
    	if(a[count]==a[count+1])
		{   
		    count++;
			time1=time1+1;grop1[time1][0]+=2;//grop[][0] ����ͬ���ݵĸ�����grop[][1]���ظ������ݵ�ֵ�� 
			grop1[time1][1]=a[count];
			while(a[count]==a[count+1])
			{
				count++;
				grop1[time1][0]++;
			}
		}
	}
	printf("��������%d��������ͬ��SRC \n",time1);
	for(count=1;count<=time1;count++)
	{
	//	printf("��%d�������ظ����ظ����ֵ�������%d,�ظ�������%d��\n",count,grop1[count][1],grop1[count][0]);//������ô�ӡ̫���˿��԰�����ע�͵� 	
	}
	printf("*********************************************���Ƿָ���**********************************************\n*********************************************���Ƿָ���**********************************************\n%d�������� ",num2);
     
  
	for(count=0;count<num2;count++)
    {   
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
	printf("��������%d��������ͬ��DST \n\n\n\n",time2);
	for(count=1;count<=time2;count++)
	{
	//	printf("��%d�������ظ����ظ����ֵ�������%d,�ظ�������%d��\n",count,grop2[count][1],grop2[count][0]);//������ô�ӡ̫���˿��԰�����ע�͵� 
		
	}
	
	
	for(i=1;i<65;i++)
	{
	//	fprintf(fptr,"�Ӻ�%d���͵İ�������Ϊ%d\n",i,src[i][0]);
		
		
		
	}
	printf("\n\n*********************************************���Ƿָ���**********************************************\n") ;
	for(i=1;i<65;i++)
	{
	//	fprintf(fptr,"�Ժ�%dΪĿ�ĵصİ�������Ϊ%d\n",i,dst[i][0]);
		
		
		
	}
	for(i=1;i<64;i++)
	{
		for(count=1;count<64;count++)
		{if(count!=63) 
		    fprintf(fptr,"�ӽڵ�%d���͵��ڵ�%d�İ�����Ϊ%d\n ",i,count,data[i][count][0]);
		 else
		     fprintf(fptr,"%d;",data[i][count][0]/*i,count,*/);
		} 
		
	}
	fclose(fp); 
	fclose(fptr); 
    return 0;  
}  

