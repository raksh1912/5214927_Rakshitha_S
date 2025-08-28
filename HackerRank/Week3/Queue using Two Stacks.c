#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
int s1[MAX],s2[MAX];
int top1 = -1,top2 = -1;

void push1(int x){
    s1[++top1] = x;
}
int pop1(){
    return s1[top1--];
}
void push2(int x){
    s2[++top2] = x;
}

int pop2(){
    return s2[top2--];
}
int isEmpty1(){
    return top1 == -1;
    
}
int isEmpty2() {
    return top2 == -1;
}

void enqueue(int x){
    push1(x);
}
void dequeue(){
    if(isEmpty2()){
        while(!isEmpty1()){
            push2(pop1());
        }
    }
    if(!isEmpty2())
    pop2();
}
int peek(){
    if(isEmpty2()){
        while(!isEmpty1()){
            push2(pop1());
        }
    }
    return (!isEmpty2()) ? s2[top2] : -1;
}

int main() {
    int q;
    scanf("%d",&q);
    
    for(int i=0;i<q;i++){
        int type;
        scanf("%d",&type);
        
        if(type == 1){
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        
        else if(type == 2){
            dequeue();
        }
        else if(type == 3){
            printf("%d\n",peek());
        }
    }
    return 0;
}
