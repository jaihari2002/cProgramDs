#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int ele,length=0,i,flag=0,pointer=0,del,ins=0,mat=0,n,choice,m,min,max,avl_bf,avl_minim,avl_maxim,search_ele,doubly_length,found, circular_doubly_length,circular_length;
char ch[100];
void zero_filler()
{
 ele=i=flag=pointer=del=ins=min=mat=n=m=max=found=0;	
}
//                                                /////////////singly-linked-list(function-declaration)/////////
struct node
{
	int data;  
	struct node* next;
}*head,*tail,*temp1,*temp2,*temp,*print,*new,*stemp;
struct sparse
{
  int data,row,col;
  struct sparse *next;	
}*matrix_head,*p,*mtemp;
void display();
int isempty();
void reverse_list(struct node* temp);  
void asort_list();
void dsort_list();
void sparse_matrix();
void matrix_insert(int,int,int);
void insert_last();
void insert_first();
void insert_nth();
void insert_before_search(); 
void insert_after_search();
void insert_mid();
int delete_first();
int delete_last();
void delete_nth();
int delete_before_search();
int delete_after_search();
int  delete_mid();
struct node* search(int del,struct node* stemp);
void delete_search(int del);
void delete_all();
//                                       ////////////////////doubly-linked-list(function-declaration)/////////////
struct doubly_node
{
	int data;
	struct doubly_node* next;
	struct doubly_node* prev;
}*doubly_head,*doubly_tail,*doubly_temp,*doubly_temp1,*doubly_print,*doubly_new,*doubly_stemp,*doubly_temp1,*doubly_temp2;

void doubly_display();
int doubly_isempty();
struct doubly_node* doubly_search(int del,struct doubly_node* doubly_stemp);
void doubly_reverse_list(struct doubly_node* doubly_temp);  
void doubly_asort_list();
void doubly_dsort_list();
void doubly_insert_last();
void doubly_insert_first();
void doubly_insert_nth();
void doubly_insert_before_search();
void doubly_insert_after_search();
void doubly_insert_mid(); 
int doubly_delete_first();
int doubly_delete_last();
void doubly_delete_nth();
int doubly_delete_before_search();
int doubly_delete_after_search();
int  doubly_delete_mid();
void doubly_delete_search(int del);
void doubly_delete_all();
//                                       //////////////////// circular-linked-list(function-declaration)/////////////
struct  circular_node
{
	int data;
	struct  circular_node* next;
}* circular_head,* circular_tail,* circular_temp,* circular_temp1,* circular_print,* circular_new,* circular_stemp,* circular_temp1,* circular_temp2;

void  circular_display();
int  circular_isempty();
struct  circular_node*  circular_search(int del,struct  circular_node*  circular_stemp);
void  circular_reverse_list(struct  circular_node*  circular_temp);  
void  circular_asort_list();
void  circular_dsort_list();
void  circular_insert_last();
void  circular_insert_first();
void  circular_insert_nth();
void  circular_insert_before_search();
void  circular_insert_after_search();
void  circular_insert_mid(); 
int  circular_delete_first();
int  circular_delete_last();
void  circular_delete_nth();
int  circular_delete_before_search();
int  circular_delete_after_search();
int   circular_delete_mid();
void  circular_delete_search(int del);
void  circular_delete_all();


//                                       //////////////////// circular_doubly-linked-list(function-declaration)/////////////
struct  circular_doubly_node
{
	int data;
	struct  circular_doubly_node* next;
	struct  circular_doubly_node* prev;
}* circular_doubly_head,* circular_doubly_tail,* circular_doubly_temp,* circular_doubly_temp1,* circular_doubly_print,* circular_doubly_new,* circular_doubly_stemp,* circular_doubly_temp1,* circular_doubly_temp2;

void  circular_doubly_display();
int  circular_doubly_isempty();
struct  circular_doubly_node*  circular_doubly_search(int del,struct  circular_doubly_node*  circular_doubly_stemp);
void  circular_doubly_reverse_list(struct  circular_doubly_node*  circular_doubly_temp);  
void  circular_doubly_asort_list();
void  circular_doubly_dsort_list();
void  circular_doubly_insert_last();
void  circular_doubly_insert_first();
void  circular_doubly_insert_nth();
void  circular_doubly_insert_before_search();
void  circular_doubly_insert_after_search();
void  circular_doubly_insert_mid(); 
int  circular_doubly_delete_first();
int  circular_doubly_delete_last();
void  circular_doubly_delete_nth();
int  circular_doubly_delete_before_search();
int  circular_doubly_delete_after_search();
int   circular_doubly_delete_mid();
void  circular_doubly_delete_search(int del);
void  circular_doubly_delete_all();


