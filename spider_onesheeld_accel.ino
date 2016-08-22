#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_ACCELEROMETER_SENSOR_SHIELD
#define INCLUDE_PUSH_BUTTON_SHIELD

#include <OneSheeld.h>
#include <hexbug-spider.h>

float x, y, z;

void setup(void)
{
    /* Start communication. */
  OneSheeld.begin();

}


void loop(void) {
  if(PushButton.isPressed())
  {
    example_hexbug_spider_lookout();
  }
  
  x=AccelerometerSensor.getX();
  y=AccelerometerSensor.getY();
  z=AccelerometerSensor.getZ();

  Terminal.println("x: ");
  Terminal.print(x);
  Terminal.print(", y: ");
  Terminal.print(y);

  int i;
    
  if(y < -5)
  {
    for (i = 0; i < 5; i++) {
      hexbug_spider_forward();
      delay(100);
    }    
  }
  else if (y > 5)
  {
    for (i = 0; i < 5; i++) {
      hexbug_spider_backward();
      delay(100);
    }
  }
  else if (x < -5)
  {
    for (i = 0; i < 5; i++) {
      hexbug_spider_right();
      delay(100);
    }
  }
  else if (x > 5)
  {
    for (i = 0; i < 5; i++) {
      hexbug_spider_left();
      delay(100);
    }
  }
}

void example_hexbug_spider_lookout() {
  int i;

  for (i = 0; i < 5; i++) {
    hexbug_spider_left();
    delay(100);
  };

  for (i = 0; i < 5; i++) {
    hexbug_spider_right();
    delay(100);
  }
}


