Disjoint Set (Union-Find)
Given an array par[] that stores all number from 1 to n (both inclusive and sorted) and k queries.
The task is to do the following operations on array elements :
1. UNION x z : Perform union of x and z i.e. parent of z will become the parent of x.
2. FIND x: Find the ultimate parent of x and print it.
Note: Initially all are the parent of themselves.The ultimate parent is the topmost node such that par[node]=node.

Input: n = 5, k = 4, queries[] = {{find 4}, {find 1}, {unionSet 3 1}, {find 3}}
Output: 4 1 1
Explanation:
1. The parent of 4 is 4. Hence the output is 4.
2. The parent of 1 is 1. Hence the output is 1.
3. After performing unionSet 3 1, parent of 3 becomes 1, since, parent of 1 is currently 1 itself.
4. The parent of 3 is now 1. Hence, the output is 1.

int find(int par[], int x) {
    // add code here
    if(par[x]==x) return x;
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int ulp_u=find(par,x);
    int ulp_v=find(par,z);
    par[ulp_u]=ulp_v;    
}