//                                               ////////////////////bst(function-declaration)/////////////
struct bst_node
{
	struct bst_node* left;
	int data;
	struct bst_node* right;
}*bst_root,*bst_new;
int bst_isempty(struct bst_node*);
void bst_print(struct bst_node*);
void bst_create();
void bst_insert(struct bst_node*,struct bst_node*);
struct bst_node* delete(struct bst_node*,int);
int bst_search(struct bst_node*,int);
int bst_find_min(struct bst_node*);
int bst_find_max(struct bst_node*);
//                                               ////////////////////avl(function-declaration)////////////
struct avl_node
{
	struct avl_node*left;
	int data;
	struct avl_node*right;
	int height;
}*avl_root;
struct avl_node* avl_create(int);
struct avl_node*avl_delete(struct avl_node*,int);
int avl_height(struct avl_node*);
int avl_balance_factor(struct avl_node*);
int avl_max(int,int);
struct avl_node* avl_right_rotate(struct avl_node*);
struct avl_node* avl_left_rotate(struct avl_node*);
struct avl_node* avl_insert(struct avl_node*,int);
int avl_search(struct avl_node*,int);
int find_avl_min(struct avl_node*avl_root);
int find_avl_max(struct avl_node*avl_root);
void avl_print(struct avl_node*);
int avl_isempty(struct avl_node*);
///////////////////
int main()
{
	int a;
	do
	{printf("-----------------------------------------\n");
	printf("press1 for singly_linked_list\npress2 for doubly_linked_list\npress3 for circular_linked_list\npress4 for circular_doubly_linked_list\npress5 for binary_search_tree\npress6 for avl_tree\npress'e' for exit\n");
	printf("-----------------------------------------\n");
	scanf("%s",ch);
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		a=a*m;
		a=a+(ch[i]-48);
	}
	switch(a)
	{
	case 1:/**********case1*********/
	{
	do
	{
	choice=0;
	printf("press0  to display_list         |press11 to delete_after_search  |\npress1  to insert_last          |press12 to delete_mid           |\npress2  to insert_first         |press13 to display_size         |\npress3  to insert_nth           |press14 to search_element       |\npress4  to insert_before_search |press15 to search_delete        |\npress5  to insert_after_search  |press16 to delete_all           |\npress6  to insert_mid           |press17 to reverse_list         |\npress7  to delete_first         |press18 to ascending sort       |\npress8  to delete_last          |press19 to desending sort       |\npress9  to delete_nth           |press20 to sparse_matrix        |\npress10 to delete_before_search |press21 to sparse_display       |\n                      press'e' to exit_program                   |\n");
	printf("------------------------------------------------------------------\n");
	scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
	switch(choice)
	{
    case 0:
    	 display(!isempty());
    	 break;
	case 1:
		  insert_last();
		break;
    case 2:
    	     insert_first();
    	break;   
    case 3:
	        insert_nth();
		 break;	
	case 4:
	      insert_before_search(ins,ele); 
	    break;
	case 5:
	       insert_after_search(); 
	    break;	
	case 6:
	       insert_mid();
	    break;			 
    case 7:
    	  del=delete_first();
    	  if(!isempty())
          printf("%d is deleted.\n",del);
        break;
    case 8:
    	del=delete_last();
    	if(!isempty())
    	 printf("%d is deleted.\n",del);
         break;	
	case 9:
	       delete_nth();
		 break;
	case 10:
	       del=delete_before_search();
	       if(del!=-1)
	       printf("%d is deleted,\n",del);
	    break;	
	case 11:
	       del=delete_after_search();
	       if(del!=-1)
	       printf("%d is deleted,\n",del);
	    break;			  	
	case 12:
		  del=delete_mid();
		    if(del!=-1)
	       printf("%d is deleted from mid.\n",del);
		break;
	case 13:
	       printf("size of linked list is:%d\n",length);	
	     break;
	case 14:
	       printf("enter the element you want to search:\n");
           scanf("%d",&del);
           stemp=search(del,head);
           if(stemp==NULL)
           {
		   printf("the element not present.\n");
           flag=pointer=0;
           }
		   else
           printf("stemp->data=%d\n",stemp->data);
	    break;
	case 15:
		   stemp=head;//initially start temp=head 
	       printf("enter the element to delete:\n");
           scanf("%d",&del);
           delete_search(del);
	    break; 
	case 16:
		    delete_all();
		    printf("!!!all elements are deleted!!!\n");
	     break;   
	case 17:
           reverse_list(head);  
	     break;
    case 18:
	     asort_list();
        break;
    case 19:
	     dsort_list();
	    break;
	case 20:
	     sparse_matrix();
	    break;
	case 21:
	     display(mat);
     	break;					         
    case 53:
    	zero_filler();
    	printf("!!exited!!\n");
	    break;
     
	default:
	   printf("!!invalid entry!!\n");
	   break;
    }
printf("------------------------------------------------------------------\n");

}while(choice!=53);
system("cls");
}
break;
case 2:/**********case2*********/
	{
	  
	do
	{choice=0;
	printf("press0  to doubly_display_list         |press10 to doubly_delete_before_search |\npress1  to doubly_insert_last          |press11 to doubly_delete_after_search  |\npress2  to doubly_insert_first         |press12 to doubly_delete_mid           |\npress3  to doubly_insert_nth           |press13 to doubly_display_size         |\npress4  to doubly_insert_before_search |press14 to doubly_search_element       |\npress5  to doubly_insert_after_search  |press15 to doubly_search_delete        |\npress6  to doubly_insert_mid           |press16 to doubly_delete_all           |\npress7  to doubly_delete_first         |press17 to doubly_reverse_list         |\npress8  to doubly_delete_last          |press18 to doubly_ascending sort       |\npress9  to doubly_delete_nth           |press19 to doubly_desending sort       |\n                      press'e' to exit_program                                 |\n");
	printf("--------------------------------------------------------------------------------\n");
	scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
	switch(choice)
	{
    case 0:
    	 doubly_display();
    	 break;
	case 1:
		    doubly_insert_last();
		break;
    case 2:
    	     doubly_insert_first();
    	break;
    case 3:
	        doubly_insert_nth();
		 break;	
	case 4:
	    	doubly_insert_before_search();
	   break;
	case 5:
	 		doubly_insert_after_search();
	 	break;
	case 6:
	 	     doubly_insert_mid(); 
		 break;	
	case 7:
    	  del=doubly_delete_first();
    	  if(!doubly_isempty())
          printf("%d is deleted.\n",del);
        break;
    case 8:
    	del=doubly_delete_last();
    	if(!doubly_isempty())
    	 printf("%d is deleted.\n",del);
         break;	
	case 9:
	       doubly_delete_nth();
		 break; 	
	case 10:
		  	del=doubly_delete_before_search();
		  	if(del!=-1)
	       printf("%d is deleted,\n",del);
		break;
	case 11:
		 del=doubly_delete_after_search();
		 if(del!=-1)
	     printf("%d is deleted,\n",del);
		break;
	case 12:
		 del=doubly_delete_mid(); 
		 if(del!=-1)
	     printf("%d is deleted from mid.\n",del);
			break;
	case 13:
	       printf("size of linked list is:%d\n",doubly_length);	
	     break;
	case 14:
	       printf("enter the element you want to search:\n");
           scanf("%d",&del);
           doubly_stemp=doubly_search(del,doubly_head);
           if(doubly_stemp==NULL)
           printf("the element not present.\n");
           flag=pointer=0;
	    break;
	case 15:
		   doubly_stemp=doubly_head;//initially start doubly_temp=doubly_head 
	       printf("enter the element to delete:\n");
           scanf("%d",&del);
           doubly_delete_search(del);
	    break; 
	case 16:
		    doubly_delete_all();
		    printf("!!!all elements are deleted!!!\n");
	     break;   
	case 17:
		  if(doubly_isempty())
	printf("!!linked list is empty!!\n");
   else
   { doubly_reverse_list(doubly_head); 
   	printf("the doublelinked list is reversed.\n");
	   }
           
	     break;
    case 18:
	    doubly_asort_list();
        break;
    case 19:
	     doubly_dsort_list();
	    break;				         
    case 53:
    	zero_filler();
    	printf("!!exited!!\n");
	    break;
     
	default:
	   printf("!!invalid entry!!\n");
	   break;
    }
printf("--------------------------------------------------------------------------------\n");
}while(choice!=53);
system("cls");
	
	}
 break;
 case 3:/**********case3*********/
	{
	 do
	{choice=0;
	printf("press0  to  circular_display_list         |press10 to  circular_delete_before_search |\npress1  to  circular_insert_last          |press11 to  circular_delete_after_search  |\npress2  to  circular_insert_first         |press12 to  circular_delete_mid           |\npress3  to  circular_insert_nth           |press13 to  circular_display_size         |\npress4  to  circular_insert_before_search |press14 to  circular_search_element       |\npress5  to  circular_insert_after_search  |press15 to  circular_search_delete        |\npress6  to  circular_insert_mid           |press16 to  circular_delete_all           |\npress7  to  circular_delete_first         |press17 to  circular_reverse_list         |\npress8  to  circular_delete_last          |press18 to  circular_ascending sort       |\npress9  to  circular_delete_nth           |press19 to  circular_desending sort       |\n                      press'e' to exit_program                                       |\n");
	printf("--------------------------------------------------------------------------------------\n");
	scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
	switch(choice)
	{
    case 0:
    
    	  circular_display();
    	 break;
	case 1:
		     circular_insert_last();
		break;
    case 2:
    	      circular_insert_first();
    	break;
    case 3:
	         circular_insert_nth();
		 break;	
	case 4:
	    	 circular_insert_before_search();
	   break;
	case 5:
	 		 circular_insert_after_search();
	 	break;
	case 6:
	 	      circular_insert_mid(); 
		 break;	
	case 7:
    	  del= circular_delete_first();
    	  if(! circular_isempty())
          printf("%d is deleted.\n",del);
        break;
    case 8:
    	del= circular_delete_last();
    	if(! circular_isempty())
    	 printf("%d is deleted.\n",del);
         break;	
	case 9:
	        circular_delete_nth();
		 break; 	
	case 10:
		  	del= circular_delete_before_search();
		  	if(del!=-1)
	       printf("%d is deleted,\n",del);
		break;
	case 11:
		 del= circular_delete_after_search();
		 if(del!=-1)
	     printf("%d is deleted,\n",del);
		break;
	case 12:
		 del= circular_delete_mid(); 
		 if(del!=-1)
	     printf("%d is deleted from mid.\n",del);
			break;
	case 13:
	       printf("size of linked list is:%d\n", circular_length);	
	     break;
	case 14:
	       printf("enter the element you want to search:\n");
           scanf("%d",&del);
            circular_stemp= circular_search(del, circular_head);
           if( circular_stemp==NULL)
           printf("the element not present.\n");
           flag=pointer=0;
	    break;
	case 15:
		 if( circular_isempty())
	printf("!!linked list is empty!!\n");
	else
	{
		    circular_stemp= circular_head;//initially start  circular_temp= circular_head 
	       printf("enter the element to delete:\n");
           scanf("%d",&del);
            circular_delete_search(del);
        }
	    break; 
	case 16:
		     circular_delete_all();
		    printf("!!!all elements are deleted!!!\n");
	     break;   
	case 17:
	  if( circular_isempty())
	printf("!!linked list is empty!!\n");
   else
   {  circular_reverse_list( circular_head); 
   	printf("the doublelinked list is reversed.\n");
	   }
           
	     break;
    case 18:
	     circular_asort_list();
        break;
    case 19:
	      circular_dsort_list();
	    break;				         
    case 53:
    	//zero_filler();
    	printf("!!exited!!\n");
	    break;
     
	default:
	   printf("!!invalid entry!!\n");
	   break;
    }
printf("----------------------------------------------------------------------------------------------------\n");
}while(choice!=53);
	system("cls");
	}
	break;
 case 4:/**********case4*********/
 	{
 	 
	do
	{choice=0;
	printf("press0  to  circular_doubly_display_list         |press10 to  circular_doubly_delete_before_search |\npress1  to  circular_doubly_insert_last          |press11 to  circular_doubly_delete_after_search  |\npress2  to  circular_doubly_insert_first         |press12 to  circular_doubly_delete_mid           |\npress3  to  circular_doubly_insert_nth           |press13 to  circular_doubly_display_size         |\npress4  to  circular_doubly_insert_before_search |press14 to  circular_doubly_search_element       |\npress5  to  circular_doubly_insert_after_search  |press15 to  circular_doubly_search_delete        |\npress6  to  circular_doubly_insert_mid           |press16 to  circular_doubly_delete_all           |\npress7  to  circular_doubly_delete_first         |press17 to  circular_doubly_reverse_list         |\npress8  to  circular_doubly_delete_last          |press18 to  circular_doubly_ascending sort       |\npress9  to  circular_doubly_delete_nth           |press19 to  circular_doubly_desending sort       |\n                      press'e' to exit_program                                                     |\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
	switch(choice)
	{
    case 0:
    
    	  circular_doubly_display();
    	 break;
	case 1:
		     circular_doubly_insert_last();
		break;
    case 2:
    	      circular_doubly_insert_first();
    	break;
    case 3:
	         circular_doubly_insert_nth();
		 break;	
	case 4:
	    	 circular_doubly_insert_before_search();
	   break;
	case 5:
	 		 circular_doubly_insert_after_search();
	 	break;
	case 6:
	 	      circular_doubly_insert_mid(); 
		 break;	
	case 7:
    	  del= circular_doubly_delete_first();
    	  if(! circular_doubly_isempty())
          printf("%d is deleted.\n",del);
        break;
    case 8:
    	del= circular_doubly_delete_last();
    	if(! circular_doubly_isempty())
    	 printf("%d is deleted.\n",del);
         break;	
	case 9:
	        circular_doubly_delete_nth();
		 break; 	
	case 10:
		  	del= circular_doubly_delete_before_search();
		  	if(del!=-1)
	       printf("%d is deleted,\n",del);
		break;
	case 11:
		 del= circular_doubly_delete_after_search();
		 if(del!=-1)
	     printf("%d is deleted,\n",del);
		break;
	case 12:
		 del= circular_doubly_delete_mid(); 
		 if(del!=-1)
	     printf("%d is deleted from mid.\n",del);
			break;
	case 13:
	       printf("size of linked list is:%d\n", circular_doubly_length);	
	     break;
	case 14:
	       printf("enter the element you want to search:\n");
           scanf("%d",&del);
            circular_doubly_stemp= circular_doubly_search(del, circular_doubly_head);
           if( circular_doubly_stemp==NULL)
           printf("the element not present.\n");
           flag=pointer=0;
	    break;
	case 15:
		 if( circular_doubly_isempty())
	printf("!!linked list is empty!!\n");
	else
	{
		    circular_doubly_stemp= circular_doubly_head;//initially start  circular_doubly_temp= circular_doubly_head 
	       printf("enter the element to delete:\n");
           scanf("%d",&del);
            circular_doubly_delete_search(del);
        }
	    break; 
	case 16:
		     circular_doubly_delete_all();
		    printf("!!!all elements are deleted!!!\n");
	     break;   
	case 17:
	  if( circular_doubly_isempty())
	printf("!!linked list is empty!!\n");
   else
   {  circular_doubly_reverse_list( circular_doubly_head); 
   	printf("the doublelinked list is reversed.\n");
	   }
           
	     break;
    case 18:
	     circular_doubly_asort_list();
        break;
    case 19:
	      circular_doubly_dsort_list();
	    break;				         
    case 53:
    	zero_filler();
    	printf("!!exited!!\n");
	    break;
     
	default:
	   printf("!!invalid entry!!\n");
	   break;
    }
printf("----------------------------------------------------------------------------------------------------\n");
}while(choice!=53);
	system("cls");
	 }
	 break;
 case 5:/**********case5*********/
 	{
 		do
	{
	printf("press0 to display     |\npress1 to bst_insert  |\npress2 to delete      |\npress3 to bst_search  |\npress4 to bst_find_min|\npress5 to bst_find_max|\npress'e' to exit      |\n");
	printf("-----------------------\n");
	scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
	switch(choice)
    {
    	case 0:
			if(!bst_isempty(bst_root))
    		{
    		printf("binary bst_search tree:\n");
    		bst_print(bst_root);	
    	    }
    		else
			printf("!!binary bst_search tree is empty!!\n");
						
        break;
    	case 1:
    	bst_create();
    	break;
    	case 2:
    		if(!bst_isempty(bst_root))
    		{
    			printf("enter the element to delete:\n");
    			scanf("%d",&ele);
    		  bst_root=delete(bst_root,ele);
    		  	if(found==0)
       		printf("!!%d is not found!!\n",ele);
       		else if(found==1)
       		printf("%d is deleted from bst tree\n",ele);
    	    }
    		else
			printf("!!binary bst_search tree is empty!!\n");	
    		
    	break;
    			
    	case 3:
    		if(!bst_isempty(bst_root))
    		{
    	    printf("enter the element to bst_search:\n");
    	    scanf("%d",&search_ele);
    		ele=bst_search(bst_root,search_ele);	
    		if(ele==-1)
    		printf("!!%d was not present in binary bst_search tree!!\n",search_ele);
    		else
    		  printf("%d was  present in binary bst_search tree\n",ele);
    	    }
    		else
			printf("!!binary bst_search tree is empty!!\n");		 
    	break;
    	case 4:
    		if(!bst_isempty(bst_root))
    		{
    		min=bst_find_min(bst_root);	
    		  printf("smallest element present in bst is %d\n",min);
    	    }
    		else
			printf("!!binary bst_search tree is empty!!\n");	
        break;
		case 5:
    		if(!bst_isempty(bst_root))
    		{
    		max=bst_find_max(bst_root);	
    		  printf("largest element present in bst is %d\n",max);
    	    }
    		else
			printf("!!binary bst_search tree is empty!!\n");			
        break;
		case 53:
			zero_filler();
    		printf("!!exited!!\n");			
        break;	
        default:
    	printf("!!invalid entry!!\n");				
        break;
	}
	printf("------------------------\n");
  }while(choice!=53);
 		system("cls");
	 }
	 break;
	 case 6:/**********case6*********/
	 	{do
	{
       printf("press0   to avl_display |\npress1   to avl_insert  |\npress2   to avl_delete  |\npress3   to avl_search  |\npress4   to find_avl_min|\npress5   to find_avl_max|\npress'e' to exit        |\n");
       printf("-------------------------\n");
       scanf("%s",ch); 
	system("cls");
	for(i=0;ch[i]!='\0';i++)
	{
		m=i;
		m=m*10;
		choice=choice*m;
		choice=choice+(ch[i]-48);
	}
       switch(choice)
       {
       	case 0:
       		if(avl_isempty(avl_root))
       		{
       			printf("avl tree is empty :(\n");
			}
			else
			{
       		printf("avl tree:\n");
       		avl_print(avl_root);
            }
       	break;
       	case 1:
       		printf("enter the element:\n");
       		scanf("%d",&ele);
       		avl_root=avl_insert(avl_root,ele);
       	break;
       	case 2:
       		if(avl_isempty(avl_root))
    		{
			printf("avl tree is empty :(\n");
    	    }
    	    else
    	    {
		    printf("enter the element to delete in avl tree:\n");
		    scanf("%d",&ele);
       		avl_root=avl_delete(avl_root,ele);
       		if(found==0)
       		printf("!!%d is not found!!\n",ele);
       		else if(found==1)
       		printf("%d is deleted from avl tree\n",ele);
         	}
       	break;
        case 3:
       		if(avl_isempty(avl_root))
    		{
			printf("avl tree is empty :(\n");
    	    }
    		else
    		{
			printf("enter the element to avl_search:\n");
    	    scanf("%d",&search_ele);
    		ele=avl_search(avl_root,search_ele);
    		if(ele==-1)
    		{
    		printf("!!%d was not present in binary avl_search tree!!\n",search_ele);
    	    }
			else
			{
    		  printf("%d was  present in avl tree\n",ele);
    	    }
			}		
       	break;
       	case 4:
       		if(!avl_isempty(avl_root))
    		{
    		avl_minim=find_avl_min(avl_root);	
    		  printf("smallest element present in avl tree is %d\n",avl_minim);
    	    }
    		else
			printf("avl tree is empty :(\n");
       	break;
       	case 5:
       		if(!avl_isempty(avl_root))
    		{
    		avl_maxim=find_avl_max(avl_root);	
    		  printf("largest element present in avl tree is %d\n",avl_maxim);
    	    }
    		else
			printf("avl tree is empty :(\n");
       	break;
       	
       	case 53:
       		zero_filler();
       		printf("!!exited!!\n");
       	break;
       	default:
       	printf("!!invalid entry!!\n");	
       	break;
	   }
	   printf("-------------------------\n");
   }while(choice!=53);
   system("cls");
	 		
		 }
		 break;
		 
		 
		 
		 
case 53:/**********case53*********/
	{
	  
      for(i=0;i<10;i++)
      {
      //	usleep(200000);
	
		if(i==0)   
			printf("\t\t\t\t\t\t\t\t\t!");
		if(i==1)	
			printf("!");
		if(i==2)
	     	printf("E");
		if(i==3)
			printf("X");
		if(i==4)
		    printf("I");
		if(i==5)
			printf("T");
		if(i==6)
			printf("E");
		if(i==7)
	    	printf("D");
		if(i==8)
			printf("!");
		if(i==9)
			printf("!");
	  }
	 system("cls");	
	 }
        break;
default:/**********default*********/
  printf("!!invalid entry!!\n");
	break;	 
}

}while(a!=53);
	return 0;
}



