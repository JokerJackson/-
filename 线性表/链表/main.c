#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int data;//������
    struct Node * pNext;//ָ����
}NODE, *PNODE;//NODE == struct Node, *PNODE == struct Node *

PNODE create_list();//�����������ҷ��ظ������ͷָ��
PNODE create_list_head();//ͷ�巨
void traverse_list(PNODE pHead);//����������
int is_empty(PNODE pHead);//�жϱ��Ƿ�Ϊ��
int insert_list(PNODE pHead, int pos, int val);//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���½ڵ㣬ֵΪval
int delete_list(PNODE pHead, int pos, int *pVal);//ɾ������ĵ�pos���ڵ㣬����ɾ���Ľڵ��ֵ�浽pVal��ָ�ñ����У�pos��1��ʼ
int length_list(PNODE pHead);//������ĳ���
void sort_list(PNODE pHead, int len);//����������

int main() {
    int val;//���汻ɾ�ڵ������ֵ
    int len;
    PNODE pHead= NULL; // == struct Node * pHead=NULL������ͷָ��
    // ���������� β�巨
    // pHead = create_list();
    // ͷ�巨��������
    pHead = create_list_head();
    //����������
    traverse_list(pHead);
    //����Ԫ��
//    insert_list(pHead, 3, 100);
//    traverse_list(pHead);
    len = length_list(pHead);
    printf("����ĳ���Ϊ��%d",len);
//    printf("ɾ�����ĸ�Ԫ��");
//    delete_list(pHead, 4, &val);
//    printf("\n��ɾԪ�ص�ֵ��%d\n",val);
//    len = length_list(pHead);
//    printf("����ĳ���Ϊ��%d",len);
    sort_list(pHead,len);
    printf("\n");
    printf("�����:");
    traverse_list(pHead);
}

PNODE create_list(){//β�巨
    int len;//���������Ч�ڵ�ĸ���
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//��ϵͳ����ռ䣬��ʾͷ�ڵ�
    PNODE pTail = pHead;//βָ�룬��ʼָ��ͷ�ڵ�
    pTail->pNext=NULL;
    if(pHead == NULL){
        printf("�ռ����ʧ�ܣ�������ֹ��\n");
        exit(-1);
    }
    printf("������Ҫ���ɵ�����ڵ������len=");
    scanf("%d",&len);//��ȡ�û������len��ֵ
    for(int i=0; i<len; i++){
        printf("�������%d���ڵ��ֵ��",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));//������½ڵ����ռ�
        if (pNew == NULL) {
            printf("�ռ����ʧ�ܣ�������ֹ��\n");
            exit(-1);
        }
        pNew->data=val;
        pTail->pNext=pNew;//�½ڵ�ҵ�pTail��next��
        pNew->pNext=NULL;
        pTail=pNew;//ʹ��pTailʼ��ָ��β�ڵ�
    }
    return pHead;
}

PNODE create_list_head(){//ͷ�巨
    int len;//���������Ч�ڵ�ĸ���
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//��ϵͳ����ռ䣬��ʾͷ�ڵ�
    if(pHead == NULL){
        printf("�ռ����ʧ�ܣ�������ֹ��\n");
        exit(-1);
    }
    pHead->pNext=NULL;
    printf("������Ҫ���ɵ�����ڵ������len=");
    scanf("%d",&len);//��ȡ�û������len��ֵ
    for(int i=len; i>0; i--){
        printf("�������%d���ڵ��ֵ��",i);
        scanf("%d",&val);
        PNODE p = (PNODE)malloc(sizeof(NODE));//������½ڵ����ռ�
        if (p == NULL) {
            printf("�ռ����ʧ�ܣ�������ֹ��\n");
            exit(-1);
        }
        p->data=val;
        p->pNext=pHead->pNext;
        pHead->pNext=p;
    }
    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p=pHead->pNext;//pָ���׽ڵ㣨����ͷ�ڵ�ĺ���һ���ڵ㣩
    while (p!=NULL){
        printf("%d   ",p->data);
        p=p->pNext;//˳������
    }
    printf("\n");
    return;
}
int is_empty(PNODE pHead){
    if(pHead->pNext==NULL){
        return 1;//1��ʾΪ�ձ�
    } else{
        return 0;//0��ʾ���ǿձ�
    }
}
int insert_list(PNODE pHead, int pos, int val){
    int i=0;
    PNODE p = pHead;
    while (p!=NULL && i<pos-1){//ѭ������ʱ��pָ����ǵ�pos-1���ڵ�
        p=p->pNext;
        i++;
    }
    if (i>pos-1 || p==NULL){
        return 0;//��ʾ����ʧ��
    }
    PNODE pNew =(PNODE)malloc(sizeof(NODE));//��ʾҪ����Ľڵ�
    if (pNew==NULL){
        printf("�ռ����ʧ�ܣ�������ֹ��\n");
        exit(-1);
    }
    pNew->data=val;
    pNew->pNext=p->pNext;
    p->pNext = pNew;
    printf("��ϲ������ɹ�!!!");
    return 1;//1��ʾ����ɹ�
}
int delete_list(PNODE pHead, int pos, int *pval){
    int i=0;
    PNODE p = pHead;
    PNODE q;//��¼��ɾ�ڵ�
    while(p!=NULL && i<pos-1){
        p=p->pNext;
        i++;
    }
    if (i>pos-1 || p->pNext==NULL){
        return 0;
    }
    q=p->pNext;
    *pval=q->data;//���汻ɾ�ڵ��������ֵ
    p->pNext=p->pNext->pNext;
    free(q);
    return 1;//��ʾɾ���ɹ�
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