#include <SPI.h>

#define X_axis 0
#define Y_axis 1
#define Z_axis 2

#define POSITION_X 0
#define POSITION_Z 2
#define POSITION_Y 4

#define NEG_X 1
#define NEG_Z 3
#define NEG_Y 5

#define BTN 8

#define TOTAL 8
#define RAIN 0
#define PLANE_BOING 1
#define SEND_VOXELS 2
#define WOOP_WOOP 3
#define CUBE_JUMP 4
#define GLOW 5
#define TEXT 6
#define LIT 7

#define RAIN_TIME 200
#define PLANE_BOING_TIME 300
#define SEND_VOXELS_TIME 140
#define WOOP_WOOP_TIME 350
#define CUBE_JUMP_TIME 200
#define GLOW_TIME 8
#define TEXT_TIME 300
#define CLOCK_TIME 500

uint8_t characters[10][8] = {
  {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, //0
  {0x10, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x3C}, //1
  {0x3C, 0x42, 0x40, 0x40, 0x3C, 0x02, 0x02, 0x7E}, //2
  {0x3C, 0x40, 0x40, 0x3C, 0x40, 0x40, 0x42, 0x3C}, //3
  {0x22, 0x22, 0x22, 0x22, 0x7E, 0x20, 0x20, 0x20}, //4
  {0x7E, 0x02, 0x02, 0x3E, 0x40, 0x40, 0x42, 0x3C}, //5
  {0x3C, 0x02, 0x02, 0x3E, 0x42, 0x42, 0x42, 0x3C}, //6
  {0x3C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40}, //7
  {0x3C, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x3C}, //8
  {0x3C, 0x42, 0x42, 0x42, 0x3C, 0x40, 0x40, 0x3C}, //9
};
const uint8_t DrillData[14][8] PROGMEM =
{
  {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01}, //
  {0x40, 0x20, 0x20, 0x10, 0x08, 0x04, 0x04, 0x02},
  {0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04},
  {0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08},
  {0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10},
  {0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20},
  {0x02, 0x04, 0x04, 0x08, 0x10, 0x20, 0x20, 0x40},
  {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}, //
  {0x00, 0x01, 0x06, 0x08, 0x10, 0x60, 0x80, 0x00},
  {0x00, 0x00, 0x03, 0x0C, 0x30, 0xC0, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00}, //
  {0x00, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00}, //
  {0x00, 0x00, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x00},
  {0x00, 0x80, 0x60, 0x10, 0x08, 0x06, 0x01, 0x00}
};

const uint8_t CharactersData[65][8] PROGMEM =
{
  {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, // 0x00 // 0 //
  {0x08, 0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x3C}, // 0x01 // 1 //
  {0x3C, 0x42, 0x42, 0x04, 0x08, 0x10, 0x20, 0x7E}, // 0x02 // 2 //
  {0x3C, 0x42, 0x02, 0x0C, 0x0C, 0x02, 0x42, 0x3C}, // 0x03 // 3 //
  {0x04, 0x0C, 0x14, 0x24, 0x44, 0x7E, 0x04, 0x04}, // 0x04 // 4 //
  {0x7E, 0x40, 0x78, 0x04, 0x02, 0x42, 0x42, 0x3C}, // 0x05 // 5 //
  {0x1C, 0x20, 0x40, 0x40, 0x7C, 0x42, 0x42, 0x3C}, // 0x06 // 6 //
  {0x7E, 0x42, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10}, // 0x07 // 7 //
  {0x3C, 0x42, 0x42, 0x3C, 0x3C, 0x42, 0x42, 0x3C}, // 0x08 // 8 //
  {0x3C, 0x42, 0x42, 0x42, 0x3E, 0x02, 0x04, 0x38}, // 0x09 // 9 //
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // 0x0A //   //
  {0x18, 0x3C, 0x66, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3}, // 0x0B // A //
  {0xFE, 0xC3, 0xC3, 0xFE, 0xFE, 0xC3, 0xC3, 0xFE}, // 0x0C // B //
  {0x7E, 0xFF, 0xC3, 0xC0, 0xC0, 0xC3, 0xFF, 0x7E}, // 0x0D // C //
  {0xFC, 0xFE, 0xC7, 0xC3, 0xC3, 0xC7, 0xFE, 0xFC}, // 0x0E // D //
  {0xFF, 0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0, 0xFF}, // 0x0F // E //
  {0xFF, 0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0, 0xC0}, // 0x10 // F //
  {0x7E, 0xFF, 0xC3, 0xC0, 0xCF, 0xC3, 0xFF, 0x7E}, // 0x11 // G //
  {0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3, 0xC3}, // 0x12 // H //
  {0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C}, // 0x13 // I //
  {0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x6C, 0x7C, 0x38}, // 0x14 // J //
  {0xC3, 0xC6, 0xCC, 0xF8, 0xF8, 0xCC, 0xC6, 0xC3}, // 0x15 // K //
  {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF}, // 0x16 // L //
  {0xC3, 0xE7, 0xDB, 0xDB, 0xC3, 0xC3, 0xC3, 0xC3}, // 0x17 // M //
  {0xC3, 0xE3, 0xF3, 0xDB, 0xDB, 0xCF, 0xC7, 0xC3}, // 0x18 // N //
  {0x7E, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0x7E}, // 0x19 // O //
  {0xFE, 0xFF, 0xC3, 0xC3, 0xFF, 0xFE, 0xC0, 0xC0}, // 0x1A // P //
  {0x7E, 0xFF, 0xC3, 0xD3, 0xCB, 0xC6, 0xFE, 0x79}, // 0x1B // Q //
  {0xFE, 0xC3, 0xC3, 0xFE, 0xD8, 0xCC, 0xC6, 0xC3}, // 0x1C // R //
  {0x7E, 0xC3, 0xC0, 0x7C, 0x3E, 0x03, 0xC3, 0x7E}, // 0x1D // S //
  {0xFF, 0xFF, 0x99, 0x18, 0x18, 0x18, 0x18, 0x18}, // 0x1E // T //
  {0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0x7E}, // 0x1F // U //
  {0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0x66, 0x3C, 0x18}, // 0x20 // V //
  {0xC3, 0xC3, 0xC3, 0xC3, 0xDB, 0xDB, 0xDB, 0x66}, // 0x21 // W //
  {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81}, // 0x22 // X //
  {0xC3, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18}, // 0x23 // Y //
  {0xFF, 0xFF, 0x06, 0x1C, 0x38, 0x60, 0xFF, 0xFF}, // 0x24 // Z //
  {0x00, 0x00, 0x00, 0x1C, 0x02, 0x1E, 0x22, 0x1E}, // 0x25 // a //
  {0x20, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x22, 0x3C}, // 0x26 // b //
  {0x00, 0x00, 0x00, 0x3C, 0x40, 0x40, 0x42, 0x3C}, // 0x27 // c //
  {0x02, 0x02, 0x02, 0x3A, 0x46, 0x42, 0x42, 0x3E}, // 0x28 // d //
  {0x00, 0x00, 0x00, 0x38, 0x44, 0x7C, 0x40, 0x38}, // 0x29 // e //
  {0x0C, 0x12, 0x10, 0x38, 0x10, 0x10, 0x10, 0x10}, // 0x2A // f //
  {0x00, 0x00, 0x1E, 0x22, 0x22, 0x1E, 0x02, 0x1C}, // 0x2B // g //
  {0x40, 0x40, 0x40, 0x5C, 0x62, 0x42, 0x42, 0x42}, // 0x2C // h //
  {0x00, 0x08, 0x00, 0x18, 0x08, 0x08, 0x08, 0x1C}, // 0x2D // i //
  {0x00, 0x04, 0x00, 0x0C, 0x04, 0x04, 0x44, 0x38}, // 0x2E // j //
  {0x20, 0x20, 0x20, 0x24, 0x28, 0x30, 0x28, 0x24}, // 0x2F // k //
  {0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1C}, // 0x30 // l //
  {0x00, 0x00, 0x00, 0x6C, 0x52, 0x52, 0x42, 0x42}, // 0x31 // m //
  {0x00, 0x00, 0x00, 0x5C, 0x62, 0x42, 0x42, 0x42}, // 0x32 // n //
  {0x00, 0x00, 0x00, 0x3C, 0x42, 0x42, 0x42, 0x3C}, // 0x33 // o //
  {0x00, 0x00, 0x00, 0x7C, 0x42, 0x42, 0x7C, 0x40}, // 0x34 // p //
  {0x00, 0x00, 0x00, 0x3E, 0x42, 0x42, 0x3E, 0x02}, // 0x35 // q //
  {0x00, 0x00, 0x00, 0x2C, 0x32, 0x20, 0x20, 0x20}, // 0x36 // r //
  {0x00, 0x00, 0x00, 0x3C, 0x40, 0x3C, 0x02, 0x7C}, // 0x37 // s //
  {0x00, 0x10, 0x38, 0x10, 0x10, 0x10, 0x12, 0x0C}, // 0x38 // t //
  {0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x46, 0x3A}, // 0x39 // u //
  {0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x24, 0x18}, // 0x3A // v //
  {0x00, 0x00, 0x00, 0x42, 0x42, 0x42, 0x5A, 0x24}, // 0x3B // w //
  {0x00, 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42}, // 0x3C // x //
  {0x00, 0x00, 0x00, 0x22, 0x22, 0x1E, 0x02, 0x1C}, // 0x3D // y //
  {0x00, 0x00, 0x00, 0x7E, 0x04, 0x08, 0x10, 0x7E}, // 0x3E // z //
  {0x00, 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00}, // 0x3F // + //
  {0x00, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00}  // 0x40 // : //
};

const uint8_t PersianText[56] PROGMEM =
{
  0x80, 0x40, 0x20, 0x1C,
  0x04, 0x04, 0xFC, 0x00,
  0x1C, 0x14, 0x1C, 0x04,
  0x04, 0x06, 0x01, 0xFC,
  0x00, 0x06, 0x01, 0x09,
  0x01, 0x06, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFC, 0x00,
  0x06, 0x01, 0x00, 0x0C,
  0x05, 0xFC, 0x00, 0x0C,
  0x05, 0x04, 0x06, 0x01,
  0x01, 0x01, 0x06, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};


uint8_t CubeData[8][8];        // LEDs Data (One Bit Per LED) => [y][z] = x //
uint8_t CurrentEffect;         // Store The Number Of Current Effect //
uint8_t Blinker;               // Counter For Blinker LED (Front LED) //
uint8_t CurrentStep;           // Output Step (Y Axis) //

uint64_t RandomSeed;

uint8_t cube[8][8];
uint8_t currentEffect;

uint16_t timer;

uint64_t randomTimer;

bool loading;

void setup() {

  loading = true;
  randomTimer = 0;
  currentEffect = RAIN;

  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));

  pinMode(BTN, INPUT_PULLUP);



  randomSeed(analogRead(0));

}