//                                              ////////////singly-linked-list(function-definition)/////////
void display(int choice)
{  
    if(choice==1)
	{
	 
    printf("linked list:\n");
	for(print=head;print!=NULL;print=print->next)
	printf("%d\n",print->data);	
   
  }
  else if(choice==100)
    {
  	printf("the compacted sparse matrix is \n");
	  for(mtemp=matrix_head;mtemp!=NULL;mtemp=mtemp->next)
	  printf("a[%d][%d]=%d\n",mtemp->row,mtemp->col,mtemp->data);
     }
  	else
  	{
  	printf("!!list is empty!!\n");	
	}
}
int isempty()
{	if(head==NULL)
	return 1;
	else 
	return 0;
}
void reverse_list(struct node*temp)
{
 if(temp->next==NULL)//exit condition
 {
 	head=temp;
 	return;
 }
 reverse_list(temp->next);
 struct node*prev=temp->next;//here temp is last before address 
 prev->next=temp;
 temp->next=NULL;
/*if(temp==NULL)
 {
 return;
 }   
 reverse_list(temp->next);
 printf("%d\n",temp->data);
*/
}
void asort_list()
{
	printf("list are now arranged in ascending order:\n");
	for(temp1=head;temp1!=NULL;temp1=temp1->next)
{
	for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
	{
		if(temp1->data<temp2->data)
		{
			del=temp1->data;
			temp1->data=temp2->data;
			temp2->data=del;
		}
	}
}
}
void dsort_list()
{
	printf("list are now arranged in descending order:\n");
	for(temp1=head;temp1!=NULL;temp1=temp1->next)
{
	for(temp2=head;temp2!=NULL;temp2=temp2->next)
	{
		if(temp1->data>temp2->data)
		{
			del=temp1->data;
			temp1->data=temp2->data;
			temp2->data=del;
		}
	}
}
}
void sparse_matrix()
{
	if(mat==100)
	{
		matrix_head=NULL;
		mat=200;
	}
	int a[5][5],i,j,r,c;
	printf("enter the number of rows and columns:\n");
	scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{   printf("enter the element at a[%d][%d]=",i,j);
    		scanf("%d",&a[i][j]);
    	    printf("\n");
		}
	}
	
	for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{   if(a[i][j]!=0)
    	{   mat=100;
    		matrix_insert(a[i][j],i,j);
		}
	   }
	}
	printf("sparse matrix:\n");
     for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{   
    	    printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	
}
void matrix_insert(int x,int r,int c)
{ 
    p=(struct sparse*)malloc(sizeof(struct sparse));
	p->data=x;
	p->row=r;
	p->col=c;
	p->next=NULL;
	if(matrix_head==NULL)
	{
	 matrix_head=p;
	 mtemp=p;
	}
	else
	{ mtemp->next=p;
	  mtemp=p;
	}
	
}
void insert_last()
{
        length++;
		printf("enter the element:\n");
		scanf("%d",&ele);
		new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        new->next=NULL;
		if(head==NULL)
		{
			head=new;
			tail=new;
		}
		else
		{
			tail->next=new;
			tail=new;
		}
}
void insert_first()
{
	if(head==NULL)
	{
	  insert_last(ele);
	}
	else
    {
	printf("enter the element to add at first:\n");
    scanf("%d",&ele);
	length++; 
	new=(struct node*)malloc(sizeof(struct node));
	temp1=head;
	head=new;
	head->next=temp1;
	head->data=ele;
	}
	
	
}
void insert_nth()
{ 
	

	printf("enter the position to insert element:\n");
	scanf("%d",&n);

    if(n==1)
	{
	  insert_first();	
	}	
	else if(length+1==n)
	{insert_last();
	}
	else if(n>length+1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{
		printf("enter the element to be added at %d position:\n",n);
	    scanf("%d",&ele);
	    new=(struct node*)malloc(sizeof(struct node));
		temp1=head;
		i=2;
		while (i!=n)
		{   temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		new->data=ele;
		temp1->next=new;
		new->next=temp2;
		length++;
	}
}
void  insert_before_search()
{
	if(head==NULL)
	{
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    stemp=search(ele,head);
     
     if(stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(stemp==head)//searched element is at 1st
	 {
	   	
	   	if(stemp->data==ele)////searched element is at first(special case1)
	    {
	     	insert_first();
        }
     else if(stemp->next->data==ele)//searched element is at second(special case2)
     {
       temp=stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	    new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        stemp->next=new;
        new->next=temp;
    	 length++;
	 }
	 }	
	 else
	 {
	 	printf("enter a element to be inserted front of %d:\n",ele);
	    scanf("%d",&ele);
        temp=stemp->next;
        new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        stemp->next=new;
        new->next=temp;
        length++;
	 }
	 }
    }
}
void  insert_after_search()
{
	 if(head==NULL)
	{
		 	printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    stemp=search(ele,head);
    
    if(stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(stemp->next==tail)//searched element is at 1st
	 {
	   	insert_last();
	 }	
	 else if(stemp==head)
	 {    
	    if(stemp->data==ele)////searched element is at first(special case1)
	    {
	     printf("enter a element:\n");
	    scanf("%d",&ele);
	    new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        temp=stemp->next;
	 	stemp->next=new;
        new->next=temp;
        length++;
      }
     else if(stemp->next->data==ele)//searched element is at second(special case2)
     {
    	stemp=stemp->next;
    	temp=stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	    new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        stemp->next=new;
        new->next=temp;
        length++;
    	
	 }
	 
	 }
	 else
	 {
	 	printf("enter a element to be inserted after of %d:\n",ele);
	    scanf("%d",&ele);
        new=(struct node*)malloc(sizeof(struct node));
        new->data=ele;
        stemp=stemp->next;
        temp=stemp->next;
        stemp->next=new;
        new->next=temp;
        length++;
	 }
	 
		
	}
}
}
void insert_mid()
{
	int mid=0; 
	 mid=ceil((float)length/2);
    if(head==NULL)
    {
    	printf("!!The list is empty!!\n");
    	return;
	}
    else
    {

	if(head!=NULL&&head->next==NULL)
	{
	printf("!!list contains only one element,atleast it should contains two element to insert mid element!!\n");	
	}
	else
	{   
		printf("enter the element to be added at mid position:\n",n);
	    scanf("%d",&ele);
	    new=(struct node*)malloc(sizeof(struct node));
		temp1=head;
		i=1;
		while (i!=mid)
		{   temp1=temp1->next;
			i++;
		}
		temp2=temp1->next;
		new->data=ele;
		temp1->next=new;
		new->next=temp2;
		length++;
	}
}
}
int delete_first()
{   if(isempty())
    {
	  printf("!!linked list is empty!!\n");
    }
    else if(head==tail)
    {length--;   
       del=head->data;
    	tail=head=NULL;
    	return del;
	}
	else
	{length--;
  del=head->data;
  head=head->next;
  return del;
}
}
int delete_last()
{   
if(isempty())
    {
	   printf("!!linked list is empty!!\n");
   }
   else if(head==tail)//only one element
    {    length--;
        del=tail->data;
    	tail=head=NULL;
    	return del;
	}
	else//more than one element
	{temp1=head;
		length--;
            del=tail->data;
            while(temp1->next!=tail)
        	temp1=temp1->next;
         	temp1->next=NULL;
	        tail=temp1;//t1 is last element
	        return del;
      
    }
}
void delete_nth()
 {printf("enter the position to delete element:\n");
	scanf("%d",&n);
 	if(n==1)
 	{
 	del=delete_first();	
 	printf("%d is deleted from 1st position\n",del);
	 }
	 else if(length==n)
	 { 
	 	del=delete_last();
	 	 printf("%d is deleted from last(%d) position\n",del,length+1);
	 }
	 else if(n>length||n<1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{
	    temp1=head;
		i=2;
		while (i!=n)
		{   temp1=temp1->next;
			i++;
		}
		printf("%d is deleted from %d position\n",temp1->next->data,n);
		temp2=temp1->next->next;	
		temp1->next=temp2;
		length--;
	}
	 
 }
 int delete_before_search()
 {
 	if(head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    stemp=search(ele,head);
    if(stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(stemp==head&&stemp->next==NULL)//if only one element present 
	 {del=-1;
	   printf("!!!%d is the first element,so we can't delete its before element!!!\n",ele);
	 }
	 else if(stemp==head&&stemp->next->data!=ele)//searched element is at 1st
	 {	 del=-1;
	   	printf("!!!%d is the first element,so we can't delete its before element!!!\n",ele);
	 }
	 else if(stemp==head&&stemp->next->data==ele)//deleted element at first and searched element is at 2nd
	 {
	 	del=delete_first();
	 }	
	 else//deleted element at middle
	 {print=head;
	 	while(print->next->next->data!=ele)
	 	{
	 		print=print->next;
		 }
	del=stemp->data;	 
	temp=stemp->next;
	stemp=NULL;//stemp is element to be deleted 
	stemp=print;
	stemp->next=temp;
    length--;
	 }
	 }
    }
 	return del;
 }
 int delete_after_search()
 {
 	if(head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{ 
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    stemp=search(ele,head);
     if(stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
    else if(stemp==head&&stemp->next==NULL)//one element
    {
       del=-1;
	   
	   printf("!!!%d is the first element,so we can't delete its before element!!!\n",ele);	
	}
	else if(stemp==head&&stemp->data==ele&&stemp->next==tail)//two element present
	 {
	 	del=delete_last();
	 }
	 else if(stemp->next->next==NULL&&stemp->next==tail)// searched element is at last
	 {del=-1;
	 
	  printf("!!!%d is the last element,so we can't delete its after element!!!\n",ele);
	 }
	else if(stemp==head&&stemp->next->data==ele&&stemp->next->next==tail)//searched element at 2nd(special case 1)
		{
		  del=delete_last();
			
		}
		else if(stemp->data==ele)//searched element at 1st(special case 2)
	   {
		temp=stemp->next->next;
		del=stemp->next->data;
		stemp->next=temp;
		length--;
		}
		else
		{
		
		temp=stemp->next->next->next;
		stemp=stemp->next;
		del=stemp->next->data;
		stemp->next=temp;
		length--;
	    }
}
 	return del;
 }
  int delete_mid()
  {
  	int mid=0; 
	 mid=ceil((float)length/2);
    if(head==NULL)
    {   del=-1;
    	printf("!!The list is empty!!\n");
    	return del;
	}
    else
    {

	if((head->next==NULL)||(head->next->next==NULL))
	{del=-1;
	printf("!!list should contain atleast three element to delete at mid!!\n");	
	}
	else
	{   
	    temp1=head;
		i=2;
		while (i!=mid)
		{   temp1=temp1->next;
			i++;
		}
		del=temp1->next->data;
		temp2=temp1->next->next;
		temp1->next->next=NULL;
		temp1->next=temp2;
		length--;
			}
	return del;
}
  }

struct node* search(int del,struct node* stemp)
{flag=pointer=0;
if(head==tail)
   {
   	print=stemp;
   	if(print->data!=del)
   	{  	flag=0;
   	return NULL;
	   }
}
    for(print=stemp;print!=NULL;print=print->next)
	{
	  pointer++;
	  if((flag==0&&print->data==del))//ele should be deleted present at first
	  { 
		    flag=1;
	    	stemp=head;
	        printf("the element is present at %d position\n",flag);
			return stemp;
	  }
	  else if((print->next!=NULL&&print->next->data==del))//ele should be deleted present at last(or)middle
	  {flag=pointer+1;
	   printf("the element is present at %d position\n",pointer+1);
	  	stemp=print;
	    return stemp;
	  }
	}
	if(flag==0)//element not found
	  {
	 	return 	NULL;
	  } 
	return stemp;//element not found during transversing 
}
void delete_search(int del)
 {  found=0;
if(head==tail&&(tail->data==del&&head->data==del))//element found and it is only one element at first
{  delete_last();
    	stemp=NULL;	//now no element present at list
}
else
{// while traverse until last element
 while((stemp!=NULL&&stemp->next!=NULL)&&(stemp!=tail||stemp->data==del))
  {
	stemp=search(del,stemp);
   if(stemp!=NULL&&stemp!=tail) //element found and it address is on stemp 
   {
    if(flag==1&&stemp->data==del)//it means element should be deleted is at first=>here stemp is address of first element 
 	{found++;
 	delete_first();	
 	stemp=head;//assigning start temp to head
 	flag--;
 	pointer--;
	}
    else if(length==flag)// it means element should be deleted is at last=>here stemp is address of del element before 
	{found++;
	delete_last();
	flag--;
	pointer--;
	}
	
	else if(flag>0&&stemp!=NULL)//(this means not last element)=>here stemp is address of del element before 
	{
	if(stemp->next!=NULL&&stemp->next->data==del)
	{ found++;
		printf("deleted.\n"); 
		temp2=stemp->next->next;
        stemp->next->next=NULL;
		stemp->next=temp2;
	    flag--;
	    pointer--;
	     length--;
    }
    else
      { 
        if(stemp->next!=NULL)
         stemp=stemp->next;//check whether stemp->next!=NULL and then assigning to next so that we can again pass to search function.	
      }  
   }
  }
  
    if(found==0)//element not found
	{
	stemp=NULL;
	printf("element not found\n");  
    } 
  if( head==tail&&(tail->data==del&&head->data==del))//element found and it is only one element at first ex:- 1 and 1 are two element simultaneously
   {   delete_last(); 
    	 stemp=NULL;	//now no element present at list
   }
  }//while end
 found=flag=pointer=0;
}
}

void delete_all()
{  
length=0;
 if(head==NULL)
    isempty();
    else
	head=NULL;
}
/////////////////////doubly-linked-list(function-definition)/////////////

void  doubly_display()
{   if(doubly_isempty())
	printf("!!doubly_linked list is empty!!\n");
   else
   {
   	do
   	{
   		printf("press1 to transverse left to right\npress2 to transverse right to left\n");
    	scanf("%d",&ele);
   	if(ele==1)
   	{
	printf("doubly_linked list left-right:\n");
	for(doubly_print=doubly_head;doubly_print!=NULL;doubly_print=doubly_print->next)
	printf("%d\n", doubly_print->data);
    }
    else if(ele==2)
    {
    printf("doubly_linked list right-left:\n");
	for(doubly_print=doubly_tail;doubly_print!=doubly_head;doubly_print=doubly_print->prev)
	printf("%d\n", doubly_print->data);
	printf("%d\n", doubly_print->data);	
	}
	else
	{
	ele=3;
	system("cls");
     }

   }while(ele==3);
}
}



int doubly_isempty()
{	if(doubly_head==NULL)
	return 1;
	else 
	return 0;
}

void doubly_reverse_list(struct doubly_node*doubly_temp)
{
 

if(doubly_temp->next==NULL)//exit condition
 {  doubly_stemp=doubly_temp;
 	doubly_stemp->prev=NULL;
 	doubly_head=doubly_temp;
 	return;
 }
 doubly_reverse_list(doubly_temp->next);
 doubly_stemp=doubly_temp->next;//here doubly_temp is last before address and p is last doubly_node address 
 doubly_stemp->next=doubly_temp;
 doubly_temp->prev=doubly_stemp;
 doubly_temp->next=NULL;
 doubly_tail=doubly_temp;
   	
/* printf("transverse reverse the list:\n");
	for(print=tail;print!=NULL;print=print->prev)
	printf("%d\n",print->data);	*/
}
void doubly_asort_list()
{
	printf("list are now arranged in ascending order:\n");
	for(doubly_temp=doubly_head;doubly_temp->next!=NULL;doubly_temp=doubly_temp->next)
    {
	for(doubly_stemp=doubly_temp->next;doubly_stemp!=NULL;doubly_stemp=doubly_stemp->next)
	{
		if(doubly_temp->data>doubly_stemp->data)
		{
	    del=doubly_temp->data;
			doubly_temp->data=doubly_stemp->data;
			doubly_stemp->data=del;
		}
	}
}
}
void doubly_dsort_list()
{
	printf("list are now arranged in descending order:\n");
	for(doubly_temp=doubly_head;doubly_temp!=NULL;doubly_temp=doubly_temp->next)
{
	for(doubly_stemp=doubly_head;doubly_stemp!=NULL;doubly_stemp=doubly_stemp->next)
	{
		if(doubly_temp->data>doubly_stemp->data)
		{
			del=doubly_temp->data;
			doubly_temp->data=doubly_stemp->data;
			doubly_stemp->data=del;
		}
	}
}
}
void doubly_insert_last()
{
        doubly_length++;
		printf("enter the element:\n");
		scanf("%d",&ele);
		doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_new->next=NULL;
        
		if(doubly_head==NULL)
		{
			doubly_head=doubly_new;
			doubly_head->prev=NULL;
			doubly_tail=doubly_new;
		}
		else
		{
			doubly_tail->next=doubly_new;
			doubly_new->prev=doubly_tail;
			doubly_tail=doubly_new;
		}
}
void doubly_insert_first()
{
	if(doubly_head==NULL)
	{
	  doubly_insert_last(ele);
	}
	else
	{printf("enter the element to added at first:\n");
	scanf("%d",&ele);
	doubly_length++; 
	doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
	doubly_new->data=ele;
	doubly_new->next=doubly_head;
	doubly_head->prev=doubly_new;
	doubly_head=doubly_new;
	doubly_head->prev=NULL;
	}
	
	
}
void doubly_insert_nth()
{
	
	doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
	printf("enter the position to insert element:\n");
	scanf("%d",&n);

    if(n==1)
	{
	  doubly_insert_first(ele);	
	}	
	else if(n==doubly_length+1)
	{doubly_insert_last(ele);
	}
	else if(n>doubly_length+1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{
		printf("enter the element to be added at %d position:\n",n);
	    scanf("%d",&ele);
	    doubly_new->data=ele;
		i=2;
		doubly_temp=doubly_head;
		while(i<=n)
		{   doubly_temp=doubly_temp->next;
			i++;
		}
		doubly_temp->prev->next=doubly_new;
		doubly_new->prev=doubly_temp->prev;
		doubly_new->next=doubly_temp;
		doubly_temp->prev=doubly_new;
		doubly_length++;
	}
}
void doubly_insert_before_search()
{
	if(doubly_head==NULL)
	{
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    doubly_stemp=doubly_search(ele,doubly_head);
     
     if(doubly_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(doubly_stemp==doubly_head)//searched element is at 1st
	 {
	   
	   	if(doubly_stemp->data==ele)////searched element is at first(special case1)
	    {
	     	doubly_insert_first();
        }
     else if(doubly_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	doubly_temp=doubly_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	    doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_stemp->next=doubly_new;
        doubly_new->prev=doubly_stemp;
        doubly_temp->prev=doubly_new;
        doubly_new->next=doubly_temp;
    	 doubly_length++;
	 }
	 }	
	 else
	 {
	 	printf("enter a element to be inserted front of %d:\n",ele);
	    scanf("%d",&ele);
        doubly_temp=doubly_stemp->next;
        doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_stemp->next=doubly_new;
        doubly_new->prev=doubly_stemp;
        doubly_new->next=doubly_temp;
        doubly_temp->prev=doubly_new;
        doubly_length++;
	 }
	 }
    }	
}
void doubly_insert_after_search()
{
	 if(doubly_head==NULL)
	{
		 	printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    doubly_stemp=doubly_search(ele,doubly_head);
    
    if(doubly_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(doubly_stemp->next==doubly_tail)//searched element is at 1st
	 {
	   	doubly_insert_last();
	 }	
	 else if(doubly_stemp==doubly_head)
	 {  
	    if(doubly_stemp->data==ele)////searched element is at first(special case1)
	    {
	     printf("enter a element:\n");
	    scanf("%d",&ele);
	    doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_temp=doubly_stemp->next;
        doubly_temp->prev=doubly_new;
	 	doubly_stemp->next=doubly_new;
	 	doubly_new->prev=doubly_stemp;
        doubly_new->next=doubly_temp;
        doubly_length++;
      }
     else if(doubly_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	doubly_stemp=doubly_stemp->next;
    	doubly_temp=doubly_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	    doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_stemp->next=doubly_new;
        doubly_new->prev=doubly_stemp;
        doubly_temp->prev=doubly_new;
        doubly_new->next=doubly_temp;
    	 doubly_length++;
	 }
	 }
	 else
	 {
	 	printf("enter a element to be inserted after of %d:\n",ele);
	    scanf("%d",&ele);
        doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
        doubly_new->data=ele;
        doubly_stemp=doubly_stemp->next;
        doubly_temp=doubly_stemp->next;
        doubly_stemp->next=doubly_new;
        doubly_new->next=doubly_temp;
        doubly_new->prev=doubly_stemp;
        doubly_temp->prev=doubly_new;
        doubly_length++;
	 }		
	}
}
	
}
void doubly_insert_mid()
{
	int mid=0; 
	 mid=ceil((float)doubly_length/2);
    if(doubly_head==NULL)
    {
    	printf("!!The list is empty!!\n");
    	return;
	}
    else
    {

	if(doubly_head!=NULL&&doubly_head->next==NULL)
	{
	printf("!!list contains only one element,atleast it should contains two element to insert mid element!!\n");	
	}
	else
	{   
		printf("enter the element to be added at mid position:\n",n);
	    scanf("%d",&ele);
	    doubly_new=(struct doubly_node*)malloc(sizeof(struct doubly_node));
		doubly_temp1=doubly_head;
		i=1;
		while (i!=mid)
		{   doubly_temp1=doubly_temp1->next;
			i++;
		}
		doubly_temp2=doubly_temp1->next;
		doubly_new->data=ele;
		doubly_temp1->next=doubly_new;
		doubly_new->prev=doubly_temp1;
		doubly_temp2->prev=doubly_new;
		doubly_new->next=doubly_temp2;
		doubly_length++;
	}
}
	
	
}
int doubly_delete_first()
{   if(doubly_isempty())
    {
	  printf("!!linked list is empty!!\n");
    }
    else if(doubly_head==doubly_tail)//only one element
    {doubly_length--;   
       del=doubly_head->data;
    	doubly_tail=doubly_head=NULL;
    	return del;
	}
	else
	{doubly_length--;
  del=doubly_head->data;
  doubly_head=doubly_head->next;
  doubly_head->prev=NULL;
  return del;
}
}
int doubly_delete_last()
{   
if(doubly_isempty())
    {
	   printf("!!linked list is empty!!\n");
   }
   else if(doubly_head==doubly_tail)//only one element
    {    doubly_length--;
        del=doubly_tail->data;
    	doubly_tail=doubly_head=NULL;
    	return del;
	}
	else//more than one element
	{
		    doubly_length--;
            del=doubly_tail->data;
            doubly_tail=doubly_tail->prev;
            doubly_tail->next=NULL;
	        return del;
      
     }
}
void doubly_delete_nth()
 {printf("enter the position to delete element:\n");
	scanf("%d",&n);
 	if(n==1)
 	{
 	del=doubly_delete_first();	
 	printf("%d is deleted from 1st position\n",del);
	 }
	 else if(doubly_length==n)
	 { 
	 	del=doubly_delete_last();
	 	printf("%d is deleted from last(%d) position\n",del,doubly_length+1);
	 }
	 else if(n>doubly_length||n<1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{	
	    doubly_temp=doubly_head;
		i=2;
		while (i<=n)
		{   doubly_temp=doubly_temp->next;
			i++;
		}
	
		printf("%d is deleted from %d position\n",doubly_temp->data,n);
		doubly_temp->next->prev=doubly_temp->prev;
		doubly_temp->prev->next=doubly_temp->next;
		doubly_temp->prev=doubly_temp->next=NULL;
		doubly_length--;
	}
	 
 }
 int doubly_delete_before_search()
{
	if(doubly_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    doubly_stemp=doubly_search(ele,doubly_head);
    if(doubly_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(doubly_stemp==doubly_head&&doubly_stemp->next==NULL)//if only one element present 
	 {del=-1;
	   printf("!!!%d is the first element,so we can't delete its before element!!!\n",ele);
	 }
	 else if(doubly_stemp==doubly_head&&doubly_stemp->next->data!=ele)//searched element is at 1st
	 {	 del=-1;
	   	printf("!!!%d is the first element,so we can't delete its before element!!!\n",ele);
	 }
	 else if(doubly_stemp==doubly_head&&doubly_stemp->next->data==ele)//deleted element at first and searched element is at 2nd
	 {
	 	del=doubly_delete_first();
	 }	
	 else//deleted element at middle
	 {  	
	    del=doubly_stemp->data;
	    doubly_temp=doubly_stemp->next;
	   	doubly_stemp=doubly_stemp->prev;
	    doubly_stemp->next->next=NULL;
	    doubly_stemp->next->prev=NULL;
	    doubly_stemp->next=doubly_temp;
	    doubly_temp->prev=doubly_stemp;
	    doubly_length--;
	 }
	 }
    }
 	return del;
}
int doubly_delete_after_search()
{
	if(doubly_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
    doubly_stemp=doubly_search(ele,doubly_head);
    if(doubly_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if(doubly_stemp==doubly_head&&doubly_stemp->next==NULL)//one element
    {
       del=-1;
	   
	   printf("!!!%d is only one element,so we can't delete its after element!!!\n",ele);	
	}
	else if(doubly_stemp==doubly_head&&doubly_stemp->data==ele&&doubly_stemp->next==doubly_tail)//two element present
	 {
	 	del=doubly_delete_last();
	 }
	 else if(doubly_stemp->next->next==NULL&&doubly_stemp->next==doubly_tail)// searched element is at last
	 {del=-1;
	   printf("!!!%d is the last element,so we can't delete its after element!!!\n",ele);
	 }
	else if(doubly_stemp==doubly_head&&doubly_stemp->next->data==ele&&doubly_stemp->next->next==doubly_tail)//searched element at 2nd(special case 1)
		{
		  del=doubly_delete_last();	
		}
		else if(doubly_stemp->data==ele)//searched element at 1st(special case 2)
	    {
	   	del=doubly_stemp->next->data;
	   	doubly_temp=doubly_stemp->next->next;
	   	doubly_stemp->next->next=NULL;
	   	doubly_stemp->next->prev=NULL;
	   	doubly_stemp->next=doubly_temp;
	   	doubly_temp->prev=doubly_stemp;
		doubly_length--;
		}
		else//part(middle)
		{
	
	    if(doubly_stemp->next->next->next==NULL)//deleted element at last
	    { 
	      del=doubly_delete_last();	
		}
		else //deleted element at middle
		{ 
		  doubly_stemp=doubly_stemp->next;
		  del=doubly_stemp->next->data;
		  doubly_temp=doubly_stemp->next->next;
		  doubly_stemp->next->next=NULL;
		  doubly_stemp->next->prev=NULL;
		  doubly_stemp->next=doubly_temp;
		  doubly_temp->prev=doubly_stemp; 
		 	doubly_length--;
		}
	
	    }
	 }
    }
 	return del;
}
int  doubly_delete_mid()
{
	
  	int mid=0; 
	 mid=ceil((float)doubly_length/2);
    if(doubly_head==NULL)
    {   del=-1;
    	printf("!!The list is empty!!\n");
    	return del;
	}
    else
    {

	if((doubly_head->next==NULL)||(doubly_head->next->next==NULL))
	{del=-1;
		printf("!!list should contain atleast three element to delete at mid!!\n");		
	}
	else
	{   
	    doubly_temp1=doubly_head;
		i=2;
		while (i!=mid)
		{   doubly_temp1=doubly_temp1->next;
			i++;
		}
		del=doubly_temp1->next->data;
		doubly_temp2=doubly_temp1->next->next;
		doubly_temp1->next->next=NULL;
		doubly_temp1->next->prev=NULL;
		doubly_temp1->next=doubly_temp2;
		doubly_temp2->prev=doubly_temp1;
		doubly_length--;
			}
	return del;
}
	
	
}
 struct doubly_node* doubly_search(int del,struct doubly_node* doubly_stemp)
{   flag=pointer=0;
if(doubly_head==doubly_tail)
   {
   	doubly_print=doubly_stemp;
   	if(doubly_print->data!=del)
   	{  	flag=0;
   	return NULL;
	   }
}
    for(doubly_print=doubly_stemp;doubly_print!=NULL;doubly_print=doubly_print->next)
	{
	  pointer++;
	  if((flag==0&&doubly_print->data==del))//ele should be deleted present at first
	  { 
		    flag=1;
	    	doubly_stemp=doubly_head;
	        printf("the element is present at %d position\n",flag);
			return doubly_stemp;
	  }
	  else if((doubly_print->next!=NULL&&doubly_print->next->data==del))//ele should be deleted present at last(or)middle
	  {flag=pointer+1;
	   printf("the element is present at %d position\n",pointer+1);
	  	doubly_stemp=doubly_print;
	    return doubly_stemp;
	  }
	}
	if(flag==0)//element not found
	  {
	 	return 	NULL;
	  } 
	return doubly_stemp;//element not found during transversing 
}
void doubly_delete_search(int del)
 {  found=0;
if(doubly_head==doubly_tail&&(doubly_tail->data==del&&doubly_head->data==del))//element found and it is only one element at first
{  doubly_delete_last();
    	doubly_stemp=NULL;	//now no element present at list
}
else
{// while traverse until last element
 while((doubly_stemp!=NULL&&doubly_stemp->next!=NULL)&&(doubly_stemp!=doubly_tail||doubly_stemp->data==del))
  {
	doubly_stemp=doubly_search(del,doubly_stemp);
   if(doubly_stemp!=NULL&&doubly_stemp!=doubly_tail) //element found and it address is on doubly_stemp
   {
    if(flag==1&&doubly_stemp->data==del)//it means element should be deleted is at first=>here doubly_stemp is address of first element 
 	{found++;
 	doubly_delete_first();	
 	doubly_stemp=doubly_head;//assigning start doubly_temp to doubly_doubly_head
 	flag--;
 	pointer--;
	}
    else if(doubly_length==flag)// it means element should be deleted is at last=>here doubly_stemp is address of del element before 
	{found++;
	doubly_delete_last();
	flag--;
	pointer--;
	}
	
	else if(flag>0&&doubly_stemp!=NULL)//(this means not last element)=>here doubly_stemp is address of del element before
	{
	if(doubly_stemp->next!=NULL&&doubly_stemp->next->data==del)
	{found++;	
	printf("deleted.\n");
	     doubly_temp=doubly_stemp->next;//here doubly_stemp is address of del element
		  //printf(".........doubly_temp->data=%d,doubly_stemp->data=%d.........\n",doubly_temp->data,doubly_stemp->data);
	    doubly_temp->next->prev=doubly_temp->prev;
		doubly_temp->prev->next=doubly_temp->next;
		doubly_temp->prev=doubly_temp->next=NULL;
	    flag--;
	    pointer--;
	     doubly_length--;
    }
    else
      { 
        if(doubly_stemp->next!=doubly_head)
         doubly_stemp=doubly_stemp->next;//check whether doubly_stemp->next!=NULL and then assigning to next so that we can again pass to search function.	
      }  
   }
  }
  
    if(found==0)//element not found
	{doubly_stemp=NULL;
	printf("element not found\n");
    } 
    if( doubly_head==doubly_tail&&( doubly_tail->data==del&& doubly_head->data==del))//element found and it is only one element at first
   {   
    	 doubly_delete_last(); 
    	 doubly_stemp=NULL;	//now no element present at list
   }

  }//while end
 found=flag=pointer=0;
}
}

void doubly_delete_all()
{   
 doubly_length=0;
 if(doubly_head==NULL)
    doubly_isempty();
    else
    {
	doubly_head=NULL;
	doubly_tail=NULL;
    }
}

///////////////////// circular-linked-list(function-definition)/////////////
void  circular_display()
{   if(circular_isempty())
	printf("!!circular_linked list is empty!!\n");
   else
   {
	printf("circular_linked list :\n");
	if(circular_head==circular_tail)
	{printf("%d\n", circular_head->data);
	}
	else
	{
	for(circular_print=circular_head;circular_print->next!=circular_head;circular_print=circular_print->next)
	printf("%d\n", circular_print->data);
     printf("%d\n", circular_print->data);
    }

    }
	
}
int  circular_isempty()
{	if(circular_head==NULL)
	return 1;
	else 
	return 0;
}

void  circular_reverse_list(struct circular_node* circular_temp)
{
 

if( circular_temp->next==circular_head)//exit condition
 {   	 circular_head=circular_temp;
 	return;
 }
  circular_reverse_list( circular_temp->next);
  circular_stemp= circular_temp->next;//here  circular_temp is last before address and p is last  circular_node address 
  circular_stemp->next= circular_temp;
  circular_temp->next=NULL;
  circular_tail= circular_temp;
  circular_tail->next=circular_head;
   	
/* printf("transverse reverse the list:\n");
	for(print=tail;print!=NULL;print=print->prev)
	printf("%d\n",print->data);	*/
}
void  circular_asort_list()
{
	printf("list are now arranged in ascending order:\n");
	for( circular_temp= circular_head; circular_temp->next!=circular_head; circular_temp= circular_temp->next)
    {
	for( circular_stemp= circular_temp->next; circular_stemp!=circular_head; circular_stemp= circular_stemp->next)
	{
		if( circular_temp->data> circular_stemp->data)
		{
	    del= circular_temp->data;
			 circular_temp->data= circular_stemp->data;
			 circular_stemp->data=del;
		}
	}
}
}
void  circular_dsort_list()
{
	printf("list are now arranged in descending order:\n");
		for( circular_temp= circular_head; circular_temp->next!=circular_head; circular_temp= circular_temp->next)
    {
	for( circular_stemp= circular_temp->next; circular_stemp!=circular_head; circular_stemp= circular_stemp->next)
	{
		if( circular_temp->data< circular_stemp->data)
		{
	    del= circular_temp->data;
			 circular_temp->data= circular_stemp->data;
			 circular_stemp->data=del;
		}
	}
}

}
void  circular_insert_last()
{
         circular_length++;
		printf("enter the element:\n");
		scanf("%d",&ele);
		 circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_new->next=NULL;
        
		if( circular_head==NULL)
		{
			 circular_head= circular_new;
			 circular_tail= circular_new;
		}
		else
		{
			 circular_tail->next= circular_new;
			 circular_tail= circular_new;
		}
		circular_tail->next=circular_head;
}
void  circular_insert_first()
{
	if( circular_head==NULL)
	{
	   circular_insert_last(ele);
	}
	else
	{printf("enter the element to added at first:\n");
	scanf("%d",&ele);
	 circular_length++; 
	 circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
	 circular_new->data=ele;
	 circular_new->next=circular_head;
	 circular_head=circular_new;
	 	circular_tail->next=circular_head;
	}
}
void  circular_insert_nth()
{
	
	 
	printf("enter the position to insert element:\n");
	scanf("%d",&n);

    if(n==1)
	{
	   circular_insert_first(ele);	
	}	
	else if(n== circular_length+1)
	{ circular_insert_last(ele);
	}
	else if(n> circular_length+1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{
		printf("enter the element to be added at %d position:\n",n);
	    scanf("%d",&ele);
	    circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
		i=2;
		 circular_temp1=circular_head;
		while(i!=n)
		{    circular_temp1= circular_temp1->next;
			i++;
		}
	
		 circular_temp2= circular_temp1->next;
		  circular_new->data=ele;
		 circular_temp1->next=circular_new;
		 circular_new->next= circular_temp2;
		 circular_length++;
	}
}
void  circular_insert_before_search()
{
	if( circular_head==NULL)
	{
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_stemp= circular_search(ele, circular_head);
     
     if( circular_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_stemp== circular_head)//searched element is at 1st
	 {
	   
	   	if( circular_stemp->data==ele)////searched element is at first(special case1)
	    {
	     	 circular_insert_first();
        }
     else if( circular_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	 circular_temp= circular_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_stemp->next= circular_new;
         circular_new->next= circular_temp;
    	  circular_length++;
	 }
	 }	
	 else
	 {
	 	printf("enter a element to be inserted front of %d:\n",ele);
	    scanf("%d",&ele);
         circular_temp= circular_stemp->next;
         circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_stemp->next= circular_new; 
         circular_new->next= circular_temp;
         circular_length++;
	 }
	 }
    }	
}
void  circular_insert_after_search()
{
	 if( circular_head==NULL)
	{
		 	printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_stemp= circular_search(ele, circular_head);
    
    if( circular_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_stemp->next== circular_tail)//searched element is at 1st
	 {
	   	 circular_insert_last();
	 }	
	 else if( circular_stemp== circular_head)
	 {  
	    if( circular_stemp->data==ele)////searched element is at first(special case1)
	    {
	     printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_temp= circular_stemp->next;
	 	 circular_stemp->next= circular_new;
         circular_new->next= circular_temp;
         circular_length++;
      }
     else if( circular_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	 circular_stemp= circular_stemp->next;
    	 circular_temp= circular_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_stemp->next= circular_new;
         circular_new->next= circular_temp;
    	  circular_length++;
	 }
	 }
	 else
	 {
	 	printf("enter a element to be inserted after of %d:\n",ele);
	    scanf("%d",&ele);
         circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
         circular_new->data=ele;
         circular_stemp= circular_stemp->next;
         circular_temp= circular_stemp->next;
         circular_stemp->next= circular_new;
         circular_new->next= circular_temp;
         circular_length++;
	 }		
	}
}
	
}
void  circular_insert_mid()
{
	int mid=0; 
	 mid=ceil((float) circular_length/2);
    if( circular_head==NULL)
    {
    	printf("!!The list is empty!!\n");
    	return;
	}
    else
    {

	if( circular_head!=NULL&& circular_head->next==NULL)
	{
	printf("!!list contains only one element,atleast it should contains two element to insert mid element!!\n");	
	}
	else
	{   
		printf("enter the element to be added at mid position:\n",n);
	    scanf("%d",&ele);
	     circular_new=(struct  circular_node*)malloc(sizeof(struct  circular_node));
		 circular_temp1= circular_head;
		i=1;
		while (i!=mid)
		{    circular_temp1= circular_temp1->next;
			i++;
		}
		 circular_temp2= circular_temp1->next;
		 circular_new->data=ele;
		 circular_temp1->next= circular_new;
		 circular_new->next= circular_temp2;
		 circular_length++;
	}
}
	
	
}
int  circular_delete_first()
{   if( circular_isempty())
    {
	  printf("!!linked list is empty!!\n");
    }
    else if( circular_head==circular_tail)//only one element
    { circular_length--;   
       del=circular_head->data;
    	 circular_tail=circular_head=NULL;
    	return del;
	}
	else if(circular_head->next==circular_tail)//two elements
	{
	  circular_length--;
      del=circular_head->data;
      circular_head=circular_head->next;
      circular_head->next=circular_tail->next=NULL;
      return del;  	
	}
	else//more than two elements
	{ circular_length--;
      del=circular_head->data;
      circular_head= circular_head->next;
      circular_tail->next=circular_head;
      return del;
}
}
int  circular_delete_last()
{   
if( circular_isempty())
    {
	   printf("!!linked list is empty!!\n");
   }
   else if( circular_head== circular_tail)//only one element
    {     circular_length--;
        del= circular_tail->data;
    	 circular_tail= circular_head=NULL;
    	return del;
	}
	else if(circular_head->next==circular_tail)//two elements
	{
	  circular_length--;
      del=circular_tail->data;
      circular_tail=circular_head;
      circular_head->next=circular_tail->next=NULL;
      return del;  	
	}
	else//more than one element
	{
		    circular_temp1=circular_head;
		circular_length--;
            del=circular_tail->data;
            while(circular_temp1->next!=circular_tail)
        	circular_temp1=circular_temp1->next;
         	circular_temp1->next=NULL;
	        circular_tail=circular_temp1;//t1 is last element
	         circular_tail->next= circular_head;
	        return del;
    }
}
void  circular_delete_nth()
 {
 	if( circular_isempty())
    {
	   printf("!!linked list is empty!!\n");
   }
   else
   {
 printf("enter the position to delete element:\n");
	scanf("%d",&n);
 	if(n==1)
 	{
 	 del=circular_delete_first();	
 	 	printf("%d is deleted from 1st position\n",del);
	}
	 else if( circular_length==n)
	 { 
	 	 del=circular_delete_last();
	 	 printf("%d is deleted from last(%d) position\n",del,circular_length+1);
	 }
	 else if(n>circular_length||n<1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{	
	     circular_temp1= circular_head;
		i=2;
		while (i!=n)
		{    circular_temp1= circular_temp1->next;
			i++;
		}
	
		printf("%d is deleted from %d position\n", circular_temp1->next->data,n);
		 circular_temp2=circular_temp1->next->next;	
		circular_temp1->next=circular_temp2;
		
		 circular_length--;
	}
}
 }
 int  circular_delete_before_search()
{
	if( circular_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_stemp= circular_search(ele, circular_head);
    if( circular_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_stemp== circular_head&& circular_stemp->next==NULL)//if only one element present 
	 {del=-1;
	   printf("!!!%d is only one element present,so we can't delete its before element!!!\n",ele);
	 }
	 else if( circular_stemp== circular_head&& circular_stemp->next->data!=ele)//searched element is at 1st
	 {	 del=circular_delete_last();
	   	
	 }
	 else if( circular_stemp== circular_head&& circular_stemp->next->data==ele)//deleted element at first and searched element is at 2nd
	 {
	 	del= circular_delete_first();
	 }	
	 else//deleted element at middle
	 {  	
	    circular_print=circular_head;
	 	while(circular_print->next->next->data!=ele)
	 	{
	 		circular_print=circular_print->next;
		 }
	del=circular_stemp->data;	 
	circular_temp=circular_stemp->next;
	circular_stemp=NULL;//stemp is element to be deleted 
	circular_stemp=circular_print;
	circular_stemp->next=circular_temp;
	     circular_length--;
	 }
	 }
    }
 	return del;
}
int  circular_delete_after_search()
{
	if( circular_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_stemp= circular_search(ele, circular_head);
   if( circular_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_stemp== circular_head&& circular_stemp->next==NULL)//one element
    {
       del=-1;
	   
	   printf("!!!%d is only one element,so we can't delete its after element!!!\n",ele);	
	}
	else if( circular_stemp== circular_head&& circular_stemp->data==ele&& circular_stemp->next== circular_tail)//two element present
	 {
	 	del= circular_delete_last();
	 	
	 }
	 else if( circular_stemp->next->next==circular_head&& circular_stemp->next== circular_tail)// searched element is at last
	 {del=circular_delete_first();
	 }
	else if( circular_stemp== circular_head&& circular_stemp->next->data==ele&& circular_stemp->next->next== circular_tail)//searched element at 2nd(special case 1)
		{
		  del= circular_delete_last();	
		}
		else if( circular_stemp->data==ele)//searched element at 1st(special case 2)
	    {
	   	del= circular_stemp->next->data;
	   	 circular_temp= circular_stemp->next->next;
	   	 circular_stemp->next->next=NULL;
	   	 circular_stemp->next= circular_temp;
		 circular_length--;
		}
		else//part(middle)
		{
	
	    if( circular_stemp->next->next->next==circular_head)//deleted element at last
	    { 
	      del= circular_delete_last();	
		}
		else //deleted element at middle
		{ 
		   circular_stemp= circular_stemp->next;
		  del= circular_stemp->next->data;
		   circular_temp= circular_stemp->next->next;
		   circular_stemp->next->next=NULL;
		   circular_stemp->next= circular_temp;
		 	 circular_length--;
		}
	
	    }
	 }
    }
 	return del;
}
int   circular_delete_mid()
{
	
  	int mid=0; 
	 mid=ceil((float) circular_length/2);
    if( circular_head==NULL)
    {   del=-1;
    	printf("!!The list is empty!!\n");
    	return del;
	}
    else
    {

	if(( circular_head==circular_tail)||( circular_head->next->next==circular_head))
	{del=-1;
		printf("!!list should contain atleast three element to delete at mid!!\n");		
	}
	else
	{   
	     circular_temp1= circular_head;
		i=2;
		while (i!=mid)
		{    circular_temp1= circular_temp1->next;
			i++;
		}
		del= circular_temp1->next->data;
		 circular_temp2= circular_temp1->next->next;
		 circular_temp1->next->next=NULL;
		 circular_temp1->next= circular_temp2;
		 circular_length--;
			}
	return del;
}
	
	
}
 struct  circular_node*  circular_search(int del,struct  circular_node*  circular_stemp)
{   flag=pointer=0;

   if(circular_head==circular_tail)
   {
   	circular_print=circular_stemp;
   	if(circular_print->data!=del)
   	{  	flag=0;
   	return NULL;
	   }
   }
   for( circular_print=circular_stemp; circular_print->next!=circular_head; circular_print= circular_print->next)
	{
	  pointer++;
	  if((flag==0&& circular_print->data==del))//ele should be deleted present at first
	  { 
		    flag=1;
	    	 circular_stemp= circular_head;
	        printf("the element is present at %d position\n",flag);
			return  circular_stemp;
	  }
	  else if(( circular_print->next!=NULL&& circular_print->next->data==del))//ele should be deleted present at last(or)middle
	  {flag=pointer+1;
	   printf("the element is present at %d position\n",pointer+1);
	  	 circular_stemp= circular_print;
	    return  circular_stemp;
	  }
	}

	if(flag==0)//element not found
	  {
	 	return 	NULL;
	  } 
	return  circular_stemp;//element not found during transversing 
}

void  circular_delete_search(int del)
 {  found=0;
if( circular_head== circular_tail&&( circular_tail->data==del&& circular_head->data==del))//element found and it is only one element at first
{   circular_delete_last();
    	 circular_stemp=NULL;	//now no element present at list
}
else
{// while traverse until last element
 while(( circular_stemp!=NULL&& circular_stemp->next!=circular_head)&&( circular_stemp!= circular_tail|| circular_stemp->data==del))
  { 
  
   circular_stemp= circular_search(del, circular_stemp);
  
   if( circular_stemp!=NULL&& circular_stemp!= circular_tail) //element found and it address is on  circular_stemp
   {
    if(flag==1&& circular_stemp->data==del)//it means element should be deleted is at first=>here  circular_stemp is address of first element 
 	{found++;
 	 circular_delete_first();	
 	 circular_stemp= circular_head;//assigning start  circular_temp to  circular_ circular_head
 	flag--;
 	pointer--;
	}
    else if( circular_length==flag)// it means element should be deleted is at last=>here  circular_stemp is address of del element before 
	{found++;
	 circular_delete_last();
	 circular_stemp= circular_head;//assigning start  circular_doubly_temp to  circular_doubly_ circular_doubly_head
	flag--;
	pointer--;
	}
	
	else if(flag>0&& circular_stemp!=NULL)//(this means not last element)=>here  circular_stemp is address of del element before
	{
	if( circular_stemp->next!=circular_head&& circular_stemp->next->data==del)
	{	printf("deleted.\n");
	found++;
	       circular_temp= circular_stemp->next->next;//here  circular_doubly_stemp is address of del before element
	      circular_stemp->next=circular_temp;
	      circular_stemp= circular_head;//assigning start  circular_doubly_temp to  circular_doubly_ circular_doubly_head
	    flag--;
	    pointer--;
	      circular_length--;
    }
    else
      { 
        if(circular_stemp->next!=circular_head)
         circular_stemp=circular_stemp->next;//check whether doubly_stemp->next!=NULL and then assigning to next so that we can again pass to search function.	
      } 
   }
  }
  if(found==0)
  {
  circular_stemp=NULL;
  printf("!!not found!!\n");
}
   if( circular_head==circular_tail&&( circular_tail->data==del&& circular_head->data==del))//element found and it is only one element at first
   {   
    	 circular_delete_last(); 
    	 circular_stemp=NULL;	//now no element present at list
   }

  }//while end
  
  
    
 found=flag=pointer=0;
}
}

void  circular_delete_all()
{   
  circular_length=0;
 if( circular_head==NULL)
     circular_isempty();
    else
    {
	 circular_head=NULL;
	 circular_tail=NULL;
    }
}


///////////////////// circular_doubly-linked-list(function-definition)/////////////
void  circular_doubly_display()
{   if(circular_doubly_isempty())
	printf("!!circular_doubly_linked list is empty!!\n");
   else
   {
   	do
   	{
   		printf("press1 to transverse left to right\npress2 to transverse right to left\n");
    	scanf("%d",&ele);
   	if(ele==1)
   	{
	printf("circular_doubly_linked list left-right:\n");
	if(circular_doubly_head==circular_doubly_tail)
	{printf("%d\n", circular_doubly_head->data);
	}
	else
	{
	for(circular_doubly_print=circular_doubly_head;circular_doubly_print->next!=circular_doubly_head;circular_doubly_print=circular_doubly_print->next)
	printf("%d\n", circular_doubly_print->data);
     printf("%d\n", circular_doubly_print->data);
    }
}
    else if(ele==2)
    {
    printf("circular_doubly_linked list right-left:\n");
    	if(circular_doubly_head==circular_doubly_tail)
	{printf("%d\n", circular_doubly_head->data);
	}
	else
	{
	for(circular_doubly_print=circular_doubly_tail; circular_doubly_print!=circular_doubly_head;circular_doubly_print=circular_doubly_print->prev)
	printf("%d\n", circular_doubly_print->data);
	printf("%d\n", circular_doubly_print->data);	
	}
}
	else
	{
	ele=3;
	system("cls");
}

   }while(ele==3);
}
}
int  circular_doubly_isempty()
{	if(circular_doubly_head==NULL)
	return 1;
	else 
	return 0;
}

void  circular_doubly_reverse_list(struct circular_doubly_node* circular_doubly_temp)
{
 

if( circular_doubly_temp->next==circular_doubly_head)//exit condition
 {   circular_doubly_stemp= circular_doubly_temp;
 	 circular_doubly_stemp->prev=circular_doubly_head;
 	 circular_doubly_head=circular_doubly_temp;
 	return;
 }
  circular_doubly_reverse_list( circular_doubly_temp->next);
  circular_doubly_stemp= circular_doubly_temp->next;//here  circular_doubly_temp is last before address and p is last  circular_doubly_node address 
  circular_doubly_stemp->next= circular_doubly_temp;
  circular_doubly_temp->prev= circular_doubly_stemp;
  circular_doubly_temp->next=NULL;
  circular_doubly_tail= circular_doubly_temp;
  circular_doubly_tail->next=circular_doubly_head;
   	
/* printf("transverse reverse the list:\n");
	for(print=tail;print!=NULL;print=print->prev)
	printf("%d\n",print->data);	*/
}
void  circular_doubly_asort_list()
{
	printf("list are now arranged in ascending order:\n");
	for( circular_doubly_temp= circular_doubly_head; circular_doubly_temp->next!=circular_doubly_head; circular_doubly_temp= circular_doubly_temp->next)
    {
	for( circular_doubly_stemp= circular_doubly_temp->next; circular_doubly_stemp!=circular_doubly_head; circular_doubly_stemp= circular_doubly_stemp->next)
	{
		if( circular_doubly_temp->data> circular_doubly_stemp->data)
		{
	    del= circular_doubly_temp->data;
			 circular_doubly_temp->data= circular_doubly_stemp->data;
			 circular_doubly_stemp->data=del;
		}
	}
}
}
void  circular_doubly_dsort_list()
{
	printf("list are now arranged in descending order:\n");
		for( circular_doubly_temp= circular_doubly_head; circular_doubly_temp->next!=circular_doubly_head; circular_doubly_temp= circular_doubly_temp->next)
    {
	for( circular_doubly_stemp= circular_doubly_temp->next; circular_doubly_stemp!=circular_doubly_head; circular_doubly_stemp= circular_doubly_stemp->next)
	{
		if( circular_doubly_temp->data< circular_doubly_stemp->data)
		{
	    del= circular_doubly_temp->data;
			 circular_doubly_temp->data= circular_doubly_stemp->data;
			 circular_doubly_stemp->data=del;
		}
	}
}

}
void  circular_doubly_insert_last()
{
         circular_doubly_length++;
		printf("enter the element:\n");
		scanf("%d",&ele);
		 circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_new->next=NULL;
        
		if( circular_doubly_head==NULL)
		{
			 circular_doubly_head= circular_doubly_new;
			 circular_doubly_head->prev=NULL;
			 circular_doubly_tail= circular_doubly_new;
		}
		else
		{
			 circular_doubly_tail->next= circular_doubly_new;
			 circular_doubly_new->prev= circular_doubly_tail;
			 circular_doubly_tail= circular_doubly_new;
		}
		circular_doubly_tail->next=circular_doubly_head;
		circular_doubly_head->prev=circular_doubly_tail;
}
void  circular_doubly_insert_first()
{
	if( circular_doubly_head==NULL)
	{
	   circular_doubly_insert_last(ele);
	}
	else
	{printf("enter the element to added at first:\n");
	scanf("%d",&ele);
	 circular_doubly_length++; 
	 circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
	 circular_doubly_new->data=ele;
	 circular_doubly_new->next=circular_doubly_head;
	 circular_doubly_head->prev= circular_doubly_new;
	 circular_doubly_head=circular_doubly_new;
	 circular_doubly_head->prev=circular_doubly_tail;
	 	circular_doubly_tail->next=circular_doubly_head;
	}
}
void  circular_doubly_insert_nth()
{
	
	 circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
	printf("enter the position to insert element:\n");
	scanf("%d",&n);

    if(n==1)
	{
	   circular_doubly_insert_first(ele);	
	}	
	else if(n== circular_doubly_length+1)
	{ circular_doubly_insert_last(ele);
	}
	else if(n> circular_doubly_length+1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{
		printf("enter the element to be added at %d position:\n",n);
	    scanf("%d",&ele);
	     circular_doubly_new->data=ele;
		i=2;
		 circular_doubly_temp= circular_doubly_head;
		while(i<=n)
		{    circular_doubly_temp= circular_doubly_temp->next;
			i++;
		}
		 circular_doubly_temp->prev->next= circular_doubly_new;
		 circular_doubly_new->prev= circular_doubly_temp->prev;
		 circular_doubly_new->next= circular_doubly_temp;
		 circular_doubly_temp->prev= circular_doubly_new;
		 circular_doubly_length++;
	}
}
void  circular_doubly_insert_before_search()
{
	if( circular_doubly_head==NULL)
	{
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_doubly_stemp= circular_doubly_search(ele, circular_doubly_head);
     
     if( circular_doubly_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_doubly_stemp== circular_doubly_head)//searched element is at 1st
	 {
	   
	   	if( circular_doubly_stemp->data==ele&&circular_doubly_stemp->prev==circular_doubly_tail)////searched element is at first(special case1)
	    {
	     	 circular_doubly_insert_first();
        }
     else if( circular_doubly_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	 circular_doubly_temp= circular_doubly_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_stemp->next= circular_doubly_new;
         circular_doubly_new->prev= circular_doubly_stemp;
         circular_doubly_temp->prev= circular_doubly_new;
         circular_doubly_new->next= circular_doubly_temp;
    	  circular_doubly_length++;
	 }
	 }	
	 else
	 {
	 	printf("enter a element to be inserted front of %d:\n",ele);
	    scanf("%d",&ele);
         circular_doubly_temp= circular_doubly_stemp->next;
         circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_stemp->next= circular_doubly_new;
         circular_doubly_new->prev= circular_doubly_stemp;
         circular_doubly_new->next= circular_doubly_temp;
         circular_doubly_temp->prev= circular_doubly_new;
         circular_doubly_length++;
	 }
	 }
    }	
}
void  circular_doubly_insert_after_search()
{
	 if( circular_doubly_head==NULL)
	{
		 	printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_doubly_stemp= circular_doubly_search(ele, circular_doubly_head);
    
    if( circular_doubly_stemp==NULL)
    {
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_doubly_stemp->next== circular_doubly_tail)//searched element is at 1st
	 {
	   	 circular_doubly_insert_last();
	 }	
	 else if( circular_doubly_stemp== circular_doubly_head)
	 {  
	    if( circular_doubly_stemp->data==ele)////searched element is at first(special case1)
	    {
	     printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_temp= circular_doubly_stemp->next;
         circular_doubly_temp->prev= circular_doubly_new;
	 	 circular_doubly_stemp->next= circular_doubly_new;
	 	 circular_doubly_new->prev= circular_doubly_stemp;
         circular_doubly_new->next= circular_doubly_temp;
         circular_doubly_length++;
      }
     else if( circular_doubly_stemp->next->data==ele)//searched element is at second(special case2)
     {
    	 circular_doubly_stemp= circular_doubly_stemp->next;
    	 circular_doubly_temp= circular_doubly_stemp->next;
    	 printf("enter a element:\n");
	    scanf("%d",&ele);
	     circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_stemp->next= circular_doubly_new;
         circular_doubly_new->prev= circular_doubly_stemp;
         circular_doubly_temp->prev=circular_doubly_new;
         circular_doubly_new->next= circular_doubly_temp;
    	  circular_doubly_length++;
	 }
	 }
	 else
	 {
	 	printf("enter a element to be inserted after of %d:\n",ele);
	    scanf("%d",&ele);
         circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
         circular_doubly_new->data=ele;
         circular_doubly_stemp= circular_doubly_stemp->next;
         circular_doubly_temp= circular_doubly_stemp->next;
         circular_doubly_stemp->next= circular_doubly_new;
         circular_doubly_new->next= circular_doubly_temp;
         circular_doubly_new->prev= circular_doubly_stemp;
         circular_doubly_temp->prev=circular_doubly_new;
         circular_doubly_length++;
	 }		
	}
}
	
}
void  circular_doubly_insert_mid()
{
	int mid=0; 
	 mid=ceil((float) circular_doubly_length/2);
    if( circular_doubly_head==NULL)
    {
    	printf("!!The list is empty!!\n");
    	return;
	}
    else
    {

	if( circular_doubly_head!=NULL&& circular_doubly_head->next==NULL)
	{
	printf("!!list contains only one element,atleast it should contains two element to insert mid element!!\n");	
	}
	else
	{   
		printf("enter the element to be added at mid position:\n",n);
	    scanf("%d",&ele);
	     circular_doubly_new=(struct  circular_doubly_node*)malloc(sizeof(struct  circular_doubly_node));
		 circular_doubly_temp1= circular_doubly_head;
		i=1;
		while (i!=mid)
		{    circular_doubly_temp1= circular_doubly_temp1->next;
			i++;
		}
		 circular_doubly_temp2= circular_doubly_temp1->next;
		 circular_doubly_new->data=ele;
		 circular_doubly_temp1->next= circular_doubly_new;
		 circular_doubly_new->prev= circular_doubly_temp1;
		 circular_doubly_temp2->prev= circular_doubly_new;
		 circular_doubly_new->next= circular_doubly_temp2;
		 circular_doubly_length++;
	}
}
	
	
}
int  circular_doubly_delete_first()
{   if( circular_doubly_isempty())
    {
	  printf("!!linked list is empty!!\n");
    }
    else if( circular_doubly_head==circular_doubly_tail)//only one element
    { circular_doubly_length--;   
       del=circular_doubly_head->data;
    	 circular_doubly_tail=circular_doubly_head=NULL;
    	return del;
	}
	else if(circular_doubly_head->next==circular_doubly_tail)//two elements
	{
	  circular_doubly_length--;
      del=circular_doubly_head->data;
      circular_doubly_head=circular_doubly_head->next;
      circular_doubly_head->prev=circular_doubly_tail->prev=NULL;
      circular_doubly_head->next=circular_doubly_tail->next=NULL;
      return del;  	
	}
	else//more than two elements
	{ circular_doubly_length--;
      del=circular_doubly_head->data;
      circular_doubly_head= circular_doubly_head->next;
      circular_doubly_head->prev=circular_doubly_tail;
      circular_doubly_tail->next=circular_doubly_head;
      return del;
}
}
int  circular_doubly_delete_last()
{   
if( circular_doubly_isempty())
    {
	   printf("!!linked list is empty!!\n");
   }
   else if( circular_doubly_head== circular_doubly_tail)//only one element
    {     circular_doubly_length--;
        del= circular_doubly_tail->data;
    	 circular_doubly_tail= circular_doubly_head=NULL;
    	return del;
	}
	else if(circular_doubly_head->next==circular_doubly_tail)//two elements
	{
	  circular_doubly_length--;
      del=circular_doubly_tail->data;
      circular_doubly_tail=circular_doubly_head;
      circular_doubly_head->prev=circular_doubly_tail->prev=NULL;
      circular_doubly_head->next=circular_doubly_tail->next=NULL;
      return del;  	
	}
	else//more than one element
	{
		    circular_doubly_length--;
            del= circular_doubly_tail->data;
            circular_doubly_tail= circular_doubly_tail->prev;
            circular_doubly_tail->next=circular_doubly_head;
            circular_doubly_head->prev=circular_doubly_tail;
	        return del;
    }
}
void  circular_doubly_delete_nth()
 {printf("enter the position to delete element:\n");
	scanf("%d",&n);
 	if(n==1)
 	{
 	 del=circular_doubly_delete_first();	
 	 	printf("%d is deleted from 1st position\n",del);
	}
	 else if( circular_doubly_length==n)
	 { 
	 	 del=circular_doubly_delete_last();
	 	 printf("%d is deleted from last(%d) position\n",del,circular_doubly_length+1);
	 }
	 else if(n>circular_doubly_length||n<1)
    {
    	printf("!!The position given is invalid!!\n");
	}
	else
	{	
	     circular_doubly_temp= circular_doubly_head;
		i=2;
		while (i<=n)
		{    circular_doubly_temp= circular_doubly_temp->next;
			i++;
		}
	
		printf("%d is deleted from %d position\n", circular_doubly_temp->data,n);
		 circular_doubly_temp->next->prev= circular_doubly_temp->prev;
		 circular_doubly_temp->prev->next= circular_doubly_temp->next;
		 circular_doubly_temp->prev= circular_doubly_temp->next=NULL;
		 circular_doubly_length--;
	}
	 
 }
 int  circular_doubly_delete_before_search()
{
	if( circular_doubly_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_doubly_stemp= circular_doubly_search(ele, circular_doubly_head);
    if( circular_doubly_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->next==NULL)//if only one element present 
	 {del=-1;
	   printf("!!!%d is only one element present,so we can't delete its before element!!!\n",ele);
	 }
	 else if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->next->data!=ele)//searched element is at 1st
	 {	 del=circular_doubly_delete_last();
	   	
	 }
	 else if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->next->data==ele)//deleted element at first and searched element is at 2nd
	 {
	 	del= circular_doubly_delete_first();
	 }	
	 else//deleted element at middle
	 {  	
	    del= circular_doubly_stemp->data;
	     circular_doubly_temp= circular_doubly_stemp->next;
	   	 circular_doubly_stemp= circular_doubly_stemp->prev;
	     circular_doubly_stemp->next->next=NULL;
	     circular_doubly_stemp->next->prev=NULL;
	     circular_doubly_stemp->next= circular_doubly_temp;
	     circular_doubly_temp->prev= circular_doubly_stemp;
	     circular_doubly_length--;
	 }
	 }
    }
 	return del;
}
int  circular_doubly_delete_after_search()
{
	if( circular_doubly_head==NULL)
	{   del=-1;
	    printf("!!list is empty!!\n");	
	}
	else
	{
	printf("enter the element to be searched:\n");
    scanf("%d",&ele);
     circular_doubly_stemp= circular_doubly_search(ele, circular_doubly_head);
   if( circular_doubly_stemp==NULL)
    {   del=-1;
    	printf("!!!%d not found!!!\n",ele);
	}
	else
	{
	 if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->next==NULL)//one element
    {
       del=-1;
	   
	   printf("!!!%d is only one element,so we can't delete its after element!!!\n",ele);	
	}
	else if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->data==ele&& circular_doubly_stemp->next== circular_doubly_tail)//two element present
	 {
	 	del= circular_doubly_delete_last();
	 	
	 }
	 else if( circular_doubly_stemp->next->next==circular_doubly_head&& circular_doubly_stemp->next== circular_doubly_tail)// searched element is at last
	 {del=circular_doubly_delete_first();
	 }
	else if( circular_doubly_stemp== circular_doubly_head&& circular_doubly_stemp->next->data==ele&& circular_doubly_stemp->next->next== circular_doubly_tail)//searched element at 2nd(special case 1)
		{
		  del= circular_doubly_delete_last();	
		}
		else if( circular_doubly_stemp->data==ele)//searched element at 1st(special case 2)
	    {
	   	del= circular_doubly_stemp->next->data;
	   	 circular_doubly_temp= circular_doubly_stemp->next->next;
	   	 circular_doubly_stemp->next->next=NULL;
	   	 circular_doubly_stemp->next->prev=NULL;
	   	 circular_doubly_stemp->next= circular_doubly_temp;
	   	 circular_doubly_temp->prev= circular_doubly_stemp;

		 circular_doubly_length--;
		}
		else//part(middle)
		{
	
	    if( circular_doubly_stemp->next->next->next==circular_doubly_head)//deleted element at last
	    { 
	      del= circular_doubly_delete_last();	
		}
		else //deleted element at middle
		{ 
		   circular_doubly_stemp= circular_doubly_stemp->next;
		  del= circular_doubly_stemp->next->data;
		   circular_doubly_temp= circular_doubly_stemp->next->next;
		   circular_doubly_stemp->next->next=NULL;
		   circular_doubly_stemp->next->prev=NULL;
		   circular_doubly_stemp->next= circular_doubly_temp;
		   circular_doubly_temp->prev= circular_doubly_stemp; 
		 	 circular_doubly_length--;
		}
	
	    }
	 }
    }
 	return del;
}
int   circular_doubly_delete_mid()
{
	
  	int mid=0; 
	 mid=ceil((float) circular_doubly_length/2);
    if( circular_doubly_head==NULL)
    {   del=-1;
    	printf("!!The list is empty!!\n");
    	return del;
	}
    else
    {

	if(( circular_doubly_head==circular_doubly_tail)||( circular_doubly_head->next->next==circular_doubly_head))
	{del=-1;
		printf("!!list should contain atleast three element to delete at mid!!\n");		
	}
	else
	{   
	     circular_doubly_temp1= circular_doubly_head;
		i=2;
		while (i!=mid)
		{    circular_doubly_temp1= circular_doubly_temp1->next;
			i++;
		}
		del= circular_doubly_temp1->next->data;
		 circular_doubly_temp2= circular_doubly_temp1->next->next;
		 circular_doubly_temp1->next->next=NULL;
		 circular_doubly_temp1->next->prev=NULL;
		 circular_doubly_temp1->next= circular_doubly_temp2;
		 circular_doubly_temp2->prev= circular_doubly_temp1;
		 circular_doubly_length--;
			}
	return del;
}
	
	
}
 struct  circular_doubly_node*  circular_doubly_search(int del,struct  circular_doubly_node*  circular_doubly_stemp)
{   flag=pointer=0;

