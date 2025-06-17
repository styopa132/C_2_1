#include <stdio.h>
#include <stdlib.h>
struct BinTree {
    int value; 
    struct BinTree* left;
    struct BinTree* right;
};
typedef struct BinTree BinTree;
void newBinTree(int val, BinTree** Tree) {
    if ((*Tree) == NULL) 
    {   (*Tree) = malloc(sizeof (struct BinTree));
        (*Tree)->value = val;  
        (*Tree)->left = (*Tree)->right = NULL;
        return;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);
    else newBinTree(val, &(*Tree)->left);
}
BinTree* Search(BinTree* Tree, int key) {
    if (Tree == NULL) return NULL;
    if  (Tree->value == key) return Tree;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}
void MenuProc() {
    BinTree* Tree = NULL;
    char variant;
    int val;
	printf("��� �������� ������ ��� ���������� �������");
	putchar('\n');
	int c;
    while ((c = getchar()) != EOF && c !=27) {
		printf("������� �������� (��� ���������� ����� ������� ESC)->");
		scanf("%d",&val);
        newBinTree(val, &Tree);
		putchar('\n');
    }
	printf("����� ��������");
	putchar('\n');
    int key;
	printf("������� �������� �������� ��� ������-> ");
	scanf("%d",&key);
    BinTree* Tree1 = Search(Tree,key);
    if (Tree1 == NULL)
		printf("������� �� ������");
    else
		printf("��� �������->");
		printf("%d",Tree1->value);
    putchar('\n');
}
 
int main() {
    MenuProc();
    system("pause");
    return 0;
}