#include "../../src/ej1/esPrimo.h"
#include "gtest/gtest.h"

TEST(EsPrimoTest, NumeroPrimo) {
	ASSERT_TRUE(esPrimo(7));
	ASSERT_TRUE(esPrimo(2));
}

TEST(EsPrimoTest, NumeroCompuesto) {
	ASSERT_FALSE(esPrimo(6));
	ASSERT_FALSE(esPrimo(10));
}

TEST(EsPrimoTest, CasosBorde) {
	ASSERT_FALSE(esPrimo(1));
	ASSERT_FALSE(esPrimo(0));
}
