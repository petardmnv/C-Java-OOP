package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class PowerDataTest {
    PowerData powerData;
    @BeforeEach
    void setUp() {
        powerData = new PowerData(0, 0, 0);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void getAllData() {
        PowerData result = powerData.getAllData(new PowerData(1, 2, 3));
        Assertions.assertEquals(1, result.minimalPower);
        Assertions.assertEquals(2, result.maximalPower);
        Assertions.assertEquals(3, result.typicalPower);
    }
}