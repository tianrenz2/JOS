#include <kern/e1000.h>

// LAB 6: Your driver code here
volatile uint32_t *bar;

int
e1000_attachfn(struct pci_func *pcif)
{
       pci_func_enable(pcif);
       bar = mmio_map_region(pcif->reg_base[0], pcif->reg_size[0]);

       uint32_t *status_reg = E1000REG(E1000_STATUS);
       assert(*status_reg == 0x80080783);
       return 0;
}