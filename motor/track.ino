void track()
{
  while(UHF.available())
  {
    ctagg = UHF.read();
    //  Serial.print(c,HEX);
    //  Serial.print(" ");
    st += ctagg,HEX;
    st += " ";
  }
  no1 = getValue(st,' ',3);
  no2 = getValue(st,' ',2);
  notag= no1.toInt();
  notag2 = no2.toInt();
  ifnya();
  realtag1 = ((255-notag)/2)-(6*count);
  realtag2 = ((255-notag2)/2)-(6*count2)+80;
//delay(100);
//Serial.print(realtag1);
//Serial.print(" ");
//Serial.println(st);
  if (realtag1 == 127 || realtag2 == 207)
  {
    tagtrack = 0;
//Serial.println("-");
  }
  else if (realtag2 == 80)
  {
//Serial.println(realtag1);
tagtrack=realtag1;
  }
  else if (realtag1 == 0)
  {
//Serial.println(realtag2);
tagtrack=realtag2;
  }
  else
  {
//Serial.println("-");
tagtrack=0;
  }
  if (tagtrack == 3)
  {
    kanan = "0";
    kiri = "0";
  }
//Serial.println(tagtrack);
}
