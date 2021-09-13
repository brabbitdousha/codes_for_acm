#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{  int x=0;int f=1;char ch=getchar();
while(ch>'9'||ch<'0'){if(ch=='-'){f=-1;}ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}

int main()
{
   string a;
   getline(cin,a);int pos=0;int k=0;int pos2=0;int fla=0;
   for(int i=0;i<a.length();i++)
   {
   	   if(a[i]=='.'){k=1;pos=i;continue;}
   	   if(a[i]=='/'){k=2;pos=i;break;}
   	   if(a[i]=='%'){k=3;pos=i;break;}
   	   if(k==1&&a[i]=='0'&&!fla){pos2++;}
   	   if(k==1&&a[i]!='0'){fla=1;} 	      
   }int f=0;
   if(k==0)
   {if(a.length()==1){cout<<a[0];return 0;}
   for(int i=a.length()-1;i>=0;i--)
   {  if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
        
    }return 0;
    } 
    if(k==2)
    {   if(pos-1==0&&a[pos-1]=='0'){cout<<"0";return 0;}
	   else
	   {for(int i=pos-1;i>=0;i--)
       { 
           if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
       }
       cout<<a[pos];f=0;
       for(int i=a.length()-1;i>=pos+1;i--)
       {
       	if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
       }
    return 0;
       }
   }
   if(k==1)
    {   if(pos==1){cout<<a[0];}
	   else for(int i=pos-1;i>=0;i--)
       { 
           if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
       }
       cout<<a[pos];f=0;
       if(a.length()-pos-1==1){cout<<a[pos+1];return 0;}
	   else for(int i=a.length()-1;i>=pos+pos2+1;i--)
       {
       	if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
       }
    return 0;
   }
   if(k==3)
   {
   	if(a.length()==2){cout<<a[0];}
   	  else for(int i=a.length()-2;i>=0;i--)
   {  if(a[i]=='0'&&!f){continue;}
        else{cout<<a[i];if(!f)f=1;}
        
    }cout<<a[pos];return 0;
   } 
}
    
    
    
	
		
		   
		   
		   
		   	
