#ifndef STRIPCONTROLLER_H
#define STRIPCONTROLLER_H

template <uint8_t DATA_PIN>
class StripController : public TM1809Controller800Mhz<DATA_PIN> {

};

#endif