   if(circular_doubly_head==circular_doubly_tail)
   {
   	circular_doubly_print=circular_doubly_stemp;
   	if(circular_doubly_print->data!=del)
   	{  	flag=0;
   	return NULL;
	   }
   }
   for( circular_doubly_print=circular_doubly_stemp; circular_doubly_print->next!=circular_doubly_head; circular_doubly_print= circular_doubly_print->next)
	{
	  pointer++;
	  if((flag==0&& circular_doubly_print->data==del))//ele should be deleted present at first
	  { 
		    flag=1;
	    	 circular_doubly_stemp= circular_doubly_head;
	        printf("the element is present at %d position\n",flag);
			return  circular_doubly_stemp;
	  }
	  else if(( circular_doubly_print->next!=NULL&& circular_doubly_print->next->data==del))//ele should be deleted present at last(or)middle
	  {flag=pointer+1;
	   printf("the element is present at %d position\n",pointer+1);
	  	 circular_doubly_stemp= circular_doubly_print;
	    return  circular_doubly_stemp;
	  }
	}

	if(flag==0)//element not found
	  {
	 	return 	NULL;
	  } 
	return  circular_doubly_stemp;//element not found during transversing 
}

void  circular_doubly_delete_search(int del)
 {  found=0;
if( circular_doubly_head== circular_doubly_tail&&( circular_doubly_tail->data==del&& circular_doubly_head->data==del))//element found and it is only one element at first
{   circular_doubly_delete_last();
    	 circular_doubly_stemp=NULL;	//now no element present at list
}
else
{// while traverse until last element
 while(( circular_doubly_stemp!=NULL&& circular_doubly_stemp->next!=circular_doubly_head)&&( circular_doubly_stemp!= circular_doubly_tail|| circular_doubly_stemp->data==del))
  { 
  
   circular_doubly_stemp= circular_doubly_search(del, circular_doubly_stemp);
  
   if( circular_doubly_stemp!=NULL&& circular_doubly_stemp!= circular_doubly_tail) //element found 
   {
    if(flag==1&& circular_doubly_stemp->data==del)//it means element should be deleted is at first=>here  circular_doubly_stemp is address of first element 
 	{found++;
 	 circular_doubly_delete_first();	
 	 circular_doubly_stemp= circular_doubly_head;//assigning start  circular_doubly_temp to  circular_doubly_ circular_doubly_head
 	flag--;
 	pointer--;
	}
    else if( circular_doubly_length==flag)// it means element should be deleted is at last=>here  circular_doubly_stemp is address of del element before 
	{found++;
	 circular_doubly_delete_last();
	 circular_doubly_stemp= circular_doubly_head;//assigning start  circular_doubly_temp to  circular_doubly_ circular_doubly_head
	flag--;
	pointer--;
	}
	else if(flag>0&& circular_doubly_stemp!=NULL)//(this means not last element)=>here  circular_doubly_stemp is address of del element before
	{
	if( circular_doubly_stemp->next!=NULL&& circular_doubly_stemp->next->data==del)
	{	printf("deleted.\n");
	found++;
	
	      circular_doubly_temp= circular_doubly_stemp->next->next;//here  circular_doubly_stemp is address of del before element
	      circular_doubly_stemp->next=circular_doubly_temp;
	      circular_doubly_temp->prev=circular_doubly_stemp;
	      circular_doubly_stemp= circular_doubly_head;//assigning start  circular_doubly_temp to  circular_doubly_ circular_doubly_head
	    flag--;
	    pointer--;
	      circular_doubly_length--;
    }
    else
      { 
        if(circular_doubly_stemp->next!=circular_doubly_head)
         circular_doubly_stemp=circular_doubly_stemp->next;//check whether doubly_stemp->next!=NULL and then assigning to next so that we can again pass to search function.	
      } 
   }
  }
  if(found==0)
  {
  circular_doubly_stemp=NULL;
  printf("!!not found!!\n");
}
   if( circular_doubly_head==circular_doubly_tail&&( circular_doubly_tail->data==del&& circular_doubly_head->data==del))//element found and it is only one element at first
   {   
    	 circular_doubly_delete_last(); 
    	 circular_doubly_stemp=NULL;	//now no element present at list
   }

  }//while end
  
  
    
 found=flag=pointer=0;
}
}

