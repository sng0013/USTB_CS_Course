#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Node {
    string expr;
    vector<Node*> children;
    int level;
    Node(string e) : expr(e), level(0) {}
};

Node* parseNode(const string& exp, int& p) {
    int start = p;
    while (p < exp.size() && exp[p] != ',' && exp[p] != ')') {
        if (exp[p] == '(') {
            int count = 1;
            ++p;
            while (p< exp.size() && count > 0) {
                if (exp[p] == '(') count++;
                else if (exp[p] == ')') count--;
                ++p;
            }
        }
        else {
            ++p;
        }
    }
    string exp1 = exp.substr(start, p- start);
    Node* node = new Node(exp1);
    int pos_1 = 0;
    while (pos_1 < exp1.size()) {
        if (exp1[pos_1] == '(') {
            ++pos_1;
            while (pos_1 < exp1.size() && exp1[pos_1] != ')') {
                node->children.push_back(parseNode(exp1, pos_1));
                if (exp1[pos_1] == ',') {
                    ++pos_1;
                }
            }
            if (pos_1 < exp1.size() && exp1[pos_1] == ')') {
                ++pos_1;
            }
        }
        else {
            ++pos_1;
        }
    }
    if (p < exp.size() && exp[p] == ',') {
        ++p;
    }

    return node;
}

int levelNum(Node* node) {
    if (node->children.empty()) {
        node->level = 0;
    }
    else {
        int maxLevel = 0;
        for (auto child : node->children) {
            maxLevel = max(maxLevel, levelNum(child));
        }
        node->level = maxLevel + 1;
    }
    return node->level;
}

void collectNodeLevel(Node* node, unordered_map<int, vector<string>>& nodeLevel) {
    nodeLevel[node->level].push_back(node->expr);
    for (auto child : node->children) {
        collectNodeLevel(child, nodeLevel);
    }
}

int main() {
    string expression;
    cin >> expression;
    int pos = 0;
    Node* root = parseNode(expression, pos);
    // 计算项的层数
    int maxLevel = levelNum(root);
    // 按层数收集项
    unordered_map<int, vector<string>> nodeLevel;
    collectNodeLevel(root, nodeLevel);
    // 输出最大层数
    cout << maxLevel << endl;
    // 按层数输出项
    for (int level = 0; level <= maxLevel; ++level) {
        if (nodeLevel.find(level) != nodeLevel.end()) {
            for (size_t i = 0; i < nodeLevel[level].size(); ++i) {
                if (i > 0) cout << ";";
                cout << nodeLevel[level][i];
            }
            cout << endl;
        }
    }
    return 0;
}

