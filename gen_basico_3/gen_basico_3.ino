#include <AD9833.h>
#include <SPI.h>

AD9833 gen(10);

int forma_onda = 0; // Inicialmente, usamos la forma de onda senoidal
long f;

bool buttonPressed = false;

void setup()
{
  pinMode(7, INPUT_PULLUP);
  pinMode(A0, OUTPUT);
  gen.Begin();
  gen.EnableOutput(true);
}

void loop()
{
  f = map(analogRead(A0), 0, 1023, 1, 10000);

  // Si se presiona el botón y no se había presionado antes, cambiamos la forma de onda
 /* if (digitalRead(7) == LOW && !buttonPressed) {
    buttonPressed = true; // Marcamos que el botón ha sido presionado
    forma_onda++; // Incrementamos la variable forma_onda para cambiar de forma de onda
    if (forma_onda > 2) forma_onda = 0; // Si forma_onda es mayor que 2, la volvemos a poner en 0

    // Cambiamos la forma de onda según el valor de la variable forma_onda
    switch (forma_onda) {
      case 0:
        gen.ApplySignal(SINE_WAVE, REG0, f);
        break;
      case 1:
        gen.ApplySignal(TRIANGLE_WAVE, REG0, f);
        break;
      case 2:
        gen.ApplySignal(SQUARE_WAVE, REG0, f);
        break;
    }
  }

  // Si se suelta el botón, marcamos que ya no está presionado
  if (digitalRead(7) == HIGH && buttonPressed) {
    buttonPressed = false;
  }
  */
if (digitalRead(7) == HIGH) {
    forma_onda++; // Incrementamos la variable forma_onda para cambiar de forma de onda
    delay(250);
}if (forma_onda > 2) forma_onda = 0; // Si forma_onda es mayor que 2, la volvemos a poner en 0

    // Cambiamos la forma de onda según el valor de la variable forma_onda
    switch (forma_onda) {
      case 0:
        gen.ApplySignal(SINE_WAVE, REG0, f);
        break;
      case 1:
        gen.ApplySignal(TRIANGLE_WAVE, REG0, f);
        break;
      case 2:
        gen.ApplySignal(SQUARE_WAVE, REG0, f);
        break;
    }

}
