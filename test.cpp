#include <cstdio>
#include <cstdlib>

struct Node{
    char data;
    Node *prev, *next;
};

Node *head = NULL;
Node *tail = NULL;
int len = 0;
bool rev = false;

Node *craete_node(char c){
    Node *new_node = new Node;
    new_node->data = c;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

Node *get_node(int pos){
    if(pos == len - 1) return rev ? head : tail;
    Node *cur = rev ? tail: head;
    while (pos--)
    {
        cur = rev ? cur->prev : cur->next;

    }
    return cur;
    
}

void insert_pos(int pos, char c){
    Node *node = craete_node(c);

    Node *left = (pos == 0) ? NULL: get_node(pos-1);
    Node *right = (pos == len) ? NULL: get_node(pos);

    if(rev){
        node->prev = right;
        node->next = left;

        if(left) left->prev = node;
        else tail = node;
    

        if(right) right->next = node;
        else head = node;

    }
    else{
        node->prev = left;
        node->next = right;

        if(left) left->next = node;
        else head = node;

        if(right) right->prev = node;
        else tail = node;
    }
    len++;
}

void delete_pos(int pos){
    Node *cur = get_node(pos);

    if(cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if(cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;

    delete cur;
    len--;

}

void print_node(){
    for(Node *cur = rev ? tail : head; cur != NULL; cur = rev ? cur->prev : cur->next){
        printf("%c", cur->data);
    }
    printf("\n");
}

void free_node(){
    while (head)
    {
       Node *nxt = head->next;
       delete head;
       head = nxt;
    }

    tail = NULL;
    len = 0;
    
}


int main(){

    int M; scanf("%d", &M);
    for(int i = 0; i < M; i++){
        char op[30]; scanf("%s", op);
        if(op[0] == 'i'){
            int pos;
            char c;

            if(op[6] == '\0') scanf(" %c %d", &c, &pos);
            else if(op[7] == 'f') {scanf(" %c", &c); pos = 0;} // insert front
            else if(op[7] == 'b') {scanf(" %c", &c); pos = len;} //insert back
            insert_pos(pos, c);

        }
        else if(op[0] == 'd'){
            int pos;
            if(op[6] == '\0'){ scanf("%d", &pos); delete_pos(pos); }
            else if(len > 0){
                if(op[7] == 'f') pos = 0;
                else if(op[7] == 'b') pos = len - 1;
                delete_pos(pos);
            }

        }
        else if (op[0] == 'r'){
            rev = !rev;
        }
        else if(op[0] == 'p'){
            print_node();
        }
        
    }
    free_node();
    return 0;
}