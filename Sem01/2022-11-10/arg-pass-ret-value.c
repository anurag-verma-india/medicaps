// Not in practical file
// Argument passed and return from a value

int checkPrimeNumber(int n);
int main()
{
    int n, flag;
    printf("Enter the integer");
    scanf("%d", &n);
    // n passed to the check Prime Number
    flag = checkPrimeNumber(n);
    if (flag == 1)
    {
        printf("%d is *not* prime number");
    } else {
        printf("%d is prime number");
    };
    return 0;
}

int checkPrimeNumber(int n)
{
    int i;
    if (n == 0 || n == 1) return 1;
    for (i == 2; i<=n/2; ++i)
    {
        if (n % i == 0)
        return 1;
    }
}