#include <kipr/wombat.h>
void wait(int x);
int thresh0 =3300;
int thresh1=3300;
void localizeblack();
void localizewhite();
void localize();
int main()
{


    enable_servos();
    
    void shakey()
    {
        for(int v=0;v<9;v++)
        {
            baasbennaguui(0,-100);
            motor(3,0);
            msleep(70); 
            motor(0,100);
            motor(3,0);
            msleep(70); 

        }
    }

    void uservo(int x) 
    {
        int servo = get_servo_position(x);
        while (servo<1580)
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
        while (servo>1230)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo=servo-1;
        }
        while (servo<1230)
        {

            break;
        }
    }
    
     void mdservo(int x) 
    {
        enable_servo(x);
        int servo = get_servo_position(x);
        while (servo>1470)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo=servo-1;
        }
        while (servo<1470)
        {

            break;
        }
    }
    
     void gdservo(int x) 
    {
        enable_servo(x);
        int servo = get_servo_position(x);
        while (servo>1180)
        {
            wait(1);
            set_servo_position(x,servo);
            msleep(1);
            servo=servo-1;
        }
        while (servo<1180)
        {

            break;
        }
    }



    void ud(int x)
    {
        freeze(0);
        freeze(3);
        dservo(x);
        freeze(0);
        freeze(3);
        shakey();
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
                msleep(220);
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
                msleep(220);
                ud(3);
            }


            i=0;
            x++;




            motor(0,100);
            motor(3,100);
            msleep(700);

        }
    }
    
    



    set_servo_position(3,1480);
    msleep(1000);

    set_servo_position(2,1840);
    msleep(1000);

    motor(0,100);
    motor(3,-100);
    msleep(790);

    int i;

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

    for(i=1;i<5;i++)

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
    msleep(500);



    motor(0,70);
    motor(3,35);
    msleep(700);

    motor(0,85);
    motor(3,100);
    msleep(400);
    
    

    //goes back

   

    motor(0,-60);
    motor(3,-70);
    msleep(1200);


    freeze(0);
    freeze(3);

    uservo(3);




    motor(0,-70);
    motor(3,-70);
    msleep(2100);

    localize();

    motor(0,-70);
    motor(3,-80);
    msleep(1400);



    motor(0,0);
    motor(3,100);
    msleep(1400);

    for(i=0;i<4;i++)
    {
        while(analog(1)<thresh1)
        {
            motor(0,85);
            motor(3,85);
        }

        while(analog(1)<thresh1)
        {
            motor(0,65);
            motor(3,85);
        }

    }



    motor(0,0);
    motor(3,40);
    msleep(1000);

    motor(0,80);
    motor(3,90);
    msleep(900);


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
            msleep(270);
            motor(0,30);
            motor(3,50);

        }

        i++;

    }

    while (analog(0)>thresh0)
    {
        freeze(0);
        freeze(3);
        wait(50);
        localize();

        break;
    }







    wait(50);
    motor(0,0);
    motor(3,90);
    msleep(420);
    motor(0,90);
    motor(3,90);
    msleep(620);



    motor(0,0);
    motor(3,-90);
    msleep(420);

    //edit distance here

    motor(0,-90);
    motor(3,-90);
    msleep(1050); //was 920
    //

    motor(0,0);
    motor(3,-90);
    msleep(1300);

    motor(0,30);
    motor(3,40);
    msleep(700);


    motor(0,80);
    motor(3,90);
    msleep(800);

    motor(0,-10);
    motor(3,-10);
    msleep(800);

    //downup
    
    //rishibh strat

    gdservo(3);
   
    motor(0,0);
    motor(3,-100);
    msleep(300);
    shakey();
    uservo(3);
    motor(0,100);
    motor(3,100);
    msleep(800);
    //

    //scanning
    scandeeznuts();


    //

    motor(0,-50);
    motor(3,-60);
    msleep(400);

    motor(0,-90);
    motor(3,100);
    msleep(840);

    motor(0,100);
    motor(3,100);
    msleep(1980);

    set_servo_position(2,265);
    msleep(700);

    motor(0,100);
    motor(3,90);
    msleep(1180);



    //linefollowx2

    /* int i;
    for (i=0;i<9;i++)
    {

        while (analog(0)<thresh0)
        {

            if(digital(9)==0)
            {
                motor(0,52);
                motor(3,30);

            }

            if(digital(9)==1)
            {
                break;

                motor(0,10);
                motor(3,50);
                msleep(300);
                motor(0,-10);
                motor(3,50);

            }

            i++;

        }
    }

    while (analog(0)<thresh0)
    {
        set_servo_position(2,1845);
        msleep(700);

        break;
    }


    motor(0,-80);
    motor(3,-90);
    msleep(1390);


    localize();

    motor(0,-80);
    motor(3,-90);
    msleep(1090);*/

    //moves cubes

    motor(0,-42);
    motor(3,0);
    msleep(390);

    motor(0,85);
    motor(3,85);
    msleep(790);

    motor(0,75);
    motor(3,85);
    msleep(1090);

    for(i=0;i<7;i++)
    {
        while(analog(1)<thresh1)
        {
            motor(0,85);
            motor(3,85);
        }

        while(analog(1)<thresh1)
        {
            motor(0,65);
            motor(3,85);
        }

    }
    mdservo(3);
    set_servo_position(2,1840);
    msleep(700);
    
    motor(0,75);
    motor(3,85);
    msleep(2090);
    
    
    motor(0,75);
    motor(3,5);
    msleep(1569);
    
    dservo(3);
    shakey();
    /*


    motor(0,-75);
    motor(3,85);
    msleep(1000);

    motor(0,75);
    motor(3,85);
    msleep(1000);

    motor(0,0);
    motor(3,-85);
    msleep(1000);




    motor(0,0);
    motor(3,-85);
    msleep(700);

    motor(0,75);
    motor(3,-85);
    msleep(700);

    localize();

    dservo(3);*/





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

