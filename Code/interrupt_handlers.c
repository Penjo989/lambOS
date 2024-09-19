

void Reset_Handler()
{
    _start:
    int a = 0;
    a += 1;
    Reset_Handler();
}

void Default_Handler()
{
    Default_Handler();
}

int main()
{
    return;
}