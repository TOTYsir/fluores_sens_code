#include <Arduino.h>
#include <Wire.h>
#include "ssd1306.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void lcd_init(void) {
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("Failed to initialise LCD");
        // while (1); // Keep waiting
    }
    display.display();
    delay(5000);
    display.clearDisplay();
}

void lcd_flush(float volts0, float volts1, float norm) {
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    display.setCursor(0, 0);
    display.printf("Normalised: %.4f ", norm);
    
    display.setCursor(0, 20);
    display.printf("PD orange: %.2f V", volts0);

    display.setCursor(0, 40);
    display.printf("PD yellow: %.2f V", volts1);
    display.display();

    vTaskDelay(20);
}
