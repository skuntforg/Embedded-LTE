#include <MKRGSM.h>
#define PINNUMBER "1210"
#define GPRS_APN       "data.uk"
#define GPRS_LOGIN     "user"
#define GPRS_PASSWORD  "one2one"

GSMClient client;
GPRS gprs;
GSM gsmAccess;

IPAddress server(its a mystery);
char path[] = "/includes/page.php";
int port = 80;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting Arduino webby web");
  boolean notConnected = true;
  while(notConnected)
  {
    if((gsmAccess.begin(PINNUMBER)==GSM_READY) && (gprs.attachGPRS(GPRS_APN, GPRS_LOGIN, GPRS_PASSWORD)==GPRS_READY))
    {
      notConnected = false;
    }
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
   }
    Serial.println("GSM Initialised cause Im a bad bitch");

}

void loop() {
  // put your main code here, to run repeatedly:
  int temperature = 24;
  int humidity = 3;
  if (client.connect(server, port)) {
    Serial.println("connected to server");
    client.print("GET /arduinostuff/data.php? HTTP/1.1");
    client.println("Host: http://ooohmystery/");
    client.print("temperature=");
    client.print(temperature);
    client.print("humidity=");
    client.print(humidity);
    client.println("Connection: close");
    client.println();
    client.stop();
    Serial.println("done my stuff - good luck lol");
    delay(10000);
  }

else {
    Serial.println("connection to server failed");
  } 
}
