#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

class NODE;struct CMP;
long long n,k,w,tot=0,maxdeep;

class NODE
{
public:
    long long deep,h,useful;
    long long w;
    string name,code;
    vector<NODE*>son;
    NODE():deep(0),w(0),useful(0),name("Default"){}
};

struct CMP{
    bool operator() (NODE* &a,NODE* &b)const{
        if(a->w==b->w){return a->h > b->h;}
        return a->w > b->w;
    }
};

class HuffmanTree
{
    void _HouXu(NODE* x){
        for(auto &i:x->son){
            _HouXu(i);
        }
        cout<<x->name<<"\n";
    }
public:
    NODE* root;
    priority_queue<NODE*,vector<NODE*>,CMP>q;//堆优化寻找每次的最小值
    int cnt_time=1;
    map<string,string>mp;

    void Build();
    void BianLi_bfs();
    void BianLi_dfs(NODE*);
    void HouXu(NODE*);
    string YiMa(string);
};

void HuffmanTree::Build(){
    //k进制添加空节点
    long long temp=(n-1)%(k-1);
    if(temp!=0)temp=k-1-temp;
    for(int i=1;i<=temp;i++){NODE* node=new NODE();node->w=0;q.push(node);}

    while(!q.empty())
    {
        NODE* newnode=new NODE();
        for(int i=1;i<=k;i++){
            NODE* now=q.top();q.pop();
            newnode->w+=now->w;
            newnode->son.push_back(now);
            newnode->h=max(newnode->h,now->h+1);
        }
        if(q.size()==0){this->root=newnode;break;}
        q.push(newnode);
    }

    queue<NODE*>q2;
    root->deep=0;
    q2.push(root);
    int cnt_code=0;
    while(!q2.empty()){
        NODE* now=q2.front();q2.pop();
        this->mp[now->code]=now->name;
        cnt_code=0;
        for(auto& i:now->son){
            i->deep=now->deep+1;
            i->code=now->code+(char)('0'+cnt_code);cnt_code++;
            if(i->son.size()==0&&i->w!=0){tot+=i->deep*i->w;maxdeep=i->deep;}
            q2.push(i);
        }
    }
}

void HuffmanTree::BianLi_bfs(){
    queue<NODE*>q2;
    q2.push(root);
    while(!q2.empty()){
        NODE* now=q2.front();q2.pop();
        if(now->useful) cout<<now->name<<" 's code is:"<<now->code<<"\n";
        for(auto& i:now->son){q2.push(i);}
    }
}
void HuffmanTree::BianLi_dfs(NODE* now){
    if(now->useful) cout<<now->name<<" 's code is:"<<now->code<<"\n";
    for(auto& i:now->son){BianLi_dfs(i);}
}

void HuffmanTree::HouXu(NODE* x){
    cout<<"HouXuBianLi:\n";
    _HouXu(x);
}

string HuffmanTree::YiMa(string code){
    return this->mp[code];
}


int main()
{
    // freopen ("data.in", "r", stdin);  
    // freopen ("data.out", "w", stdout); 
    HuffmanTree huffmanTree;

    //cout<<"一行两个数字,输入n,k.以空格或换行符隔开,表示n个数据和希望生成的哈夫曼编码为k进制\n";
    cin>>n>>k;
    //cout<<"接下来n行,输入每个数据的权值\n";
    for(int i=1;i<=n;i++){
        NODE* node=new NODE();
        node->useful=1;node->name=(char)('A'+i-1);
        cin>>(*node).w;
        huffmanTree.q.push(node);
    }

    huffmanTree.Build();
    huffmanTree.BianLi_bfs();

    // huffmanTree.HouXu(huffmanTree.root);

    string code="00";
    cout<<"the code of "<<code<<" is: "<<huffmanTree.YiMa("00")<<"\n";

    // cout<<tot<<endl;cout<<maxdeep<<endl;

    return 0;
}
/*
参考输入:
4 2
1
1
2
2
*/

