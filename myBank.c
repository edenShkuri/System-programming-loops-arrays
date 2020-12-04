#include <stdio.h>
#define size 50
double acc[2][size]={0};

void openAccount()
{
 double amount;
  printf("Please enter amount for deposit: ");
  if(scanf(" %lf", &amount)==0)
   {
    printf("Failed to read the amount\n");
    return;
   }
  if(amount<0)
   {
    printf("Invalid Amount\n");
    return;
   }
  for(int i=0; i<size; i++)
  {
    if(acc[1][i]==0)
    {
      acc[0][i]=amount;
      acc[1][i]=1.0;
      printf("New account number is: %d\n", 901+i);
      return;
    }
  }
  printf("there is no available account\n"); 
}

void checkBalance()
{
 int account;
 printf("Please enter account number: ");
 if((scanf(" %d", &account))==0)
 {
  printf("Failed to read the account number\n");
  return;
 }
 if (account<901 ||account>950) 
 {
  printf("invalid acount number \n");
  return;
 }
 if(acc[1][account-901]==0)
 {
  printf("This account is closed\n"); 
  return;
 }
  printf("The balance of account number %d is: %0.2lf\n",account, acc[0][account-901]);
}

void deposit()
{
int account;
printf("Please enter account number: ");
if((scanf(" %d", &account))==0)
   {
     printf("Failed to read the account number\n");
     return;
   }
if (account<901 ||account>950)
{
  printf("invalid acount number \n");
  return;
}
if(acc[1][account-901]==0)
{
printf("This account is closed\n");
return;
}
 double amount;
printf("Please enter amount for deposit: ");
if((scanf(" %lf", &amount)==0))
   {
     printf("Failed to read the amount\n");
     return;
   }
if(amount<0)
{
  printf("Cannot deposit a negative amount\n");
  return;
}
    acc[0][account-901]+=amount;
    printf("The new balance is: %0.2lf\n", acc[0][account-901]);
 
}

void withdraw()
{
 int account;
printf("Please enter account number: ");
if((scanf(" %d", &account))==0)
   {
     printf("Failed to read the account number\n");
     return;
   }
if (account<901 ||account>950)
{
  printf("invalid acount number \n");
  return;
}
if(acc[1][account-901]==0)
 {
    printf("This account is closed\n"); 
    return;
 }

 double amount;
printf("Please enter the amount to withdraw: ");
if((scanf(" %lf", &amount)==0))
   {
     printf("Failed to read the amount\n");
     return;
   }
if(amount<0)
{
  printf("Cannot withdraw a negative amount\n");
  return;
}
 
    if((acc[0][account-901]-amount)<0)
        printf("Cannot withdraw more than the balance\n");
    else
    {
    acc[0][account-901]-=amount;
    printf("the balance after withdraw: %0.2lf\n", acc[0][account-901]);
    }

}

void closeAccount()
{
int account;
printf("Please enter account number: ");
if((scanf(" %d", &account))==0)
   {
     printf("Failed to read the account number\n");
     return;
   }
if (account<901 ||account>950)
{
  printf("invalid acount number \n");
  return;
}
 if(acc[1][account-901]==0)
 { 
   printf("This account is already closed\n"); 
   return;
 }
 
    acc[1][account-901]=0;
    acc[0][account-901]=0;
    printf("Closed account number %d\n", account);
 
 
}

void addInterest()
{
  int rate;
  printf("Please enter interest rate: ");
  if((scanf(" %d", &rate))==0)
    {
      printf("Failed to read the interest rate\n");
      return;
    }
  if(rate<0)
    {
      printf("Invalid interest rate\n");
      return;
    }
  for(int i=0; i<size; i++)
    {
      if(acc[1][i]==1)
        acc[0][i]*=(1+rate/100.0);
    }
 }

void printAccount()
{
for(int i=0; i<size; i++)
{
  if(acc[1][i]==1)
  {
     printf("\nThe balance of account number %d is: %0.2lf\n",901+i,acc[0][i]);
  }
}
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
