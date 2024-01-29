#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEnd;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) // key = naber
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEnd = true;
}

bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return pCrawl->isEnd;
}

int main() {

    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);

    struct TrieNode* root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    char output[][32] = {"not present in trie", "present in trie"};

    cout << "the" << " --- " << output[search(root, "the")] << '\n';
    cout << "these" << " --- " << output[search(root, "these")] << '\n';
    cout << "their" << " --- " << output[search(root, "their")] << '\n';
    cout << "thaw" << " --- " << output[search(root, "thaw")] << '\n';

    return 0;
}