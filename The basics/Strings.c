#include <stdio.h>

// struct item
// {
//     char name[10];
//     int *value;
// };

    // Terminal fargeoutput med ANSI escape codes
    // start:
    // "\033[<n>m" hvor n = 30 (svart), 31 (rød), 32 (grønn), 33 (gul), 34 (blå), 35 (lilla), 36 (cyan), 37 (lys grå / hvit)
    // end:
    // "\033[<n>" hvor n = 0 (normal), 1 (bold), 4 (underline), 5 (blink), 7 (reverse)
    // eksempel grønn: "\033[0;32m"
    // char colors[5][10] = {
    //     {"gray"},
    //     {"cyan"},
    //     {"black"},
    //     {"magenta"},
    //     {"green"}
    // };

    // struct item colors[] =
    // {
    //     {"gray", 0},
    //     {"cyan", 1},
    //     {"black", 2},
    //     {"magenta", 3},
    //     {"green", 4}
    // };

    // char flight_gray_start[] = "\033[0;37m";
    // char flight_gray_end[] = "\033[0m";

    // char fblack_start[] = "\033[0;30m";
    // char fblack_end[] = "\033[0m";

    // char fgreen_start[] = "\033[0;32m";
    // char fgreen_end[] = "\033[0m";

    // char fcyan_start[] = "\033[0;36m";
    // char fcyan_end[] = "\033[0m";

    // char fmagenta_start[] = "\033[0;35m";
    // char fmagenta_end[] = "\033[0m";


int main()
{
    char color[7][10] = {
        {"\033[0;37m"}, // 0 = gray
        {"\033[0;36m"}, // 1 = cyan
        {"\033[0;30m"}, // 2 = black
        {"\033[0;35m"}, // 3 = magenta
        {"\033[0;32m"}, // 4 = green
        {"\033[0;34m"}, // 5 = blue
        {"\033[0;31m"}  // 6 = red
    };

    char cEnd[] = "\033[0m";
    
    // Bold text = "\033[1m;0m"
    
    printf("\n---------------------********************-----------------------\n");
    printf("\n\tConvert a character to its ASCII representation\n");
     
    printf("\n---------------------********************-----------------------\n");
    printf("\n   %sWritten with the%s      %s█████████%s    \n", color[2], cEnd, color[1], cEnd);
    printf("                        %s███%s%s░░░░░%s%s███   \n", color[1], cEnd, color[5], cEnd, color[1]);
    printf("                       ███%s     %s░░░    \n", cEnd, color[5]);
    printf("                      ░%s%s███%s            \n", cEnd, color[1], cEnd);
    printf("                      %s░%s%s███%s            \n", color[5], cEnd, color[1], cEnd);
    printf("                      %s░░%s%s███     ███%s   \n", color[5], cEnd, color[1], cEnd);
    printf("                       %s░░%s%s█████████%s    \n", color[5], cEnd, color[1], cEnd);
    printf("                        %s░░░░░░░░░%s         %sprogramming language%s  \n\n", color[5], cEnd, color[2], cEnd);
    printf("---------------------********************-----------------------\n\n");
    
    char c;
    printf("%s[i]%s Enter a character: ", color[5], cEnd);
    scanf("%c", &c);
    printf("%s[i]%s The ascii representation of %c is\n", color[5], cEnd, c); //%s\t%d%s\n\n", color[5], cEnd, c, fgreen_start, c, fgreen_end);
    printf("<------------------ ┌        ────────      ┐ ------------------>\n\n");
    printf("<------------------ | >         %s%d%s       < | ------------------>\n\n", color[4], c, cEnd);
    printf("<------------------ └        ────────      ┘ ------------------>\n\n");
    
    printf("\nThanks for using this freemium software. \n");
    printf("%s[!]%s You have %s0%s credits left, please buy more credits\n", color[6], cEnd, color[6], cEnd);
    printf("%s[!]%s to continue using this software by contacting Kevin\n\n", color[6], cEnd, color[6], cEnd);

    return 0;
}