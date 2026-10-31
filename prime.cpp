#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

// 判断 n 是不是素数：小于 2 的不是；2 是；其余只需要试除到 sqrt(n)。
int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int t = 2; t * t <= n; t++) {
        if (n % t == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);   // 让 Windows 控制台按 UTF-8 显示中文
#endif

    int a;
    printf("请输入一个整数：");
    if (scanf("%d", &a) != 1) {
        printf("输入的不是整数。\n");
        return 1;
    }

    if (is_prime(a)) {
        printf("%d 是素数\n", a);
    } else {
        printf("%d 不是素数\n", a);
    }
    return 0;
}
