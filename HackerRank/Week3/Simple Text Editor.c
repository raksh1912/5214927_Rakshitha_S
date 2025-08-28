#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int type;
    int k;
    char *str;
} Op;

static char *s = NULL;
static size_t slen = 0;
static size_t scap = 0;

static void ensure_cap(size_t need){
    if(need <= scap) return;
    size_t newcap = scap ? scap : 16;
    while(newcap < need) newcap <<= 1;
    char *ns = (char*)realloc(s,newcap);
    if(!ns) exit(1);
    s=ns;
    scap = newcap;
}
static void append_bytes(const char *w,size_t k){
    ensure_cap(slen + k + 1);
    memcpy(s + slen,w,k);
    slen += k;
    s[slen] = '\0';
}

static void delete_k(size_t k){
    if(k > slen) k = slen;
    slen -= k;
    s[slen] = '\0';
    
}

static void push_op(Op **stack,size_t *optop,size_t *opcap,Op rec){
  if(*optop == *opcap){
    *opcap <<= 1;
    Op *ns = (Op*)realloc(*stack, (*opcap) * sizeof(Op));
    if(!ns) exit(1);
    *stack = ns;
  }
  (*stack)[(*optop)++] = rec;   
}

int main(){
    int n;
    if(scanf("%d",&n)!= 1) return 0;
    ensure_cap(16);
    s[0] = '\0';
    slen = 0;
    
    size_t opcap = 1u << 16;
    size_t optop = 0;
    Op *stack = (Op*)malloc(opcap * sizeof(Op));
    if(!stack) exit(1);

    
    for(int i=0;i<n;i++){
        int type;
        if(scanf("%d",&type) != 1) type = 0;
        
        if(type == 1){
            char buf[100005];
            if(scanf("%100000s", buf) != 1) buf[0] = '\0';
            size_t k = strlen(buf);
            append_bytes(buf,k);
            Op rec = (Op){ .type =1, .k =(int)k, .str = NULL };
            push_op(&stack,&optop,&opcap,rec); 
        }
        else if(type ==2){
            int k;
            scanf("%d",&k);
            if(k <0) k=0;
            if((size_t)k > slen) k = (int)slen;
            
            char *dup = (char*)malloc((size_t)k +1);
            if(!dup) exit(1);
            memcpy(dup, s+slen-k,(size_t)k);
            dup[k] ='\0';
            delete_k((size_t)k);
            Op rec = (Op){ .type = 2, .k =k, .str =dup };
         push_op(&stack,&optop,&opcap,rec); 
        }
        
      else if(type == 3){
        int k;
        scanf("%d",&k);
        if(k>=1 && (size_t)k <= slen){
            putchar(s[k-1]);
            putchar('\n');
        }
        else {
            putchar('\n');
        }
      }  
      else if(type == 4 ){
        if(optop > 0){
            Op rec = stack[--optop];
            if(rec.type ==1){
                delete_k((size_t)rec.k);
            }
            else if(rec.type == 2){
                size_t k = strlen(rec.str);
                append_bytes(rec.str,k);
                free(rec.str);
            }
        }
      }}     
         for(size_t i = 0;i<optop;i++){
            if(stack[i].type == 2 && stack[i].str) free(stack[i].str);
         }  
         free(stack);
         free(s);
         return 0;         
                    }
    











