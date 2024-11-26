#include <cstdio>
#include <string>

int main() {
    const char str[] = "How many characters does this string contain?";

    printf("without null character: %zu\n", strlen(str)); // 45
    printf("with null character:    %zu\n", sizeof(str)); // 46
}
