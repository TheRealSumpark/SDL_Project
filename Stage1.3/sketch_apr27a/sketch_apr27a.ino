int x ;
char  retour;
void setup()  
{
  Serial.begin(9600);
  pinMode ( 5, INPUT ) ;
  pinMode ( 3, INPUT ) ; 
  pinMode ( 4, INPUT ) ; 
  pinMode ( 6, INPUT ) ; 
  pinMode ( 12, OUTPUT ) ;
  pinMode ( 13, OUTPUT ) ;
  digitalWrite( 12, HIGH);
  digitalWrite( 13, HIGH);
}

void loop() {
 if (Serial.available() > 0) {
               
        retour = (char) Serial.read();
         delay(5);
        }
  if(retour == '1')
     {
      digitalWrite( 12, HIGH);
     }
  if(retour == '2')
      {
         digitalWrite( 13, HIGH);
      }
 if(retour == '0')
      {
         digitalWrite( 13, LOW);
         digitalWrite( 12, LOW);
      }
 
 if ( digitalRead (3) == HIGH ) 
  {
   x=3;
    Serial.println(x) ;
  }
 else if ( digitalRead ( 4 ) == HIGH ) 
  {
   x=4;
    Serial.println(x) ;
  }
 else if ( digitalRead ( 5 ) == HIGH )
  {
    x=5;
    Serial.println(x) ; 
  }
 else if ( digitalRead ( 6 ) == HIGH ) 
  {
    x=6;
    Serial.println(x) ;
  }
 else 
  {
     x=0;
    Serial.println(x) ;
  }
}
