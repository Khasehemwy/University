#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
#define DEBUG cout<<",here\n";
using namespace std;

struct NODE
{
    int l,r;
    int vis;
    int f;
    int deep;
};NODE a[MAXN];

int n,root;


void printXtoA(int x){cout<<(char)('A'+x-1);}
/**********************************************************************************************/
//先序,中序,后序遍历;递归和非递归版
int xianXu(int x,NODE** tree)
{
    if(x==0)return 0;
    printXtoA(x);
    xianXu((*tree)[x].l,tree);
    xianXu((*tree)[x].r,tree);
}
int xianXu_Stack(NODE** tree)
{
    int x=root;
    stack<int>s;
    while(!s.empty()||x!=0)
    {
        while(x!=0){
            printXtoA(x);
            s.push(x);
            x=(*tree)[x].l;
        }
        if(!s.empty()){
            x=s.top();s.pop();
            x=(*tree)[x].r;
        }
    }
}

int zhongXu(int x,NODE** tree)
{
    if(x==0)return 0;
    zhongXu((*tree)[x].l,tree);
    printXtoA(x);
    zhongXu((*tree)[x].r,tree);
}
int zhongXu_Stack(NODE** tree)
{
    int x=root;
    stack<int>s;
    while(!s.empty()||x!=0)
    {
        while(x!=0){
            s.push(x);
            x=(*tree)[x].l;
        }
        if(!s.empty()){
            x=s.top();s.pop();
            printXtoA(x);
            x=(*tree)[x].r;
        }
    }
}

int houXu(int x,NODE** tree)
{
    if(x==0)return 0;
    houXu((*tree)[x].l,tree);
    houXu((*tree)[x].r,tree);
    printXtoA(x);
}
int houXu_Stack(NODE** tree)//加标记法
{
    int x=root;
    stack<int>s;
    s.push(x);
    a[0].vis=1;
    while(!s.empty())
    {
        x=s.top();
        if((*tree)[x].l==0&&(*tree)[x].r==0 || a[(*tree)[x].l].vis==1&&a[(*tree)[x].r].vis==1){
            printXtoA(x);a[x].vis=1;
            s.pop();
        }
        else{
            if((*tree)[x].r)s.push((*tree)[x].r);
            if((*tree)[x].l)s.push((*tree)[x].l);
        }
    }
}
/*********************************************************************************************/


/****************************************************************************************/
//层次遍历
void BianLi(NODE** tree)
{
    int x=root;
    queue<int>q;q.push(root);
    while(!q.empty())
    {
        x=q.front();q.pop();
        printXtoA(x);
        if((*tree)[x].l)q.push((*tree)[x].l);
        if((*tree)[x].r)q.push((*tree)[x].r);
    }
}
/***************************************************************************************/


/****************************************************************************************/
//交换左右子节点
void JiaoHuan(NODE** tree)
{
    int x=root;
    queue<int>q;q.push(root);
    while(!q.empty())
    {
        x=q.front();q.pop();
        swap((*tree)[x].l,(*tree)[x].r);
        if((*tree)[x].l)q.push((*tree)[x].l);
        if((*tree)[x].r)q.push((*tree)[x].r);
    }
}
/***************************************************************************************/



/*******************************************************************************************/
//dfs求深度
int SolveDeep(int x,NODE** tree)
{
    int maxDeep=0;
    if(x==root){a[x].deep=0;}
    else{
        a[x].deep=a[a[x].f].deep+1;
    }
    maxDeep=a[x].deep;
    if((*tree)[x].l){maxDeep=max(maxDeep,SolveDeep((*tree)[x].l,tree));}
    if((*tree)[x].r){maxDeep=max(maxDeep,SolveDeep((*tree)[x].r,tree));}
    return maxDeep;
}
/*******************************************************************************************/

/*******************************************************************************************/
//复制
NODE b[MAXN];
int Copy(int x,NODE** tree1,NODE** tree2)
{
    (*tree2)[x]=(*tree1)[x];
    if((*tree1)[x].l){Copy((*tree1)[x].l,tree1,tree2);}
    if((*tree1)[x].r){Copy((*tree1)[x].r,tree1,tree2);}
}
/*******************************************************************************************/



/*******************************************************************************************/
//由前序中序建立二叉树
int cnt=0;
int BuildTreeBy_Qian_Zhong(string* qian,string* zhong,int l,int r,int f)
{
    for(int i=l;i<=r;i++){
        if((*zhong)[i]==(*qian)[cnt]){
            a[(*zhong)[i]-'0'].f=f;
            if(l<=i-1){
                cnt++;
                a[(*zhong)[i]-'0'].l=BuildTreeBy_Qian_Zhong(qian,zhong,l,i-1,(*zhong)[i]-'0');
            }
            if(i+1<=r){
                cnt++;
                a[(*zhong)[i]-'0'].r=BuildTreeBy_Qian_Zhong(qian,zhong,i+1,r,(*zhong)[i]-'0');
            }
            return (*zhong)[i]-'0';
        }
    }
}
/*******************************************************************************************/


int main()
{
    cin>>n;

    for(int i=1;i<=n;i++){//链式储存
        cin>>a[i].l>>a[i].r;
        a[a[i].l].f=i;
        a[a[i].r].f=i;
    }
    string s1,s2;
    cin>>s1>>s2;

    //BuildTreeBy_Qian_Zhong(&s1,&s2,0,n-1,0);//已知前序中序求后序

    for(int i=1;i<=n;i++)if(a[i].f==0){
        root=i;break;
    }

    // cout<<"root:"<<root<<"\n";
    NODE* tree=a;
    xianXu(root,&tree);DEBUG
    zhongXu(root,&tree);DEBUG
    houXu_Stack(&tree);DEBUG
    
    BianLi(&tree);

    // int maxdeep=SolveDeep(root,&tree);
    // cout<<maxdeep<<"\n";

    // JiaoHuan(&tree);
    // BianLi(&tree);

    // NODE* tree2=b;
    // Copy(root,&tree,&tree2);
    // BianLi(&tree2);

    return 0;
}
