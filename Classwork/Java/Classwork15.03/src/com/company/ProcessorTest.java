package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ProcessorTest {
    Processor processor;
    @BeforeEach
    void setUp() {
        processor = new Processor(2, 1.5);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void getConsumption() {
        PowerData result = processor.getConsumption();
        Assertions.assertEquals(processor.getCoreCount() * Math.pow(processor.getCoreFrequency(), 2)/2 * 0.5 * 0.25, result.minimalPower);
        Assertions.assertEquals(processor.getCoreCount() * Math.pow(processor.getCoreFrequency(), 2)/2 * 0.5 * 5, result.maximalPower);
        Assertions.assertEquals(processor.getCoreCount() * Math.pow(processor.getCoreFrequency(), 2)/2 * 0.5, result.typicalPower);
    }
}