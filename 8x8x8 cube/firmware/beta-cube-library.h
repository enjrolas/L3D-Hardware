#ifndef _L3D_H
#define _L3D_H

#include "application.h"
#include "neopixel.h"

#if defined(PLATFORM_ID)
#if (PLATFORM_ID == 0) // Core
#define PROCESSOR "core"
#elif (PLATFORM_ID == 6) // Photon
#define PROCESSOR "photon"
#else
#define PROCESSOR "unknown"
#endif
#else
#define PROCESSOR "core"
#endif

#define PIXEL_COUNT 512
#define PIXEL_PIN D0
#define PIXEL_TYPE WS2812B

#define INTERNET_BUTTON D2
#define MODE D3

#define STREAMING_PORT 2222

#define MICROPHONE 12
#define X 13
#define Y 14
#define Z 15

/**   An RGB color. */
struct Color
{
  unsigned char red, green, blue;

  Color(int r, int g, int b) : red(r), green(g), blue(b) {}
  Color() : red(0), green(0), blue(0) {}
};

/**   A point in 3D space.  */
struct Point
{
  float x;
  float y;
  float z;
  Point() : x(0), y(0), z(0) {}
  Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

/**   An L3D LED cube.
      Provides methods for drawing in 3D. Controls the LED hardware.
*/
class Cube
{
  private:
    bool onlinePressed;
    bool lastOnline;
    Adafruit_NeoPixel strip;
    UDP udp;
    int lastUpdated;
    char localIP[24];
    int port;

  public:
    int size;
    int maxBrightness;
    Point center;
    float theta, phi;
    int accelerometerX, accelerometerY, accelerometerZ;
    Cube(unsigned int s, unsigned int mb);
    Cube(void);

    void setVoxel(int x, int y, int z, Color col);
    void setVoxel(Point p, Color col);
    Color getVoxel(int x, int y, int z);
    Color getVoxel(Point p);
    void line(int x1, int y1, int z1, int x2, int y2, int z2, Color col);
    void line(Point p1, Point p2, Color col);
    void sphere(int x, int y, int z, int r, Color col);
    void sphere(Point p, int r, Color col);
    void shell(float x, float y, float z, float r, Color col);
    void shell(float x, float y, float z, float r, float thickness, Color col);
    void shell(Point p, float r, Color col);
    void shell(Point p, float r, float thickness, Color col);
    void updateAccelerometer();
   void background(Color col);

    Color colorMap(float val, float min, float max);
    Color lerpColor(Color a, Color b, int val, int min, int max);

    void begin(void);
    void show(void);
    void listen(void);
    void initButtons(void);
    void checkCloudButton(void);
    void joinWifi(void);
    void updateNetworkInfo(void);
};

// common colors
const Color black     = Color(0x00, 0x00, 0x00);
const Color grey      = Color(0x92, 0x95, 0x91);
const Color yellow    = Color(0xff, 0xff, 0x14);
const Color magenta   = Color(0xc2, 0x00, 0x78);
const Color orange    = Color(0xf9, 0x73, 0x06);
const Color teal      = Color(0x02, 0x93, 0x86);
const Color red       = Color(0xe5, 0x00, 0x00);
const Color brown     = Color(0x65, 0x37, 0x00);
const Color pink      = Color(0xff, 0x81, 0xc0);
const Color blue      = Color(0x03, 0x43, 0xdf);
const Color green     = Color(0x15, 0xb0, 0x1a);
const Color purple    = Color(0x7e, 0x1e, 0x9c);
const Color white     = Color(0xff, 0xff, 0xff);

#endif
