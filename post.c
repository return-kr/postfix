#include "stdio.h"
#include "math.h"
#define MAX 200
int top=-1;

int main(){
	int stk[MAX];
	int choice, temp;
	char ch;

	while(1){
		printf("For operands press 1, for operator press 2, Press 0 when finished\n");
		scanf(" %d", &choice);
		if(choice == 1){
			printf("Enter the numbers, Press -999 when finished\n");
			while(1){
				scanf(" %d", &temp);
				if(temp == -999)
					break;
				else{
					++top;
					if(top>=MAX){
						printf("Stack Overflow\n");
						return 0;
					}
					else
						stk[top]=temp;
				}
			}
		}
		else if(choice == 2){
			printf("Enter the operators, Press \'x\' or \'X\' when finished\n");
			while(1){
				scanf(" %c", &ch);
				if(ch=='x' || ch=='X')
					break;
				else if(ch=='+'){
					stk[top-1]+=stk[top];
					--top;
				}
				else if(ch=='-'){
					stk[top-1]-=stk[top];
					--top;
				}
				else if(ch=='*'){
					stk[top-1]*=stk[top];
					--top;
				}
				else if(ch=='/'){
					stk[top-1]/=stk[top];
					--top;
				}
				else if(ch=='^'){
					stk[top-1]=pow(stk[top-1],stk[top]);
					--top;
				}
				else{
					printf("Wrong input         \n");
					return 0;
				}
			}
		}
		else if(choice == 0)
			break;
		else
			printf("Wrong input\nPlease try again\n");
	}

	printf("The result of the infix expression is = %d\n", stk[top]);

	return 0;
}

                                                                   // A 13 C
