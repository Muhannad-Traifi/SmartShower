#include"SDCard.h"

SDCard::SDCard()
{
   pinMode(CS_PIN,OUTPUT);
}
SDCard::~SDCard()
{
  
}
void SDCard::SDCardReadFromFile()
{
  char* ok = "/.+-*%";
  PasswordFile = SD.open("Password.txt",FILE_READ);
  if (PasswordFile) {
    Serial.println("Reading From Password.txt:");

    // read from the file until there's nothing else in it:
    while (PasswordFile.available()) 
      {
       
        FileData[indexOfData]=PasswordFile.read();  
        indexOfData++;  
      
      }

      for(int i=0;i<strlen(FileData);i++)
      {
        if(FileData[i]=='\n')
            LineNumber++;
       if((isDigit(FileData[i])||isAlpha(FileData[i])||((int)FileData[i]>=23&&(int)FileData[i]<=64))&&LineNumber==1)
        {
          UserName[IndexofUsername]=FileData[i];
          IndexofUsername++;
        }
       if((isDigit(FileData[i])||isAlpha(FileData[i])||((int)FileData[i]>23&&(int)FileData[i]<127))&&LineNumber==2)
        {
          Password[IndexofPassword]=FileData[i];
          IndexofPassword++;
        }      
      }
    
      Serial.println(UserName);
      Serial.println(Password);
  
    // close the file:
    
    PasswordFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening Password.txt");
  } 
}
void SDCard::KeepTryingToConnectToSDCard()
{
 
     if(SD.begin(4))
       {
          Serial.println("SDCard is Ready to use");
       }
     else
       {
          Serial.println("SDCard is NOT Ready to use");
       }
     if(SD.exists("Password.txt"))
       {
    
          this->SDCardReadFromFile();     
       }
}