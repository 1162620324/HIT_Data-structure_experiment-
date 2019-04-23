#include <stdio.h>
#include <stdlib.h>
#define M 100
struct node {
    struct node* lchild;
    int ltag;
    char data;
    struct node* rchild;
    int rtag;
};
typedef struct node tree;
typedef struct node * BTREE;//����ڵ�

struct STACK{
    BTREE pot;
    struct STACK * next;
};
typedef struct STACK ST;
typedef struct STACK * pointS;//����ջ
void Push(BTREE T, pointS S);
BTREE Top(pointS S);
void Pop(pointS S);
int isEmpty(pointS S);//ջ����

struct STACK1{
    BTREE pot;
    int flag;
    struct STACK1 * next;
};
typedef struct STACK1 ST1;
typedef struct STACK1 * pointS1;//����ջ
void Push1(BTREE T, pointS1 S);
BTREE Top1(pointS1 S);
void Pop1(pointS1 S);
int isEmpty1(pointS1 S);//ջ����

struct celltype{
    BTREE element;
    struct celltype * next;
};
typedef struct celltype celltype;
typedef struct celltype *pcell;

struct QUEUE {
    pcell pfront;
    pcell prear;//��β
};
typedef struct QUEUE DL;
typedef struct QUEUE *dui;//������У�
void MakeNull(dui Q);
int Empty(dui Q);
void EnQueue( BTREE p, dui Q);
void DeQueue(  dui Q);
BTREE outQueue( dui Q);


void CreatBT1( BTREE *T, FILE * fp );
BTREE CreatBT2( );//������������
void PreOrderd(BTREE T);//��������ݹ�
void PreOrderfd(BTREE T);//��������ǵݹ飻
void InOrderd( BTREE T);//��������ݹ飻
void InOrderfd( BTREE T);//��������ǵݹ飻
void PostOrderd( BTREE T);//��������ݹ飻
void PostOrderfd( BTREE); //��������ǵݹ�
void LeverOrder(BTREE T);//�������������
void in_Threading( BTREE p );//��PΪ���ڵ��������������
BTREE inorder_Threading( BTREE T);//��ͷ�����������������������������ͷ���ָ�룻

BTREE PreNext( BTREE p);//��p��������������������ĺ�̽��
BTREE InNext(BTREE p);//��p�������̽��
BTREE PostNext(BTREE p);//��p�����������ĺ�������ĺ�̽��
void inOrderth_Traverse( BTREE T);//�������������������
void inOrderTh_Traverse( BTREE T);//�������������������
void preOrderTh_Traverse( BTREE T);//�������������������
void postOrderTh_Traverse( BTREE T);//�������������������
BTREE Creatnode( char ch, BTREE l, BTREE r);
BTREE changeto();

void pisNULL( BTREE p);


BTREE pre;//ȫ�ֱ���ָ��ǰ����
//FILE * fp ;

int main()
{
    BTREE T1, T2, T3;
    FILE *fp = fopen("D:\\in1.txt","r");
    //CreatBT1(&T2, fp);//��һ�ַ���

    T2 = CreatBT2();//�ڶ��ַ���
    printf("��������Ϊ����ʾΪ�������� #��ʾ�սڵ㣩��  ");
    T3 = changeto();
    LeverOrder(T3);

    printf("\n\n\n");

    printf("��������ݹ飺");
    PreOrderd(T2);
    printf("\n");
    printf("��������ݹ飺");
    InOrderd(T2);
    printf("\n");
    printf("��������ݹ飺");
    PostOrderd(T2);
    printf("\n");
    printf("���������");
    LeverOrder(T2);
    printf("\n\n\n");

    printf("��������ǵݹ飺");
    PreOrderfd(T2);
    printf("\n");
    printf("��������ǵݹ飺");
    InOrderfd(T2);
    printf("\n");
    printf("��������ǵݹ飺");
    PostOrderfd(T2);
    printf("\n\n\n");

    T1 = inorder_Threading(T2);//����������


    printf("���������������");
    preOrderTh_Traverse(T1);
    printf("\n");
    printf("���������������");

    inOrderTh_Traverse(T1);
    printf("\n");
    printf("���������������");
    postOrderTh_Traverse(T1);
    printf("\n");

    return 0;
}

