#include <stdbool.h>

typedef int Error;

typedef struct TreeNode TreeNode;

TreeNode * createTree();

Error add(TreeNode *tree, int key, char *value);

char * get(TreeNode *tree, int key);

bool isExist(TreeNode *tree, int key);

Error delete(TreeNode * tree, int key);