#ifndef MPCORE_PMR_HPP
#define MPCORE_PMR_HPP
#include <cstdint>

class ARM_CPU;

class MPCore_PMR
{
    private:
        ARM_CPU* syscore, *appcore;
        uint32_t irq_cause;
        uint32_t hw_int_mask[8], hw_int_pending[8];
    public:
        MPCore_PMR(ARM_CPU* syscore);

        void reset();
        void assert_hw_irq(int id);

        uint8_t read8(uint32_t addr);
        uint32_t read32(uint32_t addr);
        void write8(uint32_t addr, uint8_t value);
        void write16(uint32_t addr, uint16_t value);
        void write32(uint32_t addr, uint32_t value);
};

#endif // MPCORE_PMR_HPP