BTREE Creatnode(char ch, BTREE l, BTREE r){//�����ڵ�������ch,
    BTREE p = (BTREE) malloc(sizeof(tree));
    p ->data = ch;
    p ->lchild = l;
    p ->rchild = r;
    return p;
}

void pisNULL(BTREE p){//�ж�ָ���Ƿ�Ϊ��
    if( p == NULL){
        printf("point is NULL");
        exit(0);
    }
}

void CreatBT1( BTREE *T, FILE *fp){//��һ�ֽ���
    char ch;
    fscanf(fp, "%c", &ch);
    if( ch == '#' ){//�����������Ϊ#��������ָ��ָ��Ϊ��
        (*T) = NULL;
    }
    else{//����ָ�����ch�Ľڵ�
        (*T) = (BTREE) malloc(sizeof(tree));//�������ch�Ľڵ�
        (*T) ->data = ch;
        CreatBT1(&((*T) ->lchild), fp);//�ݹ齨��������
        CreatBT1(&((*T) ->rchild), fp);//�ݹ齨��������
    }
}

BTREE CreatBT2(){//�ڶ��ֽ���
    int i=1, j=0;
    char ch;
    BTREE bt, p, s[M];//btΪ����p���ڽ����ڵ�
    FILE *fp = fopen("D:\\in.txt", "r");
    while(fscanf(fp, "%c", &ch) != EOF && i != 0){
        p = Creatnode(ch, NULL, NULL);
        s[i] = p;
        if( i == 1){
            bt = p;//Ϊ���ڵ㣻
        }
        else{
            if(p ->data == '#'){//�������Ϊ#���������Ӧ�ڵ��ָ����Ϊ��
                j = i/2;

                if(i%2 == 0 )
                    s[j] ->lchild = NULL;
                else
                    s[j] ->rchild = NULL;
            }else{

                j = i/2;//���ڵ�ı��

                if(i%2 == 0 )
                    s[j] ->lchild = p;//i��j�������
                else
                    s[j] ->rchild = p;//i��j���Ҷ���
            }
        }
        i++;
    }
    return bt;
}

BTREE changeto(){//�ڶ��ֽ���
    int i=1, j=0;
    char ch;
    BTREE bt, p, s[M];//btΪ����p���ڽ����ڵ�
    FILE *fp = fopen("D:\\in.txt", "r");
    while(fscanf(fp, "%c", &ch) != EOF && i != 0){
        p = Creatnode(ch, NULL, NULL);
        s[i] = p;
        if( i == 1){
            bt = p;//Ϊ���ڵ㣻
        }
        else{
            if(p ->data == '#'){//�������Ϊ#���������Ӧ�ڵ��ָ����Ϊ��
                j = i/2;

                if(i%2 == 0 )
                    s[j] ->lchild = p;
                else
                    s[j] ->rchild = p;
            }else{

                j = i/2;//���ڵ�ı��

                if(i%2 == 0 )
                    s[j] ->lchild = p;//i��j�������
                else
                    s[j] ->rchild = p;//i��j���Ҷ���
            }
        }
        i++;
    }
    return bt;
}

void PreOrderd(BTREE T){//����ݹ����
    if(T != NULL)
    {
        printf("%c", T -> data);//�ȷ��ʵ�ǰ�ڵ����ݣ���Ӧ�������
        PreOrderd(T -> lchild);//�ݹ����������
        PreOrderd(T -> rchild);//�ݹ����������
    }
}

void PreOrderfd(BTREE T){//����ǵݹ����
    pointS st1 = (pointS)malloc(sizeof(ST));
    st1 -> next = NULL;
    int u = 0;
    while( T != NULL || !isEmpty(st1))//ѭ��ֱ��ָ��Ϊ����ջΪ��
    {
        while( T != NULL )//��ָ�벻Ϊ����ѭ��
        {
            printf("%c", T ->data);//��ӡ������
            u++;
            Push( T, st1);//��ָ��ֵ������ջ��
            T = T ->lchild;//�������������
        }
        if( st1 -> next != NULL){//��ջ�ǿ�
            T = Top(st1);//ȡ��ջ��Ԫ�ظ�T
            Pop(st1);//ɾ��ջ��Ԫ��
            u++;//ͳ��ջ����
            T = T ->rchild;//���������Ҷ���
        }
    }
    printf("    steps:%d", u);
}

