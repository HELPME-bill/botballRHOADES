
#include <kipr/wombat.h>

void localize();

int main()
{

    enable_servos();
    set_servo_position(3,1474);
    msleep(500);
    disable_servos();
    motor(3,-75);
    motor(0,75);
    msleep(1000);
    localize();
    
    while (digital(9)==0)
    {
       
        motor(0,49);
        motor(3,38);
    }
    while (digital(9)==1)
    {
        motor(0,0);
        motor(3,70);
    }
    while (analog(1)<3300)
    {
        if (digital(9)==1)
        {
            motor(3,70);
            motor(0,0);
        }
        else if(digital(9)==0)
        {
            motor(0,50);
            motor(3,0);
        }
    }






    motor(3,75);
    motor(0,75);
    msleep(500);
    if (analog(1)<3300)
    {
        motor(3,90);
        motor(0,20);
    }
    else if (analog(1)>3300)
    {
        motor(0,0);
        motor(3,0);
    }
    
    enable_servos();
    set_servo_position(3,1200);
    msleep(500);
    disable_servos();
    motor(3,50);
    motor(0,50);
    msleep(800);
    motor(0,50);
    motor(3,0);
    msleep(600);
    motor(3,50);
    motor(0,50);
    msleep(350);
    motor(0,39);
    motor(3,0);
    msleep(700);
    motor(3,35);
    motor(0,35);
    msleep(500);
    motor(0,50);
    motor(3,0);
    msleep(1000);
    motor(0,50);
    motor(3,50);
    msleep(100);
    motor(0,-50);
    motor(3,-50);
    msleep(1600);
    motor(3,0);
    motor(0,50);
    msleep(250);
    enable_servos();
    set_servo_position(3,1474);
    msleep(500);
    disable_servos();
    motor(3,-75);
    motor(0,-75);
    msleep(1250);
    motor(3,75);
    motor(0,-75);
    msleep(1500);
    localize();
        
   
    
    
        










    return 0;

}

void localize()
{
    while((analog(1)<3300) || (analog(0)<3300))
    {
        if ((analog(1)<3300) && (analog(0)>3300))
        {
            motor(0,0);
            motor(3,30);
        }
        else if ((analog(1)>3300) && (analog(0)<3300))
        {
            motor(3,0);
            motor(0,30);
        }
        else
        {
            motor(3,30);
            motor(0,30);
        }
    }
    while((analog(1)>3300) || (analog(0)>3300))
    {
        if ((analog(1)>3300) && (analog(0)<3300))
        {
            motor(0,0);
            motor(3,75);
        }
        else if ((analog(1)<3300) && (analog(0)>3300))
        {
            motor(3,0);
            motor(0,75);
        }
        else
        {
            motor(3,75);
            motor(0,75);
        }
    }
}


