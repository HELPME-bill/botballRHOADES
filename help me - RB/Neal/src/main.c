#include <kipr/wombat.h>
#include<stdbool.h>
void SSU(int port, int time, int final);
void dig(double time);
bool try1;
bool try3;
double timerecord1;
int main()
{
    int thresh0 = 2100;
    int thresh1 = 2100;
    SSU(3, 560, 1480);
    motor(0,75);
    motor(3,-75);
    msleep(1000);
    motor(0,70);
    motor(3,70);
    msleep(800);
    while(analog(1)<thresh1)
    {
        if(digital(9)==0)
        {
            motor(0,70);
            motor(3,57);
        }
        else
        {
            motor(0,57);
            motor(3,70);
        }
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,70);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        else if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,70.15);
        motor(3,70);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,1);
            motor(3,30);
        }
        else if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,31);
            motor(3,0);
        }
    }
    while(analog(0)<thresh0)
    {
        motor(0,15);
        motor(3,50);
    }
    double timerecord2 = seconds();
    while(seconds() - timerecord2 <0.03)
    {
        if(analog(0)<thresh0)
        {
            motor(0,25);
            motor(3,75);
        }
        else
        {
            motor(0,75);
            motor(3,25);
        }
    }
    freeze(0);
    freeze(3);
    SSU(3, 500, 1050);
    while(analog(0)>thresh0)
    {
        motor(0,25);
        motor(3,0);
    }
    motor(0,25);
    motor(3,0);
    msleep(1000);
    motor(0,30);
    motor(3,30);
    msleep(3000);
    motor(3,-50);
    motor(0,-50);
    msleep(1000);
    freeze(0);
    freeze(3);
    SSU(3,500,1400);
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-70);
        motor(3,-70);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        else if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    while(analog(0)>thresh0 || analog(1)>thresh1)
    {
        motor(0,-70);
        motor(3,-70);
        if(analog(0)<thresh0 && analog(1)>thresh1)
        {
            motor(0,-1);
            motor(3,-30);
        }
        else if(analog(0)>thresh0 && analog(1)<thresh1)
        {
            motor(0,-31);
            motor(3,0);
        }
    }
    
    printf("Hi");
    motor(0,-70);
    motor(3,-70);
    msleep(800);
    motor(0,0);
    motor(3,70);
    msleep(1900);
    while(analog(0)<thresh0)
    {
        if(analog(1)<thresh1)
        {
            motor(0,70);
            motor(3,35);
        }
        else
        {
            motor(0,35);
            motor(3,70);
        }
    }

    return 0;
}
void dig(double time)
{
    try1 = true;
    timerecord1 = seconds();
    while(try1 == true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,70.5);
            motor(3,70);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,60);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,60);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= time)
        {
            printf("hey dummy try again stpid");
            motor(0,-71);
            motor(3,-70);
            msleep(300);
            try1=false;
        }

    }
    timerecord1 = seconds();
    try3 = true;
    while(try3==true)
    {
        if(digital(0)==0 || digital(1)==0)
        {
            motor(0,71);
            motor(3,70);
            if(digital(0)==1 && digital(1)==0)
            {
                motor(0,0);
                motor(3,60);
            }
            if(digital(0)==0 && digital(1)==1)
            {
                motor(0,60);
                motor(3,0);
            }
        }
        if(seconds() - timerecord1 >= (time/1.5)+0.5)
        {
            try3 = false;
        }


    }
}

void SSU(int port, int time, int final)
{
    enable_servo(port);
    int pos = get_servo_position(port);
    double mssleep;
    int distance;
    if(pos>final){
        distance = pos - final;
        mssleep = time/distance;
    }
    else if(pos<final){
        distance = final - pos;
        mssleep = time/distance;
    }
    while(pos<final)
    {
        pos+=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    while(pos>final)
    {
        pos-=1;
        set_servo_position(port, pos);
        msleep(mssleep);
    }
    disable_servo(port);
}

