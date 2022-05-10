#ifndef __XEN_PUBLIC_EFFECTOR_H__
#define __XEN_PUBLIC_EFFECTOR_H__


struct arbitrary_va_data {
    unsigned long target_addr; /* physical address to map */
    unsigned long va_mapped_addr; /* virtual address mapped into the domain */
};

typedef struct arbitrary_va_data arbitrary_va_t;

#endif /* __XEN_PUBLIC_ATTACK_H__ */
