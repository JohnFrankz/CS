// #include <stdio.h>

// char buffer[200];
// int i, j;
// double fp;
// char *s = "baltimore";
// char c;

// int main(void)
// {
//    c = 'l';
//    i = 35;
//    fp = 1.7320508;

//    /* Format and print various data */
// //    j = snprintf(buffer, 6, "%s\n", s);
//    j = snprintf(buffer, 6, "%c\n", c);
// //    j += snprintf(buffer+j, 6, "%d\n", i);
//    j += snprintf(buffer+j, 6, "%f\n", fp);
//    printf("string:\n%s\ncharacter count = %d\n", buffer, j);
// }


// C program to demonstrate snprintf()
#include <stdio.h>
 
int main()
{
    char buffer[50];
   
    // join two or more strings
    char* str1 = "quick";
    char* str2 = "brown";
    char* str3 = "lazy";
    int max_len = sizeof buffer;
 
    int j = snprintf(buffer, max_len,
                 "The %s %s fox jumped over the %s dog.",
                 str1, str2, str3);
    printf("\nThe number of bytes printed to 'buffer' "
           "(excluding the null terminator) is %d\n",
           j);
    if (j >= max_len)
        fputs("Buffer length exceeded; string truncated",
              stderr);
    puts("Joined string:");
    puts(buffer);
 
    return 0;
}