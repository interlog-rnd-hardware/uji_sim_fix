void senddata()
{
  kirim = "<" + nama + 
          mtr + "~" + 
          crfid/*"471847"*/ + "~" + 
          kanan/*"0"*/ + "~" + 
          kiri/*"0"*/ + "~" + 
          cpdr + "," + 
          cpdl + "," + 
          cstr + "," + 
          cstl + "~" + 
          ctegaki+ "~" + 
          ctegaki1 + "~" +
          tagtrack + ">"; // + "\r\n";
//  kirim.toCharArray(ckirim,43);
  delay(50);
  if (oldkirim != kirim)
      {
        HC12.println(kirim);       
      }
  Serial.println(kirim);
  delay(50);
  oldkirim = kirim;
}
