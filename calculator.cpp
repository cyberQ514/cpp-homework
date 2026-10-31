#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);   // 让 Windows 控制台按 UTF-8 显示中文
#endif

    int a, b;
    char op;

    printf("请输入两个整数（用空格分开）：");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("输入格式不对。\n");
        return 1;
    }

    printf("请输入运算符（+ - * /）：");
    if (scanf(" %c", &op) != 1) {
        printf("没有读到运算符。\n");
        return 1;
    }

    // 先读到运算符，再按需要计算，避免除数为 0 时也去执行除法
    switch (op) {
    case '+':
        printf("%d + %d = %d\n", a, b, a + b);
        break;
    case '-':
        printf("%d - %d = %d\n", a, b, a - b);
        break;
    case '*':
        printf("%d * %d = %d\n", a, b, a * b);
        break;
    case '/':
        if (b == 0) {
            printf("除数不能为 0。\n");
            return 1;
        }
        printf("%d / %d = %d（整数除法，余 %d）\n", a, b, a / b, a % b);
        break;
    default:
        printf("不认识的运算符：%c\n", op);
        return 1;
    }

    return 0;
}
