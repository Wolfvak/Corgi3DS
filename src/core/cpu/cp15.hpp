#ifndef CP15_HPP
#define CP15_HPP
#include <cstdint>

class ARM_CPU;
class MMU;

class CP15
{
    private:
        int id;
        ARM_CPU* cpu;
        MMU* mmu;

        uint32_t aux_control;

        bool mmu_enabled;
        bool high_exception_vector;

        uint32_t data_fault_addr;
        uint32_t data_fault_reg;

        uint32_t instr_fault_reg;

        uint32_t thread_regs[3];
    public:
        uint8_t ITCM[1024 * 32], DTCM[1024 * 16];

        uint32_t itcm_size;
        uint32_t dtcm_base, dtcm_size;
        CP15(int id, ARM_CPU* cpu, MMU* mmu);

        void reset(bool has_tcm);
        void reload_tlb(uint32_t addr);

        uint8_t** get_tlb_mapping();

        bool has_high_exceptions();

        void set_data_abort_regs(uint32_t vaddr, bool is_write);
        void set_prefetch_abort_regs(uint32_t vaddr);

        uint32_t mrc(int operation_mode, int CP_reg,
                     int coprocessor_info, int coprocessor_operand);
        void mcr(int operation_mode, int CP_reg,
                 int coprocessor_info, int coprocessor_operand, uint32_t value);
};

#endif // CP15_HPP