void loop() {

  randomTimer++;

  if (digitalRead(BTN) == LOW) {
    clearCube();
    loading = true;
    timer = 0;
    currentEffect++;
    if (currentEffect == TOTAL) {
      currentEffect = 0;
    }
    randomSeed(randomTimer);
    randomTimer = 0;
    delay(500);

  }

  switch (currentEffect) {
    case RAIN: rain(); break;
    case PLANE_BOING: planeBoing(); break;
    case SEND_VOXELS: sendVoxels(); break;
    case WOOP_WOOP: woopWoop(); break;
    case CUBE_JUMP: cubeJump(); break;
    case GLOW: glow(); break;
    case TEXT: text("0123456789", 10); break;
    case LIT: lit(); break;

    default: rain();
  }

  renderCube();

}

void renderCube() {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(SS, LOW);
    SPI.transfer(0x01 << i);
    for (uint8_t j = 0; j < 8; j++) {
      SPI.transfer(cube[i][j]);
    }
    digitalWrite(SS, HIGH);
  }
}

void rain() {
  if (loading) {
    clearCube();
    loading = false;
  }
  timer++;
  if (timer > RAIN_TIME) {
    timer = 0;
    shift(NEG_Y);
    uint8_t numDrops = random(0, 5);
    for (uint8_t i = 0; i < numDrops; i++) {
      setVoxel(random(0, 8), 7, random(0, 8));
    }
  }
}

