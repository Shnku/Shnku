int no_of_digit(int n)
{
    int rem, i = 0, len = 0;
    char arr[10];
    while (rem)
    {
        rem = n % 10;
        arr[i++] = rem;
        n = n / 10;
    }
    arr[i] = '\0';
    while (*arr)
    {
        len++;
        (*arr)++;
    }
    return len;
}
