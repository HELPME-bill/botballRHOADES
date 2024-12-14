#include <kipr/wombat.h>
void wait(int x);
void localizeblack();
void localizewhite();
void localize();
int main()
{
    
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
        while (servo>1130)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo=servo-1;
        }




        while (servo<1130)
        {
            break;
        }


    }

    set_servo_position(3,1400);
    int i;

    //nhtdhtfjhnbhg jyjgbnvjnghtfgfghgjgjhmt

    motor(0,90);
    motor(3,100);
    msleep(1900);

    motor(0,90);
    motor(3,-50);
    msleep(900);
    i=1;

    while (analog(0)<2700)
    {

        while (digital(0)==0)
        {
            motor(0,52);
            motor(3,56);

        }

        while (digital(0)==1)
        {
            motor(0,30);
            motor(3,90);
            msleep(50);
            motor(0,30);
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

    motor(0,40);
    motor(3,90);
    msleep(400);

    motor(0,-30);
    motor(3,-75);
    msleep(1000);

    motor(0,0);
    motor(3,-90);
    msleep(1300);

    motor(0,30);
    motor(3,40);
    msleep(700);


    motor(0,80);
    motor(3,90);
    msleep(1100);

    motor(0,-10);
    motor(3,-20);
    msleep(500);

    //downup

    dservo(3);

    wait(200);

    uservo(3);

    motor(0,-40);
    motor(3,0);
    msleep(300);

    freeze(0);
    freeze(3);

    dservo(3);

    wait(10);

    uservo(3);

    //scanning
    i=1;





    motor(0,90);
    motor(3,100);
    msleep(300);



    motor(0,0);
    motor(3,-100);
    msleep(90);

    dservo(3);

    wait(1);

    uservo(3);

    i++;


    motor(0,90);
    motor(3,100);
    msleep(600);

    motor(0,0);
    motor(3,-100);
    msleep(470);

    dservo(3);

    wait(1);

    uservo(3);





    //

    motor(0,-50);
    motor(3,-60);
    msleep(800);

    motor(0,-90);
    motor(3,100);
    msleep(840);

    motor(0,90);
    motor(3,100);
    msleep(1280);

    //linefollowx2


    while (analog(1)<3300)
    {

        if(digital(0)==0)
        {
            motor(0,52);
            motor(3,50);

        }

        if(digital(0)==1)
        {
            motor(0,30);
            motor(3,90);
            msleep(50);
            motor(0,30);
            motor(3,50);

        }

        i++;
        printf("i= %d", i);
    }

    while (analog(1)<3300)
    {
        break;
    }

    motor(0,-80);
    motor(3,-90);
    msleep(1390);
    
    localize();
    
    motor(0,-80);
    motor(3,-90);
    msleep(1090);


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

void localize()
{
    localizeblack();
    localizewhite();



}

