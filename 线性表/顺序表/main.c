#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  //����exit

//����ṹ�����ͣ�����˳������飩����������struct Arr
typedef struct Arr{
    int * pBase;//�����������һ��Ԫ�صĵ�ַ
    int len;//��������ĳ���
    int cnt;//��ǰ������ЧԪ�صĸ���
}Array;
void init_arr(Array * pArr, int length);//��ʼ��˳���
int append_arr(Array * pArr, int val);//��˳�����ĩβ׷����Ԫ��
int insert_arr(Array * pArr, int pos, int val);//��˳��������Ԫ��
int delete_arr(Array * pArr, int pos, int * val);//ɾ������Ԫ��
int is_empty(Array * pArr);//�ж��Ƿ�ձ�
int is_full(Array * pArr);//�ж��Ƿ�����
void sort_arr(Array * pArr);//�������Ԫ��
void show_arr(Array * pArr);//��ʾ��ӡ����Ԫ��
void inversion_arr(Array * pArr);//��˳���ת

int main() {
    int val;//��ʾ��¼��ɾԪ�ص�ֵ
    Array arr;//����ṹ�����
    init_arr(&arr, 5);//��ʼ������Ϊ10������
    append_arr(&arr, 3);
    append_arr(&arr, 5);
    append_arr(&arr, 1);
    append_arr(&arr, 7);
    append_arr(&arr, 9);
    show_arr(&arr);
    printf("\n");
    insert_arr(&arr, 6, 11);
    show_arr(&arr);
    printf("\n");
    delete_arr(&arr,3,&val);
    printf("��ɾ����ֵΪ��%d\n", val);
    show_arr(&arr);
    printf("\n");
    inversion_arr(&arr);
    show_arr(&arr);
    printf("\n");
    sort_arr(&arr);
    show_arr(&arr);
    printf("\n");
    inversion_arr(&arr);
    show_arr(&arr);
}

void init_arr(Array * pArr, int length)//��ʼ��˳���
{
    pArr->pBase = (int *)malloc(sizeof(int)*length);
    if(pArr->pBase == NULL)
    {
        printf("��̬�ڴ����ʧ��!\n");
        exit(-1);
    } else{
        pArr->len=length;
        pArr->cnt=0;
    }
    return;
}

int append_arr(Array * pArr, int val){//��˳��������Ԫ��
    pArr->pBase[pArr->cnt]=val;
    (pArr->cnt)++;
    return 1;
}

int is_empty(Array * pArr){ //�ж��Ƿ�ձ�
    if (pArr->cnt==0){
        return 1;//1��ʾ�ձ�
    } else{
        return 0;//��ʾ�ǿձ�
    }
}

int is_full(Array * pArr){
    //�жϱ��Ƿ�����
    if (pArr->cnt == pArr->len){
        printf("�ñ�����");
        return 1;//1��ʾ����
    } else{
        return 0;//0��ʾδ��
    }
}

void show_arr(Array * pArr){
    if (is_empty(pArr))
        printf("�ñ�Ϊ�ձ�\n");
    else{
        for(int i=0;i<pArr->cnt;i++){
            printf("%d ", pArr->pBase[i]);
        }
    }
    return;
}

int insert_arr(Array * pArr, int pos, int val){
    //����Ԫ�أ��ڵ�pos��λ��ǰ����룬pos��ֵ��1��ʼ
    if (is_full(pArr)){
        printf("�ñ����������ܲ��롣\n");
        return 0;
    }
    if(pos<1 || pos>pArr->cnt+1)//����λ�ò��Ϸ�
    {
        printf("����λ�÷Ƿ�������");
        return 0;//0��ʾ����ʧ��
    } else {
        for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }
    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    return 1;//1��ʾ����ɹ�
}

int delete_arr(Array * pArr, int pos, int * val) {
    //ɾ���ڵ�pos��λ�ã�ֵ�����val
    if (is_empty(pArr)){
        printf("�ձ���ɾ����\n");
        return 0;
    }
    if(pos<1 || pos>pArr->cnt+1)//ɾ��λ�ò��Ϸ�
    {
        printf("����λ�÷Ƿ�������");
        return 0;//0��ʾɾ��ʧ��
    }
    *val=pArr->pBase[pos-1]; // val��ʾ��ɾԪ�صĵ�ַ�� *val���¼��ֵ
    for (int i = pos; i < pArr->cnt; i++) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return 1;//1��ʾɾ���ɹ�
}

//ð������
void sort_arr(Array * pArr){
    int t;
    for (int i = 0; i < pArr->cnt-1; ++i) {
        for (int j = 0; j <pArr->cnt-1-i; ++j) {
            if(pArr->pBase[j]>pArr->pBase[j+1]){
                t = pArr->pBase[j+1];
                pArr->pBase[j+1] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
    return;
}

void inversion_arr(Array * pArr){
    int i=0;
    int j = pArr->cnt - 1;
    int t;
    while (i<j) {
        t=pArr->pBase[i];
        pArr->pBase[i]=pArr->pBase[j];
        pArr->pBase[j]=t;
        i++;
        j--;
    }
    return;
}