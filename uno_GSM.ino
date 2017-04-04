#include <GSM.h>

#define PINNUMBER ""

// initialize the library instance
GSM gsmAccess; // include a 'true' parameter for debug enabled
GSM_SMS sms;

// char array of the telephone number to send SMS
// change the number 1-212-555-1212 to a number
// you have access to
char remoteNumber[20]= "4064046914";  

// char array of the message
char txtMsg[1000]="-0.012091,-0.012364,-0.012182,-0.012818,-0.012909,-0.015182,-0.015455,-0.015818,-0.015545,-0.015364,-0.016455,-0.021273,-0.022000,-0.022182,-0.001455,0.043091,0.102545,0.138636,0.129000,0.102909,0.002636,-0.049182,-0.047636,-0.034000,-0.024000,-0.014273,-0.012091,-0.010545,-0.009091,-0.007455,-0.005182,-0.003909,-0.001818,0.000091,0.002000,0.004273,0.007364,0.010182,0.014273,0.017909,0.022455,0.027636,0.033364,0.038909,0.043182,0.046273,0.048636,0.047545,0.043455,0.037455,0.028727,0.019455,0.009727,0.001455,-0.004455,-0.008727,-0.011818,-0.013091,-0.014364,-0.013818,-0.014182,-0.014364,-0.013636,-0.013727,-0.014182,-0.013636,-0.013273,-0.012636,-0.012364,-0.012273,-0.011182,-0.011727,-0.012182,-0.012455,-0.012364,-0.012091";

void setup()
{
  // initialize serial communications
  Serial.begin(9600);

  Serial.println("SMS Messages Sender");

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while(notConnected)
  {
    if(gsmAccess.begin((char*)PINNUMBER)==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GSM initialized");
  sendSMS();
}

void loop()
{
// nothing to see here
}

void sendSMS(){
  
  Serial.print("Message to mobile number: ");
  Serial.println(remoteNumber);

  // sms text
  Serial.println("SENDING");
  Serial.println();
  Serial.println("Message:");
  Serial.println(txtMsg);

  // send the message
  sms.beginSMS(remoteNumber);
  sms.print(txtMsg);
  sms.endSMS(); 
  Serial.println("\nCOMPLETE!\n");  
}
