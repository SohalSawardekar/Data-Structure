#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

char infix[MAX];
char postfix[MAX];
long int stack[MAX];
int top=-1;

void push(long int symbol){
  if(top==MAX-1)
  {
    printf("Stack Overflow");
    return;
  }
  stack[++top]=symbol;
}

long int pop(){
if(top==-1){
 printf("Stack underflow");
 exit(1);
}
return stack[top--];
}

int whitespace(char symbol)
{
 if(symbol==BLANK||symbol==TAB)
    return 1;
 else
    return 0;
}

int instack_priority(char symbol)
{
  switch(symbol){
     case '(':
           return 0;
     case '+':
     case '-':
           return 1;
     case '*':
     case '/':
     case '%':
           return 2;
     case '^':
           return 3;
}
}

int incoming_priority(char symbol)
{
  switch(symbol){
     case '(':
           return 0;
     case '+':
     case '-':
           return 1;
     case '*':
     case '/':
     case '%':
           return 2;
     case '^':
           return 4;
}
}

void infix_to_postfix(){
  int i, p=0, j;
  char symbol, next;

  printf("Symbol\t\tStack\t\tPostfix\n");
  for(i=0; i<strlen(infix); i++){
      symbol=infix[i];
      printf("%c\t\t", symbol);
      if(!whitespace(symbol)){
      switch(symbol){
      case '(':
            push(symbol);
            break;
      case ')':
            while((next=pop())!='(')
            {       postfix[p++]=next;}
            break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
            while((top!=-1)&&instack_priority(stack[top])>=incoming_priority(symbol))
            {postfix[p++]=pop();}
            push(symbol);
            break;
      default:
            postfix[p++]=symbol;
            break;
      }
    for(j=0; j<=top; j++) {
      printf("%c", (int)stack[j]);
      }
      printf("\t\t%s", postfix);
   }
   printf("\n");
  }
  while(top!=-1)
  {postfix[p++]=pop();}
  postfix[p]='\0';
}

long int power(long int b,long int a)
{
  int i;
  long int ans=1;
  for(i=1; i<=a; i++)
  {  ans=ans*b; }
  return ans;
}

float eval_post()
{
  long int a, b, temp, result;
  int i;
  for(i=0; i<strlen(postfix); i++){
    if(postfix[i]<='9'&& postfix[i]>='0')
              push(postfix[i]-'0');
   else
   {
     a=pop();
     b=pop();
     switch(postfix[i]){
        	case '+':
        	        temp=b+a;
                        break;
     		case '-':
                        temp=b-a;
                        break;
     		case '*':
			temp=b*a;
                        break;
     		case '/':
			temp=b/a;
                        break;
     		case '%':
           		temp=(int)b%(int)a;
                        break;
     		case '^':
           		temp=power(b,a);
			break;
      }push(temp);
    }
  }
  result=pop();
  return result;
}

int main()
{
   float ans;
   printf("Enter the infix expression\n");
   scanf("%s", infix);
   infix_to_postfix();
   printf("Postfix expression is: %s\n", postfix);
   ans=eval_post();
   printf("The answer is: %0.2f\n", ans);
   return 0;
}     

/*

output:
Enter the infix expression
(2^1^(2/2)^(2+1+3)/1^2) 
Symbol          Stack           Postfix
(               (
2               (               2
^               (^              2
1               (^              21
^               (^^             21
(               (^^(            21
2               (^^(            212
/               (^^(/           212
2               (^^(/           2122
)               (^^             2122/
^               (^^^            2122/
(               (^^^(           2122/
2               (^^^(           2122/2
+               (^^^(+          2122/2
1               (^^^(+          2122/21
+               (^^^(+          2122/21+
3               (^^^(+          2122/21+3
)               (^^^            2122/21+3+
/               (/              2122/21+3+^^^
1               (/              2122/21+3+^^^1
^               (/^             2122/21+3+^^^1
2               (/^             2122/21+3+^^^12
)                               2122/21+3+^^^12^/

Postfix expression is: 2122/21+3+^^^12^/

The answer is: 2.00

*/
