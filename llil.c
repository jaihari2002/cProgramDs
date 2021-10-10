#include<stdio.h>
#define SIZE n
void bubble(int[]);
void seletion(int[]);
void insertion(int[]);

void merge(int[],int,int);
void partition_merge(int[],int,int,int);

void quick(int[],int,int);
int partition_quick(int[],int,int);
 
 void radix(int[]);
void count(int[]);

int i,j,k,n,temp;
void print();
int b[200],a[100];


void print()
{
    for(i=0;i<SIZE;i++)
	printf("%d\n",a[i]);
	
}


int main()
{
	
	printf("enter the number of element:\n");
	scanf("%d",&n);
	for(i=0;i<SIZE;i++)
	{
	printf("enter the the number of element:\n");
   scanf("%d",&a[i]);	 
	}
	printf("before sorting:\n");
	print();
	
	//bubble(a);
	seletion(a);
 	//insertion(a);
	//merge(a,0,n-1);
	//quick(a,0,n-1);
	
	//radix(a);
    //count(a);
	return 0;
}


void bubble(int a[])
{
  printf("bubble sort:\n");	
  for(i=0;i<n-1;i++)
  {
  	for(j=0;j<n-i-1;j++)
  	{
  		if(a[j]>a[j+1])
  		{
  			temp=a[j]; 
  			a[j]=a[j+1];
  			a[j+1]=temp;
		  }
	  }
  	
  }
  print();
  	
}



void seletion(int a[])
{
	int min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	printf("seletion sorting:\n");
     print();
}



void insertion(int a[])
{
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i;j!=0&&temp<a[j-1];j--)
		{
			a[j]=a[j-1];
		}
		a[j]=temp;
	}
	print();
}



void merge(int a[],int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		merge(a,start,mid);
		merge(a,mid+1,end);
		partition_merge(a,start,mid,end);
		
	}
	if(start==0&&end==SIZE-1)	
	{
	 printf("merge sort:\n");
       	print();
       }
}


void partition_merge(int a[],int start,int mid,int end)
{
	
	i=start;
    j=mid+1;
    k=start;
    while(i<=mid&&j<=end)
    {
    	if(a[i]<=a[j])
    	{
    		b[k]=a[i];
            i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
    
    if(i>mid)
    {
    	while(j<=end)
    	{
    		b[k]=a[j];
    		j++;
    		k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=start;i<=end;i++)
	{
		a[i]=b[i];
	}
       
       
	   
}

void quick(int a[],int lb,int ub)
{
	int loc;
	if(lb<ub)
	{
	  loc=partition_quick(a,lb,ub);
	  quick(a,lb,loc-1);
	  quick(a,loc+1,ub);
	}
	if(lb==0&&ub==SIZE-1)
	{    
	printf("quick sort:\n");
		print();
    }
}



int partition_quick(int a[],int lb,int ub)
{
	int start,end,pivot,temp;
	start=lb;
	pivot=a[lb];
	end=ub;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
		  start++;	
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;

	return end;
}




void radix(int a[])
{
	int step,div=1,nod=0,noe[10],d,max,loc;
	max=a[0];
	for(i=1;i<SIZE;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	d=max;
	while(d!=0)
	{
		nod++;
		d=d/10;
 	}
 	
    int bucket[10][SIZE];
    for(step=0;step<nod;step++)
    {
    	for(i=0;i<10;i++)
    	{
    		noe[i]=0;
		}
		for(i=0;i<SIZE;i++)
		{
			loc=(a[i]/div)%10;
			bucket[loc][noe[loc]++]=a[i];
		}
		
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<noe[i];j++)
			{
				a[k++]=bucket[i][j];
			}
		}
		div=div*10;
	}
   
printf("radix sort:\n");
       	print();
}

void count(int a[])
{
	int max;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
		
	}
	int count[max+1];
	for(i=0;i<=max;i++)
	{
      count[i]=0;
	
	}
	
	for(i=0;i<n;i++)
	{
		++count[a[i]];
	}
	for(i=1;i<=max;i++)
	{
	  count[i]=count[i]+count[i-1];	
	}
	for(i=SIZE-1;i>=0;i--)
	{
	b[--count[a[i]]]=a[i];
	
	}
	for(i=0;i<SIZE;i++)
	{
		a[i]=b[i];
	}
	printf("count sort:\n");
	print();
	
}










