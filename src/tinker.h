#pragma once

struct PinMapping {
    const char* name;
    hal_pin_t pin;
};

#define PIN(p) {#p, p}

const PinMapping g_pinmap[] = {
    // Gen 3
#if HAL_PLATFORM_NRF52840
# if PLATFORM_ID == PLATFORM_TRACKER
    PIN(D0), PIN(D1), PIN(D2), PIN(D3), PIN(D4), PIN(D5), PIN(D6), PIN(D7), PIN(D8), PIN(D9)
# elif PLATFORM_ID == PLATFORM_ESOMX
    PIN(D0), PIN(D1), PIN(D2), PIN(D5), PIN(TX), PIN(RX), PIN(A0), PIN(A1),
    PIN(A2), PIN(A3), PIN(A4), PIN(A5), PIN(A6), PIN(A7), PIN(B0), PIN(B1),
    PIN(B2), PIN(B3), PIN(C0), PIN(C1), PIN(C2), PIN(C3), PIN(C4), PIN(C5),
    PIN(SS), PIN(SCK), PIN(MISO), PIN(MOSI), PIN(SDA), PIN(SCL), PIN(CTS),
    PIN(RTS), PIN(SS1), PIN(SCK1), PIN(MISO1), PIN(MOSI1),
# else // PLATFORM_ID == PLATFORM_ESOMX
    PIN(D0), PIN(D1), PIN(D2), PIN(D3), PIN(D4), PIN(D5), PIN(D6), PIN(D7),
    PIN(D8), PIN(D9), PIN(D10), PIN(D11), PIN(D12), PIN(D13), PIN(D14), PIN(D15),
    PIN(D16), PIN(D17), PIN(D18), PIN(D19), PIN(A0), PIN(A1), PIN(A2), PIN(A3),
    PIN(A4), PIN(A5), PIN(SCK), PIN(MISO), PIN(MOSI), PIN(SDA), PIN(SCL), PIN(TX),
    PIN(RX)
#  if PLATFORM_ID == PLATFORM_BSOM || PLATFORM_ID == PLATFORM_B5SOM || PLATFORM_ID == PLATFORM_ASOM
    ,
    PIN(D20), PIN(D21), PIN(D22), PIN(D23),
    PIN(A6), PIN(A7)
#  if PLATFORM_ID == PLATFORM_ASOM
    ,
    PIN(D24)
#  endif // PLATFORM_ID == PLATFORM_ASOM
#  endif // PLATFORM_ID == PLATFORM_BSOM || PLATFORM_ID == PLATFORM_B5SOM || PLATFORM_ID == PLATFORM_ASOM
# endif // PLATFORM_ID == PLATFORM_TRACKER

#elif HAL_PLATFORM_RTL872X // P2, TrackerM or MSoM
    PIN(D0), PIN(D1), PIN(D2), PIN(D3), PIN(D4), PIN(D5), PIN(D6), PIN(D7), PIN(D8), PIN(D9),
    PIN(D10), PIN(D11), PIN(D12), PIN(D13), PIN(D14), PIN(D15), PIN(D16), PIN(D17), PIN(D18),
    PIN(D19), PIN(D20), PIN(D21),
    PIN(A0), PIN(A1), PIN(A2), PIN(A3), PIN(A4), PIN(A5),
    PIN(SS), PIN(SCK), PIN(MISO), PIN(MOSI), PIN(SS1), PIN(SCK1), PIN(MISO1), PIN(MOSI1),
    PIN(SDA), PIN(SCL),
    PIN(TX), PIN(RX), PIN(TX1), PIN(RX1),
    PIN(WKP)
#  if PLATFORM_ID == PLATFORM_P2
    // P2 exposes pins for Serial3, NCP pins not exposed on TrackerM or MSoM
    ,
    PIN(TX2), PIN(RX2), PIN(CTS2), PIN(RTS2)
#  endif // PLATFORM_ID == PLATFORM_P2
#  if PLATFORM_ID == PLATFORM_P2 || PLATFORM_ID == PLATFORM_TRACKERM
    ,
    PIN(S0), PIN(S1), PIN(S2), PIN(S3), PIN(S4), PIN(S5), PIN(S6),
    PIN(CTS1), PIN(RTS1)
#  elif PLATFORM_ID == PLATFORM_MSOM
    ,
    PIN(D22), PIN(D23), PIN(D24), PIN(D25), PIN(D26), PIN(D27), PIN(D28), PIN(D29),
    PIN(A6),
    PIN(CTS), PIN(RTS)
#  else
#  error Unsupported HAL_PLATFORM_RTL872X platform
#  endif
#else // HAL_PLATFORM_RTL872X
# error Unsupported platform
#endif // HAL_PLATFORM_NRF52840
};

const size_t g_pin_count = sizeof(g_pinmap) / sizeof(*g_pinmap);

#if HAL_PLATFORM_RTL872X
  PRODUCT_VERSION(4);
#else
  PRODUCT_VERSION(3);
#endif