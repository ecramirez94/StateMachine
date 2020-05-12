#ifndef StateMachine_h
#define StateMachine_h

#include "Arduino.h"

class StateMachine
{
  public:
    StateMachine(void);
    void Queue(void);
    void addToQueue(uint8_t stateNumber);
    void removeFromQueue(uint8_t stateNumber);

  private:
    volatile uint8_t _state;
    uint8_t _scanStates(void);
};
#endif
