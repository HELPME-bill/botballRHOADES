#include <kipr/wombat.h>
void wait(int x);
int thresh0 =3300;
int thresh1=3300;
void localizeblack();
void localizewhite();
void localize();
int main()
{

    int servo= get_servo_position(3);
    enable_servos();

    void uservo(int x) 
    {
        int servo = get_servo_position(x);
        while (servo<1480)
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




            motor(0,100);
            motor(3,100);
            msleep(700);

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
    msleep(790);



    while (i<13)
    {

        while (digital(9)==0)
        {
            motor(0,41);
            motor(3,37);

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

    motor(0,41);
    motor(3,41);
    msleep(100);



    while (analog(0)<thresh0)
    {
        motor(0,10);
        motor(3,70);
    }

    while (analog(0)>thresh0)
    {
        break;
    }

    for(i=1;i<4;i++)

    {

        while (analog(0)>thresh0)
        {
            motor(0,70);
            motor(3,0);
        }

        while (analog(0)<thresh0)
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
    msleep(750);



    motor(0,70);
    motor(3,45);
    msleep(1000);

    motor(0,100);
    motor(3,100);
    msleep(200);

    //goes back

    motor(0,-70);
    motor(3,-70);
    msleep(1200);


    freeze(0);
    freeze(3);

    uservo(3);

    motor(0,-90);
    motor(3,90);
    msleep(200);
    motor(0,0);
    motor(3,90);
    msleep(800);

    motor(0,70);
    motor(3,75);
    msleep(1200);

    wait(200);


    motor(0,-70);
    motor(3,70);
    msleep(1100);


    motor(0,90);
    motor(3,100);
    msleep(1900);

    motor(0,90);
    motor(3,-50);
    msleep(700);
    
    motor(0,90);
    motor(3,90);
    msleep(650);
    i=1;
    
    

    while (analog(0)<thresh0)
    {

        if(digital(9)==0)
        {
            motor(0,72);
            motor(3,57);

        }

        if(digital(9)==1)
        {
            motor(0,20);
            motor(3,90);
            msleep(170);
            motor(0,30);
            motor(3,50);

        }

        i++;

    }

    while (analog(0)>thresh0)
    {
        freeze(0);
        freeze(3);
        wait(5000);

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

    //scanning
    scandeeznuts();


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


    while (analog(1)<thresh1)
    {

        if(digital(0)==0)
        {
            motor(0,52);
            motor(3,0);

        }

        if(digital(0)==1)
        {
            motor(0,30);
            motor(3,90);
            msleep(170);
            motor(0,0);
            motor(3,50);

        }

        i++;
        
    }

    while (analog(1)<thresh1)
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
    while(analog(1)<thresh1 || analog(0)<thresh0)
    {
        motor(0,50);
        motor(3,50);
        while(analog(1)<thresh1 && analog(0)>thresh0)
        {
            motor(0,0);
            motor(3,50);
        }
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            motor(0,50);
            motor(3,0); 
        }
    }
}

void localizewhite()
{
    while(analog(1)>thresh1 || analog(0)>thresh0)
    {
        motor(0,50);
        motor(3,50);
        while(analog(1)>thresh1 && analog(0)<thresh0)
        {
            motor(0,0);
            motor(3,50);
        }
        while(analog(1)<thresh1 && analog(0)>thresh0)
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

