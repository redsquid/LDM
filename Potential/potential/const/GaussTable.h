#ifndef GAUSSTABLE_H
#define GAUSSTABLE_H

#include <cstdlib>
#include <gsl/gsl_integration.h>

class GaussTable {
public:
    virtual ~GaussTable();
    static const gsl_integration_glfixed_table* get();

private:
    GaussTable(uint order);
    static constexpr uint ORDER = 32;
    static GaussTable INSTANCE;
    const gsl_integration_glfixed_table* GAUSS_TABLE;

};

#endif // GAUSSTABLE_H
