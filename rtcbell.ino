
#include <EEPROM.h>
#include <Wire.h>
#include <RealTimeClockDS1307.h>
#include <LiquidCrystal.h>
int x,y,z,m;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(8, 2);
  pinMode(6,INPUT);  // put your setup code here, to run once:
 pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(10,OUTPUT);
   pinMode(13,OUTPUT);
}

void loop() {
  top:
  int day=RTC.getDayOfWeek();
  
  lcd.clear();
  lcd.print("welcome");
  delay(1000);
  int mode=EEPROM.read(0);
  if(mode==0&&day!=6)
  {
    
  EEPROM.write(1023,1);
  }
  else if(mode==0&&day==6)
  {
   EEPROM.write(1023,2);
  }
  else if(mode==1&&day!=6)
  {
    EEPROM.write(1023,3);
  }
  else if(mode==1&&day==6)
  {
    EEPROM.write(1023,4);
  }





  //set modes
  if(digitalRead(6))
  {x:
    int i=0;
    while(digitalRead(6))
    {
      i=i+1000;
      lcd.clear();
      
      if(i>5000)
      lcd.print("Edit mode");
       delay(1000);
    }


    while(i<5000)
    {
      int mode=EEPROM.read(0);
      lcd.clear();
      lcd.print("mode: ");
            lcd.print(mode);
            delay(60);

            if(digitalRead(7)){
            while(digitalRead(7));
            mode=!mode;
            EEPROM.write(0,mode);
            }
            delay(60);

        if(digitalRead(6))
        {while(digitalRead(6));
          goto top;
        }

    }

//edit values
    while(i>5000)
    {int rmode=1;
    while(1){
      t:
      delay(60);
      lcd.clear();
      if(rmode==5)
      {lcd.print("Edit time");goto r;
      }
      lcd.print("Rmode: ");
      lcd.print(rmode);r:
      if(digitalRead(7))
      {
        while(digitalRead(7));
        rmode++;
        if(rmode>5)
        rmode=1;
          
          
          
        
      }

      if(digitalRead(6))
      {while(digitalRead(6));
      
        switch(rmode)
        {
   case 1:
          m=1;x=1;y=2;z=3;
          while(1){
            lcd.clear();
            lcd.print(m);
            lcd.print("  ");
            lcd.print(EEPROM.read(x));
            lcd.print(":");
            lcd.print(EEPROM.read(y));
            //lcd.setCursor(0, 1);
            lcd.print(":");
            lcd.print(EEPROM.read(z));
            delay(30);
            
              int p1=map(analogRead(A0),0,800,0,24);
              EEPROM.write(x,p1);
              int p2=map(analogRead(A1),0,800,0,59);
              EEPROM.write(y,p2);
              int p3=map(analogRead(A2),0,800,0,20);
              EEPROM.write(z,p3);
              if(digitalRead(7)){
              while(digitalRead(7));
              x=x+3;y=y+3;z=z+3;m++;
              if(m>20)
              {x=1;y=2;z=3;m=1;}
              }
              if(digitalRead(6)){
              while(digitalRead(6));
              goto t;
              }
              
              
              }
case 2:
        
          m=1;x=70;y=71;z=72;
          while(1){
            lcd.clear();
            lcd.print(m);
            lcd.print("  ");
            lcd.print(EEPROM.read(x));
            lcd.print(":");
            lcd.print(EEPROM.read(y));
               lcd.setCursor(0, 1);
            lcd.print(":");
            lcd.print(EEPROM.read(z));
            delay(30);
            
              int p1=map(analogRead(A0),0,800,0,24);
              EEPROM.write(x,p1);
              int p2=map(analogRead(A1),0,800,0,59);
              EEPROM.write(y,p2);
              int p3=map(analogRead(A2),0,800,0,20);
              EEPROM.write(z,p3);
              if(digitalRead(7)){
              while(digitalRead(7));
              x=x+3;y=y+3;z=z+3;m++;
              if(m>20)
              {x=1;y=2;z=3;m=1;}
              }
              if(digitalRead(6)){
              while(digitalRead(6));
              goto t;
              }
              
              
              }

case 3:
          m=1;x=133;y=134;z=135;
          while(1){
            lcd.clear();
            lcd.print(m);
            lcd.print("  ");
            lcd.print(EEPROM.read(x));
            lcd.print(":");
            lcd.print(EEPROM.read(y));
              lcd.setCursor(0, 1);
            lcd.print(":");
            lcd.print(EEPROM.read(z));
            delay(30);
            
              int p1=map(analogRead(A0),0,800,0,24);
              EEPROM.write(x,p1);
              int p2=map(analogRead(A1),0,800,0,59);
              EEPROM.write(y,p2);
              int p3=map(analogRead(A2),0,800,0,20);
              EEPROM.write(z,p3);
              if(digitalRead(7)){
              while(digitalRead(7));
              x=x+3;y=y+3;z=z+3;m++;
              if(m>20)
              {x=131;y=132;z=133;m=1;}
              }
              if(digitalRead(6)){
              while(digitalRead(6));
              goto t;
              }
              
              
              }
 case 4:
          m=1;x=200;y=201;z=202;
          while(1){
            lcd.clear();
            lcd.print(m);
            lcd.print("  ");
            lcd.print(EEPROM.read(x));
            lcd.print(":");
            lcd.print(EEPROM.read(y));
              lcd.setCursor(0, 1);
            lcd.print(":");
            lcd.print(EEPROM.read(z));
            delay(30);
            
              int p1=map(analogRead(A0),0,800,0,24);
              EEPROM.write(x,p1);
              int p2=map(analogRead(A1),0,800,0,59);
              EEPROM.write(y,p2);
              int p3=map(analogRead(A2),0,800,0,20);
              EEPROM.write(z,p3);
              if(digitalRead(7)){
              while(digitalRead(7));
              x=x+3;y=y+3;z=z+3;m++;
              if(m>20)
              {x=200;y=201;z=202;m=1;}
              }
              if(digitalRead(6)){
              while(digitalRead(6));
              goto t;
              }
              
              
              }

 case 5:
 while(1){lcd.clear();
          lcd.print(RTC.getHours());
          lcd.print(":");
          lcd.print(RTC.getMinutes());
          lcd.print(" D");
          lcd.print(RTC.getDayOfWeek());
          int p1=map(analogRead(A0),0,1023,0,24);
              RTC.setHours(p1);RTC.setClock();
              int p2=map(analogRead(A1),0,1023,0,59);
              RTC.setMinutes(p2);RTC.setClock();
              int p3=map(analogRead(A2),0,1023,1,7);
              RTC.setDayOfWeek(p3);
              RTC.setClock();
          }
        
            }
            }
            }
            }
          }
       
        
   
   
    int x,y,xm,ym;
      switch(EEPROM.read(1023))
      {
        case 1:
          x=1;y=61;xm=2;ym=62;
          break;
        case 2:
        x=70;y=130;xm=71;ym=131;
        break;
        case 3:
        x=133;y=193;xm=134;ym=194;
        break;
        case 4:
        x=200;y=260;xm=201;ym=261;
        break;
      }
      for(int i=x;i<=y;)
        {
          
          if(i>y){
          goto top;
        }
        RTC.readClock();
          int h=RTC.getHours();
           lcd.clear();
        lcd.print(h);
        lcd.print(":");
        lcd.print(RTC.getMinutes());
        if(digitalRead(6)){
          goto x;
        }
       delay(50);
       
          if(EEPROM.read(i)==h)
          { 
            for(int i=xm;i<=ym;){
               // lcd.clear();
              //lcd.print(i);
           
            int m=RTC.getMinutes();
            if(EEPROM.read(i)==m)
            {i++;
              int dl=EEPROM.read(i);
              i--;
            digitalWrite(13,1);
            dl=dl*1000;
            delay(dl);
            digitalWrite(13,0);
            for(long s=65000;s>=0;){
              lcd.clear();
              lcd.print("bell in");
              lcd.setCursor(0, 1);
               lcd.print(s/1000);
            
            if(digitalRead(8))
            {lcd.clear();
              while(digitalRead(8));
              lcd.print("stoped");
              
              delay(60000);
              goto next;
           
            }  delay(1);
            s=s-5;
            }
            
            digitalWrite(10,1);
            //dl=dl*1000;
            delay(dl);
            digitalWrite(10,0);
            next:
            delay(1000);
            }
            i=i+3;
            }
            
           
          }
        i=i+3;
    }
}



    
    
  
  