void InOrderd(BTREE T){//����ݹ����
    if(T != NULL)
    {
        InOrderd( T ->lchild);//�ݹ���ʵ�ǰ�ڵ�������
        printf("%c", T ->data);//����������������ʵ�ǰ�ڵ����ݣ���Ӧ�������
        InOrderd( T ->rchild);//�ݹ���ʵ�ǰ�ڵ�������
    }
}

void InOrderfd(BTREE T){
    pointS st1 = (pointS) malloc(sizeof(ST));
    st1 ->next = NULL;
    int u = 0;
    while( T != NULL || !isEmpty(st1)){//ѭ��ֱ��ָ��Ϊ����ջΪ��
        u++;
        while( T != NULL){//��ָ�벻Ϊ����ѭ��
            Push( T, st1);//��ָ��ֵ������ջ��
            T = T ->lchild;//�������������
            u++;
        }
        if(!isEmpty(st1)){//��ջ�ǿ�
            T = Top(st1);//ȡ��ջ��Ԫ�ظ�T
            Pop(st1);//ɾ��ջ��Ԫ��
            printf("%c", T ->data);//��ӡ������
            T = T ->rchild;//���������Ҷ���
        }
    }
    printf("    steps:%d", u);
}

void PostOrderd(BTREE T){//����ݹ����
    if( T != NULL){
        PostOrderd(T ->lchild);
        PostOrderd(T ->rchild);
        printf("%c", T ->data);//������������������ʵ�ǰ�ڵ����ݣ���Ӧ�������
    }
}

void PostOrderfd(BTREE T){
    pointS1 st2 = (pointS1)malloc(sizeof(ST1));
    st2 ->next = NULL;
    BTREE T1 = T;
    int u = 0;
    while( T != NULL || !isEmpty1(st2)){//ѭ��ֱ��ָ��Ϊ����ջΪ��
        u++;
        while( T != NULL){//��ָ��ǿ�ʱѭ��
            Push1( T , st2);//����ǰ�ڵ�ָ����ջ
            st2 ->next ->flag = 1;//��ջ��Ԫ�ر�־λ��Ϊ1
            T = T ->lchild;//����������ǰ�ڵ�������
            u++;
        }
        while( !isEmpty1(st2) && st2 ->next ->flag == 2){//��ջ�ǿ���ջ��Ԫ�ر�־λΪ2ʱ����ջ�����ջ���ڵ�����
            T = Top1(st2);
            if(T == T1){//���ջ���ڵ�ʱ���ڵ㣬�����������
                printf("%c", T ->data);
                printf("    steps:%d", u);
                return;
            }
            Pop1(st2);
            u++;
            printf("%c", T ->data);
        }
        if(!isEmpty1(st2)){//��ջ�ǿգ���ջ��Ԫ�ر�־��Ϊ2������ջ���ڵ��������
            st2 ->next ->flag = 2;
            T = Top1(st2) ->rchild;
        }
    }

}

void LeverOrder(BTREE T){//�������
    dui Q = (dui)malloc(sizeof(DL));
    Q->pfront = (pcell)malloc(sizeof(celltype));
    Q->pfront ->next = NULL;
    Q->prear = Q->pfront;
    BTREE q;

    if(T == NULL)//����������ǿգ�����ָ�����
        return;
    EnQueue( T, Q );
    while(!Empty(Q))//ѭ��ֱ������Ϊ��
    {
        q = outQueue(Q);//����Ԫ�س���
        DeQueue(Q);//ɾ������Ԫ��
        printf("%c", q ->data);//���ʽڵ�������
        if(q ->lchild != NULL)//���ڵ�������ӣ�����������
        {
            EnQueue(q ->lchild, Q);
        }
        if(q ->rchild != NULL)//���ڵ����Ҷ��ӣ����Ҷ������
        {
            EnQueue(q ->rchild, Q);
        }

    }


}


