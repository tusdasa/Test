#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void en(char* username,char* temp,int n);
bool check(char * username,char * password);

void main()
{
	char username[7]="admind";
	char password[6];
	char temp[6];

	en(username,temp,5);
	
	printf("\n");
	printf("\n");
	printf("Please input your code:");
    scanf("%s",&password);
	printf("\n");
	if(check(password,temp)){
		printf("You get it!\n");
	}else{
		printf("Bad register-code, keep trying.\n");
	}
}


void en(char* username,char* temp,int n)
{
    int i=0,j=0;
	
	for(;j<2;j++){
		*username=username[j]+1;
	}

    for(i=0;i<n;i++)
    {
        temp[i]=username[i]+3;
		if(i%2==0 && i>0){
			temp[i]=username[i]-1;
		}
    }
}


bool check(char * password,char * temp){
	if(strcmp(password, temp)==0){
		return true;
	}else{
		return false;
	}
}