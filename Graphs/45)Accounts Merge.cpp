Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        // Get the number of accounts provided
        int n = details.size();
        
        // Initialize the Disjoint Set (Union-Find) structure with n accounts
        DisjointSet ds(n);
        
        // Sort the account details to ensure a consistent order when processing
        sort(details.begin(), details.end());

        // This map will associate each email to the account index it belongs to
        unordered_map<string, int> mapMailNode;

        // Iterate over each account
        for (int i = 0; i < n; i++) {
            // For every email in the account (skip the first element which is the account name)
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j]; // Get the current email
                
                // If the email is not already in the map, add it with the account index
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                // If the email already exists in the map, perform a union operation
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // A temporary array to hold merged emails for each component where the index corresponds to the root
        vector<string> mergedMail[n];

        // Iterate over the emails in the map to group them by their root parent
        for (auto it : mapMailNode) {
            string mail = it.first; // Get the email
            int node = ds.findUPar(it.second); // Find the root parent for the account index
            mergedMail[node].push_back(mail); // Add email to the corresponding root's list
        }

        // This will hold the final answer
        vector<vector<string>> ans;

        // For each index in mergedMail
        for (int i = 0; i < n; i++) {
            // If there are no emails merged under this root, skip to the next index
            if (mergedMail[i].size() == 0) continue;
            // Sort the list of emails for this root to meet the requirements
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp; // Temporary vector to hold the account name and emails
            temp.push_back(details[i][0]); // Add the account name as the first element

            // Add all merged emails to the temp vector
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            // Push the complete temp vector into the answer vector
            ans.push_back(temp);
        }
        
        // Finally, sort the answer vector to maintain the required order of accounts
        sort(ans.begin(), ans.end());
        
        // Return the merged accounts with their emails
        return ans;
        
    }
};