void  circular_doubly_delete_all()
{   
  circular_doubly_length=0;
 if( circular_doubly_head==NULL)
     circular_doubly_isempty();
    else
    {
	 circular_doubly_head=NULL;
	 circular_doubly_tail=NULL;
    }
}


     //                                      /////////////////////bst(function-definition)/////////////

int bst_isempty(struct bst_node*bst_root)
{
	if(bst_root==NULL)
	return 1;
	else
	return 0;
}
void bst_print(struct bst_node*bst_root)
{
	if(bst_root!=NULL)
	{
	  printf("%d\n",bst_root->data);
	  bst_print(bst_root->left);
	  bst_print(bst_root->right);
	}
}
void bst_create()
{

	bst_new=(struct bst_node*)malloc(sizeof(struct bst_node));
    printf("enter the element:\n");
    scanf("%d",&ele);
    bst_new->left=NULL;
    bst_new->data=ele;
    bst_new->right=NULL;
    if(bst_root==NULL)
    {
    	bst_root=bst_new;
	}
    else
    {
    	bst_insert(bst_root,bst_new);
	}
}
void bst_insert(struct bst_node*bst_root,struct bst_node*bst_new)
{
	if(bst_new->data<=bst_root->data)
	{
		if(bst_root->left==NULL)
		{
		  bst_root->left=bst_new;	
		}
		else
		{
			bst_insert(bst_root->left,bst_new);
		}
	}
	if(bst_new->data>bst_root->data)
	{
		if(bst_root->right==NULL)
		{
			bst_root->right=bst_new;
		}
		else
		{
			bst_insert(bst_root->right,bst_new);
		}
	}
}
struct bst_node* delete(struct bst_node*bst_root,int ele)
{
	if(bst_root->data==ele)
	{found=1;
		if(bst_root->right==NULL&&bst_root->left==NULL)
		{
		 return 0;
		}
		else if(bst_root->right!=NULL&&bst_root->left==NULL)
		{
			return bst_root->right;
		}
		else if(bst_root->right==NULL&&bst_root->left!=NULL)
		{
			return bst_root->left;
		}
		else
		{
			bst_root->data=bst_find_min(bst_root->right);//replace rights minimum or left maximum
			bst_root->right=delete(bst_root->right,bst_root->data);	
		}
	}
	else
	{
		if(ele<=bst_root->data)
		{ if(bst_root->left==NULL)
	   {
	   	found=0;
	   	return bst_root;
	   }
	   else
			bst_root->left=delete(bst_root->left,ele);
		}
		else
		{if(bst_root->right==NULL)
	   {
	   	found=0;
	   	return bst_root;
	   }
	   else
			bst_root->right=delete(bst_root->right,ele);
		}
		
	}
	
	
}

