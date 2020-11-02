#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int data;//数据域
    struct Node * pNext;//指针域
}NODE, *PNODE;//NODE == struct Node, *PNODE == struct Node *

PNODE create_list();//创建单链表并且返回该链表的头指针
PNODE create_list_head();//头插法
void traverse_list(PNODE pHead);//遍历单链表
int is_empty(PNODE pHead);//判断表是否为空
int insert_list(PNODE pHead, int pos, int val);//在pHead所指向的链表的第pos个节点的前面插入一个新节点，值为val
int delete_list(PNODE pHead, int pos, int *pVal);//删除链表的第pos个节点，并将删除的节点的值存到pVal所指得变量中，pos从1开始
int length_list(PNODE pHead);//单链表的长度
void sort_list(PNODE pHead, int len);//单链表排序

int main() {
    int val;//保存被删节点的数据值
    int len;
    PNODE pHead= NULL; // == struct Node * pHead=NULL。定义头指针
    // 创建单链表 尾插法
    // pHead = create_list();
    // 头插法创建链表
    pHead = create_list_head();
    //遍历单链表
    traverse_list(pHead);
    //插入元素
//    insert_list(pHead, 3, 100);
//    traverse_list(pHead);
    len = length_list(pHead);
    printf("链表的长度为：%d",len);
//    printf("删除第四个元素");
//    delete_list(pHead, 4, &val);
//    printf("\n被删元素的值：%d\n",val);
//    len = length_list(pHead);
//    printf("链表的长度为：%d",len);
    sort_list(pHead,len);
    printf("\n");
    printf("排序后:");
    traverse_list(pHead);
}

PNODE create_list(){//尾插法
    int len;//用来存放有效节点的个数
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//向系统申请空间，表示头节点
    PNODE pTail = pHead;//尾指针，开始指向头节点
    pTail->pNext=NULL;
    if(pHead == NULL){
        printf("空间分配失败，程序终止！\n");
        exit(-1);
    }
    printf("请输入要生成的链表节点个数：len=");
    scanf("%d",&len);//获取用户输入的len的值
    for(int i=0; i<len; i++){
        printf("请输入第%d个节点的值：",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));//申请给新节点分配空间
        if (pNew == NULL) {
            printf("空间分配失败，程序终止！\n");
            exit(-1);
        }
        pNew->data=val;
        pTail->pNext=pNew;//新节点挂到pTail的next域
        pNew->pNext=NULL;
        pTail=pNew;//使得pTail始终指向尾节点
    }
    return pHead;
}

PNODE create_list_head(){//头插法
    int len;//用来存放有效节点的个数
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//向系统申请空间，表示头节点
    if(pHead == NULL){
        printf("空间分配失败，程序终止！\n");
        exit(-1);
    }
    pHead->pNext=NULL;
    printf("请输入要生成的链表节点个数：len=");
    scanf("%d",&len);//获取用户输入的len的值
    for(int i=len; i>0; i--){
        printf("请输入第%d个节点的值：",i);
        scanf("%d",&val);
        PNODE p = (PNODE)malloc(sizeof(NODE));//申请给新节点分配空间
        if (p == NULL) {
            printf("空间分配失败，程序终止！\n");
            exit(-1);
        }
        p->data=val;
        p->pNext=pHead->pNext;
        pHead->pNext=p;
    }
    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p=pHead->pNext;//p指向首节点（就是头节点的后面一个节点）
    while (p!=NULL){
        printf("%d   ",p->data);
        p=p->pNext;//顺链操作
    }
    printf("\n");
    return;
}
int is_empty(PNODE pHead){
    if(pHead->pNext==NULL){
        return 1;//1表示为空表
    } else{
        return 0;//0表示不是空表
    }
}
int insert_list(PNODE pHead, int pos, int val){
    int i=0;
    PNODE p = pHead;
    while (p!=NULL && i<pos-1){//循环结束时，p指向的是第pos-1个节点
        p=p->pNext;
        i++;
    }
    if (i>pos-1 || p==NULL){
        return 0;//表示插入失败
    }
    PNODE pNew =(PNODE)malloc(sizeof(NODE));//表示要插入的节点
    if (pNew==NULL){
        printf("空间分配失败，程序终止！\n");
        exit(-1);
    }
    pNew->data=val;
    pNew->pNext=p->pNext;
    p->pNext = pNew;
    printf("恭喜，插入成功!!!");
    return 1;//1表示插入成功
}
int delete_list(PNODE pHead, int pos, int *pval){
    int i=0;
    PNODE p = pHead;
    PNODE q;//记录被删节点
    while(p!=NULL && i<pos-1){
        p=p->pNext;
        i++;
    }
    if (i>pos-1 || p->pNext==NULL){
        return 0;
    }
    q=p->pNext;
    *pval=q->data;//保存被删节的数据域的值
    p->pNext=p->pNext->pNext;
    free(q);
    return 1;//表示删除成功
}
int length_list(PNODE pHead){
    int len=0;
    PNODE p = pHead->pNext;
    while (p!=NULL){
        len++;
        p=p->pNext;
    }
    return len;
}
void sort_list(PNODE pHead, int len){
    PNODE p;
    int tmp;
    PNODE q;
    for(int i=0; i<len-1; i++){
        p = pHead->pNext;
        q = p->pNext;
        for(int j=0; j<len-1-i; j++){
            if(p->data > q->data){
                tmp = q->data;
                q->data = p->data;
                p->data = tmp;
            }
            p=p->pNext;
            q=q->pNext;
        }
    }
    return;
}