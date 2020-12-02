#include <stdio.h>
#define size 50
double acc[2][size]={0};

double getAmount()
{
double amount;
printf("enter amount \n");
if((scanf(" %lf", &amount)==0))
    return -1;
else return amount; 
}

int getAccountNum()
{
int account;
printf("enter account number \n");
if((scanf(" %d", &account))==0)
   {
     printf("invalid acount number \n");
     return -1;
   }
if (account<901 ||account>950)
{
  printf("invalid acount number \n");
  return -1;
}
else return account;
}

void openAccount()
{
 double amount=getAmount();
 if(amount<0)
 {
  printf("invalid number \n");
  return;
 }
 for(int i=0; i<size; i++)
 {
  if(acc[1][i]==0)
  {
      acc[0][i]=amount;
      acc[1][i]=1.0;
      printf("account number: %d\n", 901+i);
      return;
  }
 }
 printf("there is no available account\n"); 
}

void checkBalance()
{
 int accountNum=getAccountNum();
 if(accountNum<0)
  return;
 if(acc[1][accountNum-901]==1)
    printf("the balance for this account: %0.2lf\n", acc[0][accountNum-901]);
 else
 printf("this account is close\n"); 
}

void deposit()
{
 int accountNum=getAccountNum();
 double amount=getAmount();
 if(amount<0)
 {
  printf("invalid number \n");
  return;
 }
 if(accountNum<0)
  return;
 if(acc[1][accountNum-901]==1)
 {
     acc[0][accountNum-901]+=amount;
    printf("the balance after deposit: %0.2lf\n", acc[0][accountNum-901]);
 }
 else
 printf("this account is close\n"); 
}

void withdraw()
{
 int accountNum=getAccountNum();
 double amount=getAmount();
 if(amount<0)
 {
  printf("invalid number \n");
  return;
 }
 if(accountNum<0)
  return;
 if(acc[1][accountNum-901]==1)
 {
    if((acc[0][accountNum-901]-amount)<0)
        printf("you can't withdraw more than you have\n");
    else
    {
    acc[0][accountNum-901]-=amount;
    printf("the balance after withdraw: %0.2lf\n", acc[0][accountNum-901]);
    }
 }
 else
  printf("this account is close\n"); 
}

void closeAccount()
{
int accountNum=getAccountNum();
if(accountNum<0)
  return;
 if(acc[1][accountNum-901]==1)
 {
    acc[1][accountNum-901]=0;
    acc[0][accountNum-901]=0;
    printf("this account has been closed as you wish\n");
 }
 else
 printf("this account is already close\n"); 
}

void addInterest()
{
double rate;
printf("enter amount \n");
if((scanf(" %lf", &rate)==0))
 return;
for(int i=0; i<size; i++)
 {
  if(acc[1][i]==1)
  {
    acc[0][i]*=(1+rate/100.0);
  }
 }
}

void printAccount()
{
int count=0;
for(int i=0; i<size; i++)
{
  if(acc[1][i]==1)
  {
    count++;
     printf("account number: %d \n", 901+i);
     printf("balance: %0.2lf \n", acc[0][i]);   
     printf("--------\n");
  }
}
if(count==0)
 printf("there is no open accounts\n");
}

void closeAccounts()
{
for(int i=0; i<size; i++)
{
  if(acc[1][i]==1)
  {
    acc[1][i]=0;
    acc[0][i]=0;
  }
}
}