#include <kipr/wombat.h>
void wait(int x);
void localizeblack();
void localizewhite();
int main()
{
    enable_servos();
    void uservo(int x) 
    {
        int servo = get_servo_position(x);
        while (servo<1400)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo++;
        }
    }

    void dservo(int x) 
    {
        enable_servo(x);
        int servo = get_servo_position(x);
        while (servo>1150)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo=servo-1;
        }

        while (servo<1150)
        {
            break;
        }
       

    }

    set_servo_position(3,1400);
    int i=1;
    motor(0,100);
    motor(3,-100);
    msleep(870);

    

    while (i<3)
    {

        while (digital(9)==0)
        {
            motor(0,41);
            motor(3,41);

        }

        while (digital(9)==1)
        {
            motor(0,0);
            motor(3,70);

        }

        i++; 
    }

    localizeblack();
    localizewhite();

    while (analog(0)<3350)
    {
        motor(0,10);
        motor(3,70);
    }

    while (analog(0)>3350)
    {
        break;
    }

    for(i=1;i<4;i++)

    {

        while (analog(0)>3350)
        {
            motor(0,70);
            motor(3,0);
        }

        while (analog(0)<3350)
        {
            motor(0,20);
            motor(3,70);
        }
    }

    
    motor(0,0);
    motor(3,-50);
    msleep(200);

    wait(1);

    dservo(3);
    msleep(1000);

    
    motor(0,70);
    motor(3,70);
    msleep(700);
    


    motor(0,70);
    motor(3,50);
    msleep(1300);

    motor(0,100);
    motor(3,100);
    msleep(200);

    //goes back

    motor(0,-70);
    motor(3,-70);
    msleep(1000);


    freeze(0);
    freeze(3);

    uservo(3);

    motor(0,-90);
    motor(3,90);
    msleep(300);
    motor(0,0);
    motor(3,90);
    msleep(600);

    motor(0,70);
    motor(3,75);
    msleep(1200);

    wait(200);


    motor(0,-70);
    motor(3,70);
    msleep(1200);

    motor(0,100);
    motor(3,100);
    msleep(1900);

    motor(0,70);
    motor(3,-50);
    msleep(900);
    i=1;

    while (analog(0)<2700)
    {

        while (digital(9)==0)
        {
            motor(0,70);
            motor(3,50);

        }

        while (digital(9)==1)
        {
            motor(0,40);
            motor(3,80);
            msleep(400);
            motor(0,40);
            motor(3,50);

        }

        i++;
        printf("i= %d", i);
    }

    while (analog(0)<2700)
    {
        break;
    }

    wait(50);
    
    motor(0,-40);
    motor(3,-40);
    msleep(1000);

    motor(0,0);
    motor(3,-90);
    msleep(1400);

    motor(0,40);
    motor(3,40);
    msleep(700);

    motor(0,40);
    motor(3,0);
    msleep(600);

    wait(50);

    set_servo_position(3,1040);
    msleep(1000);

    wait(100);

    set_servo_position(3,1370);
    msleep(1000);
    
   // goes back from poms
    
    motor(0,-40);
    motor(3,-40);
    msleep(800);
    
    motor(0,90);
    motor(3,90);
    msleep(800);
    
    //linefollow x2
    
    while (analog(1)<2700)
    {

        while (digital(9)==0)
        {
            motor(0,70);
            motor(3,50);

        }

        while (digital(9)==1)
        {
            motor(0,40);
            motor(3,80);
            msleep(400);
            motor(0,40);
            motor(3,50);

        }

        i++;
        printf("i= %d", i);
    }

    while (analog(0)<2700)
    {
        break;
    }


    disable_servos();

    return 0;
}

void localizeblack()
{
    while(analog(1)<3350 || analog(0)<3000)
    {
        motor(0,50);
        motor(3,50);
        while(analog(1)<3350 && analog(0)>3000)
        {
            motor(0,0);
            motor(3,50);
        }
        while(analog(1)>3350 && analog(0)<3000)
        {
            motor(0,50);
            motor(3,0); 
        }
    }
}

void localizewhite()
{
    while(analog(1)>3350 || analog(0)>3000)
    {
        motor(0,50);
        motor(3,50);
        while(analog(1)>3350 && analog(0)<3000)
        {
            motor(0,0);
            motor(3,50);
        }
        while(analog(1)<3350 && analog(0)>3000)
        {
            motor(0,50);
            motor(3,0); 
        }
    }
}

void wait(x)
    int x;
{
    motor(0,0);
    motor(3,0);
    msleep(x);
}

