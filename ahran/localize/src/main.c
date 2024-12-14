#include <kipr/wombat.h>
#include <local.h>
#include <localwhite.h>
#include <wait.h>
void localizeblack();
void localizewhite();
int main()
{
    enable_servos;
    msleep(100);
    set_servo_position(0,1500);
    motor(0,100);
    motor(3,-100);
    msleep(900);
    localizeblack();
    localizewhite();
    motor(0,850);
    motor(3,100);
    msleep(1950);
    localizeblack();
    localizewhite();
    motor(0,20);
    motor(3,20);
    msleep(550);
    for(int i=1;i<3;i++)
    {
        while(analog(0)>3000)
        {
            motor(0,60);
            motor(3,0);
        }
        while(analog(0)<3000)
        {
            motor(0,0);
            motor(3,60);
        }
    }
    freeze(0);
    freeze(3);
    
    set_servo_position(0,1211);
    motor(0,0);
    motor(3,-30);
    msleep(900);
    motor(0,70);
    motor(3,70);
    msleep(1000);
    motor(0,-10);
    motor(3,-100);
    msleep(1000);
    motor(0,100);
    motor(3,100);
    msleep(800);
    motor(0,-100);
    motor(3,-20);
    msleep(800);
    motor(0,100);
    motor(3,100);
    msleep(900);
    motor(0,0);
    motor(3,-100);
    msleep(500);
    
    motor(0,-70);
    motor(3,-70);
    msleep(500);
    motor(0,0);
    motor(3,70);
    msleep(300);
    motor(0,20);
    motor(3,70);
    msleep(1500);
    motor(0,-80);
    motor(3,-20);
    msleep(500);
    motor(0,-40);
    motor(3,-40);
    msleep(850);
    localizeblack();
    localizewhite();
    motor(0,100);
    motor(3,100);
    msleep(900);
    motor(0,20);
    motor(3,-20);
    msleep(500);
    motor(0,20);
    motor(3,20);
    msleep(700);
    motor(0,-100);
    motor(3,100);
    msleep(700);
    localizeblack();
    localizewhite();
    motor(0,100);
    motor(3,100);
    msleep(1050);
    motor(0,100);
    motor(3,-100);
    msleep(700);

    while (analog(0)<2900 || analog(1)<2900)
    {

        while(analog(1)>2900)
        {
            motor(3,90);
            motor(0,10);
        }
        while(analog(1)<2900)
        {
            motor(3,50);
            motor(0,90);
        }
    }
    motor(0,80);
    motor(3,0);
    msleep(500);
    motor(0,-100);
    motor(3,-100);
    msleep(900);
    motor(0,-90);
    motor(3,90);
    msleep(200);
    localizeblack();
    localizewhite();
    motor(0,100);
    motor(3,100);
    msleep(2700);
    motor(0,100);
    motor(3,-100);
    msleep(700);
    localizeblack();
    localizewhite();
    
    
    return 0;
}
