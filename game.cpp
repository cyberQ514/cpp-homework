#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

// 取数游戏：共有 all 个，双方轮流取 1~2 个，取到最后一个的人获胜。
// 电脑的策略是每轮和你凑成 3，让台面始终剩下 3 的倍数，
// 这样最后 1~2 个一定轮到它拿走。
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);   // 让 Windows 控制台按 UTF-8 显示中文
#endif

    int all;
    printf("取数游戏：双方轮流取 1 或 2 个，取到最后一个的人获胜。\n");
    printf("请输入总数：");
    if (scanf("%d", &all) != 1 || all < 1) {
        printf("总数需要是正整数。\n");
        return 1;
    }

    int remain = all;

    // 总数不是 3 的倍数时，电脑先手取走余数，把局面变成 3 的倍数
    if (remain % 3 != 0) {
        int take = remain % 3;
        remain -= take;
        printf("电脑先取 %d 个，剩余 %d 个。\n", take, remain);
        if (remain == 0) {
            printf("电脑取走了最后一个，你输了。\n");
            return 0;
        }
    }

    while (remain > 0) {
        int player;
        printf("该你了，取 1 或 2 个：");
        if (scanf("%d", &player) != 1 || player < 1 || player > 2) {
            printf("只能取 1 或 2 个。\n");
            return 1;
        }

        remain -= player;
        printf("你取了 %d 个，剩余 %d 个。\n", player, remain);
        if (remain <= 0) {
            printf("你取走了最后一个，你赢了。\n");
            break;
        }

        int computer = 3 - player;
        remain -= computer;
        printf("电脑取 %d 个，剩余 %d 个。\n", computer, remain);
        if (remain <= 0) {
            printf("电脑取走了最后一个，你输了。\n");
            break;
        }
    }

    return 0;
}