int bst_search(struct bst_node*bst_root,int ele)
{  if(bst_root!=NULL)
   {

	if(ele<bst_root->data)
	{ 
		ele=bst_search(bst_root->left,ele);
		return ele;
	}
	else if(ele>bst_root->data)
	{ 
		ele=bst_search(bst_root->right,ele);
			return ele;
	}
	else if(ele==bst_root->data)
	{
		return bst_root->data;
	}
   }
		return -1;	 
    
}

int bst_find_min(struct bst_node*bst_root)
 {
	if(bst_root->left==NULL)
	{
		return bst_root->data;
	}
	else
	{
		bst_find_min(bst_root->left);
	}
}
int bst_find_max(struct bst_node*bst_root)
{
	if(bst_root->right==NULL)
	{
		return bst_root->data;
	}
	else
	{
		bst_find_max(bst_root->right);
	}
}

//                                      /////////////////////avl(function-definition)/////////////

 struct avl_node* avl_create(int ele)
 {
 	struct avl_node*avl_new;
 	avl_new=(struct avl_node*)malloc(sizeof(struct avl_node));
 	avl_new->data=ele;
 	avl_new->right=NULL;
 	avl_new->left=NULL;
 	avl_new->height=1;
 	return avl_new;
 }
 int avl_height(struct avl_node*r)
 { 
   if(r==NULL)
   {
   	return 0;
   }
   return r->height;	
 }
 int avl_max(int a,int b)
 {
 	if(a>b)
 	return a;
 	else 
 	return b;
 }
 int avl_balance_factor(struct avl_node*r)
 {
 	if(r==NULL)
    return 0;
    else
 	return avl_height(r->left)-avl_height(r->right);
 }
 struct avl_node* avl_right_rotate(struct avl_node*r)
 {
 	struct avl_node *a=r->left;
 	struct avl_node *y=a->right;
 	
 	a->right=r;
 	r->left=y;
 	
 	r->height=1+avl_max(avl_height(r->left),avl_height(r->right));
 	a->height=1+avl_max(avl_height(a->left),avl_height(a->right));
 
 	return a;
 }
