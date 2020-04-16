#include "mbed."
#include "LoraKeys.h"

using namespace EEPROMDriver;

Serial pc(USBTX, USBRX);

int main()
{
    printf("\r\n[Particula] Example of usage LoraKeys class");

    LoRaWANKeys lora_keys = {
        {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // devEui
        {0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},                                                // appEui
        {0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF} // appKey
    };

    LoRaWAN::Keys keys(lora_keys);

    pc.printf("\r\nWriting devEui to eeprom");

    keys.write_devEui();

    pc.printf("\r\nWriting appEui to eeprom");

    keys.write_appEui();

    pc.printf("\r\nWriting appKey to eeprom");

    keys.write_appKey();

    char devEui[keys.get_length_of_devEui] = 0;
    char appEui[keys.get_length_of_appEui] = 0;
    char appKey[keys.get_length_of_appKey] = 0;

    pc.printf("\r\nReading devEui to eeprom");

    devEui = keys.read_devEui();

    pc.printf("\r\nReading appEui to eeprom");

    appEui = keys.read_appEui();

    pc.printf("\r\nReading appKey to eeprom");

    appKey = keys.read_appKey();

    pc.printf("\r\nPrinting devEui to serial\r\n");

    for(unsigned int i = 0; i < keys.get_length_of_devEui; i++){
        pc.printf("0x%x", devEui[i]);
    }
    
    pc.printf("\r\nPrinting appEui to serial\r\n");

    for(unsigned int i = 0; i < keys.get_length_of_appEui; i++){
        pc.printf("0x%x", appEui[i]);
    }
   
    pc.printf("\r\nPrinting appKey to serial\r\n");

    for(unsigned int i = 0; i < keys.get_length_of_appKey; i++){
        pc.printf("0x%x", appKey[i]);
    }
   
}