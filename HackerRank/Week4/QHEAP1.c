#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int heapSize =0;

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
    
}
void insert(int val){
    heap[++heapSize] = val;
    int i=heapSize;
    while(i>1 && heap[i] < heap[i/2]){
        swap(&heap[i],&heap[i/2]);
        i/=2;
    }
}

void heapify(int i){
    int smallest = i;
    int left = 2*i ,right = 2*i+1;
    
    if(left <= heapSize && heap[left] < heap[smallest])
    smallest = left;
    if(right <= heapSize && heap[right] < heap[smallest])
    smallest = right;
    
    if(smallest != i){
        swap(&heap[i],&heap[smallest]);
        heapify(smallest);
    }
}

void removeElement(int val){
    int i;
    for(i=1;i<= heapSize;i++){
        if(heap[i] == val){
            heap[i] = heap[heapSize--];
            heapify(i);
            break;
        }
    }
}
int peek(){
    if(heapSize == 0) return -1;
    return heap[1];
    
}
int main() {
    int q;
    scanf("%d",&q);
    
    while(q--){
        int type;
        scanf("%d",&type);
        
        if(type ==1){
            int num;
            scanf("%d",&num);
            insert(num);
        }
        else if(type == 2){
            int num;
            scanf("%d",&num);
            removeElement(num);
        }
        else if(type == 3){
            printf("%d\n",peek());
        }}
        return 0;
        
        }
    
    


