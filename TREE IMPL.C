#include <stdio.h>
#include <stdlib.h>
struct node {
  char data;
  struct node *left, *right;
};
struct node *create() {
  char x;
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("enter the data(if null enter 0)\n");
  scanf("%s", &x);
  if (x == 0X30) {
    return 0;
  }
  newnode->data = x;
  printf("enter the left element of %c\n", x);
  newnode->left = create();
  printf("enter the right element of %c\n", x);
  newnode->right = create();
  return newnode;
}
void Inorder(struct node *T) {
  if (T != NULL) {

    Inorder(T->left);
    printf("%c", T->data);
    Inorder(T->right);
  }
}
void preorder(struct node *T) {
  if (T != NULL) {

    printf("%c", T->data);
    preorder(T->left);
    preorder(T->right);
  }
}
void postorder(struct node *T) {
  if (T != NULL) {
    postorder(T->left);
    postorder(T->right);
    printf("%c", T->data);
  }
}

int main() {
  struct node *root;
  root = NULL;
  root = create();
  printf("%d\n", root->data);
  printf("infix order is :\n");
  Inorder(root); // address of root node
  printf("\n");
  printf("prefix order is :\n");
  preorder(root);
  printf("\n");
  printf("postfix order is:\n");
  postorder(root);
}