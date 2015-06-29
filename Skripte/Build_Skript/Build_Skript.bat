C:\Ard\Arduino\hardware\tools\avr\bin\avr-g++ -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10600 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 -DUSB_MANUFACTURER= -DUSB_PRODUCT="Arduino Yun" -IC:\Ard\Arduino\hardware\arduino\avr\cores\arduino -IC:\Ard\Arduino\hardware\arduino\avr\variants\yun %1.cpp -o %1.cpp.o 

ping -n 5 127.0.0.1 >NUL

C:\Ard\Arduino\hardware\tools\avr\bin\avr-gcc -w -Os -Wl,--gc-sections -mmcu=atmega32u4 -o %1.cpp.elf %1.cpp.o core.a -L -lm
ping -n 5 127.0.0.1 >NUL

C:\Ard\Arduino\hardware\tools\avr\bin\avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 %1.cpp.elf %1.cpp.eep 
ping -n 5 127.0.0.1 >NUL
C:\Ard\Arduino\hardware\tools\avr\bin\avr-objcopy -O ihex -R .eeprom %1.cpp.elf %1.cpp.hex

ping -n 5 127.0.0.1 >NUL