uint8_t planePosition = 0;
uint8_t planeDirection = 0;
bool looped = false;

void planeBoing() {
  if (loading) {
    clearCube();
    uint8_t axis = random(0, 3);
    planePosition = random(0, 2) * 7;
    setPlane(axis, planePosition);
    if (axis == X_axis) {
      if (planePosition == 0) {
        planeDirection = POSITION_X;
      } else {
        planeDirection = NEG_X;
      }
    } else if (axis == Y_axis) {
      if (planePosition == 0) {
        planeDirection = POSITION_Y;
      } else {
        planeDirection = NEG_Y;
      }
    } else if (axis == Z_axis) {
      if (planePosition == 0) {
        planeDirection = POSITION_Z;
      } else {
        planeDirection = NEG_Z;
      }
    }
    timer = 0;
    looped = false;
    loading = false;
  }

  timer++;
  if (timer > PLANE_BOING_TIME) {
    timer = 0;
    shift(planeDirection);
    if (planeDirection % 2 == 0) {
      planePosition++;
      if (planePosition == 7) {
        if (looped) {
          loading = true;
        } else {
          planeDirection++;
          looped = true;
        }
      }
    } else {
      planePosition--;
      if (planePosition == 0) {
        if (looped) {
          loading = true;
        } else {
          planeDirection--;
          looped = true;
        }
      }
    }
  }
}

