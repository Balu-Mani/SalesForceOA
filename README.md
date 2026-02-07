# SalesForceOA
**Salesforce OA – Problem Description**

A Salesforce administrator is working on optimizing data collection for Opportunity records across multiple branches.

The branches follow a hierarchical structure, forming a tree with n nodes labeled from 0 to n-1. Each node represents a branch, and an array opportunityData of size n indicates whether a branch contains important Opportunity data. Specifically, opportunityData[i] is 1 if branch i holds relevant data and 0 otherwise.

To gather all Opportunity data, the admin must navigate through the branches using bidirectional paths (edges), which can be traversed multiple times if necessary. The goal is to minimize the total distance traveled, measured by the number of edges crossed. Additionally, any data within a radius of 2 edges from a branch can be collected. For system consistency, the retrieval process must start and end at the same branch.

Determine the minimum number of edges the admin needs to traverse to collect all Opportunity data.

**Test Case :** 
```
branch_nodes = 12

opportunityData = [1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1]

branch_from = [0, 1, 2, 3, 4, 5, 6, 8, 3, 9, 10]
branch_to   = [1, 2, 3, 4, 5, 6, 7, 7, 9, 10, 11]
```

**Output:=**

10

**Explanation :**

Branches 2, 6, and 9 serve as optimal points for collecting all data.

The admin starts at Branch 3 and follows the shortest path to ensure all Opportunity data is collected.

The total distance traversed is 10 edges.
![photo_2026-02-07_18-44-49](https://github.com/user-attachments/assets/fe78cede-aff4-4460-949b-bde3a8e8ceca)
