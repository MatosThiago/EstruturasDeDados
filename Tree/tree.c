#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tree.h"
#include "queue.h"

t_node * node_create(int data) {
    t_node * node = (t_node *) malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_node * insert(t_node * root, int data) {
    if(root == NULL) {
        return node_create(data);
    } else {
        if(root->data > data) {
            root->left = insert(root->left, data);
        } else if(root->data < data) {
            root->right = insert(root->right, data);
        } else {
            return root;
        }
    }
}

t_node * remove(t_node * root, int data) {
    if(root == NULL) {
        return NULL;
    }
    
    t_node * node = find(root, data),
           * dad = find_dad(root, node->data),
           * removed,
           * fusion;

    if(node == NULL) {
        return NULL;
    }

    if(node->left == NULL && node->right == NULL) {
        removed = NULL;
    }

    if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) {
        if(node->left != NULL) {
            removed = node->left;
        } else {
            removed = node->right;
        }
    }

    if(node->left != NULL && node->right != NULL) {
        removed = node->left;
        fusion = find_rightmost(removed);
        fusion->right = node->right;
    }

    if(dad != NULL) {
        if(dad->left != NULL && dad->left->data == node->data) {
            dad->left = removed;
        } else if(dad->right != NULL && dad->right->data == node->data) {
            dad->right = removed;
        }
        removed = root;
    }

    free(node);
    return removed;
}

t_node * find(t_node * root, int data) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data > data) {
        return find(root->left, data);
    } else if(root->data < data) {
        return find(root->right, data);
    }
    return root;
}

t_node * find_dad(t_node * root, int data) {
    if(root == NULL || root->data == data) {
        return NULL;
    }

    if(root->data > data) {
        if(root->left != NULL && root->left->data == data) {
            return root;
        }
        return find_dad(root->left, data);
    } else if(root->data < data) {
        if(root->right != NULL && root->right->data == data) {
            return root;
        }
        return find_dad(root->right, data);
    }
    return root;
}

t_node * find_rightmost(t_node * root) {
    if(root != NULL) {
        if(root->right != NULL) {
            return find_rightmost(root->right);
        } else {
            return NULL;
        }
    }
    return root;
}

int height(t_node * root) {
    if(root == NULL) {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    if(left_height < right->height) {
        return right->height + 1;
    } else {
        return left->height + 1;
    }
}

int big_node(t_node * root) {
    if(root == NULL) {
        return INT_MIN;
    }

    int big = root->data;
    int big_left = big_node(root->left);
    int big_right = big_node(root->right);

    if(big_left > big) {
        big = big_left;
    }
    if(big_right > big) {
        big = big_right;
    }
    return big;
}

int small_node(t_node * root) {
    if(root == NULL) {
        return INT_MAX;
    }

    int small = root->data;
    int small_left = small_node(root->left);
    int small_right = small_node(root->right);

    if(small_left < small) {
        small = small_left;
    }
    if(small_right < small) {
        small = small_right;
    }
    return small;
}

int sum_of_nodes(t_node * root) {
    if(root == NULL) {
        return 0;
    }

    return root->data + sum_of_nodes(root->left) + sum_of_nodes(root->right);
}

int qtd_of_nodes(t_node * root) {
    if(root == NULL) {
        return 0;
    }

    return qtd_of_nodes(root->left) + qtd_of_nodes(root->right) + 1;
}

int qtd_of_sheets(t_node * root) {
    if(root == NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    return qtd_of_sheets(root->left) + qtd_of_sheets(root->right);
}

void dfs(t_node * root) {
    if(root == NULL) {
        return;
    }

    printf("[%d]\n", root->data);
    dfs(root->left);
    dfs(root->right);
}

void bfs(t_node * root) {
    if(root == NULL) {
        return;
    }

    t_queue * queue = create_queue();
    t_node * node;

    push(root, queue);
    
    while(!empty_queue(queue)) {
        node = pull(queue);
        printf("[%d]\n", node->data);

        if(node->left != NULL) {
            insert(node->left, queue);
        }
        if(node->right != NULL) {
            insert(node->right, queue);
        }
    }
    free_queue(queue);
}

void free_tree(t_node * root) {
    if(root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
