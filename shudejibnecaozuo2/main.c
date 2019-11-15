#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void print()
{
    for(int i=0;i<60;i++)
    {
        printf("*");
    }
    printf("\n");
}
typedef struct TreeNode *Tree;
struct TreeNode
{
    int Data;
    Tree Left;
    Tree Right;
};
void create(Tree *BT)
{
    int n;
    scanf("%d",&n);
    if(n!=0)
    {
        (*BT)=(Tree)malloc(sizeof(struct TreeNode));
        (*BT)->Data=n;
        create(&((*BT)->Left));
        create(&((*BT)->Right));
    }
    else
    {
        (*BT)=NULL;
    }
}
void printtype(Tree BT,int num)
{
    if(BT)
    {
        printtype(BT->Right,num+1);
        for(int i=0;i<num;i++)
        {
            printf(" ");
        }
        printf("%d\n",BT->Data);
        printtype(BT->Left,num+1);
    }
}
void xianxu(Tree BT)
{
    if(BT)
    {
        printf("%d  ",BT->Data);
        xianxu(BT->Left);
        xianxu(BT->Right);
    }
}
void zhongxu(Tree BT)
{
    if(BT)
    {
        zhongxu(BT->Left);
        printf("%d  ",BT->Data);
        zhongxu(BT->Right);
    }
}
void houxu(Tree BT)
{
    if(BT)
    {
        houxu(BT->Left);
        houxu(BT->Right);
        printf("%d  ",BT->Data);
    }
}
void cenxu(Tree BT)
{
    if(BT)
    {
        Tree q[100];
        int rear=0;
        int front=0;
        q[++rear]=BT;
        while(rear!=front)
        {
            Tree m=q[++front];
            printf("%d  ",m->Data);
            if(m->Left!=NULL) q[++rear]=m->Left;
            if(m->Right!=NULL) q[++rear]=m->Right;
        }
    }
}
void printye(Tree BT)
{
    if(BT)
    {
        if(!BT->Left&&!BT->Right)
            printf("%d  ",BT->Data);
        printye(BT->Left);
        printye(BT->Right);
    }
}
int getHeight(Tree BT)
{
    if(BT)
    {
        int left=getHeight(BT->Left);
        int right=getHeight(BT->Right);
        if(left>right)
        {
            return left+1;
        }
        else
        {
            return right+1;
        }
    }
}
int p[100];
int rear=0;
bool IsBST(Tree BT)
{
    if(BT)
    {
        IsBST(BT->Left);
        p[rear++]=BT->Data;
        IsBST(BT->Right);
        for(int i=0;i<rear;i++)
        {
            for(int j=i+1;j<rear;j++)
            {
                if(p[i]>p[j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int remin(Tree BT)
{
    if(BT->Left==NULL) return BT->Data;
    else if(BT==NULL) return NULL;
    else remin(BT->Left);
}
int remax(Tree BT)
{
    if(BT)
        while(BT->Right)
            BT=BT->Right;
    return BT->Data;
    
}
int biaozhi3;
Tree IsFind(Tree BT,int x)
{
    if(BT)
    {
        if(x>BT->Data)
        {
            return IsFind(BT->Right,x);
        }
        else if(x<BT->Data)
        {
            return IsFind(BT->Left,x);
        }
        else
        {
            biaozhi3=1;
            return BT;
        }
    }
}
int biaozhi;
Tree insert(Tree BT,int x)
{
    if(BT==NULL)
    {
        BT=(Tree)malloc(sizeof(struct TreeNode));
        BT->Data=x;
        BT->Left=BT->Right=NULL;
    }
    else
    {
        if(x>BT->Data)
        {
            BT->Right=insert(BT->Right, x);
        }
        else if(x<BT->Data)
        {
            BT->Left=insert(BT->Left, x);
        }
        else
        {
            biaozhi=1;
            printf("二叉搜索树中存在该值\n");
        }
    }
    return BT;
}
int biaozhi1;
Tree Delete(Tree BT,int x)
{
    if(BT==NULL)
    {
        biaozhi1=1;
        printf("二叉搜索树中不存在该结点\n");
    }
    else
    {
        if(x>BT->Data)
        {
            BT->Right=Delete(BT->Right,x);
        }
        else if(x<BT->Data)
        {
            BT->Left=Delete(BT->Left,x);
        }
        else
        {
            if(BT->Left&&BT->Right)
            {
                int m=remin(BT->Right);
                BT->Data=m;
                BT->Right=Delete(BT->Right,m);
            }
            else
            {
                if(BT->Left==NULL)
                {
                    BT=BT->Right;
                }
                else
                {
                    BT=BT->Left;
                }
            }
        }
    }
    return BT;
}
void dist(Tree BT,int v1,int v2)
{
    Tree p=IsFind(BT,v1);
    Tree p1=IsFind(BT,v2);
    while(p!=NULL)
    {
        if(p1->Data>p->Data)
        {
            printf("%d ",p->Data);
            p=p->Right;
        }
        else if(p1->Data<p->Data)
        {
            printf("%d ",p->Data);
            p=p->Left;
        }
        else
        {
            printf("%d ",p->Data);
            break;
        }
    }
}
int main()
{
    printf("请先序建立一棵树，输入0表示该节点为空\n");
    print();
    Tree BT;
    create(&BT);
    print();
    printf("树已经建立成功！您可以选择如下操作：\n");
    print();
    printf("1.先序遍历树,并输出\n");
    printf("2.中序遍历树,并输出\n");
    printf("3.后序遍历树,并输出\n");
    printf("4.层序遍历树,并输出\n");
    printf("5.输出该树的叶子节点\n");
    printf("6.输出树的高度\n");
    printf("7.判断该树是否为二叉搜索树\n");
    printf("8.打印树形\n");
    printf("输入0表示操作结束\n");
    print();
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        switch (n)
        {
            case 1 :xianxu(BT);printf("\n");print();break;
            case 2 :zhongxu(BT);printf("\n");print();break;
            case 3 :houxu(BT);printf("\n");print();break;
            case 4 :cenxu(BT);printf("\n");print();break;
            case 5 :printye(BT);printf("\n");print();break;
            case 6 :printf("该树的高度为：%d\n",getHeight(BT));print();break;
            case 7 :
                if(IsBST(BT))
                {
                    printf("这棵树是一棵二叉搜索树！\n");
                    print();
                    printf("二叉搜索树有如下操作！\n");
                    print();
                    printf("1.查找最大值、最小值\n");
                    printf("2.查找二叉树中是否存在值X\n");
                    printf("3.向二叉搜索树中插入一个值\n");
                    printf("4.从二叉搜索树中删除一个值\n");
                    printf("5.打印二叉搜索树的树形！\n");
                    printf("6.求两个顶点的距离\n");
                    printf("输入0表示二叉搜索树的操作结束\n");
                    print();
                    while(1)
                    {
                        int er;
                        scanf("%d",&er);
                        if(er==0)
                        {
                            break;
                        }
                        switch (er)
                        {
                            case 1:printf("最大值为：%d 最小值为：%d\n",remin(BT),remax(BT));print();break;
                            case 2:
                                printf("请输入X的值\n");
                                int x;
                                scanf("%d",&x);
                                print();
                                biaozhi3=0;
                                IsFind(BT,x);
                                if(biaozhi3==1)
                                {
                                    printf("二差搜索树中存在该结点！\n");
                                    print();
                                }
                                else
                                {
                                    printf("二叉搜索树中不存在该结点\n");
                                    print();
                                }
                                break;
                            case 3:
                                biaozhi=0;
                                printf("请输入要插入的值\n");
                                print();
                                scanf("%d",&x);
                                insert(BT,x);
                                print();
                                if(biaozhi == 0)
                                {
                                    printf("插入成功\n");
                                    print();
                                }
                                break;
                            case 4:
                                printf("请输入要删除的值\n");
                                print();
                                biaozhi1=0;
                                scanf("%d",&x);
                                print();
                                Delete(BT,x);
                                if(biaozhi1==0)
                                {
                                    printf("删除成功！\n");
                                    print();
                                }
                                break;
                            case 5:printtype(BT,1);print();break;
                            case 6:printf("请输入两个顶点的值\n");print();int v1,v2;scanf("%d %d",&v1,&v2);printf("从顶点%d到顶点%d的距离为",v1,v2);dist(BT,v1,v2);printf("\n");print();break;
                        }
                    }
                }
                else
                {
                    printf("这棵树不是一棵二叉搜索树！是否需要重新建立一棵二叉搜索树！请输入是或否！\n");
                    print();
                    char s[8];
                    scanf("%s",s);
                    if(strcmp(s,"是")==0)
                    {
                        rear=0;
                        printf("请输入要新建立的二叉搜索树的信息！\n");
                        print();
                        create(&BT);
                        print();
                        if(IsBST(BT))
                        {
                            
                            printf("这棵树是一棵二叉搜索树！\n");
                            print();
                            printf("二叉搜索树有如下操作！\n");
                            print();
                            printf("1.查找最大值、最小值\n");
                            printf("2.查找二叉树中是否存在值X\n");
                            printf("3.向二叉搜索树中插入一个值\n");
                            printf("4.从二叉搜索树中删除一个值\n");
                            printf("5.打印二叉搜索树的树形！\n");
                            printf("6.求两个顶点的距离\n");
                            printf("输入0表示二叉搜索树的操作结束\n");
                            print();
                            while(1)
                            {
                                int er;
                                scanf("%d",&er);
                                if(er==0)
                                {
                                    break;
                                }
                                switch (er)
                                {
                                    case 1:printf("最大值为：%d 最小值为：%d\n",remin(BT),remax(BT));print();break;
                                    case 2:
                                        printf("请输入X的值\n");
                                        int x;
                                        scanf("%d",&x);
                                        print();
                                        biaozhi3=0;
                                        IsFind(BT,x);
                                        if(biaozhi3==1)
                                        {
                                            printf("二差搜索树中存在该结点！\n");
                                            print();
                                        }
                                        else
                                        {
                                            printf("二叉搜索树中不存在该结点\n");
                                            print();
                                        }
                                        break;
                                    case 3:
                                        biaozhi=0;
                                        printf("请输入要插入的值\n");
                                        print();
                                        scanf("%d",&x);
                                        insert(BT,x);
                                        print();
                                        if(biaozhi == 0)
                                        {
                                            printf("插入成功\n");
                                            print();
                                        }
                                        break;
                                    case 4:
                                        printf("请输入要删除的值\n");
                                        print();
                                        biaozhi1=0;
                                        scanf("%d",&x);
                                        print();
                                        Delete(BT,x);
                                        if(biaozhi1==0)
                                        {
                                            printf("删除成功！\n");
                                            print();
                                        }
                                        break;
                                    case 5:printtype(BT,1);print();break;
                                    case 6:printf("请输入两个顶点的值\n");print();int v1,v2;scanf("%d %d",&v1,&v2);printf("从顶点%d到顶点%d的距离为:",v1,v2);dist(BT,v1,v2);printf("\n");print() ;break;
                                }
                            }
                        }
                    }
                }
                break;
            case 8: printtype(BT,1);print();break;
        }
    }
    return 0;
}
//30 15 0 0 41 33 0 35 34 0 0 0 50 0 0
