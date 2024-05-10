#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

// 스택 구조체
typedef struct STACK {
    char operator[MAX_SIZE];
    int top;
} STACK;

int isEmpty(STACK *stack);
void push(STACK *stack, char operator);
char pop(STACK *stack);
char peek(STACK *stack);

void convert(char *str);  // 중위수식을 후위수식으로 변환
int priority(char operator);
int isOperator(char c);

int main() {
    int N;
    char str[MAX_SIZE] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        convert(str);
    }
    return 0;
}

int isEmpty(STACK *stack) { return (stack->top == -1); }

void push(STACK *stack, char operator) {
    stack->operator[++(stack->top)] = operator;
}

char pop(STACK *stack) {
    if (isEmpty(stack)) {
        return 0;
    }
    return stack->operator[(stack->top)--];
}

char peek(STACK *stack) {
    if (isEmpty(stack)) {
        return 0;
    }
    return stack->operator[stack->top];
}

void convert(char *str) {  // 중위수식을 후위수식으로 변환
    STACK *stack = (STACK *)malloc(1 * sizeof(STACK));
    stack->top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {  // 피연산자 case
            printf("%c", str[i]);
        } else if (str[i] == '(') {
            push(stack, str[i]);  // 여는 괄호일 때 push
        } else if (str[i] == ')') {
            while (peek(stack) != '(') {
                printf("%c", pop(stack));  // 닫는 괄호일 때 '(' 전까지 모두 pop
            }
            pop(stack);                            // 여는 괄호 제거
        } else {                                   // 기호(연산자) case
            if (str[i] == '&' || str[i] == '|') {  // 논리연산자의 경우 (&&, ||)
                while (!isEmpty(stack) &&
                       priority(str[i]) <= priority(peek(stack))) {
                    printf("%c", pop(stack));  // 현재 연산자보다 우선순위가
                                               // 높은 기호(연산자)들을 출력
                }
                push(stack, str[i++]);  // 현재 기호(연산자)를 스택에 추가
                push(stack, str[i]);  // 현재 기호(연산자)를 스택에 추가
                continue;
            } else if (str[i] == '+' ||
                       str[i] == '-') {  // 단항연산자 +, -의 경우
                // start with + or -
                // or such as *+ , /-, (+ ...
                // but not )-
                if (!isEmpty(stack) && isOperator(str[i - 1]) &&
                    str[i - 1] != ')') {
                    push(stack, (str[i] == '+')
                                    ? '@'
                                    : '#');  // 다른 문자로 치환해서 push
                    continue;
                }
            }

            // 그 외의 경우
            while (!isEmpty(stack) &&
                   priority(str[i]) <=
                       priority(peek(stack))) {  // 현재 연산자보다 우선순위가
                                                 // 높은 기호(연산자)들을 출력
                if (peek(stack) == '@') {
                    pop(stack);
                    printf("%c", '+');
                } else if (peek(stack) == '#') {
                    pop(stack);
                    printf("%c", '-');
                } else {
                    printf("%c", pop(stack));
                }
            }
            push(stack, str[i]);  // 현재 기호(연산자)를 스택에 추가
        }
    }

    // 스택에 남은 나머지 기호(연산자)들을 출력
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");
}

int priority(char operator) {
    if (operator== '!' || operator== '@' || operator==
        '#')  // 단항연산자의 경우
        return 6;
    else if (operator== '*' || operator== '/')
        return 5;
    else if (operator== '+' || operator== '-')
        return 4;
    else if (operator== '>' || operator== '<')
        return 3;
    else if (operator== '&')
        return 2;
    else if (operator== '|')
        return 1;
    else
        return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '&' ||
            c == '|' || c == '!' || c == '<' || c == '>' || c == '(' ||
            c == ')');
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)

AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||EF>!||
*/