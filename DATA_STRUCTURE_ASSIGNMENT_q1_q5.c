#include <stdio.h>
#include <string.h>

#define MAX 100

// ---------- STACK FOR STRING ----------
char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

// Q1: Reverse String 
void reverseString() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);
    top = -1;

    for(int i = 0; i < len; i++) {
        push(str[i]);
    }

    for(int i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s\n", str);
}

// Q2: Balanced Parentheses
char stack2[MAX];
int top2 = -1;

void push2(char ch) {
    stack2[++top2] = ch;
}

char pop2() {
    return stack2[top2--];
}

int isBalanced(char exp[]) {
    top2 = -1;

    for(int i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(') {
            push2(exp[i]);
        } else if(exp[i] == ')') {
            if(top2 == -1) return 0;
            pop2();
        }
    }

    return (top2 == -1);
}

void checkParentheses() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    if(isBalanced(exp))
        printf("Balanced Expression\n");
    else
        printf("Not Balanced\n");
}

//  Q3: Next Greater Element
void nextGreaterElement() {
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int stack3[100];
    int top3 = -1;

    stack3[++top3] = arr[0];

    for(int i = 1; i < n; i++) {
        int next = arr[i];

        while(top3 != -1 && stack3[top3] < next) {
            printf("%d -> %d\n", stack3[top3--], next);
        }

        stack3[++top3] = next;
    }

    while(top3 != -1) {
        printf("%d -> -1\n", stack3[top3--]);
    }
}

//  Q4: Normal Queue
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) {
        printf("Queue Full\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}

void dequeue() {
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Printed: %d\n", queue[front++]);
}

void displayQueue() {
    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void printerQueue() {
    int ch, x;
    while(1) {
        printf("\n1.Add 2.Print 3.Display 4.Back\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter document: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return;
        }
    }
}

// Q5: Circular Queue
int cqueue[MAX];
int f = -1, r = -1;

void cenqueue(int x) {
    if((r + 1) % MAX == f) {
        printf("Queue Full\n");
        return;
    }

    if(f == -1) f = 0;
    r = (r + 1) % MAX;
    cqueue[r] = x;
}

void cdequeue() {
    if(f == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed: %d\n", cqueue[f]);

    if(f == r) {
        f = r = -1;
    } else {
        f = (f + 1) % MAX;
    }
}

void cdisplay() {
    if(f == -1) {
        printf("Queue Empty\n");
        return;
    }

    int i = f;
    while(1) {
        printf("%d ", cqueue[i]);
        if(i == r) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void circularQueue() {
    int ch, x;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Back\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                scanf("%d", &x);
                cenqueue(x);
                break;
            case 2:
                cdequeue();
                break;
            case 3:
                cdisplay();
                break;
            case 4:
                return;
        }
    }
}

// ---------- MAIN MENU ----------
int main() {
    int choice;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Reverse String\n");
        printf("2. Balanced Parentheses\n");
        printf("3. Next Greater Element\n");
        printf("4. Printer Queue\n");
        printf("5. Circular Queue\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1: reverseString(); break;
            case 2: checkParentheses(); break;
            case 3: nextGreaterElement(); break;
            case 4: printerQueue(); break;
            case 5: circularQueue(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}