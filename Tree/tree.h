#ifndef _TREE_
#define _TREE_

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} t_node;

t_node * node_create(int data);
t_node * insert(t_node * root, int data);
t_node * remove(t_node * root, int data);
t_node * find(t_node * root, int data);
t_node * find_dad(t_node * root, int data);
t_node * find_rightmost(t_node * root);

int height(t_node * root);
int big_node(t_node * root);
int small_node(t_node * root);
int sum_of_nodes(t_node * root);
int qtd_of_nodes(t_node * root);
int qtd_of_sheets(t_node * root);
int is_bst(t_node * root);
int is_bst_aux(t_node * root);

void dfs(t_node * root);
void bfs(t_node * root);
void free_tree(t_node * root);

#endif