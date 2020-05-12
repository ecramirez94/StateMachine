#include "Arduino.h"
#include "StateMachine.h"

// ========== State Masks ==========
#define STATE_1  0b00000001
#define STATE_2  0b00000010
#define STATE_3  0b00000100
#define STATE_4  0b00001000
#define STATE_5  0b00010000
#define STATE_6  0b00100000
#define STATE_7  0b01000000
#define STATE_8  0b10000000
// =================================

// ========== Constructor ==========
StateMachine::StateMachine(void) {}
// =================================

// ========== Declare Weak Functions before they are called =========
void stateOne(void) __attribute__((weak));
void stateTwo(void) __attribute__((weak));
void stateThree(void) __attribute__((weak));
void stateFour(void) __attribute__((weak));
void stateFive(void) __attribute__((weak));
void stateSix(void) __attribute__((weak));
void stateSeven(void) __attribute__((weak));
void stateEight(void) __attribute__((weak));
// ==================================================================

// ========== Main State Machine ==========
void StateMachine::Queue(void)
{
  switch (_scanStates())
  {
    case STATE_1:
      stateOne();
      removeFromQueue(1);
    break;
    case STATE_2:
      stateTwo();
      removeFromQueue(2); 
    break;
    case STATE_3:
      stateThree();
      removeFromQueue(3); 
    break;
    case STATE_4:
      stateFour();
      removeFromQueue(4); 
    break;
    case STATE_5:
      stateFive();
      removeFromQueue(5);
    break;
    case STATE_6:
      stateSix();
      removeFromQueue(6); 
    break;
    case STATE_7:
      stateSeven();
      removeFromQueue(7); 
    break;
    case STATE_8:
      stateEight();
      removeFromQueue(8); 
    break;
    default:

    break;
  }
}
// =========================================

// ========== Member Functions ==========
uint8_t StateMachine::_scanStates(void)
{
  uint8_t newState = 0b00000000;

  if (_state != 0b00000000)  // If there a new state to jump to
  {
    for (uint8_t i = 0b00000001; i <= 0b10000000; i <<= 1)  // Figure out which it is and go to it. State 1 has highest priority, State 8 least.
    {       
      if ((_state & i) > 0)
      {
        newState = i;
        break;
      }
    }
  }
  
  return newState;
}

void StateMachine::removeFromQueue(uint8_t stateNumber) // Remove the most recently executed state from the queue
{
  uint8_t _st = 0b00000001;
  _st <<= (stateNumber - 1); // Select the state to remove 
  _st ^= 0xFF;  // Invert to generate bit mask
  _state &= _st;  // Remove state from queue while leaving the rest untouched
}

void StateMachine::addToQueue(uint8_t stateNumber)  // Add a state to queue for execution
{
  uint8_t _st = 0b00000001;
  _st <<= (stateNumber - 1); // Select the state to add to queue
  _state |= _st;  // Add state to queue  
}
// =======================================
