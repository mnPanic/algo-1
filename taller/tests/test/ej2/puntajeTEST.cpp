#include "../../src/ej2/puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(PuntajeTest, NumeroModTres) {
    ASSERT_EQ(puntaje(9), 28);
    ASSERT_EQ(puntaje(12), 22);
}

TEST(PuntajeTest, NumeroNoModTres) {
    ASSERT_EQ(puntaje(8), 6);
    ASSERT_EQ(puntaje(11), 1);
}