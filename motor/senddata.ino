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
  kirim.toCharArray(ckirim,43);
  delay(50);
  HC12.write(ckirim);
  Serial.println(ckirim);
}