struct avl_node* avl_left_rotate(struct avl_node*r)
{
	struct avl_node *a=r->right;
 	struct avl_node *y=a->left;
 	
     a->left=r;
     r->right=y;
     
    r->height=1+avl_max(avl_height(r->left),avl_height(r->right));
 	a->height=1+avl_max(avl_height(a->left),avl_height(a->right));
	
	return a;
}

 struct avl_node* avl_insert(struct avl_node*r,int ele)
 {
 	if(r==NULL)
 	{
 		return avl_create(ele);
	}
	else if(ele<r->data)
	 {
	 	r->left=avl_insert(r->left,ele);
	 }
	 else if(ele>r->data)
	 {
	 	r->right=avl_insert(r->right,ele);
	 }
	 else
	 {
	 	return r;
	 }
	 //recursion half
	 r->height=1+avl_max(avl_height(r->left),avl_height(r->right));//avl_height function return the avl_height of current right and left child avl_node,and we should check the avl_max and
     avl_bf=avl_balance_factor(r);     //add 1 so that we get avl_height avl_height of current avl_node(just we are updating common factor of current avl_node). 
     //left-left
	 if(avl_bf>1&&ele<r->left->data)
	 {
	 	return avl_right_rotate(r);
	 }
	 //left-right
     else if(avl_bf>1&&ele>r->left->data)
     {
     	r->left=avl_left_rotate(r->left);
     	return avl_right_rotate(r);
	 }
	 //right-right
	 else if(avl_bf<-1&&ele>r->right->data)
	 {
	 	return avl_left_rotate(r);
	 }
	 //right-left
	 else if(avl_bf<-1&&ele<r->right->data)
	 {
	 	r->right=avl_right_rotate(r->right);
	 	return avl_left_rotate(r);
	 }
    return r;
 }
 
