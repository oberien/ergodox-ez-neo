#define TRACKBALL_ADDRESS 0x0A
#define I2C_TIMEOUT 100
#define REG_LED_RED 0x00
#define REG_LED_GRN 0x01
#define REG_LED_BLU 0x02
#define REG_LED_WHT 0x03
#define REG_LEFT 0x04
#define REG_RIGHT 0x05
#define REG_UP 0x06
#define REG_DOWN 0x07
#define REG_SWITCH 0x08
#define MSK_SWITCH_STATE 0b10000000

struct tb_state { uint8_t left; uint8_t right; uint8_t up; uint8_t down; uint8_t btn; };

static void send(uint8_t reg, uint8_t* data, size_t len) {
  i2c_writeReg(TRACKBALL_ADDRESS << 1, reg, data, len, I2C_TIMEOUT);
}
static void recv(uint8_t reg, uint8_t* data, size_t len) {
  i2c_readReg(TRACKBALL_ADDRESS << 1, reg, data, len, I2C_TIMEOUT);
}
static struct tb_state recv_tb_state(void) {
  struct tb_state state = {0};
  recv(REG_LEFT, (uint8_t*)&state, sizeof(state));
  return state;
}

void trackball_set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
  uint8_t data[] = {red, green, blue, white};
  send(REG_LED_RED, data, 4);
}

static bool send_next_state = false;

void trackball_send_state(void) {
  uint8_t data[4];
  recv(REG_LED_RED, data, 4);
  send_hex(data[0]);
  send_hex(data[1]);
  send_hex(data[2]);
  send_hex(data[3]);
  send_next_state = !send_next_state;
}

static uint16_t timer = 0;

static uint32_t acceleration(uint8_t value, uint16_t elapsed) {
  return value * value * value * 5 / elapsed;
}

void trackball_pointing_device_task(void) {
  uint16_t elapsed = timer_elapsed(timer);
  struct tb_state state = recv_tb_state();
  if (send_next_state) {
    send_hex(state.left);
    send_hex(state.right);
    send_hex(state.up);
    send_hex(state.down);
    send_hex(state.btn);
    send_string(",");
  }
  report_mouse_t report = pointing_device_get_report();
  // if button was pressed
  if (state.btn & 0x7f) {
    report.buttons &= ~1;
    report.buttons |= (state.btn & 0x80) >> 7;
  }
  // trackball is mounted rotated
  int32_t dx = -acceleration(state.up, elapsed) + acceleration(state.down, elapsed) + report.x;
  int32_t dy = -acceleration(state.right, elapsed) + acceleration(state.left, elapsed) + report.y;
  while (abs(dx) > 127 || abs(dy) > 127) {
    int8_t x = 0;
    int8_t y = 0;
    if (dx > 0) {
      x = min(dx, 127);
      report.x = x;
    } else if (dx < 0) {
      x = max(dx, -127);
      report.x = x;
    }
    if (dy > 0) {
      y = min(dy, 127);
      report.y = y;
    } else if (dy < 0) {
      y = max(dy, -127);
      report.y = y;
    }
    dx -= x;
    dy -= y;
    pointing_device_set_report(report);
    pointing_device_send();
  }
  report.x += dx;
  report.y += dy;
  pointing_device_set_report(report);
  timer = timer_read();
}
