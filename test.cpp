#include <cstdio>
#include <cstdlib>

struct  Node
{
    char data;
    Node *next, *prev;
};

Node *create_node(char c){
    Node *new_node = new Node;
    new_node->data = c;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

Node *head = NULL, *tail = NULL;
int len = 0;
bool rev = false;

Node *get_node(int pos){
    if(pos == len - 1) return rev ? head : tail;
    Node *cur = rev ? tail: head;
    while (pos--)
    {
        cur = rev ? cur->prev: cur->next;
    }
    return cur;
}

void free_node(){
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    len = 0;
    
}

void insert_node(int pos, char c){
    Node *left = (pos == 0) ? NULL: get_node(pos - 1);
    Node *right = (pos == len) ? NULL: get_node(pos);

    Node *node = create_node(c);

    if(!rev){
        node->prev = left;
        node->next = right;

        if(left) left->next = node;
        else head = node;

        if(right) right->prev = node;
        else tail = node;
    }
    else{
        node->prev = right;
        node->next = left;

        if(right) right->next = node;
        else head = node;
        
        if(left) left->prev= node;
        else tail = node;
    }
    len++;
}

void delete_node(int pos){
    Node *cur = get_node(pos);

    if(cur->prev) cur->prev->next = cur->next;
    else head = cur->next;

    if(cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;

    delete cur;
    len--;
}

void print_node(){
    for(Node *cur = rev ? tail: head; cur != NULL; cur = rev ? cur->prev: cur->next){
        printf("%c", cur->data);
    }
    printf("\n");
}

int main(void){
    int M; scanf("%d", &M);
    for(int i = 0; i < M; i++){
        char op[31]; scanf("%s", op);

        if(op[0] == 'i'){
            int pos;
            char c;
            if(op[6] == '\0') scanf(" %c %d", &c, &pos);
            else if(op[7] == 'f') {scanf(" %c", &c); pos = 0;}
            else if(op[7] == 'b') {scanf(" %c", &c); pos = len;}
            insert_node(pos, c);
        }
        else if(op[0] == 'd'){
            int pos;
            if(op[6] == '\0') {scanf("%d", &pos); delete_node(pos);}
            else if(len > 0){
                if(op[7] == 'f') pos = 0;
                else pos = len - 1;
                delete_node(pos);
            }
            
        }
        else if(op[0] == 'r') rev = !rev;
        else if(op[0] == 'p') print_node();
    }
    free_node();

    return 0;
}