struct avl_node*avl_delete(struct avl_node*r,int val)
{
	if(r->data!=val)
    {

     if(val<=r->data){
	   if(r->left==NULL)
	   {
	   	found=0;
	   	return r;
	   }
	   else
	   r->left=avl_delete(r->left,val);}
	
   	else {
	    if(r->right==NULL)
	   {
	   	found=0;
	   	return r;
	   }
	   else
    	r->right=avl_delete(r->right,val);}
    	
	}
	else
	{found=1;
		if(r->left==NULL&&r->right==NULL)
	    	return 0;
		else if(r->left==NULL&&r->right!=NULL)
	        return r->right;
		else if(r->right==NULL&&r->left!=NULL)
	    	return r->left;
		else 
		{
	    	r->data=find_avl_min(r->right); 
       	//	printf("after alternation:\n");
       	//	print(root);
       	     r->right=avl_delete(r->right,r->data);    
	    }   	
	}
	
int balance_factor=avl_balance_factor(r);
   //left-left
	 if(balance_factor>1)
	 	return avl_right_rotate(r);
	 
	  //right-right
	 if (balance_factor<-1)
	 	return avl_left_rotate(r);
	
	return r;	   
}
	
 

 int avl_search(struct avl_node*r,int ele)
 {  if(r!=NULL)
   {

	if(ele<r->data)
	{ 
		ele=avl_search(r->left,ele);
		return ele;
	}
	else if(ele>r->data)
	{ 
		ele=avl_search(r->right,ele);
			return ele;
	}
	else if(ele==r->data)
	{
		return r->data;
	}
   }
		return -1;	 
    
}

 int find_avl_min(struct avl_node*avl_root)
{
	if(avl_root->left==NULL)
	{
		return avl_root->data;
	}
	else
	{
		find_avl_min(avl_root->left);
	}
}
int find_avl_max(struct avl_node*avl_root)
{
	if(avl_root->right==NULL)
	{
		return avl_root->data;
	}
	else
	{
		find_avl_max(avl_root->right);
	}
}

void avl_print(struct avl_node *avl_root)
{
	if(avl_root!=NULL)
	{
		printf("%d\n",avl_root->data);
		avl_print(avl_root->left);
		avl_print(avl_root->right);
	}
	 
}

int avl_isempty(struct avl_node *avl_root)
{
	if(avl_root==NULL)
	return 1;
	return 0;
} 


















