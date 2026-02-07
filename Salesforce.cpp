#include <bits/stdc++.h>
using namespace std;

int minEdgesToCollectData(vector<int> opportunityData, int branch_nodes,
                          vector<int> branch_from, vector<int> branch_to) {

    int _nodeCount$ = branch_nodes;

    // Adjacency list representation of the tree
    vector<vector<int>> graph$_list(_nodeCount$);
    for (int i = 0; i < (int)branch_from.size(); i++) {
        int _fromNode$ = branch_from[i];
        int _toNode$   = branch_to[i];
        graph$_list[_fromNode$].push_back(_toNode$);
        graph$_list[_toNode$].push_back(_fromNode$);
    }

    // Degree of each node
    vector<int> deg_count$(_nodeCount$);
    for (int i = 0; i < _nodeCount$; i++)
        deg_count$[i] = (int)graph$_list[i].size();

    // Marks nodes that are removed
    vector<char> _isRemoved$(_nodeCount$, 0);

    // Queue for processing leaf nodes
    deque<int> leaf_queue$;

    // Push leaf nodes without opportunity data
    for (int i = 0; i < _nodeCount$; i++) {
        if (deg_count$[i] == 1 && opportunityData[i] == 0)
            leaf_queue$.push_back(i);
    }

    // Initial number of edges in a tree
    int _remainingEdges$ = _nodeCount$ - 1;

    // Phase 1: Remove useless leaf nodes
    while (!leaf_queue$.empty()) {
        int _currNode$ = leaf_queue$.front();
        leaf_queue$.pop_front();

        if (_isRemoved$[_currNode$]) continue;
        _isRemoved$[_currNode$] = 1;

        for (int _adjNode$ : graph$_list[_currNode$]) {
            if (_isRemoved$[_adjNode$]) continue;

            deg_count$[_adjNode$]--;
            _remainingEdges$--;

            // Add neighbor if it becomes a useless leaf
            if (deg_count$[_adjNode$] == 1 && opportunityData[_adjNode$] == 0)
                leaf_queue$.push_back(_adjNode$);
        }
    }
    // Collect remaining leaf nodes
    for (int i = 0; i < _nodeCount$; i++) {
        if (!_isRemoved$[i] && deg_count$[i] == 1)
            leaf_queue$.push_back(i);
    }
    // Phase 2: Remove two layers of leaves
    for (int _layer$ = 0; _layer$ < 2 && !leaf_queue$.empty(); _layer$++) {
        int _layerSize$ = (int)leaf_queue$.size();

        while (_layerSize$--) {
            int _currNode$ = leaf_queue$.front();
            leaf_queue$.pop_front();

            if (_isRemoved$[_currNode$]) continue;
            _isRemoved$[_currNode$] = 1;

            for (int _adjNode$ : graph$_list[_currNode$]) {
                if (_isRemoved$[_adjNode$]) continue;

                deg_count$[_adjNode$]--;
                _remainingEdges$--;

                if (deg_count$[_adjNode$] == 1)
                    leaf_queue$.push_back(_adjNode$);
            }
        }
    }
    // Safety check
    if (_remainingEdges$ < 0)
        _remainingEdges$ = 0;

    // Each edge needs to be traversed twice
    return _remainingEdges$ * 2;
}
int main() {
    // Test Case 
    int branch_nodes = 12;
    vector<int> opportunityData = {
        1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1
    };
    vector<int> branch_from = {
        0, 1, 2, 3, 4, 5, 6, 8, 3, 9, 10
    };
    vector<int> branch_to = {
        1, 2, 3, 4, 5, 6, 7, 7, 9, 10, 11
    };
    int result = minEdgesToCollectData(
        opportunityData,
        branch_nodes,
        branch_from,
        branch_to
    );
    cout << "Minimum edges required: " << result << endl;
    return 0;
}

