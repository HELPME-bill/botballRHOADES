#include <kipr/wombat.h>
void dservo(int x);
void uservo(int x);
void wait(int x);
void ud();
int main()
{
    motor(0,85);
    motor(3,100);
    msleep(2050);

    /*enable_servos();

    void scandeeznuts()
    {

        int x=2;
        int i;




        for(int y=1;y<3;y++)
        {

            for(i=1;i<x;i++)
            {


                motor(0,-100);
                motor(3,0);
                msleep(250);
                ud(3);
            }
            i=0;
            motor(0,100);
            motor(3,100);
            msleep(450);

            for(i=1;i<x;i++)
            {


                motor(0,0);
                motor(3,-100);
                msleep(250);
                ud(3);
            }


            i=0;
            x++;

        } 


    motor(0,100);
    motor(3,100);
    msleep(700);
    disable_servos();
    }

    scandeeznuts();*/





    return 0;
}

void wait(int x)
{
    motor(0,0);
    motor(3,0);
    msleep(x);
}
void dservo(int x) 
{
    enable_servo(x);
    int servo = get_servo_position(x);
    while (servo>1070)
    {
        wait(1);
        set_servo_position(x,servo);
        msleep(1);
        servo=servo-1;
    }

    while (servo<1070)
    {
        break;
    }

}

void uservo(int x) 
{
    int servo = 1120;
    while (servo<1400)
    {
        wait(1);
        set_servo_position(x,servo);
        msleep(1);
        servo++;
    }



}

void ud(int x)
{
    freeze(0);
    freeze(3);
    dservo(x);
    freeze(0);
    freeze(3);
    wait(100);
    uservo(x);
    freeze(0);
    freeze(3);

}

