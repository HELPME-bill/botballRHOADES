#include <kipr/wombat.h>
#include<stdbool.h>
void SSU(int port, int time, int final);
void dig(double time);
void ud(int x);
bool try1;
bool try3;
double timerecord1;
int main()
{	
    //wait_for_light(5);
    shut_down_in(119);
    int thresh0 = 3400;
    int thresh1 = 3400;
    SSU(3, 560, 1480);
    motor(0,75);
    motor(3,-75);
    msleep(1000);
    while(analog(1)<thresh1)
    {
        if(digital(9)==0)
        {
            motor(0,70);
            motor(3,66);
        }
        else
        {
            motor(0,0);
            motor(3,70);
        }
    }
    while(analog(1)>thresh1)
    {
        if(digital(9)==0)
        {
            motor(0,70);
            motor(3,66);
        }
        else
        {
            motor(0,0);
            motor(3,70);
        }
    }
    while(analog(1)<thresh1)
    {
        if(digital(9)==0)
        {
            motor(0,70);
            motor(3,66);
        }
        else
        {
            motor(0,0);
            motor(3,70);
        }
    }
    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,80);
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
        motor(0,70);
        motor(3,80);
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
    for(int r=1;r<4;r++)

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
    while (analog(0)>thresh0)
    {
        motor(0,70);
        motor(3,0);
    }
    motor(0,0);
    motor(3,50);
    msleep(225);

    freeze(0);
    freeze(3);
    SSU(3, 500, 1100);
    msleep(1000);





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
    /*motor(0,25);
    motor(3,0);
    msleep(400);
    motor(0,30);
    motor(3,40);
    msleep(700);
    motor(0,25);
    motor(3,0);
    msleep(1220);*/
    freeze(0);
    freeze(3);
    SSU(3,500,1500);

    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,-70);
        motor(3,-80);
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
        motor(0,-70);
        motor(3,-80);
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
    motor(0, -70);
    motor(3,-80);
    msleep(1200);
    motor(0,0);
    motor(3,70);
    msleep(2300);
    motor(0,85);
    motor(3,95);
    msleep(1400);
    while(analog(0)<thresh1)
    {
        if(digital(9)==0)
        {
            motor(0,70);
            motor(3,66);
        }
        else
        {
            motor(0,0);
            motor(3,70);
        }
    }

    while(analog(0)<thresh0 || analog(1)<thresh1)
    {
        motor(0,70);
        motor(3,80);
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
        motor(0,70);
        motor(3,80);
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


    motor(3, 40);
    motor(0,0);
    msleep(700);
    motor(0, 50);
    motor(3,60);
    msleep(1100);
    motor(3,0);
    motor(0,30);
    msleep(650);
    /*for(int y=1;y<3;y++)
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

    } */
    // code comb
    motor(0,-50);
    motor(3,-60);
    msleep(900);
    int x = 2;
    int i;
    SSU(3, 560, 1480);
    SSU(2, 1500, 1845);
    double timerecord4 = seconds();
    bool try4 = true;
    while(try4 == true)
    {
        if(seconds() - timerecord4 < 1.75)
        {
            if(analog(0)<thresh0 || analog(1)<thresh1)
            {
                motor(0,-70);
                motor(3,-80);
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
            if(analog(0)>thresh0 || analog(1)>thresh1)
            {
                motor(0,-70);
                motor(3,-80);
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
        }
        else
        {
            while(analog(0)<thresh0 || analog(1)<thresh1)
            {
                motor(0,70);
                motor(3,80);
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
            try4 = false;
        } 
    }

    motor(0,0);
    motor(3,-90);
    msleep(1975);
    motor(0,70);
    motor(3,80);
    msleep(1000);
    freeze(0);
    freeze(3);
    SSU(3, 1000, 1050);

    for(int y=1;y<3;y++)
    {

        for(i=1;i<x;i++)
        {


            motor(0,0);
            motor(3,-50);
            msleep(500);
            ud(3);
        }
        i=0;
        motor(0,100);
        motor(3,100);
        msleep(450);

        for(i=1;i<x;i++)
        {


            motor(0,-50);
            motor(3,0);
            msleep(500);
            ud(3);
        }


        i=0;
        x++;




        motor(0,100);
        motor(3,100);
        msleep(1000);

    }


    motor(0,-70);
    motor(3,-80);
    msleep(600);
    motor(0,-75);
    motor(3,85);
    msleep(900);
    double timerecord3 = seconds();
    while(seconds() - timerecord3 < 2.75)
    {
        if(digital(9)==0)
        {
            motor(0,90);
            motor(3,98);
        }
        else
        {
            motor(0,88);
            motor(3,100);
        }
    }
    freeze(0);
    freeze(3);
    SSU(2, 1600, 265);
    timerecord3 = seconds();
    while(seconds() - timerecord3 < 0.1)
    {
        if(digital(9)==0)
        {
            motor(0,100);
            motor(3,90);
        }
        else
        {
            motor(0,90);
            motor(3,100);
        }
    }
    motor(3,30);
    motor(0,0);
    msleep(500);
    motor(0,50);
    motor(3,60);
    msleep(800);
    timerecord3 = seconds();
    while(seconds() - timerecord3 < 0.75)
    {
        if(analog(1)<thresh1)
        {
            motor(0,10);
            motor(3,70);
        }
        else
        {
            motor(3,10);
            motor(0, 60);
        }
    }
    motor(0, 30);
    motor(3,40);
    msleep(800);
    freeze(0);
    freeze(3);
    SSU(2, 1500, 1845);
    timerecord3 = seconds();
    while(seconds() - timerecord3 < 5)
    {
        if(analog(1)>thresh1)
        {
            motor(0,10);
            motor(3,70);
        }
        else
        {
            motor(3,10);
            motor(0, 60);
        }
    }
    freeze(0);
    freeze(3);
    SSU(3, 500, 1085);
    motor(0, 70);
    motor(3, -80);
    msleep(1000);
    freeze(0);
    freeze(3);
    SSU(3, 100, 1050);




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
void ud(int x)
{
    freeze(0);
    freeze(3);
    SSU(x, 1000, 1050);
    freeze(0);
    freeze(3);
    motor(0, 0);
    motor(3,0);
    msleep(100);
    for(int a = 0; a<8; a++)
    {
        motor(0,80);
        motor(3,0);
        msleep(80);
        motor(0,-80);
        motor(3,0);
        msleep(80);
    }
    freeze(0);
    freeze(3);
    SSU(x, 1000, 1480);
    freeze(0);
    freeze(3);

}

