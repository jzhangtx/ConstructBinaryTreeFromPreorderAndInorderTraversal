// ConstructFromPreAndInorder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

void LevelorderTraversal(std::queue<Node*>& temp, std::vector<int>& result)
{
    if (temp.empty())
        return;

    std::queue<Node*> q;
    while (!temp.empty())
    {
        Node* n = temp.front();
        temp.pop();
        result.push_back(n->data);
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
    }

    LevelorderTraversal(q, result);
}

size_t Find(const std::vector<int>& v, size_t start, size_t end, int num)
{
    for (; start < v.size(); ++start)
        if (v[start] == num)
            return start;

    return -1;
}

Node* Construct(std::vector<int>& preorder, std::vector<int>& inorder, size_t& ptPre, size_t ptInStart, size_t ptInEnd)
{
    if (ptPre == preorder.size() || ptInStart >= ptInEnd)
        return nullptr;

    Node* pNode = new Node(preorder[ptPre]);
    size_t nodeIn = Find(inorder, ptInStart, ptInEnd, preorder[ptPre]);
    if (nodeIn == -1)
        return pNode;

    if (ptInStart < nodeIn)
        pNode->left = Construct(preorder, inorder, ++ptPre, ptInStart, nodeIn);
    if (nodeIn+1 < ptInEnd)
        pNode->right = Construct(preorder, inorder, ++ptPre, ++nodeIn, ptInEnd);

    return pNode;
}

Node* ConstructTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    size_t ptPre = 0, ptIn = 0;

    return Construct(preorder, inorder,ptPre, ptIn, inorder.size());
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Inorder array: ";
        std::vector<int> preorder(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> preorder[i];

        std::vector<int> inorder(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> inorder[i];

        Node* root = ConstructTree(preorder, inorder);

        std::vector<int> result;
        std::queue<Node*> temp;
        temp.push(root);
        LevelorderTraversal(temp, result);
        std::cout << result[0];
        for (size_t i = 1; i < result.size(); ++i)
            std::cout << ", "  << result[i];
        std::cout << std::endl;

        FreeTree(root);
    }
}
