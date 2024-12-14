void wait(x)
    int x;
{
    motor(0,0);
    motor(3,0);
    msleep(x);
}