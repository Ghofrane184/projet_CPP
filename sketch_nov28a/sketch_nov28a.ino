int BuzzerPin = 11;     // Connect Buzzer to Arduino pin 11

int Si2 =1975;
int LaS2=1864;
int La2= 1760;
int SolS2=1661;
int Sol2=1567;
int FaS2=1479;
int Fa2= 1396;
int Mi2= 1318;
int ReS2=1244;
int Re2= 1174;
int DoS2=1108;
int Do2= 1046;

// Low Octave
int Si = 987;
int LaS= 932;
int La = 880;
int SolS=830;
int Sol= 783;
int FaS= 739;
int Fa=  698;
int Mi=  659;
int ReS= 622;
int Re = 587;
int DoS =554;
int Do = 523;

// define the notes
int rounda=0;
int roundp=0;
int white= 0;
int whitep=0;
int black=0;  
int blackp=0;
int quaver=0;
int quaverp =0;
int semiquaver=0;
int semiquaverp=0;
int bpm= 120;
char data;
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0
//Mario main theme melody
int tempo = 200;
int melody[] = {

  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  
  
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  
  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
  REST,1, 
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
  
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
  REST,1,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  
  //game over sound
  NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
  NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  

};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
//const int led_Red=3;
const int led_R=4;
 
  

void setup() {
 
  // put your setup code here, to run once:
   pinMode(BuzzerPin,OUTPUT);
  // pinMode(led_Red,OUTPUT); //règle la borne numérique numéro 0 de la carte Arduino en mode sortie
   pinMode(led_R,OUTPUT); 
  // digitalWrite(led_Red, LOW); 
   digitalWrite(led_R, LOW);
   
   black= 35000/bpm; 
      blackp=black*1.5;
      white= black*2;
      whitep=white*1.5;
      rounda= black*4;
      roundp= rounda*1.5;
      quaver= black/2;
      quaverp=quaver*1.5;
      semiquaver= black/4;
      semiquaverp=semiquaver*1.5;

 

 
      
     // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)

  
Serial.begin(9600); //ouvre le port serie et fixe  le debit a 9600 bauds
}

void loop() {
      

  
 
  // put your main code here, to run repeatedly:
 if (Serial.available()){ //si données disponible sur le port serie     
    
     data=Serial.read();  
 
     if(data=='1')
    {  
     

     
 
  for (int thisNote = 0; thisNote < 2 ; thisNote = thisNote + 2) {
      

  
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;

    } 
    else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;// increases the duration in half for dotted notes



    }
           digitalWrite(led_R,HIGH);
           delay(25);
  digitalWrite(led_R,LOW);
  delay(25);

 
   

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(BuzzerPin, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
 
    // stop the waveform generation before the next note.
    noTone(BuzzerPin);
    

      
  }


 

    }
   
  
 if(data=='2')
    {  

      
  digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
  
      
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(2*white+50);
  
  digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
 
  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(2*white+50);
    
  digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);

  
  tone(BuzzerPin,Mi,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
     digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
  
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(2*black+50);
  
    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
 
  
  tone(BuzzerPin,Si,black);
  delay(black+50);
  tone(BuzzerPin,La,black);
  delay(black+50);
  
    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
  
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Mi2,black);
  delay(white+100);

    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
    

  
  tone(BuzzerPin,Mi2,black);
  delay(white+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  
  digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
    
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,white*1.3);
  delay(rounda+100);

    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);


  
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  
    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
  
  tone(BuzzerPin,Re2,black);
  delay(black+50);
  tone(BuzzerPin,Fa2,black);
  delay(black+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(rounda+100);


    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
    
  
  tone(BuzzerPin,Mi2,black);
  delay(black+50);
  tone(BuzzerPin,Re2,black);
  delay(black+50);
   tone(BuzzerPin,Do2,black);
  delay(black+50);
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Mi2,white*1.3);
  delay(white+50);

    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);
  
  tone(BuzzerPin,Si,white*1.3);
  delay(white+50);
  tone(BuzzerPin,Do2,white*1.3);
  delay(white+50);
  tone(BuzzerPin,La,rounda*1.3);
  delay(rounda+50);


    digitalWrite(led_R,HIGH);
  delay(25);
  digitalWrite(led_R,LOW);
  delay(25);

    

  
  

}
 
}}