uint8_t selX = 0;
uint8_t selY = 0;
uint8_t selZ = 0;
uint8_t sendDirection = 0;
bool sending = false;

void sendVoxels() {
  if (loading) {
    clearCube();
    for (uint8_t x = 0; x < 8; x++) {
      for (uint8_t z = 0; z < 8; z++) {
        setVoxel(x, random(0, 2) * 7, z);
      }
    }
    loading = false;
  }

  timer++;
  if (timer > SEND_VOXELS_TIME) {
    timer = 0;
    if (!sending) {
      selX = random(0, 8);
      selZ = random(0, 8);
      if (getVoxel(selX, 0, selZ)) {
        selY = 0;
        sendDirection = POSITION_Y;
      } else if (getVoxel(selX, 7, selZ)) {
        selY = 7;
        sendDirection = NEG_Y;
      }
      sending = true;
    } else {
      if (sendDirection == POSITION_Y) {
        selY++;
        setVoxel(selX, selY, selZ);
        clearVoxel(selX, selY - 1, selZ);
        if (selY == 7) {
          sending = false;
        }
      } else {
        selY--;
        setVoxel(selX, selY, selZ);
        clearVoxel(selX, selY + 1, selZ);
        if (selY == 0) {
          sending = false;
        }
      }
    }
  }
}

uint8_t cubeSize = 0;
bool cubeExpanding = true;

void woopWoop() {
  if (loading) {
    clearCube();
    cubeSize = 2;
    cubeExpanding = true;
    loading = false;
  }

  timer++;
  if (timer > WOOP_WOOP_TIME) {
    timer = 0;
    if (cubeExpanding) {
      cubeSize += 2;
      if (cubeSize == 8) {
        cubeExpanding = false;
      }
    } else {
      cubeSize -= 2;
      if (cubeSize == 2) {
        cubeExpanding = true;
      }
    }
    clearCube();
    drawCube(4 - cubeSize / 2, 4 - cubeSize / 2, 4 - cubeSize / 2, cubeSize);
  }
}

uint8_t xPos;
uint8_t yPos;
uint8_t zPos;

void cubeJump() {
  if (loading) {
    clearCube();
    xPos = random(0, 2) * 7;
    yPos = random(0, 2) * 7;
    zPos = random(0, 2) * 7;
    cubeSize = 8;
    cubeExpanding = false;
    loading = false;
  }

  timer++;
  if (timer > CUBE_JUMP_TIME) {
    timer = 0;
    clearCube();
    if (xPos == 0 && yPos == 0 && zPos == 0) {
      drawCube(xPos, yPos, zPos, cubeSize);
    } else if (xPos == 7 && yPos == 7 && zPos == 7) {
      drawCube(xPos + 1 - cubeSize, yPos + 1 - cubeSize, zPos + 1 - cubeSize, cubeSize);
    } else if (xPos == 7 && yPos == 0 && zPos == 0) {
      drawCube(xPos + 1 - cubeSize, yPos, zPos, cubeSize);
    } else if (xPos == 0 && yPos == 7 && zPos == 0) {
      drawCube(xPos, yPos + 1 - cubeSize, zPos, cubeSize);
    } else if (xPos == 0 && yPos == 0 && zPos == 7) {
      drawCube(xPos, yPos, zPos + 1 - cubeSize, cubeSize);
    } else if (xPos == 7 && yPos == 7 && zPos == 0) {
      drawCube(xPos + 1 - cubeSize, yPos + 1 - cubeSize, zPos, cubeSize);
    } else if (xPos == 0 && yPos == 7 && zPos == 7) {
      drawCube(xPos, yPos + 1 - cubeSize, zPos + 1 - cubeSize, cubeSize);
    } else if (xPos == 7 && yPos == 0 && zPos == 7) {
      drawCube(xPos + 1 - cubeSize, yPos, zPos + 1 - cubeSize, cubeSize);
    }
    if (cubeExpanding) {
      cubeSize++;
      if (cubeSize == 8) {
        cubeExpanding = false;
        xPos = random(0, 2) * 7;
        yPos = random(0, 2) * 7;
        zPos = random(0, 2) * 7;
      }
    } else {
      cubeSize--;
      if (cubeSize == 1) {
        cubeExpanding = true;
      }
    }
  }
}

bool glowing;
uint16_t glowCount = 0;

