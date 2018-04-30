#include<iostream>
#include<cstring>
#include<queue>
#define maxn 100000+10

using namespace std;
int arr[maxn] = {0};

// 对于数组储存的二叉树的遍历， 还原
// 层次遍历
void lev_tra(int *arr){
    queue<int> q;
    q.push(1);
    while(q.size()){
        int cur = q.front();
        cout << arr[cur] << " ";
        q.pop();
        if(arr[cur*2]) q.push(cur*2);
        if(arr[cur*2+1]) q.push(cur*2+1);
    }
}
//先序遍历
void preorder(int *arr,int cur){
    if(!arr[cur]) return;
    cout << arr[cur] << " ";
    preorder(arr, cur*2);
    preorder(arr, cur*2+1);
}
//中序遍历
void inorder(int *arr,int cur){
    if(!arr[cur]) return;
    inorder(arr, cur*2);
    cout << arr[cur] << " ";
    inorder(arr, cur*2+1);
}
//后序遍历
void postorder(int *arr,int cur){
    if(!arr[cur]) return;
    postorder(arr, cur*2);
    postorder(arr, cur*2+1);
    cout << arr[cur] << " ";
}

int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn];
//中序遍历+后续=>建树(对于每个节点储存的不同权值的二叉树)
int build(int L1, int R1, int L2, int R2){// L1,R1为中序边界  L2,R2为后序边界
    if(L1 > R2) return 0;
    int root = post_order[R2];
    int p = R1;
    while(in_order[p] != root) p++;
    int cnt = p - R1;
    lch[root] = build(L1, p-1, L2, L2+cnt-1);
    rch[root] = build(p+1, R1, L2+cnt, R2-1);
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++) arr[i] = i;
        lev_tra(arr);
        cout << endl;
        preorder(arr, 1);
        cout << endl;
        inorder(arr, 1);
        cout << endl;
        postorder(arr, 1);
    }
    return 0;
}
