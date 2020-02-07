void rfid_trek()
{
    while(Serial3.available())
  {
    ctagg = Serial3.read();
    st += ctagg,HEX;
    st += " ";
  }
  no1 = getValue(st,' ',3);
  no2 = getValue(st,' ',2);
  notag= no1.toInt();
  notag2 = no2.toInt();

  if(notag>=255 && notag<=237)
  {
    count = 0;
  }
  else if(notag>=205 && notag<=223)
  {
    count= 1;
  }
  else if(notag>=173 && notag<=191)
  {
    count = 2;
  }
  else if(notag>=141 && notag<=159)
  {
    count = 3;
  }
  else if(notag>=109 && notag<=127)
  {
    count = 4;
  }
  else if(notag>=77 && notag<=95)
  {
    count = 5;
  }
  else if(notag>=45 && notag<=63)
  {
    count = 6;
  }
  else if(notag>=13 && notag<=31)
  {
    count = 7;
  }
  else
  {
    count = 0;
  }


  if(notag2>=255 && notag2<=237)
  {
    count2 = 0;
  }
  else if(notag2>=205 && notag2<=223)
  {
    count2= 1;
  }
  else if(notag2>=173 && notag2<=191)
  {
    count2 = 2;
  }
  else if(notag2>=141 && notag2<=159)
  {
    count2 = 3;
  }
  else if(notag2>=109 && notag2<=127)
  {
    count2 = 4;
  }
  else if(notag2>=77 && notag2<=95)
  {
    count2 = 5;
  }
  else if(notag2>=45 && notag2<=63)
  {
    count2 = 6;
  }
  else if(notag2>=13 && notag2<=31)
  {
    count2 = 7;
  }
  else
  {
    count2 = 0;
  }
  
  realtag1 = ((255-notag)/2)-(6*count);
  realtag2 = ((255-notag2)/2)-(6*count2)+80;
  if (realtag1 == 127 || realtag2 == 207)
  {
    tagtrack = 0;
  }
  else if (realtag2 == 80)
  {
    tagtrack=realtag1;
  }
  else if (realtag1 == 0)
  {
    tagtrack=realtag2;
  }
  else
  {
    tagtrack=0;
  }
  rfidtrek = (String)tagtrack;
  if (deteksirfid == 1 && stepp == 1 && tagtrack == 101) //track 1 standby pos maju
  {
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 2;    
  }
  if (tagtrack == 3 && stepp == 2) //track 1 kondisi mundur
  {
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 3;
  }
  if (tagtrack == 102 && stepp == 3) //track 2 standby pos maju
  {
      c = 'p';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 4;
  }
  if (tagtrack == 11 && stepp == 4) //track 2 kondisi mundur
  {
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 5;
  }
  if (tagtrack == 103 && stepp == 5) //track 3 standby pos mundur
  {
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 6;
  }
  if (tagtrack == 104 && stepp == 6) // track 4 standby pos mundur
  {
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 7;
  }
  if (tagtrack == 105 && stepp == 7) //track 5 standby pos maju
  {
      c = 'p';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c);
      delay(3000);
      stepp = 8;
  }
  if (tagtrack == 17 && stepp == 8) // track 5 berenti di tanjakan
  {
      c = 'n';
      sendMP3Command(c);
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //silakan berenti
      delay(3000);
    if (encoder == 0)
    {
      c = 'p';
      sendMP3Command(c);
      c = 'p';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //maju kedepan
      delay(3000);
      stepp = 9;
    }
  }
  if (tagtrack == 18 && stepp == 9) //track 5 berenti di atas
  {
      c = 'n';
      sendMP3Command(c);
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //silakan berenti
      delay(3000);
    if (encoder == 0)
    {
      c = 'p';
      sendMP3Command(c);
      c = 'p';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //maju kedepan
      delay(3000);
      stepp = 10;
    }
  }
  if (tagtrack == 19 && stepp == 10) // tracj 5 berenti di turunan
  {
      c = 'n';
      sendMP3Command(c);
      c = 'n';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //silakan berenti
      delay(3000);
    if (encoder == 0)
    {
      c = 'p';
      sendMP3Command(c);
      c = 'p';
      sendMP3Command(c);
      c = 'm';
      sendMP3Command(c); //maju kedepan
      delay(3000);
      stepp = 1;
    }
  }
}
