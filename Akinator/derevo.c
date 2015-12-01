/*Соломатин Артем
 * Бинарное Дерево
 * 
 * создать функцию для заполнения, создать базу данных
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef int Data;        //меняем тип данных

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

struct Node * tree_add (struct Node * root, Data x);
void tree_print (struct Node * root);

int main(){
	struct Node * root=NULL;
	root = tree_add(root, 7);
	root = tree_add(root, 3);
	root = tree_add(root, 2);
	root = tree_add(root, 1);
	root = tree_add(root, 9);
	root = tree_add(root, 5);
	root = tree_add(root, 4);
	root = tree_add(root, 6);
	root = tree_add(root, 8);
	tree_print(root);	
	return 0;
}

struct Node * tree_add (struct Node * root, Data x){
	 if (root == NULL){
        root = malloc(sizeof(struct Node));
        root->val = x;
    }
    if (x<(root->val)){
        root->left = tree_add(root->left, x);
    }
    if (x>(root->val)){
        root->right = tree_add(root->right, x);
    } 
    return root;
}

void tree_print (struct Node * root){
    if (root != NULL){
        tree_print(root->left);
        printf("%d ", root->val);
        tree_print(root->right);
    }
}
