/* MicroFlo - Flow-Based Programming for microcontrollers
 * Copyright (c) 2013 Jon Nordby <jononor@gmail.com>
 * MicroFlo may be freely distributed under the MIT license
 */

#include "microflo.h"

#include <mbed.h>


class MbedIO : public IO {
public:


private:
    Timer timer;
public:
    MbedIO()
    {
        timer.start();
    }

    // Serial
    // FIXME: implement
    virtual void SerialBegin(int serialDevice, int baudrate) {

    }
    virtual long SerialDataAvailable(int serialDevice) {
        return false;
    }
    virtual unsigned char SerialRead(int serialDevice) {
        return 0;
    }
    virtual void SerialWrite(int serialDevice, unsigned char b) {

    }

    // Pin config
    virtual void PinSetMode(int pin, IO::PinMode mode) {
        
    }
    virtual void PinEnablePullup(int pin, bool enable) {

    }

    // Digital
    virtual void DigitalWrite(int pin, bool val) {
        //DigitalOut((PinName)pin).write(val);
        DigitalOut((PinName)LED2).write(val);
    }
    virtual bool DigitalRead(int pin) {
        return DigitalIn((PinName)pin).read();
    }

    // Analog
    // FIXME: implement
    virtual long AnalogRead(int pin) {
        return 0;
    }
    virtual void PwmWrite(int pin, long dutyPercent) {

    }

    // Timer
    virtual long TimerCurrentMs() {
        return timer.read_ms();
    }

    virtual void AttachExternalInterrupt(int interrupt, IO::Interrupt::Mode mode,
                                         IOInterruptFunction func, void *user) {

    }
};

