#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  //包含exit

//定义结构体类型，保持顺序表（数组），类型名叫struct Arr
typedef struct Arr{
    int * pBase;//描述的数组第一个元素的地址
    int len;//描述数组的长度
    int cnt;//当前数组有效元素的个数
}Array;
void init_arr(Array * pArr, int length);//初始化顺序表
int append_arr(Array * pArr, int val);//向顺序表里末尾追加新元素
int insert_arr(Array * pArr, int pos, int val);//向顺序表里插入元素
int delete_arr(Array * pArr, int pos, int * val);//删除表里元素
int is_empty(Array * pArr);//判断是否空表
int is_full(Array * pArr);//判断是否满表
void sort_arr(Array * pArr);//排序表里元素
void show_arr(Array * pArr);//显示打印表里元素
void inversion_arr(Array * pArr);//将顺序表反转

int main() {
    int val;//表示记录被删元素的值
    Array arr;//定义结构体变量
    init_arr(&arr, 5);//初始化长度为10的数组
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
    printf("被删除的值为：%d\n", val);
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

void init_arr(Array * pArr, int length)//初始化顺序表
{
    pArr->pBase = (int *)malloc(sizeof(int)*length);
    if(pArr->pBase == NULL)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    } else{
        pArr->len=length;
        pArr->cnt=0;
    }
    return;
}

int append_arr(Array * pArr, int val){//向顺序表里插入元素
    pArr->pBase[pArr->cnt]=val;
    (pArr->cnt)++;
    return 1;
}

int is_empty(Array * pArr){ //判断是否空表
    if (pArr->cnt==0){
        return 1;//1表示空表
    } else{
        return 0;//表示非空表
    }
}

int is_full(Array * pArr){
    //判断表是否满了
    if (pArr->cnt == pArr->len){
        printf("该表已满");
        return 1;//1表示表满
    } else{
        return 0;//0表示未满
    }
}

void show_arr(Array * pArr){
    if (is_empty(pArr))
        printf("该表为空表！\n");
    else{
        for(int i=0;i<pArr->cnt;i++){
            printf("%d ", pArr->pBase[i]);
        }
    }
    return;
}

int insert_arr(Array * pArr, int pos, int val){
    //插入元素，在第pos个位置前面插入，pos的值从1开始
    if (is_full(pArr)){
        printf("该表已满，不能插入。\n");
        return 0;
    }
    if(pos<1 || pos>pArr->cnt+1)//插入位置不合法
    {
        printf("插入位置非法！！！");
        return 0;//0表示插入失败
    } else {
        for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
            pArr->pBase[i + 1] = pArr->pBase[i];
        }
    }
    pArr->pBase[pos-1] = val;
    pArr->cnt++;
    return 1;//1表示插入成功
}

int delete_arr(Array * pArr, int pos, int * val) {
    //删除在第pos个位置，值保存给val
    if (is_empty(pArr)){
        printf("空表不能删除。\n");
        return 0;
    }
    if(pos<1 || pos>pArr->cnt+1)//删除位置不合法
    {
        printf("插入位置非法！！！");
        return 0;//0表示删除失败
    }
    *val=pArr->pBase[pos-1]; // val表示被删元素的地址， *val则记录了值
    for (int i = pos; i < pArr->cnt; i++) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return 1;//1表示删除成功
}

//冒泡排序
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