#include <cstdio>

const int MAXN = 1000001;

int val[MAXN];   
int next[MAXN];   
int cur_num = 0;    
int head = -1;  
int tail = -1;   

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char com[100];
        scanf("%s", com);

        if(com[4] == 'n'){
            int N;
            scanf("%d", &N);

            val[cur_num] = N;
            next[cur_num] = -1;
            if(head == -1){
                head = tail = cur_num;
            }
            else{
                next[tail] = cur_num;
                tail = cur_num;
            }
            cur_num++;
        }
        else if(com[4] == 's'){
            int N, P;
            scanf("%d %d", &N, &P);

            val[cur_num] = N;
            if(P == 0){
                next[cur_num] = head;
                head = cur_num;
            }
            else{
                int cur = head;
                for(int j = 0; j < P - 1; j++){
                    cur = next[cur];      // walk to position P-1
                }
                next[cur_num] = next[cur];
                next[cur] = cur_num;
                if(tail == cur) tail = cur_num;
            }
            cur_num++;
        }
        else if(com[0] == 'd'){
            head = next[head];
            if(head == -1) tail = -1;
        }
        else if(com[0] == 'p'){
            int cur = head;
            while(cur != -1){
                printf("%d", val[cur]);
                if(next[cur] != -1) printf(" ");
                cur = next[cur];
            }
            printf("\n");
        }
    }

    return 0;
}