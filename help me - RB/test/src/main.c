#include <kipr/wombat.h>

int main()
{
    motor(0, 70);
    motor(3, 80);
    msleep(5000);
    return 0;
}