BTREE inorder_Threading(BTREE T){//������������������
    BTREE head, p;
    head = (BTREE) malloc(sizeof(tree));//����ͷ���
    head ->ltag = 1;
    head ->rtag = 1;
    head ->rchild = head;//��ͷ�����г�ʼ��
    if( T == NULL)
    {
        head ->lchild = head;//�����գ���ͷ�����ָ��ָ������
    }
    else
    {
        head ->lchild = T;//�����ǿգ���ͷ�����ָ��ָ����ڵ�
        pre = head;//��ʼ��ǰ���ڵ�Ϊͷָ��
        in_Threading(T);//�������������������Ը��ڵ�������
        head ->rchild = pre;
        pre ->rtag = 0;
        pre ->rchild = head;
    }
    head ->ltag = 1;
    head ->rtag = 1;
    head ->rchild = head;
    return head;
}

void in_Threading( BTREE p ){
    if(p)
    {
        in_Threading(p ->lchild);//�ݹ��������������
        if(!p ->lchild)//���û������ӣ������־λΪ0��ָ��ǰ��
        {
            p ->ltag = 0;
            p ->lchild = pre;
        }
        else//�������־λΪ1
        {
            p ->ltag = 1;
        }
        if(!pre ->rchild)//���ǰ��û���Ҷ��ӣ���ǰ���ұ�־λΪ0��ָ��ǰ�ڵ�
        {
            pre ->rtag = 0;
            pre ->rchild = p;
        }
        else//����ǰ���ұ�־λΪ1
        {
            pre ->rtag = 1;
        }
        pre = p;//����ǰ��
        in_Threading(p ->rchild);//�ݹ��������������
    }
}

/*void inOrderth_Traverse( BTREE T){//
    BTREE p;
    p = T ->lchild;
    while( p!= T)
    {
        while( p ->ltag == 1)
        {
            p = p ->lchild;
        }
        printf("%c", p ->data);
        while( p ->rtag == 0 &&  p ->rchild != T)
        {
            p = p ->rchild;
            printf("%c", p ->data);
        }
        p = p ->rchild;
    }
    printf("\n");
}*/

BTREE InNext(BTREE p){//����������������������ĺ�̽ڵ�
    BTREE q;
    q = p ->rchild;
    if( p ->rtag == 1)//�����Ҷ��ӣ��������ڵ㼴Ϊ����
    {
        while(q ->ltag == 1)//����ڵ�ʱ������������ڵ�
        {
            q = q ->lchild;
        }
    }
    return q;
}

BTREE PreNext(BTREE p){//����������������������ĺ�̽ڵ�
    BTREE q;
    q = p;
    if( p  ->ltag != 0)//������ӣ�����Ӽ�Ϊ����
    {
        return p ->lchild;
    }else
    {
        while(q ->rtag == 0)//���Ҷ��ӣ��Ҷ��Ӽ�Ϊ���󣬷�����ǵ�һ�������Ҷ��������ڵ���Ҷ���
            q = q ->rchild;
        return q ->rchild;
    }
}

BTREE PostNext(BTREE p){//�������������ĺ�������ĺ�̽ڵ�
    BTREE q = p, t, r, r1, s;
    while( q ->rtag == 1)//��ѭ���ҵ���ǰ�ڵ������������ҽڵ�
    {
        q = q ->rchild;
    }
    t = q ->rchild;//Ϊ���ҽڵ�������ڵ�
    r = t ->lchild;//Ϊ�����ڵ�������
    if( r != p)//��������ڵ������Ӳ�����p
    {
        while(r != p)
        {
            r1 = r;//����ڵ����p�ĸ��ڵ�
            r = r ->rchild;
        }
        return r1;
    }
    else
    {
        if( t ->rtag == 0)//��������ڵ�û���Ҷ���
            return t;//��ô�����ڵ��������
        else
        {
            s = t ->rchild;//s�������ڵ��Ҷ���
            while( s ->ltag == 1 || s ->rtag == 1){//ѭ��ֱ�������ڵ����Ҷ��Ӿ�Ϊ��
                if(s ->ltag == 1){//������Ӳ�Ϊ�գ�����������
                    s = s ->lchild;
                }
                else if(s ->rtag == 1){//��û������ӣ����Ҷ��ӣ�����������
                    s = s ->rchild;
                }
            }

            return s;
        }
    }
}

