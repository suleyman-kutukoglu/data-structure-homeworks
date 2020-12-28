#include <stdio.h>
#include <stdlib.h>

// Part 1 pre-definitions
typedef struct n{
  int data;
  struct n *left;
  struct n *right;
}node;

node * addRight(node * root, int data);
node * addLeft(node * root, int data);
//DFS
void printPreOrder(node* root) ;
void printInOrder(node*root);
void printPostOrder(node*root);
//DFS


// BFS
void printGivenLevel(node* root, int level);
int height(node* node);
void printLevelOrder(node* root);
// BFS

// Part 2 pre-definitions
typedef struct stu{
  int point;
  int number;
  int index;
  struct stu *left, *right;
}stuNode;

//Adds a new student.
stuNode* addStudent(stuNode* node, int index);

//Listing students with a higher point than the entered point.
void printStudentsBiggerThan(stuNode* node, int pointValue);

//This function deletes the student.
stuNode* deleteStudent(stuNode* root, int index);
//required for delete
stuNode* minValueNode(stuNode* node);

//It changes the student's point and updates its location.
void updateStudent(stuNode* root, int newPoint, int index);

//Global array definition for accessing within functions.
int studentNumbers[50] = {18060311,20060045,19061091,20060134,20060678,18061086,20060032,20060067,19060456,18060245,20060110,20060234,20060141,20060011,20060012};
int studentPoints[50] = {40,50,75,90,40,75,50,60,60,75,40,90,60,50,60};
int studentIndexes[50] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	
int main(void) {

  node * root = NULL;

  root = addRight(root,1); 
  addRight(root,7); 
  addLeft(root, 3);
  addLeft(root,2); 
  addRight(root->left,4); 
  addRight(root,5); 
  addLeft(root->right,6); 

  printf("\nPart 1:\n\nDFS:\n");
  printf("Pre-order: ");
  printPreOrder(root);
  printf("\nIn-order: ");
  printInOrder(root);
  printf("\nPost-order: ");
  printPostOrder(root);
  printf("\n\nBFS: ");
  printLevelOrder(root);

    stuNode *student = NULL;
    student = addStudent(student,0);
    addStudent(student,1);
    addStudent(student,2);
    addStudent(student,3);
    addStudent(student,4);
    addStudent(student,5);
    addStudent(student,6);
    addStudent(student,7);
    addStudent(student,8);
    addStudent(student,9);
    addStudent(student,10);
    addStudent(student,11);
    addStudent(student,12);
    addStudent(student,13);
    addStudent(student,14);
    
  printf("\n\nPart 2:\n\n");

  printStudentsBiggerThan(student,0);
  
  //Some test cases.
  
  
  //Deleting the last node successful.	
  //deleteStudent(student, 4);
  
  //Deleting a node from the middle is successful.
  //deleteStudent(student,6);
  
  //Deleting the first node succesful.
  //deleteStudent(student,3);
  
  //Update the first node successful.
  //updateStudent(student, 40, 3); 
  
  
  //The node update was successful from the middle.
  //updateStudent(student, 60, 7);
  
  //Updating the last node successful.
  //updateStudent(student 75, 4);
  
  return 0;
}

node * addRight(node * root, int data){
  
  if(root == NULL){
    node * root = (node *)malloc(sizeof(node));
    root-> left = NULL;
    root-> right = NULL;
    root-> data = data;
    return root; 
  }

  node * newNode = (node *)malloc(sizeof(node));
  newNode-> right = root->right;
  newNode-> left = NULL;
  newNode-> data = data;

  root->right = newNode;
  
  return root;
}

node * addLeft(node * root, int data){
  
  if(root == NULL){
    node * root = (node *)malloc(sizeof(node));
    root-> left = NULL;
    root-> right = NULL;
    root-> data = data;
    return root; 
  }

  node * newNode = (node *)malloc(sizeof(node));
  newNode-> left = root->left;
  newNode-> right = NULL;
  newNode-> data = data;

  root->left = newNode;
  
  return root;
}

void printInOrder(node* root) {
   if(root != NULL) {
      printInOrder(root->left);
      printf("%d ",root->data);          
      printInOrder(root->right);
   }
}
void printPostOrder(node* node) 
{ 
     if (node == NULL) 
        return; 
  

     printPostOrder(node->left); 
  
 
     printPostOrder(node->right); 
  

     printf("%d ", node->data); 
} 

void printPreOrder(node* root) 
{ 
     if (root == NULL) 
          return; 
  
     printf("%d ", root->data);   
  

     printPreOrder(root->left);   
  

     printPreOrder(root->right); 
}   

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

stuNode* addStudent(stuNode* node,int index) 
{ 

    if (node == NULL){
      
      stuNode * temp = (stuNode*)malloc(sizeof(stuNode)); 
      temp->index = index; 
      temp->left = temp->right = NULL; 
      return temp;  
    }

    if (studentPoints[index] < studentPoints[node->index])
        node->left = addStudent(node->left, index); 
    else if (studentPoints[index] > studentPoints[node->index]) 
        node->right = addStudent(node->right, index); 
    else if(studentPoints[index] == studentPoints[node->index] && studentNumbers[index] < studentNumbers[node->index])
      node->right = addStudent(node->right, index);
    else if(studentPoints[index] == studentPoints[node->index] && studentNumbers[index] > studentNumbers[node->index])
      node->left = addStudent(node->left, index); 

    return node; 
}

void printStudentsBiggerThan(stuNode* node, int pointValue) 
{ 
     if (node == NULL) 
        return;
     printStudentsBiggerThan(node->right, pointValue);
     if(studentPoints[node->index] > pointValue) 
      printf("Number: %d Point: %d Index: %d\n", studentNumbers[node->index],studentPoints[node->index],node->index);
     printStudentsBiggerThan(node->left, pointValue); 
}

stuNode* minValueNode(stuNode* node)
{
    stuNode* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
stuNode* deleteStudent(stuNode* root, int index)
{
    if (root == NULL)
        return root;
 
    if (studentPoints[index] < studentPoints[root->index])
        root->left = deleteStudent(root->left, index);
 
    else if (studentPoints[index] > studentPoints[root->index])
        root->right = deleteStudent(root->right, index);
 
    else if(studentPoints[index] == studentPoints[root->index] && studentNumbers[index] < studentNumbers[root->index])
        root->right = deleteStudent(root->right,index);

    else if(studentPoints[index] == studentPoints[root->index] &&  studentNumbers[index] > studentNumbers[root->index])
        root->left = deleteStudent(root->left, index);

    else {

        if (root->left == NULL) {
            stuNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            stuNode* temp = root->left;
            free(root);
            return temp;
        }
 
        stuNode* temp = minValueNode(root->right);
 
        root->index = temp->index;
 
        root->right = deleteStudent(root->right, temp->index);
    }
    return root;
}
void updateStudent(stuNode* root, int newPoint, int index){
  deleteStudent(root, index);
  studentPoints[index] = newPoint;
  addStudent(root, index);
}
