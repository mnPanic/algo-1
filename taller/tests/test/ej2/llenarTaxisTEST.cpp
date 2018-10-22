#include "../../src/ej1/esPrimo.h"
#include "gtest/gtest.h"
#include "../../src/ej2/llenarTaxis.h"

// Escribir tests aca:
TEST(TestLlenarTaxis, MismasCantidadesPorTamaño){
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;

    int res = 0;

    int expected = 3;

    llenarTaxis1(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis2(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis3(g1, g2, g3, res);
    EXPECT_EQ(res, expected);
}

TEST(TestLlenarTaxis, DistintasCantidadesPar) {
    int g1 = 1;
    int g2 = 2;
    int g3 = 3;

    int res = 0;

    int expected = 4;

    llenarTaxis1(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis2(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis3(g1, g2, g3, res);
    EXPECT_EQ(res, expected);
}

TEST(TestLlenarTaxis, DistintasCantidadesImparEq1) {
    int g1 = 5;
    int g2 = 3;
    int g3 = 4;

    int res = 0;

    int expected = 6;

    llenarTaxis1(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis2(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis3(g1, g2, g3, res);
    EXPECT_EQ(res, expected);
}

TEST(TestLlenarTaxis, DistintasCantidadesImparEq2) {
    int g1 = 6;
    int g2 = 3;
    int g3 = 4;

    int res = 0;

    int expected = 6;

    llenarTaxis1(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis2(g1, g2, g3, res);
    EXPECT_EQ(res, expected);

    llenarTaxis3(g1, g2, g3, res);
    EXPECT_EQ(res, expected);
}