void glow() {
  if (loading) {
    clearCube();
    glowCount = 0;
    glowing = true;
    loading = false;
  }

  timer++;
  if (timer > GLOW_TIME) {
    timer = 0;
    if (glowing) {
      if (glowCount < 448) {
        do {
          selX = random(0, 8);
          selY = random(0, 8);
          selZ = random(0, 8);
        } while (getVoxel(selX, selY, selZ));
        setVoxel(selX, selY, selZ);
        glowCount++;
      } else if (glowCount < 512) {
        lightCube();
        glowCount++;
      } else {
        glowing = false;
        glowCount = 0;
      }
    } else {
      if (glowCount < 448) {
        do {
          selX = random(0, 8);
          selY = random(0, 8);
          selZ = random(0, 8);
        } while (!getVoxel(selX, selY, selZ));
        clearVoxel(selX, selY, selZ);
        glowCount++;
      } else {
        clearCube();
        glowing = true;
        glowCount = 0;
      }
    }
  }
}

uint8_t charCounter = 0;
uint8_t charPosition = 0;

void text(char string[], uint8_t len) {
  if (loading) {
    clearCube();
    charPosition = -1;
    charCounter = 0;
    loading = false;
  }
  timer++;
  if (timer > TEXT_TIME) {
    timer = 0;

    shift(NEG_Z);
    charPosition++;

    if (charPosition == 7) {
      charCounter++;
      if (charCounter > len - 1) {
        charCounter = 0;
      }
      charPosition = 0;
    }

    if (charPosition == 0) {
      for (uint8_t i = 0; i < 8; i++) {
        cube[i][0] = characters[string[charCounter] - '0'][i];
      }
    }
  }
}

void lit() {
  if (loading) {
    clearCube();
    for(uint8_t i=0; i<8; i++) {
      for(uint8_t j=0; j<8; j++) {
        cube[i][j] = 0xFF;
      }
    }
    loading = false;
  }
}

void setVoxel(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] |= (0x01 << x);
}

void clearVoxel(uint8_t x, uint8_t y, uint8_t z) {
  cube[7 - y][7 - z] ^= (0x01 << x);
}

bool getVoxel(uint8_t x, uint8_t y, uint8_t z) {
  return (cube[7 - y][7 - z] & (0x01 << x)) == (0x01 << x);
}

void setPlane(uint8_t axis, uint8_t i) {
  for (uint8_t j = 0; j < 8; j++) {
    for (uint8_t k = 0; k < 8; k++) {
      if (axis == X_axis) {
        setVoxel(i, j, k);
      } else if (axis == Y_axis) {
        setVoxel(j, i, k);
      } else if (axis == Z_axis) {
        setVoxel(j, k, i);
      }
    }
  }
}

void shift(uint8_t dir) {

  if (dir == POSITION_X) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y][z] << 1;
      }
    }
  } else if (dir == NEG_X) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y][z] >> 1;
      }
    }
  } else if (dir == POSITION_Y) {
    for (uint8_t y = 1; y < 8; y++) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y - 1][z] = cube[y][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[7][i] = 0;
    }
  } else if (dir == NEG_Y) {
    for (uint8_t y = 7; y > 0; y--) {
      for (uint8_t z = 0; z < 8; z++) {
        cube[y][z] = cube[y - 1][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[0][i] = 0;
    }
  } else if (dir == POSITION_Z) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 1; z < 8; z++) {
        cube[y][z - 1] = cube[y][z];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[i][7] = 0;
    }
  } else if (dir == NEG_Z) {
    for (uint8_t y = 0; y < 8; y++) {
      for (uint8_t z = 7; z > 0; z--) {
        cube[y][z] = cube[y][z - 1];
      }
    }
    for (uint8_t i = 0; i < 8; i++) {
      cube[i][0] = 0;
    }
  }
}

void drawCube(uint8_t x, uint8_t y, uint8_t z, uint8_t s) {
  for (uint8_t i = 0; i < s; i++) {
    setVoxel(x, y + i, z);
    setVoxel(x + i, y, z);
    setVoxel(x, y, z + i);
    setVoxel(x + s - 1, y + i, z + s - 1);
    setVoxel(x + i, y + s - 1, z + s - 1);
    setVoxel(x + s - 1, y + s - 1, z + i);
    setVoxel(x + s - 1, y + i, z);
    setVoxel(x, y + i, z + s - 1);
    setVoxel(x + i, y + s - 1, z);
    setVoxel(x + i, y, z + s - 1);
    setVoxel(x + s - 1, y, z + i);
    setVoxel(x, y + s - 1, z + i);
  }
}

void lightCube() {
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0xFF;
    }
  }
}

void clearCube() {
  for (uint8_t i = 0; i < 8; i++) {
    for (uint8_t j = 0; j < 8; j++) {
      cube[i][j] = 0;
    }
  }
}
