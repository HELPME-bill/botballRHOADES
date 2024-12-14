void localizewhite()
{
    while(analog(1)>3000 || analog(0)>3000)
    {
        motor(0,50);
        motor(3,50);
        while(analog(1)>3000 && analog(0)<3000)
        {
            motor(0,0);
            motor(3,50);
        }
        while(analog(1)<3000 && analog(0)>3000)
        {
            motor(0,50);
            motor(3,0); 
        }
    }
}