void inOrderTh_Traverse(BTREE T){//���ú�̽ڵ���������
    BTREE p;
    p = T;
    int u = 0;
    do{
        p = InNext(p);//��ȡ��̽ڵ�
        u++;
        if( p != T )//
            printf("%c", p ->data);//���ʽڵ�������
    }while( p != T);//ѭ��ֱ���ص����ڵ�
    printf("    steps:%d", u);
}

void preOrderTh_Traverse(BTREE T){//���ú�̽ڵ���������
    BTREE p;
    //BTREE p;
    p = T;
    int o1 = 0;
    do{
        p = PreNext(p);//��ȡ��̽ڵ�
        if( p != T )
            printf("%c", p ->data);//���ʽڵ�������
        o1++;//ͳ��ѭ������
    }while( p != T);//ѭ��ֱ���ص����ڵ�
    printf("    steps:%d", o1);
}

void postOrderTh_Traverse( BTREE T){//���ú�̽ڵ�ĺ������
    BTREE p;
    int u = 0;
    p = T ->lchild;
    do{
        p = PostNext(p);//��ȡ��̽ڵ�
        u++;
        if( p != T )
            printf("%c", p ->data);//���ʽڵ�������
    }while( p != T ->lchild);//ѭ��ֱ���ص����ڵ�
        printf("    steps:%d", u);
}

/*void printTree( BTREE T, int nLayer){
    int i =0;
    if( T == NULL){
        return;
    }else
    {
        printTree(T ->rchild, nLayer + 1);
        for(i = 0; i<nLayer; i++ ){
            printf("  a ");
        }
        printf("%c\n",T ->data);
        printTree(T->lchild, nLayer + 1);
    }

}*/

int isEmpty(pointS S){
    if(S ->next == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int isEmpty1(pointS1 S){
    if(S ->next == NULL)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Push(BTREE ch, pointS S){
    pisNULL(S);
    pointS p = (pointS) malloc(sizeof(ST));
    p ->pot = ch;
    p ->next = S ->next;
    S ->next = p;
}

void Push1(BTREE ch, pointS1 S){
    pisNULL(S);
    pointS1 p = (pointS1) malloc(sizeof(ST1));
    p ->pot = ch;
    p ->next = S ->next;
    S ->next = p;
}



BTREE Top(pointS S){
    if( isEmpty(S)){
        printf("the stack is empty");
    }else
    {
        return S ->next ->pot;
    }
}

BTREE Top1(pointS1 S){
    if( isEmpty1(S)){
        printf("the stack is empty");
    }else
    {
        return S ->next ->pot;
    }
}

void Pop(pointS S){
    pointS temp;
    if(isEmpty(S)){
        printf("the stack is empty");
    }else
    {
        temp = S ->next;
        S ->next = S ->next ->next;
        free(temp);
    }
}

void Pop1(pointS1 S){
    pointS1 temp;
    if(isEmpty1(S)){
        printf("the stack is empty");
    }else
    {
        temp = S ->next;
        S ->next = S ->next ->next;
        free(temp);
    }
}




int Empty(dui Q){
    if(Q->pfront == Q->prear)
        return 1;
    else
        return 0;
}

BTREE outQueue(dui Q){
    if(Empty(Q))
        printf("Queue is empty");
    else
    {
        return Q -> pfront ->next ->element;
    }
}

void EnQueue(BTREE p, dui Q){
    pcell a = (pcell)malloc(sizeof(celltype));
    a ->element = p;
    a ->next = NULL;
    Q->prear->next = a;
    Q->prear = Q->prear->next;
}

void DeQueue(dui Q){
    pcell temp;
    if(Empty(Q))
    {
        printf("dui is empty");
        exit(0);
    }else
    {
        temp = Q->pfront ->next;
        Q->pfront ->next = temp ->next;
        free(temp);
        if(Q->pfront ->next == NULL)
        {
            Q->prear = Q->pfront;
        }
    }
}


