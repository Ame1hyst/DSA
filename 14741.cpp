#include <cstdio>

struct Node
{
    int data;
    Node *next;
};

Node *create_node(int num){
    Node *new_node = new Node;
    new_node->data = num;
    new_node->next = NULL;
    return new_node;
}



int main(){
    int M; scanf("%d ", &M);
    Node *head = NULL, *tail = NULL;
    for(int i = 0; i < M; i++){
        char op[101]; scanf("%s", op);

        if(op[0] == 'n'){
            if(op[4] == 'n'){
                int N; scanf("%d", &N);
                Node *node = create_node(N);
                if(!head) {head = tail = node;}
                else {tail->next = node; tail = node;}
            }
            else if(op[4] == 's'){
                int N, P; scanf("%d %d", &N, &P);
                Node *node = create_node(N);
                if(P == 0){
                    node->next = head;
                    head = node;
                    if(!tail) tail = node;
                }
                else{
                    Node *cur = head;
                    while(--P) cur = cur->next;
                    node->next = cur->next;
                    cur->next = node;
                    
                }
            }
        }
        else if(op[0] == 'p'){
            for(Node *cur = head; cur != NULL; cur = cur->next){
                printf("%d", cur->data);
                if(cur->next) printf(" ");
            }
            printf("\n");
        }
        else if(op[0] == 'd'){
            Node *temp = head;
            head = head->next;
            if(!head) tail = NULL;
            delete temp;
        }
    }

    return 